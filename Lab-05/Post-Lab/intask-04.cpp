#include <iostream>

using namespace std;

bool isPrime(int num, int div = 2) 
{
    if (num <= 2) 
    {
        return (num == 2);
    }
    if (num % div == 0) 
    {
        return false;
    }

    if (div * div > num) 
    {
        return true;
    }
    return isPrime(num, div + 1);
}

void PrintPrimes(int count, int current = 2) 
{
    if (count <= 0)
    {
        return;
    }
    if (isPrime(current)) 
    {
        cout << current << " ";
        PrintPrimes(count - 1, current + 1);
    } 
    else 
    {
        PrintPrimes(count, current + 1);
    }
}

int main() {
    int numPrimes;
    cout << "Enter the number of prime numbers you want: ";
    cin >> numPrimes;
    PrintPrimes(numPrimes);
    cout << "\n";
}
