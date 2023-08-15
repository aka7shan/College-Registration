#ifndef STUDENT_H
#define STUDENT_H

#include <string>
using namespace std;

class Student
{
private:
    string name;
    int rollNumber;
    string mobileNumber;
    string collegeYear;
    string bloodGroup;

public:
    Student(const string &name, int rollNumber, const string &mobileNumber, const string &collegeYear, const string &bloodGroup);
    void setName(const string &newName);
    void setRollNumber(int newRollNumber);
    void setMobileNumber(const string &newMobileNumber);
    void setCollegeYear(const string &newCollegeYear);
    void setBloodGroup(const string &newBloodGroup);
    string getName() const;
    int getRollNumber() const;
    string getMobileNumber() const;
    string getCollegeYear() const;
    string getBloodGroup() const;
};

#endif
