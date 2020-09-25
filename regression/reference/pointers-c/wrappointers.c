// wrappointers.c
// This file is generated by Shroud nowrite-version. Do not edit.
// Copyright (c) 2017-2020, Lawrence Livermore National Security, LLC and
// other Shroud Project Developers.
// See the top-level COPYRIGHT file for details.
//
// SPDX-License-Identifier: (BSD-3-Clause)
//
#include "wrappointers.h"
#include "pointers.h"
#include "typespointers.h"
#include <stdlib.h>
#include <string.h>


// helper ShroudLenTrim
// Returns the length of character string src with length nsrc,
// ignoring any trailing blanks.
static int ShroudLenTrim(const char *src, int nsrc) {
    int i;

    for (i = nsrc - 1; i >= 0; i--) {
        if (src[i] != ' ') {
            break;
        }
    }

    return i + 1;
}


// helper ShroudStrArrayAlloc
// Copy src into new memory and null terminate.
static char **ShroudStrArrayAlloc(const char *src, int nsrc, int len)
{
   char **rv = malloc(sizeof(char *) * nsrc);
   const char *src0 = src;
   for(int i=0; i < nsrc; ++i) {
      int ntrim = ShroudLenTrim(src0, len);
      char *tgt = malloc(ntrim+1);
      memcpy(tgt, src0, ntrim);
      tgt[ntrim] = '\0';
      rv[i] = tgt;
      src0 += len;
   }
   return rv;
}

// helper ShroudStrArrayFree
// Release memory allocated by ShroudStrArrayAlloc
static void ShroudStrArrayFree(char **src, int nsrc)
{
   for(int i=0; i < nsrc; ++i) {
       free(src[i]);
   }
   free(src);
}
// splicer begin C_definitions
// splicer end C_definitions

/**
 * Return strlen of the first index as a check.
 */
// ----------------------------------------
// Function:  int acceptCharArrayIn
// Requested: c_native_scalar_result_buf
// Match:     c_default
// ----------------------------------------
// Argument:  char * * names +intent(in)+len(Nnames)+rank(1)+size(Snames)
// Exact:     c_char_**_in_buf
// start POI_accept_char_array_in_bufferify
int POI_accept_char_array_in_bufferify(char *names, long Snames,
    int Nnames)
{
    // splicer begin function.accept_char_array_in_bufferify
    char **SHCXX_names = ShroudStrArrayAlloc(names, Snames, Nnames);
    int SHC_rv = acceptCharArrayIn(SHCXX_names);
    ShroudStrArrayFree(SHCXX_names, Snames);
    return SHC_rv;
    // splicer end function.accept_char_array_in_bufferify
}
// end POI_accept_char_array_in_bufferify

// ----------------------------------------
// Function:  void getPtrToScalar
// Requested: c
// Match:     c_default
// ----------------------------------------
// Argument:  int * * nitems +context(Dnitems)+deref(pointer)+intent(out)
// Exact:     c_native_**_out_buf
// start POI_get_ptr_to_scalar_bufferify
void POI_get_ptr_to_scalar_bufferify(POI_SHROUD_array *Dnitems)
{
    // splicer begin function.get_ptr_to_scalar_bufferify
    int *nitems;
    getPtrToScalar(&nitems);
    Dnitems->cxx.addr  = nitems;
    Dnitems->cxx.idtor = 0;
    Dnitems->addr.base = nitems;
    Dnitems->type = SH_TYPE_INT;
    Dnitems->elem_len = sizeof(int);
    Dnitems->rank = 0;
    Dnitems->size = 1;
    // splicer end function.get_ptr_to_scalar_bufferify
}
// end POI_get_ptr_to_scalar_bufferify

/**
 * Return a Fortran pointer to an array which is always the same length.
 */
// ----------------------------------------
// Function:  void getPtrToFixedArray
// Requested: c
// Match:     c_default
// ----------------------------------------
// Argument:  int * * count +context(Dcount)+deref(pointer)+dimension(10)+intent(out)
// Exact:     c_native_**_out_buf
// start POI_get_ptr_to_fixed_array_bufferify
void POI_get_ptr_to_fixed_array_bufferify(POI_SHROUD_array *Dcount)
{
    // splicer begin function.get_ptr_to_fixed_array_bufferify
    int *count;
    getPtrToFixedArray(&count);
    Dcount->cxx.addr  = count;
    Dcount->cxx.idtor = 0;
    Dcount->addr.base = count;
    Dcount->type = SH_TYPE_INT;
    Dcount->elem_len = sizeof(int);
    Dcount->rank = 1;
    Dcount->shape[0] = 10;
    Dcount->size = Dcount->shape[0];
    // splicer end function.get_ptr_to_fixed_array_bufferify
}
// end POI_get_ptr_to_fixed_array_bufferify

