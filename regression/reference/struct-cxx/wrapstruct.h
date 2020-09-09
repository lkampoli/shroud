// wrapstruct.h
// This file is generated by Shroud nowrite-version. Do not edit.
// Copyright (c) 2017-2020, Lawrence Livermore National Security, LLC and
// other Shroud Project Developers.
// See the top-level COPYRIGHT file for details.
//
// SPDX-License-Identifier: (BSD-3-Clause)
//
/**
 * \file wrapstruct.h
 * \brief Shroud generated wrapper for struct library
 */
// For C users and C++ implementation

#ifndef WRAPSTRUCT_H
#define WRAPSTRUCT_H

#include "typesstruct.h"

// splicer begin CXX_declarations
// splicer end CXX_declarations

#ifdef __cplusplus
extern "C" {
#endif


struct s_STR_cstruct1 {
    int ifield;
    double dfield;
};
typedef struct s_STR_cstruct1 STR_cstruct1;


struct s_STR_cstruct_ptr {
    char * cfield;
    const double * const_dvalue;
};
typedef struct s_STR_cstruct_ptr STR_cstruct_ptr;


struct s_STR_cstruct_list {
    int nitems;
    int * ivalue;
    double * dvalue;
    char * * svalue;
};
typedef struct s_STR_cstruct_list STR_cstruct_list;


struct s_STR_cstruct_numpy {
    int nitems;
    int * ivalue;
    double * dvalue;
};
typedef struct s_STR_cstruct_numpy STR_cstruct_numpy;


struct s_STR_arrays1 {
    char name[20];
    int count[10];
};
typedef struct s_STR_arrays1 STR_arrays1;

// splicer begin C_declarations
// splicer end C_declarations

int STR_pass_struct_by_value(STR_cstruct1 arg);

int STR_pass_struct1(const STR_cstruct1 * arg);

int STR_pass_struct2(const STR_cstruct1 * s1, char * outbuf);

int STR_pass_struct2_bufferify(const STR_cstruct1 * s1, char * outbuf,
    int Noutbuf);

int STR_accept_struct_in_ptr(STR_cstruct1 * arg);

void STR_accept_struct_out_ptr(STR_cstruct1 * arg, int i, double d);

void STR_accept_struct_in_out_ptr(STR_cstruct1 * arg);

STR_cstruct1 STR_return_struct_by_value(int i, double d);

STR_cstruct1 * STR_return_struct_ptr1(int i, double d);

STR_cstruct1 * STR_return_struct_ptr2(int i, double d, char * outbuf);

STR_cstruct1 * STR_return_struct_ptr2_bufferify(int i, double d,
    char * outbuf, int Noutbuf);

STR_cstruct_list * STR_get_global_struct_list(void);

STR_Cstruct_as_class * STR_create__cstruct_as_class(
    STR_Cstruct_as_class * SHadow_rv);

STR_Cstruct_as_class * STR_create__cstruct_as_class_args(int x, int y,
    STR_Cstruct_as_class * SHadow_rv);

int STR_cstruct_as_class_sum(STR_Cstruct_as_class * point);

#ifdef __cplusplus
}
#endif

#endif  // WRAPSTRUCT_H
