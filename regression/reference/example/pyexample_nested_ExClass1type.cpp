// pyexample_nested_ExClass1type.cpp
// This file is generated by Shroud 0.12.0. Do not edit.
// Copyright (c) 2017-2020, Lawrence Livermore National Security, LLC and
// other Shroud Project Developers.
// See the top-level COPYRIGHT file for details.
//
// SPDX-License-Identifier: (BSD-3-Clause)
//
#include "pyUserLibrarymodule.hpp"
// splicer begin namespace.example::nested.class.ExClass1.impl.include
// splicer end namespace.example::nested.class.ExClass1.impl.include

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
// splicer begin namespace.example::nested.class.ExClass1.impl.C_definition
// splicer end namespace.example::nested.class.ExClass1.impl.C_definition
// splicer begin namespace.example::nested.class.ExClass1.impl.additional_methods
// splicer end namespace.example::nested.class.ExClass1.impl.additional_methods
static PyObject *
PP_ExClass1_tp_repr (PP_ExClass1 *self)
{
// splicer begin namespace.example::nested.class.ExClass1.type.repr
    PyErr_SetString(PyExc_NotImplementedError, "repr");
    return nullptr;
// splicer end namespace.example::nested.class.ExClass1.type.repr
}
static void
PP_ExClass1_tp_del (PP_ExClass1 *self)
{
// splicer begin namespace.example::nested.class.ExClass1.type.del
    PP_SHROUD_release_memory(self->idtor, self->obj);
    self->obj = nullptr;
// splicer end namespace.example::nested.class.ExClass1.type.del
}
static PyObject *
PP_ExClass1_tp_richcompare (PP_ExClass1 *self, PyObject *other, int opid)
{
// splicer begin namespace.example::nested.class.ExClass1.type.richcompare
    Py_INCREF(Py_NotImplemented);
    return Py_NotImplemented;
// splicer end namespace.example::nested.class.ExClass1.type.richcompare
}

// ----------------------------------------
// Function:  ExClass1
// Exact:     py_default
static int
PP_ExClass1_tp_init_0(
  PP_ExClass1 *self,
  PyObject *SHROUD_UNUSED(args),
  PyObject *SHROUD_UNUSED(kwds))
{
// splicer begin namespace.example::nested.class.ExClass1.method.ctor_0
    self->obj = new example::nested::ExClass1();
    if (self->obj == nullptr) {
        PyErr_NoMemory();
        return -1;
    }
    self->idtor = 1;
    return 0;
// splicer end namespace.example::nested.class.ExClass1.method.ctor_0
}

// ----------------------------------------
// Function:  ExClass1
// Exact:     py_default
// ----------------------------------------
// Argument:  const string * name +intent(in)
// Exact:     py_string_*_in
/**
 * \brief constructor
 *
 * longer description
 * usually multiple lines
 *
 * \return return new instance
 */
static int
PP_ExClass1_tp_init_1(
  PP_ExClass1 *self,
  PyObject *args,
  PyObject *kwds)
{
// splicer begin namespace.example::nested.class.ExClass1.method.ctor_1
    char * name;
    const char *SHT_kwlist[] = {
        "name",
        nullptr };

    if (!PyArg_ParseTupleAndKeywords(args, kwds, "s:ctor",
        const_cast<char **>(SHT_kwlist), &name))
        return -1;

    // post_declare
    const std::string SH_name(name);

    self->obj = new example::nested::ExClass1(&SH_name);
    if (self->obj == nullptr) {
        PyErr_NoMemory();
        return -1;
    }
    self->idtor = 1;
    return 0;
// splicer end namespace.example::nested.class.ExClass1.method.ctor_1
}

// ----------------------------------------
// Function:  int incrementCount
// Requested: py_native_scalar_result
// Match:     py_default
// ----------------------------------------
// Argument:  int incr +intent(in)+value
// Requested: py_native_scalar_in
// Match:     py_default
static char PP_incrementCount__doc__[] =
"documentation"
;

