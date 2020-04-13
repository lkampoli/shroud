// wrapstrings.cpp
// This file is generated by Shroud 0.11.0. Do not edit.
// Copyright (c) 2017-2020, Lawrence Livermore National Security, LLC and
// other Shroud Project Developers.
// See the top-level COPYRIGHT file for details.
//
// SPDX-License-Identifier: (BSD-3-Clause)
//
#include "wrapstrings.h"
#include <cstddef>
#include <cstdlib>
#include <cstring>
#include <string>
#include "strings.hpp"
#include "typesstrings.h"

// splicer begin CXX_definitions
// splicer end CXX_definitions

extern "C" {


// helper ShroudStrAlloc
// Copy src into new memory and null terminate.
static char *ShroudStrAlloc(const char *src, int nsrc, int ntrim)
{
   char *rv = (char *) std::malloc(nsrc + 1);
   if (ntrim > 0) {
     std::memcpy(rv, src, ntrim);
   }
   rv[ntrim] = '\0';
   return rv;
}

// helper ShroudStrBlankFill
// blank fill dest starting at trailing NULL.
static void ShroudStrBlankFill(char *dest, int ndest)
{
   int nm = std::strlen(dest);
   if(ndest > nm) std::memset(dest+nm,' ',ndest-nm);
}

// helper ShroudStrCopy
// Copy src into dest, blank fill to ndest characters
// Truncate if dest is too short.
// dest will not be NULL terminated.
static void ShroudStrCopy(char *dest, int ndest, const char *src, int nsrc)
{
   if (src == NULL) {
     std::memset(dest,' ',ndest); // convert NULL pointer to blank filled string
   } else {
     if (nsrc < 0) nsrc = std::strlen(src);
     int nm = nsrc < ndest ? nsrc : ndest;
     std::memcpy(dest,src,nm);
     if(ndest > nm) std::memset(dest+nm,' ',ndest-nm); // blank fill
   }
}

// helper ShroudStrFree
// Release memory allocated by ShroudStrAlloc
static void ShroudStrFree(char *src)
{
   free(src);
}

// helper ShroudStrToArray
// start helper ShroudStrToArray
// Save str metadata into array to allow Fortran to access values.
static void ShroudStrToArray(STR_SHROUD_array *array, const std::string * src, int idtor)
{
    array->cxx.addr = static_cast<void *>(const_cast<std::string *>(src));
    array->cxx.idtor = idtor;
    if (src->empty()) {
        array->addr.ccharp = NULL;
        array->elem_len = 0;
    } else {
        array->addr.ccharp = src->data();
        array->elem_len = src->length();
    }
    array->size = 1;
    array->rank = 1;
}
// end helper ShroudStrToArray

// helper copy_string
// start helper copy_string
// Copy the char* or std::string in context into c_var.
// Called by Fortran to deal with allocatable character.
void STR_ShroudCopyStringAndFree(STR_SHROUD_array *data, char *c_var, size_t c_var_len) {
    const char *cxx_var = data->addr.ccharp;
    size_t n = c_var_len;
    if (data->elem_len < n) n = data->elem_len;
    std::strncpy(c_var, cxx_var, n);
    STR_SHROUD_memory_destructor(&data->cxx); // delete data->cxx.addr
}
// end helper copy_string

// splicer begin C_definitions
// splicer end C_definitions

// void passChar(char status +intent(in)+value)
/**
 * \brief pass a single char argument as a scalar.
 *
 */
// ----------------------------------------
// Result
// Requested: c
// Match:     c_default
// ----------------------------------------
// Argument:  status
// Requested: c_schar_scalar_in
// Match:     c_default
void STR_pass_char(char status)
{
    // splicer begin function.pass_char
    passChar(status);
    // splicer end function.pass_char
}

// char returnChar()
/**
 * \brief return a char argument (non-pointer)
 *
 */
// ----------------------------------------
// Result
// Requested: c_schar_scalar_result
// Match:     c_default
char STR_return_char()
{
    // splicer begin function.return_char
    char SHC_rv = returnChar();
    return SHC_rv;
    // splicer end function.return_char
}

// void returnChar(char * SHF_rv +intent(out)+len(NSHF_rv))
/**
 * \brief return a char argument (non-pointer)
 *
 */
// ----------------------------------------
// Result
// Requested: c_unknown_scalar_result_buf
// Match:     c_default
// ----------------------------------------
// Argument:  SHF_rv
// Requested: c_schar_scalar_result_buf
// Match:     c_schar_result_buf
void STR_return_char_bufferify(char * SHF_rv, int NSHF_rv)
{
    // splicer begin function.return_char_bufferify
    char SHC_rv = returnChar();
    std::memset(SHF_rv, ' ', NSHF_rv);
    SHF_rv[0] = SHC_rv;
    // splicer end function.return_char_bufferify
}

// void passCharPtr(char * dest +charlen(40)+intent(out), const char * src +intent(in))
/**
 * \brief strcpy like behavior
 *
 * dest is marked intent(OUT) to override the intent(INOUT) default
 * This avoid a copy-in on dest.
 * In Python, src must not be over 40 characters, defined by charlen.
 */
// ----------------------------------------
// Result
// Requested: c
// Match:     c_default
// ----------------------------------------
// Argument:  dest
// Requested: c_char_*_out
// Match:     c_default
// ----------------------------------------
// Argument:  src
// Requested: c_char_*_in
// Match:     c_default
// start STR_pass_char_ptr
void STR_pass_char_ptr(char * dest, const char * src)
{
    // splicer begin function.pass_char_ptr
    passCharPtr(dest, src);
    // splicer end function.pass_char_ptr
}
// end STR_pass_char_ptr

// void passCharPtr(char * dest +charlen(40)+intent(out)+len(Ndest), const char * src +intent(in))
/**
 * \brief strcpy like behavior
 *
 * dest is marked intent(OUT) to override the intent(INOUT) default
 * This avoid a copy-in on dest.
 * In Python, src must not be over 40 characters, defined by charlen.
 */
// ----------------------------------------
// Result
// Requested: c
// Match:     c_default
// ----------------------------------------
// Argument:  dest
// Requested: c_char_*_out_buf
// Match:     c_char_out_buf
// ----------------------------------------
// Argument:  src
// Requested: c_char_*_in
// Match:     c_default
// start STR_pass_char_ptr_bufferify
void STR_pass_char_ptr_bufferify(char * dest, int Ndest,
    const char * src)
{
    // splicer begin function.pass_char_ptr_bufferify
    passCharPtr(dest, src);
    ShroudStrBlankFill(dest, Ndest);
    // splicer end function.pass_char_ptr_bufferify
}
// end STR_pass_char_ptr_bufferify

// void passCharPtrInOut(char * s +intent(inout))
/**
 * \brief toupper
 *
 * Change a string in-place.
 * For Python, return a new string since strings are immutable.
 */
// ----------------------------------------
// Result
// Requested: c
// Match:     c_default
// ----------------------------------------
// Argument:  s
// Requested: c_char_*_inout
// Match:     c_default
void STR_pass_char_ptr_in_out(char * s)
{
    // splicer begin function.pass_char_ptr_in_out
    passCharPtrInOut(s);
    // splicer end function.pass_char_ptr_in_out
}

// void passCharPtrInOut(char * s +intent(inout)+len(Ns)+len_trim(Ls))
/**
 * \brief toupper
 *
 * Change a string in-place.
 * For Python, return a new string since strings are immutable.
 */
// ----------------------------------------
// Result
// Requested: c
// Match:     c_default
// ----------------------------------------
// Argument:  s
// Requested: c_char_*_inout_buf
// Match:     c_char_inout_buf
void STR_pass_char_ptr_in_out_bufferify(char * s, int Ls, int Ns)
{
    // splicer begin function.pass_char_ptr_in_out_bufferify
    char * SHCXX_s = ShroudStrAlloc(s, Ns, Ls);
    passCharPtrInOut(SHCXX_s);
    ShroudStrCopy(s, Ns, SHCXX_s, -1);
    ShroudStrFree(SHCXX_s);
    // splicer end function.pass_char_ptr_in_out_bufferify
}

// const char * getCharPtr1() +deref(allocatable)
/**
 * \brief return a 'const char *' as character(*)
 *
 */
// ----------------------------------------
// Result
// Requested: c_char_*_result
// Match:     c_char_result
// start STR_get_char_ptr1
const char * STR_get_char_ptr1()
{
    // splicer begin function.get_char_ptr1
    const char * SHC_rv = getCharPtr1();
    return SHC_rv;
    // splicer end function.get_char_ptr1
}
// end STR_get_char_ptr1

// void getCharPtr1(const char * SHF_rv +context(DSHF_rv)+deref(allocatable)+intent(out))
/**
 * \brief return a 'const char *' as character(*)
 *
 */
// ----------------------------------------
// Result
// Requested: c_unknown_scalar_result_buf
// Match:     c_default
// ----------------------------------------
// Argument:  SHF_rv
// Requested: c_char_*_result_buf_allocatable
// Match:     c_char_result_buf_allocatable
// start STR_get_char_ptr1_bufferify
void STR_get_char_ptr1_bufferify(STR_SHROUD_array *DSHF_rv)
{
    // splicer begin function.get_char_ptr1_bufferify
    const char * SHC_rv = getCharPtr1();
    DSHF_rv->cxx.addr = static_cast<void *>(const_cast<char *>(SHC_rv));
    DSHF_rv->cxx.idtor = 0;
    DSHF_rv->addr.ccharp = SHC_rv;
    DSHF_rv->type = SH_TYPE_OTHER;
    DSHF_rv->elem_len = SHC_rv == nullptr ? 0 : std::strlen(SHC_rv);
    DSHF_rv->size = 1;
    DSHF_rv->rank = 0;
    // splicer end function.get_char_ptr1_bufferify
}
// end STR_get_char_ptr1_bufferify

// const char * getCharPtr2() +deref(result_as_arg)+len(30)
/**
 * \brief return 'const char *' with fixed size (len=30)
 *
 */
// ----------------------------------------
// Result
// Requested: c_char_*_result
// Match:     c_char_result
// start STR_get_char_ptr2
const char * STR_get_char_ptr2()
{
    // splicer begin function.get_char_ptr2
    const char * SHC_rv = getCharPtr2();
    return SHC_rv;
    // splicer end function.get_char_ptr2
}
// end STR_get_char_ptr2

// void getCharPtr2(char * SHF_rv +intent(out)+len(NSHF_rv)) +len(30)
/**
 * \brief return 'const char *' with fixed size (len=30)
 *
 */
// ----------------------------------------
// Result
// Requested: c_unknown_scalar_result_buf
// Match:     c_default
// ----------------------------------------
// Argument:  SHF_rv
// Requested: c_char_*_result_buf
// Match:     c_char_result_buf
// start STR_get_char_ptr2_bufferify
void STR_get_char_ptr2_bufferify(char * SHF_rv, int NSHF_rv)
{
    // splicer begin function.get_char_ptr2_bufferify
    const char * SHC_rv = getCharPtr2();
    ShroudStrCopy(SHF_rv, NSHF_rv, SHC_rv, -1);
    // splicer end function.get_char_ptr2_bufferify
}
// end STR_get_char_ptr2_bufferify

// const char * getCharPtr3() +deref(result_as_arg)
/**
 * \brief return a 'const char *' as argument
 *
 */
// ----------------------------------------
// Result
// Requested: c_char_*_result
// Match:     c_char_result
// start STR_get_char_ptr3
const char * STR_get_char_ptr3()
{
    // splicer begin function.get_char_ptr3
    const char * SHC_rv = getCharPtr3();
    return SHC_rv;
    // splicer end function.get_char_ptr3
}
// end STR_get_char_ptr3

// void getCharPtr3(char * output +intent(out)+len(Noutput))
/**
 * \brief return a 'const char *' as argument
 *
 */
// ----------------------------------------
// Result
// Requested: c_unknown_scalar_result_buf
// Match:     c_default
// ----------------------------------------
// Argument:  output
// Requested: c_char_*_result_buf
// Match:     c_char_result_buf
// start STR_get_char_ptr3_bufferify
void STR_get_char_ptr3_bufferify(char * output, int Noutput)
{
    // splicer begin function.get_char_ptr3_bufferify
    const char * SHC_rv = getCharPtr3();
    ShroudStrCopy(output, Noutput, SHC_rv, -1);
    // splicer end function.get_char_ptr3_bufferify
}
// end STR_get_char_ptr3_bufferify

// void getConstStringResult(const string * SHF_rv +context(DSHF_rv)+deref(allocatable)+intent(out))
/**
 * \brief return an ALLOCATABLE CHARACTER from std::string
 *
 */
// ----------------------------------------
// Result
// Requested: c_unknown_scalar_result_buf
// Match:     c_default
// ----------------------------------------
// Argument:  SHF_rv
// Exact:     c_string_scalar_result_buf_allocatable
void STR_get_const_string_result_bufferify(STR_SHROUD_array *DSHF_rv)
{
    // splicer begin function.get_const_string_result_bufferify
    std::string * SHCXX_rv = new std::string;
    *SHCXX_rv = getConstStringResult();
    ShroudStrToArray(DSHF_rv, SHCXX_rv, 1);
    // splicer end function.get_const_string_result_bufferify
}

// void getConstStringLen(string * SHF_rv +intent(out)+len(NSHF_rv)) +len(30)
/**
 * \brief return a 'const string' as argument
 *
 */
// ----------------------------------------
// Result
// Requested: c_unknown_scalar_result_buf
// Match:     c_default
// ----------------------------------------
// Argument:  SHF_rv
// Exact:     c_string_scalar_result_buf
void STR_get_const_string_len_bufferify(char * SHF_rv, int NSHF_rv)
{
    // splicer begin function.get_const_string_len_bufferify
    const std::string SHCXX_rv = getConstStringLen();
    if (SHCXX_rv.empty()) {
        ShroudStrCopy(SHF_rv, NSHF_rv, nullptr, 0);
    } else {
        ShroudStrCopy(SHF_rv, NSHF_rv, SHCXX_rv.data(),
            SHCXX_rv.size());
    }
    // splicer end function.get_const_string_len_bufferify
}

// void getConstStringAsArg(string * output +intent(out)+len(Noutput))
/**
 * \brief return a 'const string' as argument
 *
 */
// ----------------------------------------
// Result
// Requested: c_unknown_scalar_result_buf
// Match:     c_default
// ----------------------------------------
// Argument:  output
// Exact:     c_string_scalar_result_buf
void STR_get_const_string_as_arg_bufferify(char * output, int Noutput)
{
    // splicer begin function.get_const_string_as_arg_bufferify
    const std::string SHCXX_rv = getConstStringAsArg();
    if (SHCXX_rv.empty()) {
        ShroudStrCopy(output, Noutput, nullptr, 0);
    } else {
        ShroudStrCopy(output, Noutput, SHCXX_rv.data(),
            SHCXX_rv.size());
    }
    // splicer end function.get_const_string_as_arg_bufferify
}

// void getConstStringAlloc(const std::string * SHF_rv +context(DSHF_rv)+deref(allocatable)+intent(out))
// ----------------------------------------
// Result
// Requested: c_unknown_scalar_result_buf
// Match:     c_default
// ----------------------------------------
// Argument:  SHF_rv
// Exact:     c_string_scalar_result_buf_allocatable
void STR_get_const_string_alloc_bufferify(STR_SHROUD_array *DSHF_rv)
{
    // splicer begin function.get_const_string_alloc_bufferify
    std::string * SHCXX_rv = new std::string;
    *SHCXX_rv = getConstStringAlloc();
    ShroudStrToArray(DSHF_rv, SHCXX_rv, 1);
    // splicer end function.get_const_string_alloc_bufferify
}

// const string & getConstStringRefPure() +deref(allocatable)
/**
 * \brief return a 'const string&' as ALLOCATABLE character
 *
 */
// ----------------------------------------
// Result
// Requested: c_string_&_result
// Match:     c_string_result
// start STR_get_const_string_ref_pure
const char * STR_get_const_string_ref_pure()
{
    // splicer begin function.get_const_string_ref_pure
    const std::string & SHCXX_rv = getConstStringRefPure();
    const char * SHC_rv = SHCXX_rv.c_str();
    return SHC_rv;
    // splicer end function.get_const_string_ref_pure
}
// end STR_get_const_string_ref_pure

// void getConstStringRefPure(const string & SHF_rv +context(DSHF_rv)+deref(allocatable)+intent(out))
/**
 * \brief return a 'const string&' as ALLOCATABLE character
 *
 */
// ----------------------------------------
// Result
// Requested: c_unknown_scalar_result_buf
// Match:     c_default
// ----------------------------------------
// Argument:  SHF_rv
// Requested: c_string_&_result_buf_allocatable
// Match:     c_string_result_buf_allocatable
// start STR_get_const_string_ref_pure_bufferify
void STR_get_const_string_ref_pure_bufferify(STR_SHROUD_array *DSHF_rv)
{
    // splicer begin function.get_const_string_ref_pure_bufferify
    const std::string & SHCXX_rv = getConstStringRefPure();
    ShroudStrToArray(DSHF_rv, &SHCXX_rv, 0);
    // splicer end function.get_const_string_ref_pure_bufferify
}
// end STR_get_const_string_ref_pure_bufferify

// const string & getConstStringRefLen() +deref(result_as_arg)+len(30)
/**
 * \brief return 'const string&' with fixed size (len=30)
 *
 * Since +len(30) is provided, the result of the function
 * will be copied directly into memory provided by Fortran.
 * The function will not be ALLOCATABLE.
 */
// ----------------------------------------
// Result
// Requested: c_string_&_result
// Match:     c_string_result
const char * STR_get_const_string_ref_len()
{
    // splicer begin function.get_const_string_ref_len
    const std::string & SHCXX_rv = getConstStringRefLen();
    // C_error_pattern
    if (SHCXX_rv.empty()) {
        return NULL;
    }

    const char * SHC_rv = SHCXX_rv.c_str();
    return SHC_rv;
    // splicer end function.get_const_string_ref_len
}

// void getConstStringRefLen(string & SHF_rv +intent(out)+len(NSHF_rv)) +len(30)
/**
 * \brief return 'const string&' with fixed size (len=30)
 *
 * Since +len(30) is provided, the result of the function
 * will be copied directly into memory provided by Fortran.
 * The function will not be ALLOCATABLE.
 */
// ----------------------------------------
// Result
// Requested: c_unknown_scalar_result_buf
// Match:     c_default
// ----------------------------------------
// Argument:  SHF_rv
// Requested: c_string_&_result_buf
// Match:     c_string_result_buf
void STR_get_const_string_ref_len_bufferify(char * SHF_rv, int NSHF_rv)
{
    // splicer begin function.get_const_string_ref_len_bufferify
    const std::string & SHCXX_rv = getConstStringRefLen();
    if (SHCXX_rv.empty()) {
        ShroudStrCopy(SHF_rv, NSHF_rv, nullptr, 0);
    } else {
        ShroudStrCopy(SHF_rv, NSHF_rv, SHCXX_rv.data(),
            SHCXX_rv.size());
    }
    // splicer end function.get_const_string_ref_len_bufferify
}

// const string & getConstStringRefAsArg() +deref(result_as_arg)
/**
 * \brief return a 'const string&' as argument
 *
 * Pass an additional argument which wil be used as the return value.
 * The length of the output variable is declared by the caller.
 */
// ----------------------------------------
// Result
// Requested: c_string_&_result
// Match:     c_string_result
const char * STR_get_const_string_ref_as_arg()
{
    // splicer begin function.get_const_string_ref_as_arg
    const std::string & SHCXX_rv = getConstStringRefAsArg();
    // C_error_pattern
    if (SHCXX_rv.empty()) {
        return NULL;
    }

    const char * SHC_rv = SHCXX_rv.c_str();
    return SHC_rv;
    // splicer end function.get_const_string_ref_as_arg
}

// void getConstStringRefAsArg(string & output +intent(out)+len(Noutput))
/**
 * \brief return a 'const string&' as argument
 *
 * Pass an additional argument which wil be used as the return value.
 * The length of the output variable is declared by the caller.
 */
// ----------------------------------------
// Result
// Requested: c_unknown_scalar_result_buf
// Match:     c_default
// ----------------------------------------
// Argument:  output
// Requested: c_string_&_result_buf
// Match:     c_string_result_buf
void STR_get_const_string_ref_as_arg_bufferify(char * output,
    int Noutput)
{
    // splicer begin function.get_const_string_ref_as_arg_bufferify
    const std::string & SHCXX_rv = getConstStringRefAsArg();
    if (SHCXX_rv.empty()) {
        ShroudStrCopy(output, Noutput, nullptr, 0);
    } else {
        ShroudStrCopy(output, Noutput, SHCXX_rv.data(),
            SHCXX_rv.size());
    }
    // splicer end function.get_const_string_ref_as_arg_bufferify
}

// const string & getConstStringRefLenEmpty() +deref(result_as_arg)+len(30)
/**
 * \brief Test returning empty string reference
 *
 */
// ----------------------------------------
// Result
// Requested: c_string_&_result
// Match:     c_string_result
const char * STR_get_const_string_ref_len_empty()
{
    // splicer begin function.get_const_string_ref_len_empty
    const std::string & SHCXX_rv = getConstStringRefLenEmpty();
    // C_error_pattern
    if (SHCXX_rv.empty()) {
        return NULL;
    }

    const char * SHC_rv = SHCXX_rv.c_str();
    return SHC_rv;
    // splicer end function.get_const_string_ref_len_empty
}

// void getConstStringRefLenEmpty(string & SHF_rv +intent(out)+len(NSHF_rv)) +len(30)
/**
 * \brief Test returning empty string reference
 *
 */
// ----------------------------------------
// Result
// Requested: c_unknown_scalar_result_buf
// Match:     c_default
// ----------------------------------------
// Argument:  SHF_rv
// Requested: c_string_&_result_buf
// Match:     c_string_result_buf
void STR_get_const_string_ref_len_empty_bufferify(char * SHF_rv,
    int NSHF_rv)
{
    // splicer begin function.get_const_string_ref_len_empty_bufferify
    const std::string & SHCXX_rv = getConstStringRefLenEmpty();
    if (SHCXX_rv.empty()) {
        ShroudStrCopy(SHF_rv, NSHF_rv, nullptr, 0);
    } else {
        ShroudStrCopy(SHF_rv, NSHF_rv, SHCXX_rv.data(),
            SHCXX_rv.size());
    }
    // splicer end function.get_const_string_ref_len_empty_bufferify
}

// const std::string & getConstStringRefAlloc() +deref(allocatable)
// ----------------------------------------
// Result
// Requested: c_string_&_result
// Match:     c_string_result
const char * STR_get_const_string_ref_alloc()
{
    // splicer begin function.get_const_string_ref_alloc
    const std::string & SHCXX_rv = getConstStringRefAlloc();
    const char * SHC_rv = SHCXX_rv.c_str();
    return SHC_rv;
    // splicer end function.get_const_string_ref_alloc
}

// void getConstStringRefAlloc(const std::string & SHF_rv +context(DSHF_rv)+deref(allocatable)+intent(out))
// ----------------------------------------
// Result
// Requested: c_unknown_scalar_result_buf
// Match:     c_default
// ----------------------------------------
// Argument:  SHF_rv
// Requested: c_string_&_result_buf_allocatable
// Match:     c_string_result_buf_allocatable
void STR_get_const_string_ref_alloc_bufferify(STR_SHROUD_array *DSHF_rv)
{
    // splicer begin function.get_const_string_ref_alloc_bufferify
    const std::string & SHCXX_rv = getConstStringRefAlloc();
    ShroudStrToArray(DSHF_rv, &SHCXX_rv, 0);
    // splicer end function.get_const_string_ref_alloc_bufferify
}

// const string * getConstStringPtrLen() +deref(result_as_arg)+len(30)
/**
 * \brief return a 'const string *' as character(30)
 *
 * It is the caller's responsibility to release the string
 * created by the C++ library.
 * This is accomplished with C_finalize_buf which is possible
 * because +len(30) so the contents are copied before returning.
 */
// ----------------------------------------
// Result
// Requested: c_string_*_result
// Match:     c_string_result
const char * STR_get_const_string_ptr_len()
{
    // splicer begin function.get_const_string_ptr_len
    const std::string * SHCXX_rv = getConstStringPtrLen();
    const char * SHC_rv = SHCXX_rv->c_str();
    return SHC_rv;
    // splicer end function.get_const_string_ptr_len
}

// void getConstStringPtrLen(string * SHF_rv +intent(out)+len(NSHF_rv)) +len(30)
/**
 * \brief return a 'const string *' as character(30)
 *
 * It is the caller's responsibility to release the string
 * created by the C++ library.
 * This is accomplished with C_finalize_buf which is possible
 * because +len(30) so the contents are copied before returning.
 */
// ----------------------------------------
// Result
// Requested: c_unknown_scalar_result_buf
// Match:     c_default
// ----------------------------------------
// Argument:  SHF_rv
// Requested: c_string_*_result_buf
// Match:     c_string_result_buf
void STR_get_const_string_ptr_len_bufferify(char * SHF_rv, int NSHF_rv)
{
    // splicer begin function.get_const_string_ptr_len_bufferify
    const std::string * SHCXX_rv = getConstStringPtrLen();
    if (SHCXX_rv->empty()) {
        ShroudStrCopy(SHF_rv, NSHF_rv, nullptr, 0);
    } else {
        ShroudStrCopy(SHF_rv, NSHF_rv, SHCXX_rv->data(),
            SHCXX_rv->size());
    }
    {
        // final
        delete SHCXX_rv;
    }
    // splicer end function.get_const_string_ptr_len_bufferify
}

// const std::string * getConstStringPtrAlloc() +deref(allocatable)+owner(library)
// ----------------------------------------
// Result
// Requested: c_string_*_result
// Match:     c_string_result
const char * STR_get_const_string_ptr_alloc()
{
    // splicer begin function.get_const_string_ptr_alloc
    const std::string * SHCXX_rv = getConstStringPtrAlloc();
    const char * SHC_rv = SHCXX_rv->c_str();
    return SHC_rv;
    // splicer end function.get_const_string_ptr_alloc
}

// void getConstStringPtrAlloc(const std::string * SHF_rv +context(DSHF_rv)+deref(allocatable)+intent(out)+owner(library))
// ----------------------------------------
// Result
// Requested: c_unknown_scalar_result_buf
// Match:     c_default
// ----------------------------------------
// Argument:  SHF_rv
// Requested: c_string_*_result_buf_allocatable
// Match:     c_string_result_buf_allocatable
void STR_get_const_string_ptr_alloc_bufferify(STR_SHROUD_array *DSHF_rv)
{
    // splicer begin function.get_const_string_ptr_alloc_bufferify
    const std::string * SHCXX_rv = getConstStringPtrAlloc();
    ShroudStrToArray(DSHF_rv, SHCXX_rv, 0);
    // splicer end function.get_const_string_ptr_alloc_bufferify
}

// const std::string * getConstStringPtrOwnsAlloc() +deref(allocatable)+owner(caller)
/**
 * It is the caller's responsibility to release the string
 * created by the C++ library.
 * This is accomplished +owner(caller) which sets idtor.
 * The contents are copied by Fortran so they must outlast
 * the return from the C wrapper.
 */
// ----------------------------------------
// Result
// Requested: c_string_*_result
// Match:     c_string_result
const char * STR_get_const_string_ptr_owns_alloc()
{
    // splicer begin function.get_const_string_ptr_owns_alloc
    const std::string * SHCXX_rv = getConstStringPtrOwnsAlloc();
    const char * SHC_rv = SHCXX_rv->c_str();
    return SHC_rv;
    // splicer end function.get_const_string_ptr_owns_alloc
}

// void getConstStringPtrOwnsAlloc(const std::string * SHF_rv +context(DSHF_rv)+deref(allocatable)+intent(out)+owner(caller))
/**
 * It is the caller's responsibility to release the string
 * created by the C++ library.
 * This is accomplished +owner(caller) which sets idtor.
 * The contents are copied by Fortran so they must outlast
 * the return from the C wrapper.
 */
// ----------------------------------------
// Result
// Requested: c_unknown_scalar_result_buf
// Match:     c_default
// ----------------------------------------
// Argument:  SHF_rv
// Requested: c_string_*_result_buf_allocatable
// Match:     c_string_result_buf_allocatable
void STR_get_const_string_ptr_owns_alloc_bufferify(
    STR_SHROUD_array *DSHF_rv)
{
    // splicer begin function.get_const_string_ptr_owns_alloc_bufferify
    const std::string * SHCXX_rv = getConstStringPtrOwnsAlloc();
    ShroudStrToArray(DSHF_rv, SHCXX_rv, 2);
    // splicer end function.get_const_string_ptr_owns_alloc_bufferify
}

// const std::string * getConstStringPtrOwnsAllocPattern() +deref(allocatable)+free_pattern(C_string_free)+owner(caller)
/**
 * Similar to getConstStringPtrOwnsAlloc, but uses pattern to release memory.
 */
// ----------------------------------------
// Result
// Requested: c_string_*_result
// Match:     c_string_result
const char * STR_get_const_string_ptr_owns_alloc_pattern()
{
    // splicer begin function.get_const_string_ptr_owns_alloc_pattern
    const std::string * SHCXX_rv = getConstStringPtrOwnsAllocPattern();
    const char * SHC_rv = SHCXX_rv->c_str();
    return SHC_rv;
    // splicer end function.get_const_string_ptr_owns_alloc_pattern
}

// void getConstStringPtrOwnsAllocPattern(const std::string * SHF_rv +context(DSHF_rv)+deref(allocatable)+free_pattern(C_string_free)+intent(out)+owner(caller))
/**
 * Similar to getConstStringPtrOwnsAlloc, but uses pattern to release memory.
 */
// ----------------------------------------
// Result
// Requested: c_unknown_scalar_result_buf
// Match:     c_default
// ----------------------------------------
// Argument:  SHF_rv
// Requested: c_string_*_result_buf_allocatable
// Match:     c_string_result_buf_allocatable
void STR_get_const_string_ptr_owns_alloc_pattern_bufferify(
    STR_SHROUD_array *DSHF_rv)
{
    // splicer begin function.get_const_string_ptr_owns_alloc_pattern_bufferify
    const std::string * SHCXX_rv = getConstStringPtrOwnsAllocPattern();
    ShroudStrToArray(DSHF_rv, SHCXX_rv, 3);
    // splicer end function.get_const_string_ptr_owns_alloc_pattern_bufferify
}

// void acceptStringConstReference(const std::string & arg1 +intent(in))
/**
 * \brief Accept a const string reference
 *
 * Save contents of arg1.
 * arg1 is assumed to be intent(IN) since it is const
 * Will copy in.
 */
// ----------------------------------------
// Result
// Requested: c
// Match:     c_default
// ----------------------------------------
// Argument:  arg1
// Requested: c_string_&_in
// Match:     c_string_in
void STR_accept_string_const_reference(const char * arg1)
{
    // splicer begin function.accept_string_const_reference
    const std::string SHCXX_arg1(arg1);
    acceptStringConstReference(SHCXX_arg1);
    // splicer end function.accept_string_const_reference
}

// void acceptStringConstReference(const std::string & arg1 +intent(in)+len_trim(Larg1))
/**
 * \brief Accept a const string reference
 *
 * Save contents of arg1.
 * arg1 is assumed to be intent(IN) since it is const
 * Will copy in.
 */
// ----------------------------------------
// Result
// Requested: c
// Match:     c_default
// ----------------------------------------
// Argument:  arg1
// Requested: c_string_&_in_buf
// Match:     c_string_in_buf
void STR_accept_string_const_reference_bufferify(const char * arg1,
    int Larg1)
{
    // splicer begin function.accept_string_const_reference_bufferify
    const std::string SHCXX_arg1(arg1, Larg1);
    acceptStringConstReference(SHCXX_arg1);
    // splicer end function.accept_string_const_reference_bufferify
}

// void acceptStringReferenceOut(std::string & arg1 +intent(out))
/**
 * \brief Accept a string reference
 *
 * Set out to a constant string.
 * arg1 is intent(OUT)
 * Must copy out.
 */
// ----------------------------------------
// Result
// Requested: c
// Match:     c_default
// ----------------------------------------
// Argument:  arg1
// Requested: c_string_&_out
// Match:     c_string_out
void STR_accept_string_reference_out(char * arg1)
{
    // splicer begin function.accept_string_reference_out
    std::string SHCXX_arg1;
    acceptStringReferenceOut(SHCXX_arg1);
    strcpy(arg1, SHCXX_arg1.c_str());
    // splicer end function.accept_string_reference_out
}

// void acceptStringReferenceOut(std::string & arg1 +intent(out)+len(Narg1))
/**
 * \brief Accept a string reference
 *
 * Set out to a constant string.
 * arg1 is intent(OUT)
 * Must copy out.
 */
// ----------------------------------------
// Result
// Requested: c
// Match:     c_default
// ----------------------------------------
// Argument:  arg1
// Requested: c_string_&_out_buf
// Match:     c_string_out_buf
void STR_accept_string_reference_out_bufferify(char * arg1, int Narg1)
{
    // splicer begin function.accept_string_reference_out_bufferify
    std::string SHCXX_arg1;
    acceptStringReferenceOut(SHCXX_arg1);
    ShroudStrCopy(arg1, Narg1, SHCXX_arg1.data(), SHCXX_arg1.size());
    // splicer end function.accept_string_reference_out_bufferify
}

// void acceptStringReference(std::string & arg1 +intent(inout))
/**
 * \brief Accept a string reference
 *
 * Append "dog" to the end of arg1.
 * arg1 is assumed to be intent(INOUT)
 * Must copy in and copy out.
 */
// ----------------------------------------
// Result
// Requested: c
// Match:     c_default
// ----------------------------------------
// Argument:  arg1
// Requested: c_string_&_inout
// Match:     c_string_inout
// start STR_accept_string_reference
void STR_accept_string_reference(char * arg1)
{
    // splicer begin function.accept_string_reference
    std::string SHCXX_arg1(arg1);
    acceptStringReference(SHCXX_arg1);
    strcpy(arg1, SHCXX_arg1.c_str());
    // splicer end function.accept_string_reference
}
// end STR_accept_string_reference

// void acceptStringReference(std::string & arg1 +intent(inout)+len(Narg1)+len_trim(Larg1))
/**
 * \brief Accept a string reference
 *
 * Append "dog" to the end of arg1.
 * arg1 is assumed to be intent(INOUT)
 * Must copy in and copy out.
 */
// ----------------------------------------
// Result
// Requested: c
// Match:     c_default
// ----------------------------------------
// Argument:  arg1
// Requested: c_string_&_inout_buf
// Match:     c_string_inout_buf
// start STR_accept_string_reference_bufferify
void STR_accept_string_reference_bufferify(char * arg1, int Larg1,
    int Narg1)
{
    // splicer begin function.accept_string_reference_bufferify
    std::string SHCXX_arg1(arg1, Larg1);
    acceptStringReference(SHCXX_arg1);
    ShroudStrCopy(arg1, Narg1, SHCXX_arg1.data(), SHCXX_arg1.size());
    // splicer end function.accept_string_reference_bufferify
}
// end STR_accept_string_reference_bufferify

// void acceptStringPointer(std::string * arg1 +intent(inout))
/**
 * \brief Accept a string pointer
 *
 */
// ----------------------------------------
// Result
// Requested: c
// Match:     c_default
// ----------------------------------------
// Argument:  arg1
// Requested: c_string_*_inout
// Match:     c_string_inout
void STR_accept_string_pointer(char * arg1)
{
    // splicer begin function.accept_string_pointer
    std::string SHCXX_arg1(arg1);
    acceptStringPointer(&SHCXX_arg1);
    strcpy(arg1, SHCXX_arg1.c_str());
    // splicer end function.accept_string_pointer
}

// void acceptStringPointer(std::string * arg1 +intent(inout)+len(Narg1)+len_trim(Larg1))
/**
 * \brief Accept a string pointer
 *
 */
// ----------------------------------------
// Result
// Requested: c
// Match:     c_default
// ----------------------------------------
// Argument:  arg1
// Requested: c_string_*_inout_buf
// Match:     c_string_inout_buf
void STR_accept_string_pointer_bufferify(char * arg1, int Larg1,
    int Narg1)
{
    // splicer begin function.accept_string_pointer_bufferify
    std::string SHCXX_arg1(arg1, Larg1);
    acceptStringPointer(&SHCXX_arg1);
    ShroudStrCopy(arg1, Narg1, SHCXX_arg1.data(), SHCXX_arg1.size());
    // splicer end function.accept_string_pointer_bufferify
}

// void explicit1(char * name +intent(in)+len_trim(AAlen))
// ----------------------------------------
// Result
// Requested: c
// Match:     c_default
// ----------------------------------------
// Argument:  name
// Requested: c_char_*_in
// Match:     c_default
void STR_explicit1(char * name)
{
    // splicer begin function.explicit1
    explicit1(name);
    // splicer end function.explicit1
}

// void explicit2(char * name +intent(out)+len(AAtrim))
// ----------------------------------------
// Result
// Requested: c
// Match:     c_default
// ----------------------------------------
// Argument:  name
// Requested: c_char_*_out
// Match:     c_default
void STR_explicit2(char * name)
{
    // splicer begin function.explicit2
    explicit2(name);
    // splicer end function.explicit2
}

// void explicit2(char * name +intent(out)+len(AAtrim))
// ----------------------------------------
// Result
// Requested: c
// Match:     c_default
// ----------------------------------------
// Argument:  name
// Requested: c_char_*_out_buf
// Match:     c_char_out_buf
void STR_explicit2_bufferify(char * name, int AAtrim)
{
    // splicer begin function.explicit2_bufferify
    explicit2(name);
    ShroudStrBlankFill(name, AAtrim);
    // splicer end function.explicit2_bufferify
}

// void CreturnChar(char * SHF_rv +intent(out)+len(NSHF_rv))
/**
 * \brief return a char argument (non-pointer), extern "C"
 *
 */
// ----------------------------------------
// Result
// Requested: c_unknown_scalar_result_buf
// Match:     c_default
// ----------------------------------------
// Argument:  SHF_rv
// Requested: c_schar_scalar_result_buf
// Match:     c_schar_result_buf
void STR_creturn_char_bufferify(char * SHF_rv, int NSHF_rv)
{
    // splicer begin function.creturn_char_bufferify
    char SHC_rv = CreturnChar();
    std::memset(SHF_rv, ' ', NSHF_rv);
    SHF_rv[0] = SHC_rv;
    // splicer end function.creturn_char_bufferify
}

// void CpassCharPtr(char * dest +intent(out)+len(Ndest), const char * src +intent(in))
/**
 * \brief strcpy like behavior
 *
 * dest is marked intent(OUT) to override the intent(INOUT) default
 * This avoid a copy-in on dest.
 * extern "C"
 */
// ----------------------------------------
// Result
// Requested: c
// Match:     c_default
// ----------------------------------------
// Argument:  dest
// Requested: c_char_*_out_buf
// Match:     c_char_out_buf
// ----------------------------------------
// Argument:  src
// Requested: c_char_*_in
// Match:     c_default
void STR_cpass_char_ptr_bufferify(char * dest, int Ndest,
    const char * src)
{
    // splicer begin function.cpass_char_ptr_bufferify
    CpassCharPtr(dest, src);
    ShroudStrBlankFill(dest, Ndest);
    // splicer end function.cpass_char_ptr_bufferify
}

// start release allocated memory
// Release library allocated memory.
void STR_SHROUD_memory_destructor(STR_SHROUD_capsule_data *cap)
{
    void *ptr = cap->addr;
    switch (cap->idtor) {
    case 0:   // --none--
    {
        // Nothing to delete
        break;
    }
    case 1:   // new_string
    {
        std::string *cxx_ptr = reinterpret_cast<std::string *>(ptr);
        delete cxx_ptr;
        break;
    }
    case 2:   // std::string
    {
        std::string *cxx_ptr = reinterpret_cast<std::string *>(ptr);
        delete cxx_ptr;
        break;
    }
    case 3:   // C_string_free
    {
        // Used with +free_pattern(C_string_free)
        std::string *cxx_ptr = reinterpret_cast<std::string *>(ptr);
        delete cxx_ptr;

        break;
    }
    default:
    {
        // Unexpected case in destructor
        break;
    }
    }
    cap->addr = nullptr;
    cap->idtor = 0;  // avoid deleting again
}
// end release allocated memory

}  // extern "C"
