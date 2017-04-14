#include <iostream>
using namespace std;

class Rectangle
{
private:
    int height, width;
public:
    Rectangle (int x, int y) {height=x; width=y;}
    int getArea(void) {return height*width;}
};

int main()
{
    int height, width;

    cout << "Height: "; cin >> height;
    cout << "Width: "; cin >> width;

    Rectangle r1 (height,width);

    cout << "\nArea is " << r1.getArea() << endl;

    return 0;
}
