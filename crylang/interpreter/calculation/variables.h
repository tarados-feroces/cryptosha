#pragma once

#include <variant>

#include <vector>
#include <string>
#include <functional>
#include <map>


namespace crylang {

    enum class type {
        Nothing,

        Byte,   //std::byte
        Char,   //char
        Int,    //std::int64_t

        Float,  //double

        String, //std::string

        Vector, //std::vector

        Function,
        Sequence,
    };

    struct nothing {
        static const bool bool_value = false;

        operator bool()
        {
            return bool_value;
        }
    };

    class object;
    class operation;
    class function;
    class sequence;

}
