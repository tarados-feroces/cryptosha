#include "code_types.hpp"

#define st_const static const auto

namespace cry {
    namespace lang {

        namespace operators {

            #define def_operation(x) \
                static const auto x = object_view(types::operation, "@x")

            st_const plus = object_view(types::operation, "@plus");
            st_const minus = object_view(types::operation, "@minus");
            st_const div = object_view(types::operation, "@div");
            st_const mult = object_view(types::operation, "@mult");

            st_const class_member = object_view(types::operation, "@class_member");
            st_const ref = object_view(types::operation, "@ref");

            st_const assign_copy = object_view(types::operation, "@assign_copy");

            def_operation(assign_move);
        }
    }   
}

#undef CONST
