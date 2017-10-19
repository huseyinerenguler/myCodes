#include <iostream>

using namespace std;

template < class T >
T maximum(T num1, T num2, T num3)
{
    T max = num1;

    if (num2 > max)
        max = num2;
    if (num3 > max)
        max = num3;

    return max;
}

int main ()
{
    int num1 = 20, num2 = 1, num3 = 7;
    double double1 = 2.5, double2 = 10.4, double3 = 7.7;

    cout << "Integer: " << num1 << " " << num2 << " " << num3 << endl;
    cout << "Double: " << double1 << " " << double2 << " " << double3 << endl;

    cout << "\nInteger max is: " << maximum(num1, num2, num3) << endl;
    cout << "Double max is: " << maximum(double1, double2, double3) << endl;

    return 0;
}
