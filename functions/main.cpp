//#include <iostream>
//
//using namespace std;
//
//int getFactorial(int number) {
//    int total = 1;
//    for (number; number>0; number--) {
//        total *= number;
//    }
//    return total;
//}
//
//int main() {
//    int total = getFactorial(5);
//    cout << total << endl;
//    return 0;
//}

/*
	Functions
	Exercise 3-3
	John Woods
*/

#include <cmath>
#include <iostream>

using namespace std;

int to_binary(int input)
{
    int result = 0;

    for(int i = 0; input > 0; i++)
    {
        result = result + ((input % 2) * pow(10, i));

        input = input / 2;
    }

    return result;
}

int main()
{
    cout << "1 in binary:  " << to_binary(1) << endl;
    cout << "2 in binary:  " << to_binary(2) << endl;
    cout << "3 in binary:  " << to_binary(3) << endl;
    cout << "4 in binary:  " << to_binary(4) << endl;
    cout << "5 in binary:  " << to_binary(5) << endl;
    cout << "6 in binary:  " << to_binary(6) << endl;
    cout << "7 in binary:  " << to_binary(7) << endl;
    cout << "8 in binary:  " << to_binary(8) << endl;
    cout << "9 in binary:  " << to_binary(9) << endl;
    cout << endl;

    return 0;
}

//End of Program
