#ifndef READEXCEPTION_H
#define READEXCEPTION_H

#include <iostream>

class ReadException : public std::exception
{
public:
    ReadException() = default;
    ~ReadException() = default;

    const char* what() const noexcept {
        return "Can not read data";
    }
};

#endif // READEXCEPTION_H
