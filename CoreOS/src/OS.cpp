
// Header
#include "../include/OS.h"
// Amazing Cow Libs
#include "acow/cpp_goodies.h"

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