#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream> 
#include <ctime>
#include <limits>
#include <iterator>

#include "PharmaCompany.h"
#include "Medication.h"
using namespace std;

class Address {
public:
    Address() : city_name(""), email(""), street_name("") {}

    Address(const Address& other) 
    {
        city_name = other.city_name;
        email = other.email;
        street_name = other.street_name;
        mobile_no = other.mobile_no;
    }

    Address(const string& city, const string& email, const string& street, const vector<string>& mobile)
        : city_name(city), email(email), street_name(street), mobile_no(mobile) 
    {
        validateEmail();
    }

    ~Address() {}

    string getCityName() const 
    { 
        return city_name; 
    }
    void setCityName(const string& city) 
    { 
        city_name = city; 
    }

    string getEmail() const 
    { 
        return email; 
    }
    void setEmail(const string& mail) 
    {
        email = mail;
        validateEmail();
    }

    string getStreetName() const 
    { 
        return street_name; 
    }
    void setStreetName(const string& street) 
    { 
        street_name = street; 
    }

    const vector<string>& getMobileNo() const 
    { 
        return mobile_no; 
    }
    void setMobileNo(const vector<string>& mobiles) 
    { 
        mobile_no = mobiles;
    }
    void display() const 
    {
        cout << "City: " << city_name << endl;
        cout << "Email: " << email << endl;
        cout << "Street: " << street_name << endl;
        cout << "Mobile Numbers:" << endl;
        for (const string& mobile : mobile_no) 
        {
        cout << "- " << mobile << endl;
        }
    }

  string operator[](int index) const 
  {
    if (index < 0 || index >= mobile_no.size()) 
    {
      throw runtime_error("Invalid mobile number index");
    }
    return mobile_no[index];
  }

  friend ostream& operator<<(ostream& os, const Address& address) 
  {
    os << "City: " << address.city_name << endl;
    os << "Email: " << address.email << endl;
    return os;
  }

  friend istream& operator>>(istream& is, Address& address) 
  {
    cout << "Enter City: ";
    getline(is, address.city_name);
    cout << "Enter Email: ";
    getline(is, address.email);
    address.validateEmail();
    cout << "Enter Street Name: ";
    getline(is, address.street_name);
    return is;
  }

private:
    void validateEmail() 
    {
        string domain = email.substr(email.find('@') + 1);
        if (domain != "gmail.com" && domain != "outlook.com" && domain != "hotmail.com") 
        {
        throw invalid_argument("Invalid email domain. Use gmail.com, outlook.com, or hotmail.com");
        }
    }
    void validateMobileNumbers() 
    {
        sort(mobile_no.begin(), mobile_no.end()); 
        for (int i = 1; i < mobile_no.size(); i++) 
        {
            if (mobile_no[i] == mobile_no[i - 1]) 
            {
                throw invalid_argument("Duplicate mobile number found");
            }
        }
    }
  string city_name;
  string email;
  string street_name;
  vector<string> mobile_no;
};

class Person {
public:
    Person() : first_name(""), last_name(""), cnic("") {}


    Person(const Person& other)
        : first_name(other.first_name),
            last_name(other.last_name),
            cnic(other.cnic),
            address(other.address),
            gender(other.gender) {}


    Person(const string& first, const string& last, const string& cnic, const Address& address, const vector<string>& gender)
        : first_name(first),
            last_name(last),
            cnic(cnic),
            address(address),
            gender(gender) {
            validateCNIC(); 
    }

    ~Person() {}

    string getFirstName() const 
    { 
        return first_name; 
    }
    void setFirstName(const string& name) 
    { 
        first_name = name; 
    }

    string getLastName() const 
    { 
        return last_name; 
    }
    void setLastName(const string& name) 
    { 
        last_name = name; 
    }

    string getCNIC() const 
    { 
        return cnic; 
    }
    void setCNIC(const string& nic) 
    {
        cnic = nic;
        validateCNIC(); 
    }

