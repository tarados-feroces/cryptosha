#pragma once


#include "operations_handler.h"

#include <iostream>
#include <stack>
#include <map>
#include <vector>

using namespace cry;
using namespace cry::lang;
using namespace cry::code;

class convertor{

public:
    explicit convertor();


    explicit convertor(string_t input_str) : str(input_str), ops_handler(syntax::lol) {}


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

    operations_handler ops_handler;

};
