// pyTutorialmodule.cpp
// This is generated code, do not edit
// Copyright (c) 2017-2020, Lawrence Livermore National Security, LLC and
// other Shroud Project Developers.
// See the top-level COPYRIGHT file for details.
//
// SPDX-License-Identifier: (BSD-3-Clause)
//
#include "pyTutorialmodule.hpp"

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
#define PyString_FromString PyUnicode_FromString
#define PyString_FromStringAndSize PyUnicode_FromStringAndSize
#endif

// splicer begin C_definition
// splicer end C_definition
PyObject *PY_error_obj;
// splicer begin additional_functions
// splicer end additional_functions

static char PY_NoReturnNoArguments__doc__[] =
"documentation"
;

static PyObject *
PY_NoReturnNoArguments(
  PyObject *SHROUD_UNUSED(self),
  PyObject *SHROUD_UNUSED(args),
  PyObject *SHROUD_UNUSED(kwds))
{
// void NoReturnNoArguments()
// splicer begin function.no_return_no_arguments
    tutorial::NoReturnNoArguments();
    Py_RETURN_NONE;
// splicer end function.no_return_no_arguments
}

static char PY_PassByValue__doc__[] =
"documentation"
;

static PyObject *
PY_PassByValue(
  PyObject *SHROUD_UNUSED(self),
  PyObject *args,
  PyObject *kwds)
{
// double PassByValue(double arg1 +intent(in)+value, int arg2 +intent(in)+value)
// splicer begin function.pass_by_value
    double arg1;
    int arg2;
    const char *SHT_kwlist[] = {
        "arg1",
        "arg2",
        NULL };
    PyObject * SHTPy_rv = NULL;

    if (!PyArg_ParseTupleAndKeywords(args, kwds, "di:PassByValue",
        const_cast<char **>(SHT_kwlist), &arg1, &arg2))
        return NULL;

    double SHCXX_rv = tutorial::PassByValue(arg1, arg2);

    // post_call
    SHTPy_rv = PyFloat_FromDouble(SHCXX_rv);

    return (PyObject *) SHTPy_rv;
// splicer end function.pass_by_value
}

static char PY_ConcatenateStrings__doc__[] =
"documentation"
;

/**
 * Note that since a reference is returned, no intermediate string
 * is allocated.  It is assumed +owner(library).
 */
static PyObject *
PY_ConcatenateStrings(
  PyObject *SHROUD_UNUSED(self),
  PyObject *args,
  PyObject *kwds)
{
// const std::string ConcatenateStrings(const std::string & arg1 +intent(in), const std::string & arg2 +intent(in)) +deref(allocatable)
// splicer begin function.concatenate_strings
    const char * arg1;
    const char * arg2;
    const char *SHT_kwlist[] = {
        "arg1",
        "arg2",
        NULL };
    PyObject * SHTPy_rv = NULL;

    if (!PyArg_ParseTupleAndKeywords(args, kwds,
        "ss:ConcatenateStrings", const_cast<char **>(SHT_kwlist), &arg1,
        &arg2))
        return NULL;

    // post_parse
    const std::string SH_arg1(arg1);
    const std::string SH_arg2(arg2);

    const std::string SHCXX_rv = tutorial::ConcatenateStrings(SH_arg1,
        SH_arg2);

    // post_call
    SHTPy_rv = PyString_FromStringAndSize(SHCXX_rv.data(),
        SHCXX_rv.size());

    return (PyObject *) SHTPy_rv;
// splicer end function.concatenate_strings
}

static char PY_UseDefaultArguments_arg1_arg2__doc__[] =
"documentation"
;

