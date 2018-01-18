#pragma once
#include <iostream>
#include <fstream>
#include "convertor/convertor.h"
#include "../language/code.hpp"
//#include <regex>



class translator{

public:

    translator(){}


    translator(const string_t& in_name) : input(in_name) {}


    std::vector<string_t> read_one_cmd() {

        std::vector<string_t> result;
        std::stack<string_t> scopes;



    }


    void cmd_handle() {

    }


    void one_cmd_handle() {

    }






private:
    std::ifstream input;

    convertor conv;
    code_type output;

};
