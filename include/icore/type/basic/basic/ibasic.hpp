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
        /// <summary>
        /// 
        /// </summary>
        /// <typeparam name="Type"></typeparam>
        template<typename Type>
        class ibasic {

        };//class ibasic

        /// <summary>
        /// 
        /// </summary>
        /// <typeparam name="Type"></typeparam>
        /// <warning></warning>
        template<typename Type>
        class ibasic_data_type : public ibasic<Type> {
            /// <summary>
            /// 
            /// </summary>
            /// <returns></returns>
            virtual Type data() = 0;

        };//class ibasic_data_type : public ibasic<Type>
    }
}//namespace i

#endif //!___MIRACLEFOREST_I_INASIC___