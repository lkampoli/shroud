// pypointersmodule.c
// This file is generated by Shroud 0.11.0. Do not edit.
// Copyright (c) 2017-2020, Lawrence Livermore National Security, LLC and
// other Shroud Project Developers.
// See the top-level COPYRIGHT file for details.
//
// SPDX-License-Identifier: (BSD-3-Clause)
//
#include "pypointersmodule.h"
#define PY_ARRAY_UNIQUE_SYMBOL SHROUD_POINTERS_ARRAY_API
#define NPY_NO_DEPRECATED_API NPY_1_7_API_VERSION
#include "numpy/arrayobject.h"
#include <stdlib.h>

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

// helper create_from_PyObject_char
// Convert obj into an array of type char *
// Return -1 on error.
static int SHROUD_create_from_PyObject_char(PyObject *obj,
    const char *name, char * **pin, Py_ssize_t *psize)
{
    PyObject *seq = PySequence_Fast(obj, "holder");
    if (seq == NULL) {
        PyErr_Format(PyExc_TypeError, "argument '%s' must be iterable",
            name);
        return -1;
    }
    Py_ssize_t size = PySequence_Fast_GET_SIZE(seq);
    char * *in = (char * *) malloc(size * sizeof(char *));
    for (Py_ssize_t i = 0; i < size; i++) {
        PyObject *item = PySequence_Fast_GET_ITEM(seq, i);
        in[i] = PyString_AsString(item);
        if (PyErr_Occurred()) {
            free(in);
            Py_DECREF(seq);
            PyErr_Format(PyExc_TypeError,
                "argument '%s', index %d must be string", name,
                (int) i);
            return -1;
        }
    }
    Py_DECREF(seq);
    *pin = in;
    *psize = size;
    return 0;
}

// splicer begin C_definition
// splicer end C_definition
PyObject *PY_error_obj;
// splicer begin additional_functions
// splicer end additional_functions

// ----------------------------------------
// Function:  void intargs
// Exact:     py_default
// ----------------------------------------
// Argument:  const int argin +intent(in)+value
// Requested: py_native_scalar_in
// Match:     py_default
// ----------------------------------------
// Argument:  int * arginout +intent(inout)
// Requested: py_native_*_inout
// Match:     py_default
// ----------------------------------------
// Argument:  int * argout +intent(out)
// Requested: py_native_*_out
// Match:     py_default
static char PY_intargs__doc__[] =
"documentation"
;

static PyObject *
PY_intargs(
  PyObject *SHROUD_UNUSED(self),
  PyObject *args,
  PyObject *kwds)
{
// splicer begin function.intargs
    int argin;
    int arginout;
    char *SHT_kwlist[] = {
        "argin",
        "arginout",
        NULL };
    PyObject *SHTPy_rv = NULL;  // return value object

    if (!PyArg_ParseTupleAndKeywords(args, kwds, "ii:intargs",
        SHT_kwlist, &argin, &arginout))
        return NULL;

    // pre_call
    int argout;  // intent(out)

    intargs(argin, &arginout, &argout);

    // post_call
    SHTPy_rv = Py_BuildValue("ii", arginout, argout);

    return SHTPy_rv;
// splicer end function.intargs
}

// ----------------------------------------
// Function:  void cos_doubles
// Exact:     py_default
// ----------------------------------------
// Argument:  double * in +intent(in)+rank(1)
// Exact:     py_native_*_in_pointer_numpy
// ----------------------------------------
// Argument:  double * out +deref(allocatable)+dimension(size(in))+intent(out)
// Exact:     py_native_*_out_allocatable_numpy
static char PY_cos_doubles__doc__[] =
"documentation"
;

/**
 * \brief compute cos of IN and save in OUT
 *
 * allocate OUT same type as IN implied size of array
 */
static PyObject *
PY_cos_doubles(
  PyObject *SHROUD_UNUSED(self),
  PyObject *args,
  PyObject *kwds)
{
// splicer begin function.cos_doubles
    PyObject * SHTPy_in;
    PyArrayObject * SHPy_in = NULL;
    npy_intp SHD_out[1];
    PyArrayObject * SHPy_out = NULL;
    char *SHT_kwlist[] = {
        "in",
        NULL };

    if (!PyArg_ParseTupleAndKeywords(args, kwds, "O:cos_doubles",
        SHT_kwlist, &SHTPy_in))
        return NULL;

    // post_parse
    SHPy_in = (PyArrayObject *) PyArray_FROM_OTF(SHTPy_in, NPY_DOUBLE,
        NPY_ARRAY_IN_ARRAY);
    if (SHPy_in == NULL) {
        PyErr_SetString(PyExc_ValueError,
            "in must be a 1-D array of double");
        goto fail;
    }
    SHD_out[0] = PyArray_SIZE(SHPy_in);
    SHPy_out = (PyArrayObject *) PyArray_SimpleNew(1, SHD_out, NPY_DOUBLE);
    if (SHPy_out == NULL) {
        PyErr_SetString(PyExc_ValueError,
            "out must be a 1-D array of double");
        goto fail;
    }

    // pre_call
    double * in = PyArray_DATA(SHPy_in);
    double * out = PyArray_DATA(SHPy_out);
    int sizein = PyArray_SIZE(SHPy_in);

    cos_doubles(in, out, sizein);

    // cleanup
    Py_DECREF(SHPy_in);

    return (PyObject *) SHPy_out;

fail:
    Py_XDECREF(SHPy_in);
    Py_XDECREF(SHPy_out);
    return NULL;
// splicer end function.cos_doubles
}

