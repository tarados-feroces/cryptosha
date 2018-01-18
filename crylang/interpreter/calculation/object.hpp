#pragma once

#include "variables.h"

#include <variant>
#include <typeinfo>
#include <iostream>
#include <type_traits>

namespace crylang {

    using int_t = std::int64_t;
    using vector_t = std::vector<object>;
    using float_t = double;

    using type_variant =
        std::variant<
            nothing,
            int_t,
            vector_t
            //function,
            //sequence,
         >;


    class object
    {
    public:
        using types_var = type_variant;

        template<class... Args>
        object( type obj_type, Args&&... args )
            : _type( obj_type )
            , _var( std::forward<Args>(args)... )
        {}

        object( const object& obj ) = default;
        object( object&& obj ) = default;

        object& operator=( const object& obj ) = default;
        object& operator=( object&& obj ) = default;

        type get_type() const
        {
            return _type;
        }

    protected:
        type      _type;
        types_var _var;
    };

    template<class T = nothing>
    auto make_object( T variable ) -> object
    {
        if constexpr( std::is_same<T, int_t>::value )
            return object( type::Int, int_t(variable) );

        if constexpr( std::is_same<T, float_t>::value )
            return object( type::Float, float_t(variable) );

        std::cout << "Unknown type : " << typeid(T).name() << std::endl;
        return object( type::Nothing, nothing() );

    }


}
