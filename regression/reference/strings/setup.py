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
    'strings',
    sources=[
         'pystringsmodule.cpp',
         'pystringsutil.cpp'
    ],
    language='c++',
#    include_dirs = ['/usr/local/include'],
#    libraries = ['tcl83'],
#    library_dirs = ['/usr/local/lib'],      
)

setup(
    name='strings',
    ext_modules = [module],
)
