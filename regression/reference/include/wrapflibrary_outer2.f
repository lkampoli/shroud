! wrapflibrary_outer2.f
! This is generated code, do not edit
! #######################################################################
! Copyright (c) 2017-2019, Lawrence Livermore National Security, LLC.
!
! Produced at the Lawrence Livermore National Laboratory
!
! LLNL-CODE-738041.
!
! All rights reserved.
!
! This file is part of Shroud.
!
! For details about use and distribution, please read LICENSE.
!
! #######################################################################
!>
!! \file wrapflibrary_outer2.f
!! \brief Shroud generated wrapper for outer2 namespace
!<
module library_outer2_mod
    use iso_c_binding, only : C_INT, C_NULL_PTR, C_PTR
    implicit none


    type, bind(C) :: SHROUD_class0_capsule
        type(C_PTR) :: addr = C_NULL_PTR  ! address of C++ memory
        integer(C_INT) :: idtor = 0       ! index of destructor
    end type SHROUD_class0_capsule

    type class0
        type(SHROUD_class0_capsule) :: cxxmem
    contains
        procedure :: method => class0_method
        procedure :: get_instance => class0_get_instance
        procedure :: set_instance => class0_set_instance
        procedure :: associated => class0_associated
    end type class0

    interface operator (.eq.)
        module procedure class0_eq
    end interface

    interface operator (.ne.)
        module procedure class0_ne
    end interface

    interface

        subroutine c_class0_method(self) &
                bind(C, name="LIB_outer2_class0_method")
            import :: SHROUD_class0_capsule
            implicit none
            type(SHROUD_class0_capsule), intent(IN) :: self
        end subroutine c_class0_method


        subroutine outer_func() &
                bind(C, name="LIB_outer2_outer_func")
            implicit none
        end subroutine outer_func

    end interface

contains

    subroutine class0_method(obj)
        class(class0) :: obj
        call c_class0_method(obj%cxxmem)
    end subroutine class0_method

    ! Return pointer to C++ memory.
    function class0_get_instance(obj) result (cxxptr)
        use iso_c_binding, only: C_PTR
        class(class0), intent(IN) :: obj
        type(C_PTR) :: cxxptr
        cxxptr = obj%cxxmem%addr
    end function class0_get_instance

    subroutine class0_set_instance(obj, cxxmem)
        use iso_c_binding, only: C_PTR
        class(class0), intent(INOUT) :: obj
        type(C_PTR), intent(IN) :: cxxmem
        obj%cxxmem%addr = cxxmem
        obj%cxxmem%idtor = 0
    end subroutine class0_set_instance

    function class0_associated(obj) result (rv)
        use iso_c_binding, only: c_associated
        class(class0), intent(IN) :: obj
        logical rv
        rv = c_associated(obj%cxxmem%addr)
    end function class0_associated



    function class0_eq(a,b) result (rv)
        use iso_c_binding, only: c_associated
        type(class0), intent(IN) ::a,b
        logical :: rv
        if (c_associated(a%cxxmem%addr, b%cxxmem%addr)) then
            rv = .true.
        else
            rv = .false.
        endif
    end function class0_eq

    function class0_ne(a,b) result (rv)
        use iso_c_binding, only: c_associated
        type(class0), intent(IN) ::a,b
        logical :: rv
        if (.not. c_associated(a%cxxmem%addr, b%cxxmem%addr)) then
            rv = .true.
        else
            rv = .false.
        endif
    end function class0_ne

end module library_outer2_mod