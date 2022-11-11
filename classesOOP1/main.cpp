#include <iostream>
using namespace std;


class Student {

private:
    string name;
    int age;
    string level;

public:
    string getName() {
        return name;
    }

    int getAge() {
        return age;
    }

    string getLevel() {
        return level;
    }

    void setName(string nameOfPerson) {
        name = nameOfPerson;
    }

    void setAge(int ageOfPerson) {
        age = ageOfPerson;
    }

    void setLevel(string levelOfPerson) {
        level = levelOfPerson;
    }

    void printStudentData() {
        cout << "Student name: " << name << endl;
        cout << "Student age: " << age << endl;
        cout << "Student level: " << level << endl;
    }

};

int main() {
    string name;
    int age;
    string level;
    int count = 0;
    string addAnotherStudent = "Yes";

    // dynamically allocate buffer for 10 Student objects.
    Student *studentList;
    studentList = new Student[10];



    while (addAnotherStudent == "Yes" && count < 10) {
        Student student;
        cout << "Enter the student's name:";
        cin >> name;
        studentList[count].setName(name);

        cout << "Enter the student's age:";
        cin >> age;
        studentList[count].setAge(age);

        cout << "Enter the student's level:";
        cin >> level;
        studentList[count].setLevel(level);
        count++;

        cout << "Would you like to add another student? (Enter Yes or No)" << endl;
        cin >> addAnotherStudent;
    }
    for (int i = 0; i < count; i++) {
        cout << "Student #" << i+1 << endl;
        cout << "-------------" << endl;
        studentList[i].printStudentData();
        cout << endl;
    }
    return 0;
}
