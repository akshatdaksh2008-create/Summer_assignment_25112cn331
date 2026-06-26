#include <iostream>
using namespace std;
class Ticket
{
private:
    string name;
    int seats;
    int total;
public:
    void bookTicket()
    {
        cout << "Enter Your Name: ";
        cin >> name;

        cout << "Enter Number of Seats: ";
        cin >> seats;

        total = seats * 200;   // Ticket price = 200 per seat

        cout << "Ticket Booked Successfully!\n";
    }
   void cancelTicket()
    {
        seats = 0;
        total = 0;

        cout << "Ticket Cancelled Successfully!\n";
    }

    void showTicket()
    {
        cout << "\n------ Ticket Details ------\n";
        cout << "Name: " << name << endl;
        cout << "Seats Booked: " << seats << endl;
        cout << "Total Amount: Rs. " << total << endl;
    }
};

int main()
{
    Ticket t;
    int choice;

    do
    {
        cout << "\n===== TICKET BOOKING SYSTEM =====\n";
        cout << "1. Book Ticket\n";
        cout << "2. Cancel Ticket\n";
        cout << "3. Show Ticket Details\n";
        cout << "4. Exit\n";
        cout << "Enter Your Choice: ";
        cin >> choice;

        switch(choice)
        {
            case 1:
                t.bookTicket();
                break;

            case 2:
                t.cancelTicket();
                break;

            case 3:
                t.showTicket();
                break;

            case 4:
                cout << "Thank You!\n";
                break;

            default:
                cout << "Invalid Choice!\n";
        }

    } while(choice != 4);

    return 0;
}
