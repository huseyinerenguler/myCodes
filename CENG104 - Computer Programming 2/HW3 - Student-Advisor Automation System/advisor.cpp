#include <iostream>
#include <fstream>
#include <cstdlib>

#include "advisor.h"
#include "student.h"
using namespace std;

void gotoxy(int,int);
void recordAdvisor(unsigned long,string,string,int,int);

Advisor::Advisor(){}

void Advisor::createAdvisor()
{
    system("cls");
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

void Advisor::showAdvisorList(int x)
{
    system("cls");
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
        if (file.eof()) break;
        gotoxy(0,y); cout << advisorId;
        gotoxy(20,y); cout << firstName;
        gotoxy(34,y); cout << lastName;
        gotoxy(50,y); cout << numberOfStudentsAssigned << " / " << allowedStudentCount << endl;
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
}

void Advisor::showAdvisorDetails(unsigned long id, int x)
{
	unsigned long ID;
	if (id == 0)
	{
		system("cls");
    	cout << "Enter the ID of the advisor who you want find: ";
    	 cin >> ID;
	}
	else ID = id;
    
    int control = 0;
    
    ifstream file;
    file.open("advisor.txt", ios::in);
    while (!file.eof())
    {
        file >> advisorId >> firstName >> lastName >> numberOfStudentsAssigned >> allowedStudentCount;
        if (advisorId == ID)
        {
        	if (file.eof()) break;
        	if (x==0 || x==2)
            	cout << "ID: " << advisorId << endl;
            if (x==0 || x==2)
            	cout << "Name: ";
            cout << firstName;
            if (x==0 || x==2)
            	cout << "\nSurname:";
            cout << " " << lastName;
            if (x==0 || x==2)
            	cout << "\n";
            control = 1;
        }
    }
    file.close();
    
    if (control == 0) cout << "Advisor is not found !" << endl;
    if (x==0)
    {
    	cout << "\n0 <-- Menu" << endl;
		while (1)
    	{
       		cout << "Choice: "; string choice; cin >> choice;
        	if (choice == "0") break;
    	}
	}
}
