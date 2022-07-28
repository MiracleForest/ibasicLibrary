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
#include "../exception/error.hpp"
#include <functional>
#include <vector>
#include <map>


SPACE(i) {
	SPACE(core) {

		enum class Library::LibraryType;

		struct ilibrary {
			type::istring filename;//库文件名
			type::istring name;//库名
			type::istring path;//库文件路径
			Version version;//版本
			handle _handle;//句柄
			type::istring dscription;//描述
			type::level _level;// 等级
			std::map<std::string, std::string> others;//其他
			Library::LibraryType type;

			static ilibrary makeDefault() {
				ilibrary lib;
				lib.filename = "";
				lib.name = "";
				lib.path = "";
				lib.version = Version::makeDefault();
				lib._handle = NULL;
				lib.dscription = "";
				lib._level = 0;
				lib.others = { };
				lib.type = Library::LibraryType::unk;
				return lib;
			}

		};

		class Library {
		public:
			enum class LibraryType
			{
				unk,
				dll,
				so
			};
		public:

			Library() :library(ilibrary::makeDefault()) {}

			Library(ilibrary _library):library(_library) {}

			Library(type::istring libfname) {
				library.filename = libfname;
			}

			~Library() {}

		public:

			IERROR load() {
				if ( !(library.filename == "") ) {
#ifdef __WINDOWS__
					library._handle = LoadLibrary(type::istring::str2wstr(library.filename.data()).data());
					if ( !library._handle ) {
						return IERROR::make(iexception::ErrorCode::loadDynamicLinkLibraryFailed, std::source_location::current());
					}
					return IERROR::noError();
#endif
				}
				else {

				}
			}

			template <typename ReturnType = void, typename... Args>
			ReturnType call(const char* functionSymbol, Args... args)
			{
#ifdef __WINDOWS__
				void* address = GetProcAddress(library._handle, functionSymbol);
				if ( !address ) {
					return ReturnType();
				}
				return reinterpret_cast<ReturnType(*)(Args...)>(address)(std::forward<Args>(args)...);
#endif
			}

			public C_OPERATOR :


			public C_STATIC :

		public:
		protected:
		private:
			ilibrary library;
		};//class Library

	}//SPACE(core)
}//SPACE(i)


#endif //! ___MIRACLEFOREST_I_LIBRARY___