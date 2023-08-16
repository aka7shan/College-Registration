#ifndef MODULEMANAGER_H
#define MODULEMANAGER_H

#include <vector>
#include <string>

class ModuleManager
{
private:
    // std::vector<std::vector<std::string>> modules;
    std::vector<std::vector<std::string>> modules;

public:
    void addModule();
    void displayModulesByYear();
    void displayAllModules();
    void runMenuManager();
};

#endif
