#pragma once
#include "typedefs.hpp"



namespace cry {

	namespace lang {

		enum class types {
			variable,
			function,
			operation
		};

		class object_view
		{
		public:
			template<class S>
			object_view( types type, S&& name )
				: _type( type )
				, _name( std::forward<S>(name) )
			{}

			object_view( const object_view& ) = default;
			object_view( object_view&& ) = default;
			object_view& operator=( const object_view& ) = default;
			object_view& operator=( object_view&& ) = default;

			friend bool operator==( const object_view& lhs,const object_view& rhs )
			{
				return (lhs._type == rhs._type) && (lhs._name == rhs._name);
			}

			types type() const
			{
				return _type;
			}

			const string_t& name() const
			{
				return _name;
			}

			types _type;
			string_t _name;
		};
	}
}

