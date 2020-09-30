// wrapSingleton.h
// This file is generated by Shroud nowrite-version. Do not edit.
// Copyright (c) 2017-2020, Lawrence Livermore National Security, LLC and
// other Shroud Project Developers.
// See the top-level COPYRIGHT file for details.
//
// SPDX-License-Identifier: (BSD-3-Clause)
//
/**
 * \file wrapSingleton.h
 * \brief Shroud generated wrapper for Singleton class
 */
// For C users and C++ implementation

#ifndef WRAPSINGLETON_H
#define WRAPSINGLETON_H

// shroud
#include "typesclasses.h"

// splicer begin class.Singleton.CXX_declarations
// splicer end class.Singleton.CXX_declarations

#ifdef __cplusplus
extern "C" {
#endif

// splicer begin class.Singleton.C_declarations
// splicer end class.Singleton.C_declarations

CLA_Singleton * CLA_Singleton_get_reference(CLA_Singleton * SHadow_rv);

#ifdef __cplusplus
}
#endif

#endif  // WRAPSINGLETON_H
