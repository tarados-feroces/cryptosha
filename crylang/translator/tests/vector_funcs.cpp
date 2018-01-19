#include "../funcs/vector_funcs.h"
#include "main_test.hpp"


TEST_CASE( "Testing insert_one_elem function" ) {

    SECTION("Inserting in front"){

        std::vector<int> vec;
        funcs::insert_one_elem(vec, 0, 2);

        REQUIRE(vec[0] == 2);
        REQUIRE(vec.size() == 1);

        vec.push_back(3);

        funcs::insert_one_elem(vec, 0, 1);
        REQUIRE(vec[0] == 1);
        REQUIRE(vec[1] == 2);
        REQUIRE(vec[2] == 3);
        REQUIRE(vec.size() == 3);
    }

    SECTION("Inserting in back"){

        std::vector<int> vec;

        vec.push_back(3);

        funcs::insert_one_elem(vec, 1, 1);
        REQUIRE(vec[0] == 3);
        REQUIRE(vec[1] == 1);
        REQUIRE(vec.size() == 2);
    }

    SECTION("Inserting"){

        std::vector<int> vec;
        funcs::insert_one_elem(vec, 0, 2);

        REQUIRE(vec[0] == 2);
        REQUIRE(vec.size() == 1);

        vec.push_back(3);

        funcs::insert_one_elem(vec, 1, 1);
        REQUIRE(vec[0] == 2);
        REQUIRE(vec[1] == 1);
        REQUIRE(vec[2] == 3);
        REQUIRE(vec.size() == 3);
    }

}


TEST_CASE( "Testing insert function" ) {

    SECTION("Inserting"){

        std::vector<int> vec;
        std::vector<int> vec1 = {10, 20};

        vec.push_back(3);

        funcs::insert(vec, 1, vec1);
        REQUIRE(vec[0] == 3);
        REQUIRE(vec[1] == 10);
        REQUIRE(vec[2] == 20);
        REQUIRE(vec.size() == 3);
    }

}


TEST_CASE( "Testing erase function" ) {

    SECTION("Erasing from back"){

        std::vector<int> vec = {1, 2, 3};

        funcs::erase(vec, 2);
        REQUIRE(vec[0] == 1);
        REQUIRE(vec[1] == 2);
        REQUIRE(vec.size() == 2);
    }

    SECTION("Erasing"){

        std::vector<int> vec = {1, 2, 3};

        funcs::erase(vec, 1);
        REQUIRE(vec[0] == 1);
        REQUIRE(vec[1] == 3);
        REQUIRE(vec.size() == 2);
    }

}