#ifndef PHARMACOMPANY_H
#define PHARMACOMPANY_H

#include <string>
#include <vector>
#include <iostream>
#include "Medication.h"
using namespace std;


class PharmaCompany {
private:
    static int nextID;
    int companyID;
    string companyName;
    string location;
    vector<Medication> listOfMedicines;

public:
    PharmaCompany();
    PharmaCompany(const PharmaCompany& other);
    PharmaCompany(const string& name, const string& loc, const vector<Medication>& medicines);
    ~PharmaCompany();

    int getCompanyID() const;
    string getCompanyName() const;
    void setCompanyName(const string& name);
    string getLocation() const;
    void setLocation(const string& loc);
    vector<Medication> getListOfMedicines() const;
    void setListOfMedicines(const vector<Medication>& medicines);

    void display() const;

    PharmaCompany& operator=(const PharmaCompany& other);

    friend ostream& operator<<(ostream& os, const PharmaCompany& company);
    friend istream& operator>>(istream& is, PharmaCompany& company);
};

#endif