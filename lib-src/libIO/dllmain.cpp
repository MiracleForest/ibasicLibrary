﻿#include "pch.h"


#include "../../include/icore/lib/libIO/IO.h"
#include "../../include/icore/lib/libIO/file.h"
#include "../../include/icore/lib/libIO/console.h"
#include "../../include/icore/lib/libIO/shelllinkfile.h"


BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}

