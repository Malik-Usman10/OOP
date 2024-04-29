#include <iostream>
#include <vector>
#include <stdexcept>
#include <cmath>

using namespace std;

class Polynomial {
private:
    int *coefficients;
    int size;

public:
    Polynomial() : size(0), coefficients(nullptr) {}
    Polynomial(int size) : size(size)
    {
    coefficients = new int[size];
    Input();
    } 
    Polynomial(const Polynomial &other) : size(other.size) 
    {
        coefficients = new int[size];
        for (int i = 0; i < size; i++) 
        {
            coefficients[i] = other.coefficients[i];
        }
    }

    ~Polynomial() 
    {
        delete[] coefficients;
    }

    void Input() 
    {
        if (coefficients != nullptr) 
        {
            delete[] coefficients;
        }
        coefficients = new int[size];
        cout << "Enter coefficients:\n";
        for (int i = 0; i < size; i++) 
        {
            cout << "Coefficient with x power " << i << ": ";
            cin >> coefficients[i];
        }
    }

    void Display() 
    {
        bool isFirstTerm = true;

        for (int i = size - 1; i >= 0; i++) 
        {
            if (coefficients[i] != 0) 
            {
                if (i > 1) 
                {
                    cout << coefficients[i] <<"x^" << i;
                } 
                else if (i == 1)
                {
                    cout << coefficients[i] <<"x";
                }
                if (i == 0) 
                {
                    cout << coefficients[i];
                }
                isFirstTerm = false;
            }
        }
        cout <<endl;
    }

    int getDegree() 
    {
        return size - 1;
    }

    void setCoefficient(int degree, int coefficient);
    double evaluate(double x) const;
    Polynomial add(const Polynomial &other);
    Polynomial subtract(const Polynomial &other);
    Polynomial multiply(int number);

    Polynomial &operator=(const Polynomial &other);
    Polynomial operator+(const Polynomial &other);
    Polynomial operator-(const Polynomial &other);
    Polynomial operator*(int number);
    bool operator==(const Polynomial &other) const;
    int &operator[](int index);
    int operator()(int x) const;
    operator vector<int>() const;
    friend ostream &operator<<(ostream &out, const Polynomial &poly);
    friend istream &operator>>(istream &in, Polynomial &poly);
};


void Polynomial::setCoefficient(int degree, int coefficient) 
{
    if (degree < 0 || degree >= size) 
    {
        throw out_of_range("Degree out of range");
    }
    coefficients[degree] = coefficient;
}

double Polynomial::evaluate(double x) const 
{
    double result = 0;
    for (int i = 0; i < size; i++) 
    {
        result += coefficients[i] * pow(x, i);
    }
    return result;
}

Polynomial Polynomial::add(const Polynomial &other) 
{
    int newSize = max(size, other.size);
    Polynomial result(newSize);
    for (int i = 0; i < newSize; i++) 
    {
        int coef1 = (i < size) ? coefficients[i] : 0;
        int coef2 = (i < other.size) ? other.coefficients[i] : 0;
        result.coefficients[i] = coef1 + coef2;
    }
    return result;
}

Polynomial Polynomial::subtract(const Polynomial &other) 
{
    int newSize = max(size, other.size);
    Polynomial result(newSize);
    for (int i = 0; i < newSize; ++i) 
    {
        int coef1 = (i < size) ? coefficients[i] : 0;
        int coef2 = (i < other.size) ? other.coefficients[i] : 0;
        result.coefficients[i] = coef1 - coef2;
    }
    return result;
}

Polynomial Polynomial::multiply(int number) 
{
    Polynomial result(size);
    for (int i = 0; i < size; ++i) 
    {
        result.coefficients[i] = coefficients[i] * number;
    }
    return result;
}

Polynomial &Polynomial::operator=(const Polynomial &other) 
{
    if (this != &other) 
    {
        if (coefficients != nullptr) 
        {
            delete[] coefficients;
        }
        size = other.size;
        coefficients = new int[size];
        for (int i = 0; i < size; ++i) 
        {
            coefficients[i] = other.coefficients[i];
        }
    }
    return *this;
}

Polynomial Polynomial::operator+(const Polynomial &other) 
{
    return add(other);
}

Polynomial Polynomial::operator-(const Polynomial &other) 
{
    return subtract(other);
}

Polynomial Polynomial::operator*(int number) 
{
    return multiply(number);
}

bool Polynomial::operator==(const Polynomial &other) const 
{
    if (size != other.size) 
    {
        return false;
    }
    for (int i = 0; i < size; i++) 
    {
        if (coefficients[i] != other.coefficients[i]) 
        {
            return false;
        }
    }
    return true;
}


int &Polynomial::operator[](int index) 
{
    if (index < 0 || index >= size) 
    {
        throw out_of_range("Index out of range");
    }
    return coefficients[index];
}


int Polynomial::operator()(int x) const 
{
    return evaluate(x);
}

