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

#ifndef _HAS_CXX14
#if _STL_LANG > 201108L
#define _HAS_CXX14 1
#else
#define _HAS_CXX14 0
#endif
#endif // _HAS_CXX14

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


/*------------------------编译器判断------------------------*/
#if defined(__ICC) || defined(__INTEL_COMPILER)
#define __ICC__ __INTEL_COMPILER
#elif defined(__clang__)
#define __CLANG__ __clang_version__
#elif defined(__GNUC__) || defined(__GNUG__)
#define __GCC__ 1
#define __GCCV__ std::to_string(__GNUC__) + "." + std::to_string(__GNUC_MINOR__) + "." + std::to_string(__GNUC_PATCHLEVEL__)
#elif defined(__HP_cc) || defined(__HP_aCC)
#define __HP__ 1  
#elif defined(__IBMCPP__)
#define __ILECPP__ __IBMCPP__
#elif defined(_MSC_VER)
#define __MSVC__ _MSC_VER
#elif defined(__PGI)
#define __PGCPP__ __PGI
#elif defined(__SUNPRO_CC)
#define __SUNPRO__ __SUNPRO_CC
#else
#define __UNKNOWN__ 1
#endif


/*------------------------C++标准判断------------------------*/
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
#define __CPP_11__ 1
#elif _HAS_CXX20
#define __CPP_20__ 1
#define __CPP_17__ 1
#define __CPP_14__ 1
#define __CPP_11__ 1
#elif _HAS_CXX17
#define __CPP_17__ 1
#define __CPP_14__ 1
#define __CPP_11__ 1
#elif _HAS_CXX14
#define __CPP_14__ 1
#define __CPP_11__ 1
#else
#define __CPP_11__ 1
#endif
#endif


/*------------------------平台的判断------------------------*/

#ifdef _WIN32
#define __WIN32__ 1
#define __WINDOWS__ 1
#elif defined __linux__
#define __LINUX__ 1
#elif defined __APPLE__
#define __APPLE__ 1
#elif defined __unix__
#define __UNIX__ 1
#else
#define __UNK__ 1
#endif

/*------------------------小数------------------------*/

#define IS_FLOAT_DIFFERENT(a,b) (fabsf((a) - (b)) > FLT_EPSILON)
#define IS_FLOAT_EQUAL(a,b) (fabsf((a) - (b)) < FLT_EPSILON)
#define IS_DOUBLE_DIFFERENT(a,b) (fabs((a) - (b)) > DBL_EPSILON)
#define IS_DOUBLE_EQUAL(a,b) (fabs((a) - (b)) < DBL_EPSILON)


/*------------------------关于 dll------------------------*/
#ifdef ___STATICLIB___
#define IAPI
#elif defined(__MSVC__)

#ifdef ___ILIBRARYEXPORT___
#define IAPI _declspec(dllexport)
#else
#define IAPI _declspec(dllimport)
#endif

#define IAPI_EXPORT _declspec(dllexport)
#define IAPI_IMPORT _declspec(dllimport)

#elif defined(__GCC__)
#define IAPI __attribute__​((visibility(​"​default​"​)))
#else
#define IAPI
#endif


/*------------------------类------------------------*/
#define C_STATIC
#define C_OPERATOR


/*------------------------快捷------------------------*/
#define CATCH(x) catch(...){printf(x);}
#define IERROR i::core::iexception::error
#define SPACE(x) namespace x
#define SPACE_ namespace


/*------------------------命名空间------------------------*/
#define N_STD ::std::
#define N_ITYPE ::i::core::type::
#define N_IBASIC ::i::core::type::basic::
#define N_ISTD ::i::core::


SPACE(i) {
    SPACE(core) {

        using ushort = unsigned short;
        using uint = unsigned int;
        using ulong = unsigned long;
        using u = unsigned;

        using __unk_type__ = void*;

#ifdef __WINDOWS__
        typedef __int64   int64;
        typedef unsigned __int64   uint64;
#else//!__WINDOWS__
        typedef long long int64;
        typedef unsigned long long uint64;
#endif //__WINDOWS__


        using VA = uint64;
        using RVA = unsigned int;

        template<typename Type>
        using Ptr = Type*;
        
        template<typename Type>
        using CPtr = const Type*;

        template<typename Type>
        using CRef = const Type&;

        template<typename Type>
        using Ref = Type&;

    }//SPACE(core)
}//SPACE(i)

#endif //___MIRACLEFOREST_I_IMACROFAMILY___