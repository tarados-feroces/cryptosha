#pragma once
#include "../convertor/convertor.h"
#include <fstream>
#include <regex>
//#include "../ancillary_funcs.hpp"
#include "../regs.hpp"
#include "../../language/code.hpp"


using namespace cry;

namespace cryptosha 
{
	enum class stack_kw
	{
		open_scope,
		m_for
	};

	std::vector<int> str_to_int_vec(string_t str, string_t mod = "d");

	string_t space_free(string_t);

	struct stack_elem {

        stack_elem():keyword(stack_kw::open_scope), position(0){
//            position = 0;
//            simple_command_list.push_back(code::command_type());
//            it = simple_command_list.begin();
        }

		stack_kw keyword;
		code::code_type simple_command_list;
//		code::code_type::iterator it;
        size_t position;
	};

	class console_reader
	{
	public:
		console_reader(const string_t& in_name,
					   const string_t& out_name)
			: input(in_name), output(out_name)
		{}
		
		void set_input(const string_t& in_name);
		
		code::code_type read();
		
		code::code_type read(string_t&&);

		~console_reader() = default;
		
		bool ifstream_good() const;
		

	private:
		std::vector<string_t> str_to_list(string_t, const string_t, const string_t);

		void cmd_make(string_t);

		void stack_close();

		expression_t simple_cmd_handle(string_t);

		string_t input_handle();

		convertor cmd_creator;

		void list_handle(const std::vector<string_t>&);

		size_t num = 0;

		size_t mark_number = 0;

		code::code_type code;

		std::stack<stack_elem> ns_stack;
		std::stack<string_t> input_stack;

		//std::unique_ptr<std::istream> input;
		std::ifstream input;
		std::ofstream output;
	};
}
