#include<iostream>
#include<string>
using namespace std;

struct Patient
{
    int patientId;
    string name;
    int age;
    string gender;
    string disease;
    string doctorName;
    string ward;
    float billAmount;
    string admitDate;
    bool discharged;
};

struct Doctor
{
    int doctorId;
    string name;
    string specialization;
    string phone;
    int patientsHandled;
};

struct Appointment
{
    int appointmentId;
    int patientId;
    string patientName;
    int doctorId;
    string doctorName;
    string date;
    string time;
    string status;
};

Patient patients[200];
Doctor doctors[50];
Appointment appointments[500];

int totalPatients = 0;
int totalDoctors = 0;
int totalAppointments = 0;
int appointmentCounter = 1;

void addDoctor()
{
    if(totalDoctors >= 50)
    {
        cout << "\nMaximum doctor limit reached!" << endl;
        return;
    }

    Doctor d;

    cout << "\n--- Add New Doctor ---" << endl;
    cout << "Enter Doctor ID: ";
    cin >> d.doctorId;

    for(int i = 0; i < totalDoctors; i++)
    {
        if(doctors[i].doctorId == d.doctorId)
        {
            cout << "Doctor ID already exists!" << endl;
            return;
        }
    }

    cin.ignore();
    cout << "Enter Name: ";
    getline(cin, d.name);

    cout << "Enter Specialization: ";
    getline(cin, d.specialization);

    cout << "Enter Phone: ";
    getline(cin, d.phone);

    d.patientsHandled = 0;

    doctors[totalDoctors] = d;
    totalDoctors++;

    cout << "\nDoctor added successfully!" << endl;
}

void displayAllDoctors()
{
    if(totalDoctors == 0)
    {
        cout << "\nNo doctors registered!" << endl;
        return;
    }

    cout << "\n--- All Doctors ---" << endl;
    cout << "------------------------------------------------------------" << endl;
    cout << "ID\tName\t\tSpecialization\t\tPhone" << endl;
    cout << "------------------------------------------------------------" << endl;

    for(int i = 0; i < totalDoctors; i++)
    {
        cout << doctors[i].doctorId << "\t"
             << doctors[i].name << "\t\t"
             << doctors[i].specialization << "\t\t"
             << doctors[i].phone << endl;
    }

    cout << "------------------------------------------------------------" << endl;
    cout << "Total Doctors: " << totalDoctors << endl;
}

void searchDoctor()
{
    int id;
    cout << "\nEnter Doctor ID to search: ";
    cin >> id;

    bool found = false;
    for(int i = 0; i < totalDoctors; i++)
    {
        if(doctors[i].doctorId == id)
        {
            cout << "\n--- Doctor Details ---" << endl;
            cout << "Doctor ID        : " << doctors[i].doctorId << endl;
            cout << "Name             : " << doctors[i].name << endl;
            cout << "Specialization   : " << doctors[i].specialization << endl;
            cout << "Phone            : " << doctors[i].phone << endl;
            cout << "Patients Handled : " << doctors[i].patientsHandled << endl;
            found = true;
            break;
        }
    }

    if(!found)
        cout << "\nDoctor with ID " << id << " not found!" << endl;
}

void admitPatient()
{
    if(totalPatients >= 200)
    {
        cout << "\nMaximum patient limit reached!" << endl;
        return;
    }

    Patient p;

    cout << "\n--- Admit New Patient ---" << endl;
    cout << "Enter Patient ID: ";
    cin >> p.patientId;

    for(int i = 0; i < totalPatients; i++)
    {
        if(patients[i].patientId == p.patientId)
        {
            cout << "Patient ID already exists!" << endl;
            return;
        }
    }

    cin.ignore();
    cout << "Enter Name: ";
    getline(cin, p.name);

    cout << "Enter Age: ";
    cin >> p.age;

    cin.ignore();
    cout << "Enter Gender (Male/Female/Other): ";
    getline(cin, p.gender);

    cout << "Enter Disease: ";
    getline(cin, p.disease);

    cout << "Enter Doctor Name: ";
    getline(cin, p.doctorName);

    cout << "Enter Ward (General/ICU/Private/Semi-Private): ";
    getline(cin, p.ward);

    cout << "Enter Admit Date (DD/MM/YYYY): ";
    getline(cin, p.admitDate);

    if(p.ward == "ICU")
        p.billAmount = 5000;
    else if(p.ward == "Private")
        p.billAmount = 3000;
    else if(p.ward == "Semi-Private")
        p.billAmount = 2000;
    else
        p.billAmount = 1000;

    p.discharged = false;

    for(int i = 0; i < totalDoctors; i++)
    {
        if(doctors[i].name == p.doctorName)
        {
            doctors[i].patientsHandled++;
            break;
        }
    }

    patients[totalPatients] = p;
    totalPatients++;

    cout << "\nPatient admitted successfully!" << endl;
    cout << "Initial Bill Amount: " << p.billAmount << " per day" << endl;
}