/**
 * Return a Fortran pointer to an array which is the length of
 * the argument ncount.
 */
// ----------------------------------------
// Function:  void getPtrToDynamicArray
// Requested: c
// Match:     c_default
// ----------------------------------------
// Argument:  int * * count +context(Dcount)+deref(pointer)+dimension(ncount)+intent(out)
// Exact:     c_native_**_out_buf
// ----------------------------------------
// Argument:  int * ncount +hidden+intent(out)
// Requested: c_native_*_out_buf
// Match:     c_default
// start POI_get_ptr_to_dynamic_array_bufferify
void POI_get_ptr_to_dynamic_array_bufferify(POI_SHROUD_array *Dcount,
    int * ncount)
{
    // splicer begin function.get_ptr_to_dynamic_array_bufferify
    int *count;
    getPtrToDynamicArray(&count, ncount);
    Dcount->cxx.addr  = count;
    Dcount->cxx.idtor = 0;
    Dcount->addr.base = count;
    Dcount->type = SH_TYPE_INT;
    Dcount->elem_len = sizeof(int);
    Dcount->rank = 1;
    Dcount->shape[0] = *ncount;
    Dcount->size = Dcount->shape[0];
    // splicer end function.get_ptr_to_dynamic_array_bufferify
}
// end POI_get_ptr_to_dynamic_array_bufferify

/**
 * Return a Fortran pointer to an array which is the length
 * is computed by C++ function getLen.
 * getLen will be called from C/C++ to compute the shape.
 */
// ----------------------------------------
// Function:  void getPtrToFuncArray
// Requested: c
// Match:     c_default
// ----------------------------------------
// Argument:  int * * count +context(Dcount)+deref(pointer)+dimension(getLen())+intent(out)
// Exact:     c_native_**_out_buf
// start POI_get_ptr_to_func_array_bufferify
void POI_get_ptr_to_func_array_bufferify(POI_SHROUD_array *Dcount)
{
    // splicer begin function.get_ptr_to_func_array_bufferify
    int *count;
    getPtrToFuncArray(&count);
    Dcount->cxx.addr  = count;
    Dcount->cxx.idtor = 0;
    Dcount->addr.base = count;
    Dcount->type = SH_TYPE_INT;
    Dcount->elem_len = sizeof(int);
    Dcount->rank = 1;
    Dcount->shape[0] = getLen();
    Dcount->size = Dcount->shape[0];
    // splicer end function.get_ptr_to_func_array_bufferify
}
// end POI_get_ptr_to_func_array_bufferify

// ----------------------------------------
// Function:  void getPtrToConstScalar
// Requested: c
// Match:     c_default
// ----------------------------------------
// Argument:  const int * * nitems +context(Dnitems)+deref(pointer)+intent(out)
// Exact:     c_native_**_out_buf
// start POI_get_ptr_to_const_scalar_bufferify
void POI_get_ptr_to_const_scalar_bufferify(POI_SHROUD_array *Dnitems)
{
    // splicer begin function.get_ptr_to_const_scalar_bufferify
    const int *nitems;
    getPtrToConstScalar(&nitems);
    Dnitems->cxx.addr  = (int *) nitems;
    Dnitems->cxx.idtor = 0;
    Dnitems->addr.base = nitems;
    Dnitems->type = SH_TYPE_INT;
    Dnitems->elem_len = sizeof(int);
    Dnitems->rank = 0;
    Dnitems->size = 1;
    // splicer end function.get_ptr_to_const_scalar_bufferify
}
// end POI_get_ptr_to_const_scalar_bufferify

// ----------------------------------------
// Function:  void getPtrToFixedConstArray
// Requested: c
// Match:     c_default
// ----------------------------------------
// Argument:  const int * * count +context(Dcount)+deref(pointer)+dimension(10)+intent(out)
// Exact:     c_native_**_out_buf
// start POI_get_ptr_to_fixed_const_array_bufferify
void POI_get_ptr_to_fixed_const_array_bufferify(
    POI_SHROUD_array *Dcount)
{
    // splicer begin function.get_ptr_to_fixed_const_array_bufferify
    const int *count;
    getPtrToFixedConstArray(&count);
    Dcount->cxx.addr  = (int *) count;
    Dcount->cxx.idtor = 0;
    Dcount->addr.base = count;
    Dcount->type = SH_TYPE_INT;
    Dcount->elem_len = sizeof(int);
    Dcount->rank = 1;
    Dcount->shape[0] = 10;
    Dcount->size = Dcount->shape[0];
    // splicer end function.get_ptr_to_fixed_const_array_bufferify
}
// end POI_get_ptr_to_fixed_const_array_bufferify

