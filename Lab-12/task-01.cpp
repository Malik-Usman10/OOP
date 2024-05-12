#include <iostream>

using namespace std;
class Operation 
{
public:
    virtual ~Operation() {}
    virtual double calculate(double num1, double num2) = 0;
};

class Addition : public Operation 
{
public:
    double calculate(double num1, double num2) override 
    {
        return num1 + num2;
    }
};
class Subtraction : public Operation {
public:
    double calculate(double num1, double num2) override 
    {
        return num1 - num2;
    }
};
class Multiplication : public Operation 
{
public:
    double calculate(double num1, double num2) override 
    {
        return num1 * num2;
    }
};
class Division : public Operation 
{
public:
    double calculate(double num1, double num2) override 
    {
        if (num2 == 0) 
        {
            cerr << "Error: Division by zero\n";
            return 0.0;
        }
        return num1 / num2;
    }
};
int main() 
{
    char choice;
    double num1, num2;
    Operation* operation;

    do  
    {
        cout << "Choose operation {+, -, *, /} or 'q' to quit: ";
        cin >> choice;
        if (choice == 'q') 
        {
            cout << "Exiting...\n";
            break;
        }
        cout << "Enter two numbers: ";
        cin >> num1 >> num2;
        switch (choice) 
        {
            case '+':
                operation = new Addition();
                break;
            case '-':
                operation = new Subtraction();
                break;
            case '*':
                operation = new Multiplication();
                break;
            case '/':
                operation = new Division();
                break;
            default:
                cerr << "Invalid operation\n";
                continue;
        }
        double result = operation->calculate(num1, num2);
        cout << "Result: " << result << endl;
        delete operation;
    } while (true);
}
