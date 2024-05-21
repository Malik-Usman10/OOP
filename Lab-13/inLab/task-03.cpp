#include <iostream> 
#include <fstream>

class Student
{
private:
    string name;
    int ID;
    float GPA;
    vector<string> listOfCourses;
public:
    Student(){}
    Student(name n, int Id, float gpa) : name(n), ID(Id), GPA(gpa) {}

    void setName(string n)
    {
        Name = n;
    }
    string getName()
    {
        return Name;
    }
    void setID(int Id)
    {
        ID = id;
    }
    int getID()
    {
        return ID;
    }
    void setGPA(float gpa)
    {
        GPA = gpa;
    }
    float getGPA()
    {
        return GPA;
    }

    void setStudentData(string name, int ID, float GPA, vector<string>& listOfCourses)
    {
        cin >> setName(name);
        cin >> setID(ID);
        cin >> setGPA(GPA); 
    }
    void printStudentData()
    {
        cout << getName() << endl;
        cout << getID() << endl;
        cout << getGPA() << endl;

    }
    void writeToFile(ofstream& file)
    {
        file studentRecord("studentRecord.txt");
        studentRecord << getName() <<"," << getID() << "," << getGPA() << "," << course 
    }
    void readFromFile(ifstream& file)
    {

    }
    
};

int main()
{
    vector<Student> studentRecord;

    ofstream record("studentRecord.txt");


}


























