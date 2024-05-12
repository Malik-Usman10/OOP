#include <iostream>

using namespace std;

class Animal
{
private:
    string name;
public:
    void setName(string Name)
    {
        name = Name;
    }
    string getName()
    {
        return name;
    }
    Animal(){}
    Animal(string name) : name("") 
    {
        cout << "Constructor of Animal Class Invoked \n";
    }
    ~Animal()
    {
        cout << "The Destructor of Animal Class Called \n";
    }
};

class Mammal: public Animal
{
private:
    int numLegs;
public:
    Mammal(){}
    Mammal(int numLegs, string name) : Animal (name)
    {
        cout << "The contructor of Mammal Class Invoked \n";
    }
    ~Mammal () 
    {
        cout << "The Destructor  of  Mammal Class Invoked \n";
    }
};

class Bird: public Animal{
private:
    int wingSpan;
public: 
    Bird(){}
    Bird(int wingSpan, string name) : Animal(name)
    {
        cout << "The contructor of Bird Class Invoked \n";
    }
    ~Bird()
    {
        cout << "The destructor of Bird Class Invoked \n";
    }
};
class Dog: public Mammal
{
private:
    string breed;
public: 
    Dog(){}
    Dog(string breed, int numLegs, string name) : Mammal(numLegs, name)
    {  
        cout << "The constructor of the Dog Class Invoked \n";
    }
    ~Dog()
    {
        cout << "The destructor of Dog Class Invoked \n";
    }

};
class Cat: public Mammal
{
private:
    string color;
public:
    Cat(){}
    Cat(string name, int numLegs, string color) : Mammal(numLegs, name)
    {
        cout << "The constructor of the Cat class Invoked \n";
    }
    ~Cat()
    {
        cout << "The destructor of the Cat class Invoked \n";
    }
};

int main()
{
    Mammal m = Mammal(4, "Horse");
    Bird b = Bird(2, "Pigeon");
    Dog d = Dog("Husky", 4, "Spoidermon");
    Cat c = Cat("Cato", 4, "Brown");
}
