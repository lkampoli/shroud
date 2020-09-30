// pyCstruct1_clstype.cpp
// This file is generated by Shroud nowrite-version. Do not edit.
// Copyright (c) 2017-2020, Lawrence Livermore National Security, LLC and
// other Shroud Project Developers.
// See the top-level COPYRIGHT file for details.
//
// SPDX-License-Identifier: (BSD-3-Clause)
//
#include "pycxxlibrarymodule.hpp"
#define NO_IMPORT_ARRAY
#define PY_ARRAY_UNIQUE_SYMBOL SHROUD_CXXLIBRARY_ARRAY_API
#define NPY_NO_DEPRECATED_API NPY_1_7_API_VERSION
#include "numpy/arrayobject.h"

// splicer begin class.Cstruct1_cls.impl.include
// splicer end class.Cstruct1_cls.impl.include

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
// splicer begin class.Cstruct1_cls.impl.C_definition
// splicer end class.Cstruct1_cls.impl.C_definition
// splicer begin class.Cstruct1_cls.impl.additional_methods
// splicer end class.Cstruct1_cls.impl.additional_methods
static void
PY_Cstruct1_cls_tp_del (PY_Cstruct1_cls *self)
{
// splicer begin class.Cstruct1_cls.type.del
    PY_SHROUD_release_memory(self->idtor, self->obj);
    self->obj = nullptr;
// splicer end class.Cstruct1_cls.type.del
}

// ----------------------------------------
// Function:  Cstruct1_cls +name(Cstruct1_cls_ctor)
// Exact:     py_default
// ----------------------------------------
// Argument:  int ifield +intent(in)
// Requested: py_ctor_native_scalar_numpy
// Match:     py_ctor_native
// ----------------------------------------
// Argument:  double dfield +intent(in)
// Requested: py_ctor_native_scalar_numpy
// Match:     py_ctor_native
static int
PY_Cstruct1_cls_tp_init(
  PY_Cstruct1_cls *self,
  PyObject *args,
  PyObject *kwds)
{
// splicer begin class.Cstruct1_cls.method.cstruct1_cls_ctor
    int ifield = 0;
    double dfield = 0;
    const char *SHT_kwlist[] = {
        "ifield",
        "dfield",
        nullptr };

    if (!PyArg_ParseTupleAndKeywords(args, kwds,
        "|id:Cstruct1_cls_ctor", const_cast<char **>(SHT_kwlist), 
        &ifield, &dfield))
        return -1;

    self->obj = new Cstruct1_cls;
    if (self->obj == nullptr) {
        PyErr_NoMemory();
        return -1;
    }
    self->idtor = 1;

    // post_call - initialize fields
    Cstruct1_cls *SH_obj = self->obj;
    SH_obj->ifield = ifield;
    SH_obj->dfield = dfield;

    return 0;
// splicer end class.Cstruct1_cls.method.cstruct1_cls_ctor
}
// splicer begin class.Cstruct1_cls.impl.after_methods
// splicer end class.Cstruct1_cls.impl.after_methods

// Requested: py_descr_native_scalar
// Match:     py_descr_native
static PyObject *PY_Cstruct1_cls_ifield_getter(PY_Cstruct1_cls *self,
    void *SHROUD_UNUSED(closure))
{
    PyObject * rv = PyInt_FromLong(self->obj->ifield);
    return rv;
}

// Requested: py_descr_native_scalar
// Match:     py_descr_native
static int PY_Cstruct1_cls_ifield_setter(PY_Cstruct1_cls *self, PyObject *value,
    void *SHROUD_UNUSED(closure))
{
    int rv = PyInt_AsLong(value);
    if (PyErr_Occurred()) {
        return -1;
    }
    self->obj->ifield = rv;
    return 0;
}

// Requested: py_descr_native_scalar
// Match:     py_descr_native
static PyObject *PY_Cstruct1_cls_dfield_getter(PY_Cstruct1_cls *self,
    void *SHROUD_UNUSED(closure))
{
    PyObject * rv = PyFloat_FromDouble(self->obj->dfield);
    return rv;
}

// Requested: py_descr_native_scalar
// Match:     py_descr_native
static int PY_Cstruct1_cls_dfield_setter(PY_Cstruct1_cls *self, PyObject *value,
    void *SHROUD_UNUSED(closure))
{
    double rv = PyFloat_AsDouble(value);
    if (PyErr_Occurred()) {
        return -1;
    }
    self->obj->dfield = rv;
    return 0;
}