// ----------------------------------------
// Function:  void truncate_to_int
// Exact:     py_default
// ----------------------------------------
// Argument:  double * in +intent(in)+rank(1)
// Exact:     py_native_*_in_pointer_numpy
// ----------------------------------------
// Argument:  int * out +deref(allocatable)+dimension(size(in))+intent(out)
// Exact:     py_native_*_out_allocatable_numpy
static char PY_truncate_to_int__doc__[] =
"documentation"
;

/**
 * \brief truncate IN argument and save in OUT
 *
 * allocate OUT different type as IN
 * implied size of array
 */
static PyObject *
PY_truncate_to_int(
  PyObject *SHROUD_UNUSED(self),
  PyObject *args,
  PyObject *kwds)
{
// splicer begin function.truncate_to_int
    PyObject * SHTPy_in;
    PyArrayObject * SHPy_in = NULL;
    npy_intp SHD_out[1];
    PyArrayObject * SHPy_out = NULL;
    char *SHT_kwlist[] = {
        "in",
        NULL };

    if (!PyArg_ParseTupleAndKeywords(args, kwds, "O:truncate_to_int",
        SHT_kwlist, &SHTPy_in))
        return NULL;

    // post_parse
    SHPy_in = (PyArrayObject *) PyArray_FROM_OTF(SHTPy_in, NPY_DOUBLE,
        NPY_ARRAY_IN_ARRAY);
    if (SHPy_in == NULL) {
        PyErr_SetString(PyExc_ValueError,
            "in must be a 1-D array of double");
        goto fail;
    }
    SHD_out[0] = PyArray_SIZE(SHPy_in);
    SHPy_out = (PyArrayObject *) PyArray_SimpleNew(1, SHD_out, NPY_INT);
    if (SHPy_out == NULL) {
        PyErr_SetString(PyExc_ValueError,
            "out must be a 1-D array of int");
        goto fail;
    }

    // pre_call
    double * in = PyArray_DATA(SHPy_in);
    int * out = PyArray_DATA(SHPy_out);
    int sizein = PyArray_SIZE(SHPy_in);

    truncate_to_int(in, out, sizein);

    // cleanup
    Py_DECREF(SHPy_in);

    return (PyObject *) SHPy_out;

fail:
    Py_XDECREF(SHPy_in);
    Py_XDECREF(SHPy_out);
    return NULL;
// splicer end function.truncate_to_int
}

// ----------------------------------------
// Function:  void get_values
// Exact:     py_default
// ----------------------------------------
// Argument:  int * nvalues +intent(out)
// Requested: py_native_*_out
// Match:     py_default
// ----------------------------------------
// Argument:  int * values +dimension(3)+intent(out)
// Exact:     py_native_*_out_pointer_numpy
static char PY_get_values__doc__[] =
"documentation"
;

/**
 * \brief fill values into array
 *
 * The function knows how long the array must be.
 * Fortran will treat the dimension as assumed-length.
 * The Python wrapper will create a NumPy array or list so it must
 * have an explicit dimension (not assumed-length).
 */
static PyObject *
PY_get_values(
  PyObject *SHROUD_UNUSED(self),
  PyObject *SHROUD_UNUSED(args),
  PyObject *SHROUD_UNUSED(kwds))
{
// splicer begin function.get_values
    npy_intp SHD_values[1];
    PyArrayObject * SHPy_values = NULL;
    PyObject *SHTPy_rv = NULL;  // return value object

    // post_parse
    SHD_values[0] = 3;
    SHPy_values = (PyArrayObject *) PyArray_SimpleNew(1, SHD_values, NPY_INT);
    if (SHPy_values == NULL) {
        PyErr_SetString(PyExc_ValueError,
            "values must be a 1-D array of int");
        goto fail;
    }

    // pre_call
    int nvalues;  // intent(out)
    int * values = PyArray_DATA(SHPy_values);

    get_values(&nvalues, values);

    // post_call
    SHTPy_rv = Py_BuildValue("iO", nvalues, SHPy_values);

    return SHTPy_rv;

fail:
    Py_XDECREF(SHPy_values);
    return NULL;
// splicer end function.get_values
}

// ----------------------------------------
// Function:  void get_values2
// Exact:     py_default
// ----------------------------------------
// Argument:  int * arg1 +dimension(3)+intent(out)
// Exact:     py_native_*_out_pointer_numpy
// ----------------------------------------
// Argument:  int * arg2 +dimension(3)+intent(out)
// Exact:     py_native_*_out_pointer_numpy
static char PY_get_values2__doc__[] =
"documentation"
;

/**
 * \brief fill values into two arrays
 *
 * Test two intent(out) arguments.
 * Make sure error handling works with C++.
 */
static PyObject *
PY_get_values2(
  PyObject *SHROUD_UNUSED(self),
  PyObject *SHROUD_UNUSED(args),
  PyObject *SHROUD_UNUSED(kwds))
{
// splicer begin function.get_values2
    npy_intp SHD_arg1[1];
    PyArrayObject * SHPy_arg1 = NULL;
    npy_intp SHD_arg2[1];
    PyArrayObject * SHPy_arg2 = NULL;
    PyObject *SHTPy_rv = NULL;  // return value object

    // post_parse
    SHD_arg1[0] = 3;
    SHPy_arg1 = (PyArrayObject *) PyArray_SimpleNew(1, SHD_arg1, NPY_INT);
    if (SHPy_arg1 == NULL) {
        PyErr_SetString(PyExc_ValueError,
            "arg1 must be a 1-D array of int");
        goto fail;
    }
    SHD_arg2[0] = 3;
    SHPy_arg2 = (PyArrayObject *) PyArray_SimpleNew(1, SHD_arg2, NPY_INT);
    if (SHPy_arg2 == NULL) {
        PyErr_SetString(PyExc_ValueError,
            "arg2 must be a 1-D array of int");
        goto fail;
    }

    // pre_call
    int * arg1 = PyArray_DATA(SHPy_arg1);
    int * arg2 = PyArray_DATA(SHPy_arg2);

    get_values2(arg1, arg2);

    // post_call
    SHTPy_rv = Py_BuildValue("OO", SHPy_arg1, SHPy_arg2);

    return SHTPy_rv;

fail:
    Py_XDECREF(SHPy_arg1);
    Py_XDECREF(SHPy_arg2);
    return NULL;
// splicer end function.get_values2
}

