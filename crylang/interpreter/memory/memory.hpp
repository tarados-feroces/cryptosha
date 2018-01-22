#pragma once

#include "../calculations.hpp"
#include <unordered_map>

using namespace crylang;

class memory{

public:

    memory() = default;


    bool insert(const string_t& string) {
        return variables.insert(std::pair(string, make_object())).second;
    }

    template <class T>
    bool insert(const string_t& string, T expr) {
        return variables.insert(std::pair(string, make_object(expr))).second;
    }


    void erase(const string_t& string) {
        variables.erase(string);
    }


    auto find(const string_t& string) {

        auto it = variables.find(string);
        return it;
    }


    const auto operator()(const string_t& string) {

        auto it = variables.find(string);
        return it->second;
    }

    ~memory() = default;

private:

    std::unordered_map<string_t, variable_ptr> variables;

};