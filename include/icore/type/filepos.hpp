/*
*
* Copyright(C) 2022 MiracleForest Studio. All Rights Reserved.
*
* @filename:filepos.hpp
* @creation time:2022.5.20.12:59
* @created by:Lovelylavender4
* -----------------------------------------------------------------------------
* Happy 520 to everyone!
*
* -----------------------------------------------------------------------------
* If you have contact or find bugs,
* you can go to Github or email (MiracleForest@Outlook.com) to give feedback.
* We will try to do our best!
*/
#ifndef ___MIRACLEFOREST_I_FILEPOS___
#define ___MIRACLEFOREST_I_FILEPOS___

#include "../family/imacrofamily.h"
#include "istring.hpp"
#include "basic/basic/position.hpp"

namespace i {
    namespace core {
        namespace type {

            struct fPos{


                static fPos makeDefault(){
                    fPos p;
                    p.x = 0;
                    p.y = 0;
                    p._fileName = "";
                    return p;
                }

                istring _fileName;
                int x;
                int y;
            };

            class FilePos :public position {
            public:
                FilePos() {}
                FilePos(istring,int,int) {}
                FilePos(fPos pos):_pos(pos) {}
                ~FilePos(){}
            public:
                

                fPos data()const { return _pos; }

            public:
            protected:
            private:
                fPos _pos;
            };

        }//namespace type
    }//namespace core
}//namespace i


#endif //!___MIRACLEFOREST_I_FILEPOS___