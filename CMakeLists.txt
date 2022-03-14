cmake_minimum_required(VERSION 3.19.2)
project(laba5c C)

set(CMAKE_C_STANDARD 11)

add_executable(laba5c main.c)

add_subdirectory(includes)

target_link_libraries(laba5c includes)