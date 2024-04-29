#include <iostream>
#include <queue>
#include <stack>

using namespace std;

void reversedQueue(queue<int>& queue) 
{
    stack<int> stack;

    while (!queue.empty()) 
    {
        stack.push(queue.front());
        queue.pop();
    }

    while (!stack.empty()) 
    {
        queue.push(stack.top());
        stack.pop();
    }
}

int main() 
{
    int range;
    cout << "Enter the range for the queue: ";
    cin >> range;

    queue<int> queue;

    cout << "Enter the elements (" << range << " numbers): ";
    for (int i = 0; i < range; i++) 
    {
        int element;
        cin >> element;
        queue.push(element);
    }
    reversedQueue(queue);

    cout << "Reversed queue: ";
    while (!queue.empty()) 
    { 
        cout << queue.front() << " ";
        queue.pop();
    }
    cout << endl;
}
