/*
*
* Copyright(C) 2022 MiracleForest Studio. All Rights Reserved.
*
* @filename:type.hpp
* @creation time:2022.4.30.12:06
* @created by:Lovelylavender4
* -----------------------------------------------------------------------------
* type
* -----------------------------------------------------------------------------
* If you have contact or find bugs,
* you can go to Github or email (MiracleForest@Outlook.com) to give feedback.
* We will try to do our best!
*/
#ifndef ___MIRACLEFOREST_I_TYPE___
#define ___MIRACLEFOREST_I_TYPE___

#include "../../family/imacrofamily.h"
#if __WIN32__
#include <windows.h>
#include <stringapiset.h>
#include <atlstr.h>
#endif
#include "../../../cppstd/string"


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

			itype(const itype&) = delete;

			void operator=(const itype&) = delete;

			~itype() {}
		public:

			/// <summary>
			/// get type
			/// </summary>
			/// <warning></warning>
			/// <include></include>
			/// <bug></bug>
			/// <returns>type enum</returns>
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

			/// <summary>
			/// 
			/// </summary>
			/// <param name="t">type enum</param>
			/// <warning></warning>
			/// <include></include>
			/// <bug></bug>
			/// <returns>Type Name</returns>
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
			static const char* getString(iType t) {
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
			static const char* getTypeString() {
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
			static const char* getTypeString(Type t) {
				return typeid(t).name();
			}



		protected:
		private:
			iType mType;
		};


	}//SPACE(core)
}//SPACE(i)



#endif //!___MIRACLEFOREST_I_TYPE___