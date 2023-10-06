#include <iostream>
#include "Octal.h"



using namespace std;

int main() {

    Octal first_try {'7', '7', '7', '7','6','5'};
    first_try.print(std::cout) << std::endl;
    Octal second {'1','1'};
    Octal res {first_try.operator+(second)};
    res.print(std::cout)<<std::endl;
    return 0; 
}