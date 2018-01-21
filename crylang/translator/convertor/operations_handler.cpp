#include "operations_handler.h"

bool operations_handler::handle_operation(expression_t &output, string_t input) {

    if(handle_operator(output, input))
        return true;

    if(handle_open_scope(output, input))
        return true;

    if(handle_close_scope(output, input))
        return true;

    return handle_args_divider(output, input);

}


bool operations_handler::handle_operator(expression_t &output, string_t input) {

    auto it = funcs::find<operation, string_t>(ops.ops, input);

    if(it == ops.ops.end())
        return false;

    while(!stack_op.empty() && stack_op.top().prior() >= it->prior()) {
        output.push_back(it->object());
        stack_op.pop();
    }
    stack_op.push(*it);

    return true;
}


bool operations_handler::handle_open_scope(expression_t &output, string_t input) {

    if(input != syntax::open_scope)
        return false;

    stack_op.push(operation(syntax::open_scope, priority::v_v_v_v_low, operators::empty));
    return true;
}


bool operations_handler::handle_close_scope(expression_t &output, string_t input) {

    if(input != syntax::close_scope)
        return false;

    if(stack_op.empty())
        throw exception_t("wrong sequense");

    while(stack_op.top().name() != syntax::open_scope) {
        if(stack_op.empty())
            throw exception_t("wrong sequense");
        output.push_back(stack_op.top().object());
        stack_op.pop();
    }
    stack_op.pop();

    return true;
}


bool operations_handler::handle_args_divider(expression_t &output, string_t input) {

    if(input != syntax::divider)
        return false;

    if(stack_op.empty())
        throw exception_t("wrong sequense");

    while(stack_op.top().name() != syntax::open_scope) {
        if(stack_op.empty())
            throw std::invalid_argument("wrong sequense");
        output.push_back(stack_op.top().object());
        stack_op.pop();
    }

    return true;
}


bool operations_handler::close_stack(expression_t &output) {

    while(!stack_op.empty()) {
        output.push_back(stack_op.top().object());
        stack_op.pop();
    }

    return true;
}