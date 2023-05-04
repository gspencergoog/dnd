# Copyright 2013 The Flutter Authors. All rights reserved.
# Use of this source code is governed by a BSD-style license that can be
# found in the LICENSE file.

cmake_minimum_required(VERSION 3.5)

project(dnd)

set(CMAKE_CXX_STANDARD 11)

find_package(PkgConfig REQUIRED)
pkg_check_modules(GTK3 REQUIRED gtk+-3.0)

include_directories(${GTK3_INCLUDE_DIRS})
link_directories(${GTK3_LIBRARY_DIRS})

add_compile_options(${GTK3_CFLAGS_OTHER})

add_executable(dnd_source dnd_source.cpp)
target_link_libraries(dnd_source ${GTK3_LIBRARIES})

add_executable(dnd_dest dnd_dest.cpp)
target_link_libraries(dnd_dest ${GTK3_LIBRARIES})