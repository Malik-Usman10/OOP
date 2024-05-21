#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() 
{
    string fileOneName, fileTwoName;
    cout << "Enter the name for the first file: ";
    cin >> fileOneName;
    cout << "Enter the name for the second file: ";
    cin >> fileTwoName;

    ofstream file1(fileOneName);
    ofstream file2(fileTwoName);

    for (int i = 0; i <= 50; i++) 
    {
        file1 << i << endl;
    }
    file1.close();

    for (int i = 51; i <= 100; i++) 
    {
        file2 << i << endl;
    }
    file2.close();

    ifstream readfile1(fileOneName);
    ifstream readfile2(fileTwoName);

    ofstream sumFile("Sum.txt");

    int num1, num2;
    while (readfile1 >> num1 && readfile2 >> num2) 
    {
        int sum = num1 + num2;
        sumFile << sum << endl;
    }

    readfile1.close();
    readfile2.close();
    sumFile.close();

    ifstream readSumFile("Sum.txt");
    string line;
    while (getline(readSumFile, line)) 
    {
        cout << line << endl;
    }
    readSumFile.close();
}