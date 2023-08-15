#include "CollegeRegistrationSystem.h"
#include "ModuleManager.h"
#include <iostream>

using namespace std;

int main()
{
    ModuleManager moduleManager;
    CollegeRegistrationSystem registrationSystem;

    char choice;
    bool flag = true;
    while (flag)
    {
        cout << "\n----------------------------------\n";
        cout << "Menu:\n";
        cout << "1. College Registration System\n";
        cout << "2. Module Manager\n";
        cout << "3. Exit\n";
        cout << "\n----------------------------------\n";

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case '1':
            registrationSystem.runMenu();
            break;
        case '2':
            moduleManager.runMenuManager();
            break;
        case '3':
            cout << "Exiting.\n";
            flag = false;
            break;
        default:
            cout << "Invalid choice. Please try again.\n";
        }
    }
    return 0;
}
