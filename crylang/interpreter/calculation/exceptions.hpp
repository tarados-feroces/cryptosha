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
}
