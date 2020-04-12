! top.f
! This file is generated by Shroud 0.11.0. Do not edit.
! Copyright (c) 2017-2020, Lawrence Livermore National Security, LLC and
! other Shroud Project Developers.
! See the top-level COPYRIGHT file for details.
!
! SPDX-License-Identifier: (BSD-3-Clause)
!
!>
!! \file top.f
!! \brief Shroud generated wrapper for testnames library
!<
! splicer begin file_top
! splicer end file_top
module top_module
    use iso_c_binding, only : C_INT, C_NULL_PTR, C_PTR
    ! splicer begin module_use
    ! splicer end module_use
    implicit none

    ! splicer begin module_top
    ! splicer end module_top

    !  enum Color
    integer(C_INT), parameter :: red = 0
    integer(C_INT), parameter :: blue = 1
    integer(C_INT), parameter :: white = 2

    type, bind(C) :: SHROUD_names2_capsule
        type(C_PTR) :: addr = C_NULL_PTR  ! address of C++ memory
        integer(C_INT) :: idtor = 0       ! index of destructor
    end type SHROUD_names2_capsule

    type names2
        type(SHROUD_names2_capsule) :: cxxmem
        ! splicer begin class.Names2.component_part
        ! splicer end class.Names2.component_part
    contains
        procedure :: get_instance => names2_get_instance
        procedure :: set_instance => names2_set_instance
        procedure :: associated => names2_associated
        ! splicer begin class.Names2.type_bound_procedure_part
        ! splicer end class.Names2.type_bound_procedure_part
    end type names2

    type, bind(C) :: SHROUD_twots_0_capsule
        type(C_PTR) :: addr = C_NULL_PTR  ! address of C++ memory
        integer(C_INT) :: idtor = 0       ! index of destructor
    end type SHROUD_twots_0_capsule

    type twots_0
        type(SHROUD_twots_0_capsule) :: cxxmem
        ! splicer begin class.twoTs_0.component_part
        ! splicer end class.twoTs_0.component_part
    contains
        procedure :: get_instance => twots_0_get_instance
        procedure :: set_instance => twots_0_set_instance
        procedure :: associated => twots_0_associated
        ! splicer begin class.twoTs_0.type_bound_procedure_part
        ! splicer end class.twoTs_0.type_bound_procedure_part
    end type twots_0

    type, bind(C) :: SHROUD_twots_instantiation4_capsule
        type(C_PTR) :: addr = C_NULL_PTR  ! address of C++ memory
        integer(C_INT) :: idtor = 0       ! index of destructor
    end type SHROUD_twots_instantiation4_capsule

    type twots_instantiation4
        type(SHROUD_twots_instantiation4_capsule) :: cxxmem
        ! splicer begin class.twoTs_instantiation4.component_part
        ! splicer end class.twoTs_instantiation4.component_part
    contains
        procedure :: get_instance_instantiation4 => twots_instantiation4_get_instance_instantiation4
        procedure :: set_instance_instantiation4 => twots_instantiation4_set_instance_instantiation4
        procedure :: associated_instantiation4 => twots_instantiation4_associated_instantiation4
        ! splicer begin class.twoTs_instantiation4.type_bound_procedure_part
        ! splicer end class.twoTs_instantiation4.type_bound_procedure_part
    end type twots_instantiation4

    interface operator (.eq.)
        module procedure names2_eq
        module procedure twots_0_eq
        module procedure twots_instantiation4_eq
    end interface

    interface operator (.ne.)
        module procedure names2_ne
        module procedure twots_0_ne
        module procedure twots_instantiation4_ne
    end interface

    interface

        ! splicer begin class.Names2.additional_interfaces
        ! splicer end class.Names2.additional_interfaces

        ! splicer begin class.twoTs_0.additional_interfaces
        ! splicer end class.twoTs_0.additional_interfaces

        ! splicer begin class.twoTs_instantiation4.additional_interfaces
        ! splicer end class.twoTs_instantiation4.additional_interfaces

        ! ----------------------------------------
        ! Result
        ! Requested: c_unknown_scalar_result
        ! Match:     c_default
        subroutine yyy_tes_function1() &
                bind(C, name="YYY_TES_function1")
            implicit none
        end subroutine yyy_tes_function1

        ! ----------------------------------------
        ! Result
        ! Requested: c_unknown_scalar_result
        ! Match:     c_default
        subroutine f_c_name_special() &
                bind(C, name="c_name_special")
            implicit none
        end subroutine f_c_name_special

        ! ----------------------------------------
        ! Result
        ! Requested: c_unknown_scalar_result
        ! Match:     c_default
        ! ----------------------------------------
        ! Argument:  i
        ! Requested: c_native_scalar_in
        ! Match:     c_default
        subroutine yyy_tes_function3a_0(i) &
                bind(C, name="YYY_TES_function3a_0")
            use iso_c_binding, only : C_INT
            implicit none
            integer(C_INT), value, intent(IN) :: i
        end subroutine yyy_tes_function3a_0

        ! ----------------------------------------
        ! Result
        ! Requested: c_unknown_scalar_result
        ! Match:     c_default
        ! ----------------------------------------
        ! Argument:  i
        ! Requested: c_native_scalar_in
        ! Match:     c_default
        subroutine yyy_tes_function3a_1(i) &
                bind(C, name="YYY_TES_function3a_1")
            use iso_c_binding, only : C_LONG
            implicit none
            integer(C_LONG), value, intent(IN) :: i
        end subroutine yyy_tes_function3a_1

        ! ----------------------------------------
        ! Result
        ! Requested: c_native_scalar_result
        ! Match:     c_default
        ! ----------------------------------------
        ! Argument:  rv
        ! Requested: c_string_&_in
        ! Match:     c_string_in
        function yyy_tes_function4(rv) &
                result(SHT_rv) &
                bind(C, name="YYY_TES_function4")
            use iso_c_binding, only : C_CHAR, C_INT
            implicit none
            character(kind=C_CHAR), intent(IN) :: rv(*)
            integer(C_INT) :: SHT_rv
        end function yyy_tes_function4

        ! ----------------------------------------
        ! Result
        ! Requested: c_native_scalar_result_buf
        ! Match:     c_default
        ! ----------------------------------------
        ! Argument:  rv
        ! Requested: c_string_&_in_buf
        ! Match:     c_string_in_buf
        function yyy_tes_function4_bufferify(rv, Lrv) &
                result(SHT_rv) &
                bind(C, name="YYY_TES_function4_bufferify")
            use iso_c_binding, only : C_CHAR, C_INT
            implicit none
            character(kind=C_CHAR), intent(IN) :: rv(*)
            integer(C_INT), value, intent(IN) :: Lrv
            integer(C_INT) :: SHT_rv
        end function yyy_tes_function4_bufferify

        ! ----------------------------------------
        ! Result
        ! Requested: c_unknown_scalar_result
        ! Match:     c_default
        subroutine yyy_tes_fiveplus() &
                bind(C, name="YYY_TES_fiveplus")
            implicit none
        end subroutine yyy_tes_fiveplus

        ! ----------------------------------------
        ! Result
        ! Requested: c_unknown_scalar_result
        ! Match:     c_default
        ! ----------------------------------------
        ! Argument:  name
        ! Requested: c_string_&_inout
        ! Match:     c_string_inout
        ! ----------------------------------------
        ! Argument:  value
        ! Requested: c_native_*_out
        ! Match:     c_default
        subroutine c_test_multiline_splicer(name, value) &
                bind(C, name="TES_test_multiline_splicer")
            use iso_c_binding, only : C_CHAR, C_INT
            implicit none
            character(kind=C_CHAR), intent(INOUT) :: name(*)
            integer(C_INT), intent(OUT) :: value
        end subroutine c_test_multiline_splicer

        ! ----------------------------------------
        ! Result
        ! Requested: c_unknown_scalar_result_buf
        ! Match:     c_default
        ! ----------------------------------------
        ! Argument:  name
        ! Requested: c_string_&_inout_buf
        ! Match:     c_string_inout_buf
        ! ----------------------------------------
        ! Argument:  value
        ! Requested: c_native_*_out_buf
        ! Match:     c_default
        subroutine c_test_multiline_splicer_bufferify(name, Lname, &
                Nname, value) &
                bind(C, name="TES_test_multiline_splicer_bufferify")
            use iso_c_binding, only : C_CHAR, C_INT
            implicit none
            character(kind=C_CHAR), intent(INOUT) :: name(*)
            integer(C_INT), value, intent(IN) :: Lname
            integer(C_INT), value, intent(IN) :: Nname
            integer(C_INT), intent(OUT) :: value
        end subroutine c_test_multiline_splicer_bufferify

        ! ----------------------------------------
        ! Result
        ! Requested: c_unknown_scalar_result
        ! Match:     c_default
        ! ----------------------------------------
        ! Argument:  arg1
        ! Requested: c_native_scalar_in
        ! Match:     c_default
        ! ----------------------------------------
        ! Argument:  arg2
        ! Requested: c_native_scalar_in
        ! Match:     c_default
        subroutine f_c_name_instantiation1(arg1, arg2) &
                bind(C, name="c_name_instantiation1")
            use iso_c_binding, only : C_INT, C_LONG
            implicit none
            integer(C_INT), value, intent(IN) :: arg1
            integer(C_LONG), value, intent(IN) :: arg2
        end subroutine f_c_name_instantiation1

        ! ----------------------------------------
        ! Result
        ! Requested: c_unknown_scalar_result
        ! Match:     c_default
        ! ----------------------------------------
        ! Argument:  arg1
        ! Requested: c_native_scalar_in
        ! Match:     c_default
        ! ----------------------------------------
        ! Argument:  arg2
        ! Requested: c_native_scalar_in
        ! Match:     c_default
        subroutine c_function_tu_instantiation2(arg1, arg2) &
                bind(C, name="TES_function_tu_instantiation2")
            use iso_c_binding, only : C_DOUBLE, C_FLOAT
            implicit none
            real(C_FLOAT), value, intent(IN) :: arg1
            real(C_DOUBLE), value, intent(IN) :: arg2
        end subroutine c_function_tu_instantiation2

        ! ----------------------------------------
        ! Result
        ! Requested: c_native_scalar_result
        ! Match:     c_default
        function c_use_impl_worker_instantiation3() &
                result(SHT_rv) &
                bind(C, name="TES_use_impl_worker_instantiation3")
            use iso_c_binding, only : C_INT
            implicit none
            integer(C_INT) :: SHT_rv
        end function c_use_impl_worker_instantiation3

        ! splicer begin additional_interfaces
        ! splicer end additional_interfaces
    end interface

    interface function_tu
        module procedure f_name_instantiation1
        module procedure function_tu_instantiation2
    end interface function_tu

    interface generic3
        module procedure F_name_function3a_int
        module procedure F_name_function3a_long
    end interface generic3

