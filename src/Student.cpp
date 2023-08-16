#include "Student.h"
using namespace std;

Student::Student(const string &name, int rollNumber, const string &mobileNumber, const string &collegeYear, const string &bloodGroup)
{
    this->name = name;
    // Student::name= name;
    this->rollNumber = rollNumber;
    this->mobileNumber = mobileNumber;
    this->collegeYear = collegeYear;
    this->bloodGroup = bloodGroup;
}

void Student::setName(const string &newName)
{
    name = newName;
}

void Student::setRollNumber(int newRollNumber)
{
    rollNumber = newRollNumber;
}

void Student::setMobileNumber(const string &newMobileNumber)
{
    mobileNumber = newMobileNumber;
}

void Student::setCollegeYear(const string &newCollegeYear)
{
    collegeYear = newCollegeYear;
}

void Student::setBloodGroup(const string &newBloodGroup)
{
    bloodGroup = newBloodGroup;
}

string Student::getName() const
{
    return name;
}

int Student::getRollNumber() const
{
    return rollNumber;
}

string Student::getMobileNumber() const
{
    return mobileNumber;
}

string Student::getCollegeYear() const
{
    return collegeYear;
}

string Student::getBloodGroup() const
{
    return bloodGroup;
}
