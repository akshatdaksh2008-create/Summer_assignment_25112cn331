#include <iostream>
using namespace std;
int main()
{
    int n;
    int a[10][10];
    bool symmetric = true;
    cout << "Enter order of square matrix: ";
    cin >> n;
    cout << "Enter matrix elements:\n";
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cin >> a[i][j];
        }
    }
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(a[i][j] != a[j][i])
            {
                symmetric = false;
            }
        }
    }
    if(symmetric)
        cout << "Matrix is Symmetric";
    else
        cout << "Matrix is Not Symmetric";

    return 0;
}
