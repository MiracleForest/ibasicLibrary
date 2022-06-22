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


				// Class number, a wrapper for arithmetic type
				template <arithmetic Type>
				class number
				{
				public:

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

					Type data() const
					{
						return _value;
					}

					std::string toStdString()
					{
						return std::to_string(_value);
					}

					std::wstring toStdWstring()
					{
						return std::to_wstring(_value);
					}

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

					void reset()
					{
						_value = static_cast<Type>(0);
					}

					auto operator<=>(const number&) const = delete;

					template <typename T>
					operator T()
					{
						return static_cast<T>(_value);
					}

					template <typename T, typename U>
					friend auto operator<=>(const number<T>& first, const number<U>& last);

					friend std::ostream& operator<<(std::ostream& os, const number& value)
					{
						os << value._value;
						return os;
					}

					template <typename T, typename U>
					friend auto operator+(const number<T>& first, const number<U>& last)
						->number<std::common_type_t<T, U>>;

					template <typename T, typename U>
					friend auto operator-(const number<T>& first, const number<U>& last)
						->number<std::common_type_t<T, U>>;

					template <typename T, typename U>
					friend auto operator*(const number<T>& first, const number<U>& last)
						->number<std::common_type_t<T, U>>;

					template <typename T, typename U>
					friend auto operator/(const number<T>& first, const number<U>& last)
						->number<std::common_type_t<T, U>>;

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

				template <arithmetic T, arithmetic U>
				static auto operator<=>(const number<T>& first, const number<U>& last)
				{
					return first._value <=> last._value;
				}

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