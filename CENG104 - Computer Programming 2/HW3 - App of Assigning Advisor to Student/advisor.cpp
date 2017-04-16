#include <iostream>
#include <fstream>
#include <cstdlib>
#include "advisor.h"
//#include "student.h"
#include "student.cpp"
using namespace std;
void gotoxy(int x,int y){printf("%c[%d;%df", 0x1B, y, x);}

Advisor::Advisor(){}
void Advisor::createAdvisor() // completed
{
    system("clear");
    cout << "*************************************\n"
         << "           CREATE ADVISOR\n"
         << "*************************************" << endl;
    cout << "Please enter the ID of the advisor: "; cin >> advisorId;
    cout << "Please enter the FIRST NAME of the advisor: "; cin >> firstName;
    cout << "Please enter the LAST NAME of the advisor: "; cin >> lastName;
    numberOfStudentsAssigned = 0;
    allowedStudentCount = 3;
    recordAdvisor(advisorId, firstName, lastName, numberOfStudentsAssigned, allowedStudentCount);
    cout << "A new advisor is created." << endl;
    cout << "\nDo you want to add a new advisor? (Y/N): "; string choice; cin >> choice;
    if (choice == "y" || choice == "Y") createAdvisor();
}
int Advisor::showAdvisorList(int x) // completed
{
    system("clear");
    cout << "********************** "
         << " A D V I S O R   L I S T  "
         << "*********************";
    gotoxy(0,5); cout << "ADVISOR ID";
    gotoxy(20,5); cout << "NAME";
    gotoxy(34,5); cout << "SURNAME";
    gotoxy(50,5); cout << "ASSIGNED STATUS" << endl;
    cout << "----------------------------------------------------------------------";
    ifstream file;
    file.open("advisor.txt", ios::in);
    for (int y = 7; !file.eof() == 1; y++)
    {
        file >> advisorId >> firstName >> lastName >> numberOfStudentsAssigned >> allowedStudentCount;
        if (file.eof()) break; // son satiri iki kere yazdirmasini engelliyor
        gotoxy(0,y); cout << advisorId;
        gotoxy(20,y); cout << firstName;
        gotoxy(34,y); cout << lastName;
        gotoxy(50,y); cout << numberOfStudentsAssigned << " / "
                           << allowedStudentCount << endl;
    }
    file.close();

    if (x == 0)
    {
        gotoxy(0,3); cout << "0 <--Menu   1 <--Create Advisor   2 <--Search Advisor";
        gotoxy(60,3); cout << "Choice: "; string choice = "0"; cin >> choice;
        if (choice == "1") createAdvisor();
        else if (choice == "2") showAdvisorDetails();
        else if (choice != "0") showAdvisorList(0);
    }
    else if (x == 1)
    {
        gotoxy(0,3); cout << "Enter the ID of the advisor who you want to assigned: ";
    }
}
void Advisor::showAdvisorDetails() // completed
{
    system("clear");
    cout << "Enter the ID of the advisor who you want find: ";
    unsigned long ID; cin >> ID;
    int control = 0;
    ifstream file;
    file.open("advisor.txt", ios::in);
    while (!file.eof())
    {
        file >> advisorId >> firstName >> lastName >> numberOfStudentsAssigned >> allowedStudentCount;
        if (advisorId == ID)
        {
            system("clear");
            cout << "ID: " << advisorId
                 << "\nName: " << firstName
                 << "\nSurname: " << lastName << endl;
            control = 1;
        }
    }
    file.close();
    if (control == 0) cout << "Advisor is not found !" << endl;
    cout << "\n0 <-- Menu" << endl;
    while (1)
    {
        cout << "Choice: "; string choice; cin >> choice;
        if (choice == "0") break;
    }
}
