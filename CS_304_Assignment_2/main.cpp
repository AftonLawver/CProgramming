#include <iostream>

using namespace std;

bool is_prime(int input);
void print_factorization(int input);

int main() {
//
    is_prime(8);
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