static PyObject *
PP_incrementCount(
  PP_ExClass1 *self,
  PyObject *args,
  PyObject *kwds)
{
// splicer begin namespace.example::nested.class.ExClass1.method.increment_count
    int incr;
    const char *SHT_kwlist[] = {
        "incr",
        nullptr };
    PyObject * SHTPy_rv = nullptr;

    if (!PyArg_ParseTupleAndKeywords(args, kwds, "i:incrementCount",
        const_cast<char **>(SHT_kwlist), &incr))
        return nullptr;

    int SHCXX_rv = self->obj->incrementCount(incr);

    // post_call
    SHTPy_rv = PyInt_FromLong(SHCXX_rv);

    return (PyObject *) SHTPy_rv;
// splicer end namespace.example::nested.class.ExClass1.method.increment_count
}

// ----------------------------------------
// Function:  const string & getNameErrorCheck +deref(allocatable)
// Exact:     py_string_&_result
static char PP_getNameErrorCheck__doc__[] =
"documentation"
;

static PyObject *
PP_getNameErrorCheck(
  PP_ExClass1 *self,
  PyObject *SHROUD_UNUSED(args),
  PyObject *SHROUD_UNUSED(kwds))
{
// splicer begin namespace.example::nested.class.ExClass1.method.get_name_error_check
    PyObject * SHTPy_rv = nullptr;

    const std::string & SHCXX_rv = self->obj->getNameErrorCheck();

    // post_call
    SHTPy_rv = PyString_FromStringAndSize(SHCXX_rv.data(),
        SHCXX_rv.size());

    return (PyObject *) SHTPy_rv;
// splicer end namespace.example::nested.class.ExClass1.method.get_name_error_check
}

// ----------------------------------------
// Function:  const string & getNameArg +deref(result-as-arg)
// Exact:     py_string_&_result
static char PP_getNameArg__doc__[] =
"documentation"
;

static PyObject *
PP_getNameArg(
  PP_ExClass1 *self,
  PyObject *SHROUD_UNUSED(args),
  PyObject *SHROUD_UNUSED(kwds))
{
// splicer begin namespace.example::nested.class.ExClass1.method.get_name_arg
    PyObject * SHTPy_rv = nullptr;

    const std::string & SHCXX_rv = self->obj->getNameArg();

    // post_call
    SHTPy_rv = PyString_FromStringAndSize(SHCXX_rv.data(),
        SHCXX_rv.size());

    return (PyObject *) SHTPy_rv;
// splicer end namespace.example::nested.class.ExClass1.method.get_name_arg
}

// ----------------------------------------
// Function:  int getValue
// Requested: py_native_scalar_result
// Match:     py_default
// ----------------------------------------
// Argument:  int value +intent(in)+value
// Requested: py_native_scalar_in
// Match:     py_default
static PyObject *
PP_getValue_from_int(
  PP_ExClass1 *self,
  PyObject *args,
  PyObject *kwds)
{
// splicer begin namespace.example::nested.class.ExClass1.method.get_value_from_int
    int value;
    const char *SHT_kwlist[] = {
        "value",
        nullptr };
    PyObject * SHTPy_rv = nullptr;

    if (!PyArg_ParseTupleAndKeywords(args, kwds, "i:getValue",
        const_cast<char **>(SHT_kwlist), &value))
        return nullptr;

    int SHCXX_rv = self->obj->getValue(value);

    // post_call
    SHTPy_rv = PyInt_FromLong(SHCXX_rv);

    return (PyObject *) SHTPy_rv;
// splicer end namespace.example::nested.class.ExClass1.method.get_value_from_int
}

// ----------------------------------------
// Function:  long getValue
// Requested: py_native_scalar_result
// Match:     py_default
// ----------------------------------------
// Argument:  long value +intent(in)+value
// Requested: py_native_scalar_in
// Match:     py_default
static PyObject *
PP_getValue_1(
  PP_ExClass1 *self,
  PyObject *args,
  PyObject *kwds)
{
// splicer begin namespace.example::nested.class.ExClass1.method.get_value_1
    long value;
    const char *SHT_kwlist[] = {
        "value",
        nullptr };
    PyObject * SHTPy_rv = nullptr;

    if (!PyArg_ParseTupleAndKeywords(args, kwds, "l:getValue",
        const_cast<char **>(SHT_kwlist), &value))
        return nullptr;

    long SHCXX_rv = self->obj->getValue(value);

    // post_call
    SHTPy_rv = PyInt_FromLong(SHCXX_rv);

    return (PyObject *) SHTPy_rv;
// splicer end namespace.example::nested.class.ExClass1.method.get_value_1
}

