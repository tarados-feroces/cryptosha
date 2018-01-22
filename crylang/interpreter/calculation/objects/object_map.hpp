#pragma once

#include <unordered_map>

#include "types.hpp"


namespace crylang {

    using namespace cry;

    class object_map
    {
    public:
        using name_to_ptrs_t = std::unordered_map<var_name_t, variable_ptr>;

        object_map& insert( const var_name_t& name, const variable_ptr& ptr )
        {
            _name_to_ptrs[name] = ptr;
            return *this;
        }

        object_map& erase( const var_name_t& name )
        {
            _name_to_ptrs.erase( name );
            return *this;
        }

        size_t size() const
        {
            return _name_to_ptrs.size();
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
                const_cast<const object_map&>(*this)[ name ]
            );
        }

    protected:
        name_to_ptrs_t _name_to_ptrs;
    };

}
