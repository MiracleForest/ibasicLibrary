/*
*
* Copyright(C) 2022 MiracleForest Studio. All Rights Reserved.
*
* @filename:level.hpp
* @creation time:2022.5.20.13:00
* @created by:Lovelylavender4
* -----------------------------------------------------------------------------
* Happy 520 to everyone!
*
* -----------------------------------------------------------------------------
* If you have contact or find bugs,
* you can go to Github or email (MiracleForest@Outlook.com) to give feedback.
* We will try to do our best!
*/
#ifndef ___MIRACLEFOREST_I_LEVEL___
#define ___MIRACLEFOREST_I_LEVEL___

#include "../family/imacrofamily.h"


namespace i {
    namespace core {
        namespace type {

            class level {
            public:
                level(int lv = 0) :_lv(lv) {}
                ~level() {}
            public:
            public:
            protected:
            private:
                int _lv;
            };//class level

        }//namespace type
    }//namespace core
}//namespace i

#endif //!___MIRACLEFOREST_I_LEVEL___