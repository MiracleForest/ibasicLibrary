/****
*
* Copyright(C) 2022 MiracleForest Studio. All Rights Reserved.
*
* @文件名:error.hpp
* @创建时间:2022.5.19.13:09
* @创建者:Lovelylavender4
* -----------------------------------------------------------------------------
* 包含错误类，错误枚举类型
* -----------------------------------------------------------------------------
* 如果你发现了bug，你可以去Github或邮箱(MiracleForest@Outlook.com)反馈给我们！
* 我们一定会努力做得更好的！
* 
****/
#ifndef ___MIRACLEFOREST_I_ERROR___
#define ___MIRACLEFOREST_I_ERROR___

#include "../../cppstd/string"
#include "../../cppstd/source_location"
#include "exception.hpp"
#include "errorcode.hpp"
#include "../family/imacrofamily.h"
#include "../type/filepos.hpp"
#include "../type/level.hpp"

SPACE(i) {
    SPACE(core) {
        SPACE(iexception) {

            struct ErrorInfo {
                ErrorCode _code;
                int _icode;
                std::string _dscription;//描述
                std::string _dscription2;//详细描述
                std::string _suggestion;//建议
                type::FilePos _position;//位置
                type::level _level;//等级
                bool _canBeIgnored;//是否可以忽略

                ErrorInfo makeDefault() {
                    ErrorInfo e;
                    e._code = ErrorCode::unkError;
                    e._icode = -1;
                    e._dscription = "";
                    e._dscription2 = "";
                    e._suggestion = "";
                    e._position = type::fPos::makeDefault();
                    e._level = -1;
                    e._canBeIgnored = false;
                    return e;
                }
            };



            class error {
            private:

                error():_noError(1) {}

                error(ErrorInfo errorinfo)
                    :_errorinfo(errorinfo),
                    _noError(0) {}            

                ~error() {}
            public:
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

            public C_STATIC:                
                
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
                    std::string _dscription2 = "",
                    std::string _suggestion = "",
                    type::FilePos _position = type::fPos::makeDefault(),
                    type::level _level = 0,
                    bool _canBeIgnored = false
                ) {

                    ErrorInfo errorinfo;

                    errorinfo._code = ErrorCode::unkError;
                    errorinfo._icode = _code;
                    errorinfo._dscription = _dscription;
                    errorinfo._dscription2 = _dscription2;
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
                    ErrorCode _code,
                    type::FilePos _position = type::fPos::makeDefault()
                ) {
                    ErrorInfo errorinfo;
                    if (_code == ErrorCode::unkError) {
                        errorinfo._code = ErrorCode::unkError;
                        errorinfo._icode = -1;
                        errorinfo._dscription = "未知的错误！";
                        errorinfo._dscription2 = "此错误未被记载！是未知的错误！";
                        errorinfo._suggestion = "仔细检查代码，或向i官方反馈并提交此错误！";
                        errorinfo._position = _position;
                        errorinfo._level = -1;
                        errorinfo._canBeIgnored = false;
                        return errorinfo;
                    }
                    else {
                        errorinfo._code = ErrorCode::errorError;
                        errorinfo._icode = -2;
                        errorinfo._dscription = "在构建错误时发生了严重的错误！";
                        errorinfo._dscription2 = "在构建错误时发生了严重的错误！此错误不可忽略！";
                        errorinfo._suggestion = "仔细检查代码中引发此错误的地方，确定参数_code是有效！";
                        errorinfo._position = _position;
                        errorinfo._level = -1;
                        errorinfo._canBeIgnored = false;
                        return errorinfo;
                    }
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

                static error errorError() {
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

        }//SPACE(iexception)
    }//SPACE(core)
}//SPACE(i)


#endif //!___MIRACLEFOREST_I_ERROR___