static PyObject *
PY_UseDefaultArguments_arg1_arg2(
  PyObject *SHROUD_UNUSED(self),
  PyObject *args,
  PyObject *kwds)
{
// double UseDefaultArguments(double arg1=3.1415 +intent(in)+value, bool arg2=true +intent(in)+value)
// splicer begin function.use_default_arguments
    Py_ssize_t SH_nargs = 0;
    double arg1;
    PyObject * SHPy_arg2;
    const char *SHT_kwlist[] = {
        "arg1",
        "arg2",
        NULL };
    double SHCXX_rv;
    PyObject * SHTPy_rv = NULL;

    if (args != NULL) SH_nargs += PyTuple_Size(args);
    if (kwds != NULL) SH_nargs += PyDict_Size(args);
    if (!PyArg_ParseTupleAndKeywords(args, kwds,
        "|dO!:UseDefaultArguments", const_cast<char **>(SHT_kwlist), 
        &arg1, &PyBool_Type, &SHPy_arg2))
        return NULL;
    switch (SH_nargs) {
    case 0:
        SHCXX_rv = tutorial::UseDefaultArguments();
        break;
    case 1:
        SHCXX_rv = tutorial::UseDefaultArguments(arg1);
        break;
    case 2:
        {
            // pre_call
            bool arg2 = PyObject_IsTrue(SHPy_arg2);

            SHCXX_rv = tutorial::UseDefaultArguments(arg1, arg2);
            break;
        }
    default:
        PyErr_SetString(PyExc_ValueError, "Wrong number of arguments");
        return NULL;
    }

    // post_call
    SHTPy_rv = PyFloat_FromDouble(SHCXX_rv);

    return (PyObject *) SHTPy_rv;
// splicer end function.use_default_arguments
}

static PyObject *
PY_OverloadedFunction_from_name(
  PyObject *SHROUD_UNUSED(self),
  PyObject *args,
  PyObject *kwds)
{
// void OverloadedFunction(const std::string & name +intent(in))
// splicer begin function.overloaded_function_from_name
    const char * name;
    const char *SHT_kwlist[] = {
        "name",
        NULL };

    if (!PyArg_ParseTupleAndKeywords(args, kwds, "s:OverloadedFunction",
        const_cast<char **>(SHT_kwlist), &name))
        return NULL;

    // post_parse
    const std::string SH_name(name);

    tutorial::OverloadedFunction(SH_name);
    Py_RETURN_NONE;
// splicer end function.overloaded_function_from_name
}

static PyObject *
PY_OverloadedFunction_from_index(
  PyObject *SHROUD_UNUSED(self),
  PyObject *args,
  PyObject *kwds)
{
// void OverloadedFunction(int indx +intent(in)+value)
// splicer begin function.overloaded_function_from_index
    int indx;
    const char *SHT_kwlist[] = {
        "indx",
        NULL };

    if (!PyArg_ParseTupleAndKeywords(args, kwds, "i:OverloadedFunction",
        const_cast<char **>(SHT_kwlist), &indx))
        return NULL;

    tutorial::OverloadedFunction(indx);
    Py_RETURN_NONE;
// splicer end function.overloaded_function_from_index
}

static PyObject *
PY_TemplateArgument_int(
  PyObject *SHROUD_UNUSED(self),
  PyObject *args,
  PyObject *kwds)
{
// void TemplateArgument(int arg +intent(in)+value)
// splicer begin function.template_argument_int
    int arg;
    const char *SHT_kwlist[] = {
        "arg",
        NULL };

    if (!PyArg_ParseTupleAndKeywords(args, kwds, "i:TemplateArgument",
        const_cast<char **>(SHT_kwlist), &arg))
        return NULL;

    tutorial::TemplateArgument<int>(arg);
    Py_RETURN_NONE;
// splicer end function.template_argument_int
}

