#include <iostream>
#include <vector>
using namespace std;
class Shape 
{
public:
    virtual ~Shape() {}
    virtual void calculateArea() = 0;
    virtual void display() = 0;
};
class Circle : public Shape {
private:
    double radius;
    double area;
public:
    Circle(double r) : radius(r), area(0) {}
    void calculateArea() override 
    {
        area = 3.14 * radius * radius;
    }
    void display() override 
    {
        cout << "Radius of Circle is:  " << radius << ", And Area is: " << area << endl;
    }
};
class Square : public Shape 
{
private:
    double side;
    double area;

public:
    Square(double s) : side(s), area(0) {}
    void calculateArea() override 
    {
        area = side * side;
    }
    void display() override 
    {
        cout << "Side of Square is: " << side << ", And Area is: " << area << endl;
    }
};
class Triangle : public Shape
{
private:
    double base;
    double height;
    double area;
public:
    Triangle(double b, double h) : base(b), height(h), area(0) {}
    void calculateArea() override
    {
        area = 0.5 * base * height;
    }
    void display() override 
    {
        cout << "Base of Triangle is: " << base << ", Height of Triangle is: " << height << ", And Area is: " << area << endl;
    }
};
class ShapeContainer 
{
private:
    vector<Shape*> shapes;
public:
    ~ShapeContainer() 
    {
        for (Shape* shape : shapes) 
        {
            delete shape;
        }
    }
    void addShape(Circle* circle) 
    {
        circle->calculateArea();
        shapes.push_back(circle);
    } 
    void addShape(Square* square) 
    {
        square->calculateArea();
        shapes.push_back(square);
    }
    void addShape(Triangle* triangle) 
    {
        triangle->calculateArea();
        shapes.push_back(triangle);
    }
    void displayAllShapes() 
    {
        for (Shape* shape : shapes) 
        {
            shape->display();
        }
    }
};
int main()
{
    ShapeContainer container;
    int choice;
    double radius, side, base, height;
    while (true) 
    {
        cout << "1. Add Circle\n2. Add Square\n3. Add Triangle\n4. Display All Shapes\n5. Exit\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter radius of the circle: ";
                cin >> radius;
                container.addShape(new Circle(radius));
                break;
            case 2:
                cout << "Enter side of the square: ";
                cin >> side;
                container.addShape(new Square(side));
                break;
            case 3:
                cout << "Enter base and height of the triangle: ";
                cin >> base >> height;
                container.addShape(new Triangle(base, height));
                break;
            case 4:
                container.displayAllShapes();
                break;
            case 5:
                return 0;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }
}