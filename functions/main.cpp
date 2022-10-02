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

#include <cmath> // import cmath for use of pow() function
#include <iostream>

using namespace std; // use the std namespace so we can use functions from it like cout and cin

int to_binary(int input) // function called to_binary that takes in an integer and also returns and integer
{
    int result = 0; // initialize a integer variable called result and set it to 0

    for(int i = 0; input > 0; i++)  // everytime input is greater than 0, we go through the for loop
                                    // and increment i each time.
    {
        result = result + ((input % 2) * pow(10, i));   // we set the value of result to the previous result
                                                            // and add the input modulo 2 multiplied by 10 to the power
                                                            // of i. This gives us a binary number (either 1 or 0)
                                                            // multiplied by 10 to the power of some value.

        input = input / 2;              // divide the current input by 2 to see if input equals 0.
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