// ----------------------------------------
// Function:  void iota_allocatable
// Exact:     py_default
// ----------------------------------------
// Argument:  int nvar +intent(in)+value
// Requested: py_native_scalar_in
// Match:     py_default
// ----------------------------------------
// Argument:  int * values +deref(allocatable)+dimension(nvar)+intent(out)
// Exact:     py_native_*_out_allocatable_numpy
static char PY_iota_allocatable__doc__[] =
"documentation"
;

static PyObject *
PY_iota_allocatable(
  PyObject *SHROUD_UNUSED(self),
  PyObject *args,
  PyObject *kwds)
{
// splicer begin function.iota_allocatable
    int nvar;
    npy_intp SHD_values[1];
    PyArrayObject * SHPy_values = NULL;
    char *SHT_kwlist[] = {
        "nvar",
        NULL };

    if (!PyArg_ParseTupleAndKeywords(args, kwds, "i:iota_allocatable",
        SHT_kwlist, &nvar))
        return NULL;

    // post_parse
    SHD_values[0] = nvar;
    SHPy_values = (PyArrayObject *) PyArray_SimpleNew(1, SHD_values, NPY_INT);
    if (SHPy_values == NULL) {
        PyErr_SetString(PyExc_ValueError,
            "values must be a 1-D array of int");
        goto fail;
    }

    // pre_call
    int * values = PyArray_DATA(SHPy_values);

    iota_allocatable(nvar, values);
    return (PyObject *) SHPy_values;

fail:
    Py_XDECREF(SHPy_values);
    return NULL;
// splicer end function.iota_allocatable
}

// ----------------------------------------
// Function:  void iota_dimension
// Exact:     py_default
// ----------------------------------------
// Argument:  int nvar +intent(in)+value
// Requested: py_native_scalar_in
// Match:     py_default
// ----------------------------------------
// Argument:  int * values +dimension(nvar)+intent(out)
// Exact:     py_native_*_out_pointer_numpy
static char PY_iota_dimension__doc__[] =
"documentation"
;

static PyObject *
PY_iota_dimension(
  PyObject *SHROUD_UNUSED(self),
  PyObject *args,
  PyObject *kwds)
{
// splicer begin function.iota_dimension
    int nvar;
    npy_intp SHD_values[1];
    PyArrayObject * SHPy_values = NULL;
    char *SHT_kwlist[] = {
        "nvar",
        NULL };

    if (!PyArg_ParseTupleAndKeywords(args, kwds, "i:iota_dimension",
        SHT_kwlist, &nvar))
        return NULL;

    // post_parse
    SHD_values[0] = nvar;
    SHPy_values = (PyArrayObject *) PyArray_SimpleNew(1, SHD_values, NPY_INT);
    if (SHPy_values == NULL) {
        PyErr_SetString(PyExc_ValueError,
            "values must be a 1-D array of int");
        goto fail;
    }

    // pre_call
    int * values = PyArray_DATA(SHPy_values);

    iota_dimension(nvar, values);
    return (PyObject *) SHPy_values;

fail:
    Py_XDECREF(SHPy_values);
    return NULL;
// splicer end function.iota_dimension
}

// ----------------------------------------
// Function:  void Sum
// Exact:     py_default
// ----------------------------------------
// Argument:  int * values +intent(in)+rank(1)
// Exact:     py_native_*_in_pointer_numpy
// ----------------------------------------
// Argument:  int * result +intent(out)
// Requested: py_native_*_out
// Match:     py_default
static char PY_Sum__doc__[] =
"documentation"
;

static PyObject *
PY_Sum(
  PyObject *SHROUD_UNUSED(self),
  PyObject *args,
  PyObject *kwds)
{
// splicer begin function.sum
    PyObject * SHTPy_values;
    PyArrayObject * SHPy_values = NULL;
    char *SHT_kwlist[] = {
        "values",
        NULL };
    PyObject * SHPy_result = NULL;

    if (!PyArg_ParseTupleAndKeywords(args, kwds, "O:Sum", SHT_kwlist, 
        &SHTPy_values))
        return NULL;

    // post_parse
    SHPy_values = (PyArrayObject *) PyArray_FROM_OTF(SHTPy_values,
        NPY_INT, NPY_ARRAY_IN_ARRAY);
    if (SHPy_values == NULL) {
        PyErr_SetString(PyExc_ValueError,
            "values must be a 1-D array of int");
        goto fail;
    }

    // pre_call
    int * values = PyArray_DATA(SHPy_values);
    int result;  // intent(out)
    int len = PyArray_SIZE(SHPy_values);

    Sum(len, values, &result);

    // post_call
    SHPy_result = PyInt_FromLong(result);

    // cleanup
    Py_DECREF(SHPy_values);

    return (PyObject *) SHPy_result;

fail:
    Py_XDECREF(SHPy_values);
    return NULL;
// splicer end function.sum
}

