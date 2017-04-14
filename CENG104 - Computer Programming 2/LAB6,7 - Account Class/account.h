#ifndef ACCOUNT_H
#define ACCOUNT_H
using namespace std;
class Account
{
private:
    int ID;
    string password;
    float balance;
public:
    Account();
    void setAccount(int, string, float);
    void printAccountInfo ();
    int withdraw(int);
    void deposit(int);
};

#endif
