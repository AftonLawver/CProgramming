#include <iostream>
#include <unistd.h>
#include <vector>


using namespace std;

int multiplyNumbers(int *value1, int *value2, int *value3);
void doubleValue(int *value);
int findMaxInArray(int myArray[], int size);
int findMaxInVector(vector<int> *myVector);
void printArray(int myArray[], int size);
int numberOfA(char *charArray);

int main() {

// To test out the numberOfA function
//    char myCharArray[6] = {'H','a','n','n','a','h'};
//    int result = numberOfA(myCharArray);
//    cout << result << endl;

//    int myNumbers[5] = {10,20,45,15, 19};
//    printArray(myNumbers, 5);

    // for findMaxInVector function
//    vector <int> myVector = {5,9,15,41,12,72};
//    vector<int> *p = &myVector;
//    int result = findMaxInVector(p);
//    cout << result << endl;

// for findMaxInArray function
//    int myNumbers[5] = {10,20,45,15, 19};
//    int result = findMaxInArray(myNumbers, 4);
//    cout << result << endl;

//    int x=5, y=3, z=4;
//    int *ptr1 = &x;
//    int *ptr2 = &y;
//    int *ptr3 = &z;
//
//    int result = multiplyNumbers(ptr1, ptr2, ptr3);
//    cout << result << endl;

//    int x, y, z;
//    int *pointerX = &x;
//    int *pointerY = &y;
//    int *pointerZ = &z;
//
//    cout << "Enter a number: " << endl;
//    cin >> *pointerX;
//
//    cout << "Enter a number: " << endl;
//    cin >> *pointerY;
//
//    cout << "Original value of x: " << *pointerX << endl;
//    cout << "Original value of Y: " << *pointerY << endl;
//
//    cout << "Swapping values.";
//    sleep(1);
//    cout << ".";
//    sleep(1);
//    cout << ".";
//    sleep(1);
//    cout << "." << endl;
//
//    *pointerZ = *pointerX;
//    *pointerX = *pointerY;
//    *pointerY = *pointerZ;
//    cout << "New value of x: " << *pointerX << endl;
//    cout << "New value of y: " << *pointerY << endl;

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
// shows us all the elements in an array

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

//    int number;
//    getNumber(&number);
//    cout << "Number is: " << number << endl;
//    doubleValue(&number);
//    cout << "That number doubled is: " << number << endl;

    return 0;
}

int multiplyNumbers(int *value1, int *value2, int *value3) {
   return *value1 * *value2 * *value3;
}

int findMaxInArray(int myArray[], int size) {
    int max = myArray[0];
    for (int i = 0; i < size; i++) {
        if (myArray[i] > max) {
            max = myArray[i];
        }
    }
    return max;
}

int findMaxInVector(vector<int> *myVector) {
    int max = myVector->at(0);
    for (int i = 0; i < myVector->size(); i++) {
        if (myVector->at(i) > max) {
            max = myVector->at(i);
        }
    }
    return max;
}


void printArray(int myArray[], int size) {
    for (int i = 0; i < size; i++) {
        cout << *(myArray + i) << endl;
    }
}

int numberOfA(char *charArray) {
    int i = 0;
    int count = 0;
    while (*(charArray + i) != NULL) {
        if (*(charArray + i) == 'A' || *(charArray + i) == 'a') {
            count ++;
        }
        i++;
    }
    return count;
}

void doubleValue(int *value) {
    *value *=2;
}