// ----------------------------------------
// Function:  void fillIntArray
// Exact:     py_default
// ----------------------------------------
// Argument:  int * out +dimension(3)+intent(out)
// Exact:     py_native_*_out_pointer_numpy
static char PY_fillIntArray__doc__[] =
"documentation"
;

/**
 * Return three values into memory the user provides.
 */
static PyObject *
PY_fillIntArray(
  PyObject *SHROUD_UNUSED(self),
  PyObject *SHROUD_UNUSED(args),
  PyObject *SHROUD_UNUSED(kwds))
{
// splicer begin function.fill_int_array
    npy_intp SHD_out[1];
    PyArrayObject * SHPy_out = NULL;

    // post_parse
    SHD_out[0] = 3;
    SHPy_out = (PyArrayObject *) PyArray_SimpleNew(1, SHD_out, NPY_INT);
    if (SHPy_out == NULL) {
        PyErr_SetString(PyExc_ValueError,
            "out must be a 1-D array of int");
        goto fail;
    }

    // pre_call
    int * out = PyArray_DATA(SHPy_out);

    fillIntArray(out);
    return (PyObject *) SHPy_out;

fail:
    Py_XDECREF(SHPy_out);
    return NULL;
// splicer end function.fill_int_array
}

// ----------------------------------------
// Function:  void incrementIntArray
// Exact:     py_default
// ----------------------------------------
// Argument:  int * array +intent(inout)+rank(1)
// Exact:     py_native_*_inout_pointer_numpy
static char PY_incrementIntArray__doc__[] =
"documentation"
;

/**
 * Increment array in place using intent(INOUT).
 */
static PyObject *
PY_incrementIntArray(
  PyObject *SHROUD_UNUSED(self),
  PyObject *args,
  PyObject *kwds)
{
// splicer begin function.increment_int_array
    PyObject * SHTPy_array;
    PyArrayObject * SHPy_array = NULL;
    char *SHT_kwlist[] = {
        "array",
        NULL };

    if (!PyArg_ParseTupleAndKeywords(args, kwds, "O:incrementIntArray",
        SHT_kwlist, &SHTPy_array))
        return NULL;

    // post_parse
    SHPy_array = (PyArrayObject *) PyArray_FROM_OTF(SHTPy_array,
        NPY_INT, NPY_ARRAY_INOUT_ARRAY);
    if (SHPy_array == NULL) {
        PyErr_SetString(PyExc_ValueError,
            "array must be a 1-D array of int");
        goto fail;
    }

    // pre_call
    int * array = PyArray_DATA(SHPy_array);
    int sizein = PyArray_SIZE(SHPy_array);

    incrementIntArray(array, sizein);
    return (PyObject *) SHPy_array;

fail:
    Py_XDECREF(SHPy_array);
    return NULL;
// splicer end function.increment_int_array
}

// ----------------------------------------
// Function:  void acceptCharArrayIn
// Exact:     py_default
// ----------------------------------------
// Argument:  char * * names +intent(in)+rank(1)
// Exact:     py_char_**_in
static char PY_acceptCharArrayIn__doc__[] =
"documentation"
;

static PyObject *
PY_acceptCharArrayIn(
  PyObject *SHROUD_UNUSED(self),
  PyObject *args,
  PyObject *kwds)
{
// splicer begin function.accept_char_array_in
    char ** names = NULL;
    PyObject * SHTPy_names;
    char *SHT_kwlist[] = {
        "names",
        NULL };

    if (!PyArg_ParseTupleAndKeywords(args, kwds, "O:acceptCharArrayIn",
        SHT_kwlist, &SHTPy_names))
        return NULL;

    // pre_call
    Py_ssize_t SHSize_names;
    if (SHROUD_create_from_PyObject_char(SHTPy_names, "names", &names, 
        &SHSize_names) == -1)
        goto fail;

    acceptCharArrayIn(names);

    // post_call
    free(names);
    names = NULL;

    Py_RETURN_NONE;

fail:
    if (names != NULL) {
        free(names);
    }
    return NULL;
// splicer end function.accept_char_array_in
}

// ----------------------------------------
// Function:  void setGlobalInt
// Exact:     py_default
// ----------------------------------------
// Argument:  int value +intent(in)+value
// Requested: py_native_scalar_in
// Match:     py_default
static char PY_setGlobalInt__doc__[] =
"documentation"
;

static PyObject *
PY_setGlobalInt(
  PyObject *SHROUD_UNUSED(self),
  PyObject *args,
  PyObject *kwds)
{
// splicer begin function.set_global_int
    int value;
    char *SHT_kwlist[] = {
        "value",
        NULL };

    if (!PyArg_ParseTupleAndKeywords(args, kwds, "i:setGlobalInt",
        SHT_kwlist, &value))
        return NULL;

    setGlobalInt(value);
    Py_RETURN_NONE;
// splicer end function.set_global_int
}

// ----------------------------------------
// Function:  int sumFixedArray
// Requested: py_native_scalar_result
// Match:     py_default
static char PY_sumFixedArray__doc__[] =
"documentation"
;

/**
 * Used to test values global_array.
 */
static PyObject *
PY_sumFixedArray(
  PyObject *SHROUD_UNUSED(self),
  PyObject *SHROUD_UNUSED(args),
  PyObject *SHROUD_UNUSED(kwds))
{
// splicer begin function.sum_fixed_array
    PyObject * SHTPy_rv = NULL;

    int SHCXX_rv = sumFixedArray();

    // post_call
    SHTPy_rv = PyInt_FromLong(SHCXX_rv);

    return (PyObject *) SHTPy_rv;
// splicer end function.sum_fixed_array
}

