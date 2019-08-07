// pypreprocessmodule.hpp
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
#ifndef PYPREPROCESSMODULE_HPP
#define PYPREPROCESSMODULE_HPP
#include <Python.h>
// splicer begin header.include
// splicer end header.include

// utility functions
extern void PY_SHROUD_release_memory(int icontext, void *ptr);
extern void *PY_SHROUD_fetch_context(int icontext);
extern void PY_SHROUD_capsule_destructor(PyObject *cap);

// ------------------------------
class User1;  // forward declare
extern PyTypeObject PY_User1_Type;
// splicer begin class.User1.C_declaration
// splicer end class.User1.C_declaration

typedef struct {
PyObject_HEAD
    User1 * obj;
    int idtor;
    // splicer begin class.User1.C_object
    // splicer end class.User1.C_object
} PY_User1;

extern const char *PY_User1_capsule_name;
PyObject *PP_User1_to_Object(User1 *addr);
int PP_User1_from_Object(PyObject *obj, void **addr);

// ------------------------------
#ifdef USE_USER2
class User2;  // forward declare
extern PyTypeObject PY_User2_Type;
// splicer begin class.User2.C_declaration
// splicer end class.User2.C_declaration

typedef struct {
PyObject_HEAD
    User2 * obj;
    int idtor;
    // splicer begin class.User2.C_object
    // splicer end class.User2.C_object
} PY_User2;

extern const char *PY_User2_capsule_name;
PyObject *PP_User2_to_Object(User2 *addr);
int PP_User2_from_Object(PyObject *obj, void **addr);
#endif // ifdef USE_USER2
// ------------------------------

// splicer begin header.C_declaration
// splicer end header.C_declaration

extern PyObject *PY_error_obj;

#if PY_MAJOR_VERSION >= 3
extern "C" PyMODINIT_FUNC PyInit_preprocess(void);
#else
extern "C" PyMODINIT_FUNC initpreprocess(void);
#endif

#endif  /* PYPREPROCESSMODULE_HPP */