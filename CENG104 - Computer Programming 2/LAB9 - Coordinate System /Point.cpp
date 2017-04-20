#include <iostream>
#include "Point.h"
using namespace std;

Point::Point(int a, int b){x=a; y=b;}
void Point::setPoint(int a, int b){x=a; y=b;}
void Point::printPoint(){
    cout << "(" << x << "," << y << ") ";}
void Point::calculateMagnitude(){
    cout << "Magnitude = " << sqrt((x*x)+(y*y)) << endl;}
int Point::getX(){return x;}
int Point::getY(){return y;}
