
#include "function.h"
#include "const.h"
#include "include.h"
int main () {
    char arr[SIZE];  // array of letters to output
    unsigned long  int num; // number
    cout << "Enter your number: \n";
    cin >> num;
    string Arr_Str{Get_To_Str(num)}; // return string
    Follow(arr, Arr_Str, SIZE);
    Print_Arr(arr, SIZE);

    return 0;


}
