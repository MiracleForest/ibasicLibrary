/*
*
* Copyright(C) 2022 MiracleForest Studio. All Rights Reserved.
*
* @文件名:ifamily.hpp
* @创建时间:2022.5.26.13:13
* @创建者:Lovelylavender4
* -----------------------------------------------------------------------------
* mian函数所在地,i程序的入口点
* -----------------------------------------------------------------------------
* 如果你发现了bug，你可以去Github或邮箱(MiracleForest@Outlook.com)反馈给我们！
* 我们一定会努力做得更好的！
*/
#ifndef ___MIRACLEFOREST_I_IFAMILY___
#define ___MIRACLEFOREST_I_IFAMILY___

#include "imacrofamily.h"

#include "../exception/error.hpp"

SPACE(i) {
	SPACE(core) {
		struct _p_start {
			int argc;
			char** argv;
			char** envp;
		};

		class Main {
		public:
			Main() {}
			~Main() {}
		public:
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
			IERROR start(_p_start& p_start);

		};
	}//SPACE(core)
}//SPACE(i)

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
int main(int argc, char** argv, char** envp) {
	try {
		N_ISTD _p_start p_start;
		p_start.argc = argc;
		p_start.argv = argv;
		p_start.envp = envp;

		N_ISTD Main appMain;
		IERROR rt = appMain.start(p_start);

		if (rt.isNoError()) {
			return 0;
		}
		if (rt.isCanBeIgnored()) {
			return 1;
		}
	}
	catch (...) {
		return -2;
	}
	return -1;
}


#endif //!___MIRACLEFOREST_I_IFAMILY___