#include <iostream>
using namespace std;
bool isEven(int number);


int main() {
    int input;
    int *dynamicIntArray = (int*) malloc(10 * sizeof(int));
    int *size;
    int s = 10;
    size = &s;
    int iteration = 1;

    cout << "Input a valid positive integer, or 0 to quit: " << endl;

    while(cin >> input && input >= 1) {

        dynamicIntArray[iteration] = input;
        cout << "Input another valid positive integer, or 0 to quit: " << endl;

    }

    return 0;
}

bool isEven(int number) {
    if(number % 2 ==0) {
        return true;
    }
}
