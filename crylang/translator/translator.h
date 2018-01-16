#include <iostream>
#include <fstream>
#include "convertor/convertor.h"



class translator{

public:

    translator(){}

    translator(const string_t& in_name) : input(in_name) {}

    

private:
    std::ifstream input;

};
