#include <iostream>
using namespace std;

class Shape
{
private:
    double length;
    double width;

public:
    void setLength(double len) 
    { 
        length = len; 
    }
    double getLength() 
    { 
        return length; 
    }

    void setWidth(double w) 
    { 
        width = w; 
    }
    double getWidth() 
    { 
        return width; 
    }
    void display()
    {
        cout << "Length: " << length << endl;
        cout << "Width: " << width << endl;
    }
};

class Rectangle : public Shape
{
private:
    double length;
    double width;

public:
    void setLength(double len) 
    { 
        length = len; 
    }
    double getLength() 
    { 
        return length; 
    }

    void setWidth(double w) 
    { 
        width = w; 
    }
    double getWidth() 
    { 
        return width; 
    }
    void displayArea()
    {
        double area = length * width;
        cout << "Area of Rectangle: " << area << endl;
    }
};

class Square : public Shape
{
private:
    double length;

public:
    void setLength(double len) 
    { 
        length = len; 
    }
    double getLength() 
    { 
        return length; 
    }
    void displayArea()
    {
        double area = length * length;
        cout << "Area of the Square: " << area << endl;
    }
};

int main()
{

    Rectangle rect;
    rect.setLength(5.0);
    rect.setWidth(3.0);
    rect.display();
    rect.displayArea();
    cout << endl;

    Square sq;
    sq.setLength(4.0);
    sq.display();
    sq.displayArea();
}