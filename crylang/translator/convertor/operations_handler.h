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

    operations_handler() = default;


    bool handle_operation(expression_t &output, string_t input);


    bool close_stack(expression_t &output);


    ~operations_handler() = default;


//    map_t op_to_prior = {
//            {syntax::assign_copy, 0},
//            {syntax::assign_move, 0},
//            {syntax::swap, 0},
//            {syntax::not_equal, 1},
//            {syntax::equal, 1},
//            {syntax::greater, 1},
//            {syntax::less, 1},
//            {syntax::plus, 2},
//            {syntax::minus, 2},
//            {syntax::div, 3},
//            {syntax::mod, 3},
//            {syntax::multi, 3},
//            {syntax::degree, 4}
//    };
//
//    std::map<string_t, object_view> op_to_obj = {
//            {syntax::assign_copy, operators::assign_copy},
//            {syntax::assign_move, operators::assign_move},
//            {syntax::swap, operators::swap},
//            {syntax::not_equal, operators::not_equal},
//            {syntax::equal, operators::equal},
//            {syntax::greater, operators::greater},
//            {syntax::less, operators::less},
//            {syntax::plus, operators::plus},
//            {syntax::minus, operators::minus},
//            {syntax::div, operators::div},
//            {syntax::mod, operators::mod},
//            {syntax::multi, operators::mult},
//            {syntax::degree, operators::degree},
//            {syntax::class_member, operators::class_member}
//    };

    operations ops;

private:

    bool handle_operator(expression_t &output, string_t input);


    bool handle_open_scope(expression_t &output, string_t input);


    bool handle_close_scope(expression_t &output, string_t input);


    bool handle_args_divider(expression_t &output, string_t input);


    std::stack<operation> stack_op;



};