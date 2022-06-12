/*
*
* Copyright(C) 2022 MiracleForest Studio. All Rights Reserved.
*
* @filename:libIO.h
* @creation time:2022.6.5.13:14
* @created by:Lovelylavender4
* -----------------------------------------------------------------------------
* 
* 
* -----------------------------------------------------------------------------
* If you have contact or find bugs,
* you can go to Github or email (MiracleForest@Outlook.com) to give feedback.
* We will try to do our best!
*/
#ifndef ___MIRACLEFOREST_I__LIBIO_LIBIO___
#define ___MIRACLEFOREST_I__LIBIO_LIBIO___

#include "../../../cppstd/format"
#include "../../type/istring.hpp"
#include "../../family/imacrofamily.h"


namespace i {
    namespace core {
        namespace libIO {

            class IAPI libIO {
            public:
                libIO();
                ~libIO();

            public:

            public:

            public STATIC:

                template<class...Args>
                static void printf(Args...args) {

                }

            protected:
            private:

            };//class IAPI libIO

        }//namespace libIO
    }//namespace core
}//namespace i

#endif //!___MIRACLEFOREST_I__LIBIO_LIBIO___