void displayAllPatients()
{
    if(totalPatients == 0)
    {
        cout << "\nNo patients in the system!" << endl;
        return;
    }

    cout << "\n--- All Patients ---" << endl;
    cout << "--------------------------------------------------------------------------------" << endl;
    cout << "ID\tName\t\tAge\tDisease\t\tWard\t\tStatus" << endl;
    cout << "--------------------------------------------------------------------------------" << endl;

    for(int i = 0; i < totalPatients; i++)
    {
        string status = patients[i].discharged ? "Discharged" : "Admitted";
        cout << patients[i].patientId << "\t"
             << patients[i].name << "\t\t"
             << patients[i].age << "\t"
             << patients[i].disease << "\t\t"
             << patients[i].ward << "\t\t"
             << status << endl;
    }

    cout << "--------------------------------------------------------------------------------" << endl;
    cout << "Total Patients: " << totalPatients << endl;
}

void searchPatient()
{
    int id;
    cout << "\nEnter Patient ID to search: ";
    cin >> id;

    bool found = false;
    for(int i = 0; i < totalPatients; i++)
    {
        if(patients[i].patientId == id)
        {
            string status = patients[i].discharged ? "Discharged" : "Currently Admitted";
            cout << "\n--- Patient Details ---" << endl;
            cout << "Patient ID   : " << patients[i].patientId << endl;
            cout << "Name         : " << patients[i].name << endl;
            cout << "Age          : " << patients[i].age << endl;
            cout << "Gender       : " << patients[i].gender << endl;
            cout << "Disease      : " << patients[i].disease << endl;
            cout << "Doctor       : " << patients[i].doctorName << endl;
            cout << "Ward         : " << patients[i].ward << endl;
            cout << "Admit Date   : " << patients[i].admitDate << endl;
            cout << "Bill Amount  : " << patients[i].billAmount << endl;
            cout << "Status       : " << status << endl;
            found = true;
            break;
        }
    }

    if(!found)
        cout << "\nPatient with ID " << id << " not found!" << endl;
}

void updatePatient()
{
    int id;
    cout << "\nEnter Patient ID to update: ";
    cin >> id;

    bool found = false;
    for(int i = 0; i < totalPatients; i++)
    {
        if(patients[i].patientId == id)
        {
            if(patients[i].discharged)
            {
                cout << "Patient is already discharged. Cannot update." << endl;
                return;
            }

            cin.ignore();
            cout << "Enter New Disease: ";
            getline(cin, patients[i].disease);

            cout << "Enter New Doctor Name: ";
            getline(cin, patients[i].doctorName);

            cout << "Enter New Ward: ";
            getline(cin, patients[i].ward);

            if(patients[i].ward == "ICU")
                patients[i].billAmount = 5000;
            else if(patients[i].ward == "Private")
                patients[i].billAmount = 3000;
            else if(patients[i].ward == "Semi-Private")
                patients[i].billAmount = 2000;
            else
                patients[i].billAmount = 1000;

            cout << "\nPatient record updated successfully!" << endl;
            found = true;
            break;
        }
    }

    if(!found)
        cout << "\nPatient with ID " << id << " not found!" << endl;
}

