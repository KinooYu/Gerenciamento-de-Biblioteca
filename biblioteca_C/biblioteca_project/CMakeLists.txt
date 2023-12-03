cmake_minimum_required(VERSION 3.17)
project(biblioteca_project C)

set(CMAKE_C_STANDARD 99)

add_executable(biblioteca_project main.c biblioteca.c biblioteca.h)
