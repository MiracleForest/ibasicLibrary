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

#pragma warning(disable:4996)
#pragma warning(disable:4819)

#include "../../cppstd/string"
#include "../../cppstd/source_location"
#include "exception.hpp"
#include "errorcode.hpp"
#include "../family/imacrofamily.h"
#include "../type/filepos.hpp"
#include "../type/level.hpp"

#ifndef ___ERROR_MAP
// ErrorCode, icode, description, description2, suggestion, level, canIgnore
#define ___ERROR_MAP( XX ) \
    XX (unkError, -1, "未知的错误！", "此错误未被记载！是未知的错误！", "仔细检查代码，或向i官方反馈并提交此错误！", -1, false)\
    XX (createErrorFailed, -2, "创建错误失败！", "创建错误失败！在构建错误时发生了严重的错误！此错误不可忽略！", "仔细检查代码中引发此错误的地方，例如确定参数code是有效！", -1, false)
#else

#endif//!___ERROR_MAP

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
            public:
                enum class EMT {//error message type
                    errorCode_enum,
                    errorCode_int,
                    dscription,
                    dscription2,
                    suggestion,
                    level
                };
            private:

                error() :_noError(1) {}

                error(ErrorInfo errorinfo)
                    :_errorinfo(errorinfo),
                    _noError(0) {}
            public:

                ~error() {}


                /****
                * @author Lovelylavender4
                * @since 2022.7.2.9:52
                * @brief 此错误是否可以忽略
                *
                * @retval 此错误是否可以忽略
                *
                * @par Example
                * @code
                * auto e=fun();//IERROR fun();
                * if(!e.isNoError()){
                *     if(e.isCanBeIgnored()){
                *
                *     }
                *     else{
                *
                *     }
                * }
                * @endcode
                *
                *
                * @include -
                * @details
                * 此错误是否可以忽略
                * @enddetails
                ****/
                bool isCanBeIgnored() const {
                    return _errorinfo._canBeIgnored;
                }

                /****
                * @author Lovelylavender4
                * @since 2022.7.2.9:55
                * @brief 是否没有错误
                *
                * @retval 是否没有错误
                *
                * @par Example
                * @code
                * auto e=fun();//IERROR fun();
                * if(!e.isNoError()){
                *
                * }
                * @endcode
                *
                * @include -
                * @details
                * 是否没有错误
                * @enddetails
                ****/
                bool isNoError() {
                    return _noError;
                }

                public C_STATIC:

                /****
                * @author Lovelylavender4
                * @since 2022.7.2.9:55
                *
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
                * IERROR fun(){
                *     return error::make(-123,"...","...","...",{"...",1,1},10,false);
                * }
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
                * @since 2022.7.2.10:05
                * @brief 创建一个已有的错误
                *
                * @param _code 错误代码
                * @param _position = type::fPos::makeDefault() 错误位置
                * @future 根据参数_code找到此错误的ErrorInfo，并创建error
                * @retval 创建完毕的错误
                *
                * @note
                * _code必须是有效的错误代码
                * @endnote
                * @pre 检测到代码发生了错误
                * @par 示例
                * @code
                * IERROR fun(){
                *     return error::make(ErrorCode::xxx,{"...",1,1});
                * }
                * @endcode
                *
                * @warning 若_code无效，会抛出createErrorFailed异常
                * @include errorcode.hpp,filepos.hpp
                * @details
                * 创建一个已有的错误
                * @enddetails
                ****/
                static error make(
                    ErrorCode code,
                    type::FilePos position = type::fPos::makeDefault()
                ) {
                    ErrorInfo errorinfo;
                    try {
                        errorinfo = getErrorInfoFrom(EMT::errorCode_enum, code);
                        errorinfo._position = position;
                    }
                    catch (...) {
                        throw createErrorFailed("错误！参数code是无效的！");
                    }
                    return errorinfo;
                }

                /****
                * @author Lovelylavender4
                * @brief 无错误
                * @retval 错误对象
                *
                * @par 示例
                * @code
                * i::core::iexception::error testFunction(){
                * return i::core::iexception::error::noError();
                * }
                * @endcode
                ****/
                static error noError() {
                    return error();
                }

                /**
                * @author Ticks
                * @since 22-7-2 下午1:32
                *
                * @brief 通过错误代码、错误信息描述、错误级别等获取错误信息(ErrorInfo)
                *
                * @param emt EMT枚举类型
                * @param emsg 枚举对应类型
                * @tparam emsg_t 通过emsg_t类型获取
                * @retval ErrorInfo 错误信息结构体
                * 
                * @note
                * emsg类型需要与emt枚举中类型对应，否则会发生未定义错误
                * @endnote
                * @pre 示例
                * @code
                * ErrorInfo info = getErrorInfo(EMT::errorCode_int, -1);
                * std::cout << "错误描述: " << info.dscription << std::endl;
                * @endcode
                * 
                * @include error.hpp
                * @details
                * 详细描述
                * @enddetails
                * 
                * @warning  
                * @bug 
                * 
                **/
                template<class emsg_t>
                static ErrorInfo getErrorInfoFrom(EMT emt, emsg_t emsg) {
                    auto hash_ = [](const std::string& str) -> size_t {
                        return std::hash<std::string>{}(str);
                    };
                    if (emt == EMT::errorCode_enum) {
                        switch (emsg) {
#define XX(Error, icode, des, des2, sug, level, ignore) case ErrorCode:: Error: \
            return ErrorInfo{ErrorCode:: Error, icode, des, des2, sug, type::fPos::makeDefault(), level, ignore};
                            ___ERROR_MAP(XX)
#undef XX
                        }
                    }
                    else if (emt == EMT::errorCode_int) {
                        switch (emsg) {
#define XX(Error, icode, des, des2, sug, level, ignore) case icode: \
            return ErrorInfo{ErrorCode:: Error, icode, des, des2, sug, type::fPos::makeDefault(), level, ignore};
                            ___ERROR_MAP(XX)
#undef XX
                        }
                    }
                    else if (emt == EMT::dscription) {
                        switch (hash_(emsg)) {
#define XX(Error, icode, des, des2, sug, level, ignore) case hash_(des): \
            return ErrorInfo{ErrorCode:: Error, icode, des, des2, sug, type::fPos::makeDefault(), level, ignore};
                            ___ERROR_MAP(XX)
#undef XX
                        }
                    }
                    else if (emt == EMT::dscription2) {
                        switch (hash_(emsg)) {
#define XX(Error, icode, des, des2, sug, level, ignore) case hash_(des2): \
            return ErrorInfo{ErrorCode:: Error, icode, des, des2, sug, type::fPos::makeDefault(), level, ignore};
                            ___ERROR_MAP(XX)
#undef XX
                        }
                    }
                    else if (emt == EMT::suggestion) {
                        switch (hash_(emsg)) {
#define XX(Error, icode, des, des2, sug, level, ignore) case hash_(sug): \
            return ErrorInfo{ErrorCode:: Error, icode, des, des2, sug, type::fPos::makeDefault(), level, ignore};
                            ___ERROR_MAP(XX)
#undef XX
                        }
                    }
                    else if (emt == EMT::level) {
                        switch (emsg) {
#define XX(Error, icode, des, des2, sug, level, ignore) case level: \
            return ErrorInfo{ErrorCode:: Error, icode, des, des2, sug, type::fPos::makeDefault(), level, ignore};
                            ___ERROR_MAP(XX)
#undef XX
                        }
                    }
                    throw -1;
                }

            public:

                /****
                * @author Lovelylavender4
                * @brief 获取错误信息
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

                ErrorInfo getErrorInfo()const {
                    return _errorinfo;
                }

            private:
                ErrorInfo _errorinfo;
                bool _noError;
            };//class error

        }//SPACE(iexception)
    }//SPACE(core)
}//SPACE(i)


#undef ___ERROR_MAP

#endif //!___MIRACLEFOREST_I_ERROR___