#include <iostream>
using namespace std;


void increment(int& value);

int main() {
    // Program that swaps the values of two reference variables

    int x=5;
    int& ref = x;

    cout << "Initial value of x: " << ref << endl;

    increment(ref);

    cout << "Final value of x: " << ref << endl;


    return 0;
}

void increment(int& value) {
    value++;
}
