#ifndef MEDICATION_H
#define MEDICATION_H

#include <string>
#include <iostream>
#include <limits>
using namespace std;

#include "PharmaCompany.h"
class PharmaCompany;

class Medication {
private:
    static int nextID; 
    int medicationID;
    string medicationName;
    string description;
    double price;
    int quantityInStock;
    string expiryDate; 
    const PharmaCompany* company; 

public:
    Medication();
    Medication(const Medication& other);
    Medication(const string& name, const string& desc, double price, int quantity, const string& expiry, const PharmaCompany& comp);
    ~Medication();

    int getMedicationID() const;
    string getMedicationName() const;
    void setMedicationName(const string& name);
    string getDescription() const;
    void setDescription(const string& desc);
    double getPrice() const;
    void setPrice(double price);
    int getQuantityInStock() const;
    void setQuantityInStock(int quantity);
    string getExpiryDate() const;
    void setExpiryDate(const string& expiry);
    const PharmaCompany* getCompany() const;
    void setCompany(const PharmaCompany* comp);

    void display() const;
    bool isExpiredOrNot() const;

    Medication& operator=(const Medication& other);
    friend ostream& operator<<(ostream& os, const Medication& med);
    friend istream& operator>>(istream& is, Medication& med);
};

#endif 