#include <iostream>
#include <string>
using namespace std;
class Student 
{
protected:
    string name;
    string department;
public:
    virtual ~Student() {}
    virtual void get_data() = 0;
    virtual void show_data() = 0;
};
class Medical : public Student 
{
public:
    void get_data() override 
    {
        cout << "Enter name of Medical student: ";
        getline(cin, name);
        department = "Medical";
    }
    void show_data() override 
    {
        cout << "Medical Student Name: " << name << ", Department: " << department << endl;
    }
};
class Engineering : public Student 
{
public:
    void get_data() override 
    {
        cout << "Enter name of Engineering student: ";
        getline(cin, name);
        department = "Engineering";
    }
    void show_data() override 
    {
        cout << "Engineering Student Name: " << name << ", Department: " << department << endl;
    }
};
class Science : public Student 
{
public:
    void get_data() override 
    {
        cout << "Enter name of Science student: ";
        getline(cin, name);
        department = "Science";
    }
    void show_data() override 
    {
        cout << "Science Student Name: " << name << ", Department: " << department << endl;
    }
};
int main() 
{
    Student* students[3];
    students[0] = new Medical();
    students[1] = new Engineering();
    students[2] = new Science();
    for (int i = 0; i < 3; i++) {
        students[i]->get_data();
    }
    for (int i = 0; i < 3; i++) {
        students[i]->show_data();
    }
    for (int i = 0; i < 3; i++) {
        delete students[i];
    }
}