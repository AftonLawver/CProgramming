#include <iostream>
#include <cmath>


using namespace std;

bool is_prime(int input);
void print_factorization(int input);

int main() {
    print_factorization(36);
//    bool result = is_prime(6);
//    if (result == true) {
//        cout << "Number is prime." << endl;
//    }
//    else if (result == false) {
//        cout << "Number is not prime." << endl;
//    }
    return 0;
}

void print_factorization(int input) {
    if( !is_prime(input) )
    {
        // recurse
        for (int i = 2; i < input; i++) {
            if (input % i == 0) {
                cout << i << endl;
                input = input / i;
                print_factorization(input);
            }
            else {
                continue;
            }
        }


    }
    else
    {
        // base case, end recursion.
        cout << input << endl;
    }
}

bool is_prime(int input) {
    // Corner case
    if (input <= 1)
        return false;

    // Check from 2 to n-1
    for (int i = 2; i < input; i++)
        if (input % i == 0)
            return false;
    return true;
}
