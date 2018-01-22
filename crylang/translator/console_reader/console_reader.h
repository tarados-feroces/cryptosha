#pragma once

#include "includes.hpp"
#include <iostream>
#include <stack>
#include <vector>
#include <regex>
#include <fstream>

#include "convertor.h"
#include "regs.hpp"
#include "handler.hpp"


using namespace cry;
using namespace cry::lang;

namespace cryptosha {

	enum class stack_kw {
		open_scope,
		m_for
	};


	struct stack_elem {

        stack_elem():keyword(stack_kw::open_scope), position(0){}

		stack_kw keyword;
		code::code_type simple_command_list;
        size_t position;
	};


	class console_reader {
	public:
		console_reader(const string_t& in_name,
					   const string_t& out_name)
			: input(in_name), output(out_name), cmd_creator(handler::handler){}


		void set_input(const string_t& in_name);


		code::code_type read();


		~console_reader() = default;


		bool ifstream_good() const;
		

	private:

		void cmd_make(string_t);


        void handle_for(std::smatch&, command_type&);


		void stack_close();


		expression_t simple_cmd_handle(string_t);


		string_t input_handle();


		void list_handle(const std::vector<string_t>&);


		convertor cmd_creator;

		static const size_t num_of_for_blocks_before_ins = 3;
		static const size_t num_of_for_blocks_after_ins = 3;

		size_t mark_number = 0;

		code::code_type code;

		std::stack<stack_elem> ns_stack;

		std::stack<string_t> input_stack;

		std::ifstream input;

		std::ofstream output;
	};
}