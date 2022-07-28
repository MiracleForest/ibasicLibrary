/****
*
* Copyright(C) 2022 MiracleForest Studio. All Rights Reserved.
*
* @�ļ�����cpp.hpp
* @����ʱ�䣺2022.7.28.10:58
* @�����ߣ�Lovelylavender4
* -----------------------------------------------------------------------------
* 
* -----------------------------------------------------------------------------
* ����㷢����bug�������ȥGithub������(MiracleForest@Outlook.com)���������ǣ�
* ����һ����Ŭ�����ø��õģ�
*
****/
#ifndef ___MIRACLEFOREST_I__INNOVATION_CPP___
#define ___MIRACLEFOREST_I__INNOVATION_CPP___

#include "../../../../../include/icore/family/imacrofamily.h"
#include "../../../../../include/icore/type/istring.hpp"
#include <map>

SPACE(i) {
	SPACE(core) {
		SPACE(innovation) {

			struct cppVariant {
				type::istring code;
				type::istring type;
				type::istring name;
				type::istring value;
				int startLine;
				int endLine;
			};

			enum class preprocessor {
				_define,
				_include,
				_if,
				_else,
				_elif,
				_ifdef,
				_ifndef,
				_endif,
				_line,
				_error,
				_import,
				_pragma,
				_undef,
				_using,
				_unk
			};

			struct cppPreprocessor {
				preprocessor type;
				int startLine;
				int endLine;
				type::istring code;

			};

			struct cppNote {

			};

			struct cppNamespace {

			};

			struct cppStruct {

			};

			struct cppClass {

			};

			struct cppFunction {

			};

			struct cppTemplate {

			};

			struct cppFunctionCall {

			};

			struct cppConditionalJudgment {

			};

			struct cppCirculation {

			};

			struct cppExceptionHandling {

			};
			


		}
	}//SPACE(core)
}//SPACE(i)


#endif //!___MIRACLEFOREST_I__INNOVATION_CPP___