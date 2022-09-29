#include <iostream>

using namespace std;

int main() {
    int number;
    int myArray[5];
    for (int i=0; i<5; i++) {
        cout << "Enter a number: " << endl;
        cin >> number;
        myArray[i] = number;
    }
    int minValue = myArray[0];
    int maxValue = myArray[0];

    for (int i=1; i<5; i++) {
        if (myArray[i] > maxValue) {
            maxValue = myArray[i];
        }
        if (myArray[i] < minValue) {
            minValue = myArray[i];
        }
    }
    cout << "Maximum value: " << maxValue << endl;
    cout << "Minimum value: " << minValue << endl;

    return 0;
}
