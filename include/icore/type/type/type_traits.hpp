/*
*
* Copyright(C) 2022 ClockParadox Studio. All Rights Reserved.
*
* @filename:type_traits.hpp
* @creation time:2022.4.26.13:00
* @created by:Lovelylavender4
* @project : iBasicLibrary-Type-Type_traits
* -----------------------------------------------------------------------------
* type traits
* -----------------------------------------------------------------------------
* If you have contact or find bugs,
* you can go to Github or email (MiracleForest@Outlook.com) to give feedback.
* We will try to do our best!
*/
#ifndef ___MIRACLEFOREST_I_TYPE_TRAITS___
#define ___MIRACLEFOREST_I_TYPE_TRAITS___

#include "../../family/imacrofamily.h"

#include <type_traits>
#include <string>
#include <concepts>

namespace i::core {
	namespace type {
		namespace type_traits {

			template <typename Type>
			struct is_std_string : std::false_type {};

			template<>
			struct is_std_string<std::string> : std::true_type {};

			template<>
			struct is_std_string<std::wstring> : std::true_type {};

			template <typename Type>
			constexpr bool is_std_string_v = is_std_string<Type>::value;

		}
	}
}
#endif //!___MIRACLEFOREST_I_TYPE_TRAITS___