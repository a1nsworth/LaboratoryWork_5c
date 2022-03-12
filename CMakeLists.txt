cmake_minimum_required(VERSION 3.21)
project(laba5c C)

set(CMAKE_C_STANDARD 23)

add_executable(laba5c main.c)

add_subdirectory(includes)

target_link_libraries(laba5c includes)