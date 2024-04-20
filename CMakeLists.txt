# Copyright (c) 2023-2024 Michael Heilmann. All rights reserved.
# This file is licensed under the "zlib License".

cmake_minimum_required(VERSION 3.20)

project(idlib-math LANGUAGES C)

set(idlib-math-cmake-files-dir ${CMAKE_CURRENT_SOURCE_DIR}/cmake)

add_subdirectory(library)
