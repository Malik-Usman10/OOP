#include <iostream>
#include <ostream>
#include <vector>

using namespace std;

class Date{
private:
    int day;
    int month;
    int year;
public:
    Date() : day(1), month(1), year(2000) {}
    Date(int day, int month, int year) : day(day), month(month), year(year) {}
    Date(const Date& copy) : day(copy.day), month(copy.month), year(copy.year) {}

    ~Date() {}

    void Display () const 
    {
        cout << day << " - " << month << " - " << year << endl;
    }

Date operator+(const Date& copy) const 
    {
        Date dateAdd;
        dateAdd.day = day + copy.day;
        dateAdd.month = month + copy.month;
        dateAdd.year = year + copy.year;
        if (dateAdd.day > 30) 
        {
            dateAdd.day -= 30;
            dateAdd.month++;
        }
        if (dateAdd.month > 12 ) 
        {
            dateAdd.month -= 12;
            dateAdd.year++;
        }
        return dateAdd;
    }

    Date operator-(const Date& copy) const 
    {
        Date dateSub;
        dateSub.day = day - copy.day;
        dateSub.month = month - copy.month;
        dateSub.year = year - copy.year;
        if (dateSub.day < 0) 
        {
            dateSub.day +=30;
            dateSub.month--;
        }
        if (dateSub.month < 0) 
        {
            dateSub.month += 12;
            dateSub.year--;
        }
        if (dateSub.year < 0) 
        {
            dateSub.year -= dateSub.year;
        }
        return dateSub;
    }

    friend ostream& operator<<(ostream& os, const Date& date) 
    {
        os << date.day << "-" << date.month << "-" << date.year;
        return os;
    }

    friend istream& operator>>(istream& is, Date& date) 
    {
        is >> date.day >> date.month >> date.year;
        return is;
    }


};
class Dept
{
private:
    int deptId;
    char *dname;
    char *location;

public:
    Dept() : deptId(0), dname(), location(){}
    Dept(int deptId, char* dname, char* location) : deptId(deptId++), dname(dname), location(location){}


    void Display () const 
    {
        cout << deptId << "\nDepartment Name" << dname << "\nLocation" << location << endl;
    }

    friend ostream& operator<<(ostream& os, const Dept& dept)
    {
        os << dept.deptId << "Department Name" << dept.dname << "\n Location" << dept.location << endl;
        return os;
    }
    friend istream& operator>>(istream& is, const Dept& dept)
    {
        is >> dept.dname >> dept.location;
        return is;
    }

};

class Employee
{
private:
    int empId;
    char* eName;
    Date date;
    int salaray;
    Dept id;
    int workingHours;
public:
    Employee() : empId(0), eName(), salaray(0), workingHours(0) {}
    Employee(int empId, char* eName, const Date& d, int salaray, const Dept& deptID, int workingHours): empId(empId), eName(eName), date(d), salaray(salaray), id(deptID), workingHours(workingHours) {}
    Employee(const Employee& copy) : empId(copy.empId), eName(copy.eName), date(copy.date), salaray(copy.salaray), id(copy.id), workingHours(copy.workingHours){}
    ~Employee() {}
    
    void Display() const 
    {
         cout << empId << "Employee Name" << eName << "\n Hire Date" << date <<"Salary" << salaray << "Departmet ID" << id << "working Housr" << workingHours << endl;
    }
        friend ostream& operator<<(ostream& os, const Employee& e)
    {
        os << e.empId << "Employee Name" << e.eName << "\n Hire Date" << e.date <<"Salary" << e.salaray << "Departmet ID" << e.id << "working Housr" << e.workingHours << endl;
        return os;
    }
    friend istream& operator>>(istream& is, const Employee& e)
    {
        is >> e.eName >> e.salaray >> e.workingHours;
        return is;
    }

};

class Firm
{
private:
    char* firmName;
    int numberOfEmployees;
    vector<int>employee;
public:
    Firm() : firmName(), numberOfEmployees(0) {}
    Firm(char *name, int numberOfEmployees) : firmName(name), numberOfEmployees(numberOfEmployees){}
    Firm(const Firm& copy) : firmName(copy.firmName), numberOfEmployees(copy.numberOfEmployees) {}
    ~Firm() {}

    void Display() const
    {
        cout << firmName << numberOfEmployees << endl;
    }

    int addEmployeeToFirm()
    {

    }
    int removeEmployee()
    {

    }
    int updateData()
    {

    }
    int employeeSorting()
    {

    }
    int employeeWithHighestSalary()
    {

    }
};

int main()
{
    int i;
    do 
    {
        cout << "\n1 : Add An Employee: ";
        cout << "\t2 : Remove An Employee: \n";
        cout << "3: Update Data Of an Employee\t";
        cout << "4: Sort All the Employees on their Working Hours\n";
        cout << "\t5: Employee With the highest Salary";
        cout <<"\n Choose the function you want to perform: ";
        cin >> i;
        switch (i) 
        {
            case 1:
            {

            }
        }

    }
    while (i != 5);    
}