Polynomial::operator vector<int>() const 
{
    vector<int> coeffs(coefficients, coefficients + size);
    return coeffs;
}

ostream &operator<<(ostream &out, const Polynomial &poly) 
{
    bool isFirstTerm = true;
    for (int i = poly.size - 1; i >= 0; i--) 
    {
        if (poly.coefficients[i] != 0)
        {
            if (!isFirstTerm) 
            {
                out << " + ";
            }
            if (i > 1) 
            {
                out << poly.coefficients[i] <<"x^" << i;
            } 
            else if (i == 1)
            {
                out << poly.coefficients[i] <<"x";
            }
            if (i == 0) 
            {
                 out << poly.coefficients[i];
            }
            isFirstTerm = false;
        }
    }
    return out;
}

istream &operator>>(istream &in, Polynomial &poly) 
{
    cout << "Enter the size of the polynomial: ";
    in >> poly.size;
    poly.coefficients = new int[poly.size];
    poly.Input();
    return in;
}

void menuFunc(Polynomial poly1, Polynomial poly2)
{
    int i;
    do 
    {
        cout << "\n_____________________________________________________________________________________\n";
        cout << "\n1: Display Coefficient ";
        cout << "\n2: Get Degree ";
        cout << "\t\t\t3: Set Coefficient For Polynomials \n";
        cout << "4: Evaluate For Given Value ";
        cout << "\t5: Add the Two Polynomials \n";
        cout << "6: Subtract Two Polynomials ";
        cout << "\t7: Multiply Two Polynomials \n";
        cout << "8: Check Equality of Polynomials \n";
        cout << "9: Output the Coefficient of Polynomials \n";
        cout << "10: Exit the Program \n";

        cout << "\nEnter the Number of Function you Wanna Perform ";
        cin >> i;
        switch (i) 
        {
            case 1:
            {
                cout << "Here are the Polynomials \n";
                cout << "Polynomial 1: " << poly1 << endl;
                cout << "Polynomial 2: " << poly2 << endl;
                break;
            }
            case 2:
            {
                cout << "Degree of Polynomial 1: " << poly1.getDegree() << endl;
                cout << "Degree of Polynomial 1: " << poly2.getDegree() << endl;
                break;
            }
            case 3:
            {
                int degree, coefficient;
                cout << "Enter the degree of Polynomial 1 for which you wanna set coefficient:   ";
                cin >> degree;
                cout << "Enter the Coofficient For Polynomial 1:   ";
                cin >> coefficient;
                poly1.setCoefficient(degree, coefficient);
                cout << "Enter the degree of Polynomial 2 for which you wanna set coefficient:   ";
                cin >> degree;
                cout << "Enter the Coofficient For Polynomial 2:   ";
                cin >> coefficient;
                poly2.setCoefficient(degree, coefficient);
                break;
            }
            case 4:
            {
                int value;
                cout << "Enter the value of X for Polynomial 1:  ";
                cin >> value;
                cout << "Evaluation of Polynomial 1:  " << poly1(value) << endl;
                cout << "Enter the value of X for Polynomial 2: ";
                cin >> value;
                cout << "Evaluation of Polynomial 1:  " << poly2(value) << endl;
                break;
            }
            case 5:
            {
                cout << "Polynomial 1 + Polynomial 2: " << poly1 + poly2 << endl;
                break;
            }  
            case 6:
            {
                Polynomial subtract = poly1 - poly2;
                cout << "Polynomial 1 - Polynomial 2: " << subtract << endl;
                break;
            }
            case 7:
            {
                int value;
                cout << "Enter the value of Multiplier for Polynomial 1:  ";
                cin >> value;
                Polynomial multiply = poly1 * value;
                cout << "Polynomial 1 *" << value << " = " << multiply << endl;
                cout << "Enter the value of Multiplier for Polynomial 2:  ";
                cin >> value;
                Polynomial multiplyTwo = poly1 * value;
                cout << "Polynomial 1 *" << value << " = " << multiplyTwo << endl;
                break;
            }
            case 8:
            {
                cout << "Polynomial 1 and Polynomial 2 are " << (poly1 == poly2 ? "equal" : "not equal") << endl;
                break;
            }
            case 9:
            {
                cout << "\nCoefficients of Polynomial 1: \n";
                vector<int> coeffs = poly1;
                for (int coef : coeffs) 
                {
                    cout << coef << " ";
                }
                cout << "\nCoefficients of Polynomial 2: \n";
                vector<int> coeffsTwo = poly2;
                for (int coeff : coeffsTwo) 
                {
                    cout << coeff << " ";
                }
                break;
            }
            case 10:
            {
                break;
            }
            default:
                break;
        }
    }
    while (i != 10);
}

int main() 
{
    Polynomial poly1, poly2;
    cout << "Enter First Polynomial:\n";
    cin >> poly1;
    cout << "Enter SecondPolynomial 2:\n";
    cin >> poly2;

    menuFunc(poly1, poly2);

    cout << endl;
}

