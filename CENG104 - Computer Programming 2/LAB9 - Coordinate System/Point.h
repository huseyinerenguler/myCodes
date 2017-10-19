#ifndef POINT_H
#define POINT_H

class Point
{
private:
    int x;
    int y;
public:
    Point(int = 0, int = 0);
    void setPoint(int,int);
    void printPoint();
    void calculateMagnitude();
    int getX();
    int getY();
};
#endif
