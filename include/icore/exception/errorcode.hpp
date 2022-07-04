/****
*
* Copyright(C) 2022 MiracleForest Studio. All Rights Reserved.
*
* @文件名：errorcode.hpp
* @创建时间：2022.5.19.13:12
* @创建者：Lovelylavender4
* -----------------------------------------------------------------------------
*
*
* -----------------------------------------------------------------------------
* 如果你发现了bug，你可以去Github或邮箱(MiracleForest@Outlook.com)反馈给我们！
* 我们一定会努力做得更好的！
*
****/
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