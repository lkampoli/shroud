! wrapfstruct.f
! This file is generated by Shroud nowrite-version. Do not edit.
! Copyright (c) 2017-2020, Lawrence Livermore National Security, LLC and
! other Shroud Project Developers.
! See the top-level COPYRIGHT file for details.
!
! SPDX-License-Identifier: (BSD-3-Clause)
!
!>
!! \file wrapfstruct.f
!! \brief Shroud generated wrapper for struct library
!<
! splicer begin file_top
! splicer end file_top
module struct_mod
    use iso_c_binding, only : C_CHAR, C_DOUBLE, C_INT, C_NULL_PTR, C_PTR
    ! splicer begin module_use
    ! splicer end module_use
    implicit none

    ! splicer begin module_top
    integer, parameter :: MAXNAME = 20
    ! splicer end module_top

    ! helper capsule_data_helper
    type, bind(C) :: STR_SHROUD_capsule_data
        type(C_PTR) :: addr = C_NULL_PTR  ! address of C++ memory
        integer(C_INT) :: idtor = 0       ! index of destructor
    end type STR_SHROUD_capsule_data


    ! start derived-type cstruct1
    type, bind(C) :: cstruct1
        integer(C_INT) :: ifield
        real(C_DOUBLE) :: dfield
    end type cstruct1
    ! end derived-type cstruct1


    type, bind(C) :: cstruct_ptr
        type(C_PTR) :: cfield
        type(C_PTR) :: const_dvalue
    end type cstruct_ptr


    type, bind(C) :: cstruct_list
        integer(C_INT) :: nitems
        type(C_PTR) :: ivalue
        type(C_PTR) :: dvalue
        type(C_PTR) :: svalue
    end type cstruct_list


    type, bind(C) :: cstruct_numpy
        integer(C_INT) :: nitems
        type(C_PTR) :: ivalue
        type(C_PTR) :: dvalue
    end type cstruct_numpy


    type, bind(C) :: arrays1
        character(kind=C_CHAR) :: name(20)
        integer(C_INT) :: count(10)
    end type arrays1

    type cstruct_as_class
        type(STR_SHROUD_capsule_data) :: cxxmem
        ! splicer begin class.Cstruct_as_class.component_part
        ! splicer end class.Cstruct_as_class.component_part
    contains
        procedure :: get_x1 => cstruct_as_class_get_x1
        procedure :: set_x1 => cstruct_as_class_set_x1
        procedure :: get_y1 => cstruct_as_class_get_y1
        procedure :: set_y1 => cstruct_as_class_set_y1
        procedure :: get_instance => cstruct_as_class_get_instance
        procedure :: set_instance => cstruct_as_class_set_instance
        procedure :: associated => cstruct_as_class_associated
        ! splicer begin class.Cstruct_as_class.type_bound_procedure_part
        ! splicer end class.Cstruct_as_class.type_bound_procedure_part
    end type cstruct_as_class

    interface operator (.eq.)
        module procedure cstruct_as_class_eq
    end interface

    interface operator (.ne.)
        module procedure cstruct_as_class_ne
    end interface

    interface

        ! ----------------------------------------
        ! Function:  int getX1
        ! Requested: c_native_scalar_result
        ! Match:     c_default
        function c_cstruct_as_class_get_x1(self) &
                result(SHT_rv) &
                bind(C, name="STR_Cstruct_as_class_get_x1")
            use iso_c_binding, only : C_INT
            import :: STR_SHROUD_capsule_data
            implicit none
            type(STR_SHROUD_capsule_data), intent(IN) :: self
            integer(C_INT) :: SHT_rv
        end function c_cstruct_as_class_get_x1

        ! ----------------------------------------
        ! Function:  void setX1
        ! Requested: c_void_scalar_result
        ! Match:     c_default
        ! ----------------------------------------
        ! Argument:  int val +intent(in)+value
        ! Requested: c_native_scalar_in
        ! Match:     c_default
        subroutine c_cstruct_as_class_set_x1(self, val) &
                bind(C, name="STR_Cstruct_as_class_set_x1")
            use iso_c_binding, only : C_INT
            import :: STR_SHROUD_capsule_data
            implicit none
            type(STR_SHROUD_capsule_data), intent(IN) :: self
            integer(C_INT), value, intent(IN) :: val
        end subroutine c_cstruct_as_class_set_x1

        ! ----------------------------------------
        ! Function:  int getY1
        ! Requested: c_native_scalar_result
        ! Match:     c_default
        function c_cstruct_as_class_get_y1(self) &
                result(SHT_rv) &
                bind(C, name="STR_Cstruct_as_class_get_y1")
            use iso_c_binding, only : C_INT
            import :: STR_SHROUD_capsule_data
            implicit none
            type(STR_SHROUD_capsule_data), intent(IN) :: self
            integer(C_INT) :: SHT_rv
        end function c_cstruct_as_class_get_y1

        ! ----------------------------------------
        ! Function:  void setY1
        ! Requested: c_void_scalar_result
        ! Match:     c_default
        ! ----------------------------------------
        ! Argument:  int val +intent(in)+value
        ! Requested: c_native_scalar_in
        ! Match:     c_default
        subroutine c_cstruct_as_class_set_y1(self, val) &
                bind(C, name="STR_Cstruct_as_class_set_y1")
            use iso_c_binding, only : C_INT
            import :: STR_SHROUD_capsule_data
            implicit none
            type(STR_SHROUD_capsule_data), intent(IN) :: self
            integer(C_INT), value, intent(IN) :: val
        end subroutine c_cstruct_as_class_set_y1

        ! splicer begin class.Cstruct_as_class.additional_interfaces
        ! splicer end class.Cstruct_as_class.additional_interfaces

        ! ----------------------------------------
        ! Function:  int passStructByValue
        ! Requested: c_native_scalar_result
        ! Match:     c_default
        ! ----------------------------------------
        ! Argument:  Cstruct1 arg +intent(in)+value
        ! Requested: c_struct_scalar_in
        ! Match:     c_struct
        ! start pass_struct_by_value
        function pass_struct_by_value(arg) &
                result(SHT_rv) &
                bind(C, name="STR_pass_struct_by_value")
            use iso_c_binding, only : C_INT
            import :: cstruct1
            implicit none
            type(cstruct1), value, intent(IN) :: arg
            integer(C_INT) :: SHT_rv
        end function pass_struct_by_value
        ! end pass_struct_by_value

        ! ----------------------------------------
        ! Function:  int passStruct1
        ! Requested: c_native_scalar_result
        ! Match:     c_default
        ! ----------------------------------------
        ! Argument:  const Cstruct1 * arg +intent(in)
        ! Requested: c_struct_*_in
        ! Match:     c_struct
        ! start pass_struct1
        function pass_struct1(arg) &
                result(SHT_rv) &
                bind(C, name="STR_pass_struct1")
            use iso_c_binding, only : C_INT
            import :: cstruct1
            implicit none
            type(cstruct1), intent(IN) :: arg
            integer(C_INT) :: SHT_rv
        end function pass_struct1
        ! end pass_struct1

        ! ----------------------------------------
        ! Function:  int passStruct2
        ! Requested: c_native_scalar_result
        ! Match:     c_default
        ! ----------------------------------------
        ! Argument:  const Cstruct1 * s1 +intent(in)
        ! Requested: c_struct_*_in
        ! Match:     c_struct
        ! ----------------------------------------
        ! Argument:  char * outbuf +charlen(LENOUTBUF)+intent(out)
        ! Requested: c_char_*_out
        ! Match:     c_default
        function c_pass_struct2(s1, outbuf) &
                result(SHT_rv) &
                bind(C, name="STR_pass_struct2")
            use iso_c_binding, only : C_CHAR, C_INT
            import :: cstruct1
            implicit none
            type(cstruct1), intent(IN) :: s1
            character(kind=C_CHAR), intent(OUT) :: outbuf(*)
            integer(C_INT) :: SHT_rv
        end function c_pass_struct2

        ! ----------------------------------------
        ! Function:  int passStruct2
        ! Requested: c_native_scalar_result_buf
        ! Match:     c_default
        ! ----------------------------------------
        ! Argument:  const Cstruct1 * s1 +intent(in)
        ! Requested: c_struct_*_in_buf
        ! Match:     c_struct
        ! ----------------------------------------
        ! Argument:  char * outbuf +charlen(LENOUTBUF)+intent(out)+len(Noutbuf)
        ! Exact:     c_char_*_out_buf
        function c_pass_struct2_bufferify(s1, outbuf, Noutbuf) &
                result(SHT_rv) &
                bind(C, name="STR_pass_struct2_bufferify")
            use iso_c_binding, only : C_CHAR, C_INT
            import :: cstruct1
            implicit none
            type(cstruct1), intent(IN) :: s1
            character(kind=C_CHAR), intent(OUT) :: outbuf(*)
            integer(C_INT), value, intent(IN) :: Noutbuf
            integer(C_INT) :: SHT_rv
        end function c_pass_struct2_bufferify

        ! ----------------------------------------
        ! Function:  int acceptStructInPtr
        ! Requested: c_native_scalar_result
        ! Match:     c_default
        ! ----------------------------------------
        ! Argument:  Cstruct1 * arg +intent(in)
        ! Requested: c_struct_*_in
        ! Match:     c_struct
        function accept_struct_in_ptr(arg) &
                result(SHT_rv) &
                bind(C, name="STR_accept_struct_in_ptr")
            use iso_c_binding, only : C_INT
            import :: cstruct1
            implicit none
            type(cstruct1), intent(IN) :: arg
            integer(C_INT) :: SHT_rv
        end function accept_struct_in_ptr

        ! ----------------------------------------
        ! Function:  void acceptStructOutPtr
        ! Requested: c_void_scalar_result
        ! Match:     c_default
        ! ----------------------------------------
        ! Argument:  Cstruct1 * arg +intent(out)
        ! Requested: c_struct_*_out
        ! Match:     c_struct
        ! ----------------------------------------
        ! Argument:  int i +intent(in)+value
        ! Requested: c_native_scalar_in
        ! Match:     c_default
        ! ----------------------------------------
        ! Argument:  double d +intent(in)+value
        ! Requested: c_native_scalar_in
        ! Match:     c_default
        subroutine accept_struct_out_ptr(arg, i, d) &
                bind(C, name="STR_accept_struct_out_ptr")
            use iso_c_binding, only : C_DOUBLE, C_INT
            import :: cstruct1
            implicit none
            type(cstruct1), intent(OUT) :: arg
            integer(C_INT), value, intent(IN) :: i
            real(C_DOUBLE), value, intent(IN) :: d
        end subroutine accept_struct_out_ptr

        ! ----------------------------------------
        ! Function:  void acceptStructInOutPtr
        ! Requested: c_void_scalar_result
        ! Match:     c_default
        ! ----------------------------------------
        ! Argument:  Cstruct1 * arg +intent(inout)
        ! Requested: c_struct_*_inout
        ! Match:     c_struct
        subroutine accept_struct_in_out_ptr(arg) &
                bind(C, name="STR_accept_struct_in_out_ptr")
            import :: cstruct1
            implicit none
            type(cstruct1), intent(INOUT) :: arg
        end subroutine accept_struct_in_out_ptr

        ! ----------------------------------------
        ! Function:  Cstruct1 returnStructByValue
        ! Requested: c_struct_scalar_result
        ! Match:     c_struct_result
        ! ----------------------------------------
        ! Argument:  int i +intent(in)+value
        ! Requested: c_native_scalar_in
        ! Match:     c_default
        ! ----------------------------------------
        ! Argument:  double d +intent(in)+value
        ! Requested: c_native_scalar_in
        ! Match:     c_default
        function return_struct_by_value(i, d) &
                result(SHT_rv) &
                bind(C, name="STR_return_struct_by_value")
            use iso_c_binding, only : C_DOUBLE, C_INT
            import :: cstruct1
            implicit none
            integer(C_INT), value, intent(IN) :: i
            real(C_DOUBLE), value, intent(IN) :: d
            type(cstruct1) :: SHT_rv
        end function return_struct_by_value

        ! ----------------------------------------
        ! Function:  Cstruct1 * returnStructPtr1 +deref(pointer)
        ! Requested: c_struct_*_result
        ! Match:     c_struct_result
        ! ----------------------------------------
        ! Argument:  int i +intent(in)+value
        ! Requested: c_native_scalar_in
        ! Match:     c_default
        ! ----------------------------------------
        ! Argument:  double d +intent(in)+value
        ! Requested: c_native_scalar_in
        ! Match:     c_default
        function c_return_struct_ptr1(i, d) &
                result(SHT_rv) &
                bind(C, name="STR_return_struct_ptr1")
            use iso_c_binding, only : C_DOUBLE, C_INT, C_PTR
            implicit none
            integer(C_INT), value, intent(IN) :: i
            real(C_DOUBLE), value, intent(IN) :: d
            type(C_PTR) SHT_rv
        end function c_return_struct_ptr1

        ! ----------------------------------------
        ! Function:  Cstruct1 * returnStructPtr2 +deref(pointer)
        ! Requested: c_struct_*_result
        ! Match:     c_struct_result
        ! ----------------------------------------
        ! Argument:  int i +intent(in)+value
        ! Requested: c_native_scalar_in
        ! Match:     c_default
        ! ----------------------------------------
        ! Argument:  double d +intent(in)+value
        ! Requested: c_native_scalar_in
        ! Match:     c_default
        ! ----------------------------------------
        ! Argument:  char * outbuf +charlen(LENOUTBUF)+intent(out)
        ! Requested: c_char_*_out
        ! Match:     c_default
        function c_return_struct_ptr2(i, d, outbuf) &
                result(SHT_rv) &
                bind(C, name="STR_return_struct_ptr2")
            use iso_c_binding, only : C_CHAR, C_DOUBLE, C_INT, C_PTR
            implicit none
            integer(C_INT), value, intent(IN) :: i
            real(C_DOUBLE), value, intent(IN) :: d
            character(kind=C_CHAR), intent(OUT) :: outbuf(*)
            type(C_PTR) SHT_rv
        end function c_return_struct_ptr2

        ! ----------------------------------------
        ! Function:  Cstruct1 * returnStructPtr2 +deref(pointer)
        ! Requested: c_struct_*_result_buf
        ! Match:     c_struct_result
        ! ----------------------------------------
        ! Argument:  int i +intent(in)+value
        ! Requested: c_native_scalar_in_buf
        ! Match:     c_default
        ! ----------------------------------------
        ! Argument:  double d +intent(in)+value
        ! Requested: c_native_scalar_in_buf
        ! Match:     c_default
        ! ----------------------------------------
        ! Argument:  char * outbuf +charlen(LENOUTBUF)+intent(out)+len(Noutbuf)
        ! Exact:     c_char_*_out_buf
        function c_return_struct_ptr2_bufferify(i, d, outbuf, Noutbuf) &
                result(SHT_rv) &
                bind(C, name="STR_return_struct_ptr2_bufferify")
            use iso_c_binding, only : C_CHAR, C_DOUBLE, C_INT, C_PTR
            implicit none
            integer(C_INT), value, intent(IN) :: i
            real(C_DOUBLE), value, intent(IN) :: d
            character(kind=C_CHAR), intent(OUT) :: outbuf(*)
            integer(C_INT), value, intent(IN) :: Noutbuf
            type(C_PTR) SHT_rv
        end function c_return_struct_ptr2_bufferify

        ! ----------------------------------------
        ! Function:  Cstruct_list * get_global_struct_list +deref(pointer)
        ! Requested: c_struct_*_result
        ! Match:     c_struct_result
        function c_get_global_struct_list() &
                result(SHT_rv) &
                bind(C, name="STR_get_global_struct_list")
            use iso_c_binding, only : C_PTR
            implicit none
            type(C_PTR) SHT_rv
        end function c_get_global_struct_list

        ! ----------------------------------------
        ! Function:  Cstruct_as_class * Create_Cstruct_as_class
        ! Requested: c_shadow_*_result
        ! Match:     c_shadow_result
        function c_create__cstruct_as_class(SHT_crv) &
                result(SHT_rv) &
                bind(C, name="STR_create__cstruct_as_class")
            use iso_c_binding, only : C_PTR
            import :: STR_SHROUD_capsule_data
            implicit none
            type(STR_SHROUD_capsule_data), intent(OUT) :: SHT_crv
            type(C_PTR) SHT_rv
        end function c_create__cstruct_as_class

        ! ----------------------------------------
        ! Function:  Cstruct_as_class * Create_Cstruct_as_class_args
        ! Requested: c_shadow_*_result
        ! Match:     c_shadow_result
        ! ----------------------------------------
        ! Argument:  int x +intent(in)+value
        ! Requested: c_native_scalar_in
        ! Match:     c_default
        ! ----------------------------------------
        ! Argument:  int y +intent(in)+value
        ! Requested: c_native_scalar_in
        ! Match:     c_default
        function c_create__cstruct_as_class_args(x, y, SHT_crv) &
                result(SHT_rv) &
                bind(C, name="STR_create__cstruct_as_class_args")
            use iso_c_binding, only : C_INT, C_PTR
            import :: STR_SHROUD_capsule_data
            implicit none
            integer(C_INT), value, intent(IN) :: x
            integer(C_INT), value, intent(IN) :: y
            type(STR_SHROUD_capsule_data), intent(OUT) :: SHT_crv
            type(C_PTR) SHT_rv
        end function c_create__cstruct_as_class_args

        ! ----------------------------------------
        ! Function:  int Cstruct_as_class_sum
        ! Requested: c_native_scalar_result
        ! Match:     c_default
        ! ----------------------------------------
        ! Argument:  const Cstruct_as_class * point +intent(in)
        ! Requested: c_shadow_*_in
        ! Match:     c_shadow_in
        function c_cstruct_as_class_sum(point) &
                result(SHT_rv) &
                bind(C, name="STR_cstruct_as_class_sum")
            use iso_c_binding, only : C_INT
            import :: STR_SHROUD_capsule_data
            implicit none
            type(STR_SHROUD_capsule_data), intent(IN) :: point
            integer(C_INT) :: SHT_rv
        end function c_cstruct_as_class_sum

        ! splicer begin additional_interfaces
        ! splicer end additional_interfaces
    end interface

    interface Cstruct_as_class
        module procedure create__cstruct_as_class
        module procedure create__cstruct_as_class_args
    end interface Cstruct_as_class

