#pragma once
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
                def_operation(degree);

                def_operation(class_member);
                def_operation(ref);

                def_operation(assign_copy);
                def_operation(assign_move);
                def_operation(swap);

                def_operation(equal);
                def_operation(not_equal);
                def_operation(less);
                def_operation(greater);

                def_operation(conv);

                def_operation(empty);


            #undef def_operation




        }
    }
}
