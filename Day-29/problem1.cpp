#include <iostream>
using namespace std;

int main()
{
    int choice;
    float num1, num2, result;

    do
    {
        cout << "\n===== MENU DRIVEN CALCULATOR =====\n";
        cout << "1. Addition\n";
        cout << "2. Subtraction\n";
        cout << "3. Multiplication\n";
        cout << "4. Division\n";
        cout << "5. Exit\n";
        cout << "Enter Your Choice: ";
        cin >> choice;

        switch(choice)
        {
            case 1:
                cout << "Enter Two Numbers: ";
                cin >> num1 >> num2;
                result = num1 + num2;
                cout << "Result = " << result << endl;
                break;

            case 2:
                cout << "Enter Two Numbers: ";
                cin >> num1 >> num2;
                result = num1 - num2;
                cout << "Result = " << result << endl;
                break;

            case 3:
                cout << "Enter Two Numbers: ";
                cin >> num1 >> num2;
                result = num1 * num2;
                cout << "Result = " << result << endl;
                break;

            case 4:
                cout << "Enter Two Numbers: ";
                cin >> num1 >> num2;

                if(num2 != 0)
                {
                    result = num1 / num2;
                    cout << "Result = " << result << endl;
                }
                else
                {
                    cout << "Division by zero is not allowed." << endl;
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
