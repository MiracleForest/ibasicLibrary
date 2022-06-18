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
#include "../type/concepts.hpp"

#include "../../../cppstd/type_traits"
#include "../../../cppstd/concepts"
#include "../../../cppstd/compare"
#include "../../../cppstd/ostream"
#include "../../../cppstd/string"

namespace i{
	namespace core {
		namespace type {
			namespace basic {


				/// <summary>
				/// Class number, a wrapper for arithmetic type
				/// </summary>
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

					/*
					number(const number& other)
						: _value(other._value) {}

					number(Type&& val)
						: _value(val) {}

					number& operator=(const number& other)
					{
						_value = other._value;
						return *this;
					}

					number& operator=(Type&& other)
					{
						return _value;
					}
					*/

					/// <summary>
					/// Return the _value that number contains
					/// </summary>
					/// <warning></warning>
					/// <include></include>
					/// <bug></bug>
					/// <returns></returns>
					Type data() const
					{
						return _value;
					}

					/// <summary>
					/// Get _value that convert to std::string
					/// </summary>
					/// <warning></warning>
					/// <include></include>
					/// <bug></bug>
					/// <returns>string</returns>
					std::string toStdString()
					{
						return std::to_string(_value);
					}

					/// <summary>
					/// Get _value that convert to std::string
					/// </summary>
					/// <warning></warning>
					/// <include></include>
					/// <bug></bug>
					/// <returns></returns>
					std::wstring toStdWstring()
					{
						return std::to_wstring(_value);
					}

					/// <summary>
					/// Convert std::string or std::wstring into Type
					/// </summary>
					/// <warning></warning>
					/// <include></include>
					/// <bug></bug>
					/// <param name="str"></param>
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
						{
						}
					}

					/// <summary>
					/// Reset the _value to 0, depends on Type
					/// </summary>
					/// <warning></warning>
					/// <include></include>
					/// <bug></bug>
					void reset()
					{
						_value = static_cast<Type>(0);
					}

					/// <summary>
					/// Avoiding ambiguous, full implement have been given below
					/// </summary>
					/// <param name=""></param>
					/// <warning></warning>
					/// <include></include>
					/// <bug></bug>
					/// <returns></returns>
					auto operator<=>(const number&) const = delete;

					/// <summary>
					/// Type convertion function
					/// </summary>
					/// <warning></warning>
					/// <include></include>
					/// <bug></bug>
					/// <typeparam name="T"></typeparam>
					template <typename T>
					operator T()
					{
						return static_cast<T>(_value);
					}

					/// <summary>
					/// operator declaration
					/// </summary>
					/// <typeparam name="T"></typeparam>
					/// <typeparam name="U"></typeparam>
					/// <param name="first"></param>
					/// <param name="last"></param>
					/// <warning></warning>
					/// <include></include>
					/// <bug></bug>
					/// <returns></returns>
					template <typename T, typename U>
					friend auto operator<=>(const number<T>& first, const number<U>& last);

					/// <summary>
					/// Overloading for std::ostream
					/// </summary>
					/// <param name="os"></param>
					/// <param name="value"></param>
					/// <warning></warning>
					/// <include></include>
					/// <bug></bug>
					/// <returns></returns>
					friend std::ostream& operator<<(std::ostream& os, const number& value)
					{
						os << value._value;
						return os;
					}

					/// <summary>
					/// operator + declaration
					/// </summary>
					/// <typeparam name="T"></typeparam>
					/// <typeparam name="U"></typeparam>
					/// <param name="first"></param>
					/// <param name="last"></param>
					/// <warning></warning>
					/// <include></include>
					/// <bug></bug>
					/// <returns></returns>
					template <typename T, typename U>
					friend auto operator+(const number<T>& first, const number<U>& last)
						->number<std::common_type_t<T, U>>;

					/// <summary>
					/// operator - declaration
					/// </summary>
					/// <typeparam name="T"></typeparam>
					/// <typeparam name="U"></typeparam>
					/// <param name="first"></param>
					/// <param name="last"></param>
					/// <warning></warning>
					/// <include></include>
					/// <bug></bug>
					/// <returns></returns>
					template <typename T, typename U>
					friend auto operator-(const number<T>& first, const number<U>& last)
						->number<std::common_type_t<T, U>>;

					/// <summary>
					/// operator * declaration
					/// </summary>
					/// <typeparam name="T"></typeparam>
					/// <typeparam name="U"></typeparam>
					/// <param name="first"></param>
					/// <param name="last"></param>
					/// <warning></warning>
					/// <include></include>
					/// <bug></bug>
					/// <returns></returns>
					template <typename T, typename U>
					friend auto operator*(const number<T>& first, const number<U>& last)
						->number<std::common_type_t<T, U>>;

