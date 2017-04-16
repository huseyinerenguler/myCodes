#include <iostream>
#include <fstream>
#include <cstdlib>

#include "advisor.h"
#include "student.h"
using namespace std;

void gotoxy(int x,int y){printf("%c[%d;%df", 0x1B, y, x);}
void recordStudent(unsigned long,string,string,int,double,int);
void recordAdvisor(unsigned long,string,string,int,int);
void deleteRecordAdvisor();
void deleteRecordStudent();
void showRecordAdvisor(unsigned long, int = 1);
void assignStudentToAdvisor(unsigned long);

Student student;
Advisor advisor;

int main ()
{
    while (1)
    {
        system("cls");
        cout << "1 <-- Show Student List\n"
             << "2 <-- Show Advisor List\n"
             << "3 <-- Create Student\n"
             << "4 <-- Create Advisor\n"
             << "5 <-- Assign Student to Advisor\n"
             << "6 <-- Delete Student\n"
             << "7 <-- Delete Advisor\n"
             << "0 <-- EXIT\n\n"
             << "Choice: ";
        int choice; cin >> choice;
        switch (choice)
        {
            case 0:return 0;
            case 1:{student.showStudentList();break;}
            case 2:{advisor.showAdvisorList(0);break;}
            case 3:{student.createStudent();break;}
            case 4:{advisor.createAdvisor();break;}
            case 5:{student.showStudentDetails();break;}
            case 6:{deleteRecordStudent();break;}
			case 7:{deleteRecordAdvisor();break;}
        }
    }
    return 0;
}

void recordStudent (unsigned long id, string name, string surname, int year, double gpa, int flag)
{
    ofstream file;
    file.open("student.txt", ios::app);
    file << id << " " << name << " " << surname << " "
         << year << " " << gpa << " " << flag << endl;
    file.close();
}

void recordAdvisor (unsigned long id, string name, string surname, int numberOfStudentsAssigned, int allowedStudentCount)
{
    ofstream file;
    file.open("advisor.txt", ios::app);
    file << id << " " << name << " " << surname << " "
         << numberOfStudentsAssigned << " " << allowedStudentCount << endl;
    file.close();
}

void deleteRecordStudent()
{
	system("cls");
	cout << "Enter the ID of the student who you want to delete: ";
	unsigned long ID; cin >> ID;
	
	unsigned long studentId;
    string sfirstName;
    string slastName;
    int year;
    double GPA;
    int assignedFlag;	
	
	int control = 0;
	
	ifstream file2; file2.open("student.txt", ios::in);
	ofstream file3; file3.open("yeni.txt", ios::app);
    while(!file2.eof())
    {
		file2 >> studentId >> sfirstName >> slastName >> year >> GPA >> assignedFlag;
		if (file2.eof()) break;
        if (studentId != ID)
        {
        	file3 << studentId << " " << sfirstName << " " << slastName << " "
                  << year << " " << GPA << " " << assignedFlag << endl;
		}		
		else control = 1;	
    }
    file2.close();
    file3.close();
	remove("student.txt");
	rename("yeni.txt","student.txt");
    
    if (control == 0)
    	cout << "Student is not found.\n\n0 <--Menu" << endl;
    else if (control == 1)
    	cout << "Successfully Deleted.\n\n0 <--Menu" << endl;
	while (1)
	{
		cout << "Choice: "; string choice; cin >> choice;
		if (choice == "0") break;
	} 	
}

void deleteRecordAdvisor()
{
	system("cls");
	cout << "Enter the ID of the advisor who you want to delete: ";
	unsigned long ID; cin >> ID;
	
	unsigned long advisorId; // ID of the advisor
    string firstName; // first name of the advisor
    string lastName; // last name of the advisor
    int numberOfStudentsAssigned; // number of students are assigned to advisor
    int allowedStudentCount;	
	
	int control = 0;
	
	ifstream file4; file4.open("advisor.txt", ios::in);
    ofstream file5; file5.open("yeni.txt", ios::app);
    while(!file4.eof())
    {
  	   	file4 >> advisorId >> firstName >> lastName >> numberOfStudentsAssigned >> allowedStudentCount;
  	   	if (file4.eof()) break;
  	   	
       	if (advisorId != ID)
       	{
       		file5 << advisorId << " " << firstName << " " << lastName << " "
           	  << numberOfStudentsAssigned << " " << allowedStudentCount << endl;
		}
		else control = 1;   	
	}
	file4.close();
	file5.close();
	remove("advisor.txt");
    rename("yeni.txt","advisor.txt");
    
    if (control == 0)
    	cout << "Advisor is not found.\n\n0 <--Menu" << endl;
    else if (control == 1)
    	cout << "Successfully Deleted.\n\n0 <--Menu" << endl;
	while (1)
	{
		cout << "Choice: "; string choice; cin >> choice;
		if (choice == "0") break;
	} 
}

