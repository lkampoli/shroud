// wraplibrary.cpp
// This file is generated by Shroud nowrite-version. Do not edit.
// Copyright (c) 2017-2020, Lawrence Livermore National Security, LLC and
// other Shroud Project Developers.
// See the top-level COPYRIGHT file for details.
//
// SPDX-License-Identifier: (BSD-3-Clause)
//
#include "zzheader.hpp"
#include "global_header.hpp"
#include "typeslibrary.h"
#include <cstdlib>


extern "C" {


// Release library allocated memory.
void LIB_SHROUD_memory_destructor(LIB_SHROUD_capsule_data *cap)
{
    cap->addr = nullptr;
    cap->idtor = 0;  // avoid deleting again
}

}  // extern "C"
