#include <iostream>

using namespace std;
int countBill(int units) 
{
    int bill = 0;
    int remaining_units = units;
    int rate = 35;

    if (remaining_units >= 100) 
    {
        bill = bill + (100 * 25);
        remaining_units -= 100;
    }

    if (remaining_units >= 50) 
    {
        bill = (50 * 30) + bill;
        remaining_units -= 50;
    }

    while (remaining_units >= 50) 
    {
        bill = (50 * rate) + bill;
        remaining_units -= 50;
        rate += 5;
    }
    return bill;
}

int main() 
{
    int units;
    cout << "Enter the number of units consumed: ";
    cin >> units;

    int total_bill = countBill(units);
    cout << "Total bill for " << units << " units: Pkr" << total_bill << endl;
}