void showRecordAdvisor(unsigned long aid, int x)
{
	advisor.showAdvisorDetails(aid,x);
}

void assignStudentToAdvisor(unsigned long sid)
{
    advisor.showAdvisorList(1);
    gotoxy(0,3); cout << "Enter the ID of the advisor who you want to assigned: ";
    unsigned long aid; cin >> aid;
    system("cls");

    unsigned long advisorId; // ID of the advisor
    string firstName; // first name of the advisor
    string lastName; // last name of the advisor
    int numberOfStudentsAssigned; // number of students are assigned to advisor
    int allowedStudentCount;

    unsigned long studentId;
    string sfirstName;
    string slastName;
    int year;
    double GPA;
    int assignedFlag;
    
    int control = 0;
    /*********************************************************************************************/
    ifstream file1;
    file1.open("advisor.txt", ios::in);
    while (!file1.eof())
    {
        file1 >> advisorId >> firstName >> lastName >> numberOfStudentsAssigned >> allowedStudentCount;
        if (file1.eof()) break;
        if (advisorId == aid)
        {
            if (numberOfStudentsAssigned < allowedStudentCount)
            {
            	control = 1;
            	/********************   E D I T E D   S T U D E N T . T X T   ********************/
                ifstream file2; file2.open("student.txt", ios::in);
                ofstream file3; file3.open("yeni.txt", ios::app);
                while(!file2.eof())
                {
                    file2 >> studentId >> sfirstName >> slastName >> year >> GPA >> assignedFlag;
                    if (studentId == sid)
                        assignedFlag = advisorId;
                    if (file2.eof()) break;
                    file3 << studentId << " " << sfirstName << " " << slastName << " "
                         << year << " " << GPA << " " << assignedFlag << endl;
                }
                file2.close();
                file3.close();
                remove("student.txt");
                rename("yeni.txt","student.txt");
                /*********************************************************************************/
            }
            else
            {
            	control = 2;
            	cout << "ERROR: Cannot assign more students to advisor." << endl;
            	cout << "Advisor ID: " << advisorId
                 	 << "\nAdvisor Name: " << firstName
                	 << "\nAdvisor Surname: " << lastName 
					 << "\n\n0 <--Menu" << endl;
                while (1)
				{
					cout << "Choice: "; string choice; cin >> choice;
					if (choice == "0") break;
				}
			}
        }
    }
    file1.close();    
	/*********************************************************************************************/
	/********************   E D I T E D   A D V I S O R . T X T   ********************/
    if (control == 1)
    {
		ifstream file4; file4.open("advisor.txt", ios::in);
    	ofstream file5; file5.open("yeni.txt", ios::app);
        while(!file4.eof())
        {
    	   	file4 >> advisorId >> firstName >> lastName >> numberOfStudentsAssigned >> allowedStudentCount;
           	if (advisorId == aid)
				numberOfStudentsAssigned = numberOfStudentsAssigned + 1;
           	if (file4.eof()) break;
           	file5 << advisorId << " " << firstName << " " << lastName << " "
           		  << numberOfStudentsAssigned << " " << allowedStudentCount << endl;
		}
		file4.close();
		file5.close();
		remove("advisor.txt");
        rename("yeni.txt","advisor.txt");
	/*********************************************************************************/
    	cout << "Successfully Completed.\n\n0 <--Menu" << endl;
		while (1)
		{
			cout << "Choice: "; string choice; cin >> choice;
			if (choice == "0") break;
		}
	}
	/*********************************************************************************************/
    else if (control == 0)
	{
		cout << "Advisor is not found.\n\n0 <--Menu" << endl;
		while (1)
		{
			cout << "Choice: "; string choice; cin >> choice;
			if (choice == "0") break;
		}
	}
}
