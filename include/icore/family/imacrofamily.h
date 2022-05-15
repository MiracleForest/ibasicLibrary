/*
*
* Copyright(C) 2022 MiracleForest Studio. All Rights Reserved.
*
* @filename:imacrofamily.h
* @creation time:2022.5.2.17:09
* @created by:Lovelylavender4
* -----------------------------------------------------------------------------
*
* -----------------------------------------------------------------------------
* If you have contact or find bugs,
* you can go to Github or email (MiracleForest@Outlook.com) to give feedback.
* We will try to do our best!
*/
#ifndef ___MIRACLEFOREST_I_IMACROFAMILY___
#define ___MIRACLEFOREST_I_IMACROFAMILY___


// C++ language standard detection
// if the user manually specified the used c++ version this is skipped
#if !defined(__CPP_23__) &&\
    !defined(__CPP_20__) &&\
    !defined(__CPP_17__) &&\
    !defined(__CPP_14__) &&\
    !defined(__CPP_11__)
#ifdef _HAS_CXX23
#define __CPP_23__
#define __CPP_20__
#define __CPP_17__
#define __CPP_14__
#elif _HAS_CXX20
#define __CPP_20__
#define __CPP_17__
#define __CPP_14__
#elif _HAS_CXX17
#define __CPP_17__
#define __CPP_14__
#else
#define __CPP_14__
#endif
#define __CPP_11__
#endif

#ifdef _WIN32
#define __WIN32__
#elif defined __linux__
#define __LINUX__
#elif defined __APPLE__
#define __APPLE__
#elif defined __unix__
#define __UNIX__
#else
#define __UNK__
#endif

#if defined(__ICC) || defined(__INTEL_COMPILER)
#define __ICC__ __INTEL_COMPILER
#elif defined(__clang__)
#define __CLANG__ __clang_version__
#elif defined(__GNUC__) || defined(__GNUG__)
#define __GCC__ 
#define __GCCV__ std::to_string(__GNUC__) + "." + std::to_string(__GNUC_MINOR__) + "." + std::to_string(__GNUC_PATCHLEVEL__)
#elif defined(__HP_cc) || defined(__HP_aCC)
#define __HP__
#elif defined(__IBMCPP__)
#define __ILECPP__ __IBMCPP__
#elif defined(_MSC_VER)
#define __MSVC__ _MSC_VER
#elif defined(__PGI)
#define __PGCPP__ __PGI
#elif defined(__SUNPRO_CC)
#define __SUNPRO__ __SUNPRO_CC
#else
#define __UNKNOWN__
#endif


namespace i::core {

    using ushort = unsigned short;
    using uint = unsigned int;
    using ulong = unsigned long;
    using u = unsigned;

}

#endif //!___MIRACLEFOREST_I_IMACROFAMILY___