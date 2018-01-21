#pragma once

#include <functional>

#include "objects.hpp"

/*
namespace crylang {

    namespace built_in {

        struct method
        {
            using function_t = std::function<object(object&, const object&)>;

            template<class... Args>
            method( Args&&...args )
                : func( std::forward<Args>(args)... )
            {}

            object operator()( object& obj, const object& argument )
            {
                return func( obj, argument );
            }

            function_t func;
        };

        struct function_handler
        {

        };

    }

    object::name_to_method_t object::_methods = {
        { "move", built_in::method( [](auto lhs, auto rhs){ return rhs; } )}
    };
}

*/
