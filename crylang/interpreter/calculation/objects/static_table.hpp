#pragma once

#include "object_map.hpp"

/*

namespace crylang {

    namespace static_tables {

        generate_static_table( type object_type )
        {
            case type::Byte:
            case type::Char:
            case type::Int:
                return static_table_fabric
            case type::Float:
            case type::String:
            case type::Vector:
            case type::Function:
            case type::Sequence:
        }
    }

    class static_table_fabric
    {
    public:
        using map_t = std::unordered_map<type, object_table_ptr>;

        table() = default;


        static auto generate_table( type object ) -> object_table_ptr
        {
            auto it = _table_ptrs.find(object);

            if( it != std::end(_table_ptrs) )
                return std::make_shared( it->second );

            auto table_ptr = generate_static_table(object);

            _table_ptrs.insert(
                std::pair<type, object_table_ptr>(object, table_ptr)
            );
            return table_ptr;
        }

        ~table() = default;

    private:
        map_t _table_ptrs;
    };


    object_table_ptr get_static_table( type var_type )
    {
        static static_table_fabric;

        switch( var_type )
        {
        case type::Byte:
        case type::Char:
        case type::Int:
            return static_table_fabric
        case type::Float:
        case type::String:
        case type::Vector:
        case type::Function:
        case type::Sequence:

        default:
            return object_table_ptr();
        }
    }
}

*/
