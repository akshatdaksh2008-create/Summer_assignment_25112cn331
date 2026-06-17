#include <iostream>
using namespace std;
int main()
{
    int rows, cols;
    int matrix[10][10];
    cout << "Enter number of rows: ";
    cin >> rows;
    cout << "Enter number of columns: ";
    cin >> cols;
    cout << "Enter matrix elements:\n";
    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < cols; j++)
        {
            cin >> matrix[i][j];
        }
    }
    cout << "Transpose of matrix is:\n";
    for(int i = 0; i < cols; i++)
    {
        for(int j = 0; j < rows; j++)
        {
            cout << matrix[j][i] << " ";
        }
        cout << endl;
    }

    return 0;
}
