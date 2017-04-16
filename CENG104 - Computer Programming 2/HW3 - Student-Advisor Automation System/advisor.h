#ifndef ADVISOR_H
#define ADVISOR_H

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
    void showAdvisorList(int);
    void showAdvisorDetails(unsigned long = 0, int = 0);
};

#endif
