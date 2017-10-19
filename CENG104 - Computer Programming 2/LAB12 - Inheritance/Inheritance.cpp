#include <iostream>
using namespace std;

class Animals {
protected:
    int legs;
public:
    Animals(int legsNumber) {
        legs=legsNumber;}
    virtual void eat() = 0;
    void walk() {}
};

class Pet {
public:
    string name;
    virtual void getName() = 0;
    virtual void setName(string name_) = 0;
    virtual void play() = 0;
};

class Spider : public Animals {
public:
    Spider() : Animals(8) {}
    void walk() {
        cout <<"Spider is walking with " << legs << " legs.."<< endl;}
    void eat() {
        cout << "Spider is eating.." << endl;}
};

class Cat : public Animals, public Pet {
public:
    static int count;
    Cat() : Animals(4) {count++;}
    Cat(string name_) : Animals(4) {
        name = name_;
        count++;}
    void getName() {
        cout << "Cat name is " << name << endl;}
    void setName(string name_) {
        name = name_;}
    void walk() {
        cout << name << " is walking with " << legs << " legs.."<< endl;}
    void play() {
        cout << name << " is playing.." << endl;}
    void eat() {
        cout << name << " is eating.." << endl;}
};
int Cat::count = 0;

class Fish : public Animals, public Pet {
public:
    Fish() : Animals(0) {}
    Fish(string name_) : Animals(0) {
        name = name_;}
    void getName() {
        cout << "Fish name is " << name << endl;}
    void setName(string name_) {
        name = name_;}
    void play() {
        cout << name << " is playing.." << endl;}
    void walk() {
        cout << name << " is not walking.." << endl;}
    void eat() {
        cout << name << " is eating.." << endl;}
};

int main() {
    Cat c1;
    c1.setName("Tugberk");
    c1.getName();
    c1.walk();
    c1.play();
    c1.eat();
    cout << "Count: " << c1.count << endl;
    cout << endl;

    Cat c2("Huseyin");
    c2.getName();
    c2.walk();
    c2.play();
    c2.eat();
    cout << "Count: " << c1.count << endl;
    cout << endl;

    Spider s1;
    s1.walk();
    s1.eat();
    cout << endl;

    Fish f1;
    f1.setName("Fatih");
    f1.getName();
    f1.walk();
    f1.play();
    f1.eat();
    cout << endl;

    Fish f2("Alperen");
    f2.getName();
    f2.walk();
    f2.play();
    f2.eat();
    cout << endl;

    return 0;
}
