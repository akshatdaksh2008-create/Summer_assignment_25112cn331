#include<iostream>
#include<string>
using namespace std;

struct Employee
{
    int empId;
    string name;
    string department;
    float basicSalary;
    float hra;
    float da;
    float ta;
    float medicalAllowance;
    float grossSalary;
    float providentFund;
    float incomeTax;
    float totalDeductions;
    float netSalary;
};

Employee employees[100];
int totalEmployees = 0;

void calculateSalary(Employee &e)
{
    e.hra = 0.20 * e.basicSalary;
    e.da = 0.10 * e.basicSalary;
    e.ta = 0.05 * e.basicSalary;
    e.medicalAllowance = 0.05 * e.basicSalary;

    e.grossSalary = e.basicSalary + e.hra + e.da + e.ta + e.medicalAllowance;

    e.providentFund = 0.12 * e.basicSalary;

    if(e.grossSalary > 50000)
        e.incomeTax = 0.20 * e.grossSalary;
    else if(e.grossSalary > 30000)
        e.incomeTax = 0.10 * e.grossSalary;
    else
        e.incomeTax = 0;

    e.totalDeductions = e.providentFund + e.incomeTax;
    e.netSalary = e.grossSalary - e.totalDeductions;
}

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

    cout << "Enter Department: ";
    getline(cin, e.department);

    cout << "Enter Basic Salary: ";
    cin >> e.basicSalary;

    calculateSalary(e);

    employees[totalEmployees] = e;
    totalEmployees++;

    cout << "\nEmployee added successfully! Net Salary: " << e.netSalary << endl;
}

void displaySalarySlip()
{
    int id;
    cout << "\nEnter Employee ID to view salary slip: ";
    cin >> id;

    bool found = false;
    for(int i = 0; i < totalEmployees; i++)
    {
        if(employees[i].empId == id)
        {
            cout << "\n============================================" << endl;
            cout << "           SALARY SLIP                      " << endl;
            cout << "============================================" << endl;
            cout << "Employee ID     : " << employees[i].empId << endl;
            cout << "Name            : " << employees[i].name << endl;
            cout << "Department      : " << employees[i].department << endl;
            cout << "--------------------------------------------" << endl;
            cout << "         EARNINGS                           " << endl;
            cout << "--------------------------------------------" << endl;
            cout << "Basic Salary    : " << employees[i].basicSalary << endl;
            cout << "HRA (20%)       : " << employees[i].hra << endl;
            cout << "DA  (10%)       : " << employees[i].da << endl;
            cout << "TA  (5%)        : " << employees[i].ta << endl;
            cout << "Medical (5%)    : " << employees[i].medicalAllowance << endl;
            cout << "--------------------------------------------" << endl;
            cout << "Gross Salary    : " << employees[i].grossSalary << endl;
            cout << "--------------------------------------------" << endl;
            cout << "         DEDUCTIONS                         " << endl;
            cout << "--------------------------------------------" << endl;
            cout << "Provident Fund  : " << employees[i].providentFund << endl;
            cout << "Income Tax      : " << employees[i].incomeTax << endl;
            cout << "--------------------------------------------" << endl;
            cout << "Total Deductions: " << employees[i].totalDeductions << endl;
            cout << "============================================" << endl;
            cout << "NET SALARY      : " << employees[i].netSalary << endl;
            cout << "============================================" << endl;
            found = true;
            break;
        }
    }

    if(!found)
        cout << "\nEmployee with ID " << id << " not found!" << endl;
}

void displayAllSalaries()
{
    if(totalEmployees == 0)
    {
        cout << "\nNo employees found in the system!" << endl;
        return;
    }

    cout << "\n--- All Employee Salaries ---" << endl;
    cout << "----------------------------------------------------------------------------" << endl;
    cout << "ID\tName\t\tDept\t\tBasic\t\tGross\t\tNet" << endl;
    cout << "----------------------------------------------------------------------------" << endl;

    for(int i = 0; i < totalEmployees; i++)
    {
        cout << employees[i].empId << "\t"
             << employees[i].name << "\t\t"
             << employees[i].department << "\t\t"
             << employees[i].basicSalary << "\t\t"
             << employees[i].grossSalary << "\t\t"
             << employees[i].netSalary << endl;
    }

    cout << "----------------------------------------------------------------------------" << endl;
    cout << "Total Employees: " << totalEmployees << endl;
}

