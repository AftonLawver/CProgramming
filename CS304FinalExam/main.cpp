#include <iostream>

using namespace std;

class c_string_wrapper {
private:
    char my_string[100];

public:

     char* get_string() {
        return my_string;
    }

    void set_string(char *c_string) {
        int index = 0;
        while(c_string[index] != '\0') {
            my_string[index] = c_string[index];
            index++;
        }
     }

     int get_length() {
         int index = 0;
         while(my_string[index] != '\0') {
             index++;
         }
         return index;
     }
};

int main() {
    c_string_wrapper c;
    char name[10] = {'A', 'f', 't', 'o', 'n'};
    c.set_string(name);
    char *result = c.get_string();
    int index = 0;
    while(*result != '\0') {
        cout << *result << endl;
        result++;
    }
    int length = c.get_length();
    cout << "Length of string is: " << length << endl;

    return 0;
}
