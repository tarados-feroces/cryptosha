#include <iostream>
#include "convertor/convertor.h"
#include <list>

int main() {
    convertor con("d.sum(a+b,k(c,4+2-1,6),(g-h))");
    con.handle();

//    std::vector<string_t> dividers = {"+", "-", "*", "/", ".", "(", ")", "^", ","};

//    auto parsed_string = con.multiple_parse(str, dividers);

//    for(auto& string : parsed_string)
//        std::cout << string << std::endl;
//    con.handle();

    return 0;
}