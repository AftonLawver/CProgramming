#include <iostream>
using namespace std;

int printNumber(int value) {
    if (value < 1) {
        return 0;
    }
    cout << value << endl;
    printNumber(value - 1);
}

int main() {
    printNumber(5);
    return 0;
}
