/*
*
* Copyright(C) 2022 MiracleForest Studio. All Rights Reserved.
*
* @filename:istring.hpp
* @creation time:2022.5.4.12:50
* @created by:Lovelylavender4
* -----------------------------------------------------------------------------
*
*
* -----------------------------------------------------------------------------
* If you have contact or find bugs,
* you can go to Github or email (MiracleForest@Outlook.com) to give feedback.
* We will try to do our best!
*/
#ifndef ___MIRACLEFOREST_I_ISTRING___
#define ___MIRACLEFOREST_I_ISTRING___

namespace i::core {
	namespace type {
		namespace basic {

			template<typename Type>
			class istring {
			public:
				istring() {}
				istring(Type _data) :_Dat(_data) {}
				~istring() {}
			public:

			public:

			protected:

			private:
				Type _Dat;
			};


		}//namespace basic
	}//namespace type
}//namespace i::core


#endif //!___MIRACLEFOREST_I_ISTRING___