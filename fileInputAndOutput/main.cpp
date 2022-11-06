#include <iostream>
#include <fstream>

using namespace std;

int main() {
    fstream fileStream;
    fileStream.open("E:\\CProgramming\\fileInputAndOutput\\test.txt");

    for (int i = 0; i < 100; i++) {
        int temp = fileStream.get();
        if(temp == -1) {
            break;
        }
        cout << (char) temp << endl;
    }
    return 0;
}