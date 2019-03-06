// wrapownership.h
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
/**
 * \file wrapownership.h
 * \brief Shroud generated wrapper for ownership library
 */
// For C users and C++ implementation

#ifndef WRAPOWNERSHIP_H
#define WRAPOWNERSHIP_H

#include "typesownership.h"

// splicer begin CXX_declarations
// splicer end CXX_declarations

#ifdef __cplusplus
extern "C" {
#endif

// splicer begin C_declarations
// splicer end C_declarations

int * OWN_return_int_ptr_raw();

int OWN_return_int_ptr_scalar();

int * OWN_return_int_ptr_pointer();

int * OWN_return_int_ptr_dim_raw(int * len);

int * OWN_return_int_ptr_dim_pointer(int * len);

int * OWN_return_int_ptr_dim_alloc(int * len);

int * OWN_return_int_ptr_dim_alloc_bufferify(OWN_SHROUD_array *DSHC_rv,
    int * len);

int * OWN_return_int_ptr_dim_default(int * len);

int * OWN_return_int_ptr_dim_raw_new(int * len);

int * OWN_return_int_ptr_dim_pointer_new(int * len);

int * OWN_return_int_ptr_dim_alloc_new(int * len);

int * OWN_return_int_ptr_dim_default_new(int * len);

void OWN_create_class_static(int flag);

OWN_class1 * OWN_get_class_static(OWN_class1 * SHC_rv);

OWN_class1 * OWN_get_class_new(int flag, OWN_class1 * SHC_rv);

#ifdef __cplusplus
}
#endif

#endif  // WRAPOWNERSHIP_H