#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

int main() 
{
    ofstream outFile("Numbers.txt", ios::app);
    if (!outFile.is_open()) 
    {
        cerr << "Failed to open file." << endl;
        return 1;
    }
    int number;
    int sum = 0;
    string line;

    while (true) 
    {
        cout << "Enter a number (-1 to stop): ";
        cin >> number;
        if (number == -1) 
        {
            break;
        }
        outFile << number << ", ";
        outFile.flush(); 
        sum += number;
        cout << "Current sum: " << sum << endl;
    }
    outFile.close();
}