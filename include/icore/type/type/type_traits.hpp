/*
*
* Copyright(C) 2022 MiracleForest Studio. All Rights Reserved.
*
* @filename:type_traits.hpp
* @creation time:2022.4.26.13:00
* @created by:Lovelylavender4
* @project:iBasicLibrary-Type-Type_traits
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

#include "../../../cppstd/type_traits"
#include "../../../cppstd/string"
#include "../../../cppstd/concepts"

SPACE(i) {
	SPACE(core) {
		SPACE(type) {
			SPACE(type_traits) {

				template <typename Type>
				struct is_std_string : std::false_type {};

				template<>
				struct is_std_string<std::string> : std::true_type {};

				template<>
				struct is_std_string<std::wstring> : std::true_type {};

#ifdef __cpp_lib_char8_t
				template<>
				struct is_std_string<std::u8string> : std::true_type {};
#endif


				template<>
				struct is_std_string<std::u16string> : std::true_type {};

				template<>
				struct is_std_string<std::u32string> : std::true_type {};

				template <typename Type>
				constexpr bool is_std_string_v = is_std_string<Type>::value;

			}//SPACE(type_traits)
		}//SPACE(type)
	}//SPACE(core)
}//SPACE(i)

#endif //!___MIRACLEFOREST_I_TYPE_TRAITS___