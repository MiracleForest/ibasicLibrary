/****
*
* Copyright(C) 2022 MiracleForest Studio. All Rights Reserved.
*
* @文件名：cpp.hpp
* @创建时间：2022.7.28.10:58
* @创建者：Lovelylavender4
* -----------------------------------------------------------------------------
* 
* -----------------------------------------------------------------------------
* 如果你发现了bug，你可以去Github或邮箱(MiracleForest@Outlook.com)反馈给我们！
* 我们一定会努力做得更好的！
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