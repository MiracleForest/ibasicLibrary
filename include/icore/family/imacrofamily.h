/* 
 ​* 
 ​* Copyright(C) 2022 ClockParadox Studio. All Rights Reserved. 
 ​* 
 ​* @filename:imacrofamily.h 
 ​* @creation time:2022.?.?.??:?? 
 ​* @created by:Lovelylavender4 
 * @project:iBasicLibrary-Family
 ​* ----------------------------------------------------------------------------- 
 ​* This file only defines some macros and alias. 
 ​* ----------------------------------------------------------------------------- 
 ​* If you have contact or find bugs, 
 ​* you can go to Github or email (MiracleForest@Outlook.com) to give feedback. 
 ​* We will try to do our best! 
 ​*/

#ifndef __MIRACLEFOREST_I_IMACROFAMILY_H__
#define __MIRACLEFOREST_I_IMACROFAMILY_H__

#ifdef __ANDROID__
#elif __linux__
#elif _WIN32
    #define __WINDOWS__
#endif

#ifdef _MSC_VER
    #define __MSVC__
#elif __GNUC__
#elif __BORLANDC__
#endif

namespace i::core {

    using ushort = unsigned short;
    using ulong = unsigned long;
	using ibool = int;

}

#endif //!__MIRACLEFOREST_I_IMACROFAMILY_H__