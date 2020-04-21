// wrapClass2.h
// This file is generated by Shroud 0.11.0. Do not edit.
// Copyright (c) 2017-2020, Lawrence Livermore National Security, LLC and
// other Shroud Project Developers.
// See the top-level COPYRIGHT file for details.
//
// SPDX-License-Identifier: (BSD-3-Clause)
//
/**
 * \file wrapClass2.h
 * \brief Shroud generated wrapper for Class2 class
 */
// For C users and C++ implementation

#ifndef WRAPCLASS2_H
#define WRAPCLASS2_H

#include "typesclasses.h"

// splicer begin class.Class2.CXX_declarations
// splicer end class.Class2.CXX_declarations

#ifdef __cplusplus
extern "C" {
#endif

// splicer begin class.Class2.C_declarations
// splicer end class.Class2.C_declarations

const char * CLA_Class2_get_name(CLA_Class2 * self);

void CLA_Class2_get_name_bufferify(CLA_Class2 * self,
    CLA_SHROUD_array *DSHF_rv);

#ifdef __cplusplus
}
#endif

#endif  // WRAPCLASS2_H
