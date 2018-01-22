#pragma once

#include <iostream>
#include "../includes.hpp"


namespace funcs{

    template <class T>
    void insert_one_elem(std::vector<T>& vector, size_t pos, T element);


    template <class T>
    void erase(std::vector<T>& vector, size_t pos);


    template <class T>
    void insert(std::vector<T>& vector, size_t pos, std::vector<T>& insert_vector);


    template <class T, class L>
    auto find(std::vector<T>& vector, L element);

}

#include "vector_funcs_impl.h"

