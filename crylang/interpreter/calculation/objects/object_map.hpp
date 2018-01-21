#pragma once

#include "object_map.hpp"


namespace crylang {

    struct object_map
    {
        using name_to_ptrs_t = std::unordered_map<var_name_t, variable_ptr>;
        

        members& insert( const var_name_t& name, const variable_ptr& ptr )
        {
            _name_to_ptrs[name] = ptr;
            return *this;
        }

        members& erase( const var_name_t& name )
        {
            _name_to_ptrs.erase( name );
            return *this;
        }

        bool has_var( const var_name_t& name )
        {
            return _name_to_ptrs.find( name ) != std::end(_name_to_ptrs);
        }

        const variable_ptr& operator[]( const var_name_t& name ) const
        {
            return _name_to_ptrs.at(name);
        }

        variable_ptr& operator[]( const var_name_t& name )
        {
            return const_cast<variable_ptr&>(
                const_cast<const members&>(*this)[ name ]
            );
        }

    protected:
        name_to_ptrs_t _name_to_ptrs;
    };

}
