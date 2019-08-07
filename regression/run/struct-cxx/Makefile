# Copyright (c) 2017-2019, Lawrence Livermore National Security, LLC and
# other Shroud Project Developers.
# See the top-level COPYRIGHT file for details.
#
# run/struct-cxx
#
ifndef top
top = ../../..
endif


include $(top)/regression/run/defaults.mk

INCLUDE = \
    -I$(top)/regression/reference/struct-cxx \
    -I$(top)/regression/run/struct-c

VPATH = \
    $(top)/regression/reference/struct-cxx \
    $(top)/regression/run/fruit

OBJS = \
    struct.o \
    wrapfstruct.o \
    wrapstruct.o \
    fruit.o \
    main.o

struct-cxx : main.f struct.h struct.cpp $(OBJS)
	$(FC) $(FFLAGS) $(OBJS) -o $@ $(FLIBS)

# Copy all source files from run/struct, need to avoid VPATH.
# "convert" to c++
struct.cpp : $(top)/regression/run/struct-c/struct.c
	cp $< $@
struct.h : $(top)/regression/run/struct-c/struct.h
	cp $< $@
main.f : $(top)/regression/run/struct-c/main.f
	cp $< $@

clean :
	rm -f $(OBJS) *.mod struct-cxx

struct.o : struct.h
wrapstruct.o : wrapstruct.h struct.h
main.o : wrapfstruct.o