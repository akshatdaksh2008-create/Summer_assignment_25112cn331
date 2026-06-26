
#include<iostream>
#include<string>
using namespace std;

struct Employee
{
    int empId;
    string name;
    int age;
    string department;
    float salary;
    string designation;
};

Employee employees[100];
int totalEmployees = 0;

void addEmployee()
{
    if(totalEmployees >= 100)
    {
        cout << "\nMaximum limit reached. Cannot add more employees." << endl;
        return;
    }

    Employee e;

    cout << "\n--- Add New Employee ---" << endl;
    cout << "Enter Employee ID: ";
    cin >> e.empId;

    for(int i = 0; i < totalEmployees; i++)
    {
        if(employees[i].empId == e.empId)
        {
            cout << "Employee ID already exists! Try again." << endl;
            return;
        }
    }

    cin.ignore();
    cout << "Enter Name: ";
    getline(cin, e.name);

    cout << "Enter Age: ";
    cin >> e.age;

    cin.ignore();
    cout << "Enter Department: ";
    getline(cin, e.department);

    cout << "Enter Designation: ";
    getline(cin, e.designation);

    cout << "Enter Salary: ";
    cin >> e.salary;

    employees[totalEmployees] = e;
    totalEmployees++;

    cout << "\nEmployee added successfully!" << endl;
}

void displayAllEmployees()
{
    if(totalEmployees == 0)
    {
        cout << "\nNo employees found in the system!" << endl;
        return;
    }

    cout << "\n--- All Employee Records ---" << endl;
    cout << "------------------------------------------------------------------------" << endl;
    cout << "ID\tName\t\tAge\tDept\t\tDesignation\tSalary" << endl;
    cout << "------------------------------------------------------------------------" << endl;

    for(int i = 0; i < totalEmployees; i++)
    {
        cout << employees[i].empId << "\t"
             << employees[i].name << "\t\t"
             << employees[i].age << "\t"
             << employees[i].department << "\t\t"
             << employees[i].designation << "\t"
             << employees[i].salary << endl;
    }

    cout << "------------------------------------------------------------------------" << endl;
    cout << "Total Employees: " << totalEmployees << endl;
}

void searchEmployee()
{
    int id;
    cout << "\nEnter Employee ID to search: ";
    cin >> id;

    bool found = false;
    for(int i = 0; i < totalEmployees; i++)
    {
        if(employees[i].empId == id)
        {
            cout << "\n--- Employee Found ---" << endl;
            cout << "Employee ID  : " << employees[i].empId << endl;
            cout << "Name         : " << employees[i].name << endl;
            cout << "Age          : " << employees[i].age << endl;
            cout << "Department   : " << employees[i].department << endl;
            cout << "Designation  : " << employees[i].designation << endl;
            cout << "Salary       : " << employees[i].salary << endl;
            found = true;
            break;
        }
    }

    if(!found)
        cout << "\nEmployee with ID " << id << " not found!" << endl;
}

void updateEmployee()
{
    int id;
    cout << "\nEnter Employee ID to update: ";
    cin >> id;

    bool found = false;
    for(int i = 0; i < totalEmployees; i++)
    {
        if(employees[i].empId == id)
        {
            cout << "\nEmployee found! Enter new details:" << endl;

            cin.ignore();
            cout << "Enter New Name: ";
            getline(cin, employees[i].name);

            cout << "Enter New Age: ";
            cin >> employees[i].age;

            cin.ignore();
            cout << "Enter New Department: ";
            getline(cin, employees[i].department);

            cout << "Enter New Designation: ";
            getline(cin, employees[i].designation);

            cout << "Enter New Salary: ";
            cin >> employees[i].salary;

            cout << "\nEmployee record updated successfully!" << endl;
            found = true;
            break;
        }
    }

    if(!found)
        cout << "\nEmployee with ID " << id << " not found!" << endl;
}

