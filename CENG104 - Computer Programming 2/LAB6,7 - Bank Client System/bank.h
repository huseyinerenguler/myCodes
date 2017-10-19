#ifndef BANK_H
#define BANK_H
using namespace std;
#include "client.h"

class Bank
{
public:
    string bank_name;
public:
    Bank();
    void setAccountInfo (Client *c);
    //void transferMoney (Account *a, Account *b);
};

#endif
