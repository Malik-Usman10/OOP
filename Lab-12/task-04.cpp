#include <iostream>
using namespace std;
class Animal 
{
public:
    virtual void make_sound() 
    {
        cout << "The animal makes a sound." << endl;
    }
    virtual ~Animal() {}
};

class Cat : public Animal 
{
public:
    void make_sound() override 
    {
        cout << "Meow Meow" << endl;
    }
};
class Dog : public Animal 
{
public:
    void make_sound() override 
    {
        cout << "Woof" << endl;
    }
};
class Bird : public Animal 
{
public:
    void make_sound() override 
    {
        cout << "Chirp" << endl;
    }
};
int main() 
{
    Animal* animals[3];
    animals[0] = new Cat();
    animals[1] = new Dog();
    animals[2] = new Bird();
    for (int i = 0; i < 3; i++) 
    {
        animals[i]->make_sound();
    }
    for (int i = 0; i < 3; i++) 
    {
        delete animals[i];
    }
}