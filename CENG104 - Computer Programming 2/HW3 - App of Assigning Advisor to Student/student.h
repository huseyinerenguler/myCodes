#ifndef STUDENT_H
#define STUDENT_H

#include "advisor.h"
using namespace std;

class Student
{
private:
    unsigned long studentId; // ID of the student
    string firstName; // first name of the student
    string lastName; // last name of the student
    int year; // between 1 and 4
    double GPA; // between 0 and 4
    //Advisor advisor;
    int assignedFlag; // 0 or 1
public:
    Student();
    void createStudent();
    void showStudentList();
    void showStudentDetails();
    bool isSuccessful();
    void currentStatus();
};
#endif
