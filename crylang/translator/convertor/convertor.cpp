#include "convertor.h"


convertor::convertor(){

    size_t k = max_length_of_operator;

    while(k != 0) {

        for (auto &operation : operations) {
            if (operation.first.size() == k)
                dividers.push_back(operation.first);
        }

        --k;
    }

    dividers.push_back(syntax::open_scope);
    dividers.push_back(syntax::close_scope);
    dividers.push_back(syntax::divider);
}


void convertor::change_str(string_t input_str) {
    str = input_str;
}


const string_t convertor::get_str() const {
    return str;
}


expression_t convertor::handle() {

    expression_t output;

    if(str.size() == 0)
        return output;

    std::stack<std::pair<string_t, int>> stack_op;
    std::stack<int> stack_num_args;
    std::vector<string_t> parsed_string = funcs::multiple_parse(str, dividers);

    int scope_counter = 0;

    for(auto i = 0; i < parsed_string.size(); ++i) {

        auto string = parsed_string[i];
        auto it = operations.find(string);

        if(it != operations.end()) {

            if(stack_op.empty()) {
                stack_op.push(std::pair<string_t, int>(it->first, it->second));
                continue;
            }

            while(stack_op.top().second >= it->second && !stack_op.empty()) {
                output.push_back(op_to_obj.find(stack_op.top().first)->second);
                stack_op.pop();
            }
            stack_op.push(std::pair<string_t, int>(it->first, it->second));
        }

        else if(string == syntax::open_scope) {
            ++scope_counter;
            stack_op.push(std::pair<string_t, int>(string, 0));
        }

        else if(string == syntax::close_scope) {
            if(stack_op.empty())
                throw exception_t("wrong sequense");

            while(stack_op.top().first != syntax::open_scope) {
                if(stack_op.empty())
                    throw exception_t("wrong sequense");
                output.push_back(op_to_obj.find(stack_op.top().first)->second);
                stack_op.pop();
            }

            stack_op.pop();

            if(scope_counter == stack_num_args.size()) {
                output.push_back(object_view(types::variable, std::to_string(stack_num_args.top())));
                output.push_back(object_view(types::operation, "@call"));
                stack_num_args.pop();
            }

            --scope_counter;
        }

        else if(string == ",") {
            if(stack_op.empty())
                throw exception_t("wrong sequense");

            while(stack_op.top().first != syntax::open_scope) {
                if(stack_op.empty())
                    throw std::invalid_argument("wrong sequense");
                output.push_back(op_to_obj.find(stack_op.top().first)->second);
                stack_op.pop();
            }

            stack_num_args.top()++;
        }

        else if(string != ""){

            if(i < parsed_string.size() - 1 && parsed_string[i + 1] == syntax::open_scope) { // Если встретили функцию
                stack_num_args.push(0);
                if(parsed_string[i + 2] != syntax::close_scope)
                    stack_num_args.top()++;
            }

            structure_handle(output, string);

        }
    }



    while(!stack_op.empty()) {
        output.push_back(op_to_obj.find(stack_op.top().first)->second);
        stack_op.pop();
    }

    return output;
}


void convertor::structure_handle(expression_t& output, string_t& input_str) {

    auto parsed_str = funcs::parse(input_str, syntax::class_member);

//    if(parsed_str.size() <= 3)
//        return;

    int args_counter = 0;
    int dots_counter = 0;

    for(auto& string : parsed_str) {

        if(string == syntax::class_member) {
            ++dots_counter;
        }
        else {
            output.push_back(object_view(types::variable, string));
            ++args_counter;
        }

        if(dots_counter > 0 && args_counter == 2) {
            output.push_back(op_to_obj.find(syntax::class_member)->second);
            --dots_counter;
            --args_counter;
        }
    }
}