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

        auto float_var = make_object( 3.2 );
        REQUIRE( float_var->get_type() == type::Float );

        auto summator = operations::summator();
        operations::arguments args = {short_var, float_var};

        auto result = summator( args );
        REQUIRE( result->get_type() == type::Float );
        REQUIRE( abs( result->get<type::Float>() - 0.2 ) < 1e-12 );

        auto new_var = *int_var;
        REQUIRE( new_var.get_type() == type::Int );

        new_var.perform( "move", *float_var );

        REQUIRE( new_var.get_type() == type::Float );
        REQUIRE( abs( new_var.get<type::Float>() - 3.2 ) < 1e-12 );

    }

    SECTION( "Strings" )
    {
        const char * chars = "This line is const char *";
        auto str_1 = make_object( chars );
        REQUIRE( str_1->get_type() == type::String );

        char* chars2 = new char[10];
        for( int i = 0; i < 9; ++i )
            chars2[i] = 48 + i;
        auto str_2 = make_object( chars2 );
        REQUIRE( str_2->get_type() == type::String );

        auto str_3 = make_object( std::string("lol") );
        REQUIRE( str_3->get_type() == type::String );
    }

    SECTION( "Testing get<>() method" )
    {
        auto str = make_object( std::string("STRING") );
        REQUIRE( str->get_type() == type::String );
        REQUIRE( str->get<cry::string_t>() == "STRING" );
        REQUIRE( str->get<type::String>() == "STRING" );
        //REQUIRE( str.get_type_index() == type::String );

        /*
        object short_var = make_object( short(-3) );
        REQUIRE( short_var.get_type() == type::Int );
        REQUIRE( short_var.get_type_index() == 1 );
        REQUIRE( short_var.get<1>() + 3 ==0 );
        */
    }
}
