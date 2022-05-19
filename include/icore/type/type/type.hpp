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
#endif
#include <string>
#include <stringapiset.h>
#include <atlstr.h>

/// <summary>
/// 
/// </summary>
namespace i {
	namespace core {
		/// <summary>
		/// 
		/// </summary>
		enum class typeList {
			unkType,
			itype,
			number,
			numberArray_const_iterator,
			numberArray_iterator,
			numberArray,
			istring
		};
		using iType = typeList;

		/// <summary>
		/// 
		/// </summary>
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
			itype getType()const {
				return typeList::itype;
			}

			/// <summary>
			/// get data
			/// </summary>
			/// <warning></warning>
			/// <include></include>
			/// <bug></bug>
			/// <returns>data</returns>
			iType data()const { return mType; }

			/// <summary>
			/// set data
			/// </summary>
			/// <warning></warning>
			/// <include></include>
			/// <bug></bug>
			/// <param name="t">new data</param>
			void setdata(iType t) { mType = t; }

			/// <summary>
			/// Get the name of the type enum
			/// </summary>
			/// <param name="t">type enum</param>
			/// <warning></warning>
			/// <include></include>
			/// <bug></bug>
			/// <returns>Type Name</returns>
			static const char* getString(iType t) {
				switch (t) {
				case iType::unkType: {
					return "unkType";
				}
				case iType::itype: {
					return "itype";
				}
				case iType::number: {
					return "number";
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
				case iType::istring:{
					return "istring";
				}
				default: {
					return "unk-Type";
				}
				}
			}

			/// <summary>
			/// Get the name of the type
			/// </summary>
			/// <typeparam name="Type">type</typeparam>
			/// <warning></warning>
			/// <include></include>
			/// <bug></bug>
			/// <returns>Type Name</returns>
			template<typename Type>
			static const char* getTypeString() {
				return typeid(Type).name();
			}

			/// <summary>
			/// Get the name of the type
			/// </summary>
			/// <typeparam name="Type">-</typeparam>
			/// <param name="t">type</param>
			/// <warning></warning>
			/// <include></include>
			/// <bug></bug>
			/// <returns>Type Name</returns>
			template<typename Type>
			static const char* getTypeString(Type t) {
				return typeid(t).name();
			}



		protected:
		private:
			iType mType;
		};

		/// <summary>
		/// toStdString
		/// </summary>
		/// <param name="value">value</param>
		/// <warning></warning>
		/// <include></include>
		/// <bug></bug>
		/// <returns>Converted string</returns>
		template <typename T>
		inline std::string toStdString(T value) {
			return itype::toStdString(value);
		}
	}//namespace icore
}//namespace i



#endif //!___MIRACLEFOREST_I_TYPE___