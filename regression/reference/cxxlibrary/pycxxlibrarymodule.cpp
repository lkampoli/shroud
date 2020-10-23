// pycxxlibrarymodule.cpp
// This file is generated by Shroud nowrite-version. Do not edit.
// Copyright (c) 2017-2020, Lawrence Livermore National Security, LLC and
// other Shroud Project Developers.
// See the top-level COPYRIGHT file for details.
//
// SPDX-License-Identifier: (BSD-3-Clause)
//
#include "pycxxlibrarymodule.hpp"
#define PY_ARRAY_UNIQUE_SYMBOL SHROUD_CXXLIBRARY_ARRAY_API
#define NPY_NO_DEPRECATED_API NPY_1_7_API_VERSION
#include "numpy/arrayobject.h"

// splicer begin include
// splicer end include

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

// splicer begin C_definition
// splicer end C_definition
PyObject *PY_error_obj;
PyObject *PY_init_cxxlibrary_structns(void);
// splicer begin additional_functions
// splicer end additional_functions

// ----------------------------------------
// Function:  int passStructByReferenceCls
// Requested: py_native_scalar_result
// Match:     py_default
// ----------------------------------------
// Argument:  Cstruct1_cls & arg +intent(inout)
// Exact:     py_struct_&_inout_class
static char PY_passStructByReferenceCls__doc__[] =
"documentation"
;

static PyObject *
PY_passStructByReferenceCls(
  PyObject *SHROUD_UNUSED(self),
  PyObject *args,
  PyObject *kwds)
{
// splicer begin function.pass_struct_by_reference_cls
    PY_Cstruct1_cls * SHPy_arg;
    const char *SHT_kwlist[] = {
        "arg",
        nullptr };
    PyObject *SHTPy_rv = nullptr;  // return value object

    if (!PyArg_ParseTupleAndKeywords(args, kwds,
        "O!:passStructByReferenceCls", const_cast<char **>(SHT_kwlist), 
        &PY_Cstruct1_cls_Type, &SHPy_arg))
        return nullptr;

    // post_declare
    Cstruct1_cls * arg = SHPy_arg ? SHPy_arg->obj : nullptr;

    int SHCXX_rv = passStructByReferenceCls(*arg);

    // post_call
    SHTPy_rv = Py_BuildValue("iO", SHCXX_rv, SHPy_arg);

    return SHTPy_rv;
// splicer end function.pass_struct_by_reference_cls
}

// ----------------------------------------
// Function:  int passStructByReferenceInCls
// Requested: py_native_scalar_result
// Match:     py_default
// ----------------------------------------
// Argument:  const Cstruct1_cls & arg +intent(in)
// Exact:     py_struct_&_in_class
static char PY_passStructByReferenceInCls__doc__[] =
"documentation"
;

/**
 * const defaults to intent(in)
 */
static PyObject *
PY_passStructByReferenceInCls(
  PyObject *SHROUD_UNUSED(self),
  PyObject *args,
  PyObject *kwds)
{
// splicer begin function.pass_struct_by_reference_in_cls
    PY_Cstruct1_cls * SHPy_arg;
    const char *SHT_kwlist[] = {
        "arg",
        nullptr };
    PyObject * SHTPy_rv = nullptr;

    if (!PyArg_ParseTupleAndKeywords(args, kwds,
        "O!:passStructByReferenceInCls",
        const_cast<char **>(SHT_kwlist), &PY_Cstruct1_cls_Type,
        &SHPy_arg))
        return nullptr;

    // post_declare
    const Cstruct1_cls * arg = SHPy_arg ? SHPy_arg->obj : nullptr;

    int SHCXX_rv = passStructByReferenceInCls(*arg);

    // post_call
    SHTPy_rv = PyInt_FromLong(SHCXX_rv);

    return (PyObject *) SHTPy_rv;
// splicer end function.pass_struct_by_reference_in_cls
}

