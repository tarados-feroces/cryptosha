#pragma once

#include "operation.hpp"



struct operations{

public:

    operations(){
        ops = {
                operation(syntax::swap, priority::v_v_v_low, cry::lang::operators::swap),
                operation(syntax::equal, priority::v_v_low, cry::lang::operators::equal),
                operation(syntax::not_equal, priority::v_v_low, cry::lang::operators::not_equal),
                operation(syntax::assign_copy, priority::v_v_v_low, cry::lang::operators::assign_copy),  // операторы с большим кол-вом символов должны располагаться первыми
                operation(syntax::assign_move, priority::v_v_v_low, cry::lang::operators::assign_move),
                operation(syntax::greater, priority::v_v_low, cry::lang::operators::greater),
                operation(syntax::less, priority::v_v_low, cry::lang::operators::less),
                operation(syntax::plus, priority::v_low, cry::lang::operators::plus),
                operation(syntax::minus, priority::v_low, cry::lang::operators::minus),
                operation(syntax::multi, priority::low, cry::lang::operators::mult),
                operation(syntax::div, priority::low, cry::lang::operators::div),
                operation(syntax::mod, priority::low, cry::lang::operators::mod),
                operation(syntax::degree, priority::medium, cry::lang::operators::degree)
        };
    }


    std::vector<string_t> get_names() {
        std::vector<string_t> result;
        for(auto& it : ops)
            result.push_back(it.name());

        return result;
    }


    std::vector<operation> ops;

};
