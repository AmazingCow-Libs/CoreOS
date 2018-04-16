
#pragma once
// std
#include <string>
// AmazingCow Libs
#include "acow/cpp_goodies.h"
#include "acow/posix/cross/utsname.h"

namespace acow { namespace OS {
//------------------------------------------------------------------------//
//                                                                        //
//------------------------------------------------------------------------//
constexpr inline bool IsBSD     () noexcept { return bool(ACOW_OS_IS_BSD      ); }
constexpr inline bool IsGNULinux() noexcept { return bool(ACOW_OS_IS_GNU_LINUX); }
constexpr inline bool IsOSX     () noexcept { return bool(ACOW_OS_IS_OSX      ); }
constexpr inline bool IsWindows () noexcept { return bool(ACOW_OS_IS_WINDOWS  ); }

constexpr inline bool IsUnix() noexcept { return !(IsWindows()); }

const std::string& GetOSName() noexcept;

//------------------------------------------------------------------------//
//                                                                        //
//------------------------------------------------------------------------//
inline std::string
KernelName() noexcept
{
    utsname name = {0};
    uname(&name);

    return name.sysname;
}

inline std::string
KernelRelease() noexcept
{
    utsname name = {0};
    uname(&name);

    return name.release;
}

inline std::string
KernelVersion() noexcept
{
    utsname name = {0};
    uname(&name);

    return name.version;
}

inline std::string
Machine() noexcept
{
    utsname name = {0};
    uname(&name);

    return name.machine;
}

inline std::string
Nodename() noexcept
{
    utsname name = {0};
    uname(&name);

    return name.nodename;
}

inline std::string
Processor() noexcept
{
    ACOW_NOT_IMPLEMENTED();
}

inline std::string
HardwarePlatform() noexcept
{
    ACOW_NOT_IMPLEMENTED();
}

inline std::string
OperatingSystem() noexcept
{
    KernelName();
}

} // namespace OS
} // namespace acow