// ----------------------------------------
// Function:  void passStructByReferenceInoutCls
// Exact:     py_default
// ----------------------------------------
// Argument:  Cstruct1_cls & arg +intent(inout)
// Exact:     py_struct_&_inout_class
static char PY_passStructByReferenceInoutCls__doc__[] =
"documentation"
;

static PyObject *
PY_passStructByReferenceInoutCls(
  PyObject *SHROUD_UNUSED(self),
  PyObject *args,
  PyObject *kwds)
{
// splicer begin function.pass_struct_by_reference_inout_cls
    PY_Cstruct1_cls * SHPy_arg;
    const char *SHT_kwlist[] = {
        "arg",
        nullptr };

    if (!PyArg_ParseTupleAndKeywords(args, kwds,
        "O!:passStructByReferenceInoutCls",
        const_cast<char **>(SHT_kwlist), &PY_Cstruct1_cls_Type,
        &SHPy_arg))
        return nullptr;

    // post_declare
    Cstruct1_cls * arg = SHPy_arg ? SHPy_arg->obj : nullptr;

    passStructByReferenceInoutCls(*arg);
    return (PyObject *) SHPy_arg;
// splicer end function.pass_struct_by_reference_inout_cls
}

// ----------------------------------------
// Function:  void passStructByReferenceOutCls
// Exact:     py_default
// ----------------------------------------
// Argument:  Cstruct1_cls & arg +intent(out)
// Exact:     py_struct_&_out_class
static char PY_passStructByReferenceOutCls__doc__[] =
"documentation"
;

static PyObject *
PY_passStructByReferenceOutCls(
  PyObject *SHROUD_UNUSED(self),
  PyObject *SHROUD_UNUSED(args),
  PyObject *SHROUD_UNUSED(kwds))
{
// splicer begin function.pass_struct_by_reference_out_cls
    Cstruct1_cls *arg = nullptr;
    PyObject *SHPy_arg = nullptr;

    // pre_call
    arg = new Cstruct1_cls;

    passStructByReferenceOutCls(*arg);

    // post_call
    SHPy_arg = PP_Cstruct1_cls_to_Object_idtor(arg, 0);
    if (SHPy_arg == nullptr) goto fail;

    return (PyObject *) SHPy_arg;

fail:
    Py_XDECREF(SHPy_arg);
    return nullptr;
// splicer end function.pass_struct_by_reference_out_cls
}

// ----------------------------------------
// Function:  bool defaultPtrIsNULL
// Requested: py_bool_scalar_result
// Match:     py_bool_result
// ----------------------------------------
// Argument:  double * data=nullptr +intent(in)+rank(1)
// Exact:     py_native_*_in_pointer_numpy
static char PY_defaultPtrIsNULL_1__doc__[] =
"documentation"
;

static PyObject *
PY_defaultPtrIsNULL_1(
  PyObject *SHROUD_UNUSED(self),
  PyObject *args,
  PyObject *kwds)
{
// splicer begin function.default_ptr_is_null
    Py_ssize_t SH_nargs = 0;
    double * data;
    PyObject * SHTPy_data;
    PyArrayObject * SHPy_data = nullptr;
    const char *SHT_kwlist[] = {
        "data",
        nullptr };
    bool SHCXX_rv;
    PyObject * SHTPy_rv = nullptr;

    if (args != nullptr) SH_nargs += PyTuple_Size(args);
    if (kwds != nullptr) SH_nargs += PyDict_Size(args);
    if (!PyArg_ParseTupleAndKeywords(args, kwds, "|O:defaultPtrIsNULL",
        const_cast<char **>(SHT_kwlist), &SHTPy_data))
        return nullptr;
    switch (SH_nargs) {
    case 0:
        SHCXX_rv = defaultPtrIsNULL();
        break;
    case 1:
        {
            // post_parse
            SHPy_data = reinterpret_cast<PyArrayObject *>
                (PyArray_FROM_OTF(SHTPy_data, NPY_DOUBLE,
                NPY_ARRAY_IN_ARRAY));
            if (SHPy_data == nullptr) {
                PyErr_SetString(PyExc_ValueError,
                    "data must be a 1-D array of double");
                goto fail;
            }

            // pre_call
            data = static_cast<double *>(PyArray_DATA(SHPy_data));

            SHCXX_rv = defaultPtrIsNULL(data);
            break;
        }
    default:
        PyErr_SetString(PyExc_ValueError, "Wrong number of arguments");
        return nullptr;
    }

    // post_call
    SHTPy_rv = PyBool_FromLong(SHCXX_rv);
    if (SHTPy_rv == nullptr) goto fail;

    // cleanup
    Py_XDECREF(SHPy_data);

    return (PyObject *) SHTPy_rv;

fail:
    Py_XDECREF(SHPy_data);
    Py_XDECREF(SHTPy_rv);
    return nullptr;
// splicer end function.default_ptr_is_null
}

