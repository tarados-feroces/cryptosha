#include "../../../../crylang/interpreter/calculations.hpp"

#include "../../../main_test.hpp"

#include <memory>


class sum
{
public:

    crylang::variable_ptr operator()(
                                const crylang::variable_ptr& lhs_ptr,
                                const crylang::variable_ptr& rhs_ptr)
    {
        using namespace crylang;



        bool is_float_result = lhs_ptr->get_type() == type::Float ||
                               rhs_ptr->get_type() == type::Float;


        auto lhs = std::static_pointer_cast<numerical_object>(lhs_ptr);
        auto rhs = std::static_pointer_cast<numerical_object>(rhs_ptr);

        if( is_float_result ) {
            return make_object( lhs->as_float() + rhs->as_float() );
        }

        return make_object( lhs->as_int() + rhs->as_int() );
    }
};

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

        auto summator = sum();

        auto result = summator( int_var, short_var );
        REQUIRE( result->get_type() == type::Int );
        REQUIRE( result->get<type::Int>() == 39 );

        result = summator( int_var, float_var );
        REQUIRE( result->get_type() == type::Float );
        REQUIRE( result->get<type::Float>() == 45.2 );
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
