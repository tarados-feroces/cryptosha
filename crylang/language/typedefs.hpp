#pragma once
#include <string>
#include <vector>
#include <stack>
#include <map>

#include <boost/any.hpp>
#include <boost/variant.hpp>
#include <boost/dynamic_bitset.hpp>


namespace cry {

	using string_t = std::string;
	using bitset_t = boost::dynamic_bitset<>;
	using    any_t = boost::any;
	using   size_t = std::size_t;

	using pair_t = std::pair<string_t, int>;
	using stack_type = std::stack<pair_t>;
	using map_t = std::map<string_t, int>;

	using var_name_t = string_t;

    template<class... T>
    	using variant = boost::variant<T...>;

	using exception_t = std::invalid_argument;
	using bad_any_cast = boost::bad_any_cast;

    using boost::get;
	using boost::any_cast;
}
