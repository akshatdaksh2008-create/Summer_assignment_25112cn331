#include <iostream>
using namespace std;
int main()
{
    int rows, cols;
   cout << "Enter number of rows: ";
    cin >> rows;
    cout << "Enter number of columns: ";
    cin >> cols;
    int a[10][10], b[10][10], sub[10][10];
    cout << "Enter elements of first matrix:\n";
    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < cols; j++)
        {
            cin >> a[i][j];
        }
    }
    cout << "Enter elements of second matrix:\n";
    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < cols; j++)
        {
            cin >> b[i][j];
        }
    }
    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < cols; j++)
        {
            sub[i][j] = a[i][j] - b[i][j];
        }
    }
    cout << "Subtraction of matrices is:\n";
    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < cols; j++)
        {
            cout << sub[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
