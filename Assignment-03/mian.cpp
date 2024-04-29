#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream> 

using namespace std;

class Address {
public:

  Address() : city_name(""), email(""), street_name("") {}

  Address(const Address& other) {
    city_name = other.city_name;
    email = other.email;
    street_name = other.street_name;
    mobile_no = other.mobile_no;
  }

  Address(const string& city, const string& email, const string& street, const vector<string>& mobile)
      : city_name(city), email(email), street_name(street), mobile_no(mobile) {
    validateEmail(); 
  }

  ~Address() {}

  string getCityName() const { return city_name; }
  void setCityName(const string& city) { city_name = city; }

  string getEmail() const { return email; }
  void setEmail(const string& mail) {
    email = mail;
    validateEmail();
  }

  string getStreetName() const { return street_name; }
  void setStreetName(const string& street) { street_name = street; }

  const vector<string>& getMobileNo() const { return mobile_no; }
  void setMobileNo(const vector<string>& mobiles) { mobile_no = mobiles; }

  void display() const {
    cout << "City: " << city_name << endl;
    cout << "Email: " << email << endl;
    cout << "Street: " << street_name << endl;
    cout << "Mobile Numbers:" << endl;
    for (const string& mobile : mobile_no) {
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

  string getFirstName() const { return first_name; }
  void setFirstName(const string& name) { first_name = name; }

  string getLastName() const { return last_name; }
  void setLastName(const string& name) { last_name = name; }

  string getCNIC() const { return cnic; }
  void setCNIC(const string& nic) 
  {
    cnic = nic;
    validateCNIC();
  }

  const Address& getAddress() const { return address; }
  void setAddress(const Address& addr) { address = addr; }

  const vector<string>& getGender() const { return gender; }
  void setGender(const vector<string>& gen) { gender = gen; }

  void display() const 
  {
    cout << "First Name: " << first_name << endl;
    cout << "Last Name: " << last_name << endl;
    cout << "CNIC: " << cnic << endl;
    cout << "Address:" << endl;
    address.display();
    cout << "Gender: ";
    for (const string& gen : gender) {
      cout << gen << " ";
    }
    cout << endl;
  }

  Person& operator=(const Person& other) {
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

 friend istream& operator>>(istream& is, Person& person) {
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
    while (getline(ss, gender, ' ')) 
    {
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





int main()
{
  
}