// ----------------------------------------
// Function:  bool hasAddr
// Requested: py_bool_scalar_result
// Match:     py_bool_result
// ----------------------------------------
// Argument:  bool in +intent(in)+value
// Requested: py_bool_scalar_in
// Match:     py_bool_in
static char PP_hasAddr__doc__[] =
"documentation"
;

static PyObject *
PP_hasAddr(
  PP_ExClass1 *self,
  PyObject *args,
  PyObject *kwds)
{
// splicer begin namespace.example::nested.class.ExClass1.method.has_addr
    bool in;
    PyObject * SHPy_in;
    const char *SHT_kwlist[] = {
        "in",
        nullptr };
    PyObject * SHTPy_rv = nullptr;

    if (!PyArg_ParseTupleAndKeywords(args, kwds, "O!:hasAddr",
        const_cast<char **>(SHT_kwlist), &PyBool_Type, &SHPy_in))
        return nullptr;

    // pre_call
    in = PyObject_IsTrue(SHPy_in);

    bool SHCXX_rv = self->obj->hasAddr(in);

    // post_call
    SHTPy_rv = PyBool_FromLong(SHCXX_rv);
    if (SHTPy_rv == nullptr) goto fail;

    return (PyObject *) SHTPy_rv;

fail:
    Py_XDECREF(SHTPy_rv);
    return nullptr;
// splicer end namespace.example::nested.class.ExClass1.method.has_addr
}

// ----------------------------------------
// Function:  void SplicerSpecial
// Exact:     py_default
static char PP_SplicerSpecial__doc__[] =
"documentation"
;

static PyObject *
PP_SplicerSpecial(
  PP_ExClass1 *self,
  PyObject *SHROUD_UNUSED(args),
  PyObject *SHROUD_UNUSED(kwds))
{
// splicer begin namespace.example::nested.class.ExClass1.method.splicer_special
    self->obj->SplicerSpecial();
    Py_RETURN_NONE;
// splicer end namespace.example::nested.class.ExClass1.method.splicer_special
}

static int
PP_ExClass1_tp_init(
  PP_ExClass1 *self,
  PyObject *args,
  PyObject *kwds)
{
// splicer begin namespace.example::nested.class.ExClass1.method.ctor
    Py_ssize_t SHT_nargs = 0;
    if (args != nullptr) SHT_nargs += PyTuple_Size(args);
    if (kwds != nullptr) SHT_nargs += PyDict_Size(args);
    int rv;
    if (SHT_nargs == 0) {
        rv = PP_ExClass1_tp_init_0(self, args, kwds);
        if (!PyErr_Occurred()) {
            return rv;
        } else if (! PyErr_ExceptionMatches(PyExc_TypeError)) {
            return rv;
        }
        PyErr_Clear();
    }
    if (SHT_nargs == 1) {
        rv = PP_ExClass1_tp_init_1(self, args, kwds);
        if (!PyErr_Occurred()) {
            return rv;
        } else if (! PyErr_ExceptionMatches(PyExc_TypeError)) {
            return rv;
        }
        PyErr_Clear();
    }
    PyErr_SetString(PyExc_TypeError, "wrong arguments multi-dispatch");
    return -1;
// splicer end namespace.example::nested.class.ExClass1.method.ctor
}

static char PP_getValue__doc__[] =
"documentation"
;

