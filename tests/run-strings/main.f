! Copyright (c) 2017, Lawrence Livermore National Security, LLC. 
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
!
! Test code generated by the strings test
!
program tester
  use fruit
  use iso_c_binding
  use strings_mod
  implicit none
  logical ok

  call init_fruit

  call test_charargs
  call test_charargs_c
  call test_functions

  call fruit_summary
  call fruit_finalize

  call is_all_successful(ok)
  if (.not. ok) then
     call exit(1)
  endif

contains

  subroutine test_charargs
    ! test C++ functions

    character(30) str
    character ch

    call set_case_name("test_charargs")

    call pass_char("w")

    ch = return_char()
    call assert_true( ch == "w")

    ! character(*) function
    str = 'XXXXXXXXXXXXXXXXXXXXXXXXXXXXXX'
    call pass_char_ptr(dest=str, src="bird")
    call assert_true( str == "bird")

    ! call C version directly via the interface
    ! caller is responsible for nulls
    str = 'XXXXXXXXXXXXXXXXXXXXXXXXXXXXXX'
    call c_pass_char_ptr(dest=str, src="mouse" // C_NULL_CHAR)
    call assert_true( str(1:5) == "mouse")
    call assert_true( str(6:6) == C_NULL_CHAR)

    str = 'dog'
    call pass_char_ptr_in_out(str)
    call assert_true( str == "DOG")

  end subroutine test_charargs

  subroutine test_charargs_c
    ! test extern "C" functions

    character(30) str
    character ch

    call set_case_name("test_charargs_c")

!    call pass_char("w")

!    ch = return_char()
!    call assert_true( ch == "w")

    ! character(*) function
    str = 'XXXXXXXXXXXXXXXXXXXXXXXXXXXXXX'
    call cpass_char_ptr(dest=str, src="bird")
    call assert_true( str == "bird")

    ! call C version directly via the interface
    ! caller is responsible for nulls
!    str = 'XXXXXXXXXXXXXXXXXXXXXXXXXXXXXX'
!    call c_pass_char_ptr(dest=str, src="mouse" // C_NULL_CHAR)
!    call assert_true( str(1:5) == "mouse")
!    call assert_true( str(6:6) == C_NULL_CHAR)

!    str = 'dog'
!    call pass_char_ptr_in_out(str)
!    call assert_true( str == "DOG")

  end subroutine test_charargs_c

  subroutine test_functions

    character(30) str

    call set_case_name("test_functions")

    ! character(*) function
    str = 'XXXXXXXXXXXXXXXXXXXXXXXXXXXXXX'
    str = get_char1()
    call assert_true( str == "bird")

    ! character(30) function
    str = 'XXXXXXXXXXXXXXXXXXXXXXXXXXXXXX'
    str = get_char2()
    call assert_true( str == "bird")

    ! string_result_as_arg
    str = 'XXXXXXXXXXXXXXXXXXXXXXXXXXXXXX'
    call get_char3(str)
    call assert_true( str == "bird")
 
!--------------------------------------------------

    ! character(*) function
    str = 'XXXXXXXXXXXXXXXXXXXXXXXXXXXXXX'
    str = get_string1()
    call assert_true( str == "dog")

    ! character(30) function
    str = 'XXXXXXXXXXXXXXXXXXXXXXXXXXXXXX'
    str = get_string2()
    call assert_true( str == "dog")

    ! string_result_as_arg
    str = 'XXXXXXXXXXXXXXXXXXXXXXXXXXXXXX'
    call get_string3(str)
    call assert_true( str == "dog")
 
    ! character(30) function
    str = 'XXXXXXXXXXXXXXXXXXXXXXXXXXXXXX'
    str = get_string2_empty()
    call assert_true( str == " ")

!--------------------------------------------------

    ! character(30) function
    str = 'XXXXXXXXXXXXXXXXXXXXXXXXXXXXXX'
    str = get_string5()
    call assert_true( str == "dog")

    ! string_result_as_arg
    str = 'XXXXXXXXXXXXXXXXXXXXXXXXXXXXXX'
    call get_string6(str)
    call assert_true( str == "dog")
 
!--------------------------------------------------

    call accept_string_const_reference("cat")
!    call assert_true( rv_char == "dog")

    str = " "
    call accept_string_reference_out(str)
    call assert_true( str == "dog")

    str = "cat"
    call accept_string_reference(str)
    call assert_true( str == "catdog")

    ! call C version directly via the interface
    ! caller is responsible for nulls
    ! str must be long enough for the result from the function
    str = "cat" // C_NULL_CHAR
    call c_accept_string_reference(str)
    call assert_true( str(1:6) == "catdog")
    call assert_true( str(7:7) == C_NULL_CHAR)

  end subroutine test_functions

end program tester
