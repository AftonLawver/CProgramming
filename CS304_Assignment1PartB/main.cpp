#include <iostream>
using namespace std;

int main() {
    int x, y;
    cout << "Please enter two integer numbers: " << endl;
    while ((!(cin >> x)) || (!(cin >> y)) || x < 0 || y < 0) {
        cout << "Invalid input..Please enter two integer numbers: " << endl;
        cin.clear();
        cin.ignore(100, '\n');
    }
    int total = x;
    if (x == 0 && y == 0) {
        cout << "Undefined." << endl;
    }
    else if (x == 0) {
        cout << "0" << endl;
    }
    else if (y == 0) {
        cout << "1" << endl;
    }
    else {
        for (int i = 1; i < y; i++) {
            total *= x;
        }
        cout << "Total: " << total << endl;
    }
    return 0;
}
