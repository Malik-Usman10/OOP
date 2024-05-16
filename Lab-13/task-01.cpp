#include <iostream>
#include <fstream>
#include <map>
#include <algorithm>
using namespace std;

int main() 
{
    ofstream outFile("task-01.txt");
    outFile << "This is the task-01 of the Lab 13. This is the first task of the Lab 13. The task is for finding the most repetitive words in the file.";
    outFile.close();

    ifstream inFile("task-01.txt");
    string word;
    map<string, int> wordCount;

    while (inFile >> word) 
    {
        transform(word.begin(), word.end(), word.begin(), ::tolower);
        wordCount[word]++;
    }
    inFile.close();

    int maxCount = 0;
    for (const auto& pair : wordCount) 
    {
        if (pair.second > maxCount) 
        {
            maxCount = pair.second;
        }
    }
    cout << "Most repititive word with " << maxCount << " occurrences:" << endl;
    for (const auto& pair : wordCount) 
    {
        if (pair.second == maxCount) 
        {
            cout << pair.first << endl;
        }
    }
}