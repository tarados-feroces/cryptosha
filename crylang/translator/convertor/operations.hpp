#pragma once

#include "operation.hpp"
#include <iterator>
#include <unordered_set>



class operations{

public:

    operations(){}


    void add(string_t name, priority prior, cry::lang::object_view obj) {
        ops.push_back(operation(name, prior, obj));
    }


    void add(const operation& op) {
        ops.push_back(op);
    }


    std::vector<string_t> get_names() {
        std::vector<string_t> result;
        for(auto& it : ops)
            result.push_back(it.name());

        return result;
    }


    auto find(string_t name) {
        return funcs::find<operation, string_t>(ops, name);
    }


    auto end() {
        return ops.end();
    }


private:
    std::vector<operation> ops;

};


template <class container>
operations make_operations(container& cont) {

    operations result;

    std::unordered_set<string_t> set;

    for(auto it = std::begin(cont); it != std::end(cont); ++it) {
        set.insert(it->name());
    }

    if(set.size() != cont.size())
        throw std::logic_error("Wrong operations");

    for(auto it = std::begin(cont); it != std::end(cont); ++it)
        result.add(*it);

    return result;
}