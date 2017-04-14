#include <iostream>
#include "book.h"

using namespace std;

Book::Book ()
{
    ID = 0;
    name = "noName";
    author = "NoAuthor";
    pageNum = 0;
    status = true;
}

void Book::getBookInfo (string name0, string author0, int pageNum0)
{
    static int x = 1;
    ID = x;
    name = name0;
    author = author0;
    pageNum = pageNum0;
    status = true;
    x++;
}

void Book::printBookInfo ()
{
    cout << "\nID: " << ID
         << "\nName: " << name
         << "\nPage Num: " << pageNum
         << "\nAuthor: " << author << endl;
    if (status == 1)
        cout << "Status: Available" << endl;
    else if (status == 0)
        cout << "Status: Borrowed" << endl;
}

string Book::getName (){return name;}

void Book::setStatus (int x)
{
    if (x == 0)
        status = false;
    else if (x == 1)
        status = true;
}
bool Book::getStatus(){return status;}

int Book::getID(){return ID;}
