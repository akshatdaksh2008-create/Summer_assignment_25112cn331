#include<iostream>
#include<string>
using namespace std;

struct Student
{
    int rollno;
    string name;
    int age;
    string className;

    string subject[6];
    int marks[6];
    int totalSubjects;

    int totalMarks;
    float percentage;
    float cgpa;
    string grade;
    string result;
};

Student students[100];
int totalStudents = 0;

string calculateGrade(float percentage)
{
    if(percentage >= 90)
        return "A+";
    else if(percentage >= 80)
        return "A";
    else if(percentage >= 70)
        return "B+";
    else if(percentage >= 60)
        return "B";
    else if(percentage >= 50)
        return "C";
    else if(percentage >= 40)
        return "D";
    else
        return "F";
}

float calculateCGPA(float percentage)
{
    return percentage / 9.5;
}

string calculateResult(int marks[], int totalSubjects)
{
    for(int i = 0; i < totalSubjects; i++)
    {
        if(marks[i] < 33)
            return "FAIL";
    }
    return "PASS";
}

void calculateAll(Student &s)
{
    s.totalMarks = 0;
    for(int i = 0; i < s.totalSubjects; i++)
        s.totalMarks += s.marks[i];

    s.percentage = ((float)s.totalMarks / (s.totalSubjects * 100)) * 100;
    s.grade = calculateGrade(s.percentage);
    s.cgpa = calculateCGPA(s.percentage);
    s.result = calculateResult(s.marks, s.totalSubjects);
}

void addStudent()
{
    if(totalStudents >= 100)
    {
        cout << "\nMaximum limit reached. Cannot add more students." << endl;
        return;
    }

    Student s;

    cout << "\n--- Add New Student ---" << endl;
    cout << "Enter Roll Number: ";
    cin >> s.rollno;

    for(int i = 0; i < totalStudents; i++)
    {
        if(students[i].rollno == s.rollno)
        {
            cout << "Roll number already exists! Try again." << endl;
            return;
        }
    }

    cin.ignore();
    cout << "Enter Name: ";
    getline(cin, s.name);

    cout << "Enter Age: ";
    cin >> s.age;

    cin.ignore();
    cout << "Enter Class: ";
    getline(cin, s.className);

    cout << "How many subjects (max 6): ";
    cin >> s.totalSubjects;

    if(s.totalSubjects < 1 || s.totalSubjects > 6)
    {
        cout << "Invalid number of subjects! Must be between 1 and 6." << endl;
        return;
    }

    cin.ignore();
    for(int i = 0; i < s.totalSubjects; i++)
    {
        cout << "Enter Subject " << i+1 << " Name: ";
        getline(cin, s.subject[i]);
        cout << "Enter Marks in " << s.subject[i] << " (out of 100): ";
        cin >> s.marks[i];

        while(s.marks[i] < 0 || s.marks[i] > 100)
        {
            cout << "Invalid marks! Enter between 0 and 100: ";
            cin >> s.marks[i];
        }
        cin.ignore();
    }

    calculateAll(s);

    students[totalStudents] = s;
    totalStudents++;

    cout << "\nStudent added successfully!" << endl;
    cout << "Result: " << s.result << " | Grade: " << s.grade << " | Percentage: " << s.percentage << "%" << endl;
}

void generateMarksheet()
{
    int roll;
    cout << "\nEnter Roll Number to generate marksheet: ";
    cin >> roll;

    bool found = false;
    for(int i = 0; i < totalStudents; i++)
    {
        if(students[i].rollno == roll)
        {
            cout << "\n=============================================" << endl;
            cout << "             MARK SHEET                      " << endl;
            cout << "=============================================" << endl;
            cout << "Roll Number : " << students[i].rollno << endl;
            cout << "Name        : " << students[i].name << endl;
            cout << "Age         : " << students[i].age << endl;
            cout << "Class       : " << students[i].className << endl;
            cout << "---------------------------------------------" << endl;
            cout << "Subject\t\t\tMarks\t\tMax" << endl;
            cout << "---------------------------------------------" << endl;

            for(int j = 0; j < students[i].totalSubjects; j++)
            {
                cout << students[i].subject[j] << "\t\t\t" << students[i].marks[j] << "\t\t100" << endl;
            }

            cout << "---------------------------------------------" << endl;
            cout << "Total Marks  : " << students[i].totalMarks << " / " << students[i].totalSubjects * 100 << endl;
            cout << "Percentage   : " << students[i].percentage << "%" << endl;
            cout << "CGPA         : " << students[i].cgpa << endl;
            cout << "Grade        : " << students[i].grade << endl;
            cout << "=============================================" << endl;

            if(students[i].result == "PASS")
                cout << "RESULT       : ** PASS **" << endl;
            else
                cout << "RESULT       : ** FAIL **" << endl;

            cout << "=============================================" << endl;
            found = true;
            break;
        }
    }

    if(!found)
        cout << "\nStudent with Roll No " << roll << " not found!" << endl;
}

