#include "../../../../crylang/interpreter/calculations.hpp"

#include "../../../main_test.hpp"



TEST_CASE( "Testing objects" )
{
    using namespace crylang;

    SECTION( "Easy types" )
    {
        int_t var = 42;
        object int_var = make_object( var );
        REQUIRE( int_var.get_type() == type::Int );

        object short_var = make_object( short(-3) );
        REQUIRE( short_var.get_type() == type::Int );

        object float_var = make_object( 3.2 );
        REQUIRE( float_var.get_type() == type::Float );
    }

    SECTION( "Strings" )
    {
        const char * chars = "This line is const char *";
        object str_1 = make_object( chars );
        REQUIRE( str_1.get_type() == type::String );

        char* chars2 = new char[10];
        for( int i = 0; i < 9; ++i )
            chars2[i] = 48 + i;
        object str_2 = make_object( chars2 );
        REQUIRE( str_2.get_type() == type::String );

        object str_3 = make_object( std::string("lol") );
        REQUIRE( str_3.get_type() == type::String );
    }
}
