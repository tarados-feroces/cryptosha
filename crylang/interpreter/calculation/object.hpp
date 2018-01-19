#pragma once

#include "variables.h"

#include <variant>
#include <typeinfo>
#include <iostream>
#include <type_traits>

#include <string>

namespace crylang {

    using int_t = std::int64_t;
    using vector_t = std::vector<object>;
    using float_t = double;
    using string_t = cry::string_t;

    using type_variant =
        std::variant<
            nothing,
            int_t,
            vector_t,
            string_t
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

        bool constexpr is_int = std::is_same<T, int_t>::value ||
                           std::is_same<T, long>::value ||
                           std::is_same<T, long long>::value ||
                           std::is_same<T, int>::value ||
                           std::is_same<T, short>::value;

        bool constexpr is_float = std::is_same<T, float_t>::value ||
                                  std::is_same<T, float>::value ||
                                  std::is_same<T, double>::value;

        bool constexpr is_string = std::is_same<T, cry::string_t>::value ||
                                  std::is_same<T, std::string>::value ||
                                  std::is_same<T, char *>::value ||
                                  std::is_same<T, const char *>::value;

        if constexpr( is_int )
            return object( type::Int, int_t(variable) );

        if constexpr( is_float )
            return object( type::Float, float_t(variable) );

        if constexpr( is_string )
            return object( type::String, string_t(variable) );


        std::cout << "Unknown type : " << typeid(T).name() << std::endl;
        return object( type::Nothing, nothing() );

    }


}
