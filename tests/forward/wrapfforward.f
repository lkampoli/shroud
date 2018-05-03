! wrapfforward.f
! This is generated code, do not edit
! #######################################################################
! Copyright (c) 2018, Lawrence Livermore National Security, LLC.
! Produced at the Lawrence Livermore National Laboratory
!
! LLNL-CODE-738041.
! All rights reserved.
!
! This file is part of Shroud.  For details, see
! https://github.com/LLNL/shroud. Please also read shroud/LICENSE.
!
! Redistribution and use in source and binary forms, with or without
! modification, are permitted provided that the following conditions are
! met:
!
! * Redistributions of source code must retain the above copyright
!   notice, this list of conditions and the disclaimer below.
!
! * Redistributions in binary form must reproduce the above copyright
!   notice, this list of conditions and the disclaimer (as noted below)
!   in the documentation and/or other materials provided with the
!   distribution.
!
! * Neither the name of the LLNS/LLNL nor the names of its contributors
!   may be used to endorse or promote products derived from this
!   software without specific prior written permission.
!
! THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
! "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
! LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
! A PARTICULAR PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL LAWRENCE
! LIVERMORE NATIONAL SECURITY, LLC, THE U.S. DEPARTMENT OF ENERGY OR
! CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
! EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
! PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
! PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
! LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
! NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
! SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
!
! #######################################################################
!>
!! \file wrapfforward.f
!! \brief Shroud generated wrapper for forward library
!<
! splicer begin file_top
! splicer end file_top
module forward_mod
    use iso_c_binding, only : C_INT, C_NULL_PTR, C_PTR
    ! splicer begin module_use
    ! splicer end module_use
    implicit none

    ! splicer begin module_top
    ! splicer end module_top

    type, bind(C) :: SHROUD_capsule_data
        type(C_PTR) :: addr = C_NULL_PTR  ! address of C++ memory
        integer(C_INT) :: idtor = 0       ! index of destructor
        integer(C_INT) :: refcount = 0    ! reference count
    end type SHROUD_capsule_data

    ! splicer begin class.Class2.module_top
    ! splicer end class.Class2.module_top

    type class2
        type(C_PTR), private :: cxxptr = C_NULL_PTR
        type(SHROUD_capsule_data), pointer :: cxxmem => null()
        ! splicer begin class.Class2.component_part
        ! splicer end class.Class2.component_part
    contains
        procedure :: dtor => class2_dtor
        procedure :: func1 => class2_func1
        procedure :: get_instance => class2_get_instance
        procedure :: set_instance => class2_set_instance
        procedure :: associated => class2_associated
        procedure :: class2_assign
        generic :: assignment(=) => class2_assign
        final :: class2_final
        ! splicer begin class.Class2.type_bound_procedure_part
        ! splicer end class.Class2.type_bound_procedure_part
    end type class2

    interface operator (.eq.)
        module procedure class2_eq
    end interface

    interface operator (.ne.)
        module procedure class2_ne
    end interface

    interface

        function c_class2_ctor() &
                result(SHT_rv) &
                bind(C, name="FOR_class2_ctor")
            use iso_c_binding, only : C_PTR
            implicit none
            type(C_PTR) :: SHT_rv
        end function c_class2_ctor

        subroutine c_class2_dtor(self) &
                bind(C, name="FOR_class2_dtor")
            use iso_c_binding, only : C_PTR
            implicit none
            type(C_PTR), value, intent(IN) :: self
        end subroutine c_class2_dtor

        subroutine c_class2_func1(self, arg) &
                bind(C, name="FOR_class2_func1")
            use iso_c_binding, only : C_PTR
            implicit none
            type(C_PTR), value, intent(IN) :: self
            type(C_PTR), value, intent(IN) :: arg
        end subroutine c_class2_func1

        ! splicer begin class.Class2.additional_interfaces
        ! splicer end class.Class2.additional_interfaces
    end interface

