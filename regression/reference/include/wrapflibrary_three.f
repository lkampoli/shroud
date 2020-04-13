! wrapflibrary_three.f
! This file is generated by Shroud 0.11.0. Do not edit.
! Copyright (c) 2017-2020, Lawrence Livermore National Security, LLC and
! other Shroud Project Developers.
! See the top-level COPYRIGHT file for details.
!
! SPDX-License-Identifier: (BSD-3-Clause)
!
!>
!! \file wrapflibrary_three.f
!! \brief Shroud generated wrapper for three namespace
!<
module library_three_mod
    use iso_c_binding, only : C_INT, C_NULL_PTR, C_PTR
    implicit none


    type, bind(C) :: SHROUD_class1_capsule
        type(C_PTR) :: addr = C_NULL_PTR  ! address of C++ memory
        integer(C_INT) :: idtor = 0       ! index of destructor
    end type SHROUD_class1_capsule

    type class1
        type(SHROUD_class1_capsule) :: cxxmem
    contains
        procedure :: method1 => class1_method1
        procedure :: get_instance => class1_get_instance
        procedure :: set_instance => class1_set_instance
        procedure :: associated => class1_associated
    end type class1

    interface operator (.eq.)
        module procedure class1_eq
    end interface

    interface operator (.ne.)
        module procedure class1_ne
    end interface

    interface

        ! ----------------------------------------
        ! Result
        ! Requested: c_unknown_scalar_result
        ! Match:     c_default
        ! ----------------------------------------
        ! Argument:  arg1
        ! Requested: c_native_scalar_in
        ! Match:     c_default
        subroutine c_class1_method1(self, arg1) &
                bind(C, name="LIB_three_Class1_method1")
            use iso_c_binding, only : C_INT
            import :: SHROUD_class1_capsule
            implicit none
            type(SHROUD_class1_capsule), intent(IN) :: self
            integer(C_INT), value, intent(IN) :: arg1
        end subroutine c_class1_method1


    end interface

contains

    ! void method1(CustomType arg1 +intent(in)+value)
    ! ----------------------------------------
    ! Result
    ! Requested: f_subroutine
    ! Match:     f_default
    ! Requested: c
    ! Match:     c_default
    ! ----------------------------------------
    ! Argument:  arg1
    ! Requested: f_native_scalar_in
    ! Match:     f_default
    ! Requested: c_native_scalar_in
    ! Match:     c_default
    subroutine class1_method1(obj, arg1)
        use iso_c_binding, only : C_INT
        class(class1) :: obj
        integer(C_INT), value, intent(IN) :: arg1
        call c_class1_method1(obj%cxxmem, arg1)
    end subroutine class1_method1

    ! Return pointer to C++ memory.
    function class1_get_instance(obj) result (cxxptr)
        use iso_c_binding, only: C_PTR
        class(class1), intent(IN) :: obj
        type(C_PTR) :: cxxptr
        cxxptr = obj%cxxmem%addr
    end function class1_get_instance

    subroutine class1_set_instance(obj, cxxmem)
        use iso_c_binding, only: C_PTR
        class(class1), intent(INOUT) :: obj
        type(C_PTR), intent(IN) :: cxxmem
        obj%cxxmem%addr = cxxmem
        obj%cxxmem%idtor = 0
    end subroutine class1_set_instance

    function class1_associated(obj) result (rv)
        use iso_c_binding, only: c_associated
        class(class1), intent(IN) :: obj
        logical rv
        rv = c_associated(obj%cxxmem%addr)
    end function class1_associated



    function class1_eq(a,b) result (rv)
        use iso_c_binding, only: c_associated
        type(class1), intent(IN) ::a,b
        logical :: rv
        if (c_associated(a%cxxmem%addr, b%cxxmem%addr)) then
            rv = .true.
        else
            rv = .false.
        endif
    end function class1_eq

    function class1_ne(a,b) result (rv)
        use iso_c_binding, only: c_associated
        type(class1), intent(IN) ::a,b
        logical :: rv
        if (.not. c_associated(a%cxxmem%addr, b%cxxmem%addr)) then
            rv = .true.
        else
            rv = .false.
        endif
    end function class1_ne

end module library_three_mod
