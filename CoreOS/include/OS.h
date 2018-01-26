
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
    std::string KernelName      () noexcept;
    std::string KernelRelease   () noexcept;
    std::string KernelVersion   () noexcept;
    std::string Machine         () noexcept;
    std::string Nodename        () noexcept;
    std::string Processor       () noexcept;
    std::string HardwarePlatform() noexcept;
    std::string OperatingSystem () noexcept;

} // namespace OSInfo
NS_COREOS_END