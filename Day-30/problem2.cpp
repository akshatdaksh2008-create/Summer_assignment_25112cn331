#include <iostream>
using namespace std;

class Library
{
private:
    int bookId;
    string bookName;
    string author;
    int copies;

public:
    void addBook()
    {
        cout << "Enter Book ID: ";
        cin >> bookId;

        cout << "Enter Book Name: ";
        cin >> bookName;

        cout << "Enter Author Name: ";
        cin >> author;

        cout << "Enter Number of Copies: ";
        cin >> copies;

        cout << "\nBook Added Successfully!\n";
    }

    void issueBook()
    {
        if(copies > 0)
        {
            copies--;
            cout << "\nBook Issued Successfully!\n";
        }
        else
        {
            cout << "\nBook Not Available!\n";
        }
    }

    void returnBook()
    {
        copies++;
        cout << "\nBook Returned Successfully!\n";
    }

    void displayBook()
    {
        cout << "\n----- BOOK DETAILS -----\n";
        cout << "Book ID : " << bookId << endl;
        cout << "Book Name : " << bookName << endl;
        cout << "Author : " << author << endl;
        cout << "Available Copies : " << copies << endl;
    }
};

int main()
{
    Library book;

    cout << "=== MINI LIBRARY SYSTEM (WITHOUT MENU) ===\n\n";

    book.addBook();
    book.displayBook();

    cout << "\nIssuing a book...\n";
    book.issueBook();
    book.displayBook();

    cout << "\nReturning a book...\n";
    book.returnBook();
    book.displayBook();

    return 0;
}