// ----------------------------------------
// Function:  void defaultArgsInOut
// Exact:     py_default
// ----------------------------------------
// Argument:  int in1 +intent(in)+value
// Requested: py_native_scalar_in
// Match:     py_default
// ----------------------------------------
// Argument:  int * out1 +intent(out)
// Exact:     py_native_*_out
// ----------------------------------------
// Argument:  int * out2 +intent(out)
// Exact:     py_native_*_out
// ----------------------------------------
// Argument:  bool flag=false +intent(in)+value
// Requested: py_bool_scalar_in
// Match:     py_bool_in
static char PY_defaultArgsInOut_1__doc__[] =
"documentation"
;

static PyObject *
PY_defaultArgsInOut_1(
  PyObject *SHROUD_UNUSED(self),
  PyObject *args,
  PyObject *kwds)
{
// splicer begin function.default_args_in_out
    Py_ssize_t SH_nargs = 0;
    int in1;
    int out1;
    int out2;
    bool flag;
    PyObject * SHPy_flag;
    const char *SHT_kwlist[] = {
        "in1",
        "flag",
        nullptr };
    PyObject *SHTPy_rv = nullptr;  // return value object

    if (args != nullptr) SH_nargs += PyTuple_Size(args);
    if (kwds != nullptr) SH_nargs += PyDict_Size(args);
    if (!PyArg_ParseTupleAndKeywords(args, kwds,
        "i|O!:defaultArgsInOut", const_cast<char **>(SHT_kwlist), &in1,
        &PyBool_Type, &SHPy_flag))
        return nullptr;
    switch (SH_nargs) {
    case 1:
        defaultArgsInOut(in1, &out1, &out2);
        break;
    case 2:
        {
            // pre_call
            flag = PyObject_IsTrue(SHPy_flag);

            defaultArgsInOut(in1, &out1, &out2, flag);
            break;
        }
    default:
        PyErr_SetString(PyExc_ValueError, "Wrong number of arguments");
        return nullptr;
    }

    // post_call
    SHTPy_rv = Py_BuildValue("ii", out1, out2);

    return SHTPy_rv;
// splicer end function.default_args_in_out
}
static PyMethodDef PY_methods[] = {
{"passStructByReferenceCls", (PyCFunction)PY_passStructByReferenceCls,
    METH_VARARGS|METH_KEYWORDS, PY_passStructByReferenceCls__doc__},
{"passStructByReferenceInCls",
    (PyCFunction)PY_passStructByReferenceInCls,
    METH_VARARGS|METH_KEYWORDS, PY_passStructByReferenceInCls__doc__},
{"passStructByReferenceInoutCls",
    (PyCFunction)PY_passStructByReferenceInoutCls,
    METH_VARARGS|METH_KEYWORDS,
    PY_passStructByReferenceInoutCls__doc__},
{"passStructByReferenceOutCls",
    (PyCFunction)PY_passStructByReferenceOutCls, METH_NOARGS,
    PY_passStructByReferenceOutCls__doc__},
{"defaultPtrIsNULL", (PyCFunction)PY_defaultPtrIsNULL_1,
    METH_VARARGS|METH_KEYWORDS, PY_defaultPtrIsNULL_1__doc__},
{"defaultArgsInOut", (PyCFunction)PY_defaultArgsInOut_1,
    METH_VARARGS|METH_KEYWORDS, PY_defaultArgsInOut_1__doc__},
{nullptr,   (PyCFunction)nullptr, 0, nullptr}            /* sentinel */
};

