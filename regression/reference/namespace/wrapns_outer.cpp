// wrapns_outer.cpp
// This file is generated by Shroud 0.11.0. Do not edit.
// Copyright (c) 2017-2020, Lawrence Livermore National Security, LLC and
// other Shroud Project Developers.
// See the top-level COPYRIGHT file for details.
//
// SPDX-License-Identifier: (BSD-3-Clause)
//
#include "wrapns_outer.h"
#include "namespace.hpp"

// splicer begin namespace.outer.CXX_definitions
// splicer end namespace.outer.CXX_definitions

extern "C" {

// splicer begin namespace.outer.C_definitions
// splicer end namespace.outer.C_definitions

// void One()
// ----------------------------------------
// Result
// Requested: c
// Match:     c_default
void NS_outer_one()
{
    // splicer begin namespace.outer.function.one
    outer::One();
    // splicer end namespace.outer.function.one
}

}  // extern "C"
