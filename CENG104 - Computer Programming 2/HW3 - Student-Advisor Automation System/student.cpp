#include <iostream>
#include <fstream>
#include <cstdlib>

#include "advisor.h"
#include "student.h"
using namespace std;

void gotoxy(int,int);
void recordStudent(unsigned long,string,string,int,double,int);
void showRecordAdvisor(unsigned long, int = 1);
void assignStudentToAdvisor(unsigned long);

Student::Student(){}

void Student::createStudent()
{
    system("cls");
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
    cout << "A new student is created.\n" << endl;
    
    cout << "Do you want to add a new student? (Y/N): "; string choice; cin >> choice;
    if (choice == "y" || choice == "Y") createStudent();
}

void Student::showStudentList()
{
    system("cls");
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
        if (file.eof()) break;
        gotoxy(0,y); cout << studentId;
        gotoxy(17,y); cout << firstName;
        gotoxy(28,y); cout << lastName;
        gotoxy(42,y); cout << year;
        gotoxy(53,y); cout << GPA;
        gotoxy(63,y); 
		if (assignedFlag == 0) cout << "No Advisor";
		else showRecordAdvisor(assignedFlag);
    }
    file.close();
    
    gotoxy(60,3); cout << "Choice: "; string choice; cin >> choice;
    if (choice == "1") createStudent();
    else if (choice == "2") showStudentDetails();
    else if (choice != "0") showStudentList();
}

void Student::showStudentDetails()
{
    system("cls");
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
            system("cls");
            cout << "ID: " << studentId
                 << "\nName: " << firstName
                 << "\nSurname: " << lastName
                 << "\nYear: " << year
                 << "\nGPA: " << GPA
                 << "\nAdvisor: ";
            if (assignedFlag != 0)
                showRecordAdvisor(assignedFlag,2);
            else cout << "No Advisor" << endl;
            cout << "-------------------------------------" << endl;
            
            currentStatus();
            control = 1;
            break;
        }
    }
    file.close();
    
    if (control == 0) cout << "Student is not found !" << endl;
    cout << "\n0 <--Menu" << endl;
    if (control != 0) cout << "1 <--Assign Student to Advisor" << endl;
    while (1)
    {
        cout << "Choice: "; string choice; cin >> choice;
        if (choice == "0") break;
        if (control != 0 && choice == "1") assignStudentToAdvisor(studentId); break;        
    }
}

bool Student::isSuccessful()
{
    if (GPA >= 2.5) return true;
    else return false;
}

void Student::currentStatus()
{
    if (isSuccessful())
        cout << "STUDENT: " << firstName << " " << lastName << " SUCCESSFUL" << endl;
    else if (!isSuccessful())
        cout << "STUDENT: " << firstName << " " << lastName << " NOT SUCCESSFUL" << endl;
}
