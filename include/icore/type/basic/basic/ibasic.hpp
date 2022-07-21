/****
*
* Copyright(C) 2022 MiracleForest Studio. All Rights Reserved.
*
* @文件名：ibasic.hpp
* @创建时间：2022.4.30.11:53
* @创建者：Lovelylavender4
* -----------------------------------------------------------------------------
* 所有i类的根基类
* -----------------------------------------------------------------------------
* 如果你发现了bug，你可以去Github或邮箱(MiracleForest@Outlook.com)反馈给我们！
* 我们一定会努力做得更好的！
*
****/
#ifndef ___MIRACLEFOREST_I_INASIC___
#define ___MIRACLEFOREST_I_INASIC___

#include "../../../family/imacrofamily.h"
#include "../../type/type.hpp"

SPACE(i) {
	SPACE(core) {
		SPACE(basic) {

			template<typename Type>
			class ibasic {

				virtual itype getType() = 0;

			};//class ibasic



			template<typename Type>
			class ibasic_data_type : public ibasic<Type> {

				virtual Type data() = 0;

			};//class ibasic_data_type : public ibasic<Type>


		}//SPACE(basic)
	}//SPACE(core)
}//SPACE(i)

#endif //!___MIRACLEFOREST_I_INASIC___