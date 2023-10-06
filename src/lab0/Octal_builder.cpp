#include "Octal_builder.h"
#include "Octal.h"

Builder::Builder() = default;

Builder& Builder::size(int value){
    object._size = value;
    return *this;
}

Builder& Builder::arr(unsigned char* t){
    object._array = new unsigned char [object._size];

    for (int i = 0; i < object._size; i++){
        object._array[object._size-i-1] = t[i];
    }
    return *this;
}

Octal Builder::build(){
    return object;
}