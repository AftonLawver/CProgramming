#include <iostream>
using namespace std;

class AbstractEmployee {
    virtual void askForPromotion() = 0;
};

class Employee: AbstractEmployee {
    // Attributes
private:

    string company;
    int age;

protected:
    string name;

public:
    void setName(string nameOfPerson) {
        name = nameOfPerson;
    }

    string getName() {
        return name;
    }

    void setCompany(string companyWorkedFor) {
        company = companyWorkedFor;
    }

    string getCompany() {
        return company;
    }

    void setAge(int ageOfPerson) {
        age = ageOfPerson;
    }

    int getAge() {
        return age;
    }

    void introduceYourself() {
        cout << "Hi, my name is " << name << "." << endl;
        cout << "I am " << age << " years old." << endl;
        cout << "I work for " << company << "." << endl;
    }

    Employee(string nameOfPerson, string companyWorkedFor, int ageOfPerson) {
        name = nameOfPerson;
        company = companyWorkedFor;
        age = ageOfPerson;
    }
    void askForPromotion() {
        if (age > 30) {
            cout << name << " got promoted! " << endl;
        }
        else {
            cout << name << ", sorry no promotion for you!" << endl;
        }
    }


};

class Developer: public Employee {
public:
    string favoriteProgrammingLanguage;

    Developer(string nameOfPerson, string companyWorkedFor, int ageOfPerson, string language)
    : Employee(nameOfPerson, companyWorkedFor, ageOfPerson)
    {
        favoriteProgrammingLanguage = language;
    }
    void fixBug() {
        cout << name << " fixed bug using " << favoriteProgrammingLanguage << endl;
    }
};

class Teacher: public Employee {
public:
    string subject;
    void prepareLesson() {
        cout << name << " is preparing " << subject << " lesson" << endl;
    }

    Teacher(string nameOfPerson, string companyWorkedFor, int ageOfPerson, string subjectTaught)
        :Employee(nameOfPerson, companyWorkedFor, ageOfPerson) {
        subject = subjectTaught;
    }
};

int main() {
    Developer d = Developer("Afton", "SIUC", 27, "C++");

    Teacher t = Teacher("Jack", "Cool School", 35, "Geography");
    t.prepareLesson();
    t.askForPromotion();
    return 0;
}
