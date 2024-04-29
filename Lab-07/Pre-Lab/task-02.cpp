#include <iostream>

using namespace std;
class Array {
private:
    int *arr;
    int size;

public:
    Array() : arr(nullptr), size(0) {}
    Array(int sz) : size(sz) 
    {
        arr = new int[size];
    }
    ~Array() {
        delete[] arr;
    }

    void display() const 
    {
        for (int i = 0; i < size; ++i) 
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    void input() {
        cout << "Enter " << size << " elements:\n";
        for (int i = 0; i < size; ++i) 
        {
            cin >> arr[i];
        }
    }

    int& operator[](int index) 
    {
        return arr[index];
    }

    Array operator+(const Array& other) const 
    {
        Array result(size);
        for (int i = 0; i < size; ++i) 
        {
            result.arr[i] = arr[i] + other.arr[i];
        }
        return result;
    }

    Array operator-(const Array& other) const 
    {
        Array result(size);
        for (int i = 0; i < size; ++i) 
        {
            result.arr[i] = arr[i] - other.arr[i];
        }
        return result;
    }
};

int main() {
    int size;
    cout << "Enter the size of arrays: ";
    cin >> size;

    Array arr1(size), arr2(size);
    cout << "Input for Array 1:\n";
    arr1.input();
    cout << "Input for Array 2:\n";
    arr2.input();

    cout << "Array 1: ";
    arr1.display();
    cout << "Array 2: ";
    arr2.display();

    Array sum = arr1 + arr2;
    cout << "Sum: ";
    sum.display();

    Array diff = arr1 - arr2;
    cout << "Difference: ";
    diff.display();
}
