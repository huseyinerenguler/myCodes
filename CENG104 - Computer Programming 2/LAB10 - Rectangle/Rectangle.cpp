#include <iostream>
#include <cmath>
using namespace std;

class Rectangle
{
private:
    int width, height;
    static int instanceCount;
    int computeArea(){
        return width*height;}
public:
    Rectangle(){
        width=1; height=1; instanceCount++;}
    Rectangle(int a,int b){
        width=a; height=b; instanceCount++;}
    void setEdge(int a, int b){
        if (a > 0 && b > 0){
            width = a; height = b;}
        else{
            width = 1; height = 1;}}
    int getInstanceCount(){
        return instanceCount;}
    void input_width_height(){
        cout << "Enter width and height: "; cin >> width >> height;}
    int getWidth(){return width;}
    int getHeight(){return height;}
    void printArea(){
        cout << "Area: " << computeArea() << endl;}
};
int Rectangle::instanceCount = 0;

int findGCD(int a, int b){
    while(1){
        if(a == 0) return b;
        b = b % a;
        if(b == 0) return a;
        a = a % b;}}
int findLCM(int a, int b){
    return (a * b) / findGCD(a,b);}

int main (){
    Rectangle r1; r1.printArea();
    Rectangle r2(6,10); r2.printArea();
    Rectangle r3; r3.input_width_height(); r3.printArea();
    cout << "Instance Count: " << r3.getInstanceCount() << endl;
    cout << endl;

    int LCM = findLCM(r3.getWidth(),r3.getHeight());
    cout << "You need "
         << (LCM / r3.getWidth()) * (LCM / r3.getHeight())
         << " rectangle to build a square and," << endl;
    cout << "area of the this square is: " << pow(LCM,2) << endl;

    return 0;
}
