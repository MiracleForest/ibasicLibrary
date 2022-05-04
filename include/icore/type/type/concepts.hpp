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

#include <type_traits>
#include "type_traits.hpp"


namespace i::core {

    /// <summary>
    /// Define concept arithmetic 
    /// </summary>
    template <typename T>
    concept arithmetic = std::is_arithmetic<T>::value;

    /// <summary>
    /// 
    /// </summary>
    template <typename T>
    concept stdString = i::core::type::type_traits::is_std_string_v<T>;


}
#endif //!___MIRACLEFOREST_I_CONCEPTS___