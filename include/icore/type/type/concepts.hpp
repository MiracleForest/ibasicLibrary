/*
*
* Copyright(C) 2022 MiracleForest Studio. All Rights Reserved.
*
* @filename:concepts.hpp
* @creation time:2022.4.30.12:12
* @created by:Lovelylavender
* -----------------------------------------------------------------------------
* some concepts
* -----------------------------------------------------------------------------
* If you have contact or find bugs,
* you can go to Github or email (MiracleForest@Outlook.com) to give feedback.
* We will try to do our best!
*/
#ifndef ___MIRACLEFOREST_I_CONCEPTS___
#define ___MIRACLEFOREST_I_CONCEPTS___

#include "../../family/imacrofamily.h"
#include "../../../cppstd/type_traits"
#include "type_traits.hpp"

#ifndef __CPP_20__
#pragma message("The contents of <concepts> are available only with C++20 concepts support.")
#else

#include "../../../cppstd/concepts"

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