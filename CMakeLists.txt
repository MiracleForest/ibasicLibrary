# cmake version should >= 3.10
cmake_minimum_required(VERSION 3.10)
# project name
project(ibasicLibrary)

# set cpp standard = cpp 20
set(CMAKE_CXX_STANDARD 14)


# library root include directory
include_directories(include)

# set the include file suffix
list(APPEND CPP_INCLUDE_SUFFIX "*.hpp" "*.h" "*.inl")
# search the include files
#include cppstd
file(GLOB_RECURSE INCLUDE_STDCPP ${PROJECT_SOURCE_DIR}/include/cppstd ${CPP_INCLUDE_SUFFIX})
# include icore/algorithm
file(GLOB_RECURSE INCLUDE_CORE_ALGORITHM ${PROJECT_SOURCE_DIR}/include/icore/algorithm ${CPP_INCLUDE_SUFFIX})
# include icore/exception
file(GLOB_RECURSE INCLUDE_CORE_EXCEPTION ${PROJECT_SOURCE_DIR}/include/icore/exception ${CPP_INCLUDE_SUFFIX})
# include icore/family
file(GLOB_RECURSE INCLUDE_CORE_FAMILY    ${PROJECT_SOURCE_DIR}/include/icore/family ${CPP_INCLUDE_SUFFIX})
# include icore/libcolor
file(GLOB_RECURSE INCLUDE_CORE_LIBCOLOR  ${PROJECT_SOURCE_DIR}/include/icore/libcolor ${CPP_INCLUDE_SUFFIX})
#include icore/libio
file(GLOB_RECURSE INCLUDE_CORE_LIBIO   ${PROJECT_SOURCE_DIR}/include/icore/lib/libIO ${CPP_INCLUDE_SUFFIX})
# include icore/libmath
file(GLOB_RECURSE INCLUDE_CORE_LIBMATH   ${PROJECT_SOURCE_DIR}/include/icore/lib/libmath ${CPP_INCLUDE_SUFFIX})
# include icore/type
file(GLOB_RECURSE INCLUDE_CORE_TYPE      ${PROJECT_SOURCE_DIR}/include/icore/type ${CPP_INCLUDE_SUFFIX})


# add executable
add_executable(ibasicLibrary
        ${INCLUDE_STDCPP}
        ${INCLUDE_CORE_ALGORITHM}
        ${INCLUDE_CORE_EXCEPTION}
        ${INCLUDE_CORE_FAMILY}
        ${INCLUDE_CORE_LIBCOLOR}
        ${INCLUDE_CORE_LIBIO}
        ${INCLUDE_CORE_LIBMATH}
        ${INCLUDE_CORE_TYPE}
        ibasicLibrary/ibasicLibrary.cpp)

