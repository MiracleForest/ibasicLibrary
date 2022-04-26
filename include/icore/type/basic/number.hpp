/*
* 
* Copyright(C) 2022 MiracleForest Studio. All Rights Reserved.
* 
* @filename : number.hpp
* @creation time : 2022.4.25 21:25
* @created by : WitherVictor
* @project:iBasicLibrary-BasicType
* -----------------------------------------------------------------------------
* Contains definition of class number
* -----------------------------------------------------------------------------
* If you have contact or find bugs,
* you can go to Github or email (MiracleForest@Outlook.com) to give feedback. 
* We will try to do our best!
*/

#ifndef ___MIRACLEFOREST_I_NUMBER___
#define ___MIRACLEFOREST_I_NUMBER___

#include "../../family/imacrofamily.h"
#include "../type/type_traits.hpp"

#include <type_traits>
#include <concepts>
#include <compare>
#include <ostream>
#include <string>

namespace i::core {
	namespace type {
		namespace basic {
			/// <summary>
			/// Define concept arithmetic 
			/// </summary>
			template <typename T>
			concept arithmetic = std::is_arithmetic<T>::value;

			template <typename T>
			concept stdString = i::core::type::type_traits::is_std_string_v<T>;

			/// <summary>
			/// Class number, a wrapper for arithmetic type
			/// <summary>
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
				/// Convert std::string or std::wstring into Type
				/// </summary>
				void fromStdString(stdString auto&& str)
				{
					if constexpr (std::is_same_v<Type, int>)
						_value = std::stoi(str);
					else if (std::is_same_v<Type, long>)
						_value = std::stol(str);
					else if (std::is_same_v<Type, unsigned long>)
						_value = std::stoul(str);
					else if (std::is_same_v<Type, long long>)
						_value = std::stoll(str);
					else if (std::is_same_v<Type, unsigned long long>)
						_value = std::stoull(str);
					else if (std::is_same_v<Type, float>)
						_value = std::stof(str);
					else if (std::is_same_v<Type, double>)
						_value = std::stod(str);
					else if (std::is_same_v<Type, long double>)
						_value = std::stold(str);
					else
						{}
				}

				/// <summary>
				/// Reset the _value to 0, depends on Type
				/// </summary>
				void reset()
				{
					_value = static_cast<Type>(0);
				}
                
				/// <summary>
				/// Avoiding ambiguous, full implement have been given below 
				/// </summary>
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

		} /// namespace basic
	} /// namespace type
} /// namespace i::core

#endif // !___MIRACLEFOREST_I_NUMBER___