    const Address& getAddress() const 
    { 
        return address; 
    }
    void setAddress(const Address& addr) 
    { 
        address = addr; 
    }

    const vector<string>& getGender() const 
    { 
        return gender; 
    }
    void setGender(const vector<string>& gen) 
    { 
        gender = gen; 
    }

    void display() const 
    {
        cout << "First Name: " << first_name << endl;
        cout << "Last Name: " << last_name << endl;
        cout << "CNIC: " << cnic << endl;
        cout << "Address:" << endl;
        address.display();
        cout << "Gender: ";
        for (const string& gen : gender) 
        {
        cout << gen << " ";
        }
        cout << endl;
    }


    Person& operator=(const Person& other) 
    {
        if (this != &other) 
        { 
        first_name = other.first_name;
        last_name = other.last_name;
        cnic = other.cnic;
        address = other.address;
        gender = other.gender;
        }
        return *this;
    }


    friend ostream& operator<<(ostream& os, const Person& person) 
    {
        os << "Name: " << person.first_name << " " << person.last_name << endl;
        return os;
    }

    friend istream& operator>>(istream& is, Person& person) 
    {
        cout << "Enter First Name: ";
        getline(is, person.first_name);
        cout << "Enter Last Name: ";
        getline(is, person.last_name);
        cout << "Enter CNIC: ";
        getline(is, person.cnic);
        person.validateCNIC(); 

        cout << "Enter Gender(s) (separate by spaces): ";
        string genders;
        getline(is, genders);

        vector<string> gender_list;
        stringstream ss(genders);
        string gender;
        while (getline(ss, gender, ' ')) {
        gender_list.push_back(gender);
        }
        person.setGender(gender_list);

        return is;
    }

private:
    void validateCNIC() 
    {
        if (cnic.length() != 13 || !all_of(cnic.begin(), cnic.end(), ::isdigit)) 
        {
        throw invalid_argument("Invalid CNIC. Must be 13 digits.");
        }
    }

    string first_name;
    string last_name;
    string cnic;
    Address address;
    vector<string> gender;
};


class Customer {
private:
    static int nextID; 
    int Customer_ID;
    Person General_info;
    bool Membership_status;

public:

    Customer() : Customer_ID(nextID++), Membership_status(false) {}

    Customer(const Customer& other) : Customer_ID(nextID++), General_info(other.General_info), Membership_status(other.Membership_status) {}

    Customer(const Person& info, bool membership) : Customer_ID(nextID++), General_info(info), Membership_status(membership) {}

    ~Customer() {}


    int getCustomerID() const 
    { 
        return Customer_ID; 
    }


    Person getGeneralInfo() const 
    { 
        return General_info; 
    }
    void setGeneralInfo(const Person& info) 
    { 
        General_info = info; 
    }

    bool getMembershipStatus() const 
    { 
        return Membership_status; 
    }
    void setMembershipStatus(bool status) 
    { 
        Membership_status = status; 
    }

    void display() const 
    {
        cout << "Customer ID: " << Customer_ID << endl;
        General_info.display();
        cout << "Membership Status: " << (Membership_status ? "Member" : "Non-Member") << endl;
    }

    Customer& operator=(const Customer& other) 
    {
        if (this != &other) 
        {
            General_info = other.General_info;
            Membership_status = other.Membership_status;
        }
        return *this;
    }

    friend ostream& operator<<(ostream& os, const Customer& customer) 
    {
        os << "Customer ID: " << customer.Customer_ID << endl;
        os << customer.General_info;
        return os;
    }

    friend istream& operator>>(istream& is, Customer& customer) {
        is >> customer.General_info;
        cout << "Enter Membership Status (1 for Member, 0 for Non-Member): ";
        is >> customer.Membership_status;
        return is;
    }
};

int Customer::nextID = 1;


class Staff {
private:
    static int nextID; 
    int ID;
    string role;
    string employmentDate; 
    Person generalInfo;
    double salary;

public:
    Staff() : ID(nextID++), role(""), employmentDate(""), salary(0.0) {}

