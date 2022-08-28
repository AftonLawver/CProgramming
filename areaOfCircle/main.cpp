#include <iostream>
#include <cmath>

using namespace std;

double areaOfCirlce(double radius) {
    double area =  M_PI * pow(radius, 2);
    return area;
}

int main() {
    double radius;
    cout << "Enter the value of the radius of the circle:";
    cin >> radius;
    double area = areaOfCirlce(radius);
    cout << "The area of the circle is: " << area;
    return 0;
}
