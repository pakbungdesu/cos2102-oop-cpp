
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
        // this->name = name;
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

    double dot(Point& point) {
        return this->x * point.x + this->y * point.y;
    }

    static int count() {
        return num;
    }

    Point midpoint(Point& p1, Point& p2) {
        double x = (p1.getX() + p2.getX()) / 2.0;
        double y = (p1.getY() + p2.getY()) / 2.0;

        setX(x);
        setY(y);
        // name of original object
        return *this;
    }
};

int Point::num;

void testPoint()
{
    Point a(3, 4, (char*)"pointA"), b(1.5, 2.5, (char*)"pointB"), c;
    cout << "a . b = " << a.dot(b) << endl;
    cout << Point::count() << endl;

    Point d = c.midpoint(a, b);
    cout << Point::count() << endl;

    cout << "midpoint info" << endl;
    c.show();
    d.show();

    cout << Point::count() << endl;
}