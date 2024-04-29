#include <algorithm>
#include <iostream>

using namespace std;

int makeData(int arr[], int size)
{
    for (int i = 0; i < size; i++) 
    {
        cout << "Enter the Element " << i + 1 << " : ";
        cin >> arr[i];
    }
    return 0;
}

int display(int arr[], int size)
{
    cout << "Array Elements: ";
    for (int i = 0; i < size; i ++) 
    {
        cout << arr[i] <<" ";
    }
    cout << endl;
    return 0;
}
int getElement(int arr[], int size, int index)
{
    if (index >= size || index < 0) {
        cout << "Enter the Correct index";
    }
        cout << "The Element at index " << index << " is " << arr[index] << endl;
        return 0;
}

int countEven(int arr[], int size, int evenNumber)
{
    for (int i = 0 ; i < size; i++)
    {
        if (arr[i] % 2 == 0 )
        {
            evenNumber = evenNumber + 1;
        }
    }
    return evenNumber;
}
int countOdd(int arr[], int size, int evenCount, int oddNumber)
{
    oddNumber = size - evenCount;
    return oddNumber;
}

int removeFirst(int arr[], int size, int key)
{
    bool found = false;
    for (int i = 0; i < size; i++) 
    {
        if (arr[i] == key)
        {
            found = true;
            for (int j = i; j < size; j++) {
                arr[j] = arr[j + 1];
            }
        }
    }
    return found;
}

int *dropSmallest(int arr[], int size)
{
    int smallestInt = *min_element(arr, arr + size);

    int *newArr = new int[size - 1];

    int j = 0;
    for (int i = 0; i < size; i++) 
    {
        if (arr[i] != smallestInt)
        {
            newArr[j++] = arr[i];
        }
    }
    return newArr;
}

int main()
{
    int size, index, evenNumber = 0, oddNumber = 0;
    cout << "Enter the Size of Array: ";
    cin >> size;

    int arr[size];

    makeData(arr,size);
    display(arr, size);

    cout << "Enter the Index of Element You Want: ";
    cin >> index;

    getElement(arr,size, index);

    int evenCount = countEven(arr, size, evenNumber);
    int oddCount = countOdd(arr, size, evenCount, oddNumber);

    cout << "Even Numbers Count are :"  << evenCount << endl;
    cout << "Even Numbers Count are :"  << oddCount << endl;

    int key;
    cout << "Enter the Key to remove: ";
    cin >> key;
    if (removeFirst(arr,size,key))
    {
        cout << "Key " << key << " removed Succesfully." << endl;
        display(arr, size - 1);
        size = size - 1;

    } 
    else 
    {
        cout << "Key " << key << " does not exist in array " <<endl;
    }
    int *modArr = dropSmallest(arr, size);
    cout << "The array after drop smallest integer is ";
    for (int i = 0; i < size - 1; i++) 
    {
        cout << modArr[i] << " ";
    }

    delete[] modArr;
    return 0;
}