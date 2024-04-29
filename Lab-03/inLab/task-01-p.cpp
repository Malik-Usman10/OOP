#include <iostream>
#include <vector>

using namespace std;

// Salesman class definition
class Salesman {
public:
  // Constructor with default values
  Salesman(string name = "", double salary = 0, int sales_made = 0)
      : name(name), salary(salary), sales_made(sales_made) {}

  // Accessors and mutators
  string getName() const { return name; }
  void setName(string newName) { name = newName; }

  double getSalary() const { return salary; }
  void setSalary(double newSalary) { salary = newSalary; }

  int getSalesMade() const { return sales_made; }
  void setSalesMade(int newSalesMade) { sales_made = newSalesMade; }

  // Comparison operator for sorting by sales_made (descending)
  bool operator<(const Salesman &other) const {
    return sales_made > other.sales_made;
  }

private:
  string name;
  double salary;
  int sales_made;
};

// Function to remove salesmen with low sales directly within the vector
void FireSalesmen(vector<Salesman> &salesmen) {
  // Manual sorting using bubble sort
  for (int i = 0; i < salesmen.size() - 1; i++) {
    for (int j = 0; j < salesmen.size() - i - 1; j++) {
      if (salesmen[j] < salesmen[j + 1]) {
        swap(salesmen[j], salesmen[j + 1]);
      }
    }
  }

  // Manual removal of elements with low sales
  int i = 0;
  while (i < salesmen.size()) {
    if (salesmen[i].getSalesMade() < 10) {
      salesmen.erase(salesmen.begin() + i);
    } else {
      i++;
    }
  }
}

int main() {
  int numSalesmen;

  cout << "Enter the number of salesmen: ";
  cin >> numSalesmen;

  if (numSalesmen <= 0) {
    cerr << "Invalid number of salesmen." << endl;
    return 1;
  }

  vector<Salesman> salesmen;

  // Input salesperson details
  for (int i = 0; i < numSalesmen; i++) {
    string name;
    double salary;
    int sales_made;

    cout << "Enter details for salesman " << i + 1 << ":" << endl;
    cout << "Name: ";
    cin >> name;
    cout << "Salary: ";
    cin >> salary;
    cout << "Sales made: ";
    cin >> sales_made;

    salesmen.push_back(Salesman(name, salary, sales_made));
  }

  // Fire salesmen with low sales
  FireSalesmen(salesmen);

  // Display remaining salesmen
  cout << "\nRemaining salesmen:" << endl;
  for (const Salesman &salesman : salesmen) {
    cout << "Name: " << salesman.getName() << endl;
    cout << "Salary: " << salesman.getSalary() << endl;
    cout << "Sales made: " << salesman.getSalesMade() << endl;
    cout << endl;
  }

  return 0;
}
