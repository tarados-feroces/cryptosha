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


    namespace function_tables {

        struct static_table;

        using static_table_ptr = std::shared_ptr<static_table>;

        template<class... Args>
        static_table_ptr make_static_table_ptr( Args&&... args )
        {
            return std::make_shared<static_table>( std::forward<Args>(args)... );
        }

        struct int_static_table;
        struct float_static_table;
        struct string_static_table;
        struct vector_static_table;
        struct function_static_table;

        struct generator;
    }

    class object_map;

    class object;

    class numerical_objects;
    class container;

    class operation;
    class function;
    class sequence;

    using variable_ptr = std::shared_ptr<object>;
    static const auto null_ptr = std::shared_ptr<object>( nullptr );

    using std::make_shared;
}
