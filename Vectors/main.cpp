#include <iostream>
#include <vector>

using namespace std;

int main() {
    int number;
    vector <int> myVector;
    cout << "Keep entering numbers or enter -1 to exit." << endl;
    cout << "Enter a number:";

    while(true) {
        if(!(cin >> number)) {
            cout << "Invalid input..Enter another integer:" << endl;
            cin.clear();
            cin.ignore(100, '\n');
            continue;
        }
        else if (number == -1) {
            break;
        }
        else {
            myVector.push_back(number);
            cout << "Enter a number:";
            continue;
        }
    }

    cout << "Vector elements before sorting:" << endl;
    for(int i=0; i<myVector.size(); i++) {
        cout << myVector[i] << endl;
    }

    // Bubble sort
    for(int i=0; i<myVector.size(); i++) {
        for (int j=0; j<myVector.size()-i; j++) {
            if (myVector[i] > myVector[i+1]) {
        }

        }
    }

    cout << "Vector elements after sorting:" << endl;
    for(int i=0; i<myVector.size(); i++) {
        cout << myVector[i] << endl;
    }
    return 0;
}
