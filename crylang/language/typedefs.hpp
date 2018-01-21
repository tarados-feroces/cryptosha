#include <string>
#include <vector>

#include <boost/any.hpp>
#include <boost/variant.hpp>
#include <boost/dynamic_bitset.hpp>


namespace cry {

	using string_t = std::string;
	using bitset_t = boost::dynamic_bitset<>;
	using    any_t = boost::any;
	using   size_t = std::size_t;

	using var_name_t = string_t;

    template<class... T>
    using variant = boost::variant<T...>;

	using exception_t = std::invalid_argument;
	using bad_any_cast = boost::bad_any_cast;

    using boost::get;
	using boost::any_cast;
}
