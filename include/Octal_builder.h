
#include "Octal.h"
#include <iostream>
class Builder{
    private:
        Octal obj;
    public:
        Builder();
        Builder& size(int val);
        Builder& arr(unsigned char* t);
        Octal build();
};