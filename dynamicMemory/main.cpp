#include <iostream>
using namespace std;
bool isEven(int number);


int main() {
    int input;
    int size = 10;
    int *dynamicIntArray = (int*) realloc(NULL, size * sizeof(int));
    int index = 0;

    cout << "Input a valid positive integer, or 0 to quit: " << endl;
    while(cin >> input) {
        if (input >= 1) {
            dynamicIntArray[index] = input;


            if (index == size) {
                size = size * 2;
                int *dynamicIntArray = (int*) realloc(dynamicIntArray,size * sizeof(int));
                cout << "Array doubled in size." << endl;
                continue;
            }
            index ++;
            cout << "Input another valid positive integer, or 0 to quit: " << endl;
        }
        else {
            int count = 0;
            for (int i = 0; i<index; i++) {
                if (dynamicIntArray[i] == 0) {
                    break;
                }
                else if (isEven(dynamicIntArray[i])) {
                    count ++;
                }
            }
            cout << "Number of numbers that are even: " << count << endl;
        }
    }
    return 0;
}

bool isEven(int number) {
    if (number == 0) {
        return false;
    }
    else if (number % 2 == 0) {
        return true;
    }
    return false;
}
