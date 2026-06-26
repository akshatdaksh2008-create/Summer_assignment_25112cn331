#include <iostream>
using namespace std;

class Employee
{
private:
    int empId;
    string name;
    string department;
    float salary;

public:
    void addEmployee()
    {
        cout << "Enter Employee ID: ";
        cin >> empId;

        cout << "Enter Name: ";
        cin >> name;

        cout << "Enter Department: ";
        cin >> department;

        cout << "Enter Salary: ";
        cin >> salary;

        cout << "\nEmployee Added Successfully!\n";
    }

    void updateSalary()
    {
        float newSalary;
        cout << "\nEnter New Salary: ";
        cin >> newSalary;

        salary = newSalary;

        cout << "Salary Updated Successfully!\n";
    }

    void displayEmployee()
    {
        cout << "\n----- EMPLOYEE DETAILS -----\n";
        cout << "Employee ID : " << empId << endl;
        cout << "Name        : " << name << endl;
        cout << "Department  : " << department << endl;
        cout << "Salary      : " << salary << endl;
    }
};

int main()
{
    Employee emp;

    cout << "=== MINI EMPLOYEE MANAGEMENT SYSTEM ===\n\n";

    emp.addEmployee();
    emp.displayEmployee();

    cout << "\nUpdating salary...\n";
    emp.updateSalary();
    emp.displayEmployee();

    return 0;
}
