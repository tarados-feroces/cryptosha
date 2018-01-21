#include "convertor.h"


convertor::convertor(){

    dividers = ops_handler.ops.get_names();

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


        if(!string.empty() && !ops_handler.handle_operation(output, string)) {

            if(i < parsed_string.size() - 1 && parsed_string[i + 1] == syntax::open_scope) { // Если встретили функцию
                stack_num_args.push(0);
                if(parsed_string[i + 2] != syntax::close_scope)
                    stack_num_args.top()++;
            }

            structure_handle(output, string);
        }

        else if(string == syntax::open_scope) {
            ++scope_counter;
        }

        else if(string == syntax::close_scope) {

            if(scope_counter == stack_num_args.size()) {
                output.emplace_back(object_view(types::variable, std::to_string(stack_num_args.top())));
                output.emplace_back(object_view(types::operation, "@call"));
                stack_num_args.pop();
            }

            --scope_counter;
        }

        else if(string == syntax::divider) {

            if(!stack_num_args.empty())
                stack_num_args.top()++;
        }

    }

    ops_handler.close_stack(output);

    return output;
}


void convertor::structure_handle(expression_t& output, string_t& input_str) {

    auto parsed_str = funcs::parse(input_str, syntax::class_member);

    int args_counter = 0;
    int dots_counter = 0;

    for(auto& string : parsed_str) {

        if(string == syntax::class_member) {
            ++dots_counter;
        }
        else {
            output.emplace_back(object_view(types::variable, string));
            ++args_counter;
        }

        if(dots_counter > 0 && args_counter == 2) {
            output.push_back(operators::class_member);
            --dots_counter;
            --args_counter;
        }
    }
}