// ----------------------------------------
// Function:  void getPtrToFixedArray
// Exact:     py_default
// ----------------------------------------
// Argument:  int * * count +deref(pointer)+dimension(10)+intent(out)
// Exact:     py_native_**_out_pointer_numpy
static char PY_getPtrToFixedArray__doc__[] =
"documentation"
;

/**
 * Return a Fortran pointer to an array which is always the same length.
 */
static PyObject *
PY_getPtrToFixedArray(
  PyObject *SHROUD_UNUSED(self),
  PyObject *SHROUD_UNUSED(args),
  PyObject *SHROUD_UNUSED(kwds))
{
// splicer begin function.get_ptr_to_fixed_array
    int *count;
    npy_intp SHD_count[1];
    PyObject *SHPy_count = NULL;

    getPtrToFixedArray(&count);

    // post_call
    SHD_count[0] = 10;
    SHPy_count = PyArray_SimpleNewFromData(1, SHD_count, NPY_INT,
        count);
    if (SHPy_count == NULL) goto fail;

    return (PyObject *) SHPy_count;

fail:
    Py_XDECREF(SHPy_count);
    return NULL;
// splicer end function.get_ptr_to_fixed_array
}

// ----------------------------------------
// Function:  void getPtrToDynamicArray
// Exact:     py_default
// ----------------------------------------
// Argument:  int * * count +deref(pointer)+dimension(ncount)+intent(out)
// Exact:     py_native_**_out_pointer_numpy
// ----------------------------------------
// Argument:  int * ncount +hidden+intent(out)
// Requested: py_native_*_out
// Match:     py_default
static char PY_getPtrToDynamicArray__doc__[] =
"documentation"
;

/**
 * Return a Fortran pointer to an array which is the length of
 * the argument ncount.
 */
static PyObject *
PY_getPtrToDynamicArray(
  PyObject *SHROUD_UNUSED(self),
  PyObject *SHROUD_UNUSED(args),
  PyObject *SHROUD_UNUSED(kwds))
{
// splicer begin function.get_ptr_to_dynamic_array
    int *count;
    npy_intp SHD_count[1];
    PyObject *SHPy_count = NULL;

    // pre_call
    int ncount;  // intent(out)

    getPtrToDynamicArray(&count, &ncount);

    // post_call
    SHD_count[0] = ncount;
    SHPy_count = PyArray_SimpleNewFromData(1, SHD_count, NPY_INT,
        count);
    if (SHPy_count == NULL) goto fail;

    return (PyObject *) SHPy_count;

fail:
    Py_XDECREF(SHPy_count);
    return NULL;
// splicer end function.get_ptr_to_dynamic_array
}

// ----------------------------------------
// Function:  void getPtrToFuncArray
// Exact:     py_default
// ----------------------------------------
// Argument:  int * * count +deref(pointer)+dimension(getLen())+intent(out)
// Exact:     py_native_**_out_pointer_numpy
static char PY_getPtrToFuncArray__doc__[] =
"documentation"
;

/**
 * Return a Fortran pointer to an array which is the length
 * is computed by C++ function getLen.
 * getLen will be called from C/C++ to compute the shape.
 */
static PyObject *
PY_getPtrToFuncArray(
  PyObject *SHROUD_UNUSED(self),
  PyObject *SHROUD_UNUSED(args),
  PyObject *SHROUD_UNUSED(kwds))
{
// splicer begin function.get_ptr_to_func_array
    int *count;
    npy_intp SHD_count[1];
    PyObject *SHPy_count = NULL;

    getPtrToFuncArray(&count);

    // post_call
    SHD_count[0] = getLen();
    SHPy_count = PyArray_SimpleNewFromData(1, SHD_count, NPY_INT,
        count);
    if (SHPy_count == NULL) goto fail;

    return (PyObject *) SHPy_count;

fail:
    Py_XDECREF(SHPy_count);
    return NULL;
// splicer end function.get_ptr_to_func_array
}

// ----------------------------------------
// Function:  void getPtrToFixedConstArray
// Exact:     py_default
// ----------------------------------------
// Argument:  const int * * count +deref(pointer)+dimension(10)+intent(out)
// Exact:     py_native_**_out_pointer_numpy
static char PY_getPtrToFixedConstArray__doc__[] =
"documentation"
;

static PyObject *
PY_getPtrToFixedConstArray(
  PyObject *SHROUD_UNUSED(self),
  PyObject *SHROUD_UNUSED(args),
  PyObject *SHROUD_UNUSED(kwds))
{
// splicer begin function.get_ptr_to_fixed_const_array
    const int *count;
    npy_intp SHD_count[1];
    PyObject *SHPy_count = NULL;

    getPtrToFixedConstArray(&count);

    // post_call
    SHD_count[0] = 10;
    SHPy_count = PyArray_SimpleNewFromData(1, SHD_count, NPY_INT,
        (int *) count);
    if (SHPy_count == NULL) goto fail;

    return (PyObject *) SHPy_count;

fail:
    Py_XDECREF(SHPy_count);
    return NULL;
// splicer end function.get_ptr_to_fixed_const_array
}

// ----------------------------------------
// Function:  void getPtrToDynamicConstArray
// Exact:     py_default
// ----------------------------------------
// Argument:  const int * * count +deref(pointer)+dimension(ncount)+intent(out)
// Exact:     py_native_**_out_pointer_numpy
// ----------------------------------------
// Argument:  int * ncount +hidden+intent(out)
// Requested: py_native_*_out
// Match:     py_default
static char PY_getPtrToDynamicConstArray__doc__[] =
"documentation"
;

