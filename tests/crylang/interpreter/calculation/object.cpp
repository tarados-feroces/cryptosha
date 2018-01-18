#include "../../../../crylang/interpreter/calculations.hpp"

#include "../../../main_test.hpp"



TEST_CASE( "Testing objects" )
{
    using namespace crylang;

    SECTION( "Compilation" )
    {
        int_t var = 42;
        object int_var = make_object( var );

        REQUIRE( int_var.get_type() == type::Int );

        object float_var = make_object( 3.2 );

        REQUIRE( float_var.get_type() == type::Float );
    }
}
