
#include "Octal.h"
#include <iostream>
class Builder{
    private:
        Octal object;
    public:
        Builder();
        Builder& size(int value);
        Builder& arr(unsigned char* t);
        Octal build();
};