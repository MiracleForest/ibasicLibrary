/*
*
* Copyright(C) 2022 MiracleForest Studio. All Rights Reserved.
*
* @filename:ifamily.hpp
* @creation time:2022.5.26.13:13
* @created by:Lovelylavender4
* -----------------------------------------------------------------------------
* 
* 
* -----------------------------------------------------------------------------
* If you have contact or find bugs,
* you can go to Github or email (MiracleForest@Outlook.com) to give feedback.
* We will try to do our best!
*/
#ifndef ___MIRACLEFOREST_I_IFAMILY___
#define ___MIRACLEFOREST_I_IFAMILY___

#include "imacrofamily.h"

#include "../exception/error.hpp"


i::core::iexception::error start();


int main() {

    auto rt = start();
    if (rt.isNoError()) {
        return 0;
    }
    if (rt.isCanBeIgnored()) {
        return 1;
    }

    return -1;
}


#endif //!___MIRACLEFOREST_I_IFAMILY___