/*
*
* Copyright(C) 2022 MiracleForest Studio. All Rights Reserved.
*
* @filename:errorcode.hpp
* @creation time:2022.5.19.13:12
* @created by:Lovelylavender4
* -----------------------------------------------------------------------------
*
*
* -----------------------------------------------------------------------------
* If you have contact or find bugs,
* you can go to Github or email (MiracleForest@Outlook.com) to give feedback.
* We will try to do our best!
*/
#ifndef ___MIRACLEFOREST_I_ERRORCODE___
#define ___MIRACLEFOREST_I_ERRORCODE___

#include "../family/imacrofamily.h"

SPACE(i) {
    SPACE(core) {
        SPACE(iexception) {

            enum class ErrorCode {
                unkError = -1,
                /*1*/createErrorFailed = -2
            };

        }//SPACE(iexception)
    }//SPACE(core)
}//SPACE(i)


#endif //!___MIRACLEFOREST_I_ERRORCODE___