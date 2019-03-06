// wrapClass1.cpp
// This is generated code, do not edit
// #######################################################################
// Copyright (c) 2017-2019, Lawrence Livermore National Security, LLC.
//
// Produced at the Lawrence Livermore National Laboratory
//
// LLNL-CODE-738041.
//
// All rights reserved.
//
// This file is part of Shroud.
//
// For details about use and distribution, please read LICENSE.
//
// #######################################################################
#include "wrapClass1.h"
#include "ownership.hpp"

// splicer begin class.Class1.CXX_definitions
// splicer end class.Class1.CXX_definitions

extern "C" {

// splicer begin class.Class1.C_definitions
// splicer end class.Class1.C_definitions

// ~Class1()
void OWN_class1_dtor(OWN_class1 * self)
{
// splicer begin class.Class1.method.dtor
    Class1 *SH_this = static_cast<Class1 *>(self->addr);
    delete SH_this;
    self->addr = NULL;
    return;
// splicer end class.Class1.method.dtor
}

// int getFlag()
int OWN_class1_get_flag(OWN_class1 * self)
{
// splicer begin class.Class1.method.get_flag
    Class1 *SH_this = static_cast<Class1 *>(self->addr);
    return SH_this->m_flag;
// splicer end class.Class1.method.get_flag
}

}  // extern "C"