static PyObject *
PY_getPtrToDynamicConstArray(
  PyObject *SHROUD_UNUSED(self),
  PyObject *SHROUD_UNUSED(args),
  PyObject *SHROUD_UNUSED(kwds))
{
// splicer begin function.get_ptr_to_dynamic_const_array
    const int *count;
    npy_intp SHD_count[1];
    PyObject *SHPy_count = NULL;

    // pre_call
    int ncount;  // intent(out)

    getPtrToDynamicConstArray(&count, &ncount);

    // post_call
    SHD_count[0] = ncount;
    SHPy_count = PyArray_SimpleNewFromData(1, SHD_count, NPY_INT,
        (int *) count);
    if (SHPy_count == NULL) goto fail;

    return (PyObject *) SHPy_count;

fail:
    Py_XDECREF(SHPy_count);
    return NULL;
// splicer end function.get_ptr_to_dynamic_const_array
}

// ----------------------------------------
// Function:  void getRawPtrToScalar
// Exact:     py_default
// ----------------------------------------
// Argument:  int * * nitems +deref(raw)+intent(out)
// Exact:     py_native_**_out_raw
static char PY_getRawPtrToScalar__doc__[] =
"documentation"
;

/**
 * Called directly via an interface in Fortran.
 */
static PyObject *
PY_getRawPtrToScalar(
  PyObject *SHROUD_UNUSED(self),
  PyObject *SHROUD_UNUSED(args),
  PyObject *SHROUD_UNUSED(kwds))
{
// splicer begin function.get_raw_ptr_to_scalar
    int *nitems;
    PyObject *SHPy_nitems = NULL;

    getRawPtrToScalar(&nitems);

    // post_call
    SHPy_nitems = PyCapsule_New(nitems, NULL, NULL);

    return (PyObject *) SHPy_nitems;
// splicer end function.get_raw_ptr_to_scalar
}

// ----------------------------------------
// Function:  void getRawPtrToFixedArray
// Exact:     py_default
// ----------------------------------------
// Argument:  int * * count +deref(raw)+intent(out)
// Exact:     py_native_**_out_raw
static char PY_getRawPtrToFixedArray__doc__[] =
"documentation"
;

/**
 * Return a type(C_PTR) to an array which is always the same length.
 * Called directly via an interface in Fortran.
 * # Uses +deref(raw) instead of +dimension(10) like getPtrToFixedArray.
 */
static PyObject *
PY_getRawPtrToFixedArray(
  PyObject *SHROUD_UNUSED(self),
  PyObject *SHROUD_UNUSED(args),
  PyObject *SHROUD_UNUSED(kwds))
{
// splicer begin function.get_raw_ptr_to_fixed_array
    int *count;
    PyObject *SHPy_count = NULL;

    getRawPtrToFixedArray(&count);

    // post_call
    SHPy_count = PyCapsule_New(count, NULL, NULL);

    return (PyObject *) SHPy_count;
// splicer end function.get_raw_ptr_to_fixed_array
}

// ----------------------------------------
// Function:  void * returnAddress1
// Requested: py_unknown_result
// Match:     py_default
// ----------------------------------------
// Argument:  int flag +intent(in)+value
// Requested: py_native_scalar_in
// Match:     py_default
static char PY_returnAddress1__doc__[] =
"documentation"
;

static PyObject *
PY_returnAddress1(
  PyObject *SHROUD_UNUSED(self),
  PyObject *args,
  PyObject *kwds)
{
// splicer begin function.return_address1
    int flag;
    char *SHT_kwlist[] = {
        "flag",
        NULL };
    PyObject * SHTPy_rv = NULL;

    if (!PyArg_ParseTupleAndKeywords(args, kwds, "i:returnAddress1",
        SHT_kwlist, &flag))
        return NULL;

    void * SHCXX_rv = returnAddress1(flag);

    // post_call
    SHTPy_rv = PyCapsule_New(SHCXX_rv, NULL, NULL);

    return (PyObject *) SHTPy_rv;
// splicer end function.return_address1
}

// ----------------------------------------
// Function:  void * returnAddress2
// Requested: py_unknown_result
// Match:     py_default
// ----------------------------------------
// Argument:  int flag +intent(in)+value
// Requested: py_native_scalar_in
// Match:     py_default
static char PY_returnAddress2__doc__[] =
"documentation"
;

static PyObject *
PY_returnAddress2(
  PyObject *SHROUD_UNUSED(self),
  PyObject *args,
  PyObject *kwds)
{
// splicer begin function.return_address2
    int flag;
    char *SHT_kwlist[] = {
        "flag",
        NULL };
    PyObject * SHTPy_rv = NULL;

    if (!PyArg_ParseTupleAndKeywords(args, kwds, "i:returnAddress2",
        SHT_kwlist, &flag))
        return NULL;

    void * SHCXX_rv = returnAddress2(flag);

    // post_call
    SHTPy_rv = PyCapsule_New(SHCXX_rv, NULL, NULL);

    return (PyObject *) SHTPy_rv;
// splicer end function.return_address2
}

// ----------------------------------------
// Function:  int * returnIntPtrToScalar +deref(pointer)
// Exact:     py_native_*_result_pointer_numpy
static char PY_returnIntPtrToScalar__doc__[] =
"documentation"
;

