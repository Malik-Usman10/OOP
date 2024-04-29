#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Person
{
private:
    string CNIC;
    string Name;
    string Address;
    string gender;
public:
    void getCNIC(string c)
    {
        CNIC = c;
    }
    string setCNIC()
    {
        return CNIC;
    }
    void getName(string n)
    {
        Name = n;
    }
    string setName()
    {
        return Name;
    }
    void getAddress(string a)
    {
        Address = a;
    }
    string setAddress()
    {
        return Address;
    }
    void getGender(string g)
    {
        gender = g; 
    }
    string setGender()
    {
        return gender;
    }
    void display()
    {
        cout << "\nThe Name of Person is: " << Name << endl;
        cout << "\nThe CNIC of Person is: " << CNIC << endl;
        cout << "\nThe Address of Person is: " << Address << endl;
        cout << "\nThe Gender of Person is: " << gender << endl;
    }

};

class Item{
private:
    string title;
    string author;
    int numPages;
    bool isBorrowed;
    int ID;
public:
    void setTitle(string t)
    {
        title = t;
    }
    string getTitle()
    {
        return title;
    }
    void setAuthor(string a)
    {
        author = a;
    }
    string getAuthor()
    {
        return author;
    }
    void setID(int id)
    {
        ID = id;
    }
    int getID()
    {
        return ID;
    }
    void setNumPages(int np)
    {
        numPages = np;
    }
    int getNumPages()
    {
        return numPages;
    }
    void display()
    {
        cout << "\nThe Title of the Book is: " << title << endl;
        cout << "\n The Author of the Book is: " << author << endl;
        cout << "\n The Number of Pages in the Book is: " << numPages << endl;
        cout << "\n The ID of the Book is: " << ID << endl;
    }
};

class Book : public Item
{
private:
    string isbn;
    Person Author;
public:
    Book(): isbn(""), Author(){};
    Book(string isbn, Person& a ) : isbn(isbn), Author(a) {}
    Book(const Book& copy) : isbn(copy.isbn), Author(copy.Author) {}

    void setISBN(string isbn)
    {
        isbn = isbn;
    }
    string getISBN()
    {
        return  isbn;
    }
    void display()
    {
        cout << "\nThe ISBN of the Book is: " << isbn << endl;
        cout << "\n The Author of the Book is: " << getAuthor() << endl;
    }

};
class Thesis : public Item
{
private:
    int thesisID;
    Person writer;
public:
    Thesis(): thesisID(0), writer(){};
    Thesis(int thesisID, Person& w) : thesisID(thesisID), writer(w) {};
    Thesis(const Thesis& copy) : thesisID(copy.thesisID), writer(copy.writer) {};

    void setID(int id)
    {
        thesisID = id;
    }
    int getID()
    {
        return thesisID;
    }
    void display()
    {
        cout << "\nThe ID of the Book is: " << thesisID << endl;
        cout << "\n The Author of the Book is: " << getAuthor() << endl;
    }

};
class Student : public Person
{
private:
    string rollNumber;
    string Degree;
    string Department;
public:
    void setRollNumber(string r)
    {
        rollNumber = r;
    }
    string getRollNumber()
    {
        return rollNumber;
    }
    void setDegree(string d)
    {
        Degree = d;
    }
    string getDegree()
    {
        return Degree;
    }
    void setDepartment(string dep)
    {
        Department = dep;
    }
    string getDepartment()
    {
        return  Department;
    }
};
class BorrowItems
{
private:
    string thesisName;
    string borrowDate;
    string returnDate;
    Student lendingTo;
public:
    void setThesisName(string n)
    {
        thesisName = n;
    }
    string getThesisName()
    {
        return thesisName;
    }
    void setBorrowDate(string d)
    {
        borrowDate = d;
    }
    string getBorrowDate()
    {
        return borrowDate;
    }



};
class Library
{
private:
    string libraryName;
    Person admin;
    vector<int> Books;
    vector<int> Thesis;
    vector<int> BorrowItems;
public:

};

int main()
{

}