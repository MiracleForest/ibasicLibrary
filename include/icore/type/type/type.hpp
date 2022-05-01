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

namespace i::core {

    enum class typeList {
        unkType,
        itype,
        number,
        numberArray_const_iterator,
    };
    using iType = typeList;

    class itype {
    public:
        itype():_T(iType::unkType) { }

        itype(iType t) :_T(t) { }

        itype(const itype&) = delete;

        void operator=(const itype&) = delete;

        ~itype(){}
    public:

        /// <summary>
        /// get type
        /// </summary>
        /// <returns></returns>
        itype getType()const {
            return typeList::itype;
        }

        /// <summary>
        /// get data
        /// </summary>
        /// <returns></returns>
        iType data()const { return _T; }

        /// <summary>
        /// set data
        /// </summary>
        /// <param name="t"></param>
        void setdata(iType t) { _T = t; }

        /// <summary>
        /// get type name string
        /// </summary>
        /// <param name="t"></param>
        /// <returns></returns>
        static const char* getString(iType t) {
            switch (t) {

            }
        }

        /// <summary>
        /// 
        /// </summary>
        /// <typeparam name="Type"></typeparam>
        /// <returns></returns>
        template<typename Type>
        static const char* getTypeString() {
            return typeid(Type).name();
        }

        /// <summary>
        /// 
        /// </summary>
        /// <typeparam name="Type"></typeparam>
        /// <param name="t"></param>
        /// <returns></returns>
        template<typename Type>
        static const char* getTypeString(Type t) {
            return typeid(t).name();
        }

    protected:
    private:
        iType _T;
    };

}//namespace i::icore

#endif //!___MIRACLEFOREST_I_TYPE___