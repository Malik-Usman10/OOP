#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

void loadFromFileAndEdit() 
{
    string filename = "Data.txt";
    ifstream inFile(filename);
    stringstream buffer;

    if (inFile) 
    {
        buffer << inFile.rdbuf();
        inFile.close();
        cout << "Current contents of the file:" << endl;
        cout << buffer.str() << endl;
    } 
    else 
    {
        cout << "No file found. New file will created." << endl;
    }

    cout << "Enter new data type 'exit' to save & close:" << endl;
    string inputLine;
    string userData;

    while (getline(cin, inputLine)) 
    {
        if (inputLine == "exit") 
        {
            break;
        }
        userData += inputLine + "\n";
    }

    ofstream outFile(filename, ios::trunc); 
    if (!outFile) 
    {
        cerr << "Error opening file for writing." << endl;
        return;
    }
    outFile << buffer.str() << userData;
    outFile.close();
    cout << "Data saved and editor closed." << endl;
}

int main() 
{
    loadFromFileAndEdit();
}