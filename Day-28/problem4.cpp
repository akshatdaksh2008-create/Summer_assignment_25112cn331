#include <iostream>
using namespace std;
class Contact
{
private:
    string name;
    string phone;
public:
    void addContact()
    {
        cout << "Enter Name: ";
        cin >> name;

        cout << "Enter Phone Number: ";
        cin >> phone;

        cout << "Contact Added Successfully!\n";
    }
    void updateContact()
    {
        cout << "Enter New Name: ";
        cin >> name;

        cout << "Enter New Phone Number: ";
        cin >> phone;

        cout << "Contact Updated Successfully!\n";
    }

    void displayContact()
    {
        cout << "\n------ Contact Details ------\n";
        cout << "Name: " << name << endl;
        cout << "Phone Number: " << phone << endl;
    }

    void deleteContact()
    {
        name = "";
        phone = "";

        cout << "Contact Deleted Successfully!\n";
    }
};

int main()
{
    Contact c;
    int choice;

    do
    {
        cout << "\n===== CONTACT MANAGEMENT SYSTEM =====\n";
        cout << "1. Add Contact\n";
        cout << "2. Update Contact\n";
        cout << "3. Display Contact\n";
        cout << "4. Delete Contact\n";
        cout << "5. Exit\n";
        cout << "Enter Your Choice: ";
        cin >> choice;

        switch(choice)
        {
            case 1:
                c.addContact();
                break;

            case 2:
                c.updateContact();
                break;

            case 3:
                c.displayContact();
                break;

            case 4:
                c.deleteContact();
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
