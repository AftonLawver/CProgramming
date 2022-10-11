#include <iostream>

using namespace std;

bool is_prime(int input);
void print_factorization(int input);

int main() {
    int input;
    cout << "Welcome to the prime factor calculator!" << endl;
    int count = 0;
    while(true) {
        if (count >=1) {
            cout << "Please enter another number or enter 0 to exit: " << endl;
        }
        else {
            cout << "Please enter a number or enter 0 to exit: " << endl;
        }
        while ((!(cin >> input))) {

            cout << "Invalid input..Please enter a valid integer: " << endl;
            cin.clear();
            cin.ignore(100, '\n');
        }
        if (input <= 0) {
            return 0;
        }
        else {
            bool isPrime = is_prime(input);
            if (isPrime) {
                cout << "Number is prime." << endl;
            }
            else {
                cout << "Prime factors:" << endl;
                print_factorization(input);
            }
            count ++;
        }
    }
}

void print_factorization(int input) {
    if (!is_prime(input)) {
        int num = 2;
        while (input % num != 0) num++;
        cout << num << endl;
        print_factorization(input/num);
    }
    else {
        cout << input << endl;
    }
    }



bool is_prime(int input) {
    if (input <= 1)
        return false;

    for (int i = 2; i < input; i++)
        if (input % i == 0)
            return false;
    return true;
}
