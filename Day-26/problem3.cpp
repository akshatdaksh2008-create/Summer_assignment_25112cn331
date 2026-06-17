#include <iostream>
using namespace std;

int main()
{
    int balance = 5000;
    int choice, amount;

    while(true)
    {
        cout << "\n--- ATM MENU ---\n";
        cout << "1. Check Balance\n";
        cout << "2. Deposit\n";
        cout << "3. Withdraw\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if(choice == 1)
        {
            cout << "Current Balance = " << balance << endl;
        }
        else if(choice == 2)
        {
            cout << "Enter amount to deposit: ";
            cin >> amount;
            balance = balance + amount;
            cout << "Amount Deposited Successfully" << endl;
        }
        else if(choice == 3)
        {
            cout << "Enter amount to withdraw: ";
            cin >> amount;

            if(amount <= balance)
            {
                balance = balance - amount;
                cout << "Please collect your cash" << endl;
            }
            else
            {
                cout << "Insufficient Balance" << endl;
            }
        }
        else if(choice == 4)
        {
            cout << "Thank you for using ATM";
            break;
        }
        else
        {
            cout << "Invalid choice";
        }
    }

    return 0;
}
