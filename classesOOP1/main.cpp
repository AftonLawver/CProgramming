#include <iostream>
#include <vector>

using namespace std;

class Person {

private:
    string name;
    int age;

public:
    Person(string name, int age) {
        this->name = name;
        this->age = age;
    }


    string getName() {
        return name;
    }

    int getAge() {
        return age;
    }

    void setName(string nameOfPerson) {
        name = nameOfPerson;
    }

    void setAge(int ageOfPerson) {
        age = ageOfPerson;
    }

    virtual void printPersonData() {
        cout << "Person name: " << getName() << endl;
        cout << "Person age: " << getAge() << endl;
    }
};

class Student : public Person {
private:
    string level;

public:
    Student(string name, int age, string level) : Person(name, age) {
        this->level = level;
    }

    string getLevel() {
        return level;
    }

    void setLevel(string levelOfPerson) {
        level = levelOfPerson;
    }

    void printPersonData() {
        cout << "Student name: " << getName() << endl;
        cout << "Student age: " << getAge() << endl;
        cout << "Student level: " << getLevel() << endl;
    }

};

class Teacher : public Person {
private:
    int salary;
    string course;

public:
    Teacher(string name, int age, int salary, string course) : Person(name, age) {
        this->salary = salary;
        this->course = course;
    }

    int getSalary() {
        return salary;
    }

    string getCourse() {
        return course;
    }

    void setSalary(int salary) {
        this->salary = salary;
    }

    void setCourse(int course) {
        this->course = course;
    }

    void printPersonData() {
        cout << "Teacher name: " << getName() << endl;
        cout << "Teacher age: " << getAge() << endl;
        cout << "Teacher salary: " << salary << endl;
        cout << "Teacher course: " << course << endl;
    }
};

class StaffMember : public Person {
private:
    string title;

public:
    StaffMember(string name, int age, string title) : Person(name, age) {
        this-> title = title;
    }

    string getTitle() {
        return title;
    }

    void setTitle(string title) {
        this->title = title;
    }

    void printPersonData() {
        cout << "Staff name: " << getName() << endl;
        cout << "Staff age: " << getAge() << endl;
        cout << "Staff title: " << title << endl;
    }
};






int main() {
    string name;
    int age;
    string level;
    int salary;
    string course;
    string title;
    int count = 0;
    string typeOfPerson;
    string addAnotherPerson = "Yes";

//     dynamically allocate buffer for 10 Person objects.
    vector<Person*> myPersonVector;


    while (addAnotherPerson == "Yes" || addAnotherPerson == "yes" && count < 10) {
        try {
            cout << "What type of Person would you like to add?" << endl;
            cout << "(Enter Student, Teacher, or Staff):";
            cin >> typeOfPerson;
            if (typeOfPerson != "Teacher" && typeOfPerson != "teacher"
            && typeOfPerson != "Student" && typeOfPerson != "student"
            && typeOfPerson != "Staff" && typeOfPerson != "staff") {
                throw 50;
            }
        }
        catch (int x) {
            cout << "Invalid type of person. Please try again. ERROR NUMBER:" << x << endl;
            return 1;
        }
        if (typeOfPerson == "Student" || typeOfPerson == "student") {
            cout << "Enter the student's name:";
            cin.ignore();
            getline(cin, name);
            try {
                cout << "Enter the student's age:";
                cin >> age;
                if (age < 18 || age > 60) {
                    throw 99;
                }
            }catch (int x) {
                cout << "Age must be between 18 and 60. ERROR NUMBER:" << x << endl;
                return 1;
            }


            try {
                cout << "Enter the student's level (undergraduate or graduate):";
                cin >> level;
                if (level != "undergraduate" && level != "Undergraduate" && level !=
                "Graduate" && level != "graduate") {
                    throw 100;
                }
            }catch (int x) {
                cout << "Student's level must be either undergraduate or graduate. ERROR NUMBER:" << x << endl;
                return 1;
            }
            Student *student = new Student(name, age, level);

            myPersonVector.push_back(student);
            count++;

            cout << "Would you like to add another Person? (Enter Yes or No)" << endl;
            cin >> addAnotherPerson;
        }
        else if (typeOfPerson == "Teacher" || typeOfPerson == "teacher") {
            cout << "Enter the teacher's name:";
            cin.ignore();
            getline(cin,name);
            cout << "Enter the teacher's age:";
            cin >> age;
            cout << "Enter the teacher's salary:";
            cin >> salary;
            cout << "Enter the teacher's course:";
            cin.ignore();
            getline(cin, course);

            Teacher *teacher = new Teacher(name, age, salary, course);

            myPersonVector.push_back(teacher);
            count++;

            cout << "Would you like to add another Person? (Enter Yes or No)" << endl;
            cin >> addAnotherPerson;
            continue;
        }
        else if (typeOfPerson == "Staff" || typeOfPerson == "staff") {
            cout << "Enter the staff member's name:";
            cin.ignore();
            getline(cin, name);
            cout << "Enter the staff member's age:";
            cin >> age;
            cout << "Enter the staff member's title:";
            cin.ignore();
            getline(cin, title);

            StaffMember *staffMember = new StaffMember(name, age, title);
            myPersonVector.push_back(staffMember);
            count++;
            cout << "Would you like to add another Person? (Enter Yes or No)" << endl;
            cin >> addAnotherPerson;
        }
        else {
            cout << "Type of person is invalid." << endl;
            break;
        }
    }
    for (int i = 0; i < count; i++) {
        cout << "Person #" << i+1 << endl;
        cout << "-------------" << endl;
        myPersonVector[i]->printPersonData();
        cout << endl;
    }
    return 0;
}
