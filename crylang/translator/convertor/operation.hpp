#pragma once

#include "../includes.hpp"
#include "../funcs/string_funcs.h"
#include "../syntax_constants.hpp"

#include <iostream>



enum priority{
    v_v_v_v_low,
    v_v_v_low,
    v_v_low,
    v_low,
    low,
    medium,
    high,
    v_high,
    v_v_high
};


class operation {

public:

    operation():_name(""), _priority(v_v_v_v_low), _object(cry::lang::operators::empty){}


    operation(string_t name, priority priority, cry::lang::object_view object): _name(name), _priority(priority), _object(object){}


    string_t name() {
        return _name;
    } const


    cry::lang::object_view object() {
        return _object;
    }const


    priority prior() {
        return _priority;
    }const


    bool operator==(string_t& rhs) {
        return funcs::equal(name(), rhs);
    }


    bool operator!=(string_t& rhs) {
        return !funcs::equal(name(), rhs);
    }


    ~operation() = default;


protected:
    string_t _name;
    priority _priority;
    cry::lang::object_view _object;


};
