# Copyright (c) 2023-2024 Michael Heilmann. All rights reserved.
# This file is licensed under MIT license.

cmake_minimum_required(VERSION 3.20)

project(idlib LANGUAGES C)

set(idlib-headers "${CMAKE_CURRENT_SOURCE_DIR}/includes/idlib.h")
set(idlib-sources "${CMAKE_CURRENT_SOURCE_DIR}/sources/idlib.c")

list(APPEND idlib-headers "${CMAKE_CURRENT_SOURCE_DIR}/includes/scalar.h")
list(APPEND idlib-sources "${CMAKE_CURRENT_SOURCE_DIR}/sources/scalar.c")

list(APPEND idlib-headers "${CMAKE_CURRENT_SOURCE_DIR}/includes/version.h")
list(APPEND idlib-sources "${CMAKE_CURRENT_SOURCE_DIR}/sources/version.c")

# For MSVC: Turn on several warnings.
if(MSVC)

  set(COMPILE_OPTIONS "")

  # C4090:  'opertion' : different 'modifier' qualifiers
  list(APPEND COMPILE_OPTIONS "/we4090")
  # C4133: 'function' incompatible types - from 'type1' to 'type2'
  list(APPEND COMPILE_OPTIONS "/we4133")
  # C4020_ 'function': too many actual parameters
  list(APPEND COMPILE_OPTIONS "/we4020")
  # C4013: 'function': undefined; assuming extern returning int
  list(APPEND COMPILE_OPTIONS "/we4013")
  # C4024: 'function': different types for formal and actual parameter 'number'
  list(APPEND COMPILE_OPTIONS "/we4024")
  # C4716: 'function' must return a value
  list(APPEND COMPILE_OPTIONS "/we4716")
  # C4013: 'function' undefined; assuming extern returning int
  list(APPEND COMPILE_OPTIONS "/we4013")

  # The quotes around "${COMPILE_OPTIONS}" concatenate the list elements to a single string separated by semicolons.
  set_source_files_properties(${idlib-sources} PROPERTIES COMPILE_OPTIONS "${COMPILE_OPTIONS}")
  set_source_files_properties(${idlib-headers} PROPERTIES COMPILE_OPTIONS "${COMPILE_OPTIONS}")

endif()

add_library(idlib STATIC)
target_sources(idlib PUBLIC ${idlib-headers})
target_sources(idlib PRIVATE ${idlib-sources})
target_include_directories(idlib PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/includes")