    Staff(const Staff& other) : ID(nextID++), role(other.role), employmentDate(other.employmentDate), generalInfo(other.generalInfo), salary(other.salary) {}

    Staff(const string& role, const string& employmentDate, const Person& info, double salary)
        : ID(nextID++), role(role), employmentDate(employmentDate), generalInfo(info), salary(salary) {}

    ~Staff() {}

    int getID() const 
    { 
        return ID; 
    }

    string getRole() const 
    { 
        return role; 
    }
    void setRole(const string& role) 
    { 
        this->role = role; 
    }

    string getEmploymentDate() const 
    { 
        return employmentDate; 
    }
    void setEmploymentDate(const string& date) 
    { 
        employmentDate = date; 
    }

    Person getGeneralInfo() const 
    { 
        return generalInfo; 
    }
    void setGeneralInfo(const Person& info) 
    { 
        generalInfo = info; 
    }

    double getSalary() const 
    { 
        return salary; 
    }
    void setSalary(double salary)
    { 
        this->salary = salary;
    }

    void display() const 
    {
        cout << "ID: " << ID << endl;
        cout << "Role: " << role << endl;
        cout << "Employment Date: " << employmentDate << endl;
        generalInfo.display(); 
        cout << "Salary: " << salary << endl;
    }

    Staff& operator=(const Staff& other) 
    {
        if (this != &other) 
        {
            role = other.role;
            employmentDate = other.employmentDate;
            generalInfo = other.generalInfo;
            salary = other.salary;
        }
        return *this;
    }

    friend ostream& operator<<(ostream& os, const Staff& staff) 
    {
        os << "ID: " << staff.ID << " Role: " << staff.role << " Employment Date: " << staff.employmentDate << endl;
        return os;
    }

    friend istream& operator>>(istream& is, Staff& staff) 
    {
        cout << "Enter Role: ";
        getline(is, staff.role);
        cout << "Enter Employment Date: ";
        getline(is, staff.employmentDate);
        return is;
    }
};
int Staff::nextID = 1;

class Salesman {
private:
    static int nextID;
    int salesmanID;
    Person generalInfo; 
    PharmaCompany company; 
    double setCommission; 
    double obtainedCommission;

public:
    Salesman() : salesmanID(nextID++), setCommission(0.0), obtainedCommission(0.0) {}

    Salesman(const Person& info, const PharmaCompany& comp, double commission)
        : salesmanID(nextID++), generalInfo(info), company(comp), setCommission(commission), obtainedCommission(0.0) {}

    int getSalesmanID() const 
    { 
        return salesmanID; 
    }

    Person getGeneralInfo() const 
    { 
        return generalInfo; 
    }
    void setGeneralInfo(const Person& info) 
    { 
        generalInfo = info; 
    }

    PharmaCompany getCompany() const 
    { 
        return company; 
    }
    void setCompany(const PharmaCompany& comp) 
    { 
        company = comp; 
    }

    double getSetCommission() const 
    { 
        return setCommission; 
    }
    void setSetCommission(double commission) 
    { 
        setCommission = commission; 
    }

    double getObtainedCommission() const 
    { 
        return obtainedCommission; 
    }
    void setObtainedCommission(double commission) 
    { 
        obtainedCommission = commission; 
    }

    void addCommission(double saleAmount) 
    {
        obtainedCommission += saleAmount * (setCommission / 100.0);
    }

    void display() const {
        cout << "Salesman ID: " << salesmanID << endl;
        generalInfo.display(); 
        cout << "Company: ";
        company.display(); 
        cout << "Set Commission: " << setCommission << "%" << endl;
        cout << "Obtained Commission: $" << obtainedCommission << endl;
    }

    void showCompanyMedicines() const 
    {
        cout << "Medicines offered by " << company.getCompanyName() << ":" << endl;
        auto meds = company.getListOfMedicines(); 
        for (const auto& med : meds)
        {
            cout << "- " << med.getMedicationName() << endl;
        }
    }
};

int Salesman::nextID = 1;

