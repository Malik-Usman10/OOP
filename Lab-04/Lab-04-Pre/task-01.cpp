#include <iostream>

using namespace std;

void update_array(int array[], int size, int newValue, int position) 
{
    if (position >= 0 && position < size) 
    {
        array[position] = newValue;
        cout << "\nArray Updated";
        cout << endl;
    } 
    else 
    {
        cout << "Invalid position" << endl;
    }
}

int main()
{
  int size;
  cout << "Enter the size of array: ";
  cin >> size;

  int array[size];

  cout << "Enter the elements for array:" << endl;
  for (int i = 0; i < size; i++) 
  {
    cin >> array[i];
  }
 cout << "\nOriginal Array";
  for (int i = 0; i < size; i++)
  {
    cout << " " << array[i];
  }

  while (true) {

    cout << "\nMenu:" << endl;
    cout << "1. Update an element" << endl;
    cout << "2. Exit" << endl;

    int choice;
    cout << "Enter your choice 1 or 2: ";
    cin >> choice;

    if (choice == 1) 
    {
      int newValue, position;
      cout << "Enter the new value: ";
      cin >> newValue;
      cout << "Enter the position: ";
      cin >> position;

      update_array(array, size, newValue, position);
    } 
    else if (choice == 2) 
    {
      cout << "\nProgram Exits" << endl;
      break;
    } 
    else 
    {
      cout << "\nInvalid choice. Please enter a number between 1 or 2." << endl;
    }
  }
    cout << "\nArray is: \n";
    for (int i = 0; i < size; i++)
    {
        cout << " " << array[i];
    }
    cout << "\n";

  return 0;
}
