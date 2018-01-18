#include "Reader.h"


namespace output {
	string_t err_str("incorrect input");
	string_t begin_str(">>>> ");
	string_t tab_str("   ");
	string_t begin_tab_str("     ");
}


namespace cryptosha {


	bool console_reader::ifstream_good() const {
		return input.good();
	}


	void console_reader::stack_close() {
		--num;
		if (ns_stack.empty()) {
			output << output::err_str << std::endl;
			return;
		}
		code::code_type code_st_el = ns_stack.top().simple_command_list;
		ns_stack.pop();
		if (ns_stack.empty()) {
			code = code_st_el;
		}
		else {
            funcs::insert<command_type>(ns_stack.top().simple_command_list, ns_stack.top().position, code_st_el);
//            ns_stack.top().simple_command_list.insert(ns_stack.top().it, code_st_el.begin(), code_st_el.end());
            ns_stack.top().position += code_st_el.size();
        }
	}


	string_t console_reader::input_handle() {
		string_t result = string_t("");
		string_t str;
		std::vector<string_t> list{};
		std::vector<string_t> dividers{syntax::open_scope, syntax::close_scope};
		do {
			getline(input, str);
			list = funcs::multiple_parse(str, dividers);
			str.clear();

			for (auto& it : list) {
				if (it == syntax::open_scope)  {
					input_stack.push(syntax::open_scope);
					result = result + it;
                    funcs::space_free(str);
				}
				else if (it == syntax::close_scope) {
					if (input_stack.empty()) {
						output << output::err_str << std::endl;
						return string_t("");
					}
					else {
						input_stack.pop();
						result = result + it;
					}
				}
				else
					result = result + it;
			}
		} while (!input_stack.empty());

		return result;

	}


	expression_t console_reader::simple_cmd_handle(string_t input) {

		cmd_creator.change_str(input);

		return cmd_creator.handle();
	}


	void console_reader::cmd_make(string_t input_str) {

		if (!input_str.size())
			return;

		std::smatch res;
		command_type code_element;
		stack_elem st_el;

		if (std::regex_search(input_str, res, m_for)) {
			++num;
			ns_stack.push(st_el);
			ns_stack.top().keyword = stack_kw::m_for;

            code_element.mark = mark_number++;
            code_element.keyword = keywords::expression;
			code_element.parameters = simple_cmd_handle(res[1].str());
			ns_stack.top().simple_command_list.push_back(code_element);

			code_element.mark = mark_number++;
			code_element.keyword = keywords::condition;
            code_element.parameters = mark_number;
            code_element.parameters = simple_cmd_handle(res[2].str());
			ns_stack.top().simple_command_list.push_back(code_element);

            code_element.mark = mark_number++;
            code_element.keyword = keywords::expression;
            code_element.parameters = simple_cmd_handle(res[3].str());
            ns_stack.top().simple_command_list.push_back(code_element);
			ns_stack.top().position = 3;

			code_element.mark = mark_number++;
			code_element.keyword = keywords::jump;
			code_element.parameters = mark_number - 4;  // Изменить, если меняется кол-во блоков в for
			ns_stack.top().simple_command_list.push_back(code_element);

			return;
		}

		else if (input_str == syntax::block_open_scope) {
			//ind = false;
			++num;
            st_el.keyword = stack_kw::open_scope;
            st_el.position = 0;
			ns_stack.push(st_el);
			return;
		}

		else if (input_str == syntax::block_close_scope) {
			if (!ns_stack.empty())
				stack_close();
			else {
				output << output::err_str << std::endl;
				return;
			}
			if (!ns_stack.empty()) {
				if (ns_stack.top().keyword == stack_kw::m_for)
					stack_close();
			}
			return;
		}

        code_element.mark = mark_number++;
        code_element.keyword = keywords::expression;
        code_element.parameters = simple_cmd_handle(input_str);

		if (ns_stack.empty()) {
			code.push_back(code_element);
		}
		else if (ns_stack.top().keyword == stack_kw::m_for) {
            funcs::insert_one_elem<command_type>(ns_stack.top().simple_command_list, ns_stack.top().position, code_element);
			stack_close();

		}
		else if (ns_stack.top().keyword == stack_kw::open_scope) {
            funcs::insert_one_elem<command_type>(ns_stack.top().simple_command_list, ns_stack.top().position, code_element);
            ns_stack.top().position++;
		}


	}


	void console_reader::list_handle(const std::vector<string_t>& list_of_strs) {
		for (auto& it : list_of_strs) {
			cmd_make(it);
		}
	}


	code::code_type console_reader::read() {

		string_t str = input_handle();
		funcs::space_free(str);
        std::vector<string_t> dividers{syntax::block_open_scope, syntax::block_open_scope};

		list_handle(funcs::multiple_parse(str, dividers));

		while (!ns_stack.empty()) {
			string_t str = input_handle();
            str = funcs::space_free(str);
            list_handle(funcs::multiple_parse(str, dividers));
		}

		code::code_type result = code;
		code.clear();
		mark_number = 0;
		return result;
	}


	void console_reader::set_input(const string_t& in_name)	{
		input.close();
		input.open(in_name);
	}


}
