cmake_minimum_required(VERSION 3.17)
project(my_compiler)

set(CMAKE_CXX_STANDARD 11)

add_executable(my_compiler main.cpp alphabet.cpp alphabet.h)
