#include <iostream>

using namespace std;

float countBill(int units) 
{
    float bill = 0;
    int remUnits = units;
    int rate = 35;


    if (remUnits >= 100) 
    {
        bill +=100 * 25;
        remUnits -= 100;
    }
    if (remUnits >= 50) 
    {
        bill += 50 * 30;
        remUnits -= 50;
    }
    while (remUnits >= 50) 
    {
        bill += 50 * rate;
        remUnits -= 50;
        rate += 5;
    }
    return bill;
}
int main() 
{
    int units;
    cout << "Enter the consumed Units: ";
    cin >> units;

    float totalBill = countBill(units);
    cout << "Total bill for " << units << " units: $" << totalBill << endl;
    return 0;
}
