#include "../funcs/string_funcs.h"
#include "main_test.hpp"


TEST_CASE( "Testing space_free function" ) {

    SECTION("Normal input"){

        string_t input = "123";
        REQUIRE(funcs::space_free(input) =="123");

        input = "1 2 3";
        REQUIRE(funcs::space_free(input) == "123");

        input = "a  +   v";
        REQUIRE(funcs::space_free(input) == "a+v");

        input = "              ";
        REQUIRE(funcs::space_free(input) == "");

        input = "asdv le,csl";
        REQUIRE(funcs::space_free(input) == "asdvle,csl");
    }

}

TEST_CASE( "Testing parce function" ) {

    SECTION("symbol"){

        string_t input = "1+2+3,";

        auto vec = funcs::parse(input, "+");

        REQUIRE(vec[0] == "1");
        REQUIRE(vec[1] == "+");
        REQUIRE(vec[2] == "2");
        REQUIRE(vec[3] == "+");
        REQUIRE(vec[4] == "3,");
    }

    SECTION("word"){

        string_t input = "1+2+3,";

        auto vec = funcs::parse(input, "+2");

        REQUIRE(vec[0] == "1");
        REQUIRE(vec[1] == "+2");
        REQUIRE(vec[2] == "+3,");
    }

}

TEST_CASE( "Testing multiple_parce function" ) {

    SECTION("symbols"){

        string_t input = "d=k+r-c*d";

        std::vector<string_t> dividers = {"+", "-", "="};

        auto vec = funcs::multiple_parse(input, dividers);

        REQUIRE(vec[0] == "d");
        REQUIRE(vec[1] == "=");
        REQUIRE(vec[2] == "k");
        REQUIRE(vec[3] == "+");
        REQUIRE(vec[4] == "r");
        REQUIRE(vec[5] == "-");
        REQUIRE(vec[6] == "c*d");
    }

    SECTION("words"){

        string_t input = "d=k+r-c*d";

        std::vector<string_t> dividers = {"+", "-", "=", "c*"};

        auto vec = funcs::multiple_parse(input, dividers);

        REQUIRE(vec[0] == "d");
        REQUIRE(vec[1] == "=");
        REQUIRE(vec[2] == "k");
        REQUIRE(vec[3] == "+");
        REQUIRE(vec[4] == "r");
        REQUIRE(vec[5] == "-");
        REQUIRE(vec[6] == "c*");
        REQUIRE(vec[7] == "d");
    }

}