contains

    ! Class2()
    ! function_index=0
    function class2_ctor() &
            result(SHT_rv)
        use iso_c_binding, only : c_f_pointer
        type(class2) :: SHT_rv
        ! splicer begin class.Class2.method.ctor
        SHT_rv%cxxptr = c_class2_ctor()
        call c_f_pointer(SHT_rv%cxxptr, SHT_rv%cxxmem)
        ! splicer end class.Class2.method.ctor
    end function class2_ctor

    ! ~Class2()
    ! function_index=1
    subroutine class2_dtor(obj)
        use iso_c_binding, only : C_NULL_PTR
        class(class2) :: obj
        ! splicer begin class.Class2.method.dtor
        call c_class2_dtor(obj%cxxptr)
        obj%cxxptr = C_NULL_PTR
        nullify(obj%cxxmem)
        ! splicer end class.Class2.method.dtor
    end subroutine class2_dtor

    ! void func1(Class1 * arg +intent(in)+value)
    ! function_index=2
    subroutine class2_func1(obj, arg)
        use tutorial_mod, only : class1
        class(class2) :: obj
        type(class1), value, intent(IN) :: arg
        ! splicer begin class.Class2.method.func1
        call c_class2_func1(obj%cxxptr, arg%cxxptr)
        ! splicer end class.Class2.method.func1
    end subroutine class2_func1

    ! Return pointer to C++ memory if allocated, else C_NULL_PTR.
    function class2_get_instance(obj) result (cxxptr)
        use iso_c_binding, only: c_associated, C_NULL_PTR, C_PTR
        class(class2), intent(IN) :: obj
        type(C_PTR) :: cxxptr
        if (c_associated(obj%cxxptr)) then
            cxxptr = obj%cxxmem%addr
        else
            cxxptr = C_NULL_PTR
        endif
    end function class2_get_instance

    subroutine class2_set_instance(obj, cxxmem)
        use iso_c_binding, only: C_PTR
        class(class2), intent(INOUT) :: obj
        type(C_PTR), intent(IN) :: cxxmem
        obj%cxxmem%addr = cxxmem
        obj%cxxmem%idtor = 0
    end subroutine class2_set_instance

    function class2_associated(obj) result (rv)
        use iso_c_binding, only: c_associated
        class(class2), intent(IN) :: obj
        logical rv
        rv = c_associated(obj%cxxmem%addr)
    end function class2_associated

    subroutine class2_assign(lhs, rhs)
        use iso_c_binding, only : c_associated, c_f_pointer
        class(class2), intent(INOUT) :: lhs
        class(class2), intent(IN) :: rhs

        lhs%cxxptr = rhs%cxxptr
        if (c_associated(lhs%cxxptr)) then
            call c_f_pointer(lhs%cxxptr, lhs%cxxmem)
            lhs%cxxmem%refcount = lhs%cxxmem%refcount + 1
        else
            nullify(lhs%cxxmem)
        endif
    end subroutine class2_assign

    subroutine class2_final(obj)
        use iso_c_binding, only : c_associated, C_BOOL, C_NULL_PTR
        type(class2), intent(INOUT) :: obj
        interface
            subroutine array_destructor(ptr, gc) &
                bind(C, name="FOR_SHROUD_array_destructor_function")
                use iso_c_binding, only : C_BOOL, C_INT, C_PTR
                implicit none
                type(C_PTR), value, intent(IN) :: ptr
                logical(C_BOOL), value, intent(IN) :: gc
            end subroutine array_destructor
        end interface
        if (c_associated(obj%cxxptr)) then
            call array_destructor(obj%cxxptr, .true._C_BOOL)
            obj%cxxptr = C_NULL_PTR
            nullify(obj%cxxmem)
        endif
    end subroutine class2_final

    ! splicer begin class.Class2.additional_functions
    ! splicer end class.Class2.additional_functions

    function class2_eq(a,b) result (rv)
        use iso_c_binding, only: c_associated
        type(class2), intent(IN) ::a,b
        logical :: rv
        if (c_associated(a%cxxmem%addr, b%cxxmem%addr)) then
            rv = .true.
        else
            rv = .false.
        endif
    end function class2_eq

    function class2_ne(a,b) result (rv)
        use iso_c_binding, only: c_associated
        type(class2), intent(IN) ::a,b
        logical :: rv
        if (.not. c_associated(a%cxxmem%addr, b%cxxmem%addr)) then
            rv = .true.
        else
            rv = .false.
        endif
    end function class2_ne

end module forward_mod
