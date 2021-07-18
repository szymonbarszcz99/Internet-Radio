cmake_minimum_required(VERSION 3.19)
project(untitled1 C)

set(CMAKE_C_STANDARD 11)

find_package(PkgConfig REQUIRED)
pkg_check_modules(GTK REQUIRED gtk+-3.0)

include_directories(${GTK_INCLUDE_DIRS})
link_directories(${GTK_LIBRARY_DIRS})

add_executable(untitled1 main.c)
target_link_libraries(untitled1 ${GTK_LIBRARIES})
