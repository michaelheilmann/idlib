# Copyright (c) 2023-2024 Michael Heilmann. All rights reserved.
# This file is licensed under MIT license.

cmake_minimum_required(VERSION 3.20)

project(idlib LANGUAGES C)

set(idlib-headers "${CMAKE_CURRENT_SOURCE_DIR}/includes/idlib.h")
set(idlib-sources "${CMAKE_CURRENT_SOURCE_DIR}/sources/idlib.c")

list(APPEND idlib-headers "${CMAKE_CURRENT_SOURCE_DIR}/includes/scalar.h")
list(APPEND idlib-sources "${CMAKE_CURRENT_SOURCE_DIR}/sources/scalar.c")

list(APPEND idlib-headers "${CMAKE_CURRENT_SOURCE_DIR}/includes/matrix_4x4.h")
list(APPEND idlib-sources "${CMAKE_CURRENT_SOURCE_DIR}/sources/matrix_4x4.c")

list(APPEND idlib-headers "${CMAKE_CURRENT_SOURCE_DIR}/includes/vector_2.h")
list(APPEND idlib-sources "${CMAKE_CURRENT_SOURCE_DIR}/sources/vector_2.c")

list(APPEND idlib-headers "${CMAKE_CURRENT_SOURCE_DIR}/includes/vector_3.h")
list(APPEND idlib-sources "${CMAKE_CURRENT_SOURCE_DIR}/sources/vector_3.c")

list(APPEND idlib-headers "${CMAKE_CURRENT_SOURCE_DIR}/includes/version.h")
list(APPEND idlib-sources "${CMAKE_CURRENT_SOURCE_DIR}/sources/version.c")

# For MSVC: Turn on several warnings.
if(MSVC)

  set(idlib_compile_options "")

  # C4090:  'opertion' : different 'modifier' qualifiers
  list(APPEND idlib_compile_options "/we4090")
  # C4133: 'function' incompatible types - from 'type1' to 'type2'
  list(APPEND idlib_compile_options "/we4133")
  # C4020_ 'function': too many actual parameters
  list(APPEND idlib_compile_options "/we4020")
  # C4013: 'function': undefined; assuming extern returning int
  list(APPEND idlib_compile_options "/we4013")
  # C4024: 'function': different types for formal and actual parameter 'number'
  list(APPEND idlib_compile_options "/we4024")
  # C4716: 'function' must return a value
  list(APPEND idlib_compile_options "/we4716")
  # C4013: 'function' undefined; assuming extern returning int
  list(APPEND idlib_compile_options "/we4013")

  # The quotes around "${idlib_compile_options}" concatenate the list elements to a single string separated by semicolons.
  set_source_files_properties(${idlib-sources} PROPERTIES COMPILE_OPTIONS "${idlib_compile_options}")
  set_source_files_properties(${idlib-headers} PROPERTIES COMPILE_OPTIONS "${idlib_compile_options}")

endif()

add_library(idlib STATIC ${idlib-headers} ${idlib-sources})
target_include_directories(idlib PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/includes")
