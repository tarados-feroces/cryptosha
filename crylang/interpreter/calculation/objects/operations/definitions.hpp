#pragma once

#include <unordered_map>

namespace crylang {

    namespace definitions {
        
        static constexpr auto int_table = {

            { "@plus", [](auto lhs, auto rhs){ return lhs + rhs; } },
            { "@minus", [](auto lhs, auto rhs){ return lhs - rhs; } },

        };
    }
}
