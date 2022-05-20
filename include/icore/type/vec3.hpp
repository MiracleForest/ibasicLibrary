/*
*
* Copyright(C) 2022 MiracleForest Studio. All Rights Reserved.
*
* @filename:vec3.hpp
* @creation time:2022.5.20.13:14
* @created by:***
* -----------------------------------------------------------------------------
* Happy 520 to everyone!
*
* -----------------------------------------------------------------------------
* If you have contact or find bugs,
* you can go to Github or email (MiracleForest@Outlook.com) to give feedback.
* We will try to do our best!
*/
#ifndef ___MIRACLEFOREST_I_VEC3___
#define ___MIRACLEFOREST_I_VEC3___

#include "../family/imacrofamily.h"

namespace i {
    namespace core {
        namespace type {

            class Vec3 {
            public:
                Vec3(float x = 0, float y = 0, float z = 0) :_x(x), _y(y), _z(z) {}
                Vec3(const Vec3& vec3) :_x(vec3.getX()), _y(vec3.getY()), _z(vec3.getZ()) {}
                ~Vec3(){}
            public:
            public:

                /// <summary>
                /// 
                /// </summary>
                /// <returns></returns>
                float getX() const { return _x; }

                /// <summary>
                /// 
                /// </summary>
                /// <returns></returns>
                float getY() const { return _y; }

                /// <summary>
                /// 
                /// </summary>
                /// <returns></returns>
                float getZ() const { return _z; }

            protected:
            private:
                float _x;
                float _y;
                float _z;
            };//class Vec3

        }//namespace type
    }//namespace core
}//namespace i



#endif //!___MIRACLEFOREST_I_VEC3___