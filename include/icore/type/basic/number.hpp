/****
*
* Copyright(C) 2022 MiracleForest Studio. All Rights Reserved.
*
* @文件名：number.hpp
* @创建时间：2022.4.25 21:25
* @创建者：WitherVictor
* -----------------------------------------------------------------------------
* Contains definition of class number
*
* -----------------------------------------------------------------------------
* 如果你发现了bug，你可以去Github或邮箱(MiracleForest@Outlook.com)反馈给我们！
* 我们一定会努力做得更好的！
*
****/
#ifndef ___MIRACLEFOREST_I_NUMBER___
#define ___MIRACLEFOREST_I_NUMBER___

#include "../../family/imacrofamily.h"
#include "../type/type_traits.hpp"
#include "../type/concepts.hpp"
#include "basic/ibasic.hpp"

#include <type_traits>
#include <concepts>
#include <compare>
#include <ostream>
#include <string>

SPACE(i) {
	SPACE(core) {
		SPACE(type) {
			SPACE(basic) {


				// Class number, a wrapper for arithmetic type
				template <arithmetic Type>
				class number :public N_ISTD basic::ibasic_data_type<Type>
				{
				public:

					number()
						: _value(static_cast<Type>(0)) {}

					number(Type val)
						: _value(val) {}

					/*
					number(CRef<number> other)
						: _value(other._value) {}

					number(Type&& val)
						: _value(val) {}

					number& operator=(CRef<number> other)
					{
						_value = other._value;
						return *this;
					}

					number& operator=(Type&& other)
					{
						return _value;
					}
					*/

				public:

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

				public C_OPERATOR:

					auto operator<=>(CRef<number>) const = delete;

					template <typename T>
					operator T()
					{
						return static_cast<T>(_value);
					}

					template <typename T, typename U>
					friend auto operator<=>(CRef<number<T>> first, CRef<number<U>> last);

					friend Ref<std::ostream> operator<<(Ref<std::ostream> os, CRef<number> value)
					{
						os << value._value;
						return os;
					}

					template <typename T, typename U>
					friend auto operator+(CRef<number<T>> first, CRef<number<U>> last)
						->number<std::common_type_t<T, U>>;

					template <typename T, typename U>
					friend auto operator-(CRef<number<T>> first, CRef<number<U>> last)
						->number<std::common_type_t<T, U>>;

					template <typename T, typename U>
					friend auto operator*(CRef<number<T>> first, CRef<number<U>> last)
						->number<std::common_type_t<T, U>>;

					template <typename T, typename U>
					friend auto operator/(CRef<number<T>> first, CRef<number<U>> last)
						->number<std::common_type_t<T, U>>;

					template <arithmetic U>
					friend auto operator+(CRef<number> num, U value)
						->number<std::common_type_t<Type, U>>
					{
						return { num.data() + value };
					}

					template <arithmetic U>
					friend auto operator+(U value, CRef<number> num)
						->number<std::common_type_t<Type, U>>
					{
						return { num.data() + value };
					}

					template <arithmetic U>
					friend auto operator-(CRef<number> num, U value)
						->number<std::common_type_t<Type, U>>
					{
						return { num.data() - value };
					}

					template <arithmetic U>
					friend auto operator-(U value, CRef<number> num)
						->number<std::common_type_t<Type, U>>
					{
						return { num.data() - value };
					}

					template <arithmetic U>
					friend auto operator*(CRef<number> num, U value)
						->number<std::common_type_t<Type, U>>
					{
						return { num.data() * value };
					}

					template <arithmetic U>
					friend auto operator*(U value, CRef<number> num)
						->number<std::common_type_t<Type, U>>
					{
						return { num.data() * value };
					}

					template <arithmetic U>
					friend auto operator/(CRef<number> num, U value)
						->number<std::common_type_t<Type, U>>
					{
						return { num.data() / value };
					}

					template <arithmetic U>
					friend auto operator/(U value, CRef<number> num)
						->number<std::common_type_t<Type, U>>
					{
						return { num.data() / value };
					}

				private:
					Type _value;
				}; /// end class number

				template <arithmetic T, arithmetic U>
				static auto operator<=>(CRef<number<T>>first, CRef<number<U>>last)
				{
					return first._value <=> last._value;
				}

				template <typename T, typename U>
				auto operator+(CRef<number<T>>first, CRef<number<U>>last)
					-> number<std::common_type_t<T, U>>
				{
					return first._value + last._value;
				}

				template <typename T, typename U>
				auto operator-(CRef<number<T>>first, CRef<number<U>>last)
					-> number<std::common_type_t<T, U>>
				{
					return first._value - last._value;
				}

				template <typename T, typename U>
				auto operator*(CRef<number<T>>first, CRef<number<U>>last)
					-> number<std::common_type_t<T, U>>
				{
					return first._value * last._value;
				}

				template <arithmetic T, arithmetic U>
				auto operator/(CRef<number<T>>first, CRef<number<U>>last)
					-> number<std::common_type_t<T, U>>
				{
					return first._value / last._value;
				}

				/*
				template<arithmetic T, arithmetic U = T>
				auto operator+(CRef<number<T>> num, U value)
					->number<std::common_type_t<T, U>>
				{
					return { num.data() + value };
				}

				template<arithmetic T, arithmetic U = T>
				auto operator+(U value, CRef<number<T>> num)
					->number<std::common_type_t<T, U>>
				{
					return { num.data() + value };
				}
				*/

			} //SPACE(basic)
		} //SPACE(type)
	}//SPACE(core)
} //SPACE(i)

#endif // !___MIRACLEFOREST_I_NUMBER___