void displayAllStudents()
{
    if(totalStudents == 0)
    {
        cout << "\nNo students found in the system!" << endl;
        return;
    }

    cout << "\n--- All Students Summary ---" << endl;
    cout << "------------------------------------------------------------------------" << endl;
    cout << "Roll\tName\t\tClass\t\tTotal\tPercent\tGrade\tResult" << endl;
    cout << "------------------------------------------------------------------------" << endl;

    for(int i = 0; i < totalStudents; i++)
    {
        cout << students[i].rollno << "\t"
             << students[i].name << "\t\t"
             << students[i].className << "\t\t"
             << students[i].totalMarks << "\t"
             << students[i].percentage << "%\t"
             << students[i].grade << "\t"
             << students[i].result << endl;
    }

    cout << "------------------------------------------------------------------------" << endl;
    cout << "Total Students: " << totalStudents << endl;
}

void searchStudent()
{
    int roll;
    cout << "\nEnter Roll Number to search: ";
    cin >> roll;

    bool found = false;
    for(int i = 0; i < totalStudents; i++)
    {
        if(students[i].rollno == roll)
        {
            cout << "\n--- Student Details ---" << endl;
            cout << "Roll Number  : " << students[i].rollno << endl;
            cout << "Name         : " << students[i].name << endl;
            cout << "Class        : " << students[i].className << endl;
            cout << "Percentage   : " << students[i].percentage << "%" << endl;
            cout << "CGPA         : " << students[i].cgpa << endl;
            cout << "Grade        : " << students[i].grade << endl;
            cout << "Result       : " << students[i].result << endl;
            found = true;
            break;
        }
    }

    if(!found)
        cout << "\nStudent with Roll No " << roll << " not found!" << endl;
}

void updateMarks()
{
    int roll;
    cout << "\nEnter Roll Number to update marks: ";
    cin >> roll;

    bool found = false;
    for(int i = 0; i < totalStudents; i++)
    {
        if(students[i].rollno == roll)
        {
            cout << "\nUpdating marks for: " << students[i].name << endl;
            cin.ignore();
            for(int j = 0; j < students[i].totalSubjects; j++)
            {
                cout << "Enter new marks for " << students[i].subject[j] << ": ";
                cin >> students[i].marks[j];

                while(students[i].marks[j] < 0 || students[i].marks[j] > 100)
                {
                    cout << "Invalid marks! Enter between 0 and 100: ";
                    cin >> students[i].marks[j];
                }
                cin.ignore();
            }

            calculateAll(students[i]);

            cout << "\nMarks updated successfully!" << endl;
            cout << "New Result: " << students[i].result << " | New Grade: " << students[i].grade << endl;
            found = true;
            break;
        }
    }

    if(!found)
        cout << "\nStudent with Roll No " << roll << " not found!" << endl;
}

void deleteStudent()
{
    int roll;
    cout << "\nEnter Roll Number to delete: ";
    cin >> roll;

    bool found = false;
    for(int i = 0; i < totalStudents; i++)
    {
        if(students[i].rollno == roll)
        {
            for(int j = i; j < totalStudents - 1; j++)
                students[j] = students[j+1];

            totalStudents--;
            cout << "\nStudent record deleted successfully!" << endl;
            found = true;
            break;
        }
    }

    if(!found)
        cout << "\nStudent with Roll No " << roll << " not found!" << endl;
}

