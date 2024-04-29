#include <iostream>
using namespace std;
class Integer
{
private:
    int *array;
    int size;

public:
    Integer(int arraySize) : size(arraySize)
    {
        array = new int[size];
        cout << "Enter Integers for Array: ";
        for (int i = 0; i < size; i++)
        {
            cin >> array[i];
        }
    }

    ~Integer()
    {
        for (int i = 0; i < size; i++)
        {
            array[i] = 0;
        }
        delete[] array;
    }

    friend int largeElem(Integer &a)
    {
        int largest = a.array[0];
        for (int i = 1; i < a.size; i++)
        {
            if (a.array[i] > largest)
            {
                largest = a.array[i];
            }
        }
        return largest;
    }
    friend int smallElem(Integer &a)
    {
        int smallest = a.array[0];
        for (int i = 1; i < a.size; i++)
        {
            if (a.array[i] < smallest)
            {
                smallest = a.array[i];
            }
        }
        return smallest;
    }

    friend void findRepeated(Integer &a)
    {
        for (int i = 0; i < a.size - 1; i++)
        {
            for (int j = i + 1; j < a.size; ++j)
            {
                if (a.array[i] == a.array[j])
                
                    cout << a.array[i] << " is repeated." << endl;
                
            }
        }
    }
};

int main()
{
    int size;
    cout << "Enter the size of array: ";
    cin >> size;

    Integer a(size);
    cout << "Large element: " << largeElem(a) << endl;
    cout << "Small element: " << smallElem(a) << endl;

    cout << "Repeated Elements are";
     findRepeated(a);

}
