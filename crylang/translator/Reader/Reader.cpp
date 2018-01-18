#include "Reader.h"


namespace ancillary_funcs {

    using namespace cry;


    int sys_transfer(string_t str, string_t mod) {
        int numb = 0;
        int res = 0;
        if (mod == "d")
        {
            res = stoi(str);
        }
        else if (mod == "b")
        {
            string_t source("01");
            auto it = --str.end();
            for (; it != str.begin(); --it)
            {
                res += source.find(*it) * pow(2.0, (double)numb);
                ++numb;
            }
            res += source.find(*it) * pow(2.0, (double)numb);
        }
        else if (mod == "h")
        {
            string_t source("0123456789abcdef");
            auto it = --str.end();
            for (; it != str.begin(); --it)
            {
                res += source.find(*it) * pow(16.0, (double)numb);
                ++numb;
            }
            res += source.find(*it) * pow(16.0, (double)numb);
        }
        return res;
    }


    std::vector<int> str_to_int_vec(string_t str, string_t mod) {
        str = str.substr(1, str.size() - 2);
        std::vector<int> buf;
        if (str == "")
            return buf;
        size_t k = 0;
        for (size_t i = 0; i < str.length(); i++)
        {
            if (str[i] == ' ')
            {
                if (str[k] != ' ')
                {
                    buf.push_back(sys_transfer(str.substr(k, i - k), mod));
                }

                k = i + 1;
                continue;
            }
            if (i == str.length() - 1)
            {
                buf.push_back(sys_transfer(str.substr(k, i - k + 1), mod));
            }
        }
        return buf;
    }


    string_t space_free(string_t input_str) {
        for (auto it = input_str.begin(); it != input_str.end();)
        {
            if (*it == ' ')
            {
                input_str.erase(it);
            }
            else
                ++it;
        }
        return input_str;
    }


    std::vector<string_t> simple_str_to_list(string_t input_str, const string_t divider1) {
        std::vector<string_t> vec{};
        size_t prev = 0;
        size_t next;
        size_t delta = divider1.length();

        while ((next = input_str.find(divider1, prev)) != string_t::npos)
        {
            string_t tmp = input_str.substr(prev, next - prev);
            if (input_str.substr(prev, next - prev).size())
                vec.push_back(input_str.substr(prev, next - prev));
            vec.push_back(divider1);
            prev = next + delta;
        }
        cry::string_t tmp = input_str.substr(prev);
        vec.push_back(input_str.substr(prev));
        return vec;
    }

    template <class T>
    void insert_one_elem(std::vector<T>& vector, int pos, T& element) {

        if(pos == vector.size()){
            vector.push_back(element);
            return;
        }

        vector.push_back(vector[vector.size() - 1]);

        for(int i = vector.size() - 2; i > pos; --i) {
            vector[i] = vector[i - 1];
        }

        vector[pos] = element;
    }