contains

    ! ----------------------------------------
    ! Function:  int getX1
    ! int getX1
    ! Requested: f_native_scalar_result
    ! Match:     f_default
    ! Requested: c_native_scalar_result
    ! Match:     c_default
    function cstruct_as_class_get_x1(obj) &
            result(SHT_rv)
        use iso_c_binding, only : C_INT
        class(cstruct_as_class) :: obj
        integer(C_INT) :: SHT_rv
        ! splicer begin class.Cstruct_as_class.method.get_x1
        SHT_rv = c_cstruct_as_class_get_x1(obj%cxxmem)
        ! splicer end class.Cstruct_as_class.method.get_x1
    end function cstruct_as_class_get_x1

    ! ----------------------------------------
    ! Function:  void setX1
    ! void setX1
    ! Requested: f_subroutine
    ! Match:     f_default
    ! Requested: c
    ! Match:     c_default
    ! ----------------------------------------
    ! Argument:  int val +intent(in)+value
    ! Requested: f_native_scalar_in
    ! Match:     f_default
    ! Requested: c_native_scalar_in
    ! Match:     c_default
    subroutine cstruct_as_class_set_x1(obj, val)
        use iso_c_binding, only : C_INT
        class(cstruct_as_class) :: obj
        integer(C_INT), value, intent(IN) :: val
        ! splicer begin class.Cstruct_as_class.method.set_x1
        call c_cstruct_as_class_set_x1(obj%cxxmem, val)
        ! splicer end class.Cstruct_as_class.method.set_x1
    end subroutine cstruct_as_class_set_x1

    ! ----------------------------------------
    ! Function:  int getY1
    ! int getY1
    ! Requested: f_native_scalar_result
    ! Match:     f_default
    ! Requested: c_native_scalar_result
    ! Match:     c_default
    function cstruct_as_class_get_y1(obj) &
            result(SHT_rv)
        use iso_c_binding, only : C_INT
        class(cstruct_as_class) :: obj
        integer(C_INT) :: SHT_rv
        ! splicer begin class.Cstruct_as_class.method.get_y1
        SHT_rv = c_cstruct_as_class_get_y1(obj%cxxmem)
        ! splicer end class.Cstruct_as_class.method.get_y1
    end function cstruct_as_class_get_y1

    ! ----------------------------------------
    ! Function:  void setY1
    ! void setY1
    ! Requested: f_subroutine
    ! Match:     f_default
    ! Requested: c
    ! Match:     c_default
    ! ----------------------------------------
    ! Argument:  int val +intent(in)+value
    ! Requested: f_native_scalar_in
    ! Match:     f_default
    ! Requested: c_native_scalar_in
    ! Match:     c_default
    subroutine cstruct_as_class_set_y1(obj, val)
        use iso_c_binding, only : C_INT
        class(cstruct_as_class) :: obj
        integer(C_INT), value, intent(IN) :: val
        ! splicer begin class.Cstruct_as_class.method.set_y1
        call c_cstruct_as_class_set_y1(obj%cxxmem, val)
        ! splicer end class.Cstruct_as_class.method.set_y1
    end subroutine cstruct_as_class_set_y1

    ! Return pointer to C++ memory.
    function cstruct_as_class_get_instance(obj) result (cxxptr)
        use iso_c_binding, only: C_PTR
        class(cstruct_as_class), intent(IN) :: obj
        type(C_PTR) :: cxxptr
        cxxptr = obj%cxxmem%addr
    end function cstruct_as_class_get_instance

    subroutine cstruct_as_class_set_instance(obj, cxxmem)
        use iso_c_binding, only: C_PTR
        class(cstruct_as_class), intent(INOUT) :: obj
        type(C_PTR), intent(IN) :: cxxmem
        obj%cxxmem%addr = cxxmem
        obj%cxxmem%idtor = 0
    end subroutine cstruct_as_class_set_instance

    function cstruct_as_class_associated(obj) result (rv)
        use iso_c_binding, only: c_associated
        class(cstruct_as_class), intent(IN) :: obj
        logical rv
        rv = c_associated(obj%cxxmem%addr)
    end function cstruct_as_class_associated

    ! splicer begin class.Cstruct_as_class.additional_functions
    ! splicer end class.Cstruct_as_class.additional_functions

    ! Generated by arg_to_buffer
    ! ----------------------------------------
    ! Function:  int passStruct2
    ! int passStruct2
    ! Requested: f_native_scalar_result
    ! Match:     f_default
    ! Requested: c_native_scalar_result_buf
    ! Match:     c_default
    ! ----------------------------------------
    ! Argument:  const Cstruct1 * s1 +intent(in)
    ! Requested: f_struct_*_in
    ! Match:     f_default
    ! Requested: c_struct_*_in_buf
    ! Match:     c_struct
    ! ----------------------------------------
    ! Argument:  char * outbuf +charlen(LENOUTBUF)+intent(out)
    ! Requested: f_char_*_out
    ! Match:     f_default
    ! Argument:  char * outbuf +charlen(LENOUTBUF)+intent(out)+len(Noutbuf)
    ! Exact:     c_char_*_out_buf
    !>
    !! Pass name argument which will build a bufferify function.
    !<
    function pass_struct2(s1, outbuf) &
            result(SHT_rv)
        use iso_c_binding, only : C_INT
        type(cstruct1), intent(IN) :: s1
        character(len=*), intent(OUT) :: outbuf
        integer(C_INT) :: SHT_rv
        ! splicer begin function.pass_struct2
        SHT_rv = c_pass_struct2_bufferify(s1, outbuf, &
            len(outbuf, kind=C_INT))
        ! splicer end function.pass_struct2
    end function pass_struct2

    ! ----------------------------------------
    ! Function:  Cstruct1 * returnStructPtr1 +deref(pointer)
    ! Cstruct1 * returnStructPtr1 +deref(pointer)
    ! Requested: f_struct_*_result_pointer
    ! Match:     f_struct_*_result
    ! Requested: c_struct_*_result
    ! Match:     c_struct_result
    ! ----------------------------------------
    ! Argument:  int i +intent(in)+value
    ! Requested: f_native_scalar_in
    ! Match:     f_default
    ! Requested: c_native_scalar_in
    ! Match:     c_default
    ! ----------------------------------------
    ! Argument:  double d +intent(in)+value
    ! Requested: f_native_scalar_in
    ! Match:     f_default
    ! Requested: c_native_scalar_in
    ! Match:     c_default
    !>
    !! \brief Return a pointer to a struct
    !!
    !! Does not generate a bufferify C wrapper.
    !<
    function return_struct_ptr1(i, d) &
            result(SHT_rv)
        use iso_c_binding, only : C_DOUBLE, C_INT, C_PTR, c_f_pointer
        integer(C_INT), value, intent(IN) :: i
        real(C_DOUBLE), value, intent(IN) :: d
        type(cstruct1), pointer :: SHT_rv
        ! splicer begin function.return_struct_ptr1
        type(C_PTR) :: SHT_ptr
        SHT_ptr = c_return_struct_ptr1(i, d)
        call c_f_pointer(SHT_ptr, SHT_rv)
        ! splicer end function.return_struct_ptr1
    end function return_struct_ptr1

    ! Generated by arg_to_buffer
    ! ----------------------------------------
    ! Function:  Cstruct1 * returnStructPtr2 +deref(pointer)
    ! Cstruct1 * returnStructPtr2 +deref(pointer)
    ! Requested: f_struct_*_result_pointer
    ! Match:     f_struct_*_result
    ! Requested: c_struct_*_result_buf
    ! Match:     c_struct_result
    ! ----------------------------------------
    ! Argument:  int i +intent(in)+value
    ! Requested: f_native_scalar_in
    ! Match:     f_default
    ! Requested: c_native_scalar_in_buf
    ! Match:     c_default
    ! ----------------------------------------
    ! Argument:  double d +intent(in)+value
    ! Requested: f_native_scalar_in
    ! Match:     f_default
    ! Requested: c_native_scalar_in_buf
    ! Match:     c_default
    ! ----------------------------------------
    ! Argument:  char * outbuf +charlen(LENOUTBUF)+intent(out)
    ! Requested: f_char_*_out
    ! Match:     f_default
    ! Argument:  char * outbuf +charlen(LENOUTBUF)+intent(out)+len(Noutbuf)
    ! Exact:     c_char_*_out_buf
    !>
    !! \brief Return a pointer to a struct
    !!
    !! Generates a bufferify C wrapper function.
    !<
    function return_struct_ptr2(i, d, outbuf) &
            result(SHT_rv)
        use iso_c_binding, only : C_DOUBLE, C_INT, C_PTR, c_f_pointer
        integer(C_INT), value, intent(IN) :: i
        real(C_DOUBLE), value, intent(IN) :: d
        character(len=*), intent(OUT) :: outbuf
        type(cstruct1), pointer :: SHT_rv
        ! splicer begin function.return_struct_ptr2
        type(C_PTR) :: SHT_ptr
        SHT_ptr = c_return_struct_ptr2_bufferify(i, d, outbuf, &
            len(outbuf, kind=C_INT))
        call c_f_pointer(SHT_ptr, SHT_rv)
        ! splicer end function.return_struct_ptr2
    end function return_struct_ptr2

    ! ----------------------------------------
    ! Function:  Cstruct_list * get_global_struct_list +deref(pointer)
    ! Cstruct_list * get_global_struct_list +deref(pointer)
    ! Requested: f_struct_*_result_pointer
    ! Match:     f_struct_*_result
    ! Requested: c_struct_*_result
    ! Match:     c_struct_result
    function get_global_struct_list() &
            result(SHT_rv)
        use iso_c_binding, only : C_PTR, c_f_pointer
        type(cstruct_list), pointer :: SHT_rv
        ! splicer begin function.get_global_struct_list
        type(C_PTR) :: SHT_ptr
        SHT_ptr = c_get_global_struct_list()
        call c_f_pointer(SHT_ptr, SHT_rv)
        ! splicer end function.get_global_struct_list
    end function get_global_struct_list

    ! ----------------------------------------
    ! Function:  Cstruct_as_class * Create_Cstruct_as_class
    ! Cstruct_as_class * Create_Cstruct_as_class
    ! Requested: f_shadow_*_result
    ! Match:     f_shadow_result
    ! Requested: c_shadow_*_result
    ! Match:     c_shadow_result
    function create__cstruct_as_class() &
            result(SHT_rv)
        use iso_c_binding, only : C_PTR
        type(cstruct_as_class) :: SHT_rv
        ! splicer begin function.create__cstruct_as_class
        type(C_PTR) :: SHT_prv
        SHT_prv = c_create__cstruct_as_class(SHT_rv%cxxmem)
        ! splicer end function.create__cstruct_as_class
    end function create__cstruct_as_class

    ! ----------------------------------------
    ! Function:  Cstruct_as_class * Create_Cstruct_as_class_args
    ! Cstruct_as_class * Create_Cstruct_as_class_args
    ! Requested: f_shadow_*_result
    ! Match:     f_shadow_result
    ! Requested: c_shadow_*_result
    ! Match:     c_shadow_result
    ! ----------------------------------------
    ! Argument:  int x +intent(in)+value
    ! Requested: f_native_scalar_in
    ! Match:     f_default
    ! Requested: c_native_scalar_in
    ! Match:     c_default
    ! ----------------------------------------
    ! Argument:  int y +intent(in)+value
    ! Requested: f_native_scalar_in
    ! Match:     f_default
    ! Requested: c_native_scalar_in
    ! Match:     c_default
    function create__cstruct_as_class_args(x, y) &
            result(SHT_rv)
        use iso_c_binding, only : C_INT, C_PTR
        integer(C_INT), value, intent(IN) :: x
        integer(C_INT), value, intent(IN) :: y
        type(cstruct_as_class) :: SHT_rv
        ! splicer begin function.create__cstruct_as_class_args
        type(C_PTR) :: SHT_prv
        SHT_prv = c_create__cstruct_as_class_args(x, y, SHT_rv%cxxmem)
        ! splicer end function.create__cstruct_as_class_args
    end function create__cstruct_as_class_args

    ! ----------------------------------------
    ! Function:  int Cstruct_as_class_sum
    ! int Cstruct_as_class_sum
    ! Requested: f_native_scalar_result
    ! Match:     f_default
    ! Requested: c_native_scalar_result
    ! Match:     c_default
    ! ----------------------------------------
    ! Argument:  const Cstruct_as_class * point +intent(in)
    ! Requested: f_shadow_*_in
    ! Match:     f_default
    ! Requested: c_shadow_*_in
    ! Match:     c_shadow_in
    function cstruct_as_class_sum(point) &
            result(SHT_rv)
        use iso_c_binding, only : C_INT
        type(cstruct_as_class), intent(IN) :: point
        integer(C_INT) :: SHT_rv
        ! splicer begin function.sum
        SHT_rv = c_cstruct_as_class_sum(point%cxxmem)
        ! splicer end function.sum
    end function cstruct_as_class_sum

    ! splicer begin additional_functions
    ! splicer end additional_functions

    function cstruct_as_class_eq(a,b) result (rv)
        use iso_c_binding, only: c_associated
        type(cstruct_as_class), intent(IN) ::a,b
        logical :: rv
        if (c_associated(a%cxxmem%addr, b%cxxmem%addr)) then
            rv = .true.
        else
            rv = .false.
        endif
    end function cstruct_as_class_eq

    function cstruct_as_class_ne(a,b) result (rv)
        use iso_c_binding, only: c_associated
        type(cstruct_as_class), intent(IN) ::a,b
        logical :: rv
        if (.not. c_associated(a%cxxmem%addr, b%cxxmem%addr)) then
            rv = .true.
        else
            rv = .false.
        endif
    end function cstruct_as_class_ne

end module struct_mod