static PyObject *
PY_TemplateArgument_double(
  PyObject *SHROUD_UNUSED(self),
  PyObject *args,
  PyObject *kwds)
{
// void TemplateArgument(double arg +intent(in)+value)
// splicer begin function.template_argument_double
    double arg;
    const char *SHT_kwlist[] = {
        "arg",
        NULL };

    if (!PyArg_ParseTupleAndKeywords(args, kwds, "d:TemplateArgument",
        const_cast<char **>(SHT_kwlist), &arg))
        return NULL;

    tutorial::TemplateArgument<double>(arg);
    Py_RETURN_NONE;
// splicer end function.template_argument_double
}

static PyObject *
PY_FortranGenericOverloaded_0(
  PyObject *SHROUD_UNUSED(self),
  PyObject *SHROUD_UNUSED(args),
  PyObject *SHROUD_UNUSED(kwds))
{
// void FortranGenericOverloaded()
// splicer begin function.fortran_generic_overloaded_0
    tutorial::FortranGenericOverloaded();
    Py_RETURN_NONE;
// splicer end function.fortran_generic_overloaded_0
}

static PyObject *
PY_FortranGenericOverloaded_1(
  PyObject *SHROUD_UNUSED(self),
  PyObject *args,
  PyObject *kwds)
{
// void FortranGenericOverloaded(const std::string & name +intent(in), double arg2 +intent(in)+value)
// splicer begin function.fortran_generic_overloaded_1
    const char * name;
    double arg2;
    const char *SHT_kwlist[] = {
        "name",
        "arg2",
        NULL };

    if (!PyArg_ParseTupleAndKeywords(args, kwds,
        "sd:FortranGenericOverloaded", const_cast<char **>(SHT_kwlist), 
        &name, &arg2))
        return NULL;

    // post_parse
    const std::string SH_name(name);

    tutorial::FortranGenericOverloaded(SH_name, arg2);
    Py_RETURN_NONE;
// splicer end function.fortran_generic_overloaded_1
}

static PyObject *
PY_UseDefaultOverload_num_offset_stride(
  PyObject *SHROUD_UNUSED(self),
  PyObject *args,
  PyObject *kwds)
{
// int UseDefaultOverload(int num +intent(in)+value, int offset=0 +intent(in)+value, int stride=1 +intent(in)+value)
// splicer begin function.use_default_overload_num_offset_stride
    Py_ssize_t SH_nargs = 0;
    int num;
    int offset;
    int stride;
    const char *SHT_kwlist[] = {
        "num",
        "offset",
        "stride",
        NULL };
    int SHCXX_rv;
    PyObject * SHTPy_rv = NULL;

    if (args != NULL) SH_nargs += PyTuple_Size(args);
    if (kwds != NULL) SH_nargs += PyDict_Size(args);
    if (!PyArg_ParseTupleAndKeywords(args, kwds,
        "i|ii:UseDefaultOverload", const_cast<char **>(SHT_kwlist), 
        &num, &offset, &stride))
        return NULL;
    switch (SH_nargs) {
    case 1:
        SHCXX_rv = tutorial::UseDefaultOverload(num);
        break;
    case 2:
        SHCXX_rv = tutorial::UseDefaultOverload(num, offset);
        break;
    case 3:
        SHCXX_rv = tutorial::UseDefaultOverload(num, offset, stride);
        break;
    default:
        PyErr_SetString(PyExc_ValueError, "Wrong number of arguments");
        return NULL;
    }

    // post_call
    SHTPy_rv = PyInt_FromLong(SHCXX_rv);

    return (PyObject *) SHTPy_rv;
// splicer end function.use_default_overload_num_offset_stride
}

