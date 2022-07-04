/****
*
* Copyright(C) 2022 MiracleForest Studio. All Rights Reserved.
*
* @文件名：istring.hpp
* @创建时间：2022.6.6.13:25
* @创建者：Lovelylavender4
* -----------------------------------------------------------------------------
*
*
* -----------------------------------------------------------------------------
* 如果你发现了bug，你可以去Github或邮箱(MiracleForest@Outlook.com)反馈给我们！
* 我们一定会努力做得更好的！
*
****/
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