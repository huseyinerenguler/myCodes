#ifndef DISTANCE_H
#define DISTANCE_H
#include "Point.h"
#define SIZE 3

class Distance
{
private:
    Point p1;
    Point p2;
    Point point[SIZE];
    double distance;
    double distanceMatrix[SIZE][SIZE];
public:
    Distance(Point,Point);
    void setDistance(Point,int);
    void calculateDistance();
    void calculateDistance2();
    void compareDistance();
    void printPointList();
};
#endif
