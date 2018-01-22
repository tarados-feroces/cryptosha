#pragma once

#include <unordered_map>

#include "object_map.hpp"



namespace crylang {
    namespace function_tables {

        using arguments_t = object_map;
        using function_t = std::function<variable_ptr(arguments_t)>;

        struct static_table
        {
            using name_to_ptrs_t = std::unordered_map<var_name_t, function_t>;

            template<class... Args>
            static_table& insert( const var_name_t& name, Args&&... args )
            {
                _name_to_ptrs[name] = function_t( std::forward<Args>(args)... );
                return *this;
            }

            static_table& erase( const var_name_t& name )
            {
                _name_to_ptrs.erase( name );
                return *this;
            }

            size_t size() const
            {
                return _name_to_ptrs.size();
            }

            bool has_function( const var_name_t& name )
            {
                return _name_to_ptrs.find( name ) != std::end(_name_to_ptrs);
            }

            function_t operator[]( const var_name_t& name )
            {
                return _name_to_ptrs[name];
            }


        protected:
            name_to_ptrs_t _name_to_ptrs;
        };

        static_table int_static_table();
    }
}

/*
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
