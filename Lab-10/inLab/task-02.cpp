#include <iostream>

using namespace std;

class Circle {
private:
    double radius;
    double area;

public:
    void setRadius(double rad) 
    {
        radius = rad;
    }
    double getRadius()
    {
        return radius;
    }
    double getArea()
    {
        return area;
    }
    void calculateArea()
    {
        area = 3.14 * (radius * radius);
        cout << "The area of the Circle is:  \n" << area << endl;
        cout << "=========================================== \n";
    }
    void display()
    {
        cout << "This is a circle \n";
    }
};

class Cylinder : public Circle{
private:
    double area;
    double height;
  
public:
    double getArea()
    {
        return getArea();
    }
    void setHeight(double h)
    {
        height = h;
    }
    double getHeight()
    {
        return height;
    }
    void display()
    {
        cout << "Cylinder is Circle \n";
    }
    void calculateArea()
    {
        area = 2 * 3.14 * getRadius() * (getRadius() + height);
        cout << "The area of the Cylinder is:  \n" << area << endl;
        cout << "=========================================== \n";
    }

};

class Sphere : public Circle
{
private:
    double area;
public: 
    double getArea()
    {
        return area;
    }
    void calculateArea()
    {
        area = 4 * 3.14 * (getRadius() * getRadius());
        cout << "The area of the Cylinder is: \n" << area << endl;
        cout << "=========================================== \n";
    }
    void display()
    {
        cout << "Sphere is a Cirlcle \n";
    }
};

int main()
{
    Circle circle;
    circle.setRadius(3);
    circle.display();
    circle.calculateArea();

    Sphere sphere;
    sphere.setRadius(3);
    sphere.display();
    sphere.calculateArea();

    Cylinder cylinder;
    cylinder.setHeight(4);
    cylinder.setRadius(3);
    cylinder.display();
    cylinder.calculateArea();
}