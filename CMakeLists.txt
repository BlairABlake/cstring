cmake_minimum_required(VERSION 3.25)
project(cstring C)

set(CMAKE_C_STANDARD 17)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/lib/munit)

add_library(cstring cstring.c)
add_library(munit ${CMAKE_CURRENT_SOURCE_DIR}/lib/munit/munit.c)

add_executable(test test.c cstring.h ${CMAKE_CURRENT_SOURCE_DIR}/lib/munit/munit.h)
target_link_libraries(test cstring munit)