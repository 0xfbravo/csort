cmake_minimum_required(VERSION 3.17)
project(csort)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS -O3)

include_directories(.)
include_directories(core)
include_directories(sort)

add_executable(csort
        core/core.c
        core/core.h
        sort/sort.c
        sort/sort.h
        LICENSE
        main.c
        README.md)