static PyObject *
PY_UseDefaultOverload_5(
  PyObject *SHROUD_UNUSED(self),
  PyObject *args,
  PyObject *kwds)
{
// int UseDefaultOverload(double type +intent(in)+value, int num +intent(in)+value, int offset=0 +intent(in)+value, int stride=1 +intent(in)+value)
// splicer begin function.use_default_overload_5
    Py_ssize_t SH_nargs = 0;
    double type;
    int num;
    int offset;
    int stride;
    const char *SHT_kwlist[] = {
        "type",
        "num",
        "offset",
        "stride",
        NULL };
    int SHCXX_rv;
    PyObject * SHTPy_rv = NULL;

    if (args != NULL) SH_nargs += PyTuple_Size(args);
    if (kwds != NULL) SH_nargs += PyDict_Size(args);
    if (!PyArg_ParseTupleAndKeywords(args, kwds,
        "di|ii:UseDefaultOverload", const_cast<char **>(SHT_kwlist), 
        &type, &num, &offset, &stride))
        return NULL;
    switch (SH_nargs) {
    case 2:
        SHCXX_rv = tutorial::UseDefaultOverload(type, num);
        break;
    case 3:
        SHCXX_rv = tutorial::UseDefaultOverload(type, num, offset);
        break;
    case 4:
        SHCXX_rv = tutorial::UseDefaultOverload(type, num, offset,
            stride);
        break;
    default:
        PyErr_SetString(PyExc_ValueError, "Wrong number of arguments");
        return NULL;
    }

    // post_call
    SHTPy_rv = PyInt_FromLong(SHCXX_rv);

    return (PyObject *) SHTPy_rv;
// splicer end function.use_default_overload_5
}

static char PY_typefunc__doc__[] =
"documentation"
;

static PyObject *
PY_typefunc(
  PyObject *SHROUD_UNUSED(self),
  PyObject *args,
  PyObject *kwds)
{
// TypeID typefunc(TypeID arg +intent(in)+value)
// splicer begin function.typefunc
    int arg;
    const char *SHT_kwlist[] = {
        "arg",
        NULL };
    PyObject * SHTPy_rv = NULL;

    if (!PyArg_ParseTupleAndKeywords(args, kwds, "i:typefunc",
        const_cast<char **>(SHT_kwlist), &arg))
        return NULL;

    tutorial::TypeID SHCXX_rv = tutorial::typefunc(arg);

    // post_call
    SHTPy_rv = PyInt_FromLong(SHCXX_rv);

    return (PyObject *) SHTPy_rv;
// splicer end function.typefunc
}

static char PY_enumfunc__doc__[] =
"documentation"
;

static PyObject *
PY_enumfunc(
  PyObject *SHROUD_UNUSED(self),
  PyObject *args,
  PyObject *kwds)
{
// EnumTypeID enumfunc(EnumTypeID arg +intent(in)+value)
// splicer begin function.enumfunc
    int arg;
    const char *SHT_kwlist[] = {
        "arg",
        NULL };
    PyObject * SHTPy_rv = NULL;

    if (!PyArg_ParseTupleAndKeywords(args, kwds, "i:enumfunc",
        const_cast<char **>(SHT_kwlist), &arg))
        return NULL;

    // post_parse
    tutorial::EnumTypeID SH_arg =
        static_cast<tutorial::EnumTypeID>(arg);

    tutorial::EnumTypeID SHCXX_rv = tutorial::enumfunc(SH_arg);

    // post_call
    SHTPy_rv = PyInt_FromLong(SHCXX_rv);

    return (PyObject *) SHTPy_rv;
// splicer end function.enumfunc
}

static char PY_colorfunc__doc__[] =
"documentation"
;

static PyObject *
PY_colorfunc(
  PyObject *SHROUD_UNUSED(self),
  PyObject *args,
  PyObject *kwds)
{
// Color colorfunc(Color arg +intent(in)+value)
// splicer begin function.colorfunc
    int arg;
    const char *SHT_kwlist[] = {
        "arg",
        NULL };
    PyObject * SHTPy_rv = NULL;

    if (!PyArg_ParseTupleAndKeywords(args, kwds, "i:colorfunc",
        const_cast<char **>(SHT_kwlist), &arg))
        return NULL;

    // post_parse
    tutorial::Color SH_arg = static_cast<tutorial::Color>(arg);

    tutorial::Color SHCXX_rv = tutorial::colorfunc(SH_arg);

    // post_call
    SHTPy_rv = PyInt_FromLong(SHCXX_rv);

    return (PyObject *) SHTPy_rv;
// splicer end function.colorfunc
}

