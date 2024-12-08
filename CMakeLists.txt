cmake_minimum_required(VERSION 3.10)
project(PrintTree)

set(CMAKE_C_STANDARD 99)

include_directories(${CMAKE_SOURCE_DIR})

add_library(print_tree print_tree.c)

enable_testing()
add_subdirectory(tests)