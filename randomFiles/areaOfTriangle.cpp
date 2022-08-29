#include <iostream>
using namespace std;

int main() {
    float base;
    float height;
    cout << "Enter the base of the triangle:";
    cin >> base;
    cout << "Enter the height of the triangle:";
    cin >> height;

    float areaOfTriangle = .5*base*height;
    cout << "The area of the triangle is: " << areaOfTriangle;


    return 0;
}
