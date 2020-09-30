// pynsutil.cpp
// This file is generated by Shroud nowrite-version. Do not edit.
// Copyright (c) 2017-2020, Lawrence Livermore National Security, LLC and
// other Shroud Project Developers.
// See the top-level COPYRIGHT file for details.
//
// SPDX-License-Identifier: (BSD-3-Clause)
//

// shroud
#include "pynsmodule.hpp"

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

const char *PY_Cstruct1_capsule_name = "Cstruct1";
const char *PY_ClassWork_capsule_name = "ClassWork";


// Wrap pointer to struct/class.
PyObject *PP_Cstruct1_to_Object_idtor(outer::Cstruct1 *addr, int idtor)
{
    // splicer begin namespace.outer.class.Cstruct1.utility.to_object
    PY_Cstruct1 *obj = PyObject_New(PY_Cstruct1, &PY_Cstruct1_Type);
    if (obj == nullptr)
        return nullptr;
    obj->obj = addr;
    obj->idtor = idtor;
    return reinterpret_cast<PyObject *>(obj);
    // splicer end namespace.outer.class.Cstruct1.utility.to_object
}

// converter which may be used with PyBuild.
PyObject *PP_Cstruct1_to_Object(outer::Cstruct1 *addr)
{
    // splicer begin namespace.outer.class.Cstruct1.utility.to_object
    PyObject *voidobj;
    PyObject *args;
    PyObject *rv;

    voidobj = PyCapsule_New(addr, PY_Cstruct1_capsule_name, nullptr);
    args = PyTuple_New(1);
    PyTuple_SET_ITEM(args, 0, voidobj);
    rv = PyObject_Call((PyObject *) &PY_Cstruct1_Type, args, nullptr);
    Py_DECREF(args);
    return rv;
    // splicer end namespace.outer.class.Cstruct1.utility.to_object
}

// converter which may be used with PyArg_Parse.
int PP_Cstruct1_from_Object(PyObject *obj, void **addr)
{
    // splicer begin namespace.outer.class.Cstruct1.utility.from_object
    if (obj->ob_type != &PY_Cstruct1_Type) {
        // raise exception
        return 0;
    }
    PY_Cstruct1 * self = (PY_Cstruct1 *) obj;
    *addr = self->obj;
    return 1;
    // splicer end namespace.outer.class.Cstruct1.utility.from_object
}

// Wrap pointer to struct/class.
PyObject *PP_ClassWork_to_Object_idtor(nswork::ClassWork *addr,
    int idtor)
{
    // splicer begin namespace.nswork.class.ClassWork.utility.to_object
    PY_ClassWork *obj = PyObject_New(PY_ClassWork, &PY_ClassWork_Type);
    if (obj == nullptr)
        return nullptr;
    obj->obj = addr;
    obj->idtor = idtor;
    return reinterpret_cast<PyObject *>(obj);
    // splicer end namespace.nswork.class.ClassWork.utility.to_object
}

// converter which may be used with PyBuild.
PyObject *PP_ClassWork_to_Object(nswork::ClassWork *addr)
{
    // splicer begin namespace.nswork.class.ClassWork.utility.to_object
    PyObject *voidobj;
    PyObject *args;
    PyObject *rv;

    voidobj = PyCapsule_New(addr, PY_ClassWork_capsule_name, nullptr);
    args = PyTuple_New(1);
    PyTuple_SET_ITEM(args, 0, voidobj);
    rv = PyObject_Call((PyObject *) &PY_ClassWork_Type, args, nullptr);
    Py_DECREF(args);
    return rv;
    // splicer end namespace.nswork.class.ClassWork.utility.to_object
}

// converter which may be used with PyArg_Parse.
int PP_ClassWork_from_Object(PyObject *obj, void **addr)
{
    // splicer begin namespace.nswork.class.ClassWork.utility.from_object
    if (obj->ob_type != &PY_ClassWork_Type) {
        // raise exception
        return 0;
    }
    PY_ClassWork * self = (PY_ClassWork *) obj;
    *addr = self->obj;
    return 1;
    // splicer end namespace.nswork.class.ClassWork.utility.from_object
}

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

// 1 - cxx outer::Cstruct1 *
static void PY_SHROUD_capsule_destructor_1(void *ptr)
{
    outer::Cstruct1 * cxx_ptr = static_cast<outer::Cstruct1 *>(ptr);
    delete cxx_ptr;
}

// Code used to release arrays for NumPy objects
// via a Capsule base object with a destructor.
// Context strings
static PY_SHROUD_dtor_context PY_SHROUD_capsule_context[] = {
    {"--none--", PY_SHROUD_capsule_destructor_0},
    {"cxx outer::Cstruct1 *", PY_SHROUD_capsule_destructor_1},
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
