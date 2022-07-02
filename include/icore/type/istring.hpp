/*
*
* Copyright(C) 2022 MiracleForest Studio. All Rights Reserved.
*
* @filename:istring.hpp
* @creation time:2022.6.6.13:25
* @created by:Lovelylavender4
* -----------------------------------------------------------------------------
*
*
* -----------------------------------------------------------------------------
* If you have contact or find bugs,
* you can go to Github or email (MiracleForest@Outlook.com) to give feedback.
* We will try to do our best!
*/
#ifndef ___MIRACLEFOREST_I_ISTRING___
#define ___MIRACLEFOREST_I_ISTRING___

#include "../family/imacrofamily.h"
#include "basic/istring.hpp"

SPACE(i) {
    SPACE(core) {
        SPACE(type) {
                using istring = basic::basic_istring<std::string>;
                using iwstring = basic::basic_istring<std::wstring>;
#ifdef __cpp_lib_char8_t
                using iu8string = basic::basic_istring<std::u8string>;
#endif // __cpp_lib_char8_t
                using iu16string = basic::basic_istring<std::u16string>;
                using iu32string = basic::basic_istring<std::u32string>;
        }//SPACE(type)
    }//SPACE(core)
}//SPACE(i)


#endif //!___MIRACLEFOREST_I_ISTRING___