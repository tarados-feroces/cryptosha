#pragma once

#include "../includes.hpp"
#include "../funcs/string_funcs.h"
#include "../syntax_constants.hpp"
#include "operations.hpp"

#include <iostream>
#include <stack>
#include <map>
#include <vector>

using namespace cry;
using namespace cry::lang;
using namespace cry::code;

class operations_handler{

public:

    operations_handler();


    bool handle_operation(expression_t &output, string_t input);


    bool close_stack(expression_t &output);


    ~operations_handler() = default;


    operations ops;

private:

    bool handle_operator(expression_t &output, string_t input);


    bool handle_open_scope(expression_t &output, string_t input);


    bool handle_close_scope(expression_t &output, string_t input);


    bool handle_args_divider(expression_t &output, string_t input);


    std::stack<operation> stack_op;



};