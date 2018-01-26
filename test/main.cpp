// std
#include <iostream>
// CoreOS
#include "../CoreOS/CoreOS.h"
#include "CoreAssert/CoreAssert.h"

int main()
{
    std::cout << "IsBSD      : " << CoreOS::OSInfo::IsBSD     () << "\n";
    std::cout << "IsGNULinux : " << CoreOS::OSInfo::IsGNULinux() << "\n";
    std::cout << "IsOSX      : " << CoreOS::OSInfo::IsOSX     () << "\n";
    std::cout << "IsWindows  : " << CoreOS::OSInfo::IsWindows () << "\n";
    std::cout << "IsUnix     : " << CoreOS::OSInfo::IsUnix    () << "\n";

    COREASSERT_NOT_IMPLEMENTED("teste %d ", 2);

    std::cout << std::endl;
}