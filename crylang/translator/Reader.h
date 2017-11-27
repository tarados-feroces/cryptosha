#pragma once
#include "../../settings.h"


using namespace cry;

namespace cryptosha 
{
	enum class stack_kw
	{
		open_scope,
		m_for
	};

	int_vector str_to_int_vec(string_t str, string_t mod = "d");

	string_t space_free(string_t);

	struct stack_elem
	{
		stack_kw keyword;
		code::code_type simple_command_list;
		code::code_type::iterator it;
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
		std::list<string_t> str_to_list(string_t, const string_t, const string_t);

		void cmd_make(string_t);

		void stack_close();

		code::simple_command simple_cmd_handle(string_t, string_t);

		string_t input_handle();

		void list_handle(const expressions&);

		size_type num = 0;

		mark_t mark_number = 0;

		code::code_type code;

		std::stack<stack_elem> ns_stack;
		std::stack<string_t> input_stack;

		//std::unique_ptr<std::istream> input;
		ifstream_t input;
		ofstream_t output;
	};
}
