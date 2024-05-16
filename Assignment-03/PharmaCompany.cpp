#include "PharmaCompany.h"

int PharmaCompany::nextID = 1;

PharmaCompany::PharmaCompany() : companyID(nextID++), companyName(""), location("") {}


PharmaCompany::PharmaCompany(const PharmaCompany& other) 
    : companyID(nextID++), companyName(other.companyName), location(other.location), listOfMedicines(other.listOfMedicines) {}


PharmaCompany::PharmaCompany(const string& name, const string& loc, const vector<Medication>& medicines)
    : companyID(nextID++), companyName(name), location(loc), listOfMedicines(medicines) {}

PharmaCompany::~PharmaCompany() {}

int PharmaCompany::getCompanyID() const 
{ 
    return companyID; 
}

string PharmaCompany::getCompanyName() const 
{ 
    return companyName; 
}
void PharmaCompany::setCompanyName(const string& name) 
{ 
    companyName = name; 
}

string PharmaCompany::getLocation() const
{ 
    return location; 
}
void PharmaCompany::setLocation(const string& loc) 
{ 
    location = loc; 
}

vector<Medication> PharmaCompany::getListOfMedicines() const 
{ 
    return listOfMedicines; 
}
void PharmaCompany::setListOfMedicines(const vector<Medication>& medicines) 
{ 
    listOfMedicines = medicines; 
}

void PharmaCompany::display() const 
{
    cout << "Company ID: " << companyID << endl;
    cout << "Company Name: " << companyName << endl;
    cout << "Location: " << location << endl;
    cout << "Medicines:" << endl;
    for (const Medication& med : listOfMedicines) 
    {
        cout << "- " << med.getMedicationName() << endl;
    }
}

PharmaCompany& PharmaCompany::operator=(const PharmaCompany& other) 
{
    if (this != &other) 
    {
        companyName = other.companyName;
        location = other.location;
        listOfMedicines = other.listOfMedicines;
    }
    return *this;
}

ostream& operator<<(ostream& os, const PharmaCompany& company) 
{
    os << "ID: " << company.companyID << " Name: " << company.companyName << " Location: " << company.location << endl;
    return os;
}

istream& operator>>(istream& is, PharmaCompany& company) 
{
    cout << "Enter Company Name: ";
    getline(is, company.companyName);
    cout << "Enter Location: ";
    getline(is, company.location);
    return is;
}