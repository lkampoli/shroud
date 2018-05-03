// wrapvectors.cpp
// This is generated code, do not edit
// #######################################################################
// Copyright (c) 2017-2018, Lawrence Livermore National Security, LLC.
// Produced at the Lawrence Livermore National Laboratory
//
// LLNL-CODE-738041.
// All rights reserved.
//
// This file is part of Shroud.  For details, see
// https://github.com/LLNL/shroud. Please also read shroud/LICENSE.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are
// met:
//
// * Redistributions of source code must retain the above copyright
//   notice, this list of conditions and the disclaimer below.
//
// * Redistributions in binary form must reproduce the above copyright
//   notice, this list of conditions and the disclaimer (as noted below)
//   in the documentation and/or other materials provided with the
//   distribution.
//
// * Neither the name of the LLNS/LLNL nor the names of its contributors
//   may be used to endorse or promote products derived from this
//   software without specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
// "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
// LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
// A PARTICULAR PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL LAWRENCE
// LIVERMORE NATIONAL SECURITY, LLC, THE U.S. DEPARTMENT OF ENERGY OR
// CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
// EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
// PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
// PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
// LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
// NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
// SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
//
// #######################################################################
#include "wrapvectors.h"
#include <stdlib.h>
#include <string>
#include "vectors.hpp"

// splicer begin CXX_definitions
// splicer end CXX_definitions

extern "C" {


// Returns the length of character string a with length ls,
// ignoring any trailing blanks.
int ShroudLenTrim(const char *s, int ls) {
    int i;

    for (i = ls - 1; i >= 0; i--) {
        if (s[i] != ' ') {
            break;
        }
    }

    return i + 1;
}


void VEC_SHROUD_vector_copy_int(SHROUD_capsule_data *cap, int *c_var, 
    size_t c_var_size)
{
    std::vector<int> *cxx_var = reinterpret_cast<std::vector<int> *>
        (cap->addr);
    std::vector<int>::size_type
        i = 0,
        n = c_var_size;
    n = std::min(cxx_var->size(), n);
    for(; i < n; ++i) {
        c_var[i] = (*cxx_var)[i];
    }
}
// splicer begin C_definitions
// splicer end C_definitions

// int vector_sum(const std::vector<int> & arg +dimension(:)+intent(in)+size(Sarg))
// function_index=6
int VEC_vector_sum_bufferify(const int * arg, long Sarg)
{
// splicer begin function.vector_sum_bufferify
    const std::vector<int> SH_arg(arg, arg + Sarg);
    int SHC_rv = vector_sum(SH_arg);
    return SHC_rv;
// splicer end function.vector_sum_bufferify
}

// void vector_iota(std::vector<int> & arg +capsule(Carg)+context(Darg)+dimension(:)+intent(out))
// function_index=7
void VEC_vector_iota_bufferify(SHROUD_capsule_data *Carg,
    SHROUD_vector_context *Darg)
{
// splicer begin function.vector_iota_bufferify
    std::vector<int> *SH_arg = new std::vector<int>;
    Carg->addr = static_cast<void *>(SH_arg);
    Carg->idtor = 1;  // index of destructor
    Carg->refcount = 1;     // reference count
    vector_iota(*SH_arg);
    Darg->addr = SH_arg->empty() ? NULL : &SH_arg->front();
    Darg->size = SH_arg->size();
    return;
// splicer end function.vector_iota_bufferify
}

// void vector_increment(std::vector<int> & arg +capsule(Carg)+context(Darg)+dimension(:)+intent(inout)+size(Sarg))
// function_index=8
void VEC_vector_increment_bufferify(int * arg, long Sarg,
    SHROUD_capsule_data *Carg, SHROUD_vector_context *Darg)
{
// splicer begin function.vector_increment_bufferify
    std::vector<int> *SH_arg = new std::vector<int>(arg, arg + Sarg);
    Carg->addr = static_cast<void *>(SH_arg);
    Carg->idtor = 0;        // index of destructor
    Carg->refcount = 1;     // reference count
    vector_increment(*SH_arg);
    Darg->addr = SH_arg->empty() ? NULL : &SH_arg->front();
    Darg->size = SH_arg->size();
    return;
// splicer end function.vector_increment_bufferify
}

// int vector_string_count(const std::vector<std::string> & arg +dimension(:)+intent(in)+len(Narg)+size(Sarg))
// function_index=9
/**
 * \brief count number of underscore in vector of strings
 *
 */
int VEC_vector_string_count_bufferify(const char * arg, long Sarg,
    int Narg)
{
// splicer begin function.vector_string_count_bufferify
    std::vector<std::string> SH_arg;
    {
          const char * BBB = arg;
          std::vector<std::string>::size_type
            SHT_i = 0,
            SHT_n = Sarg;
        for(; SHT_i < SHT_n; SHT_i++) {
            SH_arg.push_back(std::string(BBB,ShroudLenTrim(BBB, Narg)));
            BBB += Narg;
        }
    }
    int SHC_rv = vector_string_count(SH_arg);
    return SHC_rv;
// splicer end function.vector_string_count_bufferify
}

// Release C++ allocated memory if refcount reaches 0.
void VEC_SHROUD_array_destructor_function
    (SHROUD_capsule_data *cap, bool gc)
{
    --cap->refcount;
    if (cap->refcount > 0) {
        return;
    }
    void *ptr = cap->addr;
    switch (cap->idtor) {
    case 0:
    {
        // Nothing to delete
        break;
    }
    case 1:
    {
        std::vector<int> *cxx_ptr = 
            reinterpret_cast<std::vector<int> *>(ptr);
        delete cxx_ptr;
        break;
    }
    default:
    {
        // Unexpected case in destructor
        break;
    }
    }
    if (gc) {
        free(cap);
    } else {
        cap->addr = NULL;
        cap->idtor = 0;  // avoid deleting again
    }
}

}  // extern "C"
