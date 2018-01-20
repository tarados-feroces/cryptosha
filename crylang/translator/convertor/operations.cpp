#include "operations.h"

bool operations::handle_operation(expression_t &output, string_t input) {

    if(handle_operator(output, input))
        return true;

    if(handle_open_scope(output, input))
        return true;

    if(handle_close_scope(output, input))
        return true;

    if(handle_args_divider(output, input))
        return true;

    return false;

}


bool operations::handle_operator(expression_t &output, string_t input) {

    auto it = op_to_prior.find(input);

    if(it == op_to_prior.end())
        return false;

    while(!stack_op.empty() && stack_op.top().second >= it->second) {
        output.push_back(op_to_obj.find(stack_op.top().first)->second);
        stack_op.pop();
    }
    stack_op.push(*it);

    return true;
}


bool operations::handle_open_scope(expression_t &output, string_t input) {

    if(input != syntax::open_scope)
        return false;

    stack_op.push(std::pair<string_t, int>(input, 0));
    return true;
}


bool operations::handle_close_scope(expression_t &output, string_t input) {

    if(input != syntax::close_scope)
        return false;

    if(stack_op.empty())
        throw exception_t("wrong sequense");

    while(stack_op.top().first != syntax::open_scope) {
        if(stack_op.empty())
            throw exception_t("wrong sequense");
        output.push_back(op_to_obj.find(stack_op.top().first)->second);
        stack_op.pop();
    }
    stack_op.pop();

    return true;
}


bool operations::handle_args_divider(expression_t &output, string_t input) {

    if(input != syntax::divider)
        return false;

    if(stack_op.empty())
        throw exception_t("wrong sequense");

    while(stack_op.top().first != syntax::open_scope) {
        if(stack_op.empty())
            throw std::invalid_argument("wrong sequense");
        output.push_back(op_to_obj.find(stack_op.top().first)->second);
        stack_op.pop();
    }

    return true;
}


bool operations::close_stack(expression_t &output) {

    while(!stack_op.empty()) {
        output.push_back(op_to_obj.find(stack_op.top().first)->second);
        stack_op.pop();
    }

    return true;
}