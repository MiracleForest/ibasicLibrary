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
			* @pre 使用此函数的前提条件
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
            virtual Type data() = 0;

        };//class ibasic_data_type : public ibasic<Type>
    }//namespace core
}//namespace i

#endif //!___MIRACLEFOREST_I_INASIC___