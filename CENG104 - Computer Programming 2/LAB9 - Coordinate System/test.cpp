#include <iostream>
#include <cmath>
#include "Point.cpp"
#include "Distance.cpp"
#define SIZE 3

int main ()
{
    Point p1(3,8);
    Point p2(6,2);
    Distance distance(p1,p2);

    p1.printPoint();
    p1.calculateMagnitude();
    p2.printPoint();
    p2.calculateMagnitude();
    distance.calculateDistance();

    int x,y;
    Point point[SIZE];
    for(int c = 0; c < SIZE; c++)
    {
        cout << "Enter the coordinates for " << c+1 << ". point: ";
        cin >> x >> y;
        point[c].setPoint(x,y);
        distance.setDistance(point[c],c);
    }
    distance.calculateDistance2();

    return 0;
}
