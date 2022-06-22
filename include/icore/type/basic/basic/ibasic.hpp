/*
*
* Copyright(C) 2022 MiracleForest Studio. All Rights Reserved.
*
* @filename ibasic.hpp
* @creation time:2022.4.30.11:53
* @created by:Lovelylavender4
* -----------------------------------------------------------------------------
* Base pure virtual class for all i classes
* -----------------------------------------------------------------------------
* If you have contact or find bugs,
* you can go to Github or email (MiracleForest@Outlook.com) to give feedback.
* We will try to do our best!
*/

#ifndef ___MIRACLEFOREST_I_INASIC___
#define ___MIRACLEFOREST_I_INASIC___

#include "../../../family/imacrofamily.h"
#include "../../type/type.hpp"

namespace i{
    namespace core {
        

        template<typename Type>
        class ibasic {

        };//class ibasic

        

        template<typename Type>
        class ibasic_data_type : public ibasic<Type> {
            
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
			* @pre ʹ�ô˺�����ǰ������
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
            virtual Type data() = 0;

        };//class ibasic_data_type : public ibasic<Type>
    }//namespace core
}//namespace i

#endif //!___MIRACLEFOREST_I_INASIC___