class Order {
private:
    static int nextID; 
    int orderID;
    int customerID; 
    tm orderDate; 
    vector<Medication> boughtMedicine; 
    Salesman salesman; 
    PharmaCompany company;
    double totalAmount;
    string paymentMethod;

public:

    Order() : orderID(nextID++), customerID(0), totalAmount(0.0), paymentMethod("") 
    {
        time_t now = time(0);
        orderDate = *localtime(&now);
    }

    Order(int custID, const tm& date, const vector<Medication>& meds, const Salesman& sales, const PharmaCompany& comp, double amount, const string& payment)
        : orderID(nextID++), customerID(custID), orderDate(date), boughtMedicine(meds), salesman(sales), company(comp), totalAmount(amount), paymentMethod(payment) {}

    int getOrderID() const 
    { 
        return orderID; 
    }

    int getCustomerID() const 
    { 
        return customerID; 
    }
    void setCustomerID(int custID) 
    { 
        customerID = custID;
    }

    tm getOrderDate() const 
    { 
        return orderDate; 
    }
    void setOrderDate(const tm& date) 
    { 
        orderDate = date; 
    }

    vector<Medication> getBoughtMedicine() const 
    { 
        return boughtMedicine; 
    }
    void setBoughtMedicine(const vector<Medication>& meds) 
    { 
        boughtMedicine = meds; 
    }

    Salesman getSalesman() const 
    { 
        return salesman; 
    }
    void setSalesman(const Salesman& sales) 
    { 
        salesman = sales; 
    }

    PharmaCompany getCompany() const 
    { 
        return company; 
    }
    void setCompany(const PharmaCompany& comp) 
    { 
        company = comp; 
    }

    double getTotalAmount() const 
    { 
        return totalAmount; 
    }
    void setTotalAmount(double amount) 
    { 
        totalAmount = amount; 
    }

    string getPaymentMethod() const 
    { 
        return paymentMethod; 
    }
    void setPaymentMethod(const string& payment) 
    { 
        paymentMethod = payment; 
    }

    void display() const {
        cout << "Order ID: " << orderID << endl;
        cout << "Customer ID: " << customerID << endl;
        cout << "Order Date: " << asctime(&orderDate);
        cout << "Total Amount: $" << totalAmount << endl;
        cout << "Payment Method: " << paymentMethod << endl;
        cout << "Medicines Bought:" << endl;
        for (const Medication& med : boughtMedicine) 
        {
            cout << "- " << med.getMedicationName() << endl;
        }
        cout << "Salesman: ";
        salesman.display();
        cout << "Company: ";
        company.display();
    }
};

int Order::nextID = 1;


class Pharmacy {
private:
    static int nextID; 
    int pharmacyID;
    string pharmacyName;
    string pharmacyOwner;
    vector<Medication> medications; 
    vector<Staff> staffMembers; 
    vector<Salesman> salesmen; 
    vector<Order> orders;
    double totalSales;
    double totalPurchases;
    double totalProfit;
    PharmaCompany company;

public:
    Pharmacy() : pharmacyID(nextID++), totalSales(0.0), totalPurchases(0.0), totalProfit(0.0) {}

    Pharmacy(const string& name, const string& owner)
        : pharmacyID(nextID++), pharmacyName(name), pharmacyOwner(owner), totalSales(0.0), totalPurchases(0.0), totalProfit(0.0) {}

    Pharmacy(const Pharmacy& other)
        : pharmacyID(nextID++), pharmacyName(other.pharmacyName), pharmacyOwner(other.pharmacyOwner),
          medications(other.medications), staffMembers(other.staffMembers), salesmen(other.salesmen),
          orders(other.orders), totalSales(other.totalSales), totalPurchases(other.totalPurchases), totalProfit(other.totalProfit) {}

    ~Pharmacy() {}

    int getPharmacyID() const 
    { 
        return pharmacyID; 
    }

    string getPharmacyName() const 
    { 
        return pharmacyName; 
    }
    void setPharmacyName(const string& name) 
    { 
        pharmacyName = name; 
    }

