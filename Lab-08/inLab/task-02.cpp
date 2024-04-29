#include <iostream>
#include <vector>
using namespace std;

class Matrix {
private:
    int rows;
    int colums;
    int **data;

public:
    Matrix(int rows, int colums) : rows(rows), colums(colums) 
    {
        data = new int*[rows];
        for (int i = 0; i < rows; i++) 
        {
            data[i] = new int[colums];
        }
    }
    ~Matrix() 
    {
        for (int i = 0; i < rows; ++i) 
        {
            delete[] data[i];
        }
        delete[] data;
    }

    void display() const 
    {
        for (int i = 0; i < rows; ++i) 
        {
            for (int j = 0; j < colums; ++j) 
            {
                cout << data[i][j] << " ";
            }
            cout << endl;
        }
    }

    operator vector<int>() const 
    {
        vector<int> result;
        for (int i = 0; i < rows; i++) 
        {
            for (int j = 0; j < colums; j++) 
            {
                result.push_back(data[i][j]);
            }
        }
        return result;
    }

    void setValue(int row, int col, int value) 
    {
        if (row >= 0 && row < rows && col >= 0 && col < colums) 
        {
            data[row][col] = value;
        } 
        else 
        {
            cout << "Index out of bounds." << endl;
        }
    }
};

int main() 
{
    int rows, colums;
    cout << "Number of Rows for 2D Arrays: ";
    cin >> rows;
    cout << "Number of Colums for 2D Arrays: ";
    cin >> colums;
    

    Matrix mat(rows, colums);

    int value = 1;
    for (int i = 0; i < rows; ++i) 
    {
        for (int j = 0; j < colums; ++j) 
        {
            mat.setValue(i, j, value++);
        }
    }

    cout << "Matrix:" << endl;
    mat.display();

    vector<int> vec = static_cast<vector<int>>(mat);

    cout << "\n1D Vector:" << endl;
    for (int num : vec) 
    {
        cout << num << " ";
    }
    cout << endl;
}
