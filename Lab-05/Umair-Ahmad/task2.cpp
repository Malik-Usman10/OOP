#include <iostream>
#include <queue>
#include <stack>

using namespace std;
void reverseQueue(queue<int>& q) {
    stack<int> s;

    while (!q.empty()) {
        s.push(q.front());
        q.pop();
    }

    while (!s.empty()) {
        q.push(s.top());
        s.pop();
    }
}

int main() {
    int range;

    cout << "Enter the range for the queue: ";
    cin >> range;

    queue<int> q;

    if (range < 0) {
        cerr << "Error: Range cannot be negative." << endl;
        return 1; 
    }

    cout << "Enter the elements (" << range << " numbers): ";
    for (int i = 0; i < range; i++) {
        int element;
        cin >> element;
        q.push(element);
    }

    reverseQueue(q);

    cout << "Reversed queue: ";
    while (!q.empty()) { 
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;

    return 0;
}
