/****
 *
 * Copyright(C) 2022 MiracleForest Studio. All Rights Reserved.
 *
 * @�ļ�����imacrofamily.h
 * @����ʱ�䣺2022.5.2.17:09
 * @�����ߣ�Lovelylavender4
 * -----------------------------------------------------------------------------
 * ���ļ�������һЩȫ���Եĺ꣬������
 * -----------------------------------------------------------------------------
 * ����㷢����bug�������ȥGithub������(MiracleForest@Outlook.com)���������ǣ�
 * ����һ����Ŭ�����ø��õģ�
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