    template <class T>
    void erase(std::vector<T>& vector, int pos) {

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


    template <class T>
    void insert(std::vector<T>& vector, int pos, std::vector<T>& insert_vector) {
        for(auto& element : insert_vector) {
            insert_one_elem(vector, pos++, element);
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

//    std::vector<string_t> simple_str_to_list1(string_t input_str, const string_t divider1) {
//        std::vector<string_t> vec;
//        size_t prev = 0;
//        size_t next;
//        size_t delta = divider1.length();
//
//        while ((next = input_str.find(divider1, prev)) != string_t::npos)
//        {
//            string_t tmp = input_str.substr(prev, next - prev);
//            if (input_str.substr(prev, next - prev).size())
//                vec.push_back(input_str.substr(prev, next - prev));
//            prev = next + delta;
//        }
//        string_t tmp = input_str.substr(prev);
//        vec.push_back(input_str.substr(prev));
//        return vec;
//    }

}

//namespace funcs {
//
//	code::types::assigning assinging(string_t str)
//	{
//		code::types::assigning cmd;
//		std::smatch res;
//		std::regex_search(str, res, syntax::regs::assinging);
//		cmd.left_part = ancillary_funcs::space_free(res[1].str());
//		cmd.expression = ancillary_funcs::space_free(res[2].str());
//		return cmd;
//	}
//
//	code::types::delete_element del(string_t str)
//	{
//		code::types::delete_element cmd;
//		std::smatch res;
//		std::regex_search(str, res, syntax::regs::del);
//		cmd.element_name = res[1].str();
//		return cmd;
//	}
//
//	code::types::connect connect(string_t str)
//	{
//		code::types::connect cmd;
//		std::smatch res;
//		std::regex_search(str, res, syntax::regs::connect);
//		cmd.sender_name = res[1].str();
//		cmd.pins_of_sender = ancillary_funcs::simple_str_to_list1(res[2].str(), ",");
//		cmd.receiver_name = res[3].str();
//		cmd.pins_of_receiver = ancillary_funcs::simple_str_to_list1(res[4].str(), ",");
//		return cmd;
//	}
//
//	code::types::script script(string_t str)
//	{
//		code::types::script cmd;
//		std::smatch res;
//		std::regex_search(str, res, syntax::regs::script);
//		cmd.ofstream = res[1].str();
//
//		return cmd;
//	}
//	code::types::add_element add(string_t str)
//	{
//		code::types::add_element cmd;
//		std::smatch res;
//		std::regex_search(str, res, syntax::regs::add);
//		cmd.element_name_index = res[2].str();
//		cmd.element_key = code::name_to_element_key.at(res[1].str());
//		cmd.iosize = iosize_t(stoi(res[3].str()), stoi(res[4].str()));
//
//		cmd.graphic_x = res[6].str();
//		cmd.graphic_y = res[7].str();
//
//		cmd.graphic_width = res[9].str();
//		cmd.graphic_height = res[10].str();
//
//
//		return cmd;
//	}
//
//	code::types::add_element add_s_p(string_t str)
//	{
//		code::types::add_element cmd;
//		std::smatch res;
//		std::regex_search(str, res, syntax::regs::add_s_p);
//		cmd.element_name_index = res[2].str();
//		cmd.element_key = code::name_to_element_key.at(res[1].str());
//		cmd.iosize = iosize_t(stoi(res[3].str()), stoi(res[4].str()));
//
//		if (res[1].str() == syntax::element_names::simple_sbox)
//			cmd.extra_options.insert({ code::types::add_element::keys::s_vector, ancillary_funcs::str_to_int_vec(res[6].str(), res[5].str()) });
//		else if (res[1].str() == syntax::element_names::p_block)
//			cmd.extra_options.insert({ code::types::add_element::keys::p_vector, ancillary_funcs::str_to_int_vec(res[6].str(), res[5].str()) });
//
//		cmd.graphic_x = res[8].str();
//		cmd.graphic_y = res[9].str();
//		cmd.graphic_width = res[11].str();
//		cmd.graphic_height = res[12].str();
//
//		return cmd;
//	}
//
//	code::types::run_element run_element(string_t str)
//	{
//		code::types::run_element cmd;
//		std::smatch res;
//		std::regex_search(str, res, syntax::regs::run_element);
//		cmd.element_name = res[1].str();
//		cmd.bitset_pool = ancillary_funcs::simple_str_to_list1(res[2].str(), ",");
//		cmd.bit_numbers = ancillary_funcs::simple_str_to_list1(res[3].str(), ",");
//		return cmd;
//	}
//
//	code::types::run_scheme run_scheme(string_t str)
//	{
//		code::types::run_scheme cmd;
//		std::smatch res;
//		std::regex_search(str, res, syntax::regs::run_scheme);
//		cmd.bitset_pool = ancillary_funcs::simple_str_to_list1(res[1].str(), ",");
//		cmd.bit_numbers = ancillary_funcs::simple_str_to_list1(res[2].str(), ",");
//		return cmd;
//	}
//
//	code::types::run_layer run_layer(string_t str)
//	{
//		code::types::run_layer cmd;
//		std::smatch res;
//		std::regex_search(str, res, syntax::regs::run_layer);
//		cmd.layer_number = res[1].str();
//		cmd.bitset_pool = ancillary_funcs::simple_str_to_list1(res[2].str(), ",");
//		return cmd;
//	}
//
//	code::types::greatest_potentional greatest_potentional(string_t str)
//	{
//		code::types::greatest_potentional cmd;
//		std::smatch res;
//		std::regex_search(str, res, syntax::regs::greatest_potentional);
//		cmd.element_name = res[1].str();
//		cmd.diff = res[2].str();
//		cmd.bitset_pool = ancillary_funcs::simple_str_to_list1(res[3].str(), ",");
//		return cmd;
//	}
//
//
//}

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
            ancillary_funcs::insert<command_type>(ns_stack.top().simple_command_list, ns_stack.top().position, code_st_el);
//            ns_stack.top().simple_command_list.insert(ns_stack.top().it, code_st_el.begin(), code_st_el.end());
            ns_stack.top().position += code_st_el.size();
        }
	}


//	std::vector<string_t> console_reader::str_to_list(string_t input_str, const string_t divider1 = "{", const string_t divider2 = "}") {
//		std::vector<string_t> list_of_strs = {};
//		std::vector<string_t> vec{};
//
//		list_of_strs = ancillary_funcs::simple_str_to_list(input_str, divider1);
//
//		auto last = list_of_strs.begin();
//		auto first = last++;
//
//		while (first != list_of_strs.end())
//		{
//			vec = ancillary_funcs::simple_str_to_list(*first, divider2);
//			list_of_strs.insert(last, vec.begin(), vec.end());
//			list_of_strs.erase(first);
//			first = last;
//			if (last != list_of_strs.end())
//				++last;
//		}
//
//		return list_of_strs;
//	}

