#include <iostream>
#include <string>

using namespace std;

class Person {
private:
    string name;
    int age;
    char gender;

public:
    Person() : name(""), age(0), gender('M') {}

    Person(string name, int age, char gender) : name(name), age(age), gender(gender) {}

    void readPerson() 
    {
        cout << "Enter name, age, and gender in format [Name Age Gender(M/F)]: ";
        cin >> name >> age >> gender;
    }
    void writePerson() const 
    {
        cout << "Name: " << name << ", Age: " << age << ", Gender: " << gender << endl;
    }
};

int main() 
{
    Person person;
    cout << "Enter details for Person 1:\n";
    person.readPerson();

    cout << "\nPerson details:\n";
    person.writePerson();
}
