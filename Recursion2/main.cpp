#include <iostream>
using namespace std;

void print_recursion(int value) {
    if (value == 0) {
        return;
    }
    else {
        print_recursion(value - 1);
        cout << value << endl;
    }
}

int main() {
    print_recursion(5);
    return 0;
}
