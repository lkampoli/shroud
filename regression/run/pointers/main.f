! Copyright (c) 2017-2020, Lawrence Livermore National Security, LLC and
! other Shroud Project Developers.
! See the top-level COPYRIGHT file for details.
!
! SPDX-License-Identifier: (BSD-3-Clause)
! #######################################################################
!
! Test code generated by the pointers test.
! Used with pointers-c and pointers-cxx.
!
program tester
  use fruit
  use iso_c_binding
  use pointers_mod
  implicit none
  real(C_DOUBLE), parameter :: pi = 3.1415926_C_DOUBLE
  logical ok

  call init_fruit

  call test_functions
  call test_functions2
  call test_char_arrays
  call test_out_ptrs

  call fruit_summary
  call fruit_finalize

  call is_all_successful(ok)
  if (.not. ok) then
     call exit(1)
  endif

contains

  subroutine test_functions
    integer(c_int) iargin, iarginout, iargout
    real(c_double) :: in_double(5)
    real(c_double), allocatable :: out_double(:)
    integer(c_int), allocatable :: out_int(:)
    integer(c_int) :: nvalues, values1(3), values2(3)

    call set_case_name("test_functions")

    iargin    = 1
    iarginout = 2
    iargout   = -1
    call intargs(iargin, iarginout, iargout)
    call assert_true(iarginout == 1)
    call assert_true(iargout   == 2)

    call assert_false(allocated(out_double))
    in_double = [0.0*pi, 0.5*pi, pi, 1.5*pi, 2.0*pi]
    call cos_doubles(in_double, out_double)
    call assert_true(allocated(out_double))
    call assert_true(all(abs(out_double - cos(in_double)) < 1.e-08 ))

    call assert_false(allocated(out_int))
    call truncate_to_int([1.2d0, 2.3d0, 3.4d0, 4.5d0], out_int)
    call assert_true(allocated(out_int))
    call assert_true(all(out_int == [1, 2, 3, 4]))

    values1 = 0
    call get_values(nvalues, values1)
    call assert_equals(3, nvalues)
    call assert_true(all(values1(1:3) == [1, 2, 3]))

    values1 = 0
    values2 = 0
    call get_values2(values1, values2)
    call assert_true(all(values1(1:3) == [1, 2, 3]))
    call assert_true(all(values2(1:3) == [11, 12, 13]))

    values1 = 0
    call iota_allocatable(nvalues, values1)
    call assert_equals(3, nvalues)
    call assert_true(all(values1(1:3) == [1, 2, 3]))

    values1 = 0
    call iota_dimension(nvalues, values1)
    call assert_equals(3, nvalues)
    call assert_true(all(values1(1:3) == [1, 2, 3]))

  end subroutine test_functions

  subroutine test_functions2
    integer(c_int) rv_int, out(3), values(5)

    call set_case_name("test_functions2")

    call sum([1,2,3,4,5], rv_int)
    call assert_true(rv_int .eq. 15, "sum")

    out = 0
    call fill_int_array(out)
    call assert_true(all(out(1:3) == [1, 2, 3]), "fillIntArray")

    values = [1, 2, 3, 4, 5]
    call increment_int_array(values)
    call assert_true(all(values(1:5) == [2, 3, 4, 5, 6]), "incrementIntArray")

  end subroutine test_functions2

  subroutine test_char_arrays
    character(10) :: in(3) = [ &
         "dog       ", &
         "cat       ", &
         "monkey    "  &
         ]
    character(10), target :: word1, word2, word3
    type(C_PTR)  cin(4)

    call set_case_name("test_char_arrays")

    ! Call the bufferify function.
    ! It will copy strings to create char ** variable.
    call accept_char_array_in(in)

    ! Build up a native char ** variable and pass to C.
    ! Caller is responsibile for explicilty NULL terminating.
    word1 = "word1" // C_NULL_CHAR
    word2 = "word2+" // C_NULL_CHAR
    word3 = "word3long" // C_NULL_CHAR
    cin(1) = c_loc(word1)
    cin(2) = c_loc(word2)
    cin(3) = c_loc(word3)
    cin(4) = C_NULL_PTR
    call c_accept_char_array_in(cin)
    
  end subroutine test_char_arrays

  subroutine test_out_ptrs
    integer(C_INT), pointer :: iscalar, irvscalar
    integer(C_INT), pointer :: iarray(:), irvarray
    type(C_PTR) :: cptr_scalar, cptr_array
    type(C_PTR) :: void

    call set_global_int(0)
    call get_ptr_to_scalar(iscalar)
    call assert_equals(0, iscalar)

    ! iscalar points to global_int in pointers.c.
    call set_global_int(5)
    call assert_equals(5, iscalar)

    nullify(iarray)
    call get_ptr_to_fixed_array(iarray)
    call assert_equals(10, size(iarray))
    iarray = 0
    call assert_equals(0, sum_fixed_array())
    ! Make sure we're assigning to global_array.
    iarray(1) = 1
    iarray(10) = 2
    call assert_equals(3, sum_fixed_array())

    ! Returns global_array in pointers.c.
    nullify(iarray)
    call get_ptr_to_dynamic_array(iarray)
    call assert_true( associated(iarray))
    call assert_true( size(iarray) == 10 )

    ! Returns global_array in pointers.c.
    nullify(iarray)
    call get_ptr_to_func_array(iarray)
    call assert_true( associated(iarray))
    call assert_true( size(iarray) == 10 )

    call get_raw_ptr_to_scalar(cptr_scalar)
    call assert_true(c_associated(cptr_scalar))
    ! associated with global_int in pointers.c
    call assert_true(c_associated(cptr_scalar, c_loc(iscalar)))

    call get_raw_ptr_to_fixed_array(cptr_array)
    call assert_true(c_associated(cptr_array))
    ! associated with global_fixed_array in pointers.c
    call assert_true(c_associated(cptr_array, c_loc(iarray)))

    ! Return pointer to global_int as a type(C_PTR)
    ! via interface
    void = return_address1(1)
    call assert_true(c_associated(void, cptr_scalar))
    ! via wrapper
    void = return_address2(1)
    call assert_true(c_associated(void, cptr_scalar))

    nullify(irvscalar)
    irvscalar => return_int_ptr_to_scalar()
    call assert_true(associated(irvscalar, iscalar))

    irvarray => return_int_ptr_to_fixed_array()
    
  end subroutine test_out_ptrs
  
end program tester
