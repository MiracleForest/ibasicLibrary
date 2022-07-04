/****
*
* Copyright(C) 2022 MiracleForest Studio. All Rights Reserved.
*
* @文件名：type.hpp
* @创建时间：2022.4.30.12:06
* @创建者：Lovelylavender4
* -----------------------------------------------------------------------------
*
*
* -----------------------------------------------------------------------------
* 如果你发现了bug，你可以去Github或邮箱(MiracleForest@Outlook.com)反馈给我们！
* 我们一定会努力做得更好的！
*
****/
#ifndef ___MIRACLEFOREST_I_TYPE___
#define ___MIRACLEFOREST_I_TYPE___

#include "../../family/imacrofamily.h"
#if __WIN32__
#include <windows.h>
#include <stringapiset.h>
#include <atlstr.h>
#endif
#include <string>


SPACE(i) {
	SPACE(core) {

		enum class typeList {
			unkType,
			itype,
			basic_number,
			numberArray_const_iterator,
			numberArray_iterator,
			numberArray,
			basic_istring
			
		};
		using iType = typeList;


		class itype {
		public:
			itype() :mType(iType::unkType) { }

			itype(iType t) :mType(t) { }

			itype(CRef<itype>) = delete;

			void operator=(CRef<itype>) = delete;

			~itype() {}
		public:

			/****
			* @author Lovelylavender4
			* @since 2022.6.21.13:25
			* @brief 获取类型枚举
			*
			* @retval 获取到的类型枚举
			*
			* @par Example
			* @code
			* 代码示例
			* @endcode
			*
			* @include -
			* @details
			* 获取类型枚举
			* @enddetails
			****/
			itype getType()const {
				return typeList::itype;
			}

			iType data()const { return mType; }

			/****
			* @author Lovelylavender4
			* @since 2022.6.21.13:28
			* @brief 设置mType的值
			*
			* @param t mType的新值
			*
			* @par Example
			* @code
			* 代码示例
			* @endcode
			*
			* @include -
			* @details
			* 设置mType的值
			* @enddetails
			****/
			void setdata(iType t) { mType = t; }

		public C_STATIC:
			 
			/****
			* @author Lovelylavender4
			* @since 2022.6.21.13:30
			* @brief 获取类型枚举的字符串名称
			*
			* @param t 类型枚举
			* @retval 类型枚举的字符串名称
			*
			* @par Example
			* @code
			* 代码示例
			* @endcode
			*
			* @details
			* 获取类型枚举的字符串名称
			* @enddetails
			****/
			static CPtr<char> getString(iType t) {
				switch (t) {
				case iType::unkType: {
					return "unkType";
				}
				case iType::itype: {
					return "itype";
				}
				case iType::basic_number: {
					return "basic_number";
				}
				case iType::numberArray_const_iterator: {
					return "numberArray_const_iterator";
				}
				case iType::numberArray_iterator: {
					return "numberArray_iterator";
				}
				case iType::numberArray: {
					return "numberArray";
				}
				case iType::basic_istring:{
					return "basic_istring";
				}
				default: {
					return "unk-Type";
				}
				}
			}

			/****
			* @author Lovelylavender4
			* @since 2022.6.21.13:34
			* @brief 获取类型的字符串名称
			*
			* @tparam Type 类型
			* @retval 类型的字符串名称
			*
			* @par Example
			* @code
			* 代码示例
			* @endcode
			*
			* @include 需要包含的头文件
			* @details
			* 获取类型的字符串名称
			* @enddetails
			****/
			template<typename Type>
			static CPtr<char> getTypeString() {
				return typeid(Type).name();
			}

			/****
			* @author Lovelylavender4
			* @since 2022.6.21.13:35
			* @brief 获取类型的字符串名称
			*
			* @param t -
			* @retval 类型的字符串名称
			*
			* @par Example
			* @code
			* 代码示例
			* @endcode
			*
			* @include -
			* @details
			* 获取类型的字符串名称
			* @enddetails
			****/
			template<typename Type>
			static CPtr<char> getTypeString(Type t) {
				return typeid(t).name();
			}



		protected:
		private:
			iType mType;
		};


	}//SPACE(core)
}//SPACE(i)



#endif //!___MIRACLEFOREST_I_TYPE___