/*
 * initcxxlibrary - Initialization function for the module
 * *must* be called initcxxlibrary
 */
static char PY__doc__[] =
"library documentation"
;

struct module_state {
    PyObject *error;
};

#if PY_MAJOR_VERSION >= 3
#define GETSTATE(m) ((struct module_state*)PyModule_GetState(m))
#else
#define GETSTATE(m) (&_state)
static struct module_state _state;
#endif

#if PY_MAJOR_VERSION >= 3
static int cxxlibrary_traverse(PyObject *m, visitproc visit, void *arg) {
    Py_VISIT(GETSTATE(m)->error);
    return 0;
}

static int cxxlibrary_clear(PyObject *m) {
    Py_CLEAR(GETSTATE(m)->error);
    return 0;
}

static struct PyModuleDef moduledef = {
    PyModuleDef_HEAD_INIT,
    "cxxlibrary", /* m_name */
    PY__doc__, /* m_doc */
    sizeof(struct module_state), /* m_size */
    PY_methods, /* m_methods */
    nullptr, /* m_reload */
    cxxlibrary_traverse, /* m_traverse */
    cxxlibrary_clear, /* m_clear */
    NULL  /* m_free */
};

#define RETVAL m
#define INITERROR return nullptr
#else
#define RETVAL
#define INITERROR return
#endif

extern "C" PyMODINIT_FUNC
#if PY_MAJOR_VERSION >= 3
PyInit_cxxlibrary(void)
#else
initcxxlibrary(void)
#endif
{
    PyObject *m = nullptr;
    const char * error_name = "cxxlibrary.Error";

    // splicer begin C_init_locals
    // splicer end C_init_locals


    /* Create the module and add the functions */
#if PY_MAJOR_VERSION >= 3
    m = PyModule_Create(&moduledef);
#else
    m = Py_InitModule4("cxxlibrary", PY_methods,
        PY__doc__,
        (PyObject*)nullptr,PYTHON_API_VERSION);
#endif
    if (m == nullptr)
        return RETVAL;
    struct module_state *st = GETSTATE(m);

    import_array();

    {
        PyObject *submodule = PY_init_cxxlibrary_structns();
        if (submodule == nullptr)
            INITERROR;
        Py_INCREF(submodule);
        PyModule_AddObject(m, (char *) "structns", submodule);
    }

    // Cstruct1_cls
    PY_Cstruct1_cls_Type.tp_new   = PyType_GenericNew;
    PY_Cstruct1_cls_Type.tp_alloc = PyType_GenericAlloc;
    if (PyType_Ready(&PY_Cstruct1_cls_Type) < 0)
        return RETVAL;
    Py_INCREF(&PY_Cstruct1_cls_Type);
    PyModule_AddObject(m, "Cstruct1_cls", (PyObject *)&PY_Cstruct1_cls_Type);

    PY_error_obj = PyErr_NewException((char *) error_name, nullptr, nullptr);
    if (PY_error_obj == nullptr)
        return RETVAL;
    st->error = PY_error_obj;
    PyModule_AddObject(m, "Error", st->error);

    // splicer begin C_init_body
    // splicer end C_init_body

    /* Check for errors */
    if (PyErr_Occurred())
        Py_FatalError("can't initialize module cxxlibrary");
    return RETVAL;
}

