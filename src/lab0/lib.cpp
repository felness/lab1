
#include "lib.h"

int gcd(int first_number,int second_number) {
    if (second_number==0)
        return first_number;
    return gcd(second_number,first_number%second_number);
}
