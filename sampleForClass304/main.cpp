#include <iostream>
using namespace std;

int main() {
    int number;
    do {
        cout << "Please enter a positive number: " << endl;
    }
    while((!(cin >> number)) || (number <= 0));
    for (int a=1; a <= number; a++) {
        for (int i = 1; i <= number; i++) {
            if (a % 2 == 0) {
                int result = (i+1) % 2;
                cout << result << " ";
            }
            else {
                int result = i % 2;
                cout << result << " ";
            }
        }
        cout << endl;
    }

    return 0;
}