static PyObject *
PP_getValue(
  PP_ExClass1 *self,
  PyObject *args,
  PyObject *kwds)
{
// splicer begin namespace.example::nested.class.ExClass1.method.get_value
    Py_ssize_t SHT_nargs = 0;
    if (args != nullptr) SHT_nargs += PyTuple_Size(args);
    if (kwds != nullptr) SHT_nargs += PyDict_Size(args);
    PyObject *rvobj;
    if (SHT_nargs == 1) {
        rvobj = PP_getValue_from_int(self, args, kwds);
        if (!PyErr_Occurred()) {
            return rvobj;
        } else if (! PyErr_ExceptionMatches(PyExc_TypeError)) {
            return rvobj;
        }
        PyErr_Clear();
    }
    if (SHT_nargs == 1) {
        rvobj = PP_getValue_1(self, args, kwds);
        if (!PyErr_Occurred()) {
            return rvobj;
        } else if (! PyErr_ExceptionMatches(PyExc_TypeError)) {
            return rvobj;
        }
        PyErr_Clear();
    }
    PyErr_SetString(PyExc_TypeError, "wrong arguments multi-dispatch");
    return nullptr;
// splicer end namespace.example::nested.class.ExClass1.method.get_value
}
// splicer begin namespace.example::nested.class.ExClass1.impl.after_methods
// splicer end namespace.example::nested.class.ExClass1.impl.after_methods
static PyMethodDef PP_ExClass1_methods[] = {
    {"incrementCount", (PyCFunction)PP_incrementCount,
        METH_VARARGS|METH_KEYWORDS, PP_incrementCount__doc__},
    {"getNameErrorCheck", (PyCFunction)PP_getNameErrorCheck,
        METH_NOARGS, PP_getNameErrorCheck__doc__},
    {"getNameArg", (PyCFunction)PP_getNameArg, METH_NOARGS,
        PP_getNameArg__doc__},
    {"hasAddr", (PyCFunction)PP_hasAddr, METH_VARARGS|METH_KEYWORDS,
        PP_hasAddr__doc__},
    {"SplicerSpecial", (PyCFunction)PP_SplicerSpecial, METH_NOARGS,
        PP_SplicerSpecial__doc__},
    {"getValue", (PyCFunction)PP_getValue, METH_VARARGS|METH_KEYWORDS,
        PP_getValue__doc__},
    // splicer begin namespace.example::nested.class.ExClass1.PyMethodDef
    // splicer end namespace.example::nested.class.ExClass1.PyMethodDef
    {nullptr,   (PyCFunction)nullptr, 0, nullptr}            /* sentinel */
};

static char ExClass1__doc__[] =
"virtual class"
;

/* static */
PyTypeObject PP_ExClass1_Type = {
    PyVarObject_HEAD_INIT(nullptr, 0)
    "userlibrary.example.nested.ExClass1",                       /* tp_name */
    sizeof(PP_ExClass1),         /* tp_basicsize */
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
    (reprfunc)PP_ExClass1_tp_repr,                    /* tp_repr */
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
    ExClass1__doc__,         /* tp_doc */
    /* Assigned meaning in release 2.0 */
    /* call function for all accessible objects */
    (traverseproc)nullptr,                /* tp_traverse */
    /* delete references to contained objects */
    (inquiry)nullptr,                     /* tp_clear */
    /* Assigned meaning in release 2.1 */
    /* rich comparisons */
    (richcmpfunc)PP_ExClass1_tp_richcompare,                 /* tp_richcompare */
    /* weak reference enabler */
    0,                              /* tp_weaklistoffset */
    /* Added in release 2.2 */
    /* Iterators */
    (getiterfunc)nullptr,                 /* tp_iter */
    (iternextfunc)nullptr,                /* tp_iternext */
    /* Attribute descriptor and subclassing stuff */
    PP_ExClass1_methods,                             /* tp_methods */
    nullptr,                              /* tp_members */
    nullptr,                             /* tp_getset */
    nullptr,                              /* tp_base */
    nullptr,                              /* tp_dict */
    (descrgetfunc)nullptr,                /* tp_descr_get */
    (descrsetfunc)nullptr,                /* tp_descr_set */
    0,                              /* tp_dictoffset */
    (initproc)PP_ExClass1_tp_init,                   /* tp_init */
    (allocfunc)nullptr,                  /* tp_alloc */
    (newfunc)nullptr,                    /* tp_new */
    (freefunc)nullptr,                   /* tp_free */
    (inquiry)nullptr,                     /* tp_is_gc */
    nullptr,                              /* tp_bases */
    nullptr,                              /* tp_mro */
    nullptr,                              /* tp_cache */
    nullptr,                              /* tp_subclasses */
    nullptr,                              /* tp_weaklist */
    (destructor)PP_ExClass1_tp_del,                 /* tp_del */
    0,                              /* tp_version_tag */
#if PY_MAJOR_VERSION >= 3
    (destructor)nullptr,                  /* tp_finalize */
#endif
};
