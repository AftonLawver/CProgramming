#include <iostream>
#include <fstream>

using namespace std;

int splitEmployees(int n, string s[]) {
    int unfocusedEmployees = 0;
    string s1[n];
    bool isInFirstArray;
    string s2[n];
    bool isInSecondArray;
    for (int i=0; i < n-1; i++) {
        int j;
        for (j=0; j < n-1; j++) {
            if (s[i][0] == s1[j][0]){
                isInFirstArray = true;
                break;
            }
            else {
                isInFirstArray = false;
            }
            if (s[i][0] == s2[j][0]) {
                isInSecondArray = true;
                break;
            }
            else {
                isInSecondArray = false;
            }
        }
        if (isInFirstArray && isInSecondArray) {
            // add to second array
            // increment the number of unfocused workers
            s2[j+1] = s[i];
            unfocusedEmployees ++;
        }
        else if (isInFirstArray) {
            s2[j+1] = s[i];
        }
        else if (isInSecondArray) {
            s1[j+1] = s[i];
        }
        else {
            s1[j] = s[i];
        }
    }
    return unfocusedEmployees;
}

int main() {
    string names[7] = {"paras",  "priyanshu", "pratik", "manan", "eesha", "aayush", "akshay"};
    int result = splitEmployees(7, names);
    cout << "Result is: " << result;
