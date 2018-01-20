#pragma once

#include <memory>
#include "../../../language/crylang.hpp"

#include "../exceptions.hpp"


namespace crylang {

    struct nothing {
        static const bool bool_value = false;

        operator bool()
        {
            return bool_value;
        }
    };

    class object;

    class numerical_objects;
    class container;

    class operation;
    class function;
    class sequence;

    using variable_ptr = std::shared_ptr<object>;
    using std::make_shared;
}
