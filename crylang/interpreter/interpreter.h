#pragma once

#include "calculations.hpp"

namespace cryptosha {

	using namespace cry::code;
	using namespace crylang;


	struct interpreter_handler
	{
		object_map objects;
		code_t     current_code;
		size_t     curent_mark;

		interpreter_handler( code_t&& code )
			: objects()
			, current_code( code )
			, curent_mark( 0 )
		{}

		auto get_command() const
		{
			return handler.code[handler.curent_mark];
		}

		auto get_keyword() const
		{
			return get_command().keyword;
		}

		auto next() const
		{
			return ++handler.curent_mark;
		}

		bool is_runable() const
		{
			return curent_mark < current_code.size();
		}
	};

	namespace workers {

		struct empty_worker
		{
			virtual bool operator()( interpreter_handler& handler )
			{
				return true;
			};

			auto get_command( interpreter_handler& handler )
			{
				return handler.code[handler.curent_mark++];
			}
		};

		struct expression : public empty_worker
		{
			virtual bool operator()( interpreter_handler& ) override;
		};

		struct condition : public empty_worker
		{
			virtual bool operator()( interpreter_handler& ) override;
		};

		struct jump : public empty_worker
		{
			virtual bool operator()( interpreter_handler& ) override;
		};

	}


	class interpreter
	{
	public:
		using handler_ptr_t = std::unique_ptr<interpreter_handler>;
		using workers_ptr_t = std::unordered_map<
									keywords,
									std::unique_ptr<empty_worker>
							  >;

		interpreter()
		{
			_worker_ptrs[keywords::expression] = std::make_unique<expression>();
			_worker_ptrs[keywords::condition] = std::make_unique<condition>();
			_worker_ptrs[keywords::jump] = std::make_unique<jump>();
			_worker_ptrs[keywords::empty] = std::make_unique<empty_worker>();
		}

		bool run( code_t&& code )
		{
			set_handler( code );
			bool success = true;

			while( _handler_ptr->is_runable() ) {
				success	= _worker_ptrs[ _handler_ptr->get_keyword ]( _handler_ptr );
				_handler_ptr->next();
			}

			return success;
		}

		void set_handler( code_t&& code )
		{
			_handler_ptr = std::make_unique<interpreter_handler>( code );
		}

		~interpreter() = default;
	protected:
		handler_ptr_t _handler_ptr;
		workers_ptr_t _worker_ptrs;

	}

}
