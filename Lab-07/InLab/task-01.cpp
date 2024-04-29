#include <iostream>
#include <cmath>
using namespace std;

class Complex
{
private:
    double realPart;
    double imaginaryPart;

public:
    Complex() : realPart(0), imaginaryPart(0) {}

    Complex(double real, double imag) : realPart(real), imaginaryPart(imag) {}

    void setRealPart(double real)
    {
        realPart = real;
    }

    double getRealPart() const
    {
        return realPart;
    }

    void setImaginaryPart(double imag)
    {
        imaginaryPart = imag;
    }

    double getImaginaryPart() const
    {
        return imaginaryPart;
    }

    void display() const
    {
        cout << realPart << " + " << imaginaryPart << "i";
    }

    Complex operator+(const Complex &c) const
    {
        Complex sum;
        sum.realPart = realPart + c.realPart;
        sum.imaginaryPart = imaginaryPart + c.imaginaryPart;
        return sum;
    }
    Complex operator-(const Complex &c) const   //adreesss 
    {
        Complex sub;
        sub.realPart = realPart - c.realPart;
        sub.imaginaryPart = imaginaryPart - c.imaginaryPart;
        return sub;
    }
    Complex operator*(const Complex &c) const
    {
        Complex mul;
        mul.realPart = realPart * c.realPart;
        mul.imaginaryPart = imaginaryPart * c.imaginaryPart;
        return mul;
    }
    Complex operator/(const Complex &c) const
    {
        Complex div;
        div.realPart = realPart / c.realPart;
        div.imaginaryPart = imaginaryPart / c.imaginaryPart;
        return div;
    }
    // friend ostream operator <<(ostream o,const Complex &c);
    // friend istream operator >>(istream i,const Complex &c);

    bool operator ==(const Complex &c) 
    {
        Complex equal;
        bool result =false;
        if (equal.imaginaryPart == c.imaginaryPart || equal.realPart == c.realPart)
        {
            result =true;
        }
        else 
        {
            return false;
        }
    }
    bool operator !=(const Complex &c) const
    {
        Complex notEqual;
        bool result =false;
        if (notEqual.imaginaryPart != c.imaginaryPart || notEqual.realPart != c.realPart)
        {
            result =true;
        }
        else
        { 
            return false;
        }
    }
    bool operator >=(const Complex &c) const
    {
        Complex greaterthan;
        bool result =false;
        if (pow(greaterthan.realPart,2))
        {
            result = true;
        }
        else 
        {
            return false;
        }
    }
    
};

int main()
{
    double real1, imag1, real2, imag2;

    cout << "Enter real part of first complex number: ";
    cin >> real1;
    cout << "Enter imaginary part of first complex number: ";
    cin >> imag1;

    cout << "Enter real part of second complex number: ";
    cin >> real2;
    cout << "Enter imaginary part of second complex number: ";
    cin >> imag2;

    Complex c1(real1, imag1);
    Complex c2(real2, imag2);

    cout << "Complex number 1: ";
    c1.display();
    cout << endl;

    cout << "Complex number 2: ";
    c2.display();
    cout << endl;

    Complex sum = c1 + c2;
    Complex subtract = c1 - c2;
    Complex multiply = c1 * c2;
    Complex division = c1 / c2;
    // Complex equal = c1 == c2;
    // Complex notEqual = c1 != c2;
    // Complex greaterthan = c1 >= c2;

    cout << "Sum of complex numbers: ";
    sum.display();
    cout << endl;
    
    cout << "Subtraction of complex numbers: ";
    subtract.display();
    cout << endl;

    cout << "Multiplication of complex numbers: ";
    multiply.display();
    cout << endl;

    cout << "Division of complex numbers: ";
    division.display();
    cout << endl;
    // cout << "EQUAL of complex numbers: ";
    // equal.display();
    // cout << "Not Equal of complex numbers: ";
    // notEqual.display();
    // cout << "Greater than complex numbers: ";
    // greaterthan.display();




    cout << endl;

}
