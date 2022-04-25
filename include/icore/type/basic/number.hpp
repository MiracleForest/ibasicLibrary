/*
* 
* Copyright(C) 2022 ClockParadox Studio. All Rights Reserved.
* 
* @filename : number.hpp
* @creation time : 2022.4.25 21:25
* @created by : WitherVictor
* @project : iBasicLibrary-BasicType
* -----------------------------------------------------------------------------
* Contains definition of class number
* 
* -----------------------------------------------------------------------------
* If you have contact or find bugs,
* you can go to Github or email (MiracleForest@Outlook.com) to give feedback. 
* We will try to do our best!
*/

#ifndef __NUMBER_HPP__
#define __NUMBER_HPP__

#include <type_traits>
#include <concepts>
#include <compare>
#include <ostream>
#include <string>

namespace i::core
{
	namespace type
	{
		namespace basic
		{
			template <typename T>
			concept arithmetic = std::is_arithmetic<T>::value;

			template <arithmetic Type>
			class number
			{
			public:

				/// <summary>
				/// Class number ctor
				/// </summary>
				number()
					: _value(static_cast<Type>(0)) {}

				number(Type val)
					: _value(val) {}

				/// <summary>
				/// Return the _value that number contains
				/// </summary>
				Type data() const
				{
					return _value;
				}

				/// <summary>
				/// Get _value that convert to std::string
				/// </summary>
				std::string toStdString()
				{
					return std::to_string(_value);
				}

				/// <summary>
				/// Get _value that convert to std::string
				/// </summary>
				std::wstring toStdWstring()
				{
					return std::to_wstring(_value);
				}

				/// <summary>
				/// Reset the _value to 0, depends on Type
				/// </summary>
				void reset()
				{
					_value = static_cast<Type>(0);
				}
                
                auto operator<=>(const number&) const = delete;

				/// <summary>
				/// Type convertion function
				/// </summary>
				template <typename T>
				operator T()
				{
					return static_cast<T>(_value);
				}

                /// <summary>
				/// operator<=> declaration
				/// </summary>
                template <typename T, typename U>
                friend auto operator<=>(const number<T>& first, const number<U>& last);

                /// <summary>
				/// Overloading for std::ostream
				/// </summary>
				friend std::ostream& operator<<(std::ostream& os, const number& value)
				{
					os << value._value;
					return os;
				}

				/// <summary>
				/// operator+, -, *, / declaration
				/// </summary>
				template <typename T, typename U>
				friend auto operator+(const number<T>& first, const number<U>& last)
					-> number<std::common_type_t<T, U>>;
				
				template <typename T, typename U>
				friend auto operator-(const number<T>& first, const number<U>& last)
					-> number<std::common_type_t<T, U>>;

				template <typename T, typename U>
				friend auto operator*(const number<T>& first, const number<U>& last)
					-> number<std::common_type_t<T, U>>;

				template <typename T, typename U>
				friend auto operator/(const number<T>& first, const number<U>& last)
					-> number<std::common_type_t<T, U>>;

			private:
				Type _value;
			}; /// end class number

            /// <summary>
			/// operator<=> definition
			/// </summary>
            template <typename T, typename U>
            static auto operator<=>(const number<T>& first, const number<U>& last)
            {
                return first._value <=> last._value;
            }

			/// <summary>
			/// operator+, -, *, / definition
			/// </summary>
			template <typename T, typename U>
			auto operator+(const number<T>& first, const number<U>& last)
				-> number<std::common_type_t<T, U>>
			{
				return first._value + last._value;
			}

			template <typename T, typename U>
			auto operator-(const number<T>& first, const number<U>& last)
				-> number<std::common_type_t<T, U>>
			{
				return first._value - last._value;
			}

			template <typename T, typename U>
			auto operator*(const number<T>& first, const number<U>& last)
				-> number<std::common_type_t<T, U>>
			{
				return first._value * last._value;
			}

			template <typename T, typename U>
			auto operator/(const number<T>& first, const number<U>& last)
				-> number<std::common_type_t<T, U>>
			{
				return first._value / last._value;
			}

		} /// end namespace basic
	} /// end namespace type
} /// end namespace i::core

#endif // __NUMBER_HPP__