
#include<iostream>
#include<string>
using namespace std;

// structure to store student data
struct Student
{
    int rollno;
    string name;
    int age;
    float marks;
    string grade;
};

// global array to store students (max 100)
Student students[100];
int totalStudents = 0;

// function to calculate grade
string calculateGrade(float marks)
{
    if(marks >= 90)
        return "A+";
    else if(marks >= 80)
        return "A";
    else if(marks >= 70)
        return "B";
    else if(marks >= 60)
        return "C";
    else if(marks >= 50)
        return "D";
    else
        return "F";
}

// function to add a new student
void addStudent()
{
    if(totalStudents >= 100)
    {
        cout << "\nSorry! Maximum limit reached. Cannot add more students." << endl;
        return;
    }

    Student s;

    cout << "\n--- Add New Student ---" << endl;
    cout << "Enter Roll Number: ";
    cin >> s.rollno;

    // check if roll number already exists
    for(int i = 0; i < totalStudents; i++)
    {
        if(students[i].rollno == s.rollno)
        {
            cout << "Roll number already exists! Try again." << endl;
            return;
        }
    }

    cin.ignore(); // clear buffer
    cout << "Enter Name: ";
    getline(cin, s.name);

    cout << "Enter Age: ";
    cin >> s.age;

    cout << "Enter Marks (out of 100): ";
    cin >> s.marks;

    s.grade = calculateGrade(s.marks);

    students[totalStudents] = s;
    totalStudents++;

    cout << "\nStudent added successfully! Grade assigned: " << s.grade << endl;
}

// function to display all students
void displayAllStudents()
{
    if(totalStudents == 0)
    {
        cout << "\nNo students found in the system!" << endl;
        return;
    }

    cout << "\n--- All Student Records ---" << endl;
    cout << "------------------------------------------------------------" << endl;
    cout << "Roll No\tName\t\tAge\tMarks\tGrade" << endl;
    cout << "------------------------------------------------------------" << endl;

    for(int i = 0; i < totalStudents; i++)
    {
        cout << students[i].rollno << "\t"
             << students[i].name << "\t\t"
             << students[i].age << "\t"
             << students[i].marks << "\t"
             << students[i].grade << endl;
    }

    cout << "------------------------------------------------------------" << endl;
    cout << "Total Students: " << totalStudents << endl;
}

// function to search student by roll number
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
            cout << "\n--- Student Found ---" << endl;
            cout << "Roll Number : " << students[i].rollno << endl;
            cout << "Name        : " << students[i].name << endl;
            cout << "Age         : " << students[i].age << endl;
            cout << "Marks       : " << students[i].marks << endl;
            cout << "Grade       : " << students[i].grade << endl;
            found = true;
            break;
        }
    }

    if(!found)
        cout << "\nStudent with Roll No " << roll << " not found!" << endl;
}

// function to update student record
void updateStudent()
{
    int roll;
    cout << "\nEnter Roll Number to update: ";
    cin >> roll;

    bool found = false;
    for(int i = 0; i < totalStudents; i++)
    {
        if(students[i].rollno == roll)
        {
            cout << "\nStudent found! Enter new details:" << endl;

            cin.ignore();
            cout << "Enter New Name: ";
            getline(cin, students[i].name);

            cout << "Enter New Age: ";
            cin >> students[i].age;

            cout << "Enter New Marks: ";
            cin >> students[i].marks;

            students[i].grade = calculateGrade(students[i].marks);

            cout << "\nRecord updated successfully! New Grade: " << students[i].grade << endl;
            found = true;
            break;
        }
    }

    if(!found)
        cout << "\nStudent with Roll No " << roll << " not found!" << endl;
}

// function to delete a student record
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
            // shift all elements to left to fill the gap
            for(int j = i; j < totalStudents - 1; j++)
            {
                students[j] = students[j+1];
            }
            totalStudents--;
            cout << "\nStudent record deleted successfully!" << endl;
            found = true;
            break;
        }
    }

    if(!found)
        cout << "\nStudent with Roll No " << roll << " not found!" << endl;
}

// function to display highest marks student
void topStudent()
{
    if(totalStudents == 0)
    {
        cout << "\nNo students in the system!" << endl;
        return;
    }

    int topIndex = 0;
    for(int i = 1; i < totalStudents; i++)
    {
        if(students[i].marks > students[topIndex].marks)
            topIndex = i;
    }

    cout << "\n--- Top Performer ---" << endl;
    cout << "Name   : " << students[topIndex].name << endl;
    cout << "Roll No: " << students[topIndex].rollno << endl;
    cout << "Marks  : " << students[topIndex].marks << endl;
    cout << "Grade  : " << students[topIndex].grade << endl;
}

// main menu
int main()
{
    int choice;

    cout << "======================================" << endl;
    cout << "  STUDENT RECORD MANAGEMENT SYSTEM   " << endl;
    cout << "======================================" << endl;

    do
    {
        cout << "\n--- MAIN MENU ---" << endl;
        cout << "1. Add Student" << endl;
        cout << "2. Display All Students" << endl;
        cout << "3. Search Student" << endl;
        cout << "4. Update Student" << endl;
        cout << "5. Delete Student" << endl;
        cout << "6. Show Top Student" << endl;
        cout << "7. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice)
        {
            case 1:
                addStudent();
                break;
            case 2:
                displayAllStudents();
                break;
            case 3:
                searchStudent();
                break;
            case 4:
                updateStudent();
                break;
            case 5:
                deleteStudent();
                break;
            case 6:
                topStudent();
                break;
            case 7:
                cout << "\nThank you! Exiting the program..." << endl;
                break;
            default:
                cout << "\nInvalid choice! Please enter 1-7." << endl;
        }

    } while(choice != 7);

    return 0;
}
