#pragma once

#include "operation.hpp"



struct operations{

public:

    operations(){}


    void add(string_t name, priority prior, cry::lang::object_view obj) {
        ops.push_back(operation(name, prior, obj));
    }


    void add(operation op) {
        ops.push_back(op);
    }


    std::vector<string_t> get_names() {
        std::vector<string_t> result;
        for(auto& it : ops)
            result.push_back(it.name());

        return result;
    }


    std::vector<operation> ops;

};
