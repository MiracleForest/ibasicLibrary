#include <iostream>
#include <thread>
#include <functional>

#include "../include/icore/family/ifamily.hpp"
#include "../include/icore/type/type/type.hpp"
#include "../include/icore/type/istring.hpp"
#include "../include/icore/lib/libmath/math.h"
#include "../include/icore/lib/libmath/vec4.hpp"

#if __WINDOWS__
#include <Windows.h>
#endif


#if __WINDOWS__
long long useTime(std::function<void()> func) {
    _LARGE_INTEGER timeSt;
    _LARGE_INTEGER timeOv;
    double dpFr;
    LARGE_INTEGER f;
    QueryPerformanceFrequency(&f);
    dpFr = (double)f.QuadPart;
    QueryPerformanceCounter(&timeSt);

    func();

    QueryPerformanceCounter(&timeOv);
    return (timeOv.QuadPart - timeSt.QuadPart);
}

#endif

i::core::iexception::error start() {

    long long t = useTime([]() {
        {
            i::core::type::istring str = "菲,露,露~";
            std::cout << str.split2List(",").front() << std::endl;
        } {
            i::core::type::istring str = "菲,露,露~";
            std::cout << str.split2Vector(",")[0];
            std::cout << str.split2Vector(",")[1];
            std::cout << str.split2Vector(",")[2] << std::endl;
        } {
            i::core::type::istring str = "菲,露,露~";
            std::cout << *(str.split2Set(",").begin()) << std::endl;
        }

        i::core::libmath::Vec3<float> test(1.2, 2.3, 3.5);
        std::cout << test.x << std::endl;
        std::cout << test.y << std::endl;
        std::cout << test.z << std::endl;

        i::core::libmath::Vec4<float> test2(1.2, 2.3, 3.5, 1);
        std::cout << test2.x << std::endl;
        std::cout << test2.y << std::endl;
        std::cout << test2.z << std::endl;
        std::cout << test2.w << std::endl;

        {
            i::core::type::istring str = "菲,露,露~";
            std::cout << i::core::type::istring::istringSplit2List(str, ",").front() << std::endl;
        } {
            i::core::type::istring str = "菲,露,露~";
            std::cout << i::core::type::istring::istringSplit2Vector(str, ",")[0];
            std::cout << i::core::type::istring::istringSplit2Vector(str, ",")[1];
            std::cout << i::core::type::istring::istringSplit2Vector(str, ",")[2] << std::endl;
        } {
            i::core::type::istring str = "菲,露,露~";
            std::cout << *(i::core::type::istring::istringSplit2Set(str, ",").begin()) << std::endl;
        }
        });

    std::cout << "-->" << t << "<--" << std::endl;


    system("pause");
    return i::core::iexception::error::noError();
}