    std::vector<string_t> multiple_parse(string_t& input_str, std::vector<string_t>& dividers) {

        std::vector<string_t> vec{input_str};
        string_t current;

        for(auto& divider : dividers ) {
            for(int i = vec.size() - 1; i >= 0; --i) {

                auto parsed_string = ancillary_funcs::parse(vec[i], divider);


                ancillary_funcs::erase<string_t>(vec, i);
                ancillary_funcs::insert<string_t>(vec, i, parsed_string);

            }

        }

        return vec;
    }


	string_t console_reader::input_handle() {
		string_t result = string_t("");
		string_t str;
		std::vector<string_t> list{};
		std::vector<string_t> dividers{"(", ")"}; // под вопросом
		do {
			getline(input, str);
			list = multiple_parse(str, dividers);
			str.clear();

			for (auto& it : list)
			{
				if (it == "(")
				{
					input_stack.push("(");
					result = result + it;ancillary_funcs::space_free(str);
				}
				else if (it == ")")
				{
					if (input_stack.empty())
					{
						output << output::err_str << std::endl;
						return string_t("");
					}
					else
					{
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

//		command_type command;

		cmd_creator.change_str(input);
//		command.parameters = cmd_creator.handle();
//        command.mark = mark_number++;

		return cmd_creator.handle();
	}


	void console_reader::cmd_make(string_t input_str) {

		if (!input_str.size())
			return;

		std::smatch res;
		command_type code_element;
		stack_elem st_el;

		if (std::regex_search(input_str, res, m_for))
		{
			++num;
			ns_stack.push(st_el);
			ns_stack.top().keyword = stack_kw::m_for;

            code_element.mark = mark_number++;
            code_element.keyword = keywords::expression;
			code_element.parameters = simple_cmd_handle(res[1].str());
			ns_stack.top().simple_command_list.push_back(code_element);

			code_element.mark = mark_number++;
//			code_element.condition = res[2].str();
			code_element.keyword = keywords::condition;
            code_element.parameters = mark_number;
            code_element.parameters = simple_cmd_handle(res[2].str());
			ns_stack.top().simple_command_list.push_back(code_element);

//			code_element.mark = mark_number++;
//			code_element.keyword = code::keyword_t::goto_after;
//			code_element.command = code::types::goto_after{ mark_number + 1 };
//			ns_stack.top().simple_command_list.push_back(code_element);


            code_element.mark = mark_number++;
            code_element.keyword = keywords::expression;
            code_element.parameters = simple_cmd_handle(res[3].str());
            ns_stack.top().simple_command_list.push_back(code_element);
//			ns_stack.top().simple_command_list.push_back(code_element);
			ns_stack.top().position = 3;

			code_element.mark = mark_number++;
//			code_element.condition = "";
			code_element.keyword = keywords::jump;
			code_element.parameters = mark_number - 4;  // Изменить, если меняется кол-во блоков в for
			ns_stack.top().simple_command_list.push_back(code_element);

			return;
		}

		else if (input_str == "{")
		{
			//ind = false;
			++num;
            st_el.keyword = stack_kw::open_scope;
//            st_el.simple_command_list.push_back(code_element);
            st_el.position = 0;
			ns_stack.push(st_el);
//			ns_stack.top().keyword = stack_kw::open_scope;
//			ns_stack.top().it = ns_stack.top().simple_command_list.begin();
			return;
		}

		else if (input_str == "}")
		{
			if (!ns_stack.empty())
				stack_close();
			else
			{
				output << output::err_str << std::endl;
				return;
			}
			if (!ns_stack.empty())
			{
				if (ns_stack.top().keyword == stack_kw::m_for)
					stack_close();
			}
			return;
		}

//		code_element = simple_cmd_handle(input_str);
//
//		if (code_element.command.empty())
//		{
//			output << output::err_str << std::endl;
//			return;
//		}
        code_element.mark = mark_number++;
        code_element.keyword = keywords::expression;
        code_element.parameters = simple_cmd_handle(input_str);

		if (ns_stack.empty())
		{
//            ns_stack.top().simple_command_list.push_back(code_element);
			code.push_back(code_element);
		}
		else if (ns_stack.top().keyword == stack_kw::m_for)
		{
//			ns_stack.top().simple_command_list.insert(ns_stack.top().it, code_element);
            ancillary_funcs::insert_one_elem<command_type>(ns_stack.top().simple_command_list, ns_stack.top().position, code_element);
			stack_close();

		}
		else if (ns_stack.top().keyword == stack_kw::open_scope)
		{
//			ns_stack.top().simple_command_list.insert(ns_stack.top().it, code_element);
            ancillary_funcs::insert_one_elem<command_type>(ns_stack.top().simple_command_list, ns_stack.top().position, code_element);
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
		ancillary_funcs::space_free(str);
        std::vector<string_t> dividers{"{", "}"};

		list_handle(multiple_parse(str, dividers));

		while (!ns_stack.empty())
		{
			string_t str = input_handle();
            str = ancillary_funcs::space_free(str);
            list_handle(multiple_parse(str, dividers));
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
