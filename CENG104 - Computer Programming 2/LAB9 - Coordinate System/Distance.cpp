#include <iostream>
#include "Distance.h"
using namespace std;

Distance::Distance(Point x, Point y){p1=x; p2=y;}
void Distance::setDistance(Point p1, int c)
{
    point[c] = p1;
}
void Distance::calculateDistance()
{
    distance = sqrt(pow((p2.getX()-p1.getX()),2) + pow((p2.getY()-p1.getY()),2));

    cout << "Distance between ";
    p1.printPoint();
    cout << "and ";
    p2.printPoint();
    cout << "= " << distance << endl;
}
void Distance::calculateDistance2()
{
    for(int a = 0; a < SIZE; a++)
    {
        for(int b = a+1; b < SIZE; b++)
        {
            distance = sqrt(pow((point[b].getX()-point[a].getX()),2)
                     + pow((point[b].getY()-point[a].getY()),2));

            distanceMatrix[a][b] = distance;
        }
    }

    compareDistance();
}
void Distance::compareDistance()
{
    double minimumDistance = distanceMatrix[0][1];
    int x,y;
    for(int a = 0; a < SIZE; a++)
    {
        for(int b = a+1; b < SIZE; b++)
        {
            if (a != b)
            {
                if (minimumDistance > distanceMatrix[a][b])
                    minimumDistance = distanceMatrix[a][b];
                x = a; y = b;
            }
        }
    }
    printPointList();
    cout << "\nMinimum distance between ";
    point[x].printPoint();
    cout << "and ";
    point[y].printPoint();
    cout << "is: " << minimumDistance << endl;
}
void Distance::printPointList()
{
    for(int x = 0; x < SIZE; x++)
    {
        cout << x+1 << ". point is ";
        point[x].printPoint();
        cout << "\n";
    }
}
