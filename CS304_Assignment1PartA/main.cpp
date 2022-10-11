//
// Created by Aftonlawver on 9/12/2022.
//

#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    int number;
    cout << "Please enter a positive integer number: " << endl;
    while ((!(cin >> number)) || number < 2) {
        cout << "Please enter a positive integer number: " << endl;
        cin.clear();
        cin.ignore(100, '\n');
    }
    for (int i = 1; i <= number; i++) {
        for (int j = 1; j <= number; j++) {
            cout << setw(3);
            cout << i * j << " ";
        }
        cout << endl;
    }
    return 0;
}

