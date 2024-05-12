#include "PharmaCompany.h"
#include "Medication.h"

int Medication::nextID = 1;

Medication::Medication()
    : medicationID(nextID++), medicationName(""), description(""), price(0.0), quantityInStock(0), expiryDate("") {
}

Medication::Medication(const Medication& other)
    : medicationID(nextID++), medicationName(other.medicationName), description(other.description),
      price(other.price), quantityInStock(other.quantityInStock), expiryDate(other.expiryDate), company(other.company) 
      {}

Medication::Medication(const string& name, const string& desc, double price, int quantity, const string& expiry, const PharmaCompany& comp)
    : medicationID(nextID++), medicationName(name), description(desc), price(price),
      quantityInStock(quantity), expiryDate(expiry)
    {
        company = new PharmaCompany(comp);
    }

Medication::~Medication() 
{
    delete company;
}

int Medication::getMedicationID() const 
{
    return medicationID; 
}
string Medication::getMedicationName() const 
{ 
    return medicationName;
}
void Medication::setMedicationName(const string& name) 
{ 
    medicationName = name; 
}
string Medication::getDescription() const 
{ 
    return description; 
}
void Medication::setDescription(const string& desc) 
{ 
    description = desc; 
}
double Medication::getPrice() const 
{ 
    return price; 
}
void Medication::setPrice(double newPrice) 
{ 
    price = newPrice; 
}
int Medication::getQuantityInStock() const 
{ 
    return quantityInStock;
}
void Medication::setQuantityInStock(int quantity) 
{ 
    quantityInStock = quantity; 
}
string Medication::getExpiryDate() const 
{ 
    return expiryDate; 
}
void Medication::setExpiryDate(const string& expiry) 
{ 
    expiryDate = expiry; 
}
const PharmaCompany* Medication::getCompany() const 
{ 
    return company; 
}
void Medication::setCompany(const PharmaCompany* comp) 
{ 
    company = comp; 
}

void Medication::display() const 
{
    cout << "Medication ID: " << medicationID << endl;
    cout << "Name: " << medicationName << endl;
    cout << "Description: " << description << endl;
    cout << "Price: " << price << endl;
    cout << "Quantity in Stock: " << quantityInStock << endl;
    cout << "Expiry Date: " << expiryDate << endl;
    cout << "Company: ";
    company->display();
}
bool Medication::isExpiredOrNot() const 
{
     return false;
}

Medication& Medication::operator=(const Medication& other) 
{
    if (this != &other)
    {
        medicationName = other.medicationName;
        description = other.description;
        price = other.price;
        quantityInStock = other.quantityInStock;
        expiryDate = other.expiryDate;
        company = other.company;
    }
    return *this;
}
ostream& operator<<(ostream& os, const Medication& med) 
{
    os << "ID: " << med.medicationID << " Name: " << med.medicationName << " Price: " << med.price 
        << " Quantity in Stock: " << med.quantityInStock << " Expiry Date: " << med.expiryDate << endl;
    return os;
}

istream& operator>>(istream& is, Medication& med) 
{
    cout << "Enter Medication Name: ";
    getline(is, med.medicationName);
    cout << "Enter Description: ";
    getline(is, med.description);
    cout << "Enter Price: ";
    is >> med.price;
    is.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Enter Quantity in Stock: ";
    is >> med.quantityInStock;
    is.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Enter Expiry Date (format YYYY-MM-DD): ";
    getline(is, med.expiryDate);
    return is;
}
