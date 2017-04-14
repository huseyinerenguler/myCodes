#include <iostream>
#include <fstream> // dosya islemleri
#include <cstdlib>
using namespace std;

void gotoxy (int x,int y){printf("%c[%d;%df", 0x1B, y, x);}
void recordStudent (unsigned long,string,string,int,double);
void recordAdvisor (unsigned long,string,string,int,int);

class Advisor
{
private:
    unsigned long advisorId; // ID of the advisor
    string firstName; // first name of the advisor
    string lastName; // last name of the advisor
public:
    int numberOfStudentsAssigned; // number of students are assigned to advisor
    int allowedStudentCount;
public:
    void createAdvisor ()
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
    }
    void showAdvisorDetails ()
    {
        ifstream file;
        file.open("advisor.txt", ios::in);
        while (!file.eof())
        {
            file >> advisorId >> firstName >> lastName;
            if (file.eof()) break; // son satiri iki kere yazdirmasini engelliyor
            cout << advisorId << " " << firstName << " " << lastName << endl;
        }
        file.close();
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
    Student ()
    {
        GPA = 3;
    }
    void createStudent ()
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
            cout << "Please enter the YEAR of the student: "; cin >> year;
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
            cout << "Please enter the GPA of the student: "; cin >> GPA;
            if (GPA >= 0 && GPA <= 4 ) break;
            else
            {
                cout << "*************************************\n"
                     << "ERROR: Wrong GPA value for student: " << GPA
                     << "\n*************************************" << endl;
            }
        }
        recordStudent(studentId, firstName, lastName, year, GPA);
        cout << "A new student is created." << endl;
    }
    void showStudentDetails ()
    {
        system("clear");
        cout << "********************** "
             << " S T U D E N T  L I S T  "
             << "*********************";
        gotoxy(0,2); cout << "STUDENT ID";
        gotoxy(17,2); cout << "NAME";
        gotoxy(28,2); cout << "SURNAME";
        gotoxy(42,2); cout << "YEAR";
        gotoxy(53,2); cout << "GPA";
        gotoxy(63,2); cout << "ADVISOR";

        ifstream file;
        file.open("student.txt", ios::in);
        for (int y = 4; !file.eof() == 1; y++)
        {
            file >> studentId >> firstName >> lastName >> year >> GPA;
            if (file.eof()) break; // son satiri iki kere yazdirmasini engelliyor

            gotoxy(0,y); cout << studentId;
            gotoxy(17,y); cout << firstName;
            gotoxy(28,y); cout << lastName;
            gotoxy(42,y); cout << year;
            gotoxy(53,y); cout << GPA;
            gotoxy(63,y); cout << " ";
        }
        file.close();
        cout << "\n\nPress any key to return menu..";string c;cin >> c;
    }
    bool isSuccessful ()
    {
        if (GPA >= 2.5) return true;
        else return false;
    }
    void currentStatus ()
    {
        if (isSuccessful())
            cout << "STUDENT: " << firstName << " " << lastName << "SUCCESSFUL" << endl;
        else if (!isSuccessful())
            cout << "STUDENT: " << firstName << " " << lastName << "NOT SUCCESSFUL" << endl;
    }
};

int main ()
{
    while (1)
    {
        system("clear");
        cout << "1) Show Student List\n"
             << "2) Show Advisor List\n"
             << "3) Create Student\n"
             << "4) Create Advisor\n"
             << "0) EXIT";
        int choice; cin >> choice;

        switch (choice)
        {
            case 1:
            {
                Student student1;
                student1.showStudentDetails();
                break;
            }
            case 3:
            {
                char choice1 = 'y';
                while (choice1 == 'y' || choice1 == 'Y')
                {
                    Student student;
                    student.createStudent();
                    cout << "\nDo you want to add a new student? (Y/N): "; cin >> choice1;
                }
                break;
            }
            case 4:
            {
                char choice1 = 'y';
                while (choice1 == 'y' || choice1 == 'Y')
                {
                    Advisor advisor;
                    advisor.createAdvisor();
                    cout << "\nDo you want to add a new advisor? (Y/N): "; cin >> choice1;
                }
                break;
            }
        }
        cout << "\n\n";
    }

    return 0;
}

void recordStudent (unsigned long id, string name, string surname, int year, double gpa)
{
    ofstream file;
    file.open("student.txt", ios::app);
    file << id << " " << name << " " << surname << " "
         << year << " " << gpa << endl;
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
