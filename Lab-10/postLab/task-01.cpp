#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Person 
{
private:
    string name;
    int id;
public:
    void setName(string name) 
    {
        this->name = name;
    }
    string getName() const
    {
        return name;
    }
    void setId(int id) 
    {
        this->id = id;
    }
    int getId() const 
    {
        return id;
    }
};

class Teacher : public Person 
{
private:
    string department;
    int teacherId;
    int coursesTaught;
public:
    void setDepartment(string department) 
    {
        this->department = department;
    }
    string getDepartment() const 
    {
        return department;
    }
    void setTeacherId(int teacherId) 
    {
        this->teacherId = teacherId;
    }
    int getTeacherId() const 
    {
        return teacherId;
    }
    void increaseCoursesTaught() 
    {
        coursesTaught++;
    }
    void decreaseCoursesTaught()
    {
        coursesTaught--;
    }
};

class Course 
{
private:
    string name;
    int id;
    int capacity;
    Teacher teacher;
    int creditHours;
public:
    void setName(string name) 
    {
        this->name = name;
    }
    string getName() const 
    {
        return name;
    }
    void setId(int id) 
    {
        this->id = id;
    }
    int getId() const 
    {
        return id;
    }
    void setCapacity(int capacity) 
    {
        this->capacity = capacity;
    }
    int getCapacity() const 
    {
        return capacity;
    }
    void setTeacher(Teacher teacher) 
    {
        this->teacher = teacher;
    }
    Teacher getTeacher() const 
    {
        return teacher;
    }
    void setCreditHours(int creditHours) 
    {
        this->creditHours = creditHours;
    }
    int getCreditHours() const
    {
        return creditHours;
    }
};

class Student : public Person 
{
private:
    vector<Course> courses;
public:
    void addCourse(const Course& course) 
    {
        courses.push_back(course);
    }
    bool dropCourse(int courseId) 
    {
        auto it = find_if(courses.begin(), courses.end(), [courseId](const Course& c) 
        {
            return c.getId() == courseId;
        });
        if (it != courses.end()) 
        {
            courses.erase(it);
            return true;
        }
        else 
        {
            cout << "Error: Course not found" << endl;
            return false;
        }
    }
    const vector<Course>& getCourses() const 
    {
        return courses;
    }
    void updateCourseInfo(int courseId, string newName, int newCapacity, Teacher newTeacher, int newCreditHours) 
    {
        auto it = find_if(courses.begin(), courses.end(), [courseId](const Course& c) 
        {
            return c.getId() == courseId;
        });
        if (it != courses.end()) 
        {
            it->setName(newName);
            it->setCapacity(newCapacity);
            it->setTeacher(newTeacher);
            it->setCreditHours(newCreditHours);
        } 
        else 
        {
            cout << "Error: Course not found" << endl;
        }
    }
};

class University 
{
private:
    vector<Student> students;
    vector<Teacher> teachers;
    vector<Course> courses;
public:
    Student createStudent(string name) 
    {
        Student student;
        student.setName(name);
        student.setId(students.size() + 1);
        students.push_back(student);
        return student;
    }
    Teacher createTeacher(string name, string department) 
    {
        Teacher teacher;
        teacher.setName(name);
        teacher.setDepartment(department);
        teacher.setTeacherId(teachers.size() + 1);
        teachers.push_back(teacher);
        return teacher;
    }
    Course createCourse(string name, int capacity, Teacher teacher, int creditHours) 
    {
        Course course;
        course.setName(name);
        course.setCapacity(capacity);
        course.setTeacher(teacher);
        course.setCreditHours(creditHours);
        course.setId(courses.size() + 1);
        courses.push_back(course);
        return course;
    }
    void enrollStudent(int studentId, int courseId) 
    {
        auto studentID = find_if(students.begin(), students.end(), [studentId](const Student& s) 
        {
            return s.getId() == studentId;
        });
        auto courseID = find_if(courses.begin(), courses.end(), [courseId](const Course& c) 
        {
            return c.getId() == courseId;
        });
        if (studentID != students.end() && courseID != courses.end()) 
        {
            if (courseID->getCapacity() > static_cast<int>(studentID->getCourses().size())) 
            {
                studentID->addCourse(*courseID);
                cout << "Enrolled successfully!" << endl;
            } 
            else 
            {
                cout << "Error: Course is full" << endl;
            }
        } 
        else 
        {
            cout << "Error: Student or Course not found" << endl;
        }
    }
    bool dropStudent(int studentId, int courseId) 
    {
        auto studentID = find_if(students.begin(), students.end(), [studentId](const Student& s) 
        {
            return s.getId() == studentId;
        });
        auto courseID = find_if(courses.begin(), courses.end(), [courseId](const Course& c) 
        {
            return c.getId() == courseId;
        });
        if (studentID != students.end() && courseID != courses.end()) 
        {
            if (studentID->dropCourse(courseId)) 
            {
                cout << "Student dropped successfully!" << endl;
                return true;
            } 
            else 
            {
                cout << "Error: Student is not enrolled in this course" << endl;
                return false;
            }
        } 
        else 
        {
            cout << "Error: Student or Course not found" << endl;
            return false;
        }
    }
    void displayEnrolledCourses(int studentId) 
    {
        auto studentID = find_if(students.begin(), students.end(), [studentId](const Student& s) 
        {
            return s.getId() == studentId;
        });
        if (studentID != students.end()) 
        {
            cout << "Courses enrolled by student " << studentId << ":" << endl;
            const vector<Course>& studentCourses = studentID->getCourses();
            for (const Course& course : studentCourses) 
            {
                cout << course.getName() << endl;
            }
        } 
        else 
        {
            cout << "Error: Student not found" << endl;
        }
    }
};

int main() 
{
    University uni;
    Student student;
    Teacher teacher;
    Course course;
     while (true) {
        int choice;
        cout << "\n==================================================================\n";
        cout << "1. Create a new student\n";
        cout << "2. Create a new course\n";
        cout << "3. Enroll a student in a course\n";
        cout << "4. Drop a student from a course\n";
        cout << "5. Display all courses a student is enrolled in\n";
        cout << "6. Quit\n";
        cout << "===================================================================\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) 
        {
            case 1:
            {
                string studentName;
                cout << "Enter student name: ";
                cin.ignore();
                getline(cin, studentName);
                uni.createStudent(studentName);
                break;
            }
            case 2:
            {
                string courseName, teacherName;
                int courseCapacity, creditHours;
                cout << "Enter course name: ";
                cin.ignore();
                getline(cin, courseName);
                cout << "Enter course capacity: ";
                cin >> courseCapacity;
                cout << "Enter the Name of Teacher For this Course: " ;
                cin.ignore();
                getline(cin,teacherName);
                cout << "Enter the credit Hours of this Course: ";
                cin >> creditHours;
                uni.createCourse(courseName, courseCapacity, teacher, creditHours);
                break;
            }
            case 3:
            {
                int studentId, courseId;
                cout << "Enter student ID: ";
                cin >> studentId;
                cout << "Enter course ID: ";
                cin >> courseId;
                uni.enrollStudent(studentId, courseId);
                break;
            }
            case 4:
            {
                int studentId, courseId;
                cout << "Enter student ID: ";
                cin>> studentId;
                cout << "Enter course ID: ";
                cin >> courseId;
                uni.dropStudent(studentId, courseId);
                break;
            }
            case 5:
                int studentId;
                cout << "Enter student ID: ";
                cin >> studentId;
                uni.displayEnrolledCourses(studentId);
                break;
            case 6:
                return 0;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }
}
