#include <iostream>
#include <ostream>
#include <istream>
using namespace std;

class Array
{
private:
    int *arr;
    int size;
public:
    Array(): arr(nullptr), size(0) {}
    Array(int sz) : size(sz)
    {
        arr = new int[size];
    }
    ~Array()
    {
        delete[] arr;
    }
    void display() const
    {
        for (int i = 0; i < size; i++) 
        {
            cout << arr[i] << " ";
        }
    }
    void input() {
    cout << "Enter " << size << " elements:\n";
    for (int i = 0; i < size; ++i) 
    {
        cin >> arr[i];
    }
    }
    int& operator[](int index) const
    {
        return arr[index];
    }
    Array operator+(const Array& other) const
    {
        Array result(size);
        for (int i = 0; i < size; i++) 
        {
            result.arr[i] = arr[i] + other.arr[i];
        }
        return result;
    }
    Array operator-(const Array& other) const
    {
        Array result(size);
        for (int i = 0; i < size; i++) 
        {
            result.arr[i] = arr[i] - other.arr[i];
        }
        return result;
    }
    // friend istream& operator<<(istream& is, const Array& arr) 
    // {
    //     for (int i = 0; i < arr.size; i++) 
    //     {
    //         is >> arr.arr[i];
    //     }
    //     return is;
    // }

    friend ostream& operator<<(ostream& os, const Array& arr) 
    {
        for (int i = arr.size; i >= 0; i--) 
        {
            os << arr.arr[i];
        }
        return os;
    }
};
int main()
{
    int size;
    cout << "Enter the Size of the Array: ";
    cin >> size;

    Array arr1(size), arr2(size);
    cout << "Input for Array 1:\n";
    arr1.input();
    cout << "Input for Array 2:\n";
    arr2.input();

    cout << "\n Array 1: ";
    arr1.display();
    cout << "\n Array 2: ";
    arr2.display();

    Array sum = arr1 + arr2;
    cout << "\nSum: ";
    sum.display();

    Array diff = arr1 - arr2;
    cout << "\nDifference: ";
    diff.display();
    return 0;
}