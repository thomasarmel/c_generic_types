cmake_minimum_required(VERSION 3.23)
project(generic_types C)

set(CMAKE_C_STANDARD 99)

add_executable(generic_types main.c generic_type.c generic_type.h)
