#include <iostream>
#include <thread>
#include <functional>

#include "../include/icore/family/ifamily.hpp"
#include "../include/icore/type/type/type.hpp"
#include "../include/icore/type/istring.hpp"


#include "../include/icore/lib/libmath/vec4.hpp"

#include "../include/icore/lib/libIO/file.h"
#include "../include/icore/lib/libIO/shelllinkfile.h"
#pragma comment(lib,R"(E:\program\MiracleForest\ibasicLibrary\build\x64\Debug\libIO.lib)")



#if __WINDOWS__
#include <Windows.h>
#endif



IERROR i::core::Main::start(N_ISTD _p_start& p_start) {

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


    auto gfnl = libIO::File::getFileNameList(R"(E:\program\MiracleForest\ibasicLibrary\build\x64\Debug\)");
    for (int i = 0; i < gfnl.size(); i++) {
        std::cout << gfnl[i] << std::endl;
    }
    std::cout << (libIO::File::readAllFile(R"(E:\program\MiracleForest\ibasicLibrary\build\x64\Debug\MFCApp-test.exe)", true).value()).data() << std::endl;

    system("pause");
    return i::core::iexception::error::noError();
}

