#include <iostream>
#include <string>
using namespace std;

class Date 
{
private:
    int day;
    int month;
    int year;

public:
    Date(int d, int m, int y) : day(d), month(m), year(y) {}

    int getDay() const 
    {
        return day;
    }

    int getMonth() const 
    {
        return month;
    }
    int getYear() const 
    {
        return year;
    }

    void displayDate() const 
    {
        cout << day << "-" << month << "-" << year;
    }
};

class Member 
{
private:
    int memberId;
    string name;
    char gender;
    Date dateOfBirth;

public:
    Member(int id, string n, char g, Date dob) : memberId(id), name(n), gender(g), dateOfBirth(dob) {}

    void displayMember() const 
    {
        cout << "Member ID: " << memberId << endl;
        cout << "Name: " << name << endl;
        cout << "Gender: " << gender << endl;
        cout << "Date of Birth: ";
        dateOfBirth.displayDate();
        cout << endl;
    }

    int getAge() const 
    {

        int age = 2024 - dateOfBirth.getYear();
        if (dateOfBirth.getMonth()> 3 || (dateOfBirth.getMonth() == 3 && dateOfBirth.getDay() > 10)) {
            age--;
        }
        return age;
    }
};

class Family 
{
private:
    static int nextId;
    int familyId;
    Member** members;
    int numMembers;

public:

    Family() : familyId(nextId++), members(nullptr), numMembers(0) {}

    ~Family() 
    {
        if (members != nullptr) 
        {
            for (int i = 0; i < numMembers; i++) 
            {
                delete members[i];
            }
            delete[] members;
        }
    }

    void displayFamily() const 
    {
        cout << "Family ID: " << familyId << endl;
        cout << "Number of Members: " << numMembers << endl;
        cout << "Members Details:\n";
        for (int i = 0; i < numMembers; i++) 
        {
            cout << "Member " << i + 1 << ":\n";
            members[i]->displayMember();
            cout << endl;
        }
    }

    void addMember(Member* member) 
    {
        Member** temp = new Member*[numMembers + 1];
        for (int i = 0; i < numMembers; i++) 
        {
            temp[i] = members[i];
        }
        temp[numMembers] = member;
        delete[] members;
        members = temp;
        numMembers++;
    }

    void removeMember(int index) 
    {
        if (index >= 0 && index < numMembers) 
        {
            delete members[index];
            for (int i = index; i < numMembers - 1; i++) 
            {
                members[i] = members[i + 1];
            }
            numMembers--;
        }
    }

    void updateMember(int index, Member* updatedMember) 
    {
        if (index >= 0 && index < numMembers)
        {
            delete members[index];
            members[index] = updatedMember;
        }
    }
};

int Family::nextId = 1;

int main() 
{
    Family family;

    int choice;
    do 
    {
        cout << "\nMenu:\n";
        cout << "1. Display whole family\n";
        cout << "2. Add member to family\n";
        cout << "3. Remove a member from family\n";
        cout << "4. Update data of a member\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) 
        {
            case 1:
                family.displayFamily();
                break;
            case 2:
                {
                    int memberId, day, month, year;
                    string name;
                    char gender;
                    cout << "Enter member ID: ";
                    cin >> memberId;
                    cout << "Enter name: ";
                    cin.ignore();
                    getline(cin, name); 
                    cout << "Enter gender (M/F): ";
                    cin >> gender;
                    cout << "Enter date of birth (DD MM YYYY): ";
                    cin >> day >> month >> year;
                    Member* newMember = new Member(memberId, name, gender, Date(day, month, year));
                    family.addMember(newMember);
                    break;
                }
            case 3:
                {
                    int index;
                    cout << "Enter index of member to remove: ";
                    cin >> index;
                    family.removeMember(index - 1);
                    break;
                }
            case 4:
                {
                    int index;
                    cout << "Enter index of member to update: ";
                    cin >> index;
                    int memberId;
                    string name;
                    char gender;
                    int day, month, year;
                    cout << "Enter member ID: ";
                    cin >> memberId;
                    cout << "Enter name: ";
                    cin.ignore();
                    getline(cin, name); 
                    cout << "Enter gender (M/F): ";
                    cin >> gender;
                    cout << "Enter date of birth (DD MM YYYY): ";
                    cin >> day >> month >> year;

                    Member* updatedMember = new Member(memberId, name, gender, Date(day, month, year));
                    family.updateMember(index - 1, updatedMember);
                    break;
                }
            case 5:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 5);
}
