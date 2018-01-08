#include "typedefs.hpp"



namespace cry {

	namespace lang {

		enum class types {
			variable,
			function,
			operation
		}

		class object_view
		{
			template<class S>
			object_view( types type, S&& name )
				: type( type )
				, name( std::forward<S>(name) )

			object_view( const object_view& ) = default;
			object_view( object_view&& ) = default;
			object_view operator=( const object_view& ) = default;
			object_view operator=( object_view&& ) = default;

			friend bool operator==( const object_view& lhs,const object_view& rhs )
			{
				return (_lhs._type == _rhs._type) && (_lhs._name == _rhs._name);
			}

			types type() const
			{
				return _type;
			}




		protected:
			types _type;
			string_t _name;
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