static PyGetSetDef PY_Cstruct1_cls_getset[] = {
    {(char *)"ifield", (getter)PY_Cstruct1_cls_ifield_getter,
        (setter)PY_Cstruct1_cls_ifield_setter, nullptr, nullptr},
    {(char *)"dfield", (getter)PY_Cstruct1_cls_dfield_getter,
        (setter)PY_Cstruct1_cls_dfield_setter, nullptr, nullptr},
    // splicer begin class.Cstruct1_cls.PyGetSetDef
    // splicer end class.Cstruct1_cls.PyGetSetDef
    {nullptr}            /* sentinel */
};
static PyMethodDef PY_Cstruct1_cls_methods[] = {
    // splicer begin class.Cstruct1_cls.PyMethodDef
    // splicer end class.Cstruct1_cls.PyMethodDef
    {nullptr,   (PyCFunction)nullptr, 0, nullptr}            /* sentinel */
};

static char Cstruct1_cls__doc__[] =
"virtual class"
;

/* static */
PyTypeObject PY_Cstruct1_cls_Type = {
    PyVarObject_HEAD_INIT(nullptr, 0)
    "cxxlibrary.Cstruct1_cls",                       /* tp_name */
    sizeof(PY_Cstruct1_cls),         /* tp_basicsize */
    0,                              /* tp_itemsize */
    /* Methods to implement standard operations */
    (destructor)nullptr,                 /* tp_dealloc */
    (printfunc)nullptr,                   /* tp_print */
    (getattrfunc)nullptr,                 /* tp_getattr */
    (setattrfunc)nullptr,                 /* tp_setattr */
#if PY_MAJOR_VERSION >= 3
    nullptr,                               /* tp_reserved */
#else
    (cmpfunc)nullptr,                     /* tp_compare */
#endif
    (reprfunc)nullptr,                    /* tp_repr */
    /* Method suites for standard classes */
    nullptr,                              /* tp_as_number */
    nullptr,                              /* tp_as_sequence */
    nullptr,                              /* tp_as_mapping */
    /* More standard operations (here for binary compatibility) */
    (hashfunc)nullptr,                    /* tp_hash */
    (ternaryfunc)nullptr,                 /* tp_call */
    (reprfunc)nullptr,                    /* tp_str */
    (getattrofunc)nullptr,                /* tp_getattro */
    (setattrofunc)nullptr,                /* tp_setattro */
    /* Functions to access object as input/output buffer */
    nullptr,                              /* tp_as_buffer */
    /* Flags to define presence of optional/expanded features */
    Py_TPFLAGS_DEFAULT,             /* tp_flags */
    Cstruct1_cls__doc__,         /* tp_doc */
    /* Assigned meaning in release 2.0 */
    /* call function for all accessible objects */
    (traverseproc)nullptr,                /* tp_traverse */
    /* delete references to contained objects */
    (inquiry)nullptr,                     /* tp_clear */
    /* Assigned meaning in release 2.1 */
    /* rich comparisons */
    (richcmpfunc)nullptr,                 /* tp_richcompare */
    /* weak reference enabler */
    0,                              /* tp_weaklistoffset */
    /* Added in release 2.2 */
    /* Iterators */
    (getiterfunc)nullptr,                 /* tp_iter */
    (iternextfunc)nullptr,                /* tp_iternext */
    /* Attribute descriptor and subclassing stuff */
    PY_Cstruct1_cls_methods,                             /* tp_methods */
    nullptr,                              /* tp_members */
    PY_Cstruct1_cls_getset,                             /* tp_getset */
    nullptr,                              /* tp_base */
    nullptr,                              /* tp_dict */
    (descrgetfunc)nullptr,                /* tp_descr_get */
    (descrsetfunc)nullptr,                /* tp_descr_set */
    0,                              /* tp_dictoffset */
    (initproc)PY_Cstruct1_cls_tp_init,                   /* tp_init */
    (allocfunc)nullptr,                  /* tp_alloc */
    (newfunc)nullptr,                    /* tp_new */
    (freefunc)nullptr,                   /* tp_free */
    (inquiry)nullptr,                     /* tp_is_gc */
    nullptr,                              /* tp_bases */
    nullptr,                              /* tp_mro */
    nullptr,                              /* tp_cache */
    nullptr,                              /* tp_subclasses */
    nullptr,                              /* tp_weaklist */
    (destructor)PY_Cstruct1_cls_tp_del,                 /* tp_del */
    0,                              /* tp_version_tag */
#if PY_MAJOR_VERSION >= 3
    (destructor)nullptr,                  /* tp_finalize */
#endif
};