static char PY_getMinMax__doc__[] =
"documentation"
;

/**
 * \brief Pass in reference to scalar
 *
 */
static PyObject *
PY_getMinMax(
  PyObject *SHROUD_UNUSED(self),
  PyObject *SHROUD_UNUSED(args),
  PyObject *SHROUD_UNUSED(kwds))
{
// void getMinMax(int & min +intent(out), int & max +intent(out))
// splicer begin function.get_min_max
    PyObject *SHTPy_rv = NULL;  // return value object

    // pre_call
    int min;  // intent(out)
    int max;  // intent(out)

    tutorial::getMinMax(min, max);

    // post_call
    SHTPy_rv = Py_BuildValue("ii", min, max);

    return SHTPy_rv;
// splicer end function.get_min_max
}

static char PY_LastFunctionCalled__doc__[] =
"documentation"
;

static PyObject *
PY_LastFunctionCalled(
  PyObject *SHROUD_UNUSED(self),
  PyObject *SHROUD_UNUSED(args),
  PyObject *SHROUD_UNUSED(kwds))
{
// const std::string & LastFunctionCalled() +deref(result_as_arg)+len(30)
// splicer begin function.last_function_called
    PyObject * SHTPy_rv = NULL;

    const std::string & SHCXX_rv = tutorial::LastFunctionCalled();

    // post_call
    SHTPy_rv = PyString_FromStringAndSize(SHCXX_rv.data(),
        SHCXX_rv.size());

    return (PyObject *) SHTPy_rv;
// splicer end function.last_function_called
}

static char PY_OverloadedFunction__doc__[] =
"documentation"
;

static PyObject *
PY_OverloadedFunction(
  PyObject *self,
  PyObject *args,
  PyObject *kwds)
{
// splicer begin function.overloaded_function
    Py_ssize_t SHT_nargs = 0;
    if (args != NULL) SHT_nargs += PyTuple_Size(args);
    if (kwds != NULL) SHT_nargs += PyDict_Size(args);
    PyObject *rvobj;
    if (SHT_nargs == 1) {
        rvobj = PY_OverloadedFunction_from_name(self, args, kwds);
        if (!PyErr_Occurred()) {
            return rvobj;
        } else if (! PyErr_ExceptionMatches(PyExc_TypeError)) {
            return rvobj;
        }
        PyErr_Clear();
    }
    if (SHT_nargs == 1) {
        rvobj = PY_OverloadedFunction_from_index(self, args, kwds);
        if (!PyErr_Occurred()) {
            return rvobj;
        } else if (! PyErr_ExceptionMatches(PyExc_TypeError)) {
            return rvobj;
        }
        PyErr_Clear();
    }
    PyErr_SetString(PyExc_TypeError, "wrong arguments multi-dispatch");
    return NULL;
// splicer end function.overloaded_function
}

static char PY_TemplateArgument__doc__[] =
"documentation"
;

static PyObject *
PY_TemplateArgument(
  PyObject *self,
  PyObject *args,
  PyObject *kwds)
{
// splicer begin function.template_argument
    Py_ssize_t SHT_nargs = 0;
    if (args != NULL) SHT_nargs += PyTuple_Size(args);
    if (kwds != NULL) SHT_nargs += PyDict_Size(args);
    PyObject *rvobj;
    if (SHT_nargs == 1) {
        rvobj = PY_TemplateArgument_int(self, args, kwds);
        if (!PyErr_Occurred()) {
            return rvobj;
        } else if (! PyErr_ExceptionMatches(PyExc_TypeError)) {
            return rvobj;
        }
        PyErr_Clear();
    }
    if (SHT_nargs == 1) {
        rvobj = PY_TemplateArgument_double(self, args, kwds);
        if (!PyErr_Occurred()) {
            return rvobj;
        } else if (! PyErr_ExceptionMatches(PyExc_TypeError)) {
            return rvobj;
        }
        PyErr_Clear();
    }
    PyErr_SetString(PyExc_TypeError, "wrong arguments multi-dispatch");
    return NULL;
// splicer end function.template_argument
}

