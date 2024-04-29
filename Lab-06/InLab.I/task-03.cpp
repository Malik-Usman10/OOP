#include<iostream>
#include <string>
using namespace std;

class Customer
{
    int ID;
    string name;
    string phone;
    string gender;

    Customer () : ID(1), name("Dynamic"), phone("Dynamic"), gender("") {}
    Customer (int id, string n, string p, string g)
    {
        ID = id;
        name = n;
        phone =p;
        gender = g;
    }
    void setID()
    {

    }
    void getName()
    {

    }
    void getPhone()
    {

    }
    void getGender()
    {

    }
};


int main()
{
    
}