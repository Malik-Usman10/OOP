#include <iostream>
using namespace std;

void makedata(int array[], int size)
{
    cout << "Enter " << size << " intergers:" << endl;
    for (int i = 0; i < size; i++)
    {
        cin >> array[i];
    }
}

void display(int array[], int size)
{
    cout << "The array is :" << endl;
    for (int i = 0; i < size; i++)
    {
        cout << array[i] << endl;
    }
}

int getelement(int array[], int size, int index)
{
    if (index < 0 || index > size)
    {
        cout << "Invalid index,write the index correctly: " << endl;
    }
    else
    {
        return array[index];
    }
}

int countevens(int array[], int size)
{
    int count = 0;
    for (int i = 0; i < size; i++)
    {
        if (array[i] % 2 == 0)
        {
            count++;
        }
    }
    return count;
}
int countodds(int array[], int size)
{
    int count = 0;
    for (int i = 0; i < size; i++)
    {
        if (array[i] % 2 != 0)
        {
            count++;
        }
    }
    return count;
}
bool removeFirst(int arr[], int &size, int key)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == key)
        {

            for (int j = i; j < size - 1; j++)
            {
                arr[j] = arr[j + 1];
            }
            size--;
            return true;
        }
    }
    return false;
}
int *dropSmallest(int arr[], int size)
{

    int minIndex = 0;
    for (int i = 1; i < size; ++i)
    {
        if (arr[i] < arr[minIndex])
        {
            minIndex = i;
        }
    }

    int *newArr = new int[size - 1];

    int j = 0; 

    for (int i = 0; i < size; ++i)
    {
        if (i != minIndex)
        {
            newArr[j] = arr[i]; 
            ++j;                
        }
    }
    return newArr;
}
int main()
{
    int size;
    int c;
    int even;
    int odd;
    int key;
    cout << "Enter ther size of array:" << endl;
    cin >> size;
    int arr[size];
    makedata(arr, size);
    display(arr, size);
    cout << "The content exist on third index is :" << endl;
    c = getelement(arr, size, 3);
    cout << c << endl;
    even = countevens(arr, size);
    cout << "The number of evens in the given array is :" << endl;
    cout << even << endl;
    odd = countodds(arr, size);
    cout << "The number of odds in the given array is :" << endl;
    cout << odd << endl;
    cout << "Please Enter the key to removed from array:" << endl;
    cin >> key;
    if (removeFirst(arr, size, key))
    {
        cout << "First occurrence of " << key << " removed." << endl;
    }
    else
    {
        cout << key << " not found in the array." << endl;
    }
    cout << "The array after changing some key is :" << endl;
    display(arr, size);

    int *newArr = dropSmallest(arr, size);
    cout << "Array after dropping the smallest element:\n";
    display(newArr, size - 1);


    delete[] newArr;
}