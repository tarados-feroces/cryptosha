#include <iostream>
#include "console_reader/console_reader.h"


int main(int argc, char* argv[]) {

    cryptosha::console_reader reader("/home/anton/projects/technopark/cryptosha/crylang/translator/input", "output");

    auto code = reader.read();
//    cry::any_cast<std::vector<cry::lang::object_view>>(code.);
//    std::cout <<"********************" <<std::endl;

    for(auto& i : code) {
        auto vec = cry::any_cast<std::vector<cry::lang::object_view>>(i.parameters);

        for(auto& k : vec) {
            std::cout << k.name() << " ";
        }
        std::cout << std::endl;

    }

    std::cout << "ok" << std::endl;
//    convertor con("d.sum(a+b,k(c,4+2-1,6),(g-h))");
//    con.handle();

//    std::vector<string_t> dividers = {"+", "-", "*", "/", ".", "(", ")", "^", ","};

//    auto parsed_string = con.multiple_parse(str, dividers);

//    for(auto& string : parsed_string)
//        std::cout << string << std::endl;
//    con.handle();

    return 0;
}