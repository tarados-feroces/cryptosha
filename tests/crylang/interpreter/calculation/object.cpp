#include "../../../../crylang/interpreter/calculations.hpp"

#include "../../../main_test.hpp"



TEST_CASE( "Testing objects" )
{
    using namespace crylang;

    SECTION( "Type: nothing" )
    {
        auto none = *make_object();

        REQUIRE( none.get_type() == type::Nothing );
    }

    SECTION( "Simple types" )
    {
        int_t var = 42;
        auto int_var = make_object( var );
        REQUIRE( int_var->get_type() == type::Int );

        auto short_var = make_object( short(-3) );
        REQUIRE( short_var->get_type() == type::Int );

        auto f = short_var->function("@plus");

        auto map = object_map();
        map.insert("lhs",int_var).insert("rhs",short_var);

        auto result = f(map);

        REQUIRE( result->get_type() == type::Int );
        REQUIRE( result->get<type::Int>() == 39);

        f = short_var->function("@minus");

        result = f(map);

        REQUIRE( result->get_type() == type::Int );
        REQUIRE( result->get<type::Int>() == 45);

        f = short_var->function("@equal");

        result = f(map);

        REQUIRE( result->get_type() == type::Bool );
        REQUIRE( result->get<type::Bool>() == false);

        f = short_var->function("@assign_copy");

        result = f(map);

        REQUIRE( result->get_type() == type::Int );
        REQUIRE( result->get<type::Int>() == -3);

        f = short_var->function("@assign_move");

        result = f(map);

        REQUIRE( result->get_type() == type::Int );
        REQUIRE( result->get<type::Int>() == -3);




    }

    // SECTION( "Strings" )
    // {
    //     const char * chars = "This line is const char *";
    //     auto str_1 = make_object( chars );
    //     REQUIRE( str_1->get_type() == type::String );
    //
    //     char* chars2 = new char[10];
    //     for( int i = 0; i < 9; ++i )
    //         chars2[i] = 48 + i;
    //     auto str_2 = make_object( chars2 );
    //     REQUIRE( str_2->get_type() == type::String );
    //
    //     auto str_3 = make_object( std::string("lol") );
    //     REQUIRE( str_3->get_type() == type::String );
    // }
    //
    // SECTION( "Testing get<>() method" )
    // {
    //     auto str = make_object( std::string("STRING") );
    //     REQUIRE( str->get_type() == type::String );
    //     REQUIRE( str->get<cry::string_t>() == "STRING" );
    //     REQUIRE( str->get<type::String>() == "STRING" );
    //     //REQUIRE( str.get_type_index() == type::String );
    //
    //     /*
    //     object short_var = make_object( short(-3) );
    //     REQUIRE( short_var.get_type() == type::Int );
    //     REQUIRE( short_var.get_type_index() == 1 );
    //     REQUIRE( short_var.get<1>() + 3 ==0 );
    //     */
    // }
}
