
#pragma once
// std
#include <string>
// CoreOS
#include "CoreOS_Utils.h"

NS_COREOS_BEGIN
namespace OSInfo
{
    //------------------------------------------------------------------------//
    //                                                                        //
    //------------------------------------------------------------------------//
    bool IsBSD     () noexcept;
    bool IsGNULinux() noexcept;
    bool IsOSX     () noexcept;
    bool IsWindows () noexcept;

    bool IsUnix() noexcept;

    const std::string& GetOSName() noexcept;

    //------------------------------------------------------------------------//
    //                                                                        //
    //------------------------------------------------------------------------//
    const std::string& KernelName      () noexcept;
    const std::string& KernelRelease   () noexcept;
    const std::string& KernelVersion   () noexcept;
    const std::string& Machine         () noexcept;
    const std::string& Nodename        () noexcept;
    const std::string& Processor       () noexcept;
    const std::string& HardwarePlatform() noexcept;
    const std::string& OperatingSystem () noexcept;

} // namespace OSInfo
NS_COREOS_END