void dischargePatient()
{
    int id;
    cout << "\nEnter Patient ID to discharge: ";
    cin >> id;

    bool found = false;
    for(int i = 0; i < totalPatients; i++)
    {
        if(patients[i].patientId == id)
        {
            if(patients[i].discharged)
            {
                cout << "Patient is already discharged!" << endl;
                return;
            }

            int days;
            cout << "Enter number of days admitted: ";
            cin >> days;

            float totalBill = patients[i].billAmount * days;
            float tax = totalBill * 0.05;
            float finalBill = totalBill + tax;

            cout << "\n=============================================" << endl;
            cout << "           DISCHARGE SUMMARY                 " << endl;
            cout << "=============================================" << endl;
            cout << "Patient ID   : " << patients[i].patientId << endl;
            cout << "Name         : " << patients[i].name << endl;
            cout << "Disease      : " << patients[i].disease << endl;
            cout << "Doctor       : " << patients[i].doctorName << endl;
            cout << "Ward         : " << patients[i].ward << endl;
            cout << "Days Admitted: " << days << endl;
            cout << "---------------------------------------------" << endl;
            cout << "Rate per Day : " << patients[i].billAmount << endl;
            cout << "Total Charges: " << totalBill << endl;
            cout << "Tax (5%)     : " << tax << endl;
            cout << "=============================================" << endl;
            cout << "FINAL BILL   : " << finalBill << endl;
            cout << "=============================================" << endl;

            patients[i].discharged = true;
            patients[i].billAmount = finalBill;

            cout << "\nPatient discharged successfully!" << endl;
            found = true;
            break;
        }
    }

    if(!found)
        cout << "\nPatient with ID " << id << " not found!" << endl;
}

void bookAppointment()
{
    if(totalAppointments >= 500)
    {
        cout << "\nAppointment limit reached!" << endl;
        return;
    }

    Appointment a;

    cout << "\n--- Book Appointment ---" << endl;
    cout << "Enter Patient ID: ";
    cin >> a.patientId;

    bool patientFound = false;
    for(int i = 0; i < totalPatients; i++)
    {
        if(patients[i].patientId == a.patientId)
        {
            a.patientName = patients[i].name;
            patientFound = true;
            break;
        }
    }

    if(!patientFound)
    {
        cout << "Patient not found! Please admit patient first." << endl;
        return;
    }

    cout << "Enter Doctor ID: ";
    cin >> a.doctorId;

    bool doctorFound = false;
    for(int i = 0; i < totalDoctors; i++)
    {
        if(doctors[i].doctorId == a.doctorId)
        {
            a.doctorName = doctors[i].name;
            doctorFound = true;
            break;
        }
    }

    if(!doctorFound)
    {
        cout << "Doctor not found!" << endl;
        return;
    }

    cin.ignore();
    cout << "Enter Appointment Date (DD/MM/YYYY): ";
    getline(cin, a.date);

    cout << "Enter Appointment Time (HH:MM AM/PM): ";
    getline(cin, a.time);

    a.appointmentId = appointmentCounter++;
    a.status = "Scheduled";

    appointments[totalAppointments] = a;
    totalAppointments++;

    cout << "\nAppointment booked successfully!" << endl;
    cout << "Appointment ID : " << a.appointmentId << endl;
    cout << "Patient        : " << a.patientName << endl;
    cout << "Doctor         : " << a.doctorName << endl;
    cout << "Date & Time    : " << a.date << " at " << a.time << endl;
}

void displayAppointments()
{
    if(totalAppointments == 0)
    {
        cout << "\nNo appointments booked!" << endl;
        return;
    }

    cout << "\n--- All Appointments ---" << endl;
    cout << "--------------------------------------------------------------------------------" << endl;
    cout << "AptID\tPatient\t\tDoctor\t\tDate\t\tTime\t\tStatus" << endl;
    cout << "--------------------------------------------------------------------------------" << endl;

    for(int i = 0; i < totalAppointments; i++)
    {
        cout << appointments[i].appointmentId << "\t"
             << appointments[i].patientName << "\t\t"
             << appointments[i].doctorName << "\t\t"
             << appointments[i].date << "\t\t"
             << appointments[i].time << "\t\t"
             << appointments[i].status << endl;
    }

    cout << "--------------------------------------------------------------------------------" << endl;
}

void cancelAppointment()
{
    int id;
    cout << "\nEnter Appointment ID to cancel: ";
    cin >> id;

    bool found = false;
    for(int i = 0; i < totalAppointments; i++)
    {
        if(appointments[i].appointmentId == id)
        {
            if(appointments[i].status == "Cancelled")
            {
                cout << "Appointment is already cancelled!" << endl;
                return;
            }
            appointments[i].status = "Cancelled";
            cout << "\nAppointment cancelled successfully!" << endl;
            found = true;
            break;
        }
    }

    if(!found)
        cout << "\nAppointment with ID " << id << " not found!" << endl;
}

