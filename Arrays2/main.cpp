#include <iostream>

using namespace std;

int main() {
    int myArray[15];
    for (int i=0; i<15; i++) {
        cout << "Enter a number: " << endl;
        cin >> myArray[i];
    }

    // print the array before sorting it
    cout << "Elements of the array before sorting them: " << endl;
    for (int i=0; i<sizeof(myArray)/sizeof(int); i++) {
        cout << myArray[i] << endl;
    }

    for (int i=0; i<sizeof(myArray)/sizeof(int); i++) {
        for (int j=i+1; j<sizeof(myArray)/sizeof(int); j++) {
            if (myArray[j] < myArray[i]) {
                int temp = myArray[i];
                myArray[i] = myArray[j];
                myArray[j] = temp;
            }
        }
    }
    cout << "Elements of the array after sorting them: " << endl;
    for (int i=0; i<sizeof(myArray)/sizeof(int); i++) {
        cout << myArray[i] << endl;
    }


    return 0;
}
