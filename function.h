#include "include.h"
string Get_To_Str ( unsigned long int n) {
    bitset<32> bits(n);
    return bits.to_string();
}
void Print_Arr(char *arr, const int size) {
    cout << '[';
    for( int i = 0; i < size; i++) {
        cout << arr[i];
    if (i != size - 1) cout << ',';
    }

    cout << ']' << endl;
}
void Follow (char arr[], string str, const int size) {
    for (int i = 0; i < size; i ++) {
        arr[i] = str[i];
    } // follow array
}

