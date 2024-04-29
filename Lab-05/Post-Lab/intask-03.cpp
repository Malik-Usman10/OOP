#include <iostream>

using namespace std;

bool isPalindrome(int num) {
    if (num < 0) 
    {
        return false; 
    }
    int reversed = 0, remainder, original = num;
    while (num != 0) 
    {
        remainder = num % 10;
        reversed = reversed * 10 + remainder;
        num /= 10;
    }
    return original == reversed;
}

int main() {
    int number;

    cout << "Enter a number: ";
    cin >> number;

    if (isPalindrome(number)) 
    {
        cout << number << " is a palindrome." << endl;
    } else 
    {
        cout << number << " is not a palindrome." << endl;
    }
}
