#include <iostream>
using namespace std;

class Complex {
private:
    double real;
    double imaginary;

public:
    Complex(double r = 0.0, double i = 0.0) : real(r), imaginary(i) {}

    void print() const 
    {
        cout << real;
        if (imaginary >= 0) 
        {
            cout << " + " << imaginary << "i";
        }
        else 
        {
            cout << " - " << -imaginary << "i";
        }
    }

    friend Complex add(const Complex &c1, const Complex &c2);
};

Complex add(const Complex &c1, const Complex &c2) {
    return Complex(c1.real + c2.real, c1.imaginary + c2.imaginary);
}

int main() {
    double realNum1, imaginaryNum1, realNum2, imaginaryNum2;

    cout << "Enter real and imaginary parts of the first number: ";
    cin >> realNum1 >> imaginaryNum1;
    Complex first(realNum1, imaginaryNum1);

    cout << "Enter real and imaginary parts of the second number: ";
    cin >> realNum2 >> imaginaryNum2;
    Complex second(realNum2, imaginaryNum2);


    Complex result = add(first, second);

    cout << "First number is: ";
    first.print();
    cout << endl << "Second number is ";
    second.print();
    cout << endl << "Result is ";
    result.print();
    cout << endl;
}
