#ifndef COLLEGEREGISTRATIONSYSTEM_H
#define COLLEGEREGISTRATIONSYSTEM_H

#include <vector>
#include "Student.h"

class CollegeRegistrationSystem
{
private:
    std::vector<Student> studentRecords;

public:
    void addRecord();
    void updateRecord();
    void getAnyRecord();
    void getAllRecords();
    void runMenu();
};

#endif
