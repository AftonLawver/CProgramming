#include <iostream>
#include <cmath>


using namespace std;

bool is_prime(int input);

int main() {
    bool result = is_prime(43);
    if (result == true) {
        cout << "Number is prime." << endl;
    }
    else if (result == false) {
        cout << "Number is not prime." << endl;
    }
    return 0;
}

bool is_prime(int input) {
    if (input <= 2) {
        return false;
    }
    for (int i = 2; i <= sqrt(input); i++) {
        if (input % i == 0) {
            return false;
        }
        else {
            return true;
        }
    }
}
