cmake_minimum_required(VERSION 3.27)
project(Zephylix C)

set(CMAKE_C_STANDARD 11)

add_executable(Zephylix
        c/sources/main.c
        challenges/main.c
        c/include/common.h
        c/include/chunk.h)
