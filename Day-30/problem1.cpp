#include <iostream>
using namespace std;

int main()
{
    int roll[10], marks[10];
    string name[10];
    int n, i, choice;

    cout << "Enter Number of Students: ";
    cin >> n;

    do
    {
        cout << "\n===== STUDENT RECORD SYSTEM =====\n";
        cout << "1. Add Student Records\n";
        cout << "2. Display Student Records\n";
        cout << "3. Search Student by Roll Number\n";
        cout << "4. Exit\n";
        cout << "Enter Your Choice: ";
        cin >> choice;

        switch(choice)
        {
            case 1:
                for(i = 0; i < n; i++)
                {
                    cout << "\nStudent " << i + 1 << endl;

                    cout << "Enter Roll Number: ";
                    cin >> roll[i];

                    cout << "Enter Name: ";
                    cin >> name[i];

                    cout << "Enter Marks: ";
                    cin >> marks[i];
                }
                break;

            case 2:
                cout << "\nStudent Records\n";
                for(i = 0; i < n; i++)
                {
                    cout << "Roll No: " << roll[i] << endl;
                    cout << "Name: " << name[i] << endl;
                    cout << "Marks: " << marks[i] << endl;
                    cout << "----------------------" << endl;
                }
                break;

            case 3:
            {
                int r;
                cout << "Enter Roll Number to Search: ";
                cin >> r;

                for(i = 0; i < n; i++)
                {
                    if(roll[i] == r)
                    {
                        cout << "Student Found!" << endl;
                        cout << "Roll No: " << roll[i] << endl;
                        cout << "Name: " << name[i] << endl;
                        cout << "Marks: " << marks[i] << endl;
                        break;
                    }
                }

                if(i == n)
                {
                    cout << "Student Not Found!" << endl;
                }
                break;
            }

            case 4:
                cout << "Thank You!" << endl;
                break;

            default:
                cout << "Invalid Choice!" << endl;
        }

    } while(choice != 4);

    return 0;
}
