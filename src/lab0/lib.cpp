#include <cstdlib>
#include "lib.h"

int gcd(int first_number,int second_number) {
    first_number=abs(first_number);
    second_number=abs(second_number);
    if (second_number==0)
        return first_number;
    return gcd(second_number,first_number%second_number);
}
