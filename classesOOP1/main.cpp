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

    virtual string getType() {
    }
};

class Student : public Person {
private:
    string level;
    string type;

public:
    Student(string name, int age, string level) : Person(name, age) {
        this->level = level;
        this->type = "Student";
    }

    string getLevel() {
        return level;
    }

    string getType() {
        return type;
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
    string type;

public:
    Teacher(string name, int age, int salary, string course) : Person(name, age) {
        this->salary = salary;
        this->course = course;
        this->type = "Teacher";
    }

    int getSalary() {
        return salary;
    }

    string getCourse() {
        return course;
    }

    string getType() {
        return type;
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
    string type;

public:
    StaffMember(string name, int age, string title) : Person(name, age) {
        this-> title = title;
        this->type = "Staff Member";
    }

    string getTitle() {
        return title;
    }
    string getType() {
        return type;
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

string addAPerson(int count) {
    string addAPerson = "";
    do {
        if (count >= 1) {
            cout << "Would you like to add another person? (Type yes or no): " << endl;
            cin >> addAPerson;
        }
        else {
            cout << "Would you like to add a person? (Enter yes or no): " << endl;
            cin >> addAPerson;
        }
    }
    while (addAPerson != "No" && addAPerson != "no" && addAPerson != "Yes" && addAPerson != "yes");
    return addAPerson;
}

int main() {
    string name;
    int age;
    string level;
    int salary;
    string course;
    string title;
    int count = 0;
    string typeOfPerson;
    string addAnotherPerson = addAPerson(count);

    vector<Person*> myPersonVector;

    while (addAnotherPerson == "Yes" || addAnotherPerson == "yes") {
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
            addAnotherPerson = addAPerson(count);
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
            addAnotherPerson = addAPerson(count);
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
            addAnotherPerson = addAPerson(count);
        }
        else {
            cout << "Type of person is invalid." << endl;
            break;
        }
    }
    for (int i = 0; i < count; i++) {
        cout << "Person #" << i+1 << ": " << myPersonVector[i]->getType() << endl;
        cout << "-------------" << endl;
        myPersonVector[i]->printPersonData();
        cout << endl;
    }
    return 0;
}
