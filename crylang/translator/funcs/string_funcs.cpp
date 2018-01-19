#include "string_funcs.h"


namespace funcs {

    std::vector<string_t> parse(string_t &input_str, const string_t &divider) {
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


    std::vector<string_t> multiple_parse(string_t &input_str, std::vector<string_t> &dividers) {

        std::vector<string_t> vec{input_str};

        for (auto& divider : dividers) {
            for (long long int i = vec.size() - 1; i >= 0; --i) {

                if(find(dividers, vec[i]))
                    continue;

                auto parsed_string = parse(vec[i], divider);

                erase(vec, i);
                insert(vec, i, parsed_string);

            }

        }

        return vec;
    }


    string_t space_free(string_t input_str) {
        for (auto it = input_str.begin(); it != input_str.end();) {
            if (*it == ' ') {
                input_str.erase(it);
            } else
                ++it;
        }
        return input_str;
    }

}
