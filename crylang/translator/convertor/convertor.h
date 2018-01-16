#include <iostream>
#include <string>
#include <stack>
#include <map>
#include <vector>
#include "../../language/object_view.hpp"


using string_t = std::string;
using pair_t = std::pair<string_t, int>;
using stack_type = std::stack<pair_t>;
using map_t = std::map<string_t, int>;
using namespace cry::code;
using namespace cry::lang;



class convertor{

public:
    explicit convertor() = default;


    convertor(string_t input_str) : str(input_str) {}


    void change_str(string_t input_str) {
        str = input_str;
    }


    const string_t get_str() const {
        return str;
    }

    ~convertor() = default;



    expression_t handle() {

        expression_t output;

        std::vector<string_t> dividers = {"+", "-", "*", "/", "(", ")", "^", ","};
        std::stack<std::pair<string_t, int>> stack_op;
        std::stack<int> stack_num_args;
        std::vector<string_t> parsed_string = multiple_parse(str, dividers);

        for(auto& string : parsed_string)
            std::cout << string << std::endl;

        std::cout << "******************" << std::endl;


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
                    output.push_back(object_view(types::operation, stack_op.top().first));
                    stack_op.pop();
                }
                stack_op.push(std::pair<string_t, int>(it->first, it->second));
            }

            else if(string == "(") {
                ++scope_counter;
                stack_op.push(std::pair<string_t, int>(string, 0));
            }

            else if(string == ")") {
                if(stack_op.empty())
                    throw std::invalid_argument("wrong sequense");

                while(stack_op.top().first != "(") {
                    if(stack_op.empty())
                        throw std::invalid_argument("wrong sequense");
                    output.push_back(object_view(types::operation, stack_op.top().first));
                    stack_op.pop();
                }

                stack_op.pop();

                if(scope_counter == stack_num_args.size()) {
                    output.push_back(object_view(types::variable, std::to_string(stack_num_args.top())));
                    output.push_back(object_view(types::operation, "call"));
                    stack_num_args.pop();
                }

                --scope_counter;
            }

            else if(string == ",") {
                if(stack_op.empty())
                    throw std::invalid_argument("wrong sequense");

                while(stack_op.top().first != "(") {
                    if(stack_op.empty())
                        throw std::invalid_argument("wrong sequense");
                    output.push_back(object_view(types::operation, stack_op.top().first));
                    stack_op.pop();
                }

                stack_num_args.top()++;
            }

            else if(string != ""){

                if(i < parsed_string.size() - 1 && parsed_string[i + 1] == "(") { // Если встретили функцию
                    stack_num_args.push(0);
                    if(parsed_string[i + 2] != ")")
                        stack_num_args.top()++;
                }

                structure_handle(output, string);
            }
        }

        while(!stack_op.empty()) {
            output.push_back(object_view(types::operation, stack_op.top().first));
            stack_op.pop();
        }

        for(auto& string : output)
            std::cout << string._name << std::endl;

        return output;
    }


    void structure_handle(expression_t& output, string_t& input_str) {

        auto parsed_str = parse(input_str, ".");

        int args_counter = 0;
        int dots_counter = 0;

        for(auto& string : parsed_str) {

            if(string == ".") {
                ++dots_counter;
            }
            else {
                output.push_back(object_view(types::variable, string));
                ++args_counter;
            }

            if(dots_counter > 0 && args_counter == 2) {
                output.push_back(object_view(types::operation, "."));
                --dots_counter;
                --args_counter;
            }
        }
    }


    void insert_one_elem(std::vector<string_t>& vector, int pos, string_t& string) {

        if(pos == vector.size()){
            vector.push_back(string);
            return;
        }

        vector.push_back(vector[vector.size() - 1]);

        for(int i = vector.size() - 2; i > pos; --i) {
            vector[i] = vector[i - 1];
        }

        vector[pos] = string;
    }


    void erase(std::vector<string_t>& vector, int pos) {

        if(vector.size() <= 1) {
            vector.clear();
            return;
        }

        if(pos == vector.size() - 1) {
            vector.pop_back();
            return;
        }

        for(int i = pos; i < vector.size() - 1; ++i)
            vector[i] = vector[i + 1];

        vector.pop_back();

    }


    void insert(std::vector<string_t>& vector, int pos, std::vector<string_t>& insert_vector) {
        for(auto& string : insert_vector) {
            insert_one_elem(vector, pos++, string);
        }
    }


    std::vector<string_t> parse(string_t& input_str, const string_t& divider) {
        std::vector<string_t> vec;
        size_t prev = 0;
        size_t next;
        size_t delta = divider.length();

        while ((next = input_str.find(divider, prev)) != string_t::npos) {
            string_t tmp = input_str.substr(prev, next - prev);
            if (input_str.substr(prev, next - prev).size())
                vec.push_back(input_str.substr(prev, next - prev));
            vec.push_back(divider);
            prev = next + delta;
        }
        string_t tmp = input_str.substr(prev);
        vec.push_back(input_str.substr(prev));
        return vec;
    }


    std::vector<string_t> multiple_parse(string_t& input_str, std::vector<string_t>& dividers) {

        std::vector<string_t> vec{input_str};
        string_t current;

        for(auto& divider : dividers ) {
            for(int i = vec.size() - 1; i >= 0; --i) {
//                std::cout << *it << std::endl;

                auto parsed_string = parse(vec[i], divider);

//                auto iter = it + 1;
//                std::copy(parsed_string.begin(), parsed_string.end(), std::inserter(vec, iter));
//                std::cout << *it << std::endl;

                erase(vec, i);
                insert(vec, i, parsed_string);

            }
//            std::cout << *vec.begin() << std::endl;
//
//            auto parsed_string = parse(*vec.begin(), divider);
//
//            vec.erase(vec.begin());
//            vec.insert(vec.begin(), parsed_string.begin(), parsed_string.end());
        }

        return vec;
    }


    string_t str;
    std::vector<cry::lang::object_view> output;

    map_t operations = {
//            {"(", 0},
//            {")", 0},
            {"+", 1},
            {"-", 1},
            {"/", 2},
            {"*", 2},
            {"^", 3},
            {".", 4},
    };
};
