#pragma once

#include <iostream>

#include "object.hpp"
//#include "numerical_objects.hpp"



namespace crylang {

    template<class T = nothing>
    auto make_object( T variable = T() ) -> variable_ptr
    {

        bool constexpr is_int = std::is_same<T, int_t>::value ||
                               std::is_same<T, long>::value ||
                               std::is_same<T, long long>::value ||
                               std::is_same<T, int>::value ||
                               std::is_same<T, short>::value;

        bool constexpr is_bool = std::is_same<T, bool>::value;

        // bool constexpr is_float = std::is_same<T, float_t>::value ||
        //                           std::is_same<T, float>::value ||
        //                           std::is_same<T, double>::value;

        // bool constexpr is_string = std::is_same<T, string_t>::value ||
        //                           std::is_same<T, std::string>::value ||
        //                           std::is_same<T, char *>::value ||
        //                           std::is_same<T, const char *>::value;

        bool constexpr is_none = std::is_same<T, nothing>::value;

        if constexpr( is_none )
            return make_shared<object>( type::Nothing, nullptr, nothing() );

        if constexpr( is_int ) {
            auto func_ptr = function_tables::generator::get_table( type::Int );
            return make_shared<object>( type::Int, func_ptr, int_t(variable) );
        }

        if constexpr( is_bool ) {
            return make_shared<object>( type::Bool, nullptr, bool_t(variable) );
        }
        /*
        if constexpr( is_float )
            return make_shared<numerical_object>( type::Float, float_t(variable) );

        if constexpr( is_string )
            return make_shared<object>( type::String, string_t(variable) );
        */

        std::cout << "Unknown type : " << typeid(T).name() << std::endl;
        return make_shared<object>( type::Nothing, nullptr, nothing() );
    }

}