void hospitalStatistics()
{
    int admitted = 0, discharged = 0;
    float totalRevenue = 0;

    for(int i = 0; i < totalPatients; i++)
    {
        if(patients[i].discharged)
        {
            discharged++;
            totalRevenue += patients[i].billAmount;
        }
        else
            admitted++;
    }

    int scheduledApt = 0;
    for(int i = 0; i < totalAppointments; i++)
    {
        if(appointments[i].status == "Scheduled")
            scheduledApt++;
    }

    cout << "\n--- Hospital Statistics ---" << endl;
    cout << "Total Doctors          : " << totalDoctors << endl;
    cout << "Total Patients         : " << totalPatients << endl;
    cout << "Currently Admitted     : " << admitted << endl;
    cout << "Discharged             : " << discharged << endl;
    cout << "Total Appointments     : " << totalAppointments << endl;
    cout << "Scheduled Appointments : " << scheduledApt << endl;
    cout << "Total Revenue          : " << totalRevenue << endl;
}

void displayAdmittedPatients()
{
    bool any = false;
    cout << "\n--- Currently Admitted Patients ---" << endl;

    for(int i = 0; i < totalPatients; i++)
    {
        if(!patients[i].discharged)
        {
            cout << "ID: " << patients[i].patientId
                 << " | Name: " << patients[i].name
                 << " | Ward: " << patients[i].ward
                 << " | Doctor: " << patients[i].doctorName << endl;
            any = true;
        }
    }

    if(!any)
        cout << "No patients currently admitted." << endl;
}

void doctorMenu()
{
    int choice;
    do
    {
        cout << "\n--- DOCTOR MENU ---" << endl;
        cout << "1. Add Doctor" << endl;
        cout << "2. Display All Doctors" << endl;
        cout << "3. Search Doctor" << endl;
        cout << "4. Back" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        switch(choice)
        {
            case 1: addDoctor(); break;
            case 2: displayAllDoctors(); break;
            case 3: searchDoctor(); break;
            case 4: break;
            default: cout << "Invalid choice!" << endl;
        }
    } while(choice != 4);
}

void patientMenu()
{
    int choice;
    do
    {
        cout << "\n--- PATIENT MENU ---" << endl;
        cout << "1. Admit Patient" << endl;
        cout << "2. Display All Patients" << endl;
        cout << "3. Display Admitted Patients" << endl;
        cout << "4. Search Patient" << endl;
        cout << "5. Update Patient" << endl;
        cout << "6. Discharge Patient" << endl;
        cout << "7. Back" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        switch(choice)
        {
            case 1: admitPatient(); break;
            case 2: displayAllPatients(); break;
            case 3: displayAdmittedPatients(); break;
            case 4: searchPatient(); break;
            case 5: updatePatient(); break;
            case 6: dischargePatient(); break;
            case 7: break;
            default: cout << "Invalid choice!" << endl;
        }
    } while(choice != 7);
}

void appointmentMenu()
{
    int choice;
    do
    {
        cout << "\n--- APPOINTMENT MENU ---" << endl;
        cout << "1. Book Appointment" << endl;
        cout << "2. Display All Appointments" << endl;
        cout << "3. Cancel Appointment" << endl;
        cout << "4. Back" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        switch(choice)
        {
            case 1: bookAppointment(); break;
            case 2: displayAppointments(); break;
            case 3: cancelAppointment(); break;
            case 4: break;
            default: cout << "Invalid choice!" << endl;
        }
    } while(choice != 4);
}

int main()
{
    int choice;

    cout << "==========================================" << endl;
    cout << "      HOSPITAL MANAGEMENT SYSTEM         " << endl;
    cout << "      Mini Project - Summer Assignment   " << endl;
    cout << "==========================================" << endl;

    do
    {
        cout << "\n--- MAIN MENU ---" << endl;
        cout << "1. Doctor Management" << endl;
        cout << "2. Patient Management" << endl;
        cout << "3. Appointment Management" << endl;
        cout << "4. Hospital Statistics" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice)
        {
            case 1: doctorMenu(); break;
            case 2: patientMenu(); break;
            case 3: appointmentMenu(); break;
            case 4: hospitalStatistics(); break;
            case 5: cout << "\nThank you! Exiting the program..." << endl; break;
            default: cout << "\nInvalid choice! Please enter 1-5." << endl;
        }

    } while(choice != 5);

    return 0;
}
