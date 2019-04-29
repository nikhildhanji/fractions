#ifndef _INVALID_ARGUMENT_EXCEPTION_H_
#define _INVALID_ARGUMENT_EXCEPTION_H_
#include <exception>
class InvalidArgumentException: public std::exception
{
    public:

    InvalidArgumentException() = default;
    ~InvalidArgumentException() = default;
    virtual const char* what() const noexcept{
        return "Invalid argument exception!";
    }
};

#endif // _INVALID_ARGUMENT_EXCEPTION_H_
