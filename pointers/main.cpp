#include <iostream>

using namespace std;

void getNumber(int *value);
void doubleValue(int *value);

int main() {
    // showing the size and address of a variable
//    int x;
//    x = 25;
//    cout << "Size of x is: " << sizeof(x) << " bytes" << endl;
//    cout << "Address of x is: " << &x << endl;

    // using a pointer to get the address of a variable
//    int y = 17;
//    int *ptr = nullptr;
//    ptr = &y;
//    cout << "This is the address of y: " << ptr << endl;
//    cout << "This is the value of y: " << y << endl;

    // showing that we can change the value of a variable by using the pointer variable
//    int z = 25;
//    int *ptr = nullptr;
//    ptr = &z;   // pointer variable ptr points to the int variable z
//    cout << "This is the value of z before change: \n";
//    cout << z << endl;
//    cout << *ptr << endl;
//
//    *ptr = 50;
//    cout << "This is the value of z after change: \n";
//    cout << z << endl;
//    cout << *ptr << endl;

    // showing that we can use a pointer variable to point to different variables
//    int x = 25, y =50, z = 75;
//    int *ptr = nullptr;
//
//    cout << "Values before: " << endl;
//    cout << "x: " << x << endl;
//    cout << "y: " << y << endl;
//    cout << "z: " << z << endl;
//
//    ptr = &x;
//    *ptr += 100;
//
//    ptr = &y;
//    *ptr += 100;
//
//    ptr = &z;
//    *ptr += 100;
//
//    cout << "Values before: " << endl;
//    cout << "x: " << x << endl;
//    cout << "y: " << y << endl;
//    cout << "z: " << z << endl;

    // Get the first element of an array by using the indirection operator
//    int numbers[] = {10,20,30,40,50};
//    cout << *numbers << endl;

    // Have user input 5 numbers into an array
    // Get all elements in an array only using a pointer to the array
//    const int SIZE = 5;
//    int numbers[SIZE];
//    int count;
//
//    // take user input
//    cout << "Enter 5 numbers: " << endl;
//    for (count = 0; count < SIZE; count++)
//        cin >> * (numbers + count);
//
//    for (count=0; count < SIZE; count++)
//        cout << "The value of element " << count << " is: " << *(numbers + count) << "\n";


// can also print all values in an array by using subscript notation with the pointer
//    const int SIZE = 3;
//    int numbers[SIZE] = {3,4,5};
//    int *ptr;
//    ptr = numbers; // array names can be used as pointers, so dont need &.
//    int count;
//
//    cout << "The numbers in the array are: \n";
//    for(count = 0; count < SIZE; count++) {
//        cout << numbers[count] << endl;
//    }

// We can increment (or decrement) a pointer variable so that it
// shows us all of the elements in an array

//const int SIZE = 5;
//int nums[SIZE] = {1,2,3,4,5};
//int *numPtr = nullptr;
//numPtr = nums;
//int count = 0;
//
//for(count; count<SIZE; count++) {
//    cout << *numPtr << endl;
//    *numPtr ++;
//}


// use a pointer as an argument in some functions, manipulate that
// value it points to

    int number;
    getNumber(&number);
    cout << "Number is: " << number << endl;
    doubleValue(&number);
    cout << "That number doubled is: " << number << endl;

    return 0;
}

void getNumber(int *value) {
   cout << "Type a number: " << endl;
   cin >> *value;
}

void doubleValue(int *value) {
    *value *=2;
}
