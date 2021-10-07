cmake_minimum_required(VERSION 3.20)
project(Sortings C)

set(CMAKE_C_STANDARD 11)

add_executable(Sortings
        main.c sorting_algorithms.c sorting_algorithms.h)
