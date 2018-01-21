cmake_minimum_required(VERSION 3.8)
project(translator)

set(CMAKE_CXX_STANDARD 17)

set(SOURCE_FILES includes.hpp main.cpp convertor/convertor.h convertor/convertor.cpp console_reader/console_reader.h console_reader/console_reader.cpp regs.hpp funcs/string_funcs.h funcs/vector_funcs.h funcs/string_funcs.cpp funcs/vector_funcs_impl.h syntax_constants.hpp convertor/operations_handler.h convertor/operations_handler.cpp convertor/operation.hpp convertor/operations.hpp handler.hpp)

include_directories(funcs convertor console_reader ./ ..)

add_executable(translator ${SOURCE_FILES})