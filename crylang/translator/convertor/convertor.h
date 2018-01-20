#pragma once

#include "includes.hpp"
#include "string_funcs.h"
#include "syntax_constants.hpp"

#include <iostream>
#include <stack>
#include <map>
#include <vector>
//#include "../vector_funcs.hpp"

using namespace cry;
using namespace cry::lang;
using namespace cry::code;

class convertor{

public:
    explicit convertor();


    convertor(string_t input_str) : str(input_str) {}


    void change_str(string_t input_str);


    const string_t get_str() const;


    expression_t handle();


    ~convertor() = default;


private:

    void structure_handle(expression_t& output, string_t& input_str);


    string_t str;

    std::vector<object_view> output;

    std::vector<string_t> dividers;

    size_t max_length_of_operator = 2;

    map_t operations = {
            {"=", 0},
            {"<-", 0},
            {"<->", 0},
            {"!=", 1},
            {"==", 1},
            {">", 1},
            {"<", 1},
            {"+", 2},
            {"-", 2},
            {"/", 3},
            {"%", 3},
            {"*", 3},
            {"^", 4},
    };

    std::map<string_t, object_view> op_to_obj = {
            {"=", operators::assign_copy},
            {"<-", operators::assign_move},
            {"<->", operators::swap},
            {"!=", operators::not_equal},
            {"==", operators::equal},
            {">", operators::greater},
            {"<", operators::less},
            {"+", operators::plus},
            {"-", operators::minus},
            {"/", operators::div},
            {"%", operators::mod},
            {"*", operators::mult},
            {"^", operators::degree},
            {".", operators::class_member},
    };
};
