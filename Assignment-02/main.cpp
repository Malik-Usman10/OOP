#include <iostream>
#include "vector.h"

using namespace std;


int main() 
{ 
    int sizeOne,sizeTwo;
    Vector<int> vectorOne(sizeOne);
    Vector<int> vectorTwo(sizeTwo);

    cout << "Enter the size of vectorOne: ";
    cin >> sizeOne;
    cin.ignore(); 

    cout << "Enter elements of vectorOne: ";
    cin >> vectorOne;

    cout << "Enter the size of vectorTwo: ";
    cin >> sizeTwo;
    cin.ignore();

    cout << "Enter elements of vectorTwo: ";
    cin >> vectorTwo;

    cout << "First vector: " << vectorOne << endl;
    cout << "Second vector: " << vectorTwo << endl;

    int choice;
    do {
        cout << "\nMenu:\n";
        cout << "1. Get size of Vectors\n";
        cout << "2. Get max size of Vectors\n";
        cout << "3. Push element to the Vectors\n";
        cout << "4. Pop element from the Vectors\n";
        cout << "5. Check if the Vectors is Empty\n";
        cout << "6. Check if the Vectors is full\n";
        cout << "7. Access element by index from Vectors\n";
        cout << "8. Erase element by index from Vectors\n";
        cout << "9. Swap VectorOne with VectorTwo\n";
        cout << "10. Insert element at index of Vectors\n";
        cout << "11. Sort Vectors\n";
        cout << "12. Move elements in Vectors\n";
        cout << "13. Union of VectorOne and VectorTwo\n";
        cout << "14. Intersection VectorOne and Vector Two\n";
        cout << "15. Unique elements in Vectorss\n";
        cout << "16. Count occurrences of an elements in Vectors\n";
        cout << "17. Check if the VectorTwo is subset of VectorONe\n";
        cout << "18. Search for an elements in Vectors\n";
        cout << "19. Concatenate the first and second vectors\n";
        cout << "20. Subtract VectorOne and VectorTwo\n";
        cout << "21. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice) {
            case 1:
                cout << "Size of the first vector: " << vectorOne.size() << endl;
                break;
            case 2:
                cout << "Max size of the first vector: " << vectorOne.getMaxSize() << endl;
                break;
            case 3: {
                int value;
                cout << "Enter the value to push: ";
                cin >> value;
                vectorOne.push_back(value);
                cout << "Element pushed successfully.\n";
                break;
            }
            case 4:
                vectorOne.pop_back();
                cout << "Element popped successfully.\n";
                break;
            case 5:
                cout << "First vector is " << (vectorOne.is_empty() ? "empty" : "not empty") << endl;
                break;
            case 6:
                cout << "First vector is " << (vectorOne.is_full() ? "full" : "not full") << endl;
                break;
            case 7: {
                int index;
                cout << "Enter the index: ";
                cin >> index;
                try 
                {
                    cout << "Element at index " << index << " in the first vector: " << vectorOne[index] << endl;
                } 
                catch(const out_of_range& e) 
                {
                    cerr << "Error: " << e.what() << endl;
                }
                break;
            }
            case 8: 
            {
                int index;
                cout << "Enter the index to erase: ";
                cin >> index;
                try 
                {
                    int erasedValue = vectorOne.erase(index);
                    cout << "Erased element: " << erasedValue << endl;
                } 
                catch(const out_of_range& e) 
                {
                    cerr << "Error: " << e.what() << endl;
                }
                break;
            }
            case 9: {
                Vector<int> temp = vectorOne;
                // vectorOne.swap(vectorTwo);     //Cannot make it working
                // vectorTwo.swap(temp);
                cout << "Vectors swapped successfully.\n";
                break;
            }
            case 10: {
                int index, value;
                cout << "Enter the index to insert: ";
                cin >> index;
                cout << "Enter the value to insert: ";
                cin >> value;
                try 
                {
                    vectorOne.insert(index, value);
                    cout << "Element inserted successfully.\n";
                } 
                catch(const out_of_range& e) 
                {
                    cerr << "Error: " << e.what() << endl;
                }
                break;
            }
            case 11:
            {
                // vectorOne.sort();     //Cannot make it working
                cout << "First vector sorted successfully.\n";
                break;
            }
            case 12: 
            {
                int num;
                cout << "Enter the number of positions to move: ";
                cin >> num;
                vectorOne.move(num);
                cout << "Elements moved successfully.\n";
                break;
            }
            case 13: 
            {
                Vector<int> unionVec = vectorOne.union_with(vectorTwo);
                cout << "Union of the first and second vectors: " << unionVec << endl;
                break;
            }
            case 14: 
            {
                Vector<int> intersectionVec = vectorOne.intersection_with(vectorTwo);
                cout << "Intersection of the first and second vectors: " << intersectionVec << endl;
                break;
            }
            case 15: 
            {
                Vector<int> uniqueVec = vectorOne.unique_elements();
                cout << "Unique elements in the first vector: " << uniqueVec << endl;
                break;
            }
            case 16: 
            {
                int element;
                cout << "Enter the element to count: ";
                cin >> element;
                int count = vectorOne.count(element);
                cout << "Occurrences of element " << element << " in the first vector: " << count << endl;
                break;
            }
            case 17: 
            {
                bool isSubset = vectorOne.is_subset(vectorTwo);
                cout << "Second vector is " << (isSubset ? "a subset" : "not a subset") << " of the first vector\n";
                break;
            }
            case 18: 
            {
                int key;
                cout << "Enter the element to search: ";
                cin >> key;
                bool found = vectorOne.search(key);
                cout << "Element " << key << " is " << (found ? "found" : "not found") << " in the first vector\n";
                break;
            }
            case 19: 
            {
                Vector<int> addedVector = vectorOne + vectorTwo;
                cout << "Added vector: " << addedVector << endl;
                break;
            }
            case 20: 
            {
                Vector<int> subtractedVec = vectorOne - vectorTwo;
                cout << "Subtracted vector: " << subtractedVec << endl;
                break;
            }
            case 21:
            {
                cout << "Exiting program...\n";
                break;
            }
            default:
            {
                cout << "Invalid choice. Please enter a number between 1 and 21.\n";
            }
        }
    } while(choice != 21);
}
