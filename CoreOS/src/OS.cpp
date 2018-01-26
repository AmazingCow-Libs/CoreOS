
// Header
#include "../include/OS.h"
// Amazing Cow Libs
#include "acow/cpp_goodies.h"
#include "acow/utsname.h"


bool CoreOS::OSInfo::IsBSD() noexcept
{
    return bool(ACOW_OS_IS_BSD);
}

bool CoreOS::OSInfo::IsGNULinux() noexcept
{
    return bool(ACOW_OS_IS_GNU_LINUX);
}

bool CoreOS::OSInfo::IsOSX() noexcept
{
    return bool(ACOW_OS_IS_OSX);
}

bool CoreOS::OSInfo::IsWindows() noexcept
{
    return bool(ACOW_OS_IS_WINDOWS);
}


bool CoreOS::OSInfo::IsUnix() noexcept
{
    return bool(ACOW_OS_IS_UNIX);
}

const std::string& CoreOS::OSInfo::GetOSName() noexcept
{
    return "";
}


//----------------------------------------------------------------------------//
//                                                                            //
//----------------------------------------------------------------------------//
std::string CoreOS::OSInfo::KernelName() noexcept
{
    utsname name = {};
    uname(&name);

    return name.sysname;
}

std::string CoreOS::OSInfo::KernelRelease() noexcept
{
    utsname name = {};
    uname(&name);

    return name.release;
}

std::string CoreOS::OSInfo::KernelVersion() noexcept
{
    utsname name = {};
    uname(&name);

    return name.version;
}

std::string CoreOS::OSInfo::Machine() noexcept
{
    utsname name = {};
    uname(&name);
    
    return name.machine;
}

std::string CoreOS::OSInfo::Nodename() noexcept
{
    utsname name = {};
    uname(&name);

    return name.nodename;
}

std::string CoreOS::OSInfo::Processor() noexcept
{    
    return "";
}

std::string CoreOS::OSInfo::HardwarePlatform() noexcept
{
    return "";
}

std::string CoreOS::OSInfo::OperatingSystem() noexcept
{
    return KernelName();
}
