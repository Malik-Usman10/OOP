#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> input() {
    int numElements;
    cout << "Enter the number of elements: ";
    cin >> numElements;

    vector<int> v(numElements);
    cout << "Enter the elements: ";
    for (int i = 0; i < numElements; ++i)
    {
        cin >> v[i];
    }

    return v;
}

void display(const vector<int>& v) {
    cout << "Vector: ";
    for (int element : v) {
        cout << element << " ";
    }
    cout << endl;
}

int getMin(const vector<int>& v) 
{
    int minElement = v[0];
    for (int element : v) 
    {
        minElement = min(minElement, element);
    }

    return minElement;
}

int getMax(const vector<int>& v) 
{
    int maxElement = v[0];
    for (int element: v) 
    {
        maxElement = max(maxElement, element);
    }

    return maxElement;
}

int countElements(const vector<int>& v) 
{
    return v.size();
}

void sortElements(vector<int>& v, string order) 
{
    if (order == "a") 
    {
        sort(v.begin(), v.end());
    } 
    else if (order == "d") 
    {
        sort(v.begin(), v.end(), greater<int>());
    } else 
    {
        cout << "Invalid order. Please enter 'a: ascending' or 'd: descending'." << endl;
    }
}

int main() {
    vector<int> numbers = input();
    display(numbers);

    int minimum = getMin(numbers);
    cout << "Minimum element: " << minimum << endl;

    int maximum = getMax(numbers);
    cout << "Maximum element: " << maximum << endl;

    int count = countElements(numbers);
    cout << "Number of elements: " << count << endl;

    string sortOrder;
    cout << "Enter sort order (a: ascending/d: descending): ";
    cin >> sortOrder;
    sortElements(numbers, sortOrder);
    display(numbers);

    return 0;
}
