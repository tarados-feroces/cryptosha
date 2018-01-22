#pragma once

#include "convertor/operations_handler.h"

namespace handler {

    static std::vector<operation> ops = {
            {syntax::swap,        priority::v_v_v_low, cry::lang::operators::swap},
            {syntax::equal,       priority::v_v_low,   cry::lang::operators::equal},
            {syntax::not_equal,   priority::v_v_low,   cry::lang::operators::not_equal},
            {syntax::assign_copy, priority::v_v_v_low, cry::lang::operators::assign_copy},  // операторы с большим кол-вом символов должны располагаться первыми
            {syntax::assign_move, priority::v_v_v_low, cry::lang::operators::assign_move},
            {syntax::greater,     priority::v_v_low,   cry::lang::operators::greater},
            {syntax::less,        priority::v_v_low,   cry::lang::operators::less},
            {syntax::conv,        priority::v_low, cry::lang::operators::conv},
            {syntax::plus,        priority::v_low,     cry::lang::operators::plus},
            {syntax::minus,       priority::v_low,     cry::lang::operators::minus},
            {syntax::multi,       priority::low,       cry::lang::operators::mult},
            {syntax::div,         priority::low,       cry::lang::operators::div},
            {syntax::mod,         priority::low,       cry::lang::operators::mod},
            {syntax::degree,      priority::medium,    cry::lang::operators::degree}
    };


    static operations_handler handler(ops);
}
