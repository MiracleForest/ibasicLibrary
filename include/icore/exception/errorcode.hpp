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

            enum class ErrorCode : int{
                unkError = -1,
                createErrorFailed = -2,
                loadDynamicLinkLibraryFailed = -1000,
				initializationWinsockFailed = -1001,
				socketError=-1002,
				bindError = -1003,
				listenError = -1004,
				acceptError = -1005,
				sendFailed = -1006,
				recvFailed = -1007,
				portTooSmall = -1008,
				maxcouTooBig = -1009,
				connectFailed = -1010,
				unsupportedOperations = -1011,
				connecting = -1012,
				noConnected = -1013,
				changeError = -1014,
				theMaximumNumberOfConnectionsHasBeenReached = -1015,
				theClientIsDisconnected = -1016

            };

        }//SPACE(iexception)
    }//SPACE(core)
}//SPACE(i)


#endif //!___MIRACLEFOREST_I_ERRORCODE___