contains

    ! Return pointer to C++ memory.
    function names2_get_instance(obj) result (cxxptr)
        use iso_c_binding, only: C_PTR
        class(names2), intent(IN) :: obj
        type(C_PTR) :: cxxptr
        cxxptr = obj%cxxmem%addr
    end function names2_get_instance

    subroutine names2_set_instance(obj, cxxmem)
        use iso_c_binding, only: C_PTR
        class(names2), intent(INOUT) :: obj
        type(C_PTR), intent(IN) :: cxxmem
        obj%cxxmem%addr = cxxmem
        obj%cxxmem%idtor = 0
    end subroutine names2_set_instance

    function names2_associated(obj) result (rv)
        use iso_c_binding, only: c_associated
        class(names2), intent(IN) :: obj
        logical rv
        rv = c_associated(obj%cxxmem%addr)
    end function names2_associated

    ! splicer begin class.Names2.additional_functions
    ! splicer end class.Names2.additional_functions

    ! Return pointer to C++ memory.
    function twots_0_get_instance(obj) result (cxxptr)
        use iso_c_binding, only: C_PTR
        class(twots_0), intent(IN) :: obj
        type(C_PTR) :: cxxptr
        cxxptr = obj%cxxmem%addr
    end function twots_0_get_instance

    subroutine twots_0_set_instance(obj, cxxmem)
        use iso_c_binding, only: C_PTR
        class(twots_0), intent(INOUT) :: obj
        type(C_PTR), intent(IN) :: cxxmem
        obj%cxxmem%addr = cxxmem
        obj%cxxmem%idtor = 0
    end subroutine twots_0_set_instance

    function twots_0_associated(obj) result (rv)
        use iso_c_binding, only: c_associated
        class(twots_0), intent(IN) :: obj
        logical rv
        rv = c_associated(obj%cxxmem%addr)
    end function twots_0_associated

    ! splicer begin class.twoTs_0.additional_functions
    ! splicer end class.twoTs_0.additional_functions

    ! Return pointer to C++ memory.
    function twots_instantiation4_get_instance_instantiation4(obj) result (cxxptr)
        use iso_c_binding, only: C_PTR
        class(twots_instantiation4), intent(IN) :: obj
        type(C_PTR) :: cxxptr
        cxxptr = obj%cxxmem%addr
    end function twots_instantiation4_get_instance_instantiation4

    subroutine twots_instantiation4_set_instance_instantiation4(obj, cxxmem)
        use iso_c_binding, only: C_PTR
        class(twots_instantiation4), intent(INOUT) :: obj
        type(C_PTR), intent(IN) :: cxxmem
        obj%cxxmem%addr = cxxmem
        obj%cxxmem%idtor = 0
    end subroutine twots_instantiation4_set_instance_instantiation4

    function twots_instantiation4_associated_instantiation4(obj) result (rv)
        use iso_c_binding, only: c_associated
        class(twots_instantiation4), intent(IN) :: obj
        logical rv
        rv = c_associated(obj%cxxmem%addr)
    end function twots_instantiation4_associated_instantiation4

    ! splicer begin class.twoTs_instantiation4.additional_functions
    ! splicer end class.twoTs_instantiation4.additional_functions

    ! void function1()
    ! ----------------------------------------
    ! Result
    ! Requested: f_subroutine
    ! Match:     f_default
    ! Requested: c
    ! Match:     c_default
    subroutine testnames_function1()
        ! splicer begin function.function1
        call yyy_tes_function1()
        ! splicer end function.function1
    end subroutine testnames_function1

    ! void function2()
    ! ----------------------------------------
    ! Result
    ! Requested: f_subroutine
    ! Match:     f_default
    ! Requested: c
    ! Match:     c_default
    subroutine f_name_special()
        ! splicer begin function.function2
        call f_c_name_special()
        ! splicer end function.function2
    end subroutine f_name_special

    ! void function3a(int i +intent(in)+value)
    ! ----------------------------------------
    ! Result
    ! Requested: f_subroutine
    ! Match:     f_default
    ! Requested: c
    ! Match:     c_default
    ! ----------------------------------------
    ! Argument:  i
    ! Requested: f_native_scalar_in
    ! Match:     f_default
    ! Requested: c_native_scalar_in
    ! Match:     c_default
    subroutine F_name_function3a_int(i)
        use iso_c_binding, only : C_INT
        integer(C_INT), value, intent(IN) :: i
        ! splicer begin function.function3a_0
        call yyy_tes_function3a_0(i)
        ! splicer end function.function3a_0
    end subroutine F_name_function3a_int

    ! void function3a(long i +intent(in)+value)
    ! ----------------------------------------
    ! Result
    ! Requested: f_subroutine
    ! Match:     f_default
    ! Requested: c
    ! Match:     c_default
    ! ----------------------------------------
    ! Argument:  i
    ! Requested: f_native_scalar_in
    ! Match:     f_default
    ! Requested: c_native_scalar_in
    ! Match:     c_default
    subroutine F_name_function3a_long(i)
        use iso_c_binding, only : C_LONG
        integer(C_LONG), value, intent(IN) :: i
        ! splicer begin function.function3a_1
        call yyy_tes_function3a_1(i)
        ! splicer end function.function3a_1
    end subroutine F_name_function3a_long

    ! int function4(const std::string & rv +intent(in))
    ! arg_to_buffer
    ! ----------------------------------------
    ! Result
    ! Requested: f_native_scalar_result
    ! Match:     f_default
    ! Requested: c_native_scalar_result_buf
    ! Match:     c_default
    ! ----------------------------------------
    ! Argument:  rv
    ! Requested: f_string_&_in
    ! Match:     f_default
    ! Requested: c_string_&_in_buf
    ! Match:     c_string_in_buf
    function testnames_function4(rv) &
            result(SHT_rv)
        use iso_c_binding, only : C_INT
        character(len=*), intent(IN) :: rv
        integer(C_INT) :: SHT_rv
        ! splicer begin function.function4
        SHT_rv = yyy_tes_function4_bufferify(rv, &
            len_trim(rv, kind=C_INT))
        ! splicer end function.function4
    end function testnames_function4

    ! void function5() +name(fiveplus)
    ! ----------------------------------------
    ! Result
    ! Requested: f_subroutine
    ! Match:     f_default
    ! Requested: c
    ! Match:     c_default
    subroutine testnames_fiveplus()
        ! splicer begin function.fiveplus
        call yyy_tes_fiveplus()
        ! splicer end function.fiveplus
    end subroutine testnames_fiveplus

    ! void TestMultilineSplicer(std::string & name +intent(inout), int * value +intent(out))
    ! arg_to_buffer
    ! ----------------------------------------
    ! Result
    ! Requested: f_subroutine
    ! Match:     f_default
    ! Requested: c
    ! Match:     c_default
    ! ----------------------------------------
    ! Argument:  name
    ! Requested: f_string_&_inout
    ! Match:     f_default
    ! Requested: c_string_&_inout_buf
    ! Match:     c_string_inout_buf
    ! ----------------------------------------
    ! Argument:  value
    ! Requested: f_native_*_out
    ! Match:     f_default
    ! Requested: c_native_*_out_buf
    ! Match:     c_default
    !>
    !! Use std::string argument to get bufferified function.
    !<
    subroutine test_multiline_splicer(name, value)
        use iso_c_binding, only : C_INT
        character(len=*), intent(INOUT) :: name
        integer(C_INT), intent(OUT) :: value
        ! splicer begin function.test_multiline_splicer
        ! line 1
        ! line 2
        ! splicer end function.test_multiline_splicer
    end subroutine test_multiline_splicer

    ! void FunctionTU(int arg1 +intent(in)+value, long arg2 +intent(in)+value)
    ! cxx_template
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
    ! ----------------------------------------
    ! Argument:  arg2
    ! Requested: f_native_scalar_in
    ! Match:     f_default
    ! Requested: c_native_scalar_in
    ! Match:     c_default
    !>
    !! \brief Function template with two template parameters.
    !!
    !<
    subroutine f_name_instantiation1(arg1, arg2)
        use iso_c_binding, only : C_INT, C_LONG
        integer(C_INT), value, intent(IN) :: arg1
        integer(C_LONG), value, intent(IN) :: arg2
        ! splicer begin function.function_tu_0
        call f_c_name_instantiation1(arg1, arg2)
        ! splicer end function.function_tu_0
    end subroutine f_name_instantiation1

    ! void FunctionTU(float arg1 +intent(in)+value, double arg2 +intent(in)+value)
    ! cxx_template
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
    ! ----------------------------------------
    ! Argument:  arg2
    ! Requested: f_native_scalar_in
    ! Match:     f_default
    ! Requested: c_native_scalar_in
    ! Match:     c_default
    !>
    !! \brief Function template with two template parameters.
    !!
    !<
    subroutine function_tu_instantiation2(arg1, arg2)
        use iso_c_binding, only : C_DOUBLE, C_FLOAT
        real(C_FLOAT), value, intent(IN) :: arg1
        real(C_DOUBLE), value, intent(IN) :: arg2
        ! splicer begin function.function_tu_instantiation2
        call c_function_tu_instantiation2(arg1, arg2)
        ! splicer end function.function_tu_instantiation2
    end subroutine function_tu_instantiation2

    ! int UseImplWorker()
    ! cxx_template
    ! ----------------------------------------
    ! Result
    ! Requested: f_native_scalar_result
    ! Match:     f_default
    ! Requested: c_native_scalar_result
    ! Match:     c_default
    !>
    !! \brief Function which uses a templated T in the implemetation.
    !!
    !<
    function use_impl_worker_instantiation3() &
            result(SHT_rv)
        use iso_c_binding, only : C_INT
        integer(C_INT) :: SHT_rv
        ! splicer begin function.use_impl_worker_instantiation3
        SHT_rv = c_use_impl_worker_instantiation3()
        ! splicer end function.use_impl_worker_instantiation3
    end function use_impl_worker_instantiation3

    ! splicer begin additional_functions
    ! splicer end additional_functions

    function names2_eq(a,b) result (rv)
        use iso_c_binding, only: c_associated
        type(names2), intent(IN) ::a,b
        logical :: rv
        if (c_associated(a%cxxmem%addr, b%cxxmem%addr)) then
            rv = .true.
        else
            rv = .false.
        endif
    end function names2_eq

    function names2_ne(a,b) result (rv)
        use iso_c_binding, only: c_associated
        type(names2), intent(IN) ::a,b
        logical :: rv
        if (.not. c_associated(a%cxxmem%addr, b%cxxmem%addr)) then
            rv = .true.
        else
            rv = .false.
        endif
    end function names2_ne

    function twots_0_eq(a,b) result (rv)
        use iso_c_binding, only: c_associated
        type(twots_0), intent(IN) ::a,b
        logical :: rv
        if (c_associated(a%cxxmem%addr, b%cxxmem%addr)) then
            rv = .true.
        else
            rv = .false.
        endif
    end function twots_0_eq

    function twots_0_ne(a,b) result (rv)
        use iso_c_binding, only: c_associated
        type(twots_0), intent(IN) ::a,b
        logical :: rv
        if (.not. c_associated(a%cxxmem%addr, b%cxxmem%addr)) then
            rv = .true.
        else
            rv = .false.
        endif
    end function twots_0_ne

    function twots_instantiation4_eq(a,b) result (rv)
        use iso_c_binding, only: c_associated
        type(twots_instantiation4), intent(IN) ::a,b
        logical :: rv
        if (c_associated(a%cxxmem%addr, b%cxxmem%addr)) then
            rv = .true.
        else
            rv = .false.
        endif
    end function twots_instantiation4_eq

    function twots_instantiation4_ne(a,b) result (rv)
        use iso_c_binding, only: c_associated
        type(twots_instantiation4), intent(IN) ::a,b
        logical :: rv
        if (.not. c_associated(a%cxxmem%addr, b%cxxmem%addr)) then
            rv = .true.
        else
            rv = .false.
        endif
    end function twots_instantiation4_ne

end module top_module