static PyObject *
PY_returnIntPtrToScalar(
  PyObject *SHROUD_UNUSED(self),
  PyObject *SHROUD_UNUSED(args),
  PyObject *SHROUD_UNUSED(kwds))
{
// splicer begin function.return_int_ptr_to_scalar
    PyObject * SHTPy_rv = NULL;

    int * SHCXX_rv = returnIntPtrToScalar();

    // post_call
    SHTPy_rv = PyArray_SimpleNewFromData(0, NULL, NPY_INT, SHCXX_rv);
    if (SHTPy_rv == NULL) goto fail;

    return (PyObject *) SHTPy_rv;

fail:
    Py_XDECREF(SHTPy_rv);
    return NULL;
// splicer end function.return_int_ptr_to_scalar
}

// ----------------------------------------
// Function:  int * returnIntPtrToFixedArray +deref(pointer)+dimension(10)
// Exact:     py_native_*_result_pointer_numpy
static char PY_returnIntPtrToFixedArray__doc__[] =
"documentation"
;

static PyObject *
PY_returnIntPtrToFixedArray(
  PyObject *SHROUD_UNUSED(self),
  PyObject *SHROUD_UNUSED(args),
  PyObject *SHROUD_UNUSED(kwds))
{
// splicer begin function.return_int_ptr_to_fixed_array
    npy_intp SHD_rv[1];
    PyObject * SHTPy_rv = NULL;

    int * SHCXX_rv = returnIntPtrToFixedArray();

    // post_call
    SHD_rv[0] = 10;
    SHTPy_rv = PyArray_SimpleNewFromData(1, SHD_rv, NPY_INT, SHCXX_rv);
    if (SHTPy_rv == NULL) goto fail;

    return (PyObject *) SHTPy_rv;

fail:
    Py_XDECREF(SHTPy_rv);
    return NULL;
// splicer end function.return_int_ptr_to_fixed_array
}

// ----------------------------------------
// Function:  const int * returnIntPtrToConstScalar +deref(pointer)
// Exact:     py_native_*_result_pointer_numpy
static char PY_returnIntPtrToConstScalar__doc__[] =
"documentation"
;

static PyObject *
PY_returnIntPtrToConstScalar(
  PyObject *SHROUD_UNUSED(self),
  PyObject *SHROUD_UNUSED(args),
  PyObject *SHROUD_UNUSED(kwds))
{
// splicer begin function.return_int_ptr_to_const_scalar
    PyObject * SHTPy_rv = NULL;

    const int * SHCXX_rv = returnIntPtrToConstScalar();

    // post_call
    SHTPy_rv = PyArray_SimpleNewFromData(0, NULL, NPY_INT,
        (int *) SHCXX_rv);
    if (SHTPy_rv == NULL) goto fail;

    return (PyObject *) SHTPy_rv;

fail:
    Py_XDECREF(SHTPy_rv);
    return NULL;
// splicer end function.return_int_ptr_to_const_scalar
}

// ----------------------------------------
// Function:  const int * returnIntPtrToFixedConstArray +deref(pointer)+dimension(10)
// Exact:     py_native_*_result_pointer_numpy
static char PY_returnIntPtrToFixedConstArray__doc__[] =
"documentation"
;

static PyObject *
PY_returnIntPtrToFixedConstArray(
  PyObject *SHROUD_UNUSED(self),
  PyObject *SHROUD_UNUSED(args),
  PyObject *SHROUD_UNUSED(kwds))
{
// splicer begin function.return_int_ptr_to_fixed_const_array
    npy_intp SHD_rv[1];
    PyObject * SHTPy_rv = NULL;

    const int * SHCXX_rv = returnIntPtrToFixedConstArray();

    // post_call
    SHD_rv[0] = 10;
    SHTPy_rv = PyArray_SimpleNewFromData(1, SHD_rv, NPY_INT,
        (int *) SHCXX_rv);
    if (SHTPy_rv == NULL) goto fail;

    return (PyObject *) SHTPy_rv;

fail:
    Py_XDECREF(SHTPy_rv);
    return NULL;
// splicer end function.return_int_ptr_to_fixed_const_array
}

// ----------------------------------------
// Function:  int * returnIntScalar +deref(scalar)
// Requested: py_native_*_result_scalar_numpy
// Match:     py_default
static char PY_returnIntScalar__doc__[] =
"documentation"
;

