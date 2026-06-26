#include <iostream>
using namespace std;

int main()
{
    int arr[100], n, i, choice, sum = 0;
    int largest, smallest;

    cout << "Enter Number of Elements: ";
    cin >> n;

    cout << "Enter Array Elements:\n";
    for(i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    do
    {
        cout << "\n===== ARRAY OPERATIONS =====\n";
        cout << "1. Display Array\n";
        cout << "2. Find Sum\n";
        cout << "3. Find Largest Element\n";
        cout << "4. Find Smallest Element\n";
        cout << "5. Exit\n";
        cout << "Enter Your Choice: ";
        cin >> choice;

        switch(choice)
        {
            case 1:
                cout << "Array Elements: ";
                for(i = 0; i < n; i++)
                {
                    cout << arr[i] << " ";
                }
                cout << endl;
                break;

            case 2:
                sum = 0;
                for(i = 0; i < n; i++)
                {
                    sum = sum + arr[i];
                }
                cout << "Sum = " << sum << endl;
                break;

            case 3:
                largest = arr[0];
                for(i = 1; i < n; i++)
                {
                    if(arr[i] > largest)
                    {
                        largest = arr[i];
                    }
                }
                cout << "Largest Element = " << largest << endl;
                break;

            case 4:
                smallest = arr[0];
                for(i = 1; i < n; i++)
                {
                    if(arr[i] < smallest)
                    {
                        smallest = arr[i];
                    }
                }
                cout << "Smallest Element = " << smallest << endl;
                break;

            case 5:
                cout << "Thank You!" << endl;
                break;

            default:
                cout << "Invalid Choice!" << endl;
        }

    } while(choice != 5);

    return 0;
}
