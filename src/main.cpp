#include "CollegeRegistrationSystem.h"
#include "ModuleManager.h"
#include <iostream>
#include <limits>

using namespace std;

int main()
{
    ModuleManager moduleManager;
    CollegeRegistrationSystem registrationSystem;

    int choice;
    bool flag = true;
    while (flag)
    {
        cout << "\n----------------------------------\n";
        cout << "Menu:\n";
        cout << "1. College Registration System\n";
        cout << "2. Module Manager\n";
        cout << "3. Exit\n";
        cout << "\n----------------------------------\n";

        while (true) {
       cout << "Enter your choice: ";
        if (cin >> choice) {
            cin.ignore(); 
            break;
        }
        cin.clear();  
        cin.ignore(numeric_limits<streamsize>::max(), '\n');  
        cout << "Invalid Input. Please enter a again.\n";
    }

        switch (choice)
        {
        case 1:
            registrationSystem.runMenu();
            break;
        case 2:
            moduleManager.runMenuManager();
            break;
        case 3:
            cout << "Exiting.\n";
            flag = false;
            break;
        default:
            cout << "Invalid choice. Please try again.\n";
        }
    }
    return 0;
}
