#include "ModuleManager.h"
#include <iostream>
#include <limits>

using namespace std;

void ModuleManager::runMenuManager()
{
    int choice;
    bool flag = true;
 
    while (flag)
    {
        cout << "\n----------------------------------\n";
        cout << "Module Manager Menu:\n";
        cout << "1. Add Module\n";
        cout << "2. Display Modules by Year\n";
        cout << "3. Display All Modules\n";
        cout << "4. Back\n";
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
            addModule();
            break;
        case 2:
            displayModulesByYear();
            break;
        case 3:
            displayAllModules();
            break;
        case 4:
            cout << "Exiting.\n";
            flag = false;
            break;
        default:
            cout << "Invalid choice. Please try again.\n";
            break;
        }
    }
}

void ModuleManager::addModule()
{
    unsigned int year;
    string moduleName;
    string moduleId;

    while (true) {
        cout << "Enter the year (1st/2nd/3rd/4th): ";
        if (cin >> year && year >= 1 && year <= 4) {
            cin.ignore(); 
            break;
        }
        cin.clear();  
        cin.ignore();  
        cout << "Invalid year. Please enter a valid year.\n";
    }

    cout << "Enter the module ID: ";
    getline(cin, moduleId);

    cout << "Enter the module name: ";
    getline(cin, moduleName);

    if (year > modules.size())
    {
        modules.resize(year);
    }
    string moduleInfo = moduleId + " - " + moduleName;
    modules[year - 1].push_back(moduleInfo);
    cout << "Module added successfully.\n";
}

void ModuleManager::displayModulesByYear()
{
    int year;
    cout << "Enter the year (1st/2nd/3rd/4th): ";
    cin >> year;
    cin.ignore();

    if (year >= 1 && year <= static_cast<int>(modules.size()))
    {
        const vector<string> &yearModules = modules[year - 1];
        if (!yearModules.empty())
        {
            cout << "\n----------------------------------\n";
            cout << "Year " << year << " Modules:\n";
            for (const string &moduleInfo : yearModules)
            {
                cout << " - " << moduleInfo << '\n';
            }
            cout << "\n----------------------------------\n";
        }
        else
        {
            cout << "No module for Year " << year << ".\n";
        }
    }
    else
    {
        cout << "Invalid year.\n";
    }
}

// {
//     if (modules.empty())
//     {
//         cout << "No Record Found!!  Please Enter Data First\n";
//         return;
//     }
//     for (size_t i = 0; i < modules.size(); ++i)
//     {
//         cout << "\n----------------------------------\n";
//         cout << "Year " << i + 1 << " Modules:\n";
//         if (modules[i].empty())
//         {
//             cout << "No module found\n";
//             cout << "\n----------------------------------\n";
//             continue;
//         }
//         for (const string &moduleName : modules[i])
//         {
//             cout << " - " << moduleName << '\n';
//         }
//         cout << "\n----------------------------------\n";
//     }
// }

void ModuleManager::displayAllModules()
{
    if (modules.empty())
    {
        cout << "No Record Found!!  Please Enter Data First\n";
        return;
    }
    for (size_t i = 0; i < modules.size(); ++i)
    {
        cout << "\n----------------------------------\n";
        cout << "Year " << i + 1 << " Modules:\n";
        if (modules[i].empty())
        {
            cout << "No module found\n";
            cout << "\n----------------------------------\n";
            continue;
        }
        for (const string &moduleInfo : modules[i])
        {
            cout << " - " << moduleInfo << '\n';
        }
        cout << "\n----------------------------------\n";
    }
}
