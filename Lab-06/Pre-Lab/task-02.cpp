#include <iostream>
using namespace std;

bool isPrime(int num) 
{
    if (num <= 1)
    {
       return false;
    }
    for (int i = 2; i * i <= num; ++i) 
    {
        if (num % i == 0)
        {
            return false;
        }
    }
    return true;
}

class Number {
private:
    int value;
public:
    Number(int val) : value(val) {}
    friend void expressInSumOfPrimes(int val);
};

void expressInSumOfPrimes(int number) 
{
    bool found = false;
    for (int i = 2; i <= number / 2; i++) 
    {
        if (isPrime(i) && isPrime(number - i)) 
        {
            cout << number << " = " << i << " + " << (number - i) << endl;
            found = true;
        }
    }
    if (!found) 
    {
        cout << number << " cannot be expressed as the sum of two prime numbers." << endl;
    }
}

int main() {
    int num;
    cout << "Input a positive integer: ";
    cin >> num;

    Number number(num);
    expressInSumOfPrimes(num);

    return 0;
}