    string getPharmacyOwner() const 
    { 
        return pharmacyOwner;
    }
    void setPharmacyOwner(const string& owner) 
    { 
        pharmacyOwner = owner; 
    }

    void addMedication(const Medication& medication) 
    {
        medications.push_back(medication);
    }

    void removeMedication(int medicationID) 
    {
        auto it = remove_if(medications.begin(), medications.end(), [medicationID](const Medication& m) 
        {
            return m.getMedicationID() == medicationID;
        });
        medications.erase(it, medications.end());
    }

    void addOrder(const Order& order) 
    {
        orders.push_back(order);
    }

    void addStaff(const Staff& staff) 
    {
        staffMembers.push_back(staff);
    }

    void removeStaff(int staffID)
     {
        auto it = remove_if(staffMembers.begin(), staffMembers.end(), [staffID](const Staff& s) 
        {
            return s.getID() == staffID;
        });
        staffMembers.erase(it, staffMembers.end());
    }

    void addSalesman(const Salesman& salesman) 
    {
        salesmen.push_back(salesman);
    }

    void removeSalesman(int salesmanID) 
    {
        auto it = remove_if(salesmen.begin(), salesmen.end(), [salesmanID](const Salesman& s) 
        {
            return s.getSalesmanID() == salesmanID;
        });
        salesmen.erase(it, salesmen.end());
    }

    void setPharmaCompany(const PharmaCompany& comp) 
    {
        company = comp;
    }
    Pharmacy& operator=(const Pharmacy& other) 
    {
        if (this != &other) 
        {
            pharmacyName = other.pharmacyName;
            pharmacyOwner = other.pharmacyOwner;
            medications = other.medications;
            staffMembers = other.staffMembers;
            salesmen = other.salesmen;
            orders = other.orders;
            totalSales = other.totalSales;
            totalPurchases = other.totalPurchases;
            totalProfit = other.totalProfit;
            company = other.company;
        }
        return *this;
    }

    friend ostream& operator<<(ostream& os, const Pharmacy& pharmacy) 
    {
        os << "Pharmacy ID: " << pharmacy.pharmacyID << endl;
        os << "Pharmacy Name: " << pharmacy.pharmacyName << endl;
        os << "Pharmacy Owner: " << pharmacy.pharmacyOwner << endl;
        return os;
    }

    friend istream& operator>>(istream& is, Pharmacy& pharmacy)
    {
        cout << "Enter Pharmacy Name: ";
        getline(is, pharmacy.pharmacyName);
        cout << "Enter Pharmacy Owner Name: ";
        getline(is, pharmacy.pharmacyOwner);
        return is;
    }
};
int Pharmacy::nextID = 1;


void addPharmacy(vector<Pharmacy>& pharmacies) 
{
    Pharmacy newPharmacy;
    cout << "Adding a new Pharmacy." << endl;
    cin >> newPharmacy; 
    PharmaCompany company;
    cout << "Enter details for the associated PharmaCompany:" << endl;
    cin >> company;
    newPharmacy.setPharmaCompany(company);
    pharmacies.push_back(newPharmacy);
    cout << "Pharmacy added successfully." << endl;
}


void displayPharmacies(const vector<Pharmacy>& pharmacies)
{
    if (pharmacies.empty()) 
    {
        cout << "No pharmacies available." << endl;
        return;
    }
    for (const auto& pharmacy : pharmacies) 
    {
        cout << pharmacy << endl;
    }
}

int main() 
{
    vector<Pharmacy> pharmacies;
    int choice;

    do {
        cout << "\nPharmacy Management System" << endl;
        cout << "1. Add a Pharmacy" << endl;
        cout << "2. Display All Pharmacies" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch (choice) 
        {
            case 1:
                addPharmacy(pharmacies);
                break;
            case 2:
                displayPharmacies(pharmacies);
                break;
            case 3:
                cout << "Exiting the program." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 3);

    return 0;
}