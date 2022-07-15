/****
*
* Copyright(C) 2022 MiracleForest Studio. All Rights Reserved.
*
* @文件名：version.hpp
* @创建时间：2022.7.14.12:32
* @创建者：Lovelylavender4
* -----------------------------------------------------------------------------
* i版本结构体
* -----------------------------------------------------------------------------
* 如果你发现了bug，你可以去Github或邮箱(MiracleForest@Outlook.com)反馈给我们！
* 我们一定会努力做得更好的！
*
****/
#ifndef ___MIRACLEFOREST_I_VERSION___
#define ___MIRACLEFOREST_I_VERSION___

#include "../family/imacrofamily.h"
#include "istring.hpp"


SPACE(i) {
	SPACE(core) {

		struct Version {

			enum Status
			{
				Unk,
				Dev,
				Beta,
				Release
			};

			int macro;//宏版本
			int major;//主版本
			int minor;//次版本
			int revision;//修订版本
			type::istring branch;//分支
			uint64 numberOfBuilds;//构建次数
			Status status;

			static Version makeDefault() {
				Version v;
				v.macro = 0;
				v.major = 0;
				v.minor = 0;
				v.revision = 0;
				v.branch = "master";
				v.numberOfBuilds = 0;
				v.status = Status::Unk;
				return v;
			}
		};

	}//SPACE(core)
}//SPACE(i)


#endif //!___MIRACLEFOREST_I_VERSION___