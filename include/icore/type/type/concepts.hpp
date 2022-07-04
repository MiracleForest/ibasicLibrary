/****
*
* Copyright(C) 2022 MiracleForest Studio. All Rights Reserved.
*
* @�ļ�����concepts.hpp
* @����ʱ�䣺2022.4.30.12:12
* @�����ߣ�Lovelylavender4
* -----------------------------------------------------------------------------
*
*
* -----------------------------------------------------------------------------
* ����㷢����bug�������ȥGithub������(MiracleForest@Outlook.com)���������ǣ�
* ����һ����Ŭ�����ø��õģ�
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