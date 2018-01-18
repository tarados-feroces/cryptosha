cmake_minimum_required(VERSION 3.8)
project(translator)

set(CMAKE_CXX_STANDARD 17)

set(SOURCE_FILES includes.hpp main.cpp convertor/convertor.h convertor/convertor.cpp Reader/Reader.h Reader/Reader.cpp regs.hpp string_funcs.h vector_funcs.h string_funcs.cpp vector_funcs_impl.h syntax_constants.hpp)
add_executable(translator ${SOURCE_FILES})