#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

void gotoxy(int x,int y){printf("%c[%d;%df", 0x1B, y, x);}
void recordStudent(unsigned long,string,string,int,double,int);
void recordAdvisor(unsigned long,string,string,int,int);
void assignStudentToAdvisor(unsigned long);
void editStudentRecord();

class Advisor
{
private:
    unsigned long advisorId; // ID of the advisor
    string firstName; // first name of the advisor
    string lastName; // last name of the advisor
    int numberOfStudentsAssigned; // number of students are assigned to advisor
    int allowedStudentCount;
public:
    Advisor(){}
    void createAdvisor() // completed
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
    int showAdvisorList(int x) // completed
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
    void showAdvisorDetails() // completed
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
};
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
    Student(){}
    void createStudent() // completed
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
    void showStudentList() // completed
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
    void showStudentDetails() // completed
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
                if (assignedFlag == 1)
                    cout << "Deneme";
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
    bool isSuccessful() // completed
    {
        if (GPA >= 2.5) return true;
        else return false;
    }
    void currentStatus() // completed
    {
        if (isSuccessful())
            cout << "STUDENT: " << firstName << " " << lastName << " SUCCESSFUL" << endl;
        else if (!isSuccessful())
            cout << "STUDENT: " << firstName << " " << lastName << " NOT SUCCESSFUL" << endl;
    }
};
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
void editStudentRecord()
{

}
