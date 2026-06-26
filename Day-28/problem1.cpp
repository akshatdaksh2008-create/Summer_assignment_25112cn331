#include<iostream>
#include<string>
using namespace std;

struct Book
{
    int bookId;
    string title;
    string author;
    string publisher;
    int year;
    float price;
    int totalCopies;
    int availableCopies;
    string category;
};

struct Member
{
    int memberId;
    string name;
    string phone;
    string email;
    int booksIssued;
};

struct IssuedBook
{
    int issueId;
    int memberId;
    string memberName;
    int bookId;
    string bookTitle;
    string issueDate;
    string dueDate;
    bool returned;
};

Book books[200];
Member members[100];
IssuedBook issuedBooks[500];

int totalBooks = 0;
int totalMembers = 0;
int totalIssued = 0;
int issueCounter = 1;

void addBook()
{
    if(totalBooks >= 200)
    {
        cout << "\nMaximum book limit reached!" << endl;
        return;
    }

    Book b;

    cout << "\n--- Add New Book ---" << endl;
    cout << "Enter Book ID: ";
    cin >> b.bookId;

    for(int i = 0; i < totalBooks; i++)
    {
        if(books[i].bookId == b.bookId)
        {
            cout << "Book ID already exists!" << endl;
            return;
        }
    }

    cin.ignore();
    cout << "Enter Title: ";
    getline(cin, b.title);

    cout << "Enter Author: ";
    getline(cin, b.author);

    cout << "Enter Publisher: ";
    getline(cin, b.publisher);

    cout << "Enter Category: ";
    getline(cin, b.category);

    cout << "Enter Year of Publication: ";
    cin >> b.year;

    cout << "Enter Price: ";
    cin >> b.price;

    cout << "Enter Total Copies: ";
    cin >> b.totalCopies;

    b.availableCopies = b.totalCopies;

    books[totalBooks] = b;
    totalBooks++;

    cout << "\nBook added successfully!" << endl;
}

void displayAllBooks()
{
    if(totalBooks == 0)
    {
        cout << "\nNo books in the library!" << endl;
        return;
    }

    cout << "\n--- All Books ---" << endl;
    cout << "--------------------------------------------------------------------------------" << endl;
    cout << "ID\tTitle\t\t\tAuthor\t\tAvail\tCategory" << endl;
    cout << "--------------------------------------------------------------------------------" << endl;

    for(int i = 0; i < totalBooks; i++)
    {
        cout << books[i].bookId << "\t"
             << books[i].title << "\t\t\t"
             << books[i].author << "\t\t"
             << books[i].availableCopies << "/" << books[i].totalCopies << "\t"
             << books[i].category << endl;
    }

    cout << "--------------------------------------------------------------------------------" << endl;
    cout << "Total Books: " << totalBooks << endl;
}

void searchBookById()
{
    int id;
    cout << "\nEnter Book ID to search: ";
    cin >> id;

    bool found = false;
    for(int i = 0; i < totalBooks; i++)
    {
        if(books[i].bookId == id)
        {
            cout << "\n--- Book Details ---" << endl;
            cout << "Book ID     : " << books[i].bookId << endl;
            cout << "Title       : " << books[i].title << endl;
            cout << "Author      : " << books[i].author << endl;
            cout << "Publisher   : " << books[i].publisher << endl;
            cout << "Category    : " << books[i].category << endl;
            cout << "Year        : " << books[i].year << endl;
            cout << "Price       : " << books[i].price << endl;
            cout << "Total Copies: " << books[i].totalCopies << endl;
            cout << "Available   : " << books[i].availableCopies << endl;

            if(books[i].availableCopies > 0)
                cout << "Status      : Available" << endl;
            else
                cout << "Status      : Not Available" << endl;

            found = true;
            break;
        }
    }

    if(!found)
        cout << "\nBook with ID " << id << " not found!" << endl;
}

void searchBookByTitle()
{
    string title;
    cin.ignore();
    cout << "\nEnter Book Title to search: ";
    getline(cin, title);

    bool found = false;
    cout << "\n--- Search Results ---" << endl;

    for(int i = 0; i < totalBooks; i++)
    {
        if(books[i].title == title)
        {
            cout << "ID: " << books[i].bookId
                 << " | Title: " << books[i].title
                 << " | Author: " << books[i].author
                 << " | Available: " << books[i].availableCopies << endl;
            found = true;
        }
    }

    if(!found)
        cout << "No book found with title: " << title << endl;
}

