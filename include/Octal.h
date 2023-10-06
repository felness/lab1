#pragma once
#include <string>


class Octal{
private:
    unsigned char* _array;
    int _size;

public:
    Octal();
    Octal(const size_t &n, unsigned char t);
    Octal(const std::initializer_list< unsigned char> &t);
    Octal(const std::string &t);
    Octal(const Octal& other);
    Octal(Octal&& other) noexcept;
    virtual ~Octal() noexcept;

    unsigned char* getArray();
    int getSize();
    Octal operator+(const Octal& other);
    Octal operator-(const Octal& other);
    bool equal(const Octal& other);
    bool more(const Octal& other) const;
    bool less(const Octal& other) const;
    std::ostream& print(std::ostream& os);

    friend class Builder;
};
std::ostream &operator <<(std::ostream& os, const Octal& object);
