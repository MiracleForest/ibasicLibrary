/*
*
* Copyright(C) 2022 MiracleForest Studio. All Rights Reserved.
*
* @filename:ifamily.hpp
* @creation time:2022.5.26.13:13
* @created by:Lovelylavender4
* -----------------------------------------------------------------------------
*
*
* -----------------------------------------------------------------------------
* If you have contact or find bugs,
* you can go to Github or email (MiracleForest@Outlook.com) to give feedback.
* We will try to do our best!
*/
#ifndef ___MIRACLEFOREST_I_IFAMILY___
#define ___MIRACLEFOREST_I_IFAMILY___

#include "imacrofamily.h"

#include "../exception/error.hpp"

namespace i {
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
			IERROR start(_p_start& p_start);

		};
	}
}
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