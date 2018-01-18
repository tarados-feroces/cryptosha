#include "Reader.h"



namespace ancillary_funcs {

	using namespace cry;

	int sys_transfer(string_t str, string_t mod)
	{
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

	int_vector str_to_int_vec(string_t str, string_t mod)
	{
		str = str.substr(1, str.size() - 2);
		int_vector buf;
		if (str == "")
			return buf;
		size_type k = 0;
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

	string_t space_free(string_t input_str)
	{
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

	expressions simple_str_to_list(string_t input_str, const string_t divider1)
	{
		expressions vec;
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

	expressions simple_str_to_list1(string_t input_str, const string_t divider1)
	{
		cry::expressions vec;
		size_t prev = 0;
		size_t next;
		size_t delta = divider1.length();

		while ((next = input_str.find(divider1, prev)) != string_t::npos)
		{
			string_t tmp = input_str.substr(prev, next - prev);
			if (input_str.substr(prev, next - prev).size())
				vec.push_back(input_str.substr(prev, next - prev));
			prev = next + delta;
		}
		string_t tmp = input_str.substr(prev);
		vec.push_back(input_str.substr(prev));
		return vec;
	}
}

namespace funcs
{

	code::types::assigning assinging(string_t str)
	{
		code::types::assigning cmd;
		std::smatch res;
		std::regex_search(str, res, syntax::regs::assinging);
		cmd.left_part = ancillary_funcs::space_free(res[1].str());
		cmd.expression = ancillary_funcs::space_free(res[2].str());
		return cmd;
	}

	code::types::delete_element del(string_t str)
	{
		code::types::delete_element cmd;
		std::smatch res;
		std::regex_search(str, res, syntax::regs::del);
		cmd.element_name = res[1].str();
		return cmd;
	}

	code::types::connect connect(string_t str)
	{
		code::types::connect cmd;
		std::smatch res;
		std::regex_search(str, res, syntax::regs::connect);
		cmd.sender_name = res[1].str();
		cmd.pins_of_sender = ancillary_funcs::simple_str_to_list1(res[2].str(), ",");
		cmd.receiver_name = res[3].str();
		cmd.pins_of_receiver = ancillary_funcs::simple_str_to_list1(res[4].str(), ",");
		return cmd;
	}

	code::types::script script(string_t str)
	{
		code::types::script cmd;
		std::smatch res;
		std::regex_search(str, res, syntax::regs::script);
		cmd.ofstream = res[1].str();

		return cmd;
	}
	code::types::add_element add(string_t str)
	{
		code::types::add_element cmd;
		std::smatch res;
		std::regex_search(str, res, syntax::regs::add);
		cmd.element_name_index = res[2].str();
		cmd.element_key = code::name_to_element_key.at(res[1].str());
		cmd.iosize = iosize_t(stoi(res[3].str()), stoi(res[4].str()));

		cmd.graphic_x = res[6].str();
		cmd.graphic_y = res[7].str();

		cmd.graphic_width = res[9].str();
		cmd.graphic_height = res[10].str();


		return cmd;
	}

	code::types::add_element add_s_p(string_t str)
	{
		code::types::add_element cmd;
		std::smatch res;
		std::regex_search(str, res, syntax::regs::add_s_p);
		cmd.element_name_index = res[2].str();
		cmd.element_key = code::name_to_element_key.at(res[1].str());
		cmd.iosize = iosize_t(stoi(res[3].str()), stoi(res[4].str()));

		if (res[1].str() == syntax::element_names::simple_sbox)
			cmd.extra_options.insert({ code::types::add_element::keys::s_vector, ancillary_funcs::str_to_int_vec(res[6].str(), res[5].str()) });
		else if (res[1].str() == syntax::element_names::p_block)
			cmd.extra_options.insert({ code::types::add_element::keys::p_vector, ancillary_funcs::str_to_int_vec(res[6].str(), res[5].str()) });

		cmd.graphic_x = res[8].str();
		cmd.graphic_y = res[9].str();
		cmd.graphic_width = res[11].str();
		cmd.graphic_height = res[12].str();

		return cmd;
	}

	code::types::run_element run_element(string_t str)
	{
		code::types::run_element cmd;
		std::smatch res;
		std::regex_search(str, res, syntax::regs::run_element);
		cmd.element_name = res[1].str();
		cmd.bitset_pool = ancillary_funcs::simple_str_to_list1(res[2].str(), ",");
		cmd.bit_numbers = ancillary_funcs::simple_str_to_list1(res[3].str(), ",");
		return cmd;
	}

	code::types::run_scheme run_scheme(string_t str)
	{
		code::types::run_scheme cmd;
		std::smatch res;
		std::regex_search(str, res, syntax::regs::run_scheme);
		cmd.bitset_pool = ancillary_funcs::simple_str_to_list1(res[1].str(), ",");		
		cmd.bit_numbers = ancillary_funcs::simple_str_to_list1(res[2].str(), ",");
		return cmd;
	}

	code::types::run_layer run_layer(string_t str)
	{
		code::types::run_layer cmd;
		std::smatch res;
		std::regex_search(str, res, syntax::regs::run_layer);
		cmd.layer_number = res[1].str();
		cmd.bitset_pool = ancillary_funcs::simple_str_to_list1(res[2].str(), ",");
		return cmd;
	}

	code::types::greatest_potentional greatest_potentional(string_t str)
	{
		code::types::greatest_potentional cmd;
		std::smatch res;
		std::regex_search(str, res, syntax::regs::greatest_potentional);
		cmd.element_name = res[1].str();
		cmd.diff = res[2].str();
		cmd.bitset_pool = ancillary_funcs::simple_str_to_list1(res[3].str(), ",");
		return cmd;
	}


}

namespace output
{
	string_t err_str("incorrect input");
	string_t begin_str(">>>> ");
	string_t tab_str("   ");
	string_t begin_tab_str("     ");
}

namespace cryptosha
{


	bool console_reader::ifstream_good() const
	{
		return input.good();
	}

	void console_reader::stack_close()
	{
		--num;
		if (ns_stack.empty())
		{
			output << output::err_str << std::endl;
			return;
		}
		code::code_type code_st_el = ns_stack.top().simple_command_list;
		ns_stack.pop();
		if (ns_stack.empty())
		{
			code = code_st_el;
		}
		else
			ns_stack.top().simple_command_list.insert(ns_stack.top().it, code_st_el.begin(), code_st_el.end());
	}


	std::list<string_t> console_reader::str_to_list(string_t input_str, const string_t divider1 = syntax::keywords::c_open, const string_t divider2 = syntax::keywords::c_close)
	{
		std::list<string_t> list_of_strs;
		std::list<string_t> vec;

		list_of_strs = ancillary_funcs::simple_str_to_list(input_str, divider1);

		auto last = list_of_strs.begin();
		auto first = last++;

		while (first != list_of_strs.end())
		{
			vec = ancillary_funcs::simple_str_to_list(*first, divider2);
			list_of_strs.insert(last, vec.begin(), vec.end());
			list_of_strs.erase(first);
			first = last;
			if (last != list_of_strs.end())
				++last;
		}

		return list_of_strs;
	}


	string_t console_reader::input_handle()
	{
		string_t result = string_t("");
		string_t str;
		std::list<string_t> list;
		do {
			getline(input, str);
			list = str_to_list(str, syntax::keywords::c_open, syntax::keywords::c_close);
			str.clear();

			for (auto& it : list)
			{
				if (it == syntax::keywords::c_open_m)
				{
					input_stack.push(syntax::keywords::c_open_m);
					result = result + it;
				}
				else if (it == syntax::keywords::c_close_m)
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


	code::simple_command console_reader::simple_cmd_handle(string_t input_str, string_t condition = "")
	{
		std::smatch res;

		code::simple_command code_element;

		if (std::regex_match(input_str, syntax::regs::assinging))
		{
			code_element.keyword = code::keyword_t::assinging;
			code_element.command = funcs::assinging(input_str);
			code_element.condition = condition;
			code_element.mark = mark_number++;
		}
		if (std::regex_match(input_str, syntax::regs::assembly))
		{
			code_element.keyword = code::keyword_t::assembly;
			code_element.condition = condition;
			code_element.mark = mark_number++;
			code_element.command = 42;
		}
		if (std::regex_match(input_str, syntax::regs::clear_scheme))
		{
			code_element.keyword = code::keyword_t::clear_scheme;
			code_element.condition = condition;
			code_element.mark = mark_number++;
			code_element.command = 42;
		}
		if (std::regex_match(input_str, syntax::regs::run))
		{
			code_element.keyword = code::keyword_t::run;
			code_element.condition = condition;
			code_element.mark = mark_number++;
			code_element.command = 42;
		}
		else if (std::regex_match(input_str, syntax::regs::del))
		{
			code_element.keyword = code::keyword_t::delete_element;
			code_element.command = funcs::del(input_str);
			code_element.condition = condition;
			code_element.mark = mark_number++;
		}
		else if (std::regex_match(input_str, syntax::regs::connect))
		{
			code_element.keyword = code::keyword_t::connect;
			code_element.command = funcs::connect(input_str);
			code_element.condition = condition;
			code_element.mark = mark_number++;
		}
		else if (std::regex_match(input_str, syntax::regs::add))
		{
			code_element.keyword = code::keyword_t::add_element;
			code_element.command = funcs::add(input_str);
			code_element.condition = condition;
			code_element.mark = mark_number++;
		}
		else if (std::regex_match(input_str, syntax::regs::add_s_p))
		{
			code_element.keyword = code::keyword_t::add_element;
			code_element.command = funcs::add_s_p(input_str);
			code_element.condition = condition;
			code_element.mark = mark_number++;
		}
		else if (std::regex_match(input_str, syntax::regs::script))
		{
			code_element.keyword = code::keyword_t::script;
			code_element.command = funcs::script(input_str);
			code_element.condition = condition;
			code_element.mark = mark_number++;
		}
		else if (std::regex_match(input_str, syntax::regs::run_element))
		{
			code_element.keyword = code::keyword_t::run_element;
			code_element.command = funcs::run_element(input_str);
			code_element.condition = condition;
			code_element.mark = mark_number++;
		}
		else if (std::regex_match(input_str, syntax::regs::run_scheme))
		{
			code_element.keyword = code::keyword_t::run_scheme;
			code_element.command = funcs::run_scheme(input_str);
			code_element.condition = condition;
			code_element.mark = mark_number++;
		}
		else if (std::regex_match(input_str, syntax::regs::run_layer))
		{
			code_element.keyword = code::keyword_t::run_layer;
			code_element.command = funcs::run_layer(input_str);
			code_element.condition = condition;
			code_element.mark = mark_number++;
		}
		else if (std::regex_match(input_str, syntax::regs::greatest_potentional))
		{
			code_element.keyword = code::keyword_t::greatest_potentional;
			code_element.command = funcs::greatest_potentional(input_str);
			code_element.condition = condition;
			code_element.mark = mark_number++;
		}

		return code_element;
	}


	void console_reader::cmd_make(string_t input_str)
	{
		if (!input_str.size())
			return;

		std::smatch res;
		code::simple_command code_element;
		stack_elem st_el;

		if (std::regex_search(input_str, res, syntax::regs::m_for))
		{
			++num;
			ns_stack.push(st_el);
			ns_stack.top().keyword = stack_kw::m_for;

			code_element = simple_cmd_handle(res[1].str());
			ns_stack.top().simple_command_list.push_back(code_element);

			code_element.mark = mark_number++;
			code_element.condition = res[2].str();
			code_element.keyword = code::keyword_t::goto_after;
			code_element.command = code::types::goto_after{ mark_number };
			ns_stack.top().simple_command_list.push_back(code_element);

			code_element.mark = mark_number++;
			code_element.condition = "";
			code_element.keyword = code::keyword_t::goto_after;
			code_element.command = code::types::goto_after{ mark_number + 1 };
			ns_stack.top().simple_command_list.push_back(code_element);


			code_element = simple_cmd_handle(res[3].str());
			ns_stack.top().simple_command_list.push_back(code_element);
			ns_stack.top().it = --ns_stack.top().simple_command_list.end();

			code_element.mark = mark_number++;
			code_element.condition = "";
			code_element.keyword = code::keyword_t::goto_after;
			code_element.command = code::types::goto_after{ mark_number - 5 };
			ns_stack.top().simple_command_list.push_back(code_element);

			return;

		}

		else if (input_str == syntax::keywords::c_open)
		{
			//ind = false;
			++num;
			ns_stack.push(st_el);
			ns_stack.top().keyword = stack_kw::open_scope;
			ns_stack.top().it = ns_stack.top().simple_command_list.begin();
			return;
		}

		else if (input_str == syntax::keywords::c_close)
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

		code_element = simple_cmd_handle(input_str);

		if (code_element.command.empty())
		{
			output << output::err_str << std::endl;
			return;
		}
		if (ns_stack.empty())
		{
			code.push_back(code_element);
		}
		else if (ns_stack.top().keyword == stack_kw::m_for)
		{
			ns_stack.top().simple_command_list.insert(ns_stack.top().it, code_element);
			stack_close();

		}
		else if (ns_stack.top().keyword == stack_kw::open_scope)
		{
			ns_stack.top().simple_command_list.insert(ns_stack.top().it, code_element);
		}


	}


	void console_reader::list_handle(const expressions& list_of_strs)
	{
		for (auto it : list_of_strs)
		{
			cmd_make(it);
		}
	}

	code::code_type console_reader::read()
	{
		output << output::begin_str;
		string_t str = input_handle();

		if (!ancillary_funcs::space_free(str).size())
		{
			code::simple_command code_element;
			code_element.condition = string_t("0");
			code::code_type result;
			result.push_back(code_element);
			return result;
		}

		list_handle(str_to_list(str));

		while (!ns_stack.empty())
		{
			output << output::begin_tab_str;
			for (size_type i = 0; i < num; ++i)
				output << output::tab_str;
			string_t str = input_handle();

			list_handle(str_to_list(str));
		}

		code::code_type result = code;
		code.clear();
		mark_number = 0;
		return result;
	}
	
	code::code_type console_reader::read(string_t&& input_str)
	{
		code::code_type result;
		string_t str = input_str;
		if (!ancillary_funcs::space_free(str).size())
		{
			code::simple_command code_element;
			code_element.condition = string_t("0");
			result.push_back(code_element);
			return result;
		}
		list_handle(str_to_list(str));
		result = code;
		code.clear();
		mark_number = 0;
		return result;
	}

	void console_reader::set_input(const string_t& in_name)
	{
		input.close();
		input.open(in_name);
	}



}
