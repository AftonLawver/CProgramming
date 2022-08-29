#include <iostream>
using namespace std;


class Employee {
    // Attributes
public:
    string name;
    string company;
    int age;

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
};

int main() {
    Employee employee1("Afton", "Southern Illinois University - Carbondale", 27);

    employee1.introduceYourself();

    return 0;
}
