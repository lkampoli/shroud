// wrapuser.cpp
// This is generated code, do not edit
#include "wrapuser.h"

// splicer begin class.user.CXX_definitions
// splicer end class.user.CXX_definitions

extern "C" {

// splicer begin class.user.C_definitions
// splicer end class.user.C_definitions

void TEM_user_nested_double(TEM_user_0 * self, int value, double arg2)
{
// splicer begin class.user.method.nested_double
    std::user<int> *SH_this = static_cast<std::user<int> *>(self->addr);
    SH_this->nested<double>(value, arg2);
    return;
// splicer end class.user.method.nested_double
}

}  // extern "C"
