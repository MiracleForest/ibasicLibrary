#include <iostream>
#include <thread>
#include "../include/icore/type/type/type.hpp"
#include "../include/icore/type/basic/istring.hpp"
#include "../include/icore/lib/libmath/math.h"
#include "../include/icore/lib/libmath/vec4.hpp"
#if __WINDOWS__
#include <Windows.h>
#endif
#include <functional>

#if __WINDOWS__

long long useTime(std::function<void()> func) {
    double useTime;
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

int main() {

    long long t =useTime([]() {
            {
                i::core::type::basic::istring<std::string> str = "菲,露,露~";
                std::cout << str.split2List(",").front() << std::endl;
            } {
                i::core::type::basic::istring<std::string> str = "菲,露,露~";
                std::cout << str.split2Vector(",")[0];
                std::cout << str.split2Vector(",")[1];
                std::cout << str.split2Vector(",")[2] << std::endl;
            } {
                i::core::type::basic::istring<std::string> str = "菲,露,露~";
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
                i::core::type::basic::istring<std::string> str = "菲,露,露~";
                std::cout << i::core::type::basic::istring<std::string>::istringSplit2List(str, ",").front() << std::endl;
            } {
                i::core::type::basic::istring<std::string> str = "菲,露,露~";
                std::cout << i::core::type::basic::istring<std::string>::istringSplit2Vector(str, ",")[0];
                std::cout << i::core::type::basic::istring<std::string>::istringSplit2Vector(str, ",")[1];
                std::cout << i::core::type::basic::istring<std::string>::istringSplit2Vector(str, ",")[2] << std::endl;
            } {
                i::core::type::basic::istring<std::string> str = "菲,露,露~";
                std::cout << *(i::core::type::basic::istring<std::string>::istringSplit2Set(str, ",").begin()) << std::endl;
            }
            });

    std::cout << "-->" << t << "<--" << std::endl;

    system("pause");
    return 0;
}

