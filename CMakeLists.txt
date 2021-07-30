cmake_minimum_required(VERSION 3.19)
project(untitled1 C)

set(CMAKE_C_STANDARD 11)

find_package(PkgConfig REQUIRED)
pkg_check_modules(GTK REQUIRED gtk+-3.0)
pkg_check_modules(GSTREAMER REQUIRED gstreamer-1.0)

include_directories(${GTK_INCLUDE_DIRS}  ${GSTREAMER_INCLUDE_DIRS})
link_directories(${GTK_LIBRARY_DIRS}  ${GSTREAMER_LIBRARY_DIRS})

add_executable(untitled1 main.c ports/gui_port.c ports/gui_port.h ports/player_control.h)
target_link_libraries(untitled1 ${GTK_LIBRARIES} ${GSTREAMER_LIBRARIES})
