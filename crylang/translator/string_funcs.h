#pragma once

#include "includes.hpp"
#include "../language/code.hpp"
#include "vector_funcs.h"

using namespace cry;

namespace funcs{

    std::vector<string_t> parse(string_t& input_str, const string_t& divider) ;


    std::vector<string_t> multiple_parse(string_t& input_str, std::vector<string_t>& dividers) ;


    string_t space_free(string_t input_str) ;

}
