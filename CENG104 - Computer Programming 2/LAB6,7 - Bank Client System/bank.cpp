#include <iostream>
using namespace std;

#include "bank.h"

Bank::Bank () {bank_name = "HKG BANK";}

void Bank::setAccountInfo (Client *c)
{
    string pass1;
    float balance1;
    int ID = 1;

    cout << "Enter password: "; cin >> pass1;
    cout << "Enter balance: "; cin >> balance1;

    c->account.setAccount (ID, pass1, balance1);
}
