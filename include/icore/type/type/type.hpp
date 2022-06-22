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


namespace i {
	namespace core {

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
			* @brief ��ȡ����ö��
			*
			* @retval ��ȡ��������ö��
			*
			* @par Example
			* @code
			* ����ʾ��
			* @endcode
			*
			* @include -
			* @details
			* ��ȡ����ö��
			* @enddetails
			****/
			itype getType()const {
				return typeList::itype;
			}

			iType data()const { return mType; }

			/****
			* @author Lovelylavender4
			* @since 2022.6.21.13:28
			* @brief ����mType��ֵ
			*
			* @param t mType����ֵ
			*
			* @par Example
			* @code
			* ����ʾ��
			* @endcode
			*
			* @include -
			* @details
			* ����mType��ֵ
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
			* @brief ��ȡ����ö�ٵ��ַ�������
			*
			* @param t ����ö��
			* @retval ����ö�ٵ��ַ�������
			*
			* @par Example
			* @code
			* ����ʾ��
			* @endcode
			*
			* @details
			* ��ȡ����ö�ٵ��ַ�������
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
			* @brief ��ȡ���͵��ַ�������
			*
			* @tparam Type ����
			* @retval ���͵��ַ�������
			*
			* @par Example
			* @code
			* ����ʾ��
			* @endcode
			*
			* @include ��Ҫ������ͷ�ļ�
			* @details
			* ��ȡ���͵��ַ�������
			* @enddetails
			****/
			template<typename Type>
			static const char* getTypeString() {
				return typeid(Type).name();
			}

			/****
			* @author Lovelylavender4
			* @since 2022.6.21.13:35
			* @brief ��ȡ���͵��ַ�������
			*
			* @param t -
			* @retval ���͵��ַ�������
			*
			* @par Example
			* @code
			* ����ʾ��
			* @endcode
			*
			* @include -
			* @details
			* ��ȡ���͵��ַ�������
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


	}//namespace icore
}//namespace i



#endif //!___MIRACLEFOREST_I_TYPE___