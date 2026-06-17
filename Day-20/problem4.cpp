#include <iostream>
using namespace std;
int main()
{
    int rows, cols;
    int a[10][10];
    cout << "Enter number of rows: ";
    cin >> rows;
    cout << "Enter number of columns: ";
    cin >> cols;
    cout << "Enter matrix elements:\n";
    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < cols; j++)
        {
            cin >> a[i][j];
        }
    }
    cout << "Column-wise sums are:\n";
    for(int j = 0; j < cols; j++)
    {
        int sum = 0;
        for(int i = 0; i < rows; i++)
        {
            sum = sum + a[i][j];
        }

        cout << "Sum of column " << j + 1 << " = " << sum << endl;
    }

    return 0;
}
