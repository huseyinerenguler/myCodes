#ifndef CLIENT_H
#include <iostream>
#define CLIENT_H
using namespace std;
#include "account.h"

class Client
{
private:
    string TC;
    string client_name;
    int birt_year;
public:
    Account account;
    Client();
    void setClientInfo (string, string, int);
    //void changePassword ();
    //void printClientInfo ();
};

#endif
