#pragma warning(disable:4996)
#pragma warning(disable:4819)
#pragma warning(disable:4464)
#include <iostream>
#include <thread>
#include <functional>

#include <format>

#include "../include/icore/family/ifamily.hpp"
#include "../include/icore/type/type/type.hpp"
#include "../include/icore/type/istring.hpp"
#include "../include/icore/type/time.hpp"
#include "../include/icore/type/color.hpp"

#include "../include/icore/lib/libmath/vec4.hpp"

#include "../include/icore/lib/libIO/file.h"
#pragma comment(lib,R"(E:\program\MiracleForest\ibasicLibrary\build\x64\Debug\libIO.lib)")


#if __WINDOWS__
#include <Windows.h>
#endif


IERROR fun() {
    return IERROR::make(i::core::iexception::ErrorCode::unkError, { "ibasicLibrary.cpp",1,__LINE__ });
}


IERROR i::core::Main::start(::i::core::Ref< N_ISTD _p_start> p_start) {
    try {
        auto rtet = fun();
        if (!rtet.isNoError()) {
            if (rtet.isCanBeIgnored()) {
                std::cout << "错误可忽略" << std::endl;
            }
            else {
                std::cout << "错误不可忽略" << std::endl;
            }
            auto ei = rtet.getErrorInfo();
            std::cout << "_icode->" <<ei._icode << std::endl;
            std::cout << "_dscription->" << ei._dscription << std::endl;
            std::cout << "_dscription2->" << ei._dscription2 << std::endl;
            std::cout << "_suggestion->" << ei._suggestion << std::endl;
            std::cout 
                << "_position->fileName->" << ei._position.getFileName() << std::endl
                << "_position->x->" << ei._position.getX() << std::endl 
                << "_position->y->" << ei._position.getY() << std::endl;
            std::cout << "_level->" << ei._level.getLevel() << std::endl;
            std::cout << "_canBeIgnored->" << ei._canBeIgnored << std::endl;
        }
        else {
            std::cout << "无错误" << std::endl;
        }
    }
    catch (::i::core::CRef<::i::core::iexception::createErrorFailed> e) {
        std::cout << "异常！" << e.what() << std::endl;
    }
    catch (...) {
        std::cout << "未知的异常！"  << std::endl;
    }
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

    std::cout << type::color::toHex({ 123,123,123 }) << std::endl;
    std::cout << type::color::toHex(type::RGBA::makeRGBA(123,123,123,222)) << std::endl;
    type::color c(type::color::toHex({ 123,123,123 }));
    std::cout << c.data().r << std::endl;
    std::cout << c.data().g << std::endl;
    std::cout << c.data().b << std::endl;
    system("pause");
    return i::core::iexception::error::noError();
}

