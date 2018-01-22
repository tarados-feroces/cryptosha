#include "code.hpp"


namespace cry {
    namespace lang {
        namespace operators {

            #define def_operation(x) \
                static const auto x = object_view(types::operation, "@"#x)

                def_operation(plus);
                def_operation(minus);
                def_operation(mult);
                def_operation(div);
                def_operation(mod);

                def_operation(class_member);
                def_operation(ref);

                def_operation(assign_copy);
                def_operation(assign_move);


            #undef def_operation
        }
    }
}
