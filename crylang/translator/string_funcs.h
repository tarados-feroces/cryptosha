#pragma once

#include "includes.hpp"
#include "../language/code.hpp"
#include "vector_funcs.h"

using namespace cry;

namespace funcs{

    std::vector<string_t> parse(string_t& input_str, const string_t& divider) ;


    std::vector<string_t> multiple_parse(string_t& input_str, std::vector<string_t>& dividers) ;


    string_t space_free(string_t input_str) ;


//    int sys_transfer(string_t str, string_t mod) {
//        int numb = 0;
//        int res = 0;
//        if (mod == "d")
//        {
//            res = stoi(str);
//        }
//        else if (mod == "b")
//        {
//            string_t source("01");
//            auto it = --str.end();
//            for (; it != str.begin(); --it)
//            {
//                res += source.find(*it) * pow(2.0, (double)numb);
//                ++numb;
//            }
//            res += source.find(*it) * pow(2.0, (double)numb);
//        }
//        else if (mod == "h")
//        {
//            string_t source("0123456789abcdef");
//            auto it = --str.end();
//            for (; it != str.begin(); --it)
//            {
//                res += source.find(*it) * pow(16.0, (double)numb);
//                ++numb;
//            }
//            res += source.find(*it) * pow(16.0, (double)numb);
//        }
//        return res;
//    }

}
