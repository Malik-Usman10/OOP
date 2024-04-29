#include <iostream>
#include <string>
using namespace std;

class Vehicles
{
private:
    int maxSpeed;
    int numWheels;
    int numDoors;
    int numSeats;
    double price;
    string fuelType;
    string model;
    string color;

public:
    void setMaxSpeed(int speed) 
    { 
        maxSpeed = speed; 
    }
    int getMaxSpeed() 
    { 
        return maxSpeed; 
    }

    void setNumWheels(int wheels) 
    { 
        numWheels = wheels; 
    }
    int getNumWheels() 
    { 
        return numWheels; 
    }

    void setNumDoors(int doors) 
    { 
        numDoors = doors; 
    }
    int getNumDoors() 
    { 
        return numDoors; 
    }

    void setNumSeats(int seats) 
    { 
        numSeats = seats; 
    }
    int getNumSeats() 
    { 
        return numSeats; 
    }

    void setPrice(double p) 
    { 
        price = p; 
    }
    double getPrice() 
    { 
        return price; 
    }

    void setFuelType(string fuel) 
    { 
        fuelType = fuel; 
    }
    string getFuelType() 
    { 
        return fuelType; 
    }

    void setModel(string m) 
    { 
        model = m; 
    }
    string getModel() 
    { 
        return model; 
    }
    string getColor() 
    { 
        return color; 
    }
    void setColor(string c) 
    { 
        color = c; 
    }
    void display()
    {
        cout << "Maximum Speed: " << maxSpeed << " mp/s" << endl;
        cout << "Number of Wheels: " << numWheels << endl;
        cout << "Number of Doors: " << numDoors << endl;
        cout << "Number of Seats: " << numSeats << endl;
        cout << "Price: Pkr " << price << endl;
        cout << "Fuel Type: " << fuelType << endl;
        cout << "Model: " << model << endl;
        cout << "Color: " << color << endl;
    }
};

class Truck : public Vehicles
{
private:
    int loadCapacity;

public:
    void setLoadCapacity(int capacity) 
    { 
        loadCapacity = capacity; 
    }
    int getLoadCapacity() 
    { 
        return loadCapacity; 
    }

    void display()
    {
        Vehicles::display();
        cout << "Load Capacity: " << loadCapacity << " tons" << endl;
    }
};

class Car : public Vehicles
{
private:
    string useType;

public:
    void setUseType(string type) 
    { 
        useType = type; 
    }
    string getUseType() 
    {
        return useType; 
    }

    void display()
    {
        Vehicles::display();
        cout << "Use Type: " << useType << endl;
    }
};
class Motorcycle : public Vehicles
{
private:
    string engineOption;

public:
    void setEngineOption(string option) 
    { 
        engineOption = option; 
    }
    string getEngineOption() 
    { 
        return engineOption; 
    }

    void display()
    {
        Vehicles::display();
        cout << "Engine Option: " << engineOption << endl;
    }
};

int main()
{

    Truck truck;
    truck.setMaxSpeed(220);
    truck.setNumWheels(10);
    truck.setNumDoors(2);
    truck.setNumSeats(2);
    truck.setPrice(5000000);
    truck.setFuelType("Diesel");
    truck.setModel("Volvo");
    truck.setColor("Blue");
    truck.setLoadCapacity(100000);
    truck.display();
    cout << endl;

    Car car;
    car.setMaxSpeed(220);
    car.setNumWheels(4);
    car.setNumDoors(4);
    car.setNumSeats(5);
    car.setPrice(700000);
    car.setFuelType("High Octane");
    car.setModel("Boss Mehran");
    car.setColor("White");
    car.setUseType("Travelling");
    car.display();
    cout << endl;

    Motorcycle motorcycle;
    motorcycle.setMaxSpeed(150);
    motorcycle.setNumWheels(2);
    motorcycle.setNumDoors(0);
    motorcycle.setNumSeats(2);
    motorcycle.setPrice(150000);
    motorcycle.setFuelType("Petrol");
    motorcycle.setModel("Honda CD70");
    motorcycle.setColor("REd");
    motorcycle.setEngineOption("Petrol");
    motorcycle.display();
}