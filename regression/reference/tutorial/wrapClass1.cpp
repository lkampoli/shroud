// wrapClass1.cpp
// This is generated code, do not edit
// #######################################################################
// Copyright (c) 2017-2019, Lawrence Livermore National Security, LLC.
//
// Produced at the Lawrence Livermore National Laboratory
//
// LLNL-CODE-738041.
//
// All rights reserved.
//
// This file is part of Shroud.
//
// For details about use and distribution, please read LICENSE.
//
// #######################################################################
#include "wrapClass1.h"
#include <stdlib.h>
#include <string>
#include "tutorial.hpp"

// splicer begin class.Class1.CXX_definitions
// splicer end class.Class1.CXX_definitions

extern "C" {

// splicer begin class.Class1.C_definitions
// splicer end class.Class1.C_definitions

// Class1() +name(new)
TUT_class1 * TUT_class1_new_default(TUT_class1 * SHC_rv)
{
// splicer begin class.Class1.method.new_default
    tutorial::Class1 *SHCXX_rv = new tutorial::Class1();
    SHC_rv->addr = static_cast<void *>(SHCXX_rv);
    SHC_rv->idtor = 0;
    return SHC_rv;
// splicer end class.Class1.method.new_default
}

// Class1(int flag +intent(in)+value) +name(new)
TUT_class1 * TUT_class1_new_flag(int flag, TUT_class1 * SHC_rv)
{
// splicer begin class.Class1.method.new_flag
    tutorial::Class1 *SHCXX_rv = new tutorial::Class1(flag);
    SHC_rv->addr = static_cast<void *>(SHCXX_rv);
    SHC_rv->idtor = 0;
    return SHC_rv;
// splicer end class.Class1.method.new_flag
}

// ~Class1() +name(delete)
void TUT_class1_delete(TUT_class1 * self)
{
// splicer begin class.Class1.method.delete
    tutorial::Class1 *SH_this =
        static_cast<tutorial::Class1 *>(self->addr);
    delete SH_this;
    self->addr = NULL;
    return;
// splicer end class.Class1.method.delete
}

// int Method1()
/**
 * \brief returns the value of flag member
 *
 */
int TUT_class1_method1(TUT_class1 * self)
{
// splicer begin class.Class1.method.method1
    tutorial::Class1 *SH_this =
        static_cast<tutorial::Class1 *>(self->addr);
    int SHC_rv = SH_this->Method1();
    return SHC_rv;
// splicer end class.Class1.method.method1
}

// bool equivalent(const Class1 & obj2 +intent(in)) const
/**
 * \brief Pass in reference to instance
 *
 */
bool TUT_class1_equivalent(const TUT_class1 * self,
    const TUT_class1 * obj2)
{
// splicer begin class.Class1.method.equivalent
    const tutorial::Class1 *SH_this =
        static_cast<const tutorial::Class1 *>(self->addr);
    const tutorial::Class1 * SHCXX_obj2 =
        static_cast<const tutorial::Class1 *>(obj2->addr);
    bool SHC_rv = SH_this->equivalent(*SHCXX_obj2);
    return SHC_rv;
// splicer end class.Class1.method.equivalent
}

// Class1 * returnThis()
/**
 * \brief Return pointer to 'this' to allow chaining calls
 *
 */
void TUT_class1_return_this(TUT_class1 * self)
{
// splicer begin class.Class1.method.return_this
    tutorial::Class1 *SH_this =
        static_cast<tutorial::Class1 *>(self->addr);
    SH_this->returnThis();
    return;
// splicer end class.Class1.method.return_this
}

// Class1 * returnThisBuffer(std::string & name +intent(in), bool flag +intent(in)+value)
/**
 * \brief Return pointer to 'this' to allow chaining calls
 *
 */
TUT_class1 * TUT_class1_return_this_buffer(TUT_class1 * self,
    char * name, bool flag, TUT_class1 * SHC_rv)
{
// splicer begin class.Class1.method.return_this_buffer
    tutorial::Class1 *SH_this =
        static_cast<tutorial::Class1 *>(self->addr);
    std::string SH_name(name);
    tutorial::Class1 * SHCXX_rv = SH_this->returnThisBuffer(SH_name,
        flag);
    SHC_rv->addr = static_cast<void *>(SHCXX_rv);
    SHC_rv->idtor = 0;
    return SHC_rv;
// splicer end class.Class1.method.return_this_buffer
}

// Class1 * returnThisBuffer(std::string & name +intent(in)+len_trim(Lname), bool flag +intent(in)+value)
/**
 * \brief Return pointer to 'this' to allow chaining calls
 *
 */
TUT_class1 * TUT_class1_return_this_buffer_bufferify(TUT_class1 * self,
    char * name, int Lname, bool flag, TUT_class1 * SHC_rv)
{
// splicer begin class.Class1.method.return_this_buffer_bufferify
    tutorial::Class1 *SH_this =
        static_cast<tutorial::Class1 *>(self->addr);
    std::string SH_name(name, Lname);
    tutorial::Class1 * SHCXX_rv = SH_this->returnThisBuffer(SH_name,
        flag);
    SHC_rv->addr = static_cast<void *>(SHCXX_rv);
    SHC_rv->idtor = 0;
    return SHC_rv;
// splicer end class.Class1.method.return_this_buffer_bufferify
}

// Class1 * getclass3() const
/**
 * \brief Test const method
 *
 */
TUT_class1 * TUT_class1_getclass3(const TUT_class1 * self,
    TUT_class1 * SHC_rv)
{
// splicer begin class.Class1.method.getclass3
    const tutorial::Class1 *SH_this =
        static_cast<const tutorial::Class1 *>(self->addr);
    tutorial::Class1 * SHCXX_rv = SH_this->getclass3();
    SHC_rv->addr = static_cast<void *>(SHCXX_rv);
    SHC_rv->idtor = 0;
    return SHC_rv;
// splicer end class.Class1.method.getclass3
}

// DIRECTION directionFunc(DIRECTION arg +intent(in)+value)
int TUT_class1_direction_func(TUT_class1 * self, int arg)
{
// splicer begin class.Class1.method.direction_func
    tutorial::Class1 *SH_this =
        static_cast<tutorial::Class1 *>(self->addr);
    tutorial::Class1::DIRECTION SHCXX_arg =
        static_cast<tutorial::Class1::DIRECTION>(arg);
    tutorial::Class1::DIRECTION SHCXX_rv = SH_this->directionFunc(
        SHCXX_arg);
    int SHC_rv = static_cast<int>(SHCXX_rv);
    return SHC_rv;
// splicer end class.Class1.method.direction_func
}

// int getM_flag()
int TUT_class1_get_m_flag(TUT_class1 * self)
{
// splicer begin class.Class1.method.get_m_flag
    tutorial::Class1 *SH_this =
        static_cast<tutorial::Class1 *>(self->addr);
    return SH_this->m_flag;
// splicer end class.Class1.method.get_m_flag
}

// int getTest()
int TUT_class1_get_test(TUT_class1 * self)
{
// splicer begin class.Class1.method.get_test
    tutorial::Class1 *SH_this =
        static_cast<tutorial::Class1 *>(self->addr);
    return SH_this->m_test;
// splicer end class.Class1.method.get_test
}

// void setTest(int val +intent(in)+value)
void TUT_class1_set_test(TUT_class1 * self, int val)
{
// splicer begin class.Class1.method.set_test
    tutorial::Class1 *SH_this =
        static_cast<tutorial::Class1 *>(self->addr);
    SH_this->m_test = val;
    return;
// splicer end class.Class1.method.set_test
}

}  // extern "C"