static char PY_FortranGenericOverloaded__doc__[] =
"documentation"
;

static PyObject *
PY_FortranGenericOverloaded(
  PyObject *self,
  PyObject *args,
  PyObject *kwds)
{
// splicer begin function.fortran_generic_overloaded
    Py_ssize_t SHT_nargs = 0;
    if (args != NULL) SHT_nargs += PyTuple_Size(args);
    if (kwds != NULL) SHT_nargs += PyDict_Size(args);
    PyObject *rvobj;
    if (SHT_nargs == 0) {
        rvobj = PY_FortranGenericOverloaded_0(self, args, kwds);
        if (!PyErr_Occurred()) {
            return rvobj;
        } else if (! PyErr_ExceptionMatches(PyExc_TypeError)) {
            return rvobj;
        }
        PyErr_Clear();
    }
    if (SHT_nargs == 2) {
        rvobj = PY_FortranGenericOverloaded_1(self, args, kwds);
        if (!PyErr_Occurred()) {
            return rvobj;
        } else if (! PyErr_ExceptionMatches(PyExc_TypeError)) {
            return rvobj;
        }
        PyErr_Clear();
    }
    PyErr_SetString(PyExc_TypeError, "wrong arguments multi-dispatch");
    return NULL;
// splicer end function.fortran_generic_overloaded
}

static char PY_UseDefaultOverload__doc__[] =
"documentation"
;

static PyObject *
PY_UseDefaultOverload(
  PyObject *self,
  PyObject *args,
  PyObject *kwds)
{
// splicer begin function.use_default_overload
    Py_ssize_t SHT_nargs = 0;
    if (args != NULL) SHT_nargs += PyTuple_Size(args);
    if (kwds != NULL) SHT_nargs += PyDict_Size(args);
    PyObject *rvobj;
    if (SHT_nargs >= 1 && SHT_nargs <= 3) {
        rvobj = PY_UseDefaultOverload_num_offset_stride(self, args, kwds);
        if (!PyErr_Occurred()) {
            return rvobj;
        } else if (! PyErr_ExceptionMatches(PyExc_TypeError)) {
            return rvobj;
        }
        PyErr_Clear();
    }
    if (SHT_nargs >= 2 && SHT_nargs <= 4) {
        rvobj = PY_UseDefaultOverload_5(self, args, kwds);
        if (!PyErr_Occurred()) {
            return rvobj;
        } else if (! PyErr_ExceptionMatches(PyExc_TypeError)) {
            return rvobj;
        }
        PyErr_Clear();
    }
    PyErr_SetString(PyExc_TypeError, "wrong arguments multi-dispatch");
    return NULL;
// splicer end function.use_default_overload
}
static PyMethodDef PY_methods[] = {
{"NoReturnNoArguments", (PyCFunction)PY_NoReturnNoArguments,
    METH_NOARGS, PY_NoReturnNoArguments__doc__},
{"PassByValue", (PyCFunction)PY_PassByValue, METH_VARARGS|METH_KEYWORDS,
    PY_PassByValue__doc__},
{"ConcatenateStrings", (PyCFunction)PY_ConcatenateStrings,
    METH_VARARGS|METH_KEYWORDS, PY_ConcatenateStrings__doc__},
{"UseDefaultArguments", (PyCFunction)PY_UseDefaultArguments_arg1_arg2,
    METH_VARARGS|METH_KEYWORDS,
    PY_UseDefaultArguments_arg1_arg2__doc__},
{"typefunc", (PyCFunction)PY_typefunc, METH_VARARGS|METH_KEYWORDS,
    PY_typefunc__doc__},
{"enumfunc", (PyCFunction)PY_enumfunc, METH_VARARGS|METH_KEYWORDS,
    PY_enumfunc__doc__},
{"colorfunc", (PyCFunction)PY_colorfunc, METH_VARARGS|METH_KEYWORDS,
    PY_colorfunc__doc__},
{"getMinMax", (PyCFunction)PY_getMinMax, METH_NOARGS,
    PY_getMinMax__doc__},
{"LastFunctionCalled", (PyCFunction)PY_LastFunctionCalled, METH_NOARGS,
    PY_LastFunctionCalled__doc__},
{"OverloadedFunction", (PyCFunction)PY_OverloadedFunction,
    METH_VARARGS|METH_KEYWORDS, PY_OverloadedFunction__doc__},
{"TemplateArgument", (PyCFunction)PY_TemplateArgument,
    METH_VARARGS|METH_KEYWORDS, PY_TemplateArgument__doc__},
{"FortranGenericOverloaded", (PyCFunction)PY_FortranGenericOverloaded,
    METH_VARARGS|METH_KEYWORDS, PY_FortranGenericOverloaded__doc__},
{"UseDefaultOverload", (PyCFunction)PY_UseDefaultOverload,
    METH_VARARGS|METH_KEYWORDS, PY_UseDefaultOverload__doc__},
{NULL,   (PyCFunction)NULL, 0, NULL}            /* sentinel */
};

