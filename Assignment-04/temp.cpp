#include <iostream>
using namespace std;

int main() {
    int balance = 1250;
    const int arrSize = 4;
    char balanceArray[arrSize];

    // Save the balance into the array digit by digit
    for (int i = arrSize - 1; i >= 0; i--) {
        int digit = balance % 10;
        balanceArray[i] = digit + '0';
        balance /= 10;
    }

    // Print the array
    for (int i = 0; i < arrSize; i++) {
        std::cout << balanceArray[i] << " ";
    }
    int result = 0;
    for (int i = 0; i < arrSize; i++) {
        int digit = balanceArray[i] - '0'; // Convert character to integer
        result = result * 10 + digit;
    }
    std::cout << "\nResult: " << result << std::endl;

    return 0;
}