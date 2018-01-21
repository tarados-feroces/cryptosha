#include <stdexcept>



namespace errors {

    struct type_error
        : public std::logic_error
    {
        template<class... Args>
        type_error( Args&&... args )
            : std::logic_error( std::forward<Args>(args)... )
        {}
    };

    struct arguments_error
        : public std::logic_error
    {
        template<class... Args>
        arguments_error( Args&&... args )
            : std::logic_error( std::forward<Args>(args)... )
        {}
    };
}
