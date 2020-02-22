# setup.py
# This file is generated by Shroud 0.11.0. Do not edit.
# Copyright (c) 2017-2020, Lawrence Livermore National Security, LLC and
# other Shroud Project Developers.
# See the top-level COPYRIGHT file for details.
#
# SPDX-License-Identifier: (BSD-3-Clause)
#

from setuptools import setup, Extension

module = Extension(
    'ns',
    sources=[
         'pyouter_Cstruct1type.cpp',
         'pyns_outermodule.cpp',
         'pynswork_ClassWorktype.cpp',
         'pyns_nsworkmodule.cpp',
         'pynsmodule.cpp',
         'pynsutil.cpp'
    ],
    language='c++',
#    include_dirs = ['/usr/local/include'],
#    libraries = ['tcl83'],
#    library_dirs = ['/usr/local/lib'],      
)

setup(
    name='ns',
    ext_modules = [module],
)
