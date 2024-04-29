#include <iostream>

using namespace std;

class Student {
private:
    int subjects;
    int* marks;

public:
    Student(int numSubjects) : subjects(numSubjects) 
    {
        marks = new int[subjects];
    }

    Student(const Student& cp) : subjects(cp.subjects) 
    {
        marks = new int[subjects];
        for (int i = 0; i < subjects; i++) 
        {
            marks[i] = cp.marks[i];
        }
    }

    ~Student() {
        delete[] marks;
    }

    int getSubjects() const 
    {
        return subjects;
    }

    void setSubjects(int numSubjects) 
    {
        subjects = numSubjects;
    }

    int getMarks(int subjectIndex) const 
    {
        return marks[subjectIndex];
    }

    void setMarks(int subjectIndex, int mark) 
    {
        marks[subjectIndex] = mark;
    }

    void inputMarks() 
    {
        cout << "Enter marks for each subject:\n";
        for (int i = 0; i < subjects; i++) 
        {
            cout << "Subject " << i + 1 << ": ";
            cin >> marks[i];
        }
    }

    void outputMarks() const
     {
        cout << "Marks:\n";
        for (int i = 0; i < subjects; i++) 
        {
            cout << "Subject " << i + 1 << ": " << marks[i] << endl;
        }
    }
};

int main() 
{
    int numSubjects;
    cout << "Enter the number of subjects: ";
    cin >> numSubjects;

    Student student(numSubjects);

    student.inputMarks();

    student.outputMarks();

    Student studentCopy = student;

    cout << "\nCopy of Studnet marks:\n";
    studentCopy.outputMarks();
}
