/*
*
* Copyright(C) 2022 MiracleForest Studio. All Rights Reserved.
*
* @filename:imacrofamily.h
* @creation time:2022.5.2.17:09
* @created by:Lovelylavender4
* -----------------------------------------------------------------------------
* some macro and Type Alias
* -----------------------------------------------------------------------------
* If you have contact or find bugs,
* you can go to Github or email (MiracleForest@Outlook.com) to give feedback.
* We will try to do our best!
*/
#ifndef ___MIRACLEFOREST_I_IMACROFAMILY___
#define ___MIRACLEFOREST_I_IMACROFAMILY___

#ifdef _MSVC_LANG
#define _STL_LANG _MSVC_LANG
#elif defined(__cplusplus) // ^^^ use _MSVC_LANG / use __cplusplus vvv
#define _STL_LANG __cplusplus
#else  // ^^^ use __cplusplus / no C++ support vvv
#define _STL_LANG 0L
#endif // ^^^ no C++ support ^^^

#ifndef _HAS_CXX17
#if _STL_LANG > 201402L
#define _HAS_CXX17 1
#else
#define _HAS_CXX17 0
#endif
#endif // _HAS_CXX17

#ifndef _HAS_CXX20
#if _HAS_CXX17 && _STL_LANG > 201703L
#define _HAS_CXX20 1
#else
#define _HAS_CXX20 0
#endif
#endif // _HAS_CXX20

#ifndef _HAS_CXX23
#if _HAS_CXX20 && _STL_LANG > 202002L
#define _HAS_CXX23 1
#else
#define _HAS_CXX23 0
#endif
#endif // _HAS_CXX23

#undef _STL_LANG

#if _HAS_CXX20 && !_HAS_CXX17
#error _HAS_CXX20 must imply _HAS_CXX17.
#endif

#if _HAS_CXX23 && !_HAS_CXX20
#error _HAS_CXX23 must imply _HAS_CXX20.
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


#if !defined(__CPP_23__) &&\
    !defined(__CPP_20__) &&\
    !defined(__CPP_17__) &&\
    !defined(__CPP_14__) &&\
    !defined(__CPP_11__)
#if _HAS_CXX23 
#define __CPP_23__ 1
#define __CPP_20__ 1
#define __CPP_17__ 1
#define __CPP_14__ 1
#elif _HAS_CXX20
#define __CPP_20__ 1
#define __CPP_17__ 1
#define __CPP_14__ 1
#elif _HAS_CXX17
#define __CPP_17__ 1
#define __CPP_14__ 1
#else
#define __CPP_14__ 1
#endif
#define __CPP_11__ 1
#endif

#ifdef _WIN32
#define __WIN32__ 1
#elif defined __linux__
#define __LINUX__ 1
#elif defined __APPLE__
#define __APPLE__ 1
#elif defined __unix__
#define __UNIX__ 1
#else
#define __UNK__ 1
#endif


namespace i::core {

    using ushort = unsigned short;
    using uint = unsigned int;
    using ulong = unsigned long;
    using ullong = unsigned long long;
    using u = unsigned;

}

#endif //!___MIRACLEFOREST_I_IMACROFAMILY___