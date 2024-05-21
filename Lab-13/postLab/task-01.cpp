#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

class Book
{
private:
    string title;
    string author;
    string publisher;
    int publicationYear;
    string ISBN;
    string status;
public:
    void setBookData()
    {
        cout << "Enter book title: ";
        getline(cin, title);
        cout << "Enter book author: ";
        getline(cin, author);
        cout << "Enter book publisher: ";
        getline(cin, publisher);
        cout << "Enter book publication year: ";
        cin >> publicationYear;
        cout << "Enter book ISBN: ";
        cin >> ISBN;
        cout << "Enter book status (available or checked-out): ";
        cin >> status;
        cin.ignore();
    }
    void printBookData()
    {
        cout << "Title: " << title << endl;
        cout << "Author: " << author << endl;
        cout << "Publisher: " << publisher << endl;
        cout << "Publication Year: " << publicationYear << endl;
        cout << "ISBN: " << ISBN << endl;
        cout << "Status: " << status << endl;
    }
    void writeToFile(ofstream &file)
    {
        file << title << endl;
        file << author << endl;
        file << publisher << endl;
        file << publicationYear << endl;
        file << ISBN << endl;
        file << status << endl;
    }
    void readFromFile(ifstream &file)
    {
        getline(file, title);
        getline(file, author);
        getline(file, publisher);
        file >> publicationYear;
        file >> ISBN;
        file >> status;
        file.ignore();
    }
    string getTitle()
    {
        return title;
    }
    string getStatus()
    {
        return status;
    }
    void setStatus(string status)
    {
        this->status = status;
    }
};
class Library
{
private:
    string name;
    string address;
    vector<Book> books;
public:
    void setNameAndAddress()
    {
        cout << "Enter library name: ";
        getline(cin, name);
        cout << "Enter library address: ";
        getline(cin, address);
    }
    void addBook(Book b)
    {
        books.push_back(b);
    }
    void removeBook(Book b)
    {
        for (int i = 0; i < books.size(); i++)
        {
            if (books[i].getTitle() == b.getTitle())
            {
                books.erase(books.begin() + i);
                return;
            }
        }
    }
    void printLibraryData()
    {
        cout << "Library Name: " << name << endl;
        cout << "Library Address: " << address << endl;
        cout << "Books: " << endl;
        for (int i = 0; i < books.size(); i++)
        {
            books[i].printBookData();
            cout << endl;
        }
    }
    void writeToFile(ofstream &file)
    {
        file << name << endl;
        file << address << endl;
        file << endl;
        for (int i = 0; i < books.size(); i++)
        {
            books[i].writeToFile(file);
            file << endl;
        }
    }
    void readFromFile(ifstream &file)
    {
        getline(file, name);
        getline(file, address);
        file.ignore();
        Book b;
        while (file.peek() != EOF)
        {
            b.readFromFile(file);
            file.ignore();
            books.push_back(b);
        }
    }
    void checkOutBook(Book b)
    {
        for (int i = 0; i < books.size(); i++)
        {
            if (books[i].getTitle() == b.getTitle())
            {
                books[i].setStatus("checked out");
                return;
            }
        }
    }
    void returnBook(Book b)
    {
        for (int i = 0; i < books.size(); i++)
        {
            if (books[i].getTitle() == b.getTitle())
            {
                books[i].setStatus("available");
                return;
            }
        }
    }
};
int main()
{
    Library lib;
    lib.setNameAndAddress();
    int numBooks;
    cout << "Enter number of books: ";
    cin >> numBooks;
    cin.ignore();
    for (int i = 0; i < numBooks; i++)
    {
        Book b;
        b.setBookData();
        lib.addBook(b);
    }
    ofstream file("library.txt");
    lib.writeToFile(file);
    file.close();

    Library lib2;
    ifstream readFile("library.txt");
    lib2.readFromFile(readFile);
    readFile.close();
    lib2.printLibraryData();

    Book b;
    b.setBookData();
    if (b.getStatus() == "checked-out")
    {
        lib2.checkOutBook(b);
    }
    else (b.getStatus() == "available")
    {
        lib2.returnBook(b);
    }
}