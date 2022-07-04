/****
*
* Copyright(C) 2022 MiracleForest Studio. All Rights Reserved.
*
* @文件名：concepts.hpp
* @创建时间：2022.4.30.12:12
* @创建者：Lovelylavender4
* -----------------------------------------------------------------------------
*
*
* -----------------------------------------------------------------------------
* 如果你发现了bug，你可以去Github或邮箱(MiracleForest@Outlook.com)反馈给我们！
* 我们一定会努力做得更好的！
*
****/
#ifndef ___MIRACLEFOREST_I_CONCEPTS___
#define ___MIRACLEFOREST_I_CONCEPTS___

#include "../../family/imacrofamily.h"
#include <type_traits>
#include "type_traits.hpp"

#ifndef __CPP_20__
#pragma message("The contents of <concepts> are available only with C++20 concepts support.")
#else

#include <concepts>

SPACE(i) {
    SPACE(core) {

        template <typename T>
        concept arithmetic = std::is_arithmetic<T>::value;


        template <typename T>
        concept stdString = i::core::type::type_traits::is_std_string_v<T>;

    }//SPACE(core)
}//SPACE(i)

#endif//!__CPP_20__

#endif //!___MIRACLEFOREST_I_CONCEPTS___