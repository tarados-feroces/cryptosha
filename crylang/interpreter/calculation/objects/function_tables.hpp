#include "function_table_generator.hpp"
#include "make_object.hpp"



namespace crylang {
    namespace function_tables {

        static_table int_static_table()
        {
            using namespace cry::lang::operators;

            static_table st;

            st.insert(
                plus.name(),
                []( auto vars )
                {
                    variable_ptr lhs = vars["lhs"];
                    variable_ptr rhs = vars["rhs"];

                    return make_object(
                        lhs->get<type::Int>() + rhs->get<type::Int>()
                    );
                }
            );

            st.insert(
                minus.name(),
                []( auto vars )
                {
                    variable_ptr lhs = vars["lhs"];
                    variable_ptr rhs = vars["rhs"];

                    return make_object(
                        lhs->get<type::Int>() - rhs->get<type::Int>()
                    );
                }
            );

            return st;
        }

    }
}
