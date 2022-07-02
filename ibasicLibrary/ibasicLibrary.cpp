#pragma warning(disable:4996)
#pragma warning(disable:4819)
#include <iostream>
#include <thread>
#include <functional>

#include "../include/icore/family/ifamily.hpp"
#include "../include/icore/type/type/type.hpp"
#include "../include/icore/type/istring.hpp"
#include "../include/icore/type/time.hpp"


#include "../include/icore/lib/libmath/vec4.hpp"

#include "../include/icore/lib/libIO/file.h"
#include "../include/icore/lib/libIO/shelllinkfile.h"
#pragma comment(lib,R"(E:\program\MiracleForest\ibasicLibrary\build\x64\Debug\libIO.lib)")



#if __WINDOWS__
#include <Windows.h>
#endif



IERROR i::core::Main::start(N_ISTD _p_start& p_start) {
    type::time t;
    t.getTimeNow();
    auto r = t.data();
    std::cout << std::format("{0}.{1}.{2} {4}:{5}:{6}:{7}:{8}:{9} {10}--{3}--{11}", 
        /*0*/r.years,
        /*1*/r.months,
        /*2*/r.days,
        /*3*/r.weeks,
        /*4*/r.hours,
        /*5*/r.minutes,
        /*6*/r.seconds,
        /*7*/r.milliseconds,
        /*8*/r.microseconds,
        /*9*/r.nanoseconds,
        /*10*/r.yday,
        /*11*/r.isdst) << std::endl;

    {
        type::istring str = "f,l,l~";
        std::cout << str.split2List(",").front() << std::endl;
    } {
        type::istring str = "菲,露,露~";
        std::cout << str.split2Vector(",")[0];
        std::cout << str.split2Vector(",")[1];
        std::cout << str.split2Vector(",")[2] << std::endl;
    } {
        type::istring str = "菲,露,露~";
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


    auto gfnl = libIO::File::getFileNameList(R"(E:\program\MiracleForest\ibasicLibrary\build\x64\Debug\)");
    for (int i = 0; i < gfnl.size(); i++) {
        std::cout << gfnl[i] << std::endl;
    }

    system("pause");
    return i::core::iexception::error::noError();
}

