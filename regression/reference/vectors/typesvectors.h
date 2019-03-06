// typesvectors.h
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
// For C users and C++ implementation

#ifndef TYPESVECTORS_H
#define TYPESVECTORS_H

#include <stddef.h>


#ifdef __cplusplus
extern "C" {
#endif

struct s_VEC_SHROUD_capsule_data {
    void *addr;     /* address of C++ memory */
    int idtor;      /* index of destructor */
};
typedef struct s_VEC_SHROUD_capsule_data VEC_SHROUD_capsule_data;

struct s_VEC_SHROUD_array {
    VEC_SHROUD_capsule_data cxx;      /* address of C++ memory */
    union {
        const void * cvoidp;
        const char * ccharp;
    } addr;
    size_t len;     /* bytes-per-item or character len of data in cxx */
    size_t size;    /* size of data in cxx */
};
typedef struct s_VEC_SHROUD_array VEC_SHROUD_array;

void VEC_SHROUD_memory_destructor(VEC_SHROUD_capsule_data *cap);

#ifdef __cplusplus
}
#endif

#endif  // TYPESVECTORS_H