#pragma once

#include <variant>
#include <string>
#include <cstddef>

#include <boost/bimap.hpp>

#include "variables.h"

namespace crylang {

    enum class type {
        Nothing = 0,

        Bool,

        Byte,   //std::byte
        Char,   //char
        Int,    //std::int64_t

        Float,  //double

        String, //std::string

        Vector, //std::vector

        Function, //function
        Sequence, //sequence
    };

    using none_t = nothing;
    using byte_t = std::byte;
    using char_t = char;
    using int_t = std::int64_t;
    using bool_t = bool;
    using vector_t = std::vector<variable_ptr>;

    using float_t = double;
    using string_t = cry::string_t;

    using type_variant =
        std::variant<
            none_t,

            bool_t,

            byte_t,
            char_t,
            int_t,

            float_t,

            string_t,

            vector_t

            //function,
            //sequence,
         >;

};
