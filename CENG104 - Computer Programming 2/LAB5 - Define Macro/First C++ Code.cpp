#include <iostream>
using namespace std;

inline double rectangle_Area (double x, double y) {return x*y;}

void hello (string name = "there");

int main ()
{
    /*int first, second;
    cout << "Enter first integer " << endl; cin >> first;
    cout << "Enter second integer " << endl; cin >> second;
    cout << "Multiplication of " << first
         << " and " << second << " is "
         << first + second << endl;

    double side1, side2;
    cout << "\nEnter side1 of rectangle: "; cin >> side1;
    cout << "Enter side2 of rectangle: "; cin >> side2;
    cout << "If sides are " << side1 << " and " << side2
         << ", Area of the rectangle is "
         << rectangle_Area(side1, side2) << endl;
    */
    hello();
    hello("Huso");
    hello("Huso Basgan");

    return 0;
}

void hello (string name)
{
    cout << "Hello " << name << endl;
}
