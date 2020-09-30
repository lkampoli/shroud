// pypreprocessutil.cpp
// This file is generated by Shroud nowrite-version. Do not edit.
// Copyright (c) 2017-2020, Lawrence Livermore National Security, LLC and
// other Shroud Project Developers.
// See the top-level COPYRIGHT file for details.
//
// SPDX-License-Identifier: (BSD-3-Clause)
//

// shroud
#include "pypreprocessmodule.hpp"

#ifdef __cplusplus
#define SHROUD_UNUSED(param)
#else
#define SHROUD_UNUSED(param) param
#endif

#if PY_MAJOR_VERSION >= 3
#define PyInt_AsLong PyLong_AsLong
#define PyInt_FromLong PyLong_FromLong
#define PyInt_FromSize_t PyLong_FromSize_t
#define PyString_FromString PyUnicode_FromString
#define PyString_FromStringAndSize PyUnicode_FromStringAndSize
#endif

const char *PY_User1_capsule_name = "User1";
#ifdef USE_USER2
const char *PY_User2_capsule_name = "User2";
#endif  // ifdef USE_USER2


// Wrap pointer to struct/class.
PyObject *PP_User1_to_Object_idtor(User1 *addr, int idtor)
{
    // splicer begin class.User1.utility.to_object
    PY_User1 *obj = PyObject_New(PY_User1, &PY_User1_Type);
    if (obj == nullptr)
        return nullptr;
    obj->obj = addr;
    obj->idtor = idtor;
    return reinterpret_cast<PyObject *>(obj);
    // splicer end class.User1.utility.to_object
}

// converter which may be used with PyBuild.
PyObject *PP_User1_to_Object(User1 *addr)
{
    // splicer begin class.User1.utility.to_object
    PyObject *voidobj;
    PyObject *args;
    PyObject *rv;

    voidobj = PyCapsule_New(addr, PY_User1_capsule_name, nullptr);
    args = PyTuple_New(1);
    PyTuple_SET_ITEM(args, 0, voidobj);
    rv = PyObject_Call((PyObject *) &PY_User1_Type, args, nullptr);
    Py_DECREF(args);
    return rv;
    // splicer end class.User1.utility.to_object
}

// converter which may be used with PyArg_Parse.
int PP_User1_from_Object(PyObject *obj, void **addr)
{
    // splicer begin class.User1.utility.from_object
    if (obj->ob_type != &PY_User1_Type) {
        // raise exception
        return 0;
    }
    PY_User1 * self = (PY_User1 *) obj;
    *addr = self->obj;
    return 1;
    // splicer end class.User1.utility.from_object
}

#ifdef USE_USER2
// Wrap pointer to struct/class.
PyObject *PP_User2_to_Object_idtor(User2 *addr, int idtor)
{
    // splicer begin class.User2.utility.to_object
    PY_User2 *obj = PyObject_New(PY_User2, &PY_User2_Type);
    if (obj == nullptr)
        return nullptr;
    obj->obj = addr;
    obj->idtor = idtor;
    return reinterpret_cast<PyObject *>(obj);
    // splicer end class.User2.utility.to_object
}

#ifdef USE_USER2
// converter which may be used with PyBuild.
PyObject *PP_User2_to_Object(User2 *addr)
{
    // splicer begin class.User2.utility.to_object
    PyObject *voidobj;
    PyObject *args;
    PyObject *rv;

    voidobj = PyCapsule_New(addr, PY_User2_capsule_name, nullptr);
    args = PyTuple_New(1);
    PyTuple_SET_ITEM(args, 0, voidobj);
    rv = PyObject_Call((PyObject *) &PY_User2_Type, args, nullptr);
    Py_DECREF(args);
    return rv;
    // splicer end class.User2.utility.to_object
}

// converter which may be used with PyArg_Parse.
int PP_User2_from_Object(PyObject *obj, void **addr)
{
    // splicer begin class.User2.utility.from_object
    if (obj->ob_type != &PY_User2_Type) {
        // raise exception
        return 0;
    }
    PY_User2 * self = (PY_User2 *) obj;
    *addr = self->obj;
    return 1;
    // splicer end class.User2.utility.from_object
}
#endif  // ifdef USE_USER2

// ----------------------------------------
typedef struct {
    const char *name;
    void (*dtor)(void *ptr);
} PY_SHROUD_dtor_context;

// 0 - --none--
static void PY_SHROUD_capsule_destructor_0(void *ptr)
{
    // Do not release
}

// Code used to release arrays for NumPy objects
// via a Capsule base object with a destructor.
// Context strings
static PY_SHROUD_dtor_context PY_SHROUD_capsule_context[] = {
    {"--none--", PY_SHROUD_capsule_destructor_0},
    {nullptr, nullptr},
};

// Release memory based on icontext.
void PY_SHROUD_release_memory(int icontext, void *ptr)
{
    PY_SHROUD_capsule_context[icontext].dtor(ptr);
}

//Fetch garbage collection context.
void *PY_SHROUD_fetch_context(int icontext)
{
    return PY_SHROUD_capsule_context + icontext;
}

// destructor function for PyCapsule
void PY_SHROUD_capsule_destructor(PyObject *cap)
{
    void *ptr = PyCapsule_GetPointer(cap, "PY_array_dtor");
    PY_SHROUD_dtor_context * context = static_cast<PY_SHROUD_dtor_context *>
        (PyCapsule_GetContext(cap));
    context->dtor(ptr);
}
