#include <iostream>
#include <string>
using namespace std;

class Mammals {
private:
    int numLegs;
    int numTeeth;
    string habitat;

public:
    void printMammal() 
    {
        cout << "I'm a mammal." << endl;
    }
    void setAttributes(int legs, int teeth, string hab) 
    {
        numLegs = legs;
        numTeeth = teeth;
        habitat = hab;
    }

    void displayAttributes() 
    {
        cout << "Number of Legs: " << numLegs << endl;
        cout << "Number of Arms: " << numTeeth << endl;
        cout << "Habitat: " << habitat << endl;
    }
};

class MarineAnimals 
{
private:
    int numFins;
    int maxDepth;
    string habitat;

public:
    void printMarineAnimal() 
    {
        cout << "I'm, a marine animal." << endl;
    }

    void setAttributes(int fins, int depth, string hab) 
    {
        numFins = fins;
        maxDepth = depth;
        habitat = hab;
    }

    void displayAttributes() 
    {
        cout << "Number of Fins: " << numFins << endl;
        cout << "Maximum Depth: " << maxDepth << " meters" << endl;
        cout << "Habitat: " << habitat << endl;
    }
};

class MammalMarine : public Mammals, public MarineAnimals 
{
public:
    void display() 
    {
        Mammals::printMammal();
        MarineAnimals::printMarineAnimal();
        Mammals::setAttributes(4, 50, "Ocean");
        Mammals::displayAttributes();
        MarineAnimals::displayAttributes();
    }

    void makeSound() 
    {
        cout << "The whale sings." << endl;
    }
};

class Lion : public Mammals 
{
public:
    void display() 
    {
        printMammal();
        setAttributes(4, 30, "Savanna");
        displayAttributes();
    }

    void makeSound() 
    {
        cout << "The lion roars." << endl;
    }
};

class Dolphin : public MarineAnimals 
{
public:
    void display() 
    {
        printMarineAnimal();
        setAttributes(2, 300, "Ocean");
        displayAttributes();
    }

    void makeSound() 
    {
        cout << "The dolphin clicks and whistles." << endl;
    }
};

class Cow : public Mammals 
{
public:
    void display() {
        printMammal();
        setAttributes(4, 32, "Grassland");
        displayAttributes();
    }

    void makeSound() 
    {
        cout << "The cow moos." << endl;
    }
};

class Shark : public MarineAnimals 
{
public:
    void display() 
    {
        printMarineAnimal();
        setAttributes(2, 1000, "Ocean");
        displayAttributes();
    }

    void makeSound() 
    {
        cout << "The shark growls." << endl;
    }
};

int main() 
{
    Lion lion;
    lion.display();
    lion.makeSound();
    cout << endl;

    Dolphin dolphin;
    dolphin.display();
    dolphin.makeSound();
    cout << endl;

    MammalMarine whale;
    whale.display();
    whale.makeSound();
    cout << endl;

    Cow cow;
    cow.display();
    cow.makeSound();
    cout << endl;

    Shark shark;
    shark.display();
    shark.makeSound();
}