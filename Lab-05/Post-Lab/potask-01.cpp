#include <iostream>
#include <queue>

using namespace std;

int main() 
{
    int start, end;

    cout << "Enter the start of the range: ";
    cin >> start;

    cout << "Enter the end of the range: ";
    cin >> end;

    queue<int> rangeNum;

    for (int i = start; i <= end; i++) 
    {
        rangeNum.push(i);
    }

    queue<int> oddNumbers;
    while (!rangeNum.empty()) {
        int num = rangeNum.front();
        rangeNum.pop();
        if (num % 2 != 0) {
            oddNumbers.push(num);
        }
    }

    cout << "Queue with odd Numbers from Range: ";
    while (!oddNumbers.empty()) 
    {
        cout << oddNumbers.front() << " ";
        oddNumbers.pop();
    }
    cout << endl;
}
