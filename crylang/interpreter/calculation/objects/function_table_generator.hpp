#include "static_table.hpp"

namespace crylang {
    namespace function_tables {

        class generator
        {
        public:
            using map_t = std::unordered_map<type, static_table_ptr>;

            static auto get_table( type object_type ) -> static_table_ptr
            {
                auto it = _table_ptrs.find( object_type );

                if( it != std::end(_table_ptrs) )
                    return it->second;

                auto table_ptr = generate_static_table( object_type );

                _table_ptrs.insert({ object_type , table_ptr});
                return table_ptr;
            }

        private:
            static map_t _table_ptrs;

            static auto generate_static_table( type object_type ) -> static_table_ptr
            {
                switch( object_type )
                {
                case type::Byte:
                case type::Char:
                case type::Int:
                    return make_static_table_ptr( int_static_table() );
                case type::Float:
                case type::String:
                case type::Vector:
                case type::Function:
                case type::Sequence:

                default:
                    return static_table_ptr( nullptr );
                }
            }
        };

        generator::map_t generator::_table_ptrs = {};

    }
}
