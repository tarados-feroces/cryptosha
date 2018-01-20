#pragma once

#include "types.hpp"


namespace crylang {

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

        size_t get_type_index() const
        {
            return _var.index();
        }

        template<type T>
        const auto& get() const
        {
            constexpr size_t type_id = size_t(T);
            return std::get<type_id>( _var );
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

    protected:
        type      _type;
        types_var _var;
    };

}
