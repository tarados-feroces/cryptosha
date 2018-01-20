#pragma once

#include <iostream>
#include "includes.hpp"


namespace funcs{

    template <class T>
    void insert_one_elem(std::vector<T>& vector, size_t pos, T element);


    template <class T>
    void erase(std::vector<T>& vector, size_t pos);

    template <class T>
    void insert(std::vector<T>& vector, size_t pos, std::vector<T>& insert_vector);

    template <class T>
    bool find(std::vector<T>& vector, T element);

}

#include "vector_funcs_impl.h"

//string_funcs_tests:
//        $(compiler) $(std_version) string_funcs.cpp -o string_funcs.test.out
//./string_funcs.test.out
//
//        vector_funcs_tests:
//$(compiler) $(std_version) vector_funcs.cpp -o vector_funcs.test.out
//./vector_funcs.test.out
//
//        reader_tests:
//$(compiler) $(std_version) reader.cpp -o reader.test.out
//./reader.test.out