void searchBookByAuthor()
{
    string author;
    cin.ignore();
    cout << "\nEnter Author Name to search: ";
    getline(cin, author);

    bool found = false;
    cout << "\n--- Books by " << author << " ---" << endl;

    for(int i = 0; i < totalBooks; i++)
    {
        if(books[i].author == author)
        {
            cout << "ID: " << books[i].bookId
                 << " | Title: " << books[i].title
                 << " | Available: " << books[i].availableCopies << endl;
            found = true;
        }
    }

    if(!found)
        cout << "No books found by author: " << author << endl;
}

void updateBook()
{
    int id;
    cout << "\nEnter Book ID to update: ";
    cin >> id;

    bool found = false;
    for(int i = 0; i < totalBooks; i++)
    {
        if(books[i].bookId == id)
        {
            cout << "\nEnter new details for: " << books[i].title << endl;

            cin.ignore();
            cout << "Enter New Title: ";
            getline(cin, books[i].title);

            cout << "Enter New Author: ";
            getline(cin, books[i].author);

            cout << "Enter New Publisher: ";
            getline(cin, books[i].publisher);

            cout << "Enter New Category: ";
            getline(cin, books[i].category);

            cout << "Enter New Year: ";
            cin >> books[i].year;

            cout << "Enter New Price: ";
            cin >> books[i].price;

            cout << "\nBook updated successfully!" << endl;
            found = true;
            break;
        }
    }

    if(!found)
        cout << "\nBook with ID " << id << " not found!" << endl;
}

void deleteBook()
{
    int id;
    cout << "\nEnter Book ID to delete: ";
    cin >> id;

    bool found = false;
    for(int i = 0; i < totalBooks; i++)
    {
        if(books[i].bookId == id)
        {
            for(int j = i; j < totalBooks - 1; j++)
                books[j] = books[j+1];

            totalBooks--;
            cout << "\nBook deleted successfully!" << endl;
            found = true;
            break;
        }
    }

    if(!found)
        cout << "\nBook with ID " << id << " not found!" << endl;
}

void addMember()
{
    if(totalMembers >= 100)
    {
        cout << "\nMaximum member limit reached!" << endl;
        return;
    }

    Member m;

    cout << "\n--- Add New Member ---" << endl;
    cout << "Enter Member ID: ";
    cin >> m.memberId;

    for(int i = 0; i < totalMembers; i++)
    {
        if(members[i].memberId == m.memberId)
        {
            cout << "Member ID already exists!" << endl;
            return;
        }
    }

    cin.ignore();
    cout << "Enter Name: ";
    getline(cin, m.name);

    cout << "Enter Phone: ";
    getline(cin, m.phone);

    cout << "Enter Email: ";
    getline(cin, m.email);

    m.booksIssued = 0;

    members[totalMembers] = m;
    totalMembers++;

    cout << "\nMember added successfully!" << endl;
}

void displayAllMembers()
{
    if(totalMembers == 0)
    {
        cout << "\nNo members registered!" << endl;
        return;
    }

    cout << "\n--- All Members ---" << endl;
    cout << "------------------------------------------------------------" << endl;
    cout << "ID\tName\t\tPhone\t\tBooks Issued" << endl;
    cout << "------------------------------------------------------------" << endl;

    for(int i = 0; i < totalMembers; i++)
    {
        cout << members[i].memberId << "\t"
             << members[i].name << "\t\t"
             << members[i].phone << "\t\t"
             << members[i].booksIssued << endl;
    }

    cout << "------------------------------------------------------------" << endl;
    cout << "Total Members: " << totalMembers << endl;
}

void searchMember()
{
    int id;
    cout << "\nEnter Member ID to search: ";
    cin >> id;

    bool found = false;
    for(int i = 0; i < totalMembers; i++)
    {
        if(members[i].memberId == id)
        {
            cout << "\n--- Member Details ---" << endl;
            cout << "Member ID    : " << members[i].memberId << endl;
            cout << "Name         : " << members[i].name << endl;
            cout << "Phone        : " << members[i].phone << endl;
            cout << "Email        : " << members[i].email << endl;
            cout << "Books Issued : " << members[i].booksIssued << endl;
            found = true;
            break;
        }
    }

    if(!found)
        cout << "\nMember with ID " << id << " not found!" << endl;
}

