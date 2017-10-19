#include <iostream>
using namespace std;

#include "client.h"

Client::Client () {}

void Client::setClientInfo (string tc, string name, int year)
{
    TC = tc;
    client_name = name;
    birt_year = year;
}
