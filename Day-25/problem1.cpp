#include <iostream>
using namespace std;

int main()
{
    int a[50], b[50], c[100];
    int n1, n2;

    cout << "Enter size of first array: ";
    cin >> n1;

    cout << "Enter elements of first sorted array:\n";
    for(int i = 0; i < n1; i++)
    {
        cin >> a[i];
    }

    cout << "Enter size of second array: ";
    cin >> n2;

    cout << "Enter elements of second sorted array:\n";
    for(int i = 0; i < n2; i++)
    {
        cin >> b[i];
    }

    int i = 0, j = 0, k = 0;

    while(i < n1 && j < n2)
    {
        if(a[i] < b[j])
        {
            c[k] = a[i];
            i++;
        }
        else
        {
            c[k] = b[j];
            j++;
        }
        k++;
    }

    while(i < n1)
    {
        c[k] = a[i];
        i++;
        k++;
    }

    while(j < n2)
    {
        c[k] = b[j];
        j++;
        k++;
    }

    cout << "Merged sorted array:\n";

    for(int x = 0; x < k; x++)
    {
        cout << c[x] << " ";
    }

    return 0;
}
