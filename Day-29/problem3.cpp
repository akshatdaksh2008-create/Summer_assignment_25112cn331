#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    char str1[100], str2[100];
    int choice;

    cout << "Enter First String: ";
    cin >> str1;

    cout << "Enter Second String: ";
    cin >> str2;

    do
    {
        cout << "\n===== STRING OPERATIONS =====\n";
        cout << "1. Find Length of First String\n";
        cout << "2. Copy First String\n";
        cout << "3. Concatenate Strings\n";
        cout << "4. Compare Strings\n";
        cout << "5. Exit\n";
        cout << "Enter Your Choice: ";
        cin >> choice;

        switch(choice)
        {
            case 1:
                cout << "Length = " << strlen(str1) << endl;
                break;

            case 2:
                strcpy(str2, str1);
                cout << "Copied String = " << str2 << endl;
                break;

            case 3:
                strcat(str1, str2);
                cout << "Concatenated String = " << str1 << endl;
                break;

            case 4:
                if(strcmp(str1, str2) == 0)
                {
                    cout << "Strings are Equal." << endl;
                }
                else
                {
                    cout << "Strings are Not Equal." << endl;
                }
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
