#include <iostream>
using namespace std;

class Inventory
{
private:
    int itemCode;
    string itemName;
    int quantity;
    float price;

public:
    void addItem()
    {
        cout << "Enter Item Code: ";
        cin >> itemCode;

        cout << "Enter Item Name: ";
        cin >> itemName;

        cout << "Enter Quantity: ";
        cin >> quantity;

        cout << "Enter Price: ";
        cin >> price;

        cout << "Item Added Successfully!\n";
    }

    void updateItem()
    {
        cout << "Enter New Quantity: ";
        cin >> quantity;

        cout << "Enter New Price: ";
        cin >> price;

        cout << "Item Updated Successfully!\n";
    }

    void displayItem()
    {
        cout << "\n------ Item Details ------\n";
        cout << "Item Code : " << itemCode << endl;
        cout << "Item Name : " << itemName << endl;
        cout << "Quantity  : " << quantity << endl;
        cout << "Price     : Rs. " << price << endl;
    }

    void deleteItem()
    {
        itemCode = 0;
        itemName = "";
        quantity = 0;
        price = 0;

        cout << "Item Deleted Successfully!\n";
    }
};

int main()
{
    Inventory item;
    int choice;

    do
    {
        cout << "\n===== INVENTORY MANAGEMENT SYSTEM =====\n";
        cout << "1. Add Item\n";
        cout << "2. Update Item\n";
        cout << "3. Display Item\n";
        cout << "4. Delete Item\n";
        cout << "5. Exit\n";
        cout << "Enter Your Choice: ";
        cin >> choice;

        switch(choice)
        {
            case 1:
                item.addItem();
                break;

            case 2:
                item.updateItem();
                break;

            case 3:
                item.displayItem();
                break;

            case 4:
                item.deleteItem();
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