void topperStudent()
{
    if(totalStudents == 0)
    {
        cout << "\nNo students in the system!" << endl;
        return;
    }

    int topIndex = 0;
    for(int i = 1; i < totalStudents; i++)
    {
        if(students[i].percentage > students[topIndex].percentage)
            topIndex = i;
    }

    cout << "\n--- Class Topper ---" << endl;
    cout << "Name       : " << students[topIndex].name << endl;
    cout << "Roll No    : " << students[topIndex].rollno << endl;
    cout << "Class      : " << students[topIndex].className << endl;
    cout << "Percentage : " << students[topIndex].percentage << "%" << endl;
    cout << "CGPA       : " << students[topIndex].cgpa << endl;
    cout << "Grade      : " << students[topIndex].grade << endl;
}

void classStatistics()
{
    if(totalStudents == 0)
    {
        cout << "\nNo students in the system!" << endl;
        return;
    }

    int passed = 0, failed = 0;
    float totalPercentage = 0;
    float highest = students[0].percentage;
    float lowest = students[0].percentage;

    for(int i = 0; i < totalStudents; i++)
    {
        totalPercentage += students[i].percentage;

        if(students[i].result == "PASS")
            passed++;
        else
            failed++;

        if(students[i].percentage > highest)
            highest = students[i].percentage;

        if(students[i].percentage < lowest)
            lowest = students[i].percentage;
    }

    float classAverage = totalPercentage / totalStudents;

    cout << "\n--- Class Statistics ---" << endl;
    cout << "Total Students   : " << totalStudents << endl;
    cout << "Passed           : " << passed << endl;
    cout << "Failed           : " << failed << endl;
    cout << "Class Average    : " << classAverage << "%" << endl;
    cout << "Highest Marks    : " << highest << "%" << endl;
    cout << "Lowest Marks     : " << lowest << "%" << endl;
}

void displayPassedStudents()
{
    if(totalStudents == 0)
    {
        cout << "\nNo students in the system!" << endl;
        return;
    }

    cout << "\n--- Passed Students ---" << endl;
    bool anyPassed = false;
    for(int i = 0; i < totalStudents; i++)
    {
        if(students[i].result == "PASS")
        {
            cout << "Roll: " << students[i].rollno
                 << " | Name: " << students[i].name
                 << " | Percentage: " << students[i].percentage << "%"
                 << " | Grade: " << students[i].grade << endl;
            anyPassed = true;
        }
    }
    if(!anyPassed)
        cout << "No students passed." << endl;
}

void displayFailedStudents()
{
    if(totalStudents == 0)
    {
        cout << "\nNo students in the system!" << endl;
        return;
    }

    cout << "\n--- Failed Students ---" << endl;
    bool anyFailed = false;
    for(int i = 0; i < totalStudents; i++)
    {
        if(students[i].result == "FAIL")
        {
            cout << "Roll: " << students[i].rollno
                 << " | Name: " << students[i].name
                 << " | Percentage: " << students[i].percentage << "%" << endl;
            anyFailed = true;
        }
    }
    if(!anyFailed)
        cout << "No students failed." << endl;
}

int main()
{
    int choice;

    cout << "======================================" << endl;
    cout << "   MARKSHEET GENERATION SYSTEM       " << endl;
    cout << "======================================" << endl;

    do
    {
        cout << "\n--- MAIN MENU ---" << endl;
        cout << "1.  Add Student" << endl;
        cout << "2.  Generate Marksheet" << endl;
        cout << "3.  Display All Students" << endl;
        cout << "4.  Search Student" << endl;
        cout << "5.  Update Marks" << endl;
        cout << "6.  Delete Student" << endl;
        cout << "7.  Show Class Topper" << endl;
        cout << "8.  Class Statistics" << endl;
        cout << "9.  Show Passed Students" << endl;
        cout << "10. Show Failed Students" << endl;
        cout << "11. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice)
        {
            case 1:
                addStudent();
                break;
            case 2:
                generateMarksheet();
                break;
            case 3:
                displayAllStudents();
                break;
            case 4:
                searchStudent();
                break;
            case 5:
                updateMarks();
                break;
            case 6:
                deleteStudent();
                break;
            case 7:
                topperStudent();
                break;
            case 8:
                classStatistics();
                break;
            case 9:
                displayPassedStudents();
                break;
            case 10:
                displayFailedStudents();
                break;
            case 11:
                cout << "\nThank you! Exiting the program..." << endl;
                break;
            default:
                cout << "\nInvalid choice! Please enter 1-11." << endl;
        }

    } while(choice != 11);

    return 0;
}
