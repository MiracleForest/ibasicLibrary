/****
*
* Copyright(C) 2022 MiracleForest Studio. All Rights Reserved.
*
* @文件名：exception.hpp
* @创建时间：2022.4.30.18:25
* @创建者：Lovelylavender4
* -----------------------------------------------------------------------------
* 此文件包含i异常类的定义
* -----------------------------------------------------------------------------
* 如果你发现了bug，你可以去Github或邮箱（MiracleForest@Outlook.com）反馈给我们！
* 我们一定会努力做得更好的！
*
****/
#ifndef ___MIRACLEFOREST_I_EXCEPTION___
#define ___MIRACLEFOREST_I_EXCEPTION___

#include <exception>
#include "../../icore/type/istring.hpp"

SPACE(i) {
    SPACE(core) {
        SPACE(iexception) {

            class createErrorFailed {
            public:
                createErrorFailed() = delete;
                createErrorFailed(CPtr<char> errorMsg) :emsg(errorMsg) {}
            public:
                CPtr<char> what()const {
                    return emsg;
                }
            private:
                CPtr<char> emsg;
            };

        }//SPACE(iexception)
    }//SPACE(core)
}//SPACE(i)

#endif //!___MIRACLEFOREST_I_EXCEPTION___