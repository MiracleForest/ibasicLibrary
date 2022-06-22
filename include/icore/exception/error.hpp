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
                std::string _dscription;//����
                std::string _suggestion;//����
                type::FilePos _position;//λ��
                type::level _level;//�ȼ�
                bool _canBeIgnored;//�Ƿ���Ժ���
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
                * @since ��д�˴����ʱ���汾
                * @brief �˴����Ƿ���Ժ���
                *
                * @future δ��Ҫ��������
                * @retval �˴����Ƿ���Ժ���
                *
                * @par Example
                * @code
                * ����ʾ��
                * @endcode
                * ...
                * if(!xxx.isCanBeIgnored){
                * ...
                * }
                * ...
                * @include ��Ҫ������ͷ�ļ�
                * @details
                * �˴����Ƿ���Ժ���
                * @enddetails
                ****/
                bool isCanBeIgnored() const{
                    return _errorinfo._canBeIgnored;
                }

                /****
                * @author Lovelylavender4
                * @since ��д�˴����ʱ���汾
                * @brief ����
                *
                * @param ������ ע��
                * @tparam ģ������� ע��
                * @future δ��Ҫ��������
                * @retval ����ֵע��
                * @throws �׳����쳣
                *
                * @note
                * ע������
                * @endnote
                * @pre ����ʹ�õ�ǰ������
                * @par Example
                * @code
                * ����ʾ��
                * @endcode
                *
                * @warning ����
                * @bug ���ڵ�©��
                * @include ��Ҫ������ͷ�ļ�
                * @details
                * ��ϸ����
                * @enddetails
                * @other ����
                ****/
                bool isNoError() {
                    return _noError;
                }

            public:                
                
                /****
                * @author Lovelylavender4
                * @brief ����һ���Զ���Ĵ���
                * @param _code ��������
                * @param _dscription = "" ����
                * @param _suggestion = "" ����
                * @param _position = type::fPos::makeDefault() λ��
                * @param _level = 0 �ȼ�
                * @param _canBeIgnored = false �Ƿ���Ժ���
                * @retval �������
                * @note ��������
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
                * @brief ����һ������
                * @param _code ����
                * @future NULL
                * @retval error����
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
                * @brief �޴���
                * @retval �������
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
                * @retval ErrorInfo ������Ϣ
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