/*
 * inittutorial - Initialization function for the module
 * *must* be called inittutorial
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
static int tutorial_traverse(PyObject *m, visitproc visit, void *arg) {
    Py_VISIT(GETSTATE(m)->error);
    return 0;
}

static int tutorial_clear(PyObject *m) {
    Py_CLEAR(GETSTATE(m)->error);
    return 0;
}

static struct PyModuleDef moduledef = {
    PyModuleDef_HEAD_INIT,
    "tutorial", /* m_name */
    PY__doc__, /* m_doc */
    sizeof(struct module_state), /* m_size */
    PY_methods, /* m_methods */
    NULL, /* m_reload */
    tutorial_traverse, /* m_traverse */
    tutorial_clear, /* m_clear */
    NULL  /* m_free */
};

#define RETVAL m
#define INITERROR return NULL
#else
#define RETVAL
#define INITERROR return
#endif

extern "C" PyMODINIT_FUNC
#if PY_MAJOR_VERSION >= 3
PyInit_tutorial(void)
#else
inittutorial(void)
#endif
{
    PyObject *m = NULL;
    const char * error_name = "tutorial.Error";

    // splicer begin C_init_locals
    // splicer end C_init_locals


    /* Create the module and add the functions */
#if PY_MAJOR_VERSION >= 3
    m = PyModule_Create(&moduledef);
#else
    m = Py_InitModule4("tutorial", PY_methods,
        PY__doc__,
        (PyObject*)NULL,PYTHON_API_VERSION);
#endif
    if (m == NULL)
        return RETVAL;
    struct module_state *st = GETSTATE(m);

    // enum tutorial::Color
    PyModule_AddIntConstant(m, "RED", tutorial::RED);
    PyModule_AddIntConstant(m, "BLUE", tutorial::BLUE);
    PyModule_AddIntConstant(m, "WHITE", tutorial::WHITE);

    PY_error_obj = PyErr_NewException((char *) error_name, NULL, NULL);
    if (PY_error_obj == NULL)
        return RETVAL;
    st->error = PY_error_obj;
    PyModule_AddObject(m, "Error", st->error);

    // splicer begin C_init_body
    // splicer end C_init_body

    /* Check for errors */
    if (PyErr_Occurred())
        Py_FatalError("can't initialize module tutorial");
    return RETVAL;
}