// ----------------------------------------
// Function:  void getPtrToDynamicConstArray
// Requested: c
// Match:     c_default
// ----------------------------------------
// Argument:  const int * * count +context(Dcount)+deref(pointer)+dimension(ncount)+intent(out)
// Exact:     c_native_**_out_buf
// ----------------------------------------
// Argument:  int * ncount +hidden+intent(out)
// Requested: c_native_*_out_buf
// Match:     c_default
// start POI_get_ptr_to_dynamic_const_array_bufferify
void POI_get_ptr_to_dynamic_const_array_bufferify(
    POI_SHROUD_array *Dcount, int * ncount)
{
    // splicer begin function.get_ptr_to_dynamic_const_array_bufferify
    const int *count;
    getPtrToDynamicConstArray(&count, ncount);
    Dcount->cxx.addr  = (int *) count;
    Dcount->cxx.idtor = 0;
    Dcount->addr.base = count;
    Dcount->type = SH_TYPE_INT;
    Dcount->elem_len = sizeof(int);
    Dcount->rank = 1;
    Dcount->shape[0] = *ncount;
    Dcount->size = Dcount->shape[0];
    // splicer end function.get_ptr_to_dynamic_const_array_bufferify
}
// end POI_get_ptr_to_dynamic_const_array_bufferify

/**
 * Called directly via an interface in Fortran.
 */
// ----------------------------------------
// Function:  void getRawPtrToScalar
// Requested: c
// Match:     c_default
// ----------------------------------------
// Argument:  int * * nitems +context(Dnitems)+deref(raw)+intent(out)
// Exact:     c_native_**_out_buf
// start POI_get_raw_ptr_to_scalar_bufferify
void POI_get_raw_ptr_to_scalar_bufferify(POI_SHROUD_array *Dnitems)
{
    // splicer begin function.get_raw_ptr_to_scalar_bufferify
    int *nitems;
    getRawPtrToScalar(&nitems);
    Dnitems->cxx.addr  = nitems;
    Dnitems->cxx.idtor = 0;
    Dnitems->addr.base = nitems;
    Dnitems->type = SH_TYPE_INT;
    Dnitems->elem_len = sizeof(int);
    Dnitems->rank = 0;
    Dnitems->size = 1;
    // splicer end function.get_raw_ptr_to_scalar_bufferify
}
// end POI_get_raw_ptr_to_scalar_bufferify

/**
 * Create a Fortran wrapper.
 */
// ----------------------------------------
// Function:  void getRawPtrToScalarForce
// Requested: c
// Match:     c_default
// ----------------------------------------
// Argument:  int * * nitems +context(Dnitems)+deref(raw)+intent(out)
// Exact:     c_native_**_out_buf
// start POI_get_raw_ptr_to_scalar_force_bufferify
void POI_get_raw_ptr_to_scalar_force_bufferify(
    POI_SHROUD_array *Dnitems)
{
    // splicer begin function.get_raw_ptr_to_scalar_force_bufferify
    int *nitems;
    getRawPtrToScalarForce(&nitems);
    Dnitems->cxx.addr  = nitems;
    Dnitems->cxx.idtor = 0;
    Dnitems->addr.base = nitems;
    Dnitems->type = SH_TYPE_INT;
    Dnitems->elem_len = sizeof(int);
    Dnitems->rank = 0;
    Dnitems->size = 1;
    // splicer end function.get_raw_ptr_to_scalar_force_bufferify
}
// end POI_get_raw_ptr_to_scalar_force_bufferify

/**
 * Return a type(C_PTR) to an array which is always the same length.
 * Called directly via an interface in Fortran.
 * # Uses +deref(raw) instead of +dimension(10) like getPtrToFixedArray.
 */
// ----------------------------------------
// Function:  void getRawPtrToFixedArray
// Requested: c
// Match:     c_default
// ----------------------------------------
// Argument:  int * * count +context(Dcount)+deref(raw)+intent(out)
// Exact:     c_native_**_out_buf
// start POI_get_raw_ptr_to_fixed_array_bufferify
void POI_get_raw_ptr_to_fixed_array_bufferify(POI_SHROUD_array *Dcount)
{
    // splicer begin function.get_raw_ptr_to_fixed_array_bufferify
    int *count;
    getRawPtrToFixedArray(&count);
    Dcount->cxx.addr  = count;
    Dcount->cxx.idtor = 0;
    Dcount->addr.base = count;
    Dcount->type = SH_TYPE_INT;
    Dcount->elem_len = sizeof(int);
    Dcount->rank = 0;
    Dcount->size = 1;
    // splicer end function.get_raw_ptr_to_fixed_array_bufferify
}
// end POI_get_raw_ptr_to_fixed_array_bufferify