					/// <summary>
					/// operator / declaration
					/// </summary>
					/// <typeparam name="T"></typeparam>
					/// <typeparam name="U"></typeparam>
					/// <param name="first"></param>
					/// <param name="last"></param>
					/// <warning></warning>
					/// <include></include>
					/// <bug></bug>
					/// <returns></returns>
					template <typename T, typename U>
					friend auto operator/(const number<T>& first, const number<U>& last)
						->number<std::common_type_t<T, U>>;

					///<summary>
					/// operator between arithmetic type and number<_Tp>
					///<summary>
					template <arithmetic U>
					friend auto operator+(const number& num, U value)
						->number<std::common_type_t<Type, U>>
					{
						return { num.data() + value };
					}

					template <arithmetic U>
					friend auto operator+(U value, const number& num)
						->number<std::common_type_t<Type, U>>
					{
						return { num.data() + value };
					}

					template <arithmetic U>
					friend auto operator-(const number& num, U value)
						->number<std::common_type_t<Type, U>>
					{
						return { num.data() - value };
					}

					template <arithmetic U>
					friend auto operator-(U value, const number& num)
						->number<std::common_type_t<Type, U>>
					{
						return { num.data() - value };
					}

					template <arithmetic U>
					friend auto operator*(const number& num, U value)
						->number<std::common_type_t<Type, U>>
					{
						return { num.data() * value };
					}

					template <arithmetic U>
					friend auto operator*(U value, const number& num)
						->number<std::common_type_t<Type, U>>
					{
						return { num.data() * value };
					}

					template <arithmetic U>
					friend auto operator/(const number& num, U value)
						->number<std::common_type_t<Type, U>>
					{
						return { num.data() / value };
					}

					template <arithmetic U>
					friend auto operator/(U value, const number& num)
						->number<std::common_type_t<Type, U>>
					{
						return { num.data() / value };
					}

				private:
					Type _value;
				}; /// end class number

				/// <summary>
				/// operator definition
				/// </summary>
				/// <typeparam name="T"></typeparam>
				/// <typeparam name="U"></typeparam>
				/// <param name="first"></param>
				/// <param name="last"></param>
				/// <warning></warning>
				/// <include></include>
				/// <bug></bug>
				/// <returns></returns>
				template <arithmetic T, arithmetic U>
				static auto operator<=>(const number<T>& first, const number<U>& last)
				{
					return first._value <=> last._value;
				}

				/// <summary>
				/// operator + definition
				/// </summary>
				/// <typeparam name="T"></typeparam>
				/// <typeparam name="U"></typeparam>
				/// <param name="first"></param>
				/// <param name="last"></param>
				/// <warning></warning>
				/// <include></include>
				/// <bug></bug>
				/// <returns></returns>
				template <typename T, typename U>
				auto operator+(const number<T>& first, const number<U>& last)
					-> number<std::common_type_t<T, U>>
				{
					return first._value + last._value;
				}

				/// <summary>
				/// operator - definition
				/// </summary>
				/// <typeparam name="T"></typeparam>
				/// <typeparam name="U"></typeparam>
				/// <param name="first"></param>
				/// <param name="last"></param>
				/// <warning></warning>
				/// <include></include>
				/// <bug></bug>
				/// <returns></returns>
				template <typename T, typename U>
				auto operator-(const number<T>& first, const number<U>& last)
					-> number<std::common_type_t<T, U>>
				{
					return first._value - last._value;
				}

				/// <summary>
				/// operator * definition
				/// </summary>
				/// <typeparam name="T"></typeparam>
				/// <typeparam name="U"></typeparam>
				/// <param name="first"></param>
				/// <param name="last"></param>
				/// <warning></warning>
				/// <include></include>
				/// <bug></bug>
				/// <returns></returns>
				template <typename T, typename U>
				auto operator*(const number<T>& first, const number<U>& last)
					-> number<std::common_type_t<T, U>>
				{
					return first._value * last._value;
				}

				/// <summary>
				/// operator / definition
				/// </summary>
				/// <typeparam name="T"></typeparam>
				/// <typeparam name="U"></typeparam>
				/// <param name="first"></param>
				/// <param name="last"></param>
				/// <warning></warning>
				/// <include></include>
				/// <bug></bug>
				/// <returns></returns>
				template <arithmetic T, arithmetic U>
				auto operator/(const number<T>& first, const number<U>& last)
					-> number<std::common_type_t<T, U>>
				{
					return first._value / last._value;
				}

				/*
				template<arithmetic T, arithmetic U = T>
				auto operator+(const number<T>& num, U value)
					->number<std::common_type_t<T, U>>
				{
					return { num.data() + value };
				}

				template<arithmetic T, arithmetic U = T>
				auto operator+(U value, const number<T>& num)
					->number<std::common_type_t<T, U>>
				{
					return { num.data() + value };
				}
				*/

			} // namespace basic
		} // namespace type
	}// namespace core
} // namespace i

#endif // !___MIRACLEFOREST_I_NUMBER___