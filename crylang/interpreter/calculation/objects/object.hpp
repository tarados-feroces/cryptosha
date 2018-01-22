#pragma once

#include "object_map.hpp"

namespace crylang {

    using namespace cry;

    class object
    {
    public:
        using variants_t = type_variant;
        using members_t = object_map;
        using func_table_ptr_t = function_tables::static_table_ptr;

        template<class... Args>
        object( type obj_type, func_table_ptr_t funcs_ptr, Args&&... args )
            : _type( obj_type )
            , _var( std::forward<Args>(args)... )
            , _members()
            , _func_ptrs( funcs_ptr )
        {}

        object( const object& obj ) = default;
        object( object&& obj ) = default;

        object& operator=( const object& obj ) = default;
        object& operator=( object&& obj ) = default;


        bool connect_table( func_table_ptr_t table_ptr )
        {
            _func_ptrs = table_ptr;
            return true;
        }

        auto function( const var_name_t& name )
        {
            return (*_func_ptrs)[name];
        }

        type get_type() const
        {
            return _type;
        }

        size_t get_type_index() const
        {
            return _var.index();
        }

        template<type T>
        const auto& get() const
        {
            constexpr size_t type_id = size_t(T);
            try {
                return std::get<type_id>( _var );
            }
            catch( ... ) {
                throw errors::type_error( "Type error" );
            }
        }

        template<int N>
        const auto& get() const
        {
            return std::get<N>( _var );
        }

        template<typename T>
        const auto& get() const
        {
            return std::get<T>( _var );
        }

        members_t& members()
        {
            return _members;
        }

    protected:
        type        _type;
        variants_t  _var;
        members_t   _members;

        func_table_ptr_t _func_ptrs;

    };
}
