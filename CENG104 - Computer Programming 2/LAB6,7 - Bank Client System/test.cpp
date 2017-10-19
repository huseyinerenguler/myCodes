#include <iostream>
using namespace std;

#include "account.h"
#include "account.cpp"
#include "bank.h"
#include "bank.cpp"
#include "client.h"
#include "client.cpp"

int main ()
{
    Client c1, c2;
    Bank bank;

    string name;
    int TC, birth_year;

    cout << "Enter your TC: "; cin >> TC;
    cout << "Enter your name: "; cin >> name;
    cout << "Enter your birth year: "; cin >> birth_year;

    cout << "Welcome to " << bank.bank_name << endl;

    bank.setAccountInfo (&c1);
    c1.setClientInfo (TC, name, birth_year);

    return 0;
}
