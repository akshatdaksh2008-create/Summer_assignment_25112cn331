#include <iostream>
using namespace std;

class BankAccount
{
private:
    int accountNumber;
    string name;
    float balance;

public:
    void createAccount()
    {
        cout << "Enter Account Number: ";
        cin >> accountNumber;

        cout << "Enter Name: ";
        cin >> name;

        cout << "Enter Starting Balance: ";
        cin >> balance;
    }

    void deposit()
    {
        float amount;
        cout << "Enter Amount to Deposit: ";
        cin >> amount;

        balance = balance + amount;

        cout << "Money Deposited Successfully.\n";
    }

    void withdraw()
    {
        float amount;
        cout << "Enter Amount to Withdraw: ";
        cin >> amount;

        if (amount <= balance)
        {
            balance = balance - amount;
            cout << "Money Withdrawn Successfully.\n";
        }
        else
        {
            cout << "Not Enough Balance.\n";
        }
    }

    void display()
    {
        cout << "\n------ Account Details ------\n";
        cout << "Account Number: " << accountNumber << endl;
        cout << "Name: " << name << endl;
        cout << "Balance: " << balance << endl;
    }
};

int main()
{
    BankAccount account;
    int choice;

    do
    {
        cout << "\n===== BANK ACCOUNT SYSTEM =====\n";
        cout << "1. Create Account\n";
        cout << "2. Deposit Money\n";
        cout << "3. Withdraw Money\n";
        cout << "4. Display Account\n";
        cout << "5. Exit\n";
        cout << "Enter Your Choice: ";
        cin >> choice;

        switch(choice)
        {
            case 1:
                account.createAccount();
                break;

            case 2:
                account.deposit();
                break;

            case 3:
                account.withdraw();
                break;

            case 4:
                account.display();
                break;

            case 5:
                cout << "Thank You!\n";
                break;

            default:
                cout << "Invalid Choice!\n";
        }

    } while(choice != 5);

    return 0;
}
