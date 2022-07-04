/****
*
* Copyright(C) 2022 MiracleForest Studio. All Rights Reserved.
*
* @文件名：filepos.hpp
* @创建时间：2022.5.20.12:59
* @创建者：Lovelylavender4
* -----------------------------------------------------------------------------
* 祝大家520快乐！
* 文件坐标
* -----------------------------------------------------------------------------
* 如果你发现了bug，你可以去Github或邮箱(MiracleForest@Outlook.com)反馈给我们！
* 我们一定会努力做得更好的！
*
****/
#ifndef ___MIRACLEFOREST_I_FILEPOS___
#define ___MIRACLEFOREST_I_FILEPOS___

#include "../family/imacrofamily.h"
#include "istring.hpp"
#include "basic/basic/position.hpp"

SPACE(i) {
    SPACE(core) {
        SPACE(type) {

            struct fPos {

                static fPos makeDefault() {
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


            class FilePos :
                public position<int>
            {
            public:
                FilePos() :_pos(fPos::makeDefault()) {}
                FilePos(istring fileName, int x, int y) :_pos({ fileName ,x,y }) {}
                FilePos(fPos pos) :_pos(pos) {}
                ~FilePos() {}
            public:

                istring getFileName()const {
                    return _pos._fileName;
                }

                void setFileName(istring fileName) {
                    _pos._fileName = fileName;
                }

                int getX() const{
                    return _pos.x;
                }

                void setX(int x) {
                    _pos.x = x;
                }

                void setY(int y){
                    _pos.y = y;
                }

                int getY()const {
                    return _pos.y;
                }

                fPos data()const {
                    return _pos; 
                }

            public:
            protected:
            private:
                fPos _pos;
            };

        }//SPACE(type)
    }//SPACE(core)
}//SPACE(i)


#endif //!___MIRACLEFOREST_I_FILEPOS___