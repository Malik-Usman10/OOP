#include <iostream>
#include <algorithm> 

using namespace std;

class Fraction {
private:
    int numerator;
    int denominator;

public:
    Fraction() : numerator(0), denominator(1) {} 
    Fraction(int num, int denom) : numerator(num), denominator(denom) {} 
    Fraction(const Fraction& other) : numerator(other.numerator), denominator(other.denominator) {} 

    void simplify() const 
    {
        int gcd = __gcd(numerator, denominator);
        int num = numerator / gcd;
        int denom = denominator / gcd;
        cout << num << "/" << denom;
    }
    void setNumerator(int num) 
    { 
        numerator = num; 
    }
    void setDenominator(int denom) 
    { 
        denominator = denom; 
    }
    int getNumerator() const 
    {
        return numerator; 
    }
    int getDenominator() const 
    { 
        return denominator; 
    }

    void display() const 
    {
        simplify();
    }

    Fraction operator+(const Fraction& other) const 
    {
        int newNumerator = numerator * other.denominator + other.numerator * denominator;
        int newDenominator = denominator * other.denominator;
        return Fraction(newNumerator, newDenominator);
    }

    Fraction operator-(const Fraction& other) const 
    {
        return Fraction(numerator * other.denominator - other.numerator * denominator,
                        denominator * other.denominator);
    }

    Fraction operator*(const Fraction& other) const 
    {
        return Fraction(numerator * other.numerator, denominator * other.denominator);
    }

    Fraction operator/(const Fraction& other) const 
    {
        return Fraction(numerator * other.denominator, denominator * other.numerator);
    }

    Fraction operator!() const 
    {
        int newNumerator = -numerator;                              
        int newDenominator = - denominator;                       
        return Fraction(newNumerator, newDenominator);
    }

    Fraction operator~() const 
    {
        return Fraction(denominator, numerator);
    }

    Fraction operator++() 
    {
        numerator++;
        denominator++;
        return *this;
    }

    Fraction operator--() 
    {
        numerator--;
        denominator--;            
        return *this;
    }
    friend ostream& operator<<(ostream& os, const Fraction& fraction) 
    {
        os << fraction.numerator << "/" << fraction.denominator;
        return os;
    }

    friend istream& operator>>(istream& is, Fraction& fraction)
     {
        is >> fraction.numerator >> fraction.denominator;
        return is;
    }
};

int main() {
    int num1, denom1, num2, denom2;
    cout << "Enter the numerator of First Fraction: ";
    cin >> num1;
    cout << "Enter the denominator of First Fraction: ";
    cin >> denom1;
    cout << "Enter the numerator of Second Fraction: ";
    cin >> num2;
    cout << "Enter the denominator of Second Fraction: ";
    cin >> denom2;
    Fraction f1(num1, denom1);
    Fraction f2(num2, denom2);
    Fraction sum = f1 + f2;
    Fraction difference = f1 - f2;
    Fraction product = f1 * f2;
    Fraction quotient = f1 / f2;
    Fraction negationOne = !f1;
    Fraction negationTwo = !f1;
    Fraction inversionOne = ~f1;
    Fraction inversionTwo = ~f2;
    Fraction incrementOne = ++f1;
    Fraction incrementTwo = ++f2;
    Fraction decrementOne = --f1;
    Fraction decrementTwo = --f2;

    cout << "\nSum: ";
    sum.display(); 
    cout << "\nDifference: ";
    difference.display();
    cout << "\nProduct: ";
    product.display();
    cout << "\nQuotient: ";
    quotient.display();
    cout << "\nFraction One Negation: " << negationOne;
     cout << "\nFraction Two Negation: " << negationTwo;
    cout << "\nFraction One Inversion: ";
    inversionOne.display();
    cout << "\nFraction Two Inversion: ";
    inversionTwo.display();
    cout << "\nFraction One Increment: ";
    incrementOne.display();
    cout << "\nFraction Two Increment: ";
    incrementTwo.display();
    cout << "\nFraction One Decrement: ";
    decrementOne.display();
    cout << "\nFraction Two Decrement: ";
    decrementTwo.display();
    cout << "\n";
}