void deleteMember()
{
    int id;
    cout << "\nEnter Member ID to delete: ";
    cin >> id;

    bool found = false;
    for(int i = 0; i < totalMembers; i++)
    {
        if(members[i].memberId == id)
        {
            if(members[i].booksIssued > 0)
            {
                cout << "\nCannot delete! Member has " << members[i].booksIssued << " book(s) not returned yet." << endl;
                return;
            }

            for(int j = i; j < totalMembers - 1; j++)
                members[j] = members[j+1];

            totalMembers--;
            cout << "\nMember deleted successfully!" << endl;
            found = true;
            break;
        }
    }

    if(!found)
        cout << "\nMember with ID " << id << " not found!" << endl;
}

void issueBook()
{
    int memberId, bookId;

    cout << "\n--- Issue Book ---" << endl;
    cout << "Enter Member ID: ";
    cin >> memberId;

    int memberIndex = -1;
    for(int i = 0; i < totalMembers; i++)
    {
        if(members[i].memberId == memberId)
        {
            memberIndex = i;
            break;
        }
    }

    if(memberIndex == -1)
    {
        cout << "Member not found!" << endl;
        return;
    }

    if(members[memberIndex].booksIssued >= 3)
    {
        cout << "Member has already issued 3 books. Return a book first." << endl;
        return;
    }

    cout << "Enter Book ID: ";
    cin >> bookId;

    int bookIndex = -1;
    for(int i = 0; i < totalBooks; i++)
    {
        if(books[i].bookId == bookId)
        {
            bookIndex = i;
            break;
        }
    }

    if(bookIndex == -1)
    {
        cout << "Book not found!" << endl;
        return;
    }

    if(books[bookIndex].availableCopies <= 0)
    {
        cout << "Sorry! No copies available for this book." << endl;
        return;
    }

    IssuedBook ib;
    ib.issueId = issueCounter++;
    ib.memberId = memberId;
    ib.memberName = members[memberIndex].name;
    ib.bookId = bookId;
    ib.bookTitle = books[bookIndex].title;
    ib.returned = false;

    cin.ignore();
    cout << "Enter Issue Date (DD/MM/YYYY): ";
    getline(cin, ib.issueDate);

    cout << "Enter Due Date (DD/MM/YYYY): ";
    getline(cin, ib.dueDate);

    books[bookIndex].availableCopies--;
    members[memberIndex].booksIssued++;

    issuedBooks[totalIssued] = ib;
    totalIssued++;

    cout << "\nBook issued successfully!" << endl;
    cout << "Issue ID    : " << ib.issueId << endl;
    cout << "Member      : " << ib.memberName << endl;
    cout << "Book        : " << ib.bookTitle << endl;
    cout << "Issue Date  : " << ib.issueDate << endl;
    cout << "Due Date    : " << ib.dueDate << endl;
}

void returnBook()
{
    int issueId;
    cout << "\nEnter Issue ID to return book: ";
    cin >> issueId;

    bool found = false;
    for(int i = 0; i < totalIssued; i++)
    {
        if(issuedBooks[i].issueId == issueId)
        {
            if(issuedBooks[i].returned)
            {
                cout << "This book has already been returned!" << endl;
                return;
            }

            for(int j = 0; j < totalBooks; j++)
            {
                if(books[j].bookId == issuedBooks[i].bookId)
                {
                    books[j].availableCopies++;
                    break;
                }
            }

            for(int j = 0; j < totalMembers; j++)
            {
                if(members[j].memberId == issuedBooks[i].memberId)
                {
                    members[j].booksIssued--;
                    break;
                }
            }

            issuedBooks[i].returned = true;

            cout << "\nBook returned successfully!" << endl;
            cout << "Book   : " << issuedBooks[i].bookTitle << endl;
            cout << "Member : " << issuedBooks[i].memberName << endl;
            found = true;
            break;
        }
    }

    if(!found)
        cout << "\nIssue record with ID " << issueId << " not found!" << endl;
}

void displayIssuedBooks()
{
    bool anyActive = false;
    cout << "\n--- Currently Issued Books ---" << endl;
    cout << "------------------------------------------------------------------------" << endl;
    cout << "IssueID\tMember\t\tBook\t\t\tIssue Date\tDue Date" << endl;
    cout << "------------------------------------------------------------------------" << endl;

    for(int i = 0; i < totalIssued; i++)
    {
        if(!issuedBooks[i].returned)
        {
            cout << issuedBooks[i].issueId << "\t"
                 << issuedBooks[i].memberName << "\t\t"
                 << issuedBooks[i].bookTitle << "\t\t\t"
                 << issuedBooks[i].issueDate << "\t"
                 << issuedBooks[i].dueDate << endl;
            anyActive = true;
        }
    }

    if(!anyActive)
        cout << "No books currently issued." << endl;

    cout << "------------------------------------------------------------------------" << endl;
}

