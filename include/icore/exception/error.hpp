/*
*
* Copyright(C) 2022 MiracleForest Studio. All Rights Reserved.
*
* @filename:error.hpp
* @creation time:2022.5.19.13:09
* @created by:Lovelylavender4
* -----------------------------------------------------------------------------
* Contains the error class, and related content
* -----------------------------------------------------------------------------
* If you have contact or find bugs,
* you can go to Github or email (MiracleForest@Outlook.com) to give feedback.
* We will try to do our best!
*/
#ifndef ___MIRACLEFOREST_I_ERROR___
#define ___MIRACLEFOREST_I_ERROR___

#include "../../cppstd/string"
#include "../../cppstd/source_location"
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
                std::string _dscription;//描述
                std::string _suggestion;//建议
                type::FilePos _position;//位置
                type::level _level;//等级
                bool _canBeIgnored;//是否可以忽略
            };



            class error {
            private:

                error():_noError(1) {}

                error(ErrorInfo errorinfo)
                    :_errorinfo(errorinfo),
                    _noError(0) {}            

            public:
                ~error() {}
            public:
                

                /****
                * @author Lovelylavender4
                * @since 编写此代码的时间或版本
                * @brief 此错误是否可以忽略
                *
                * @future 未来要做的事情
                * @retval 此错误是否可以忽略
                *
                * @par Example
                * @code
                * 代码示例
                * @endcode
                * ...
                * if(!xxx.isCanBeIgnored){
                * ...
                * }
                * ...
                * @include 需要包含的头文件
                * @details
                * 此错误是否可以忽略
                * @enddetails
                ****/
                bool isCanBeIgnored() const{
                    return _errorinfo._canBeIgnored;
                }

                /****
                * @author Lovelylavender4
                * @since 编写此代码的时间或版本
                * @brief 描述
                *
                * @param 参数名 注释
                * @tparam 模板参数名 注释
                * @future 未来要做的事情
                * @retval 返回值注释
                * @throws 抛出的异常
                *
                * @note
                * 注意事项
                * @endnote
                * @pre 代码使用的前提条件
                * @par Example
                * @code
                * 代码示例
                * @endcode
                *
                * @warning 警告
                * @bug 存在的漏洞
                * @include 需要包含的头文件
                * @details
                * 详细描述
                * @enddetails
                * @other 其他
                ****/
                bool isNoError() {
                    return _noError;
                }

            public:                
                
                /****
                * @author Lovelylavender4
                * @brief 创建一个自定义的错误
                * @param _code 错诶代码
                * @param _dscription = "" 描述
                * @param _suggestion = "" 建议
                * @param _position = type::fPos::makeDefault() 位置
                * @param _level = 0 等级
                * @param _canBeIgnored = false 是否可以忽略
                * @retval 错误对象
                * @note 错诶代码
                * @par Example
                * @code
                * NULL
                * @endcode
                * @include <string>,filepos.hpp,level.hpp
                ****/
                static error make(
                    int _code,
                    std::string _dscription = "",
                    std::string _suggestion = "",
                    type::FilePos _position = type::fPos::makeDefault(),
                    type::level _level = 0,
                    bool _canBeIgnored = false
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

                /****
                * @author Lovelylavender4
                * @brief 创建一个错误
                * @param _code 代码
                * @future NULL
                * @retval error对象
                * @throws NULL
                * @note NULL
                * @par Example
                * @code
                * NULL
                * @endcode
                * @warning NULL
                * @bug NULL
                * @include NULL
                ****/
                static error make(
                    ErrorCode _code
                ) {
                    
                }

                /****
                * @author Lovelylavender4
                * @brief 无错误
                * @retval 错误对象
                * @par Example
                * 
                * @code
                * i::core::iexception::error testFunction(){
                * return i::core::iexception::error::noError();
                * }
                * @endcode
                * 
                * @warning NULL
                * @bug NULL
                ****/
                static error noError() {
                    return error();
                }

            public:
                
                /****
                * @author Lovelylavender4
                * @brief get ErrorInfo
                * @retval ErrorInfo 错误信息
                * @throws NULL
                * @note NULL
                * @par Example
                * @code
                * NULL
                * @endcode
                * @warning NULL
                * @bug NULL
                * @include NULL
                ****/
                ErrorInfo data()const {
                    return _errorinfo;
                }

            private:
                ErrorInfo _errorinfo;
                bool _noError;
            };//class error

        }//namespace iexception
    }//namespace core
}//namespace i


#endif //!___MIRACLEFOREST_I_ERROR___