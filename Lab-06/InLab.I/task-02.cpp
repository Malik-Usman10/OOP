#include <iostream>
using namespace std;


class RECTANGLE;


class Square {
private:
    int side;
public:
    Square(int s) : side(s) {}
    friend class RECTANGLE; 
};


class RECTANGLE {
private:
    int height;
    int width;
public:
    RECTANGLE(int h, int w) : height(h), width(w) {}
    int area(const Square& s) { 
        return s.side * s.side;
    }
};

int main() {
    int side, height, width;

    cout << "Enter side of square: ";
    cin >> side;

    Square square(side);

    cout << "Enter height of Rectangle: ";
    cin >> height;

    cout << "Enter width of Rectangle: ";
    cin >> width;

    RECTANGLE RECTANGLE(height, width);

    
    cout << "Area of square: " << RECTANGLE.area(square) << endl;

    return 0;
}
