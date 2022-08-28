#include <iostream>

using namespace std;


double fahrenheitToCelsius(double fahrenheitDegrees) {
    double degreesCelsius = (fahrenheitDegrees - 32) / 1.8000;
    return degreesCelsius;
}

int main() {
    double fahrenheitDegrees;
    cout << "Enter a fahrenheit temperature: ";
    cin >> fahrenheitDegrees;

    double result = fahrenheitToCelsius(fahrenheitDegrees);
    cout << "The temperature in Celsius is: " << result << static_cast<char>(248) << "C";

    return 0;
}



