/*
*
* Copyright(C) 2022 MiracleForest Studio. All Rights Reserved.
*
* @filename:time.hpp
* @creation time:2022.6.28.21:26
* @created by:Lovelylavender4
* -----------------------------------------------------------------------------
*
*
* -----------------------------------------------------------------------------
* If you have contact or find bugs,
* you can go to Github or email (MiracleForest@Outlook.com) to give feedback.
* We will try to do our best!
*/
#ifndef ___MIRACLEFOREST_I_TIME___
#define ___MIRACLEFOREST_I_TIME___

#pragma warning(disable:4996)
#pragma warning(disable:4819)

#include "../family/imacrofamily.h"
#include "istring.hpp"

#if __WINDOWS__
#include <windows.h>
#endif
#include <chrono>
#include <ctime>

SPACE(i) {
    SPACE(core) {
        SPACE(type) {

            struct time_s {
                ushort years;//年
                ushort months;//月
                ushort days;//日
                ushort weeks;//星期
                ushort hours;//时
                ushort minutes;//分
                ushort seconds;//秒
                ushort milliseconds;//毫秒
                ushort microseconds;//微秒
                ushort nanoseconds;//纳秒
                ushort yday;//一年中的第n天
                int isdst;//是否启用夏令时

                static time_s makeDefault() {
                    time_s t;
                    t.years = 0;
                    t.months = 0;
                    t.days = 0;
                    t.weeks = 0;
                    t.hours = 0;
                    t.minutes = 0;
                    t.seconds = 0;
                    t.milliseconds = 0;
                    t.microseconds = 0;
                    t.nanoseconds = 0;
                    t.yday = 0;
                    t.isdst = 0;
                    return t;
                }
            };

            class time {
            public:                
                time(time_s _time = time_s::makeDefault()) :__stime(_time) {}

                ~time() {}

            public:

                void getTimeNow() {
                    std::chrono::system_clock::time_point now = std::chrono::system_clock::now();

                    std::time_t now_time_t = std::chrono::system_clock::to_time_t(now);
                    std::tm* now_tm = std::localtime(&now_time_t);
                    __stime.years = now_tm->tm_year + 1900;
                    __stime.months = now_tm->tm_mon + 1;
                    __stime.days = now_tm->tm_mday;
                    __stime.weeks = now_tm->tm_wday + 1;
                    __stime.hours = now_tm->tm_hour;
                    __stime.minutes = now_tm->tm_min;
                    __stime.seconds = now_tm->tm_sec;
                    
                    __stime.yday = now_tm->tm_yday;
                    __stime.isdst = now_tm->tm_isdst;

                    std::chrono::milliseconds ms;
                    std::chrono::microseconds cs;
                    std::chrono::nanoseconds ns;

                    ms = std::chrono::duration_cast<std::chrono::milliseconds>(now.time_since_epoch()) % 1000;
                    cs = std::chrono::duration_cast<std::chrono::microseconds>(now.time_since_epoch()) % 1000000;
                    ns = std::chrono::duration_cast<std::chrono::nanoseconds>(now.time_since_epoch()) % 1000000000;
                    
                    __stime.milliseconds = ms.count();
                    __stime.microseconds = cs.count() % 1000;
                    __stime.nanoseconds = ns.count() % 1000;
                }


                time_s data(){
                    return __stime;
                }

            public C_OPERATOR:
            
            public C_STATIC:

            protected:
            private:
                time_s __stime;
            };



        }//SPACE(type)
    }//SPACE(core)
}//SPACE(i)

#endif //!___MIRACLEFOREST_I_TIME___