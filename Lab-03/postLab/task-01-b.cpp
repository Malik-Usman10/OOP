#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

vector<string> Input() 
{
    int numStrings;
    cout << "Enter the number of strings: ";
    cin >> numStrings;

    vector<string> v(numStrings);
    cout << "Enter the strings: ";
    for (int i = 0; i < numStrings; i++) 
    {
        cin >> v[i];
    }

    return v;
}

void display(const vector<string>& v) 
{
    cout << "Vector: ";
    for (const string& element : v) 
    {
        cout << element << " ";
    }
    cout << endl;
}

vector<string> changeCaps(const vector<string>& v) 
{
    vector<string> newV(v.size());
    for (int i = 0; i < v.size(); i++) 
    {
        newV[i] = char(toupper(v[i][0])) + v[i].substr(1);

    }
    return newV;
}

vector<string> isNumberString(const vector<string>& v) 
{
    vector<string> newV;
    for (const string& element : v) 
    {
        if (any_of(element.begin(), element.end(), ::isdigit)) 
        {
            newV.push_back(element);
        }
    }
    return newV;
}

int main() {
        vector<string> originalStrings = Input();


        cout << "Original strings:" << endl;
        display(originalStrings);

        vector<string> capitalizedStrings = changeCaps(originalStrings);
        cout << "Capital strings:" << endl;
        display(capitalizedStrings);


        vector<string> numberStrings = isNumberString(originalStrings);
        cout << "Strings with Numbers:" << endl;
        display(numberStrings);

    return 0;
}
