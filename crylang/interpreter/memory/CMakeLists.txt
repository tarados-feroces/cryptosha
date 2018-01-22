cmake_minimum_required(VERSION 3.8)
project(memory)

set(CMAKE_CXX_STANDARD 17)

set(SOURCE_FILES main.cpp memory.hpp)
add_executable(memory ${SOURCE_FILES})