#pragma once

#include <iostream>
#include "includes.hpp"


namespace funcs{

    template <class T>
    void insert_one_elem(std::vector<T>& vector, int pos, T& element);


    template <class T>
    void erase(std::vector<T>& vector, int pos);

    template <class T>
    void insert(std::vector<T>& vector, int pos, std::vector<T>& insert_vector);

//    void lol() ;

}

#include "vector_funcs_impl.h"
