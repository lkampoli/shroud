// wrapexample_nested_ExClass1.h
// This file is generated by Shroud 0.11.0. Do not edit.
// Copyright (c) 2017-2020, Lawrence Livermore National Security, LLC and
// other Shroud Project Developers.
// See the top-level COPYRIGHT file for details.
//
// SPDX-License-Identifier: (BSD-3-Clause)
//
/**
 * \file wrapexample_nested_ExClass1.h
 * \brief Shroud generated wrapper for ExClass1 class
 */
// For C users and C++ implementation

#ifndef WRAPEXAMPLE_NESTED_EXCLASS1_H
#define WRAPEXAMPLE_NESTED_EXCLASS1_H

#include "typesUserLibrary.h"
#ifndef __cplusplus
#include <stdbool.h>
#endif

// splicer begin namespace.example::nested.class.ExClass1.CXX_declarations
// splicer end namespace.example::nested.class.ExClass1.CXX_declarations

#ifdef __cplusplus
extern "C" {
#endif

// splicer begin namespace.example::nested.class.ExClass1.C_declarations
// splicer end namespace.example::nested.class.ExClass1.C_declarations

AA_example_nested_ExClass1 * AA_example_nested_ExClass1_ctor_0(
    AA_example_nested_ExClass1 * SHC_rv);

AA_example_nested_ExClass1 * AA_example_nested_ExClass1_ctor_1(
    const char * name, AA_example_nested_ExClass1 * SHC_rv);

AA_example_nested_ExClass1 * AA_example_nested_ExClass1_ctor_1_bufferify(
    const char * name, int Lname, AA_example_nested_ExClass1 * SHC_rv);

void AA_example_nested_ExClass1_dtor(AA_example_nested_ExClass1 * self);

int AA_example_nested_ExClass1_increment_count(
    AA_example_nested_ExClass1 * self, int incr);

const char * AA_example_nested_ExClass1_get_name_error_check(
    const AA_example_nested_ExClass1 * self);

void AA_example_nested_ExClass1_get_name_error_check_bufferify(
    const AA_example_nested_ExClass1 * self, AA_SHROUD_array *DSHF_rv);

const char * AA_example_nested_ExClass1_get_name_arg(
    const AA_example_nested_ExClass1 * self);

void AA_example_nested_ExClass1_get_name_arg_bufferify(
    const AA_example_nested_ExClass1 * self, char * name, int Nname);

int AA_example_nested_ExClass1_get_value_from_int(
    AA_example_nested_ExClass1 * self, int value);

long AA_example_nested_ExClass1_get_value_1(
    AA_example_nested_ExClass1 * self, long value);

bool AA_example_nested_ExClass1_has_addr(
    AA_example_nested_ExClass1 * self, bool in);

void AA_example_nested_ExClass1_splicer_special(
    AA_example_nested_ExClass1 * self);

#ifdef __cplusplus
}
#endif

#endif  // WRAPEXAMPLE_NESTED_EXCLASS1_H
