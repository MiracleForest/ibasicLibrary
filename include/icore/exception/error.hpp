/*
*
* Copyright(C) 2022 MiracleForest Studio. All Rights Reserved.
*
* @filename:error.hpp
* @creation time:2022.5.19.13:09
* @created by:Lovelylavender4
* -----------------------------------------------------------------------------
* Contains the error class, and related content
* 
* -----------------------------------------------------------------------------
* If you have contact or find bugs,
* you can go to Github or email (MiracleForest@Outlook.com) to give feedback.
* We will try to do our best!
*/
#ifndef ___MIRACLEFOREST_I_ERROR___
#define ___MIRACLEFOREST_I_ERROR___

#include <string>
#include "error.hpp"
#include "exception.hpp"
#include "errorcode.hpp"
#include "../family/imacrofamily.h"
#include "../type/filepos.hpp"
#include "../type/level.hpp"

namespace i {
    namespace core {
        namespace iexception {

            enum class ErrorCode;

            struct ErrorInfo {
                ErrorCode _code;
                int _icode;
                std::string _dscription;
                std::string _suggestion;
                type::FilePos _position;
                type::level _level;
                uint _canBeIgnored;
            };



            class error {
            private:
                error() {}
                error(ErrorInfo errorinfo)
                    :_errorinfo(errorinfo) {}
                ~error() {}
            public:

            public:
                /// <summary>
                /// 
                /// </summary>
                /// <param name="_code"></param>
                /// <param name="_dscription"></param>
                /// <param name="_suggestion"></param>
                /// <param name="_position"></param>
                /// <param name="_level"></param>
                /// <param name="_canBeIgnored"></param>
                /// <returns></returns>
                static error make(
                    int _code,
                    std::string _dscription = "",
                    std::string _suggestion = "",
                    type::FilePos _position = type::fPos::makeDefault(),
                    type::level _level = 0,
                    uint _canBeIgnored = 0
                ) {
                    ErrorInfo errorinfo;
                    errorinfo._code = ErrorCode::unkError;
                    errorinfo._icode = _code;
                    errorinfo._dscription = _dscription;
                    errorinfo._suggestion = _suggestion;
                    errorinfo._position = _position;
                    errorinfo._level = _level;
                    errorinfo._canBeIgnored = _canBeIgnored;
                    return errorinfo;
                }

                /// <summary>
                /// 
                /// </summary>
                /// <param name="_code"></param>
                /// <returns></returns>
                static error make(
                    ErrorCode _code
                ) {
                    
                }

                ErrorInfo data()const {
                    return _errorinfo;
                }
            private:
                ErrorInfo _errorinfo;
            };//class error

        }//namespace iexception
    }//namespace core
}//namespace i


#endif //!___MIRACLEFOREST_I_ERROR___