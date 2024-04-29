#include <iostream>
#include <vector>
#include <string>

using namespace std;

class BigInt {
private:
    vector<int> digits;

public:
    BigInt() {}

    BigInt(const vector<int>& digits) : digits(digits) {}

    BigInt(const string& number) 
    {
        for (int i = number.size() - 1; i >= 0; i--) 
        {
            digits.push_back(number[i] - '0');
        }
    }

    BigInt(const BigInt& other) : digits(other.digits) {}


    BigInt& operator++() 
    {
        int carry = 1;
        for (int i = 0; i < digits.size() || carry != 0; i++) 
        {
            if (i == digits.size())
                digits.push_back(0);

            int sum = digits[i] + carry;
            digits[i] = sum % 10;
            carry = sum / 10;
        }
        return *this;
    }

    BigInt& operator--() 
    {
        int borrow = 1;
        for (int i = 0; i < digits.size(); i++) 
        {
            int diff = digits[i] - borrow;
            if (diff < 0) 
            {
                digits[i] = 10 + diff;
                borrow = 1;
            } 
            else 
            {
                digits[i] = diff;
                borrow = 0;
            }
        }

        while (digits.size() > 1 && digits.back() == 0)
            digits.pop_back();

        return *this;
    }

    friend ostream& operator<<(ostream& os, const BigInt& bigint) 
    {
        for (int i = bigint.digits.size() - 1; i >= 0; i--) 
        {
            os << bigint.digits[i];
        }
        return os;
    }
};

int main() 
{
    string input;
    cout << "Enter a large integer: ";
    cin >> input;

    BigInt num(input);

    BigInt num2 = num;
    
    cout << "Original number: " << num << endl;
    ++num2;

    cout << "After increment: " << num2 << endl;

    --num;
    cout << "After decrement: " << num << endl;
}