void displayIssuedByMember()
{
    int id;
    cout << "\nEnter Member ID: ";
    cin >> id;

    bool found = false;
    cout << "\n--- Books Issued to Member " << id << " ---" << endl;

    for(int i = 0; i < totalIssued; i++)
    {
        if(issuedBooks[i].memberId == id && !issuedBooks[i].returned)
        {
            cout << "Issue ID : " << issuedBooks[i].issueId << endl;
            cout << "Book     : " << issuedBooks[i].bookTitle << endl;
            cout << "Due Date : " << issuedBooks[i].dueDate << endl;
            cout << "---" << endl;
            found = true;
        }
    }

    if(!found)
        cout << "No active issued books for this member." << endl;
}

void libraryStatistics()
{
    int availableBooks = 0;
    int issuedCount = 0;

    for(int i = 0; i < totalBooks; i++)
        availableBooks += books[i].availableCopies;

    for(int i = 0; i < totalIssued; i++)
    {
        if(!issuedBooks[i].returned)
            issuedCount++;
    }

    cout << "\n--- Library Statistics ---" << endl;
    cout << "Total Book Titles    : " << totalBooks << endl;
    cout << "Total Members        : " << totalMembers << endl;
    cout << "Books Currently Out  : " << issuedCount << endl;
    cout << "Total Available      : " << availableBooks << endl;
    cout << "Total Issue Records  : " << totalIssued << endl;
}

void bookMenu()
{
    int choice;
    do
    {
        cout << "\n--- BOOK MENU ---" << endl;
        cout << "1. Add Book" << endl;
        cout << "2. Display All Books" << endl;
        cout << "3. Search Book by ID" << endl;
        cout << "4. Search Book by Title" << endl;
        cout << "5. Search Book by Author" << endl;
        cout << "6. Update Book" << endl;
        cout << "7. Delete Book" << endl;
        cout << "8. Back to Main Menu" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        switch(choice)
        {
            case 1: addBook(); break;
            case 2: displayAllBooks(); break;
            case 3: searchBookById(); break;
            case 4: searchBookByTitle(); break;
            case 5: searchBookByAuthor(); break;
            case 6: updateBook(); break;
            case 7: deleteBook(); break;
            case 8: break;
            default: cout << "Invalid choice!" << endl;
        }
    } while(choice != 8);
}

void memberMenu()
{
    int choice;
    do
    {
        cout << "\n--- MEMBER MENU ---" << endl;
        cout << "1. Add Member" << endl;
        cout << "2. Display All Members" << endl;
        cout << "3. Search Member" << endl;
        cout << "4. Delete Member" << endl;
        cout << "5. Back to Main Menu" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        switch(choice)
        {
            case 1: addMember(); break;
            case 2: displayAllMembers(); break;
            case 3: searchMember(); break;
            case 4: deleteMember(); break;
            case 5: break;
            default: cout << "Invalid choice!" << endl;
        }
    } while(choice != 5);
}

void issueMenu()
{
    int choice;
    do
    {
        cout << "\n--- ISSUE / RETURN MENU ---" << endl;
        cout << "1. Issue Book" << endl;
        cout << "2. Return Book" << endl;
        cout << "3. View All Issued Books" << endl;
        cout << "4. View Books Issued to a Member" << endl;
        cout << "5. Back to Main Menu" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        switch(choice)
        {
            case 1: issueBook(); break;
            case 2: returnBook(); break;
            case 3: displayIssuedBooks(); break;
            case 4: displayIssuedByMember(); break;
            case 5: break;
            default: cout << "Invalid choice!" << endl;
        }
    } while(choice != 5);
}

int main()
{
    int choice;

    cout << "======================================" << endl;
    cout << "     LIBRARY MANAGEMENT SYSTEM       " << endl;
    cout << "======================================" << endl;

    do
    {
        cout << "\n--- MAIN MENU ---" << endl;
        cout << "1. Book Management" << endl;
        cout << "2. Member Management" << endl;
        cout << "3. Issue / Return Books" << endl;
        cout << "4. Library Statistics" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice)
        {
            case 1: bookMenu(); break;
            case 2: memberMenu(); break;
            case 3: issueMenu(); break;
            case 4: libraryStatistics(); break;
            case 5: cout << "\nThank you! Exiting the program..." << endl; break;
            default: cout << "\nInvalid choice! Please enter 1-5." << endl;
        }

    } while(choice != 5);

    return 0;
}