void deleteEmployee()
{
    int id;
    cout << "\nEnter Employee ID to delete: ";
    cin >> id;

    bool found = false;
    for(int i = 0; i < totalEmployees; i++)
    {
        if(employees[i].empId == id)
        {
            for(int j = i; j < totalEmployees - 1; j++)
            {
                employees[j] = employees[j+1];
            }
            totalEmployees--;
            cout << "\nEmployee record deleted successfully!" << endl;
            found = true;
            break;
        }
    }

    if(!found)
        cout << "\nEmployee with ID " << id << " not found!" << endl;
}

void giveRaise()
{
    int id;
    float percent;

    cout << "\nEnter Employee ID to give raise: ";
    cin >> id;

    bool found = false;
    for(int i = 0; i < totalEmployees; i++)
    {
        if(employees[i].empId == id)
        {
            cout << "Current Salary: " << employees[i].salary << endl;
            cout << "Enter Raise Percentage: ";
            cin >> percent;

            float raise = (employees[i].salary * percent) / 100;
            employees[i].salary += raise;

            cout << "\nRaise applied! New Salary: " << employees[i].salary << endl;
            found = true;
            break;
        }
    }

    if(!found)
        cout << "\nEmployee with ID " << id << " not found!" << endl;
}

void searchByDepartment()
{
    string dept;
    cin.ignore();
    cout << "\nEnter Department Name to search: ";
    getline(cin, dept);

    bool found = false;
    cout << "\n--- Employees in Department: " << dept << " ---" << endl;
    cout << "--------------------------------------------" << endl;

    for(int i = 0; i < totalEmployees; i++)
    {
        if(employees[i].department == dept)
        {
            cout << "ID: " << employees[i].empId
                 << " | Name: " << employees[i].name
                 << " | Salary: " << employees[i].salary << endl;
            found = true;
        }
    }

    if(!found)
        cout << "No employees found in department: " << dept << endl;
}

void highestSalary()
{
    if(totalEmployees == 0)
    {
        cout << "\nNo employees in the system!" << endl;
        return;
    }

    int topIndex = 0;
    for(int i = 1; i < totalEmployees; i++)
    {
        if(employees[i].salary > employees[topIndex].salary)
            topIndex = i;
    }

    cout << "\n--- Highest Paid Employee ---" << endl;
    cout << "Name        : " << employees[topIndex].name << endl;
    cout << "Employee ID : " << employees[topIndex].empId << endl;
    cout << "Department  : " << employees[topIndex].department << endl;
    cout << "Designation : " << employees[topIndex].designation << endl;
    cout << "Salary      : " << employees[topIndex].salary << endl;
}

int main()
{
    int choice;

    cout << "======================================" << endl;
    cout << "   EMPLOYEE MANAGEMENT SYSTEM        " << endl;
    cout << "======================================" << endl;

    do
    {
        cout << "\n--- MAIN MENU ---" << endl;
        cout << "1. Add Employee" << endl;
        cout << "2. Display All Employees" << endl;
        cout << "3. Search Employee by ID" << endl;
        cout << "4. Search Employee by Department" << endl;
        cout << "5. Update Employee" << endl;
        cout << "6. Delete Employee" << endl;
        cout << "7. Give Salary Raise" << endl;
        cout << "8. Show Highest Paid Employee" << endl;
        cout << "9. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice)
        {
            case 1:
                addEmployee();
                break;
            case 2:
                displayAllEmployees();
                break;
            case 3:
                searchEmployee();
                break;
            case 4:
                searchByDepartment();
                break;
            case 5:
                updateEmployee();
                break;
            case 6:
                deleteEmployee();
                break;
            case 7:
                giveRaise();
                break;
            case 8:
                highestSalary();
                break;
            case 9:
                cout << "\nThank you! Exiting the program..." << endl;
                break;
            default:
                cout << "\nInvalid choice! Please enter 1-9." << endl;
        }

    } while(choice != 9);

    return 0;
}
