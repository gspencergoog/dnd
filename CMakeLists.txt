cmake_minimum_required(VERSION 3.10)
find_package(GTK REQUIRED)

project(dnd)

set(CMAKE_CXX_STANDARD 17)

find_package(GTK REQUIRED)

include_directories(${GTK_INCLUDE_DIRS})

add_executable(dnd_source dnd_source.cpp)
target_link_libraries(dnd_source PRIVATE GTK::gtkmm)

add_executable(dnd_dest dnd_dest.cpp)
target_link_libraries(dnd_dest PRIVATE GTK::gtkmm)