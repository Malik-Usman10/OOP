#include <iostream>
using namespace std;

int multiplication(int num1, int num2)
{
    return num1 * num2;
}

double multiplication(double num1, double num2) 
{
    return num1 * num2;
}

double multiplication(int num1, double num2) 
{
    return num1 * num2; 
}


double multiplication(double num1, int num2) 
{
    return num1 * (num2);
}

int division(int num1, int num2) 
{
    if (num2 == 0) 
    {
        cout << "Division by Zero is not allowd";
    }
    return num1 / num2;
}

double division(double num1, double num2)
{
    if (num2 == 0) 
    {
        cout << "Division by Zero is not allowd";
    }
    return num1 / num2;
}

double division(int num1, double num2)
{
    if (num2 == 0) 
    {
        cout << "Division by Zero is not allowd";
    }
    return num1 / num2; 
}

double division(double num1, int num2) 
{
    if (num2 == 0) 
    {
        cout << "Division by Zero is not allowd";
    }
    return num1 / (num2); 
}

int main() 
{
    int choice;
    double num1, num2;
    double result;
    do 
    {
        cout << "\nSelect an operation (1-8) or -1 to exit:" << endl;
        cout << "1. Integer multiplication" << endl;
        cout << "2. Double multiplication" << endl;
        cout << "3. Integer division" << endl;
        cout << "4. Double division" << endl;
        cout << "5. Integer multiplied by double" << endl;
        cout << "6. Double multiplied by integer" << endl;
        cout << "7. Integer divided by double" << endl;
        cout << "8. Double divided by integer \n" << endl;

        cout << "Enter the Choice \n";
        cin >> choice;

        if (choice == -1 ) 
        {
            break;
        }

        if (choice < -1 || choice > 8)
        {
            cout << "Invalid input. Please enter a valid choice (1-8) or -1 to exit: ";
        }
        cout << "Enter the Lumber 1: \n";
        cin >> num1;
        cout << "Enter the Lumber 2: \n";
        cin >> num2;
        switch (choice)
        {
            case 1:
                result = multiplication(num1, num2);
                break;
            case 2:
                result = multiplication(num1, num2);
                break;
            case 3:
                result = division(num1, num2);
                break;
            case 4:
                result = division(num1, num2);
                break;
            case 5:
                result = multiplication(num1, num2);
                break;
            case 6:
                result = multiplication(num1, num2);
                break;
            case 7:
                result = division(num1, num2);
                break;
            case 8:
                result = division(num1, num2);
                break;
        }
        cout << "Result: " << result << endl;
    }

    while(choice  != -1);
}