#include "../../../crylang/language/crylang.hpp"

#include "../../main_test.hpp"

/*
namespace cry {
    namespace lang {

        namespace operators {

            #define def_operation(x) \
                static const auto x = object_view(types::operation, "@x")

            CONST plus = object_view(types::operation, "@plus");
            CONST minus = object_view(types::operation, "@minus");
            CONST div = object_view(types::operation, "@div");
            CONST mult = object_view(types::operation, "@mult");

            CONST class_member = object_view(types::operation, "@class_member");
            CONST ref = object_view(types::operation, "@ref");

            CONST assign_copy = object_view(types::operation, "@assign_copy");

            def_operation(assign_move);
        }
    }
}
*/


TEST_CASE( "Testing operators (object_view)" )
{
    using namespace cry::lang;

    SECTION( "Math operators" )
    {
        auto add = operators::plus;
        auto minus = operators::minus;
        const object_view& mult = operators::mult;
        auto div = operators::div;
        auto mod = operators::div;
        mod = operators::mod;

        REQUIRE( add.name() == "@plus" );
        REQUIRE( minus.name() == "@minus" );
        REQUIRE( mult.name() == "@mult" );
        REQUIRE( div.name() == "@div" );
        REQUIRE( mod.name() == "@mod" );

    }
}
