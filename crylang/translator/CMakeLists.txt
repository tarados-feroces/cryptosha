cmake_minimum_required(VERSION 3.8)
project(translator)

set(CMAKE_CXX_STANDARD 17)

set(SOURCE_FILES main.cpp translator.cpp translator.h convertor/convertor.h convertor/convertor.cpp)
add_executable(translator ${SOURCE_FILES})