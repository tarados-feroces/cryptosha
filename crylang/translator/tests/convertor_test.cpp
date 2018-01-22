#include "../convertor/convertor.h"
#include "main_test.hpp"


TEST_CASE( "Testing change/get_str functions" ) {

    convertor conv;
    string_t input = "123";

    conv.change_str(input);

    REQUIRE(conv.get_str() == "123");
}


TEST_CASE( "Testing handle" ) {

    SECTION("Empty input") {
        convertor conv;

        string_t input = "";

        conv.change_str(input);

        auto output = conv.handle();

        REQUIRE(output.size() == 0);
    }

    SECTION("Calculator input") {
        convertor conv;

        string_t input = "4+7*9^(c==b)";

        conv.change_str(input);

        auto output = conv.handle();

        REQUIRE(output.size() == 9);

        REQUIRE(output[0].name() == "4");
        REQUIRE(output[1].name() == "7");
        REQUIRE(output[2].name() == "9");
        REQUIRE(output[3].name() == "c");
        REQUIRE(output[4].name() == "b");
        REQUIRE(output[5].name() == "@equal");
        REQUIRE(output[6].name() == "@degree");
        REQUIRE(output[7].name() == "@mult");
        REQUIRE(output[8].name() == "@plus");
    }

    SECTION("Function input") {
        convertor conv;

        string_t input = "sin(4-b,l,foo())";

        conv.change_str(input);

        auto output = conv.handle();

        REQUIRE(output.size() == 10);
        REQUIRE(output[0].name() == "sin");
        REQUIRE(output[1].name() == "4");
        REQUIRE(output[2].name() == "b");
        REQUIRE(output[3].name() == "@minus");
        REQUIRE(output[4].name() == "l");
        REQUIRE(output[5].name() == "foo");
        REQUIRE(output[6].name() == "0");
        REQUIRE(output[7].name() == "@call");
        REQUIRE(output[8].name() == "3");
        REQUIRE(output[9].name() == "@call");
    }

    SECTION("Structure input") {
        convertor conv;

        string_t input = "k.sin(4-b,l,foo())";

        conv.change_str(input);

        auto output = conv.handle();

        REQUIRE(output.size() == 12);
        REQUIRE(output[0].name() == "k");
        REQUIRE(output[1].name() == "sin");
        REQUIRE(output[2].name() == "@class_member");
        REQUIRE(output[3].name() == "4");
        REQUIRE(output[4].name() == "b");
        REQUIRE(output[5].name() == "@minus");
        REQUIRE(output[6].name() == "l");
        REQUIRE(output[7].name() == "foo");
        REQUIRE(output[8].name() == "0");
        REQUIRE(output[9].name() == "@call");
        REQUIRE(output[10].name() == "3");
        REQUIRE(output[11].name() == "@call");
    }

}