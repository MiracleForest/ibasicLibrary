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

#undef FALSE
#undef TRUE

SPACE(i) {
    SPACE(core) {
        SPACE(type) {

            class level {
            public:
                enum class Level {
                    φ,
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
                    S,
                    T,
                    U,
                    V,
                    W,
                    X,
                    Y,
                    Z,
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

                level& operator=(int lv) {
                    _lv = lv;
                    return *this;
                }

                level& operator=(const level& lv) {
                    _lv = lv.data();
                    return *this;
                }

                level& operator+(int lv) {
                    _lv + lv;
                    return *this;
                }

                level& operator-(int lv) {
                    _lv - lv;
                    return *this;
                }

                level& operator*(int lv) {
                    _lv *= lv;
                    return *this;
                }

                level& operator*=(int lv) {
                    _lv *= lv;
                    return *this;
                }

                level& operator/(int lv) {
                    _lv /= lv;
                    return *this;
                }

                level& operator/=(int lv) {
                    _lv /= lv;
                    return *this;
                }

                level& operator+=(int lv) {
                    _lv += lv;
                    return *this;
                }

                level& operator-=(int lv) {
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