#include <string>
#include <vector>



namespace cry {

	using string_t = std::string;
	using bitset_t = boost::dynamic_bitset<>;
	using    any_t = boost::any;
	using   size_t = std::size_t;

	using exception_t = std::invalid_argument;
	using bad_any_cast = boost::bad_any_cast;

	using boost::any_cast;


	namespace lang {

		enum class types {
			variable,
			function,
			operation
		}

		struct object_view {

			types type;

			string_t name;
		};
	}

	namespace code {

		using expression_t = std::vector<lang::object_view>;
		using parameters_t = any_t;

		enum class keywords {
			expression,
			function,
			condition,
			moveto,
			empty
		}

		struct command_type {
			size_t mark;

			keywords keyword;
			parameters_t parameters;
		}

		using code_type = std::vector<command_type>;
	}

}