#pragma once

//----------------------------------------------------------------------------//
// Namespaces                                                                 //
//----------------------------------------------------------------------------//
// All classes of this core is placed inside this namespace.
// We use MACROS so is easier to change if needed.
// Is (in our opinion) more explicit.
// And finally the editors will not reformat the code.
#define NS_COREOS_BEGIN namespace CoreOS {
#define NS_COREOS_END   }
#define USING_NS_COREOS using namespace CoreOS;


//----------------------------------------------------------------------------//
// Version                                                                    //
//----------------------------------------------------------------------------//
#define COW_COREOS_VERSION_MAJOR    "0"
#define COW_COREOS_VERSION_MINOR    "0"
#define COW_COREOS_VERSION_REVISION "1"

#define COW_COREOS_VERSION       \
    COW_COREOS_VERSION_MAJOR "." \
    COW_COREOS_VERSION_MINOR "." \
    COW_COREOS_VERSION_REVISION
