// Header
#include "acow/include/Windows.h"
// AmazingCow Libs
#include "acow/cpp_goodies.h"

// Usings
using namespace acow;
using namespace OS;

#if (!ACOW_OS_IS_WINDOWS)

//------------------------------------------------------------------------------
// XP
bool Windows::IsXP        () noexcept { return false; }
bool Windows::IsXP_OrLater() noexcept { return false; }

//------------------------------------------------------------------------------
// Vista
bool Windows::IsVista        () noexcept { return false; }
bool Windows::IsVista_OrLater() noexcept { return false; }

//------------------------------------------------------------------------------
// Seven
bool Windows::IsSeven        () noexcept { return false; }
bool Windows::IsSeven_OrLater() noexcept { return false; }

//------------------------------------------------------------------------------
// Eight
bool Windows::IsEight        () noexcept { return false; }
bool Windows::IsEight_OrLater() noexcept { return false; }

//------------------------------------------------------------------------------
// 10
bool Windows::IsTen        () noexcept { return false; }
bool Windows::IsTen_OrLater() noexcept { return false; }

#else // Current OS is Windows.

//----------------------------------------------------------------------------//
// Includes                                                                   //
//----------------------------------------------------------------------------//
#define WIN32_LEAN_AND_MEAN
#define _WINSOCKAPI_
#include <Windows.h>

//----------------------------------------------------------------------------//
// Defines                                                                    //
//----------------------------------------------------------------------------//
#ifndef _WIN32_WINNT_WIN10
    #define _WIN32_WINNT_WIN10	0x0A00
#endif // #ifndef _WIN32_WINNT_WIN10

//----------------------------------------------------------------------------//
// Macros                                                                     //
//----------------------------------------------------------------------------//
#define VERSION_EQ(_what_) \
    windows_GetU64Version() == u64(_what_)
#define VERSION_GT(_what_) \
    windows_GetU64Version() >= u64(_what_)

//----------------------------------------------------------------------------//
// Helper Functions                                                           //
//----------------------------------------------------------------------------//
acow_internal_function RTL_OSVERSIONINFOEXW*
windows_GetOsVersion()
{
    //COWNOTE(n2omatt): Copied from codeproject without any shame :D
    //  https://www.codeproject.com/Messages/5080848/A-much-easier-and-shorter-code.aspx
    acow_local_persist bool                 s_init = false;
    acow_local_persist RTL_OSVERSIONINFOEXW s_info = {0};

    // A little optimization...
    //   We only need query it once!
    if(s_init)
        return &s_info;

    typedef LONG (WINAPI* tRtlGetVersion)(RTL_OSVERSIONINFOEXW*);

    memset(&s_info, 0, sizeof(RTL_OSVERSIONINFOEXW));
    s_info.dwOSVersionInfoSize = sizeof(RTL_OSVERSIONINFOEXW);

    HMODULE        h_NtDll         = GetModuleHandleW(L"ntdll.dll");
    tRtlGetVersion f_RtlGetVersion = (tRtlGetVersion)GetProcAddress(
        h_NtDll,
        "RtlGetVersion"
    );

    s_init = (f_RtlGetVersion(&s_info) == 0);
    return &s_info;
}

acow_internal_function u64
windows_GetU64Version()
{
    u64  version = 0;
    auto p_info  = windows_GetOsVersion();

    return p_info->dwMajorVersion << 8 | p_info->dwMinorVersion;
}

//----------------------------------------------------------------------------//
// Implementation                                                             //
//----------------------------------------------------------------------------//
//------------------------------------------------------------------------------
// XP
bool Windows::IsXP        () noexcept { return VERSION_EQ(_WIN32_WINNT_WINXP); }
bool Windows::IsXP_OrLater() noexcept { return VERSION_GT(_WIN32_WINNT_WINXP); }

//------------------------------------------------------------------------------
// Vista
bool Windows::IsVista        () noexcept { return VERSION_EQ(_WIN32_WINNT_VISTA); }
bool Windows::IsVista_OrLater() noexcept { return VERSION_GT(_WIN32_WINNT_VISTA); }

//------------------------------------------------------------------------------
// Seven
bool Windows::IsSeven        () noexcept { return VERSION_EQ(_WIN32_WINNT_WIN7); }
bool Windows::IsSeven_OrLater() noexcept { return VERSION_GT(_WIN32_WINNT_WIN7); }

//------------------------------------------------------------------------------
// Eight
bool Windows::IsEight        () noexcept { return VERSION_EQ(_WIN32_WINNT_WIN8); }
bool Windows::IsEight_OrLater() noexcept { return VERSION_GT(_WIN32_WINNT_WIN8); }

//------------------------------------------------------------------------------
// 10
bool Windows::IsTen        () noexcept { return VERSION_EQ(_WIN32_WINNT_WIN10); }
bool Windows::IsTen_OrLater() noexcept { return VERSION_GT(_WIN32_WINNT_WIN10); }

#endif // (!ACOW_OS_IS_WINDOWS)