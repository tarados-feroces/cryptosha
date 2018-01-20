#include "object_view.hpp"


namespace cry {
	namespace code {

    	using expression_t = std::vector<lang::object_view>;
		using parameters_t = any_t;

		enum class keywords {
			expression,      ///< math expression
			//function,        ///< function definition
			condition,       ///< for branching
			jump,            ///< for jumping to another command
			empty            ///< command-stub
		};

		class command_type
        {
			size_t mark;
			keywords keyword;
			parameters_t parameters;
		};

		using code_type = std::vector<command_type>;
	}

}
