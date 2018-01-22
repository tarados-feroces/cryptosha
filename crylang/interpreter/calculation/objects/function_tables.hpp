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

            st.insert(
                mult.name(),
                []( auto vars )
                {
                    variable_ptr lhs = vars["lhs"];
                    variable_ptr rhs = vars["rhs"];

                    return make_object(
                        lhs->get<type::Int>() * rhs->get<type::Int>()
                    );
                }
            );

            st.insert(
                divis.name(),
                []( auto vars )
                {
                    variable_ptr lhs = vars["lhs"];
                    variable_ptr rhs = vars["rhs"];

                    return make_object(
                        lhs->get<type::Int>() / rhs->get<type::Int>()
                    );
                }
            );

            st.insert(
                mod.name(),
                []( auto vars )
                {
                    variable_ptr lhs = vars["lhs"];
                    variable_ptr rhs = vars["rhs"];

                    return make_object(
                        lhs->get<type::Int>() % rhs->get<type::Int>()
                    );
                }
            );

            st.insert(
                degree.name(),
                []( auto vars )
                {
                    variable_ptr lhs = vars["lhs"];
                    variable_ptr rhs = vars["rhs"];

                    return make_object(
                        std::pow(lhs->get<type::Int>(), rhs->get<type::Int>())
                    );
                }
            );

            // TODO
            st.insert(
                assign_copy.name(),
                []( auto vars )
                {
                    variable_ptr lhs = vars["lhs"];
                    variable_ptr rhs = vars["rhs"];

                    *lhs = *rhs;

                    return make_object(
                        lhs->get<type::Int>()
                    );
                }
            );
            // TODO
            st.insert(
                assign_move.name(),
                []( auto vars )
                {
                    variable_ptr lhs = vars["lhs"];
                    variable_ptr rhs = vars["rhs"];

                    *lhs = std::move(*rhs);

                    return make_object(
                        lhs->get<type::Int>()
                    );
                }
            );

            st.insert(
                swap.name(),
                []( auto vars )
                {
                    variable_ptr lhs = vars["lhs"];
                    variable_ptr rhs = vars["rhs"];

                    std::swap(lhs, rhs);

                    return make_object(
                        lhs->get<type::Int>()
                    );
                }
            );

            st.insert(
                equal.name(),
                []( auto vars )
                {
                    variable_ptr lhs = vars["lhs"];
                    variable_ptr rhs = vars["rhs"];

                    return make_object(
                        lhs->get<type::Int>() == rhs->get<type::Int>()
                    );
                }
            );

            st.insert(
                not_equal.name(),
                []( auto vars )
                {
                    variable_ptr lhs = vars["lhs"];
                    variable_ptr rhs = vars["rhs"];

                    return make_object(
                        lhs->get<type::Int>() != rhs->get<type::Int>()
                    );
                }
            );

            st.insert(
                less.name(),
                []( auto vars )
                {
                    variable_ptr lhs = vars["lhs"];
                    variable_ptr rhs = vars["rhs"];

                    return make_object(
                        lhs->get<type::Int>() < rhs->get<type::Int>()
                    );
                }
            );

            st.insert(
                greater.name(),
                []( auto vars )
                {
                    variable_ptr lhs = vars["lhs"];
                    variable_ptr rhs = vars["rhs"];

                    return make_object(
                        lhs->get<type::Int>() > rhs->get<type::Int>()
                    );
                }
            );


            return st;
        }

    }
}
