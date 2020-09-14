cmake_minimum_required(VERSION 3.17)
project(csort C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_FLAGS_RELEASE "-O3")

add_executable(csort main.c)