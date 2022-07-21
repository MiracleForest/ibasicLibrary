/****
 *
 * Copyright(C) 2022 MiracleForest Studio. All Rights Reserved.
 *
 * @文件名：imacrofamily.h
 * @创建时间：2022.5.2.17:09
 * @创建者：Lovelylavender4
 * -----------------------------------------------------------------------------
 * 此文件定义了一些全局性的宏，别名等
 * -----------------------------------------------------------------------------
 * 如果你发现了bug，你可以去Github或邮箱(MiracleForest@Outlook.com)反馈给我们！
 * 我们一定会努力做得更好的！
 *
 ****/
#ifndef ___MIRACLEFOREST_I__LIBIO_CONSOLE_REDIRECTION___
#define ___MIRACLEFOREST_I__LIBIO_CONSOLE_REDIRECTION___

#include "../../../family/imacrofamily.h"
#include "../../../type/istring.hpp"

SPACE(i) {
	SPACE(core) {
		SPACE(libIO) {
			SPACE(console) {

				class IAPI Redirection
				{
				public:

					Redirection(void);

					~Redirection(void);
				public:

					bool runProcess(const type::iwstring& process);


					bool stopProcess(void);


					bool getOutput(int timeout, type::istring& outstr);


					bool setInput(const type::istring& cmd);

				private:
					handle _ChildInputWrite;
					handle _ChildInputRead;
					handle _ChildOutputWrite;
					handle _ChildOutputRead;
					PROCESS_INFORMATION CmdPI;

				};
			}
		}
	}
}

#endif//!___MIRACLEFOREST_I__LIBIO_CONSOLE_REDIRECTION___