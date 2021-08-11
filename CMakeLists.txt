cmake_minimum_required(VERSION 3.19)
project(untitled1 C)

set(CMAKE_C_STANDARD 11)

find_package(PkgConfig REQUIRED)
pkg_check_modules(GTK REQUIRED gtk+-3.0)
pkg_check_modules(GSTREAMER REQUIRED gstreamer-1.0)

include_directories(${GTK_INCLUDE_DIRS}  ${GSTREAMER_INCLUDE_DIRS})
link_directories(${GTK_LIBRARY_DIRS}  ${GSTREAMER_LIBRARY_DIRS})

add_executable(untitled1 main.c gui/gui_init.c gui/gui_init.h player/player_data.h gui/widgets_init.c gui/widgets_init.h gui/gui_elements.h player/player_init.c player/player_init.h link_parser/parser_init.c link_parser/parser_init.h link_parser/get_stations.c link_parser/get_stations.h)
target_link_libraries(untitled1 ${GTK_LIBRARIES} ${GSTREAMER_LIBRARIES})