static PyObject *
PY_returnIntScalar(
  PyObject *SHROUD_UNUSED(self),
  PyObject *SHROUD_UNUSED(args),
  PyObject *SHROUD_UNUSED(kwds))
{
// splicer begin function.return_int_scalar
    PyObject * SHTPy_rv = NULL;

    int * SHCXX_rv = returnIntScalar();

    // post_call
    SHTPy_rv = PyInt_FromLong(*SHCXX_rv);

    return (PyObject *) SHTPy_rv;
// splicer end function.return_int_scalar
}
static PyMethodDef PY_methods[] = {
{"intargs", (PyCFunction)PY_intargs, METH_VARARGS|METH_KEYWORDS,
    PY_intargs__doc__},
{"cos_doubles", (PyCFunction)PY_cos_doubles, METH_VARARGS|METH_KEYWORDS,
    PY_cos_doubles__doc__},
{"truncate_to_int", (PyCFunction)PY_truncate_to_int,
    METH_VARARGS|METH_KEYWORDS, PY_truncate_to_int__doc__},
{"get_values", (PyCFunction)PY_get_values, METH_NOARGS,
    PY_get_values__doc__},
{"get_values2", (PyCFunction)PY_get_values2, METH_NOARGS,
    PY_get_values2__doc__},
{"iota_allocatable", (PyCFunction)PY_iota_allocatable,
    METH_VARARGS|METH_KEYWORDS, PY_iota_allocatable__doc__},
{"iota_dimension", (PyCFunction)PY_iota_dimension,
    METH_VARARGS|METH_KEYWORDS, PY_iota_dimension__doc__},
{"Sum", (PyCFunction)PY_Sum, METH_VARARGS|METH_KEYWORDS, PY_Sum__doc__},
{"fillIntArray", (PyCFunction)PY_fillIntArray, METH_NOARGS,
    PY_fillIntArray__doc__},
{"incrementIntArray", (PyCFunction)PY_incrementIntArray,
    METH_VARARGS|METH_KEYWORDS, PY_incrementIntArray__doc__},
{"acceptCharArrayIn", (PyCFunction)PY_acceptCharArrayIn,
    METH_VARARGS|METH_KEYWORDS, PY_acceptCharArrayIn__doc__},
{"setGlobalInt", (PyCFunction)PY_setGlobalInt,
    METH_VARARGS|METH_KEYWORDS, PY_setGlobalInt__doc__},
{"sumFixedArray", (PyCFunction)PY_sumFixedArray, METH_NOARGS,
    PY_sumFixedArray__doc__},
{"getPtrToFixedArray", (PyCFunction)PY_getPtrToFixedArray, METH_NOARGS,
    PY_getPtrToFixedArray__doc__},
{"getPtrToDynamicArray", (PyCFunction)PY_getPtrToDynamicArray,
    METH_NOARGS, PY_getPtrToDynamicArray__doc__},
{"getPtrToFuncArray", (PyCFunction)PY_getPtrToFuncArray, METH_NOARGS,
    PY_getPtrToFuncArray__doc__},
{"getPtrToFixedConstArray", (PyCFunction)PY_getPtrToFixedConstArray,
    METH_NOARGS, PY_getPtrToFixedConstArray__doc__},
{"getPtrToDynamicConstArray", (PyCFunction)PY_getPtrToDynamicConstArray,
    METH_NOARGS, PY_getPtrToDynamicConstArray__doc__},
{"getRawPtrToScalar", (PyCFunction)PY_getRawPtrToScalar, METH_NOARGS,
    PY_getRawPtrToScalar__doc__},
{"getRawPtrToFixedArray", (PyCFunction)PY_getRawPtrToFixedArray,
    METH_NOARGS, PY_getRawPtrToFixedArray__doc__},
{"returnAddress1", (PyCFunction)PY_returnAddress1,
    METH_VARARGS|METH_KEYWORDS, PY_returnAddress1__doc__},
{"returnAddress2", (PyCFunction)PY_returnAddress2,
    METH_VARARGS|METH_KEYWORDS, PY_returnAddress2__doc__},
{"returnIntPtrToScalar", (PyCFunction)PY_returnIntPtrToScalar,
    METH_NOARGS, PY_returnIntPtrToScalar__doc__},
{"returnIntPtrToFixedArray", (PyCFunction)PY_returnIntPtrToFixedArray,
    METH_NOARGS, PY_returnIntPtrToFixedArray__doc__},
{"returnIntPtrToConstScalar", (PyCFunction)PY_returnIntPtrToConstScalar,
    METH_NOARGS, PY_returnIntPtrToConstScalar__doc__},
{"returnIntPtrToFixedConstArray",
    (PyCFunction)PY_returnIntPtrToFixedConstArray, METH_NOARGS,
    PY_returnIntPtrToFixedConstArray__doc__},
{"returnIntScalar", (PyCFunction)PY_returnIntScalar, METH_NOARGS,
    PY_returnIntScalar__doc__},
{NULL,   (PyCFunction)NULL, 0, NULL}            /* sentinel */
};

/*
 * initpointers - Initialization function for the module
 * *must* be called initpointers
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
static int pointers_traverse(PyObject *m, visitproc visit, void *arg) {
    Py_VISIT(GETSTATE(m)->error);
    return 0;
}

static int pointers_clear(PyObject *m) {
    Py_CLEAR(GETSTATE(m)->error);
    return 0;
}

static struct PyModuleDef moduledef = {
    PyModuleDef_HEAD_INIT,
    "pointers", /* m_name */
    PY__doc__, /* m_doc */
    sizeof(struct module_state), /* m_size */
    PY_methods, /* m_methods */
    NULL, /* m_reload */
    pointers_traverse, /* m_traverse */
    pointers_clear, /* m_clear */
    NULL  /* m_free */
};

#define RETVAL m
#define INITERROR return NULL
#else
#define RETVAL
#define INITERROR return
#endif

PyMODINIT_FUNC
#if PY_MAJOR_VERSION >= 3
PyInit_pointers(void)
#else
initpointers(void)
#endif
{
    PyObject *m = NULL;
    const char * error_name = "pointers.Error";

    // splicer begin C_init_locals
    // splicer end C_init_locals


    /* Create the module and add the functions */
#if PY_MAJOR_VERSION >= 3
    m = PyModule_Create(&moduledef);
#else
    m = Py_InitModule4("pointers", PY_methods,
        PY__doc__,
        (PyObject*)NULL,PYTHON_API_VERSION);
#endif
    if (m == NULL)
        return RETVAL;
    struct module_state *st = GETSTATE(m);

    import_array();

    PY_error_obj = PyErr_NewException((char *) error_name, NULL, NULL);
    if (PY_error_obj == NULL)
        return RETVAL;
    st->error = PY_error_obj;
    PyModule_AddObject(m, "Error", st->error);

    // splicer begin C_init_body
    // splicer end C_init_body

    /* Check for errors */
    if (PyErr_Occurred())
        Py_FatalError("can't initialize module pointers");
    return RETVAL;
}

