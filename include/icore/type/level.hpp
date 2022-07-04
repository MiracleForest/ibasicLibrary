/****
*
* Copyright(C) 2022 MiracleForest Studio. All Rights Reserved.
*
* @文件名：level.hpp
* @创建时间：2022.5.20.13:00
* @创建者：Lovelylavender4
* -----------------------------------------------------------------------------
* 祝大家520快乐！ 
* 等级
* -----------------------------------------------------------------------------
* 如果你发现了bug，你可以去Github或邮箱(MiracleForest@Outlook.com)反馈给我们！
* 我们一定会努力做得更好的！
*
****/
#ifndef ___MIRACLEFOREST_I_LEVEL___
#define ___MIRACLEFOREST_I_LEVEL___

#include "../family/imacrofamily.h"

#undef FALSE
#undef TRUE

SPACE(i) {
    SPACE(core) {
        SPACE(type) {

            class level {
            public:
                enum class Level {
                    φ,
                    V,
                    S,
                    A,
                    B,
                    C,
                    D,
                    E,
                    F,
                    G,
                    H,
                    I,
                    J,
                    K,
                    L,
                    M,
                    N,
                    O,
                    P,
                    Q,
                    R,
                    FALSE
                };
            public:

                level(int lv = 0) :_lv(lv) {}
                ~level() {}

            public:

                int data()const {
                    return _lv;
                }

                int getlv()const {
                    return _lv;
                }

                int getLevel()const {
                    return _lv;
                }

                void setLevel(int _level) {
                    _lv = _level;
                }

            public C_OPERATOR:

                Ref<level> operator=(int lv) {
                    _lv = lv;
                    return *this;
                }

                Ref<level> operator=(CRef<level> lv) {
                    _lv = lv.data();
                    return *this;
                }


                Ref<level> operator*=(int lv) {
                    _lv *= lv;
                    return *this;
                }

                Ref<level> operator/=(int lv) {
                    _lv /= lv;
                    return *this;
                }

                Ref<level> operator+=(int lv) {
                    _lv += lv;
                    return *this;
                }

                Ref<level> operator-=(int lv) {
                    _lv -= lv;
                    return *this;
                }

                bool operator==(int lv) {
                    return _lv == lv;
                }

                bool operator>(int lv) {
                    return _lv > lv;
                }

                bool operator<(int lv) {
                    return _lv < lv;
                }

                bool operator>=(int lv) {
                    return _lv >= lv;
                }

                bool operator<=(int lv) {
                    return _lv <= lv;
                }

                bool operator!=(int lv) {
                    return _lv != lv;
                }

            protected:
            private:
                int _lv;
            };//class level

        }//SPACE(type)
    }//SPACE(core)
}//SPACE(i)

#endif //!___MIRACLEFOREST_I_LEVEL___