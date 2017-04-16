#include <iostream>
#include <fstream>
#include <cstdlib>
//#include "advisor.h"
#include "advisor.cpp"
//#include "student.h"
#include "student.cpp"
using namespace std;

void gotoxy(int x,int y){printf("%c[%d;%df", 0x1B, y, x);}
void recordStudent(unsigned long,string,string,int,double,int);
void recordAdvisor(unsigned long,string,string,int,int);
void assignStudentToAdvisor(unsigned long);

Student student;
Advisor advisor;
int main ()
{
    while (1)
    {
        system("clear");
        cout << "1 <-- Show Student List\n"
             << "2 <-- Show Advisor List\n"
             << "3 <-- Create Student\n"
             << "4 <-- Create Advisor\n"
             << "5 <-- Assign Student to Advisor\n"
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
void assignStudentToAdvisor(unsigned long sid)
{
    advisor.showAdvisorList(1);
    unsigned long aid; cin >> aid;
    system("clear");

    unsigned long advisorId; // ID of the advisor
    string firstName; // first name of the advisor
    string lastName; // last name of the advisor
    int numberOfStudentsAssigned; // number of students are assigned to advisor
    int allowedStudentCount;
    int control = 0;

    unsigned long studentId;
    string sfirstName;
    string slastName;
    int year;
    double GPA;
    int assignedFlag;
    //***************************************************************************************************
    ifstream file1;
    file1.open("advisor.txt", ios::in);
    while (!file1.eof())
    {
        file1 >> advisorId >> firstName >> lastName >> numberOfStudentsAssigned >> allowedStudentCount;
        if (file1.eof()) break;
        if (advisorId == aid)
        {
            control = 1;
            if (numberOfStudentsAssigned < allowedStudentCount) // assign islemi yapilacak
            {
                ifstream file2;
                file2.open("student.txt", ios::in);
                ofstream file3;
                file3.open("yeni.txt", ios::app);
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
            }
            else cout << "yapamazsin" << endl; // warning gelicek
        }
    }
    file1.close();
    if (control == 0) cout << "!!!Advisor is not found !" << endl;

    cin >> control;


}