void updateBasicSalary()
{
    int id;
    cout << "\nEnter Employee ID to update salary: ";
    cin >> id;

    bool found = false;
    for(int i = 0; i < totalEmployees; i++)
    {
        if(employees[i].empId == id)
        {
            cout << "Current Basic Salary: " << employees[i].basicSalary << endl;
            cout << "Enter New Basic Salary: ";
            cin >> employees[i].basicSalary;

            calculateSalary(employees[i]);

            cout << "\nSalary updated successfully!" << endl;
            cout << "New Net Salary: " << employees[i].netSalary << endl;
            found = true;
            break;
        }
    }

    if(!found)
        cout << "\nEmployee with ID " << id << " not found!" << endl;
}

void giveSalaryRaise()
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
            cout << "Current Basic Salary: " << employees[i].basicSalary << endl;
            cout << "Enter Raise Percentage: ";
            cin >> percent;

            float raise = (employees[i].basicSalary * percent) / 100;
            employees[i].basicSalary += raise;

            calculateSalary(employees[i]);

            cout << "\nRaise applied!" << endl;
            cout << "New Basic Salary : " << employees[i].basicSalary << endl;
            cout << "New Net Salary   : " << employees[i].netSalary << endl;
            found = true;
            break;
        }
    }

    if(!found)
        cout << "\nEmployee with ID " << id << " not found!" << endl;
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
            cout << "\n--- Employee Details ---" << endl;
            cout << "Employee ID  : " << employees[i].empId << endl;
            cout << "Name         : " << employees[i].name << endl;
            cout << "Department   : " << employees[i].department << endl;
            cout << "Basic Salary : " << employees[i].basicSalary << endl;
            cout << "Gross Salary : " << employees[i].grossSalary << endl;
            cout << "Net Salary   : " << employees[i].netSalary << endl;
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
            cout << "\nEmployee deleted successfully!" << endl;
            found = true;
            break;
        }
    }

    if(!found)
        cout << "\nEmployee with ID " << id << " not found!" << endl;
}

void highestPaidEmployee()
{
    if(totalEmployees == 0)
    {
        cout << "\nNo employees in the system!" << endl;
        return;
    }

    int topIndex = 0;
    for(int i = 1; i < totalEmployees; i++)
    {
        if(employees[i].netSalary > employees[topIndex].netSalary)
            topIndex = i;
    }

    cout << "\n--- Highest Paid Employee ---" << endl;
    cout << "Name         : " << employees[topIndex].name << endl;
    cout << "Employee ID  : " << employees[topIndex].empId << endl;
    cout << "Department   : " << employees[topIndex].department << endl;
    cout << "Net Salary   : " << employees[topIndex].netSalary << endl;
}

void totalSalaryBill()
{
    if(totalEmployees == 0)
    {
        cout << "\nNo employees in the system!" << endl;
        return;
    }

    float totalGross = 0;
    float totalNet = 0;
    float totalDeductions = 0;

    for(int i = 0; i < totalEmployees; i++)
    {
        totalGross += employees[i].grossSalary;
        totalNet += employees[i].netSalary;
        totalDeductions += employees[i].totalDeductions;
    }

    cout << "\n--- Monthly Salary Bill ---" << endl;
    cout << "Total Employees  : " << totalEmployees << endl;
    cout << "Total Gross      : " << totalGross << endl;
    cout << "Total Deductions : " << totalDeductions << endl;
    cout << "Total Net Payout : " << totalNet << endl;
}

int main()
{
    int choice;

    cout << "======================================" << endl;
    cout << "     SALARY MANAGEMENT SYSTEM        " << endl;
    cout << "======================================" << endl;

    do
    {
        cout << "\n--- MAIN MENU ---" << endl;
        cout << "1.  Add Employee" << endl;
        cout << "2.  View Salary Slip" << endl;
        cout << "3.  Display All Salaries" << endl;
        cout << "4.  Search Employee" << endl;
        cout << "5.  Update Basic Salary" << endl;
        cout << "6.  Give Salary Raise" << endl;
        cout << "7.  Delete Employee" << endl;
        cout << "8.  Show Highest Paid Employee" << endl;
        cout << "9.  Show Total Salary Bill" << endl;
        cout << "10. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice)
        {
            case 1:
                addEmployee();
                break;
            case 2:
                displaySalarySlip();
                break;
            case 3:
                displayAllSalaries();
                break;
            case 4:
                searchEmployee();
                break;
            case 5:
                updateBasicSalary();
                break;
            case 6:
                giveSalaryRaise();
                break;
            case 7:
                deleteEmployee();
                break;
            case 8:
                highestPaidEmployee();
                break;
            case 9:
                totalSalaryBill();
                break;
            case 10:
                cout << "\nThank you! Exiting the program..." << endl;
                break;
            default:
                cout << "\nInvalid choice! Please enter 1-10." << endl;
        }

    } while(choice != 10);

    return 0;
}
