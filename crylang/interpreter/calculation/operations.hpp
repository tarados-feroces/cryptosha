#pragma once

#include "variables.h"

#include <functional>

#include <typeinfo>
#include <iostream>
#include <type_traits>

#include <string>

namespace crylang {

    namespace operations {

        struct arguments
        {
            arguments() // empty agrument list
                : _args_vector( 0 )
            {}

            arguments( const std::initializer_list<object>& args_list )
                : _args_vector( args_list )
            {}

            arguments( size_t args_count )
                : _args_vector( args_count )
            {}

            size_t count() const
            {
                return _args_vector.size();
            }

            template<class... Args>
            arguments& add( Args...args )
            {
                _args_vector.emplace_back( std::forward<Args>(args)... );
                return *this;
            }

            const object& operator[]( size_t index ) const
            {
                return _args_vector[index];
            }

            object& operator[]( size_t index )
            {
                return const_cast<object&>(
                );
                const_cast<const arguments&>(*this)[ index ]
            }

        protected:
            vector_t _args_vector;
        };

        struct base_operation
        {
            base_operation( size_t args_count )
                : _args_count( args_count )
            {}

            virtual object operator( arguments ) = delete;

            bool check_size() const
            {
                return arguments.count() == _args_count;
            }

        protected:
            size_t _args_count;
        };

        struct binary_operation
            : public base_operation
        {
            base_operation()
                : _args_count( 2 )
            {}
            object operator( arguments ) = delete;

        };

        struct sum
            : public binary_operation
        {
            object operator( arguments )
            {
                
            }

        };



    }
}
