#pragma once

#include <iostream>
#include <array>
#include "includes.hpp"
#include "convertor/operations.hpp"



namespace syntax {
    static const cry::string_t block_open_scope = "{";
    static const cry::string_t block_close_scope = "}";
    static const cry::string_t open_scope = "(";
    static const cry::string_t close_scope = ")";

    static const cry::string_t class_member = ".";

    static const cry::string_t divider = ",";

    static const cry::string_t assign_copy = "=";
    static const cry::string_t assign_move = "<-";
    static const cry::string_t swap = "<->";
    static const cry::string_t less = "<";
    static const cry::string_t greater = ">";
    static const cry::string_t equal = "==";
    static const cry::string_t not_equal = "!=";
    static const cry::string_t multi = "*";
    static const cry::string_t degree = "^";
    static const cry::string_t div = "/";
    static const cry::string_t mod = "%";
    static const cry::string_t minus = "-";
    static const cry::string_t plus = "+";


    static std::vector<operation> lol = {
            {syntax::swap, priority::v_v_v_low, cry::lang::operators::swap},
            {syntax::equal, priority::v_v_low, cry::lang::operators::equal},
            {syntax::not_equal, priority::v_v_low, cry::lang::operators::not_equal},
            {syntax::assign_copy, priority::v_v_v_low, cry::lang::operators::assign_copy},  // операторы с большим кол-вом символов должны располагаться первыми
            {syntax::assign_move, priority::v_v_v_low, cry::lang::operators::assign_move},
            {syntax::greater, priority::v_v_low, cry::lang::operators::greater},
            {syntax::less, priority::v_v_low, cry::lang::operators::less},
            {syntax::plus, priority::v_low, cry::lang::operators::plus},
            {syntax::minus, priority::v_low, cry::lang::operators::minus},
            {syntax::multi, priority::low, cry::lang::operators::mult},
            {syntax::div, priority::low, cry::lang::operators::div},
            {syntax::mod, priority::low, cry::lang::operators::mod},
            {syntax::degree, priority::medium, cry::lang::operators::degree}
    };


}



