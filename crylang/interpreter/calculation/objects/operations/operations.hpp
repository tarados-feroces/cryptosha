#pragma once

#include "../variables.hpp"

#include "definitions.hpp"

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

            arguments( const std::initializer_list<variable_ptr>& args_list )
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
            arguments& push( Args...args )
            {
                _args_vector.emplace_back( std::forward<Args>(args)... );
                return *this;
            }

            variable_ptr& pop()
            {
                variable_ptr ptr = *std::end( _args_vector );
                _args_vector.pop_back();
                return *this;
            }

            const variable_ptr& operator[]( size_t index ) const
            {
                return _args_vector[index];
            }

            variable_ptr& operator[]( size_t index )
            {
                return const_cast<variable_ptr&>(
                    const_cast<const arguments&>(*this)[ index ]
                );
            }

        protected:
            vector_t _args_vector;
        };

    }
}


namespace crylang {

    namespace operations {

        using function_t = std::function<variable_ptr(arguments)>;

        struct base_operation
        {
            template<class... Args>
            base_operation( size_t args_count, Args&&... args )
                : _args_count( args_count )
                , _func( std::forward<Args>(args)... )
            {}

            virtual variable_ptr run( arguments args )
            {
                if( correct_args_count() )
                    return _func( args );
                else
                    throw errors::arguments_error("Wrong number of parameters.")
            }

            bool correct_args_count( const arguments& args ) const
            {
                return args.count() == _args_count;
            }

        protected:
            size_t _args_count;
            function_t _func;
        };

        // struct built_in_operation
        //     : public base_operation
        // {
        //     template<class... Args>
        //     built_in_operation( size_t args_count, Args&&... args )
        //         : base_operation( args_count + 1, std::forward<Args>(args)... )
        //     {}
        //
        //     virtual variable_ptr run( arguments args )
        //     {
        //         if( correct_args_count() )
        //             return _func( args );
        //         else
        //             throw errors::arguments_error("Wrong number of parameters.")
        //     }
        // }


        struct binary_operation
            : public base_operation
        {
            binary_operation()
                : base_operation( 2 )
            {}
            virtual variable_ptr operator()( arguments ) = 0;

        };



        /*
        struct numerical_binary_operation
            : public binary_operation
        {

            template<class F>
            variable_ptr run_operator(
                const variable_ptr& lhs_ptr,
                const variable_ptr& rhs_ptr,
                F oper)
            {



                bool is_float_result = lhs_ptr->get_type() == type::Float ||
                                       rhs_ptr->get_type() == type::Float;


                auto lhs = std::static_pointer_cast<numerical_object>(lhs_ptr);
                auto rhs = std::static_pointer_cast<numerical_object>(rhs_ptr);

                if( is_float_result ) {
                    return make_object(oper( lhs->as_float(), rhs->as_float() ));
                }

                return make_object(oper( lhs->as_int(), rhs->as_int() ));
            }
        };

        struct summator
            : public numerical_binary_operation
        {

            virtual variable_ptr operator()( arguments args ) override
            {
                if(this->correct_args_count( args )) {
                    return this->run_operator( args[0], args[1], static_oper );
                }
                else throw errors::arguments_error( "Operator '@sum' : required 2 arguments." );
            }

            static constexpr auto static_oper = [](auto l, auto r)
            {
                return l + r;
            };
        };
        */




    }
}
