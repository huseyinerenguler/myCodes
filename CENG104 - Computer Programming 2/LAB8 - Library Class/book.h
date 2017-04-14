#ifndef BOOK_H
#define BOOK_H

using namespace std;

class Book
{
private:
    int ID;
    string name;
    string author;
    int pageNum;
    bool status;
public:
    Book();
    void getBookInfo(string,string,int);
    void printBookInfo();
    string getName();
    void setStatus(int);
    bool getStatus();
    int getID();
};
#endif
