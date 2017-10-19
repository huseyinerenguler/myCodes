#include <iostream>
#include "account.h"

using namespace std;

Account::Account ()
{
    ID = 0;
    password = 'd';
    balance = 0.0;
}

void Account::setAccount (int Id, string Password, float Balance)
{
    ID = Id;
    password = Password;
    balance = Balance;
}

void Account::printAccountInfo ()
{
    cout << "\nAccount Info\n"
         << "\nID: " << ID
         << "\nPassword: " << password
         << "\nBalance: " << balance << endl;
}

int Account::withdraw (int money)
{
    if (money > balance)
        return 0;
    else if (money <= balance)
    {
        balance = balance - money;
        return 1;
    }
}

void Account::deposit (int money)
{
    balance = balance + money;
}
