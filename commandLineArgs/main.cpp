#include <iostream>
using namespace std;

// argc is argument count --> it stores the number of command line arguments
// the user passes in along with the name of the function

// argv is argument vector --> array of character pointers that hold the actual arguments
// argv[0] is the name of the program.

int main(int argc, char** argv) {
    cout << "You have entered " << argc << " arguments" << endl;

    for (int i=0; i < argc; ++i) {
        cout << argv[i] << endl;
    }
    return 0;
}
