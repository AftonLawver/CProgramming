#include <iostream>
using namespace std;


int main() {
    int number1;
    int number2;
    int result;
    cout << "Enter a number:";
    cin >> number1;
    cout << "Enter another number:";
    cin >> number2;
    result = number1 % number2;

    cout << "Remainder is: " << result;

    return 0;
}