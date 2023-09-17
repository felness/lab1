#include <iostream>

#include "lib.h"

using namespace std;

int main() {
    int first,second;
    cout<<"Enter the first number:"<<endl;
    cin>>first;
    cout<<"Enter the second number:"<<endl;
    cin>>second;
    if(gcd(first,second)<0) {
         cout<<"gcd is "<<gcd(first,second)*-1<<endl;
    }
       
    else{
        cout<<"gcd is "<<gcd(first,second)<<endl;
    }
    

}