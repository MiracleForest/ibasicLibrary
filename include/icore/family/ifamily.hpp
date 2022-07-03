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
			* @since 2022.7.2.21:03
			* @brief i程序的入口点
			*
			* @param p_start main参数包

			* @future 被用户实现
			* @retval IERROR 发生的错误
			*
			* @pre 被用户实现
			*
			* @include "error.h"
			* @details
			* i程序的入口点，ic++程序从此处开始执行
			* @enddetails
			****/
			IERROR start(_p_start& p_start);

		};
	}//SPACE(core)
}//SPACE(i)

/****
* @author Lovelylavender4
* @since 2022.7.2.20:39
* @brief C++程序的入口点
*
* @param argc argv中元素的个数
* @param argv 命令行参数
* @param envp 环境变量
* @future 完善main 
* @retval 结束代码
* 
* @warning 此函数不提供给用户调用，若想调用，请谨慎调用！
* 
* @include "error.hpp"
* @details
* C++程序的入口点，程序从此处开始执行
* @enddetails
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
	catch (const ::i::core::iexception::createErrorFailed& e) {
		return -3;
	}
	catch (...) {
		return -2;
	}
	return -1;
}


#endif //!___MIRACLEFOREST_I_IFAMILY___