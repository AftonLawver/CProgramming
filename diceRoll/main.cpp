#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;


int main() {
    const short minValue = 1;
    const short maxValue = 6;
    srand(time(0));
    short first = (rand() % (maxValue - minValue + 1)) + 1;
    short second = (rand() % (maxValue - minValue + 1)) + 1;

    cout << "Die 1: " << first << endl;
    cout << "Die 2: " << second << endl;


    return 0;
}
