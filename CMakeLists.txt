cmake_minimum_required(VERSION 3.22)
project(colorex_c C)

set(CMAKE_C_STANDARD 11)

add_library(colorex_c SHARED src/colorize.c
        src/colorize.h
)
