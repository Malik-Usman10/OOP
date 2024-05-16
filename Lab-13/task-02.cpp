#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int main() 
{    
    ofstream outFile("matrix.txt");
    int rows = 3, cols = 4;
    int matrix[3][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {1, 2, 3, 4}
    };
    outFile << rows << " " << cols << endl;
    for (int i = 0; i < rows; i++) 
    {
        for (int j = 0; j < cols; j++) 
        {
            outFile << matrix[i][j] << " ";
        }
        outFile << endl;
    }
    outFile.close();
    ifstream inFile("matrix.txt");
    int r, c;
    inFile >> r >> c;

    vector<vector<int>> readMatrix(r, vector<int>(c));
    for (int i = 0; i < r; i++) 
    {
        for (int j = 0; j < c; j++) 
        {
            inFile >> readMatrix[i][j];
        }
    }
    inFile.close();
    cout << r << " " << c << endl;
    for (const auto& row : readMatrix) 
    {
        for (int num : row) 
        {
            cout << num << " ";
        }
        cout << endl;
    }
}