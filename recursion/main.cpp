#include <iostream>
using namespace std;

int printNumber(int value) {
    if (value < 1) {
        return 0;
    }
    printNumber(value - 1);
    cout << value << endl;
}

int main() {
    printNumber(5);
    return 0;
}
