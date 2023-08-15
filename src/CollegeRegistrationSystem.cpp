#include "CollegeRegistrationSystem.h"
#include <iostream>
#include <limits>

using namespace std;

void CollegeRegistrationSystem::addRecord()
{
    string name;
    int rollNumber;
    string mobileNumber;
    string collegeYear;
    string bloodGroup;

    while (true)
    {
        cout << "Enter student name: ";
        getline(cin, name);

        if (!name.empty())
        {
            break;
        }
        else
        {
            cout << "Name cannot be empty. Please enter a valid name.\n";
        }
    }

    while (true)
    {
        bool isRollNumberUnique = true;

        cout << "Enter roll number: ";
        if (!(cin >> rollNumber))
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a number.\n";
            continue;
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        for (const Student &student : studentRecords)
        {
            if (student.getRollNumber() == rollNumber)
            {
                isRollNumberUnique = false;
                cout << "Roll number already exists. Please enter a different roll number.\n";
                break;
            }
        }

        if (isRollNumberUnique)
        {
            break;
        }
    }

    cout << "Enter mobile number: ";
    getline(cin, mobileNumber);

    cout << "Enter college year: ";
    getline(cin, collegeYear);

    cout << "Enter blood group: ";
    getline(cin, bloodGroup);

    Student student(name, rollNumber, mobileNumber, collegeYear, bloodGroup);
    studentRecords.push_back(student);

    cout << "Record added successfully.\n";
}

void CollegeRegistrationSystem::updateRecord()
{
    int rollNumber;
    cout << "Enter roll number to update: ";
    cin >> rollNumber;
    cin.ignore();

    for (Student &student : studentRecords)
    {
        if (student.getRollNumber() == rollNumber)
        {
            string newName;
            cout << "Enter updated name: ";
            getline(cin, newName);
            if (!newName.empty())
            {
                student.setName(newName);
            }

            string newMobileNumber;
            cout << "Enter updated mobile number: ";
            getline(cin, newMobileNumber);
            if (!newMobileNumber.empty())
            {
                student.setMobileNumber(newMobileNumber);
            }

            string newCollegeYear;
            cout << "Enter updated college year: ";
            getline(cin, newCollegeYear);
            if (!newCollegeYear.empty())
            {
                student.setCollegeYear(newCollegeYear);
            }

            string newBloodGroup;
            cout << "Enter updated blood group: ";
            getline(cin, newBloodGroup);
            if (!newBloodGroup.empty())
            {
                student.setBloodGroup(newBloodGroup);
            }

            cout << "Record updated successfully.\n";
            return;
        }
    }
    cout << "Record not found.\n";
}

void CollegeRegistrationSystem::getAnyRecord()
{
    int rollNumber;
    cout << "Enter roll number to retrieve: ";
    cin >> rollNumber;

    for (const Student &student : studentRecords)
    {
        if (student.getRollNumber() == rollNumber)
        {
            cout << "\n----------------------------------\n";
            cout << "Name: " << student.getName() << endl;
            cout << "Roll Number: " << student.getRollNumber() << endl;
            cout << "Mobile Number: " << student.getMobileNumber() << endl;
            cout << "College Year: " << student.getCollegeYear() << endl;
            cout << "Blood Group: " << student.getBloodGroup() << endl;
            cout << "\n----------------------------------\n";
            return;
        }
    }
    cout << "Record not found.\n";
}

void CollegeRegistrationSystem::getAllRecords()
{
    if (studentRecords.empty())
    {
        cout << "No Record Found!! Please Enter Data First\n";
        return;
    }
    for (const Student &student : studentRecords)
    {
        cout << "\n----------------------------------\n";
        cout << "Roll Number: " << student.getRollNumber() << endl;
        cout << "Name: " << student.getName() << endl;
        cout << "Mobile Number: " << student.getMobileNumber() << endl;
        cout << "College Year: " << student.getCollegeYear() << endl;
        cout << "Blood Group: " << student.getBloodGroup() << endl;
        cout << endl;
        cout << "\n----------------------------------\n";
    }
}

void CollegeRegistrationSystem::runMenu()
{
    char choice;
    bool flag = true;
    while (flag)
    {
        cout << "\n----------------------------------\n";
        cout << "Menu:\n";
        cout << "1. Add Record\n";
        cout << "2. Update Record\n";
        cout << "3. Get Any Record\n";
        cout << "4. Get All Records\n";
        cout << "5. Back\n";
        cout << "\n----------------------------------\n";

        cout << "Enter your choice: ";
        cin>>choice;

        switch (choice)
        {
        case '1':
            addRecord();
            break;
        case '2':
            updateRecord();
            break;
        case '3':
            getAnyRecord();
            break;
        case '4':
            getAllRecords();
            break;
        case '5':
            cout << "Exiting.\n";
            flag = false;
            break;
        default:
            cout << "Invalid choice. Please try again.\n";
            break;
        }
    }
}
