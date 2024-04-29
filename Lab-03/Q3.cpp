#include <iostream>

using namespace std;

double multiplication(int a, int b)
{
    return a * b;
}

double multiplication(double a, double b)
{
    return a * b;
}

double multiplication(int a, double b)
{
    return a * b;
}

double multiplication(double a, int b)
{
    return a * b;
}

double division(int a, int b)
{
    if (b == 0)
    {
        cout << "Error: Division by zero is not allowed." << endl;
    }
    return (double(a)) / b;
}

double division(double a, double b)
{
    if (b == 0)
    {
        cout << "Error: Division by zero is not allowed." << endl;
    }
    return a / b;
}

double division(int a, double b)
{
    if (b == 0)
    {
        cout << "Error: Division by zero is not allowed." << endl;
    }
    return (double(a)) / b;
}

double division(double a, int b)
{
    if (b == 0)
    {
        cout << "Error: Division by zero is not allowed." << endl;
    }
    return a / double(b);
}

int main()
{
    int choice;
    double num1, num2, result;

    while (true)
    {
        cout << "Select an operation:" << endl;
        cout << "1. Multiplication (integers)" << endl;
        cout << "2. Multiplication (doubles)" << endl;
        cout << "3. Multiplication (integer, double)" << endl;
        cout << "4. Multiplication (double, integer)" << endl;
        cout << "5. Division (integers)" << endl;
        cout << "6. Division (doubles)" << endl;
        cout << "7. Division (integer, double)" << endl;
        cout << "8. Division (double, integer)" << endl;
        cout << "9. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 9)
        {
            break;
        }

        cout << "Enter two numbers: " << endl;
        cin >> num1;
        cin >> num2;

        switch (choice)
        {
        case 1:
            result = multiplication(int(num1), int(num2));
            break;
        case 2:
            result = multiplication(num1, num2);
            break;
        case 3:
            result = multiplication(int(num1), num2);
            break;
        case 4:
            result = multiplication(num1, int(num2));
            break;
        case 5:
            result = division(int(num1), int(num2));
            break;
        case 6:
            result = division(num1, num2);
            break;
        case 7:
            result = division(int(num1), num2);
            break;
        case 8:
            result = division(num1, int(num2));
            break;
        default:
            cout << "Invalid choice." << endl;
            continue;
        }

        if (result != -1)
        {
            cout << "Result: " << result << endl;
        }
    }

    return 0;
}
