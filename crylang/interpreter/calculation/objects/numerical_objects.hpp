#include "object.hpp"


namespace crylang {

    class numerical_object
        : public object
    {
    public:

        template<class... Args>
        numerical_object( type obj_type, Args&&... args )
            : object( obj_type, std::forward<Args>(args)... )
        {}

        float_t as_float() const
        {
            return this->as<float_t>();
        }

        int_t as_int() const
        {
            return this->as<float_t>();
        }

        template<typename T>
        T as() const
        {
            switch( this->get_type() )
            {
            case type::Byte:
                return static_cast<T>(this->get<type::Byte>());
            case type::Char:
                return static_cast<T>(this->get<type::Char>());
            case type::Int:
                return static_cast<T>(this->get<type::Int>());
            case type::Float:
                return static_cast<T>(this->get<type::Float>());
            default:
                throw errors::type_error( "Type is not a number" );
            }
        }
    };

}
