#include <iostream>
#include <fstream>
#include <cstdlib>

//#include "advisor.h"
#include "advisor.cpp"
#include "student.h"

using namespace std;

void gotoxy(int x,int y){printf("%c[%d;%df", 0x1B, y, x);}
Student::Student(){}
void Student::createStudent() // completed
{
    system("clear");
    cout << "*************************************\n"
         << "           CREATE STUDENT\n"
         << "*************************************" << endl;

    cout << "Please enter the ID of the student: "; cin >> studentId;
    cout << "Please enter the FIRST NAME of the student: "; cin >> firstName;
    cout << "Please enter the LAST NAME of the student: "; cin >> lastName;
    while (1)
    {
        cout << "Please enter the YEAR of the student(1-4): "; cin >> year;
        if (year >= 1 && year <= 4 ) break;
        else
        {
            cout << "**************************************\n"
                 << "ERROR: Wrong year value for student: " << year
                 << "\n**************************************" << endl;
        }
    }
    while (1)
    {
        cout << "Please enter the GPA of the student(0-4): "; cin >> GPA;
        if (GPA >= 0 && GPA <= 4 ) break;
        else
        {
            cout << "*************************************\n"
                 << "ERROR: Wrong GPA value for student: " << GPA
                 << "\n*************************************" << endl;
        }
    }
    assignedFlag = 0;
    recordStudent(studentId, firstName, lastName, year, GPA, assignedFlag);
    cout << "A new student is created." << endl;
    cout << "\nDo you want to add a new student? (Y/N): "; string choice; cin >> choice;
    if (choice == "y" || choice == "Y") createStudent();
}
void Student::showStudentList() // completed
{
    system("clear");
    cout << "********************** "
         << " S T U D E N T  L I S T  "
         << "*********************";

    gotoxy(0,3); cout << "0 <--Menu    1 <--Create Student    2 <--Search Student";
    gotoxy(0,5); cout << "STUDENT ID";
    gotoxy(17,5); cout << "NAME";
    gotoxy(28,5); cout << "SURNAME";
    gotoxy(42,5); cout << "YEAR";
    gotoxy(53,5); cout << "GPA";
    gotoxy(63,5); cout << "ADVISOR" << endl;
    cout << "---------------------------------------------------------------------";

    ifstream file;
    file.open("student.txt", ios::in);
    for (int y = 7; !file.eof() == 1; y++)
    {
        file >> studentId >> firstName >> lastName >> year >> GPA >> assignedFlag;
        if (file.eof()) break; // son satiri iki kere yazdirmasini engelliyor

        gotoxy(0,y); cout << studentId;
        gotoxy(17,y); cout << firstName;
        gotoxy(28,y); cout << lastName;
        gotoxy(42,y); cout << year;
        gotoxy(53,y); cout << GPA;
        gotoxy(63,y); if (assignedFlag != 1) cout << "No Advisor";
    }
    file.close();
    gotoxy(60,3); cout << "Choice: "; string choice; cin >> choice;
    if (choice == "1") createStudent();
    else if (choice == "2") showStudentDetails();
    else if (choice != "0") showStudentList();
}
void Student::showStudentDetails() // completed
{
    system("clear");
    cout << "Enter the ID of the student who you want find: ";
    unsigned long ID; cin >> ID;
    int control = 0;
    ifstream file;
    file.open("student.txt", ios::in);
    while (!file.eof())
    {
        file >> studentId >> firstName >> lastName >> year >> GPA >> assignedFlag;
        if (studentId == ID)
        {
            system("clear");
            cout << "ID: " << studentId
                 << "\nName: " << firstName
                 << "\nSurname: " << lastName
                 << "\nYear: " << year
                 << "\nGPA: " << GPA
                 << "\nAdvisor: ";
            if (assignedFlag == 0)
                cout << "No ";
            else cout << "No Advisor" << endl;
            cout << "-------------------------------------" << endl;
            currentStatus();
            control = 1;
            break;
        }
    }
    file.close();
    if (control == 0) cout << "Student is not found !" << endl;
    cout << "\n0 <--Menu\n1 <--Assign Student to Advisor" << endl;
    while (1)
    {
        cout << "Choice: "; string choice; cin >> choice;
        if (choice == "0") break;
        else if (choice == "1") assignStudentToAdvisor(studentId); break;
    }
}
bool Student::isSuccessful() // completed
{
    if (GPA >= 2.5) return true;
    else return false;
}
void Student::currentStatus() // completed
{
    if (isSuccessful())
        cout << "STUDENT: " << firstName << " " << lastName << " SUCCESSFUL" << endl;
    else if (!isSuccessful())
        cout << "STUDENT: " << firstName << " " << lastName << " NOT SUCCESSFUL" << endl;
}
