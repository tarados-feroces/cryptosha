#include "../convertor/convertor.h"
#include "main_test.hpp"

TEST_CASE( "Testing string adapting" ) {

}

TEST_CASE( "Testing ancillary funcs" ) {

    convertor con;

    SECTION("parse") {
        string_t str = "1234567, 9";
        auto vec = con.parse(str, ",");
        REQUIRE("1234567" == vec[0]);
        REQUIRE("," == vec[1]);
        REQUIRE(" 9" == vec[2]);
    }

    SECTION("multiple parse") {
        string_t str = "1234+567-9";
        auto vec = con.multiple_parse(str);
        REQUIRE("1234" == vec[0]);
        REQUIRE("+" == vec[1]);
        REQUIRE("567" == vec[2]);
        REQUIRE("-" == vec[3]);
        REQUIRE("9" == vec[4]);

//        str = "12*34+56/7-9";
//        vec = con.multiple_parse(str);
//        REQUIRE("12" == vec[0]);
//        REQUIRE("*" == vec[1]);
//        REQUIRE("34" == vec[2]);
//        REQUIRE("+" == vec[3]);
//        REQUIRE("56" == vec[4]);
//        REQUIRE("/" == vec[5]);
//        REQUIRE("7" == vec[6]);
//        REQUIRE("-" == vec[7]);
//        REQUIRE("9" == vec[8]);
    }
}