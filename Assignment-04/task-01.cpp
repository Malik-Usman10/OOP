#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Vehicle
{
protected:
    string make;
    string model;
    int year;
    double price;
public:
    Vehicle(){}
    Vehicle(string make, string model, int year, double price)
    {
        this->make = make;
        this->model = model;
        this->year = year;
        this->price = price;
    }
    virtual void displayInfo()
    {
        cout << "Make: " << make << endl;
        cout << "Model: " << model << endl;
        cout << "Year: " << year << endl;
        cout << "Price: " << price << endl;
    }
    string getMake() const 
    { 
        return make; 
    }
    string getModel() const 
    { 
        return model; 
    }
    int getYear() const 
    { 
        return year; 
    }
    double getPrice() const 
    { 
        return price; 
    }

};
class Car : public Vehicle
{
private:
    int doors;
public:
    Car(){}
    Car(string make, string model, int year, double price, int doors) : Vehicle(make, model, year, price)
    {
        this->doors = doors;
    }
    void setDoors(int doors)
    {
        this->doors = doors;
    }
    int getDoors()
    {
        return doors;
    }
    void displayInfo()
    {
        cout << "Make: " << make << endl;
        cout << "Model: " << model << endl;
        cout << "Year: " << year << endl;
        cout << "Price: " << price << endl;
        cout << "Doors: " << doors << endl;
    }

};

class Truck : public Vehicle
{
private:
    string bedSize;
public:
    Truck(){}
    Truck(string make, string model, int year, double price, string bedSize) : Vehicle(make, model, year, price)
    {
        this->bedSize = bedSize;
    }
    void setBedSize(string bedSize)
    {
        this->bedSize = bedSize;
    }
    string getBedSize()
    {
        return bedSize;
    }
    void displayInfo()
    {
        cout << "Make: " << make << endl;
        cout << "Model: " << model << endl;
        cout << "Year: " << year << endl;
        cout << "Price: " << price << endl;
        cout << "Bed Size: " << bedSize << endl;
    }
};

class Motorcycle : public Vehicle
{
private:
    double engineSize;
public:
    Motorcycle(){}
    Motorcycle(string make, string model, int year, double price, double engineSize) : Vehicle(make, model, year, price)
    {
        this->engineSize = engineSize;
    }
    void setEngineSize(double engineSize)
    {
        this->engineSize = engineSize;
    }
    double getEngineSize()
    {
        return engineSize;
    }
    void displayInfo()
    {
        cout << "Make: " << make << endl;
        cout << "Model: " << model << endl;
        cout << "Year: " << year << endl;
        cout << "Price: " << price << endl;
        cout << "Engine Size: " << engineSize << endl;
    }
};

class Inventory : public Vehicle
{
private:
    vector<Vehicle*> inventory;

public:
    Inventory(){}
    void addVehicle(Vehicle* vehicle)
    {
        inventory.push_back(vehicle);
    }
    void displayInventory()
    {
        for(int i = 0; i < inventory.size(); i++)
        {
            inventory[i]->displayInfo();
        }
    }
    void removeVehicle(string make, string model, int year)
    {
        for(int i = 0; i < inventory.size(); i++)
        {
            if(inventory[i]->getMake() == make && inventory[i]->getModel() == model && inventory[i]->getYear() == year)
            {
                inventory.erase(inventory.begin() + i);
                cout << "Vehicle Remove Successfully" << endl;
            }
            else
            {
                cout << "No Vehicle With these details found" << endl;
            }
        }
    }
    void searchVehicle(string term)
    {
        for(int i = 0; i < inventory.size(); i++)
        {
            if(inventory[i]->getMake() == term || inventory[i]->getModel() == term)
            {
                inventory[i]->displayInfo();
            }
            else
            {
                cout << "No Vehicle With these details found" << endl;
            }
        }
    }
    void sortVehicles(string term)
    {
        if(term == "make")
        {
            sort(inventory.begin(), inventory.end(), [](Vehicle* a, Vehicle* b) 
            { 
                return a->getMake() < b->getMake(); 
            });
            cout << "Vehicle Sorted Succesfuully" << endl;

        }
        else if(term == "model")
        {
            sort(inventory.begin(), inventory.end(), [](Vehicle* a, Vehicle* b) 
            { 
                return a->getModel() < b->getModel(); 
            });
            cout << "Vehicle Sorted Succesfuully" << endl;
            
        }
        else if(term == "year")
        {
            sort(inventory.begin(), inventory.end(), [](Vehicle* a, Vehicle* b) 
            { 
                return a->getYear() < b->getYear(); 
            });
            cout << "Vehicle Sorted Succesfuully" << endl;
        }
        else if(term == "price")
        {
            sort(inventory.begin(), inventory.end(), [](Vehicle* a, Vehicle* b) 
            { 
                return a->getPrice() < b->getPrice(); 
            });
            cout << "Vehicle Sorted Succesfuully" << endl;
        }
        else
        {
            cout << "Invalid term" << endl;
        }
    }

};

int main() 
{
    Inventory inventory;
    int choice;
    string make, model, term, bedSize;
    int year, numDoors, type, secondTerm;
    double price, engineSize;

    while (true) 
    {
        cout << "1. Add Vehicle\n";
        cout << "2. Remove Vehicle\n";
        cout << "3. Search Vehicle\n";
        cout << "4. Sort Vehicles\n";
        cout << "5. Display Inventory\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) 
        {
            case 1:
                cout << "Which type of Vehicle you want to add?\n";
                cout << "1. Car\n";
                cout << "2. Truck\n";
                cout << "3. Motorcycle\n";
                cin >> type;
                if (type == 1)
                {
                    cout << "Enter make, model, year, price, number of doors: ";
                    cin >> make >> model >> year >> price >> numDoors;
                    inventory.addVehicle(new Car(make, model, year, price, numDoors));
                }
                else if(type == 2)
                {
                    cout << "Enter make, model, year, price, bed size: ";
                    cin >> make >> model >> year >> price >> bedSize;
                    inventory.addVehicle(new Truck(make, model, year, price, bedSize));
                }
                else if(type == 3)
                {
                    cout << "Enter make, model, year, price, engine size: ";
                    cin >> make >> model >> year >> price >> engineSize;
                    inventory.addVehicle(new Motorcycle(make, model, year, price, engineSize));
                }
                break;
            case 2:
                cout << "Enter make model & year to remove: ";
                cin >> make >> model >> year;
                inventory.removeVehicle(make, model, year);
                break;
            case 3:
                cout << "Enter search term (make or model): ";
                cin >> term;
                inventory.searchVehicle(term);
                break;
            case 4:
                cout << "Enter make, model, year, or price for sort: ";
                cin >> term;
                inventory.sortVehicles(term);
                break;
            case 5:
                inventory.displayInventory();
                break;
            case 6:
                return 0;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }
}
