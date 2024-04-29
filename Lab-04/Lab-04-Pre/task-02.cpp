#include <iostream>
#include <array>

using namespace std;

class Addition {
public:
  static const int arraySize = 32;

  array<int, arraySize> firstNum;

  array<int, arraySize> secondNum;


  void input(int first, int second) 
  {
    fill(firstNum.begin(), firstNum.end(), 0);
    fill(secondNum.begin(), secondNum.end(), 0);

    int i = arraySize - 1;
    while (first > 0) 
    {
        firstNum[i--] = first % 2;
        first /= 2;
    }

    cout << "\n firstNum in binary: \t";
    for (auto i : firstNum) 
    {
        cout << i;
    }

    i = arraySize - 1;
    while (second > 0) 
    {
        secondNum[i--] = second % 2;
        second /= 2;
    }

    cout << "\n secondNum in binary:\t";
    for (auto i : secondNum) 
    {
        cout << i;
    }
  }

  array<int, arraySize> getSum() 
  {
    array<int, arraySize> sum; 
    fill(sum.begin(), sum.end(), 0);

    int carry = 0;
    for (int i = arraySize - 1; i >= 0; --i) 
    {
        int sumBit = 0;

        int bit1 = firstNum[i];
        int bit2 = secondNum[i];
        if (carry == 1) 
        {
            sumBit = bit1 + bit2 + carry;
        }
        else
        {
            sumBit = bit1 + bit2;
        }
        if (sumBit % 2 == 0) 
        {
            sum[i] = 0;
            carry = sumBit / 2;
        } 
        else if (sumBit % 2 != 0) 
        {
        sum[i] = 1;
            carry = sumBit / 2;
        } 
        else 
        { 
            sum[i] = 0;
            carry = sumBit / 2;
        }
    }
    return sum;
  }
};

int main() {
  Addition addition;

  int first, second;
  cout << "Enter first number: ";
  cin >> first;
  cout << "Enter second number: ";
  cin >> second;

  addition.input(first, second);

  array<int, Addition::arraySize> sum = addition.getSum();

  cout << "\n Sum in binary:\t\t";
  for (auto i : sum) 
  {
    cout << i;
  }
  cout << endl;

  return 0;
}
