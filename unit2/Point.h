#pragma once
#include <iostream>
using namespace std;

class Point {
private:
    static int num;
    double x;
    double y;
    char name[20];

public:
    Point() {
        num++;
        setAll(0.0, 0.0, (char*)"no name");
    }

    Point(double x, double y, char* name) {
        num++;
        setAll(x, y, name);
    }

    Point(double x) {
        num++;
        setX(x);
        setY(0.0);
        setName((char*)"no name");
    }

    Point(char* name) {
        num++;
        setX(0.0);
        setY(0.0);
        setName(name);
    }

    ~Point() {
        num--;
        cout << num << endl;
    }

    void setAll(double x, double y, char* name) {
        this->x = x;
        this->y = y;
        strcpy_s(this->name, sizeof(this->name), name);
    }

    void setX(double x) {
        this->x = x;
    }

    void setY(double y) {
        this->y = y;
    }

    void setName(char* name) {
        strcpy_s(this->name, sizeof(this->name), name);
    }

    double getX() {
        return this->x;
    }

    double getY() {
        return this->y;
    }

    char* getName() {
        return this->name;
    }

    void show() {
        cout << "x = " << this->x << endl;
        cout << "y = " << this->y << endl;
        cout << "name = " << this->name << endl;
    }

    static int count() {
        return num;
    }
};

int Point::num;

void testPoint()
{
    cout << "Remainig objects: " << Point::count() << endl;

    Point a, b;
    cout << "Remaining objects: " << Point::count() << endl;

    // show default
    a.show();
    b.show();

    // set
    a.setAll(2.5, 3.6, (char*)"pointA");
    b.setX(7.5);
    b.setY(4.6);
    b.setName((char*)"pointB");

    // get
    cout << "x = " << a.getX() << endl;
    cout << "y = " << a.getY() << endl;
    cout << "name = " << a.getName() << endl;

    cout << "x = " << b.getX() << endl;
    cout << "y = " << b.getY() << endl;
    cout << "name = " << b.getName() << endl;

    // Scope tesing
    {
        Point c(1.5, 2.7, (char*)"pointC"), d(3.5, 1.3, (char*)"pointD");
        cout << "Remaining objects: " << Point::count() << endl;
    }

    Point e(6.4, 1.3, (char*)"pointE"), f(3.5), g((char*)"pointG");
    e.show();
    f.show();
    g.show();
    cout << "Remaining objects: " << Point::count() << endl;
}
