#include "code_types.hpp"

#define CONST static const auto

namespace cry {
    namespace lang {

        namespace operators {

            #define def_operation(x) \
                static const auto x = object_view(types::operation, "@x")

            CONST plus = object_view(types::operation, "@plus");
            CONST minus = object_view(types::operation, "@minus");
            CONST div = object_view(types::operation, "@div");
            CONST mult = object_view(types::operation, "@mult");

            CONST class_member = object_view(types::operation, "@class_member");
            CONST ref = object_view(types::operation, "@ref");

            CONST assign_copy = object_view(types::operation, "@assign_copy");

            def_operation(assign_move);
        }
    }   
}

#undef CONST
