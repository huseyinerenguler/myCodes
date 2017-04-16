#ifndef ADVISOR_H
#define ADVISOR_H

#include "student.h"
using namespace std;

class Advisor
{
private:
    unsigned long advisorId; // ID of the advisor
    string firstName; // first name of the advisor
    string lastName; // last name of the advisor
    int numberOfStudentsAssigned; // number of students are assigned to advisor
    int allowedStudentCount;
public:
    Advisor();
    void createAdvisor();
    int showAdvisorList(int x);
    void showAdvisorDetails();
};

#endif
