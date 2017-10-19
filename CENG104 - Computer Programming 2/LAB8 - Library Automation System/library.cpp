#include <iostream>
#include <cstring>
#include "book.h"
#include "book.cpp"

using namespace std;

void AddBook ();
void BorrowBook ();
void ReturnBook ();
void DisplayBook ();

Book book[10];
int main ()
{
    while (1)
    {
        cout << "------------------------\n"
             << "1 - Add Book\n"
             << "2 - Borrow Book\n"
             << "3 - Return Book\n"
             << "4 - Display Book\n"
             << "5 - EXIT\n"
             << "------------------------" << endl;
        int choice; cin >> choice;

        if (choice == 1) AddBook();
        else if (choice == 2) BorrowBook();
        else if (choice == 3) ReturnBook();
        else if (choice == 4) DisplayBook();
        else return 0;
    }
    return 0;
}

void AddBook ()
{
    string name;
    string author;
    int pageNum;
    static int x = 0;

    cout << "------------------------\n"
         << "ADD BOOK TO LIBRARY\n"
         << "------------------------\n";
    cout << "Enter the NAME of Book: ";cin>>name;
    cout << "Enter the AUTHOR of Book: ";cin>>author;
    cout << "Enter the PAGE NUMBER of Book: ";cin>>pageNum;

    if (pageNum > 0)
    {
        book[x].getBookInfo(name,author,pageNum);
        x++;
    }
    else
        cout << "Invalid Page Number !" << endl;
}

void BorrowBook ()
{
    string name;
    bool control = false;

    cout << "Enter the name of the book that you want to borrow: ";
    cin >> name;

    for (int x = 0; x < 10; x++)
    {
        if (name == book[x].getName())
        {
            book[x].setStatus(0);
            cout <<"Book borrewed succesfully !";
            book[x].printBookInfo();
            control = true;
        }
    }
    if (control == false)
        cout << "No such book is found !" << endl;
}

void ReturnBook ()
{
    string name;

    cout << "Enter the name of the book that you want to return: ";
    cin >> name;

    static int x;
    for (x = 0; x < 10; x++)
    {
        if (book[x].getStatus() == 0)
        {
            if (name == book[x].getName())
            {
                book[x].setStatus(1);
                cout << "Book Returned Succesfully ! ";
                book[x].printBookInfo();
            }
        }
    }
    if (name == book[x].getName())
    {
        cout << "AVAILABLE !" << endl;
    }
}

void DisplayBook ()
{
    cout << "----------------------------\n"
         << "DISPLAY BOOKS IN THE LIBRARY\n"
         << "----------------------------";

    for (int x = 0; x < 10; x++)
    {
        if (book[x].getID() != 0)
        {
            book[x].printBookInfo();
            cout << "----------------------------" << endl;
        }
    }
}
