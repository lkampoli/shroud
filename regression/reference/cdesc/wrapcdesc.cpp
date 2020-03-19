// wrapcdesc.cpp
// This file is generated by Shroud 0.11.0. Do not edit.
// Copyright (c) 2017-2020, Lawrence Livermore National Security, LLC and
// other Shroud Project Developers.
// See the top-level COPYRIGHT file for details.
//
// SPDX-License-Identifier: (BSD-3-Clause)
//
#include "wrapcdesc.h"
#include <cstdlib>
#include "cdesc.hpp"
#include "typescdesc.h"

// splicer begin CXX_definitions
// splicer end CXX_definitions

extern "C" {

// splicer begin C_definitions
// splicer end C_definitions

// void Rank2In(int * arg +cdesc+context(Darg)+intent(in)+rank(2))
void CDE_rank2_in(CDE_SHROUD_array *Darg)
{
    // splicer begin function.rank2_in
    int * arg = static_cast<int *>(const_cast<void *>(Darg->addr.base));
    Rank2In(arg);
    // splicer end function.rank2_in
}

// Release library allocated memory.
void CDE_SHROUD_memory_destructor(CDE_SHROUD_capsule_data *cap)
{
    cap->addr = nullptr;
    cap->idtor = 0;  // avoid deleting again
}

}  // extern "C"