/**
 * Return a type(C_PTR) to an array which is always the same length.
 * Create a Fortran wrapper.
 */
// ----------------------------------------
// Function:  void getRawPtrToFixedArrayForce
// Requested: c
// Match:     c_default
// ----------------------------------------
// Argument:  int * * count +context(Dcount)+deref(raw)+intent(out)
// Exact:     c_native_**_out_buf
// start POI_get_raw_ptr_to_fixed_array_force_bufferify
void POI_get_raw_ptr_to_fixed_array_force_bufferify(
    POI_SHROUD_array *Dcount)
{
    // splicer begin function.get_raw_ptr_to_fixed_array_force_bufferify
    int *count;
    getRawPtrToFixedArrayForce(&count);
    Dcount->cxx.addr  = count;
    Dcount->cxx.idtor = 0;
    Dcount->addr.base = count;
    Dcount->type = SH_TYPE_INT;
    Dcount->elem_len = sizeof(int);
    Dcount->rank = 0;
    Dcount->size = 1;
    // splicer end function.get_raw_ptr_to_fixed_array_force_bufferify
}
// end POI_get_raw_ptr_to_fixed_array_force_bufferify

// ----------------------------------------
// Function:  int * returnIntPtrToFixedArray +context(DSHC_rv)+deref(pointer)+dimension(10)
// Exact:     c_native_*_result_buf
// start POI_return_int_ptr_to_fixed_array_bufferify
int * POI_return_int_ptr_to_fixed_array_bufferify(
    POI_SHROUD_array *DSHC_rv)
{
    // splicer begin function.return_int_ptr_to_fixed_array_bufferify
    int * SHC_rv = returnIntPtrToFixedArray();
    DSHC_rv->cxx.addr  = SHC_rv;
    DSHC_rv->cxx.idtor = 0;
    DSHC_rv->addr.base = SHC_rv;
    DSHC_rv->type = SH_TYPE_INT;
    DSHC_rv->elem_len = sizeof(int);
    DSHC_rv->rank = 1;
    DSHC_rv->shape[0] = 10;
    DSHC_rv->size = DSHC_rv->shape[0];
    return SHC_rv;
    // splicer end function.return_int_ptr_to_fixed_array_bufferify
}
// end POI_return_int_ptr_to_fixed_array_bufferify

// ----------------------------------------
// Function:  const int * returnIntPtrToFixedConstArray +context(DSHC_rv)+deref(pointer)+dimension(10)
// Exact:     c_native_*_result_buf
// start POI_return_int_ptr_to_fixed_const_array_bufferify
const int * POI_return_int_ptr_to_fixed_const_array_bufferify(
    POI_SHROUD_array *DSHC_rv)
{
    // splicer begin function.return_int_ptr_to_fixed_const_array_bufferify
    const int * SHC_rv = returnIntPtrToFixedConstArray();
    DSHC_rv->cxx.addr  = (int *) SHC_rv;
    DSHC_rv->cxx.idtor = 0;
    DSHC_rv->addr.base = SHC_rv;
    DSHC_rv->type = SH_TYPE_INT;
    DSHC_rv->elem_len = sizeof(int);
    DSHC_rv->rank = 1;
    DSHC_rv->shape[0] = 10;
    DSHC_rv->size = DSHC_rv->shape[0];
    return SHC_rv;
    // splicer end function.return_int_ptr_to_fixed_const_array_bufferify
}
// end POI_return_int_ptr_to_fixed_const_array_bufferify

// ----------------------------------------
// Function:  int * returnIntScalar +deref(scalar)
// Requested: c_native_*_result
// Match:     c_default
// start POI_return_int_scalar
int POI_return_int_scalar(void)
{
    // splicer begin function.return_int_scalar
    int * SHC_rv = returnIntScalar();
    return *SHC_rv;
    // splicer end function.return_int_scalar
}
// end POI_return_int_scalar

// start release allocated memory
// Release library allocated memory.
void POI_SHROUD_memory_destructor(POI_SHROUD_capsule_data *cap)
{
    cap->addr = NULL;
    cap->idtor = 0;  // avoid deleting again
}
// end release allocated memory
