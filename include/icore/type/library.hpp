/****
*
* Copyright(C) 2022 MiracleForest Studio. All Rights Reserved.
*
* @文件名：library.hpp
* @创建时间：2022.7.15.12:12
* @创建者：Lovelylavender4
* -----------------------------------------------------------------------------
* i动态库
* -----------------------------------------------------------------------------
* 如果你发现了bug，你可以去Github或邮箱(MiracleForest@Outlook.com)反馈给我们！
* 我们一定会努力做得更好的！
*
****/
#ifndef  ___MIRACLEFOREST_I_LIBRARY___
#define  ___MIRACLEFOREST_I_LIBRARY___

#include "../family/imacrofamily.h"
#include "istring.hpp"
#include "version.hpp"
#include "level.hpp"
#include <functional>
#include <vector>
#include <map>

SPACE(i) {
	SPACE(core) {

		struct ilibrary {
			type::istring filename;//库文件名
			type::istring name;//库名
			type::istring path;//库文件路径
			Version version;//版本
			handle _handle;//句柄
			type::istring dscription;//描述
			type::level _level;// 等级

			static ilibrary makeDefault() {
				ilibrary lib;
				lib.filename = "";
				lib.name = "";
				lib.path = "";
				lib.version = Version::makeDefault();
				lib._handle = NULL;
				lib.dscription = "";
				lib._level = 0;
				return lib;
			}

		};

		class Library {
		public:

			Library() {}

			~Library() {}

		public:

		public C_OPERATOR :


		public C_STATIC:

		public:
		protected:
		private:

		};//class Library

	}//SPACE(core)
}//SPACE(i)


#endif //! ___MIRACLEFOREST_I_LIBRARY___