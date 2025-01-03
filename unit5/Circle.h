
#pragma once
#include <iostream>
#include <cmath>
#include "../unit5/Point.h"
#include "../unit5/Rectangle.h"
using namespace std;


class Circle {

private:
    static int num;
    double radian;
    Point center;
public:
    Circle() {
        this->radian = 0.0;
        this->center = Point((char*)"center");
    }

    Circle(double r, Point c) {
        this->radian = r;
        this->center = c;
    }

    Circle(double r) {
        this->radian = r;
        this->center = Point((char*)"center");
    }

    Circle(Point c) {
        this->radian = 0.0;
        this->center = c;
    }

    ~Circle(){}

    void setAll(double r, Point& p) {
        this->radian = r;
        this->center = p;
    }

    void setRadian(double r) {
        this->radian = r;
    }

    void setCenter(Point& p) {
        this->center = p;
    }

    double getRadian() {
        return this->radian;
    }

    Point getCenter() {
        return this->center;
    }

    void show() {
        cout << "center point: " << endl;
        this->center.show();
        cout << "radian: " << this->radian << endl;
    }

    friend bool isCircleInsideRect(Circle, Rectangle); // frien with Circle, not Rectangle
};

bool isInsideCircle(Point p, Circle c) { // friend with Point, not Circle
    double distance = sqrt(pow(c.getCenter().x - p.x, 2) + pow(c.getCenter().y - p.y, 2));
    return c.getRadian() > distance;
}

bool isCircleInsideRect(Circle circle, Rectangle rect) {
    double left = rect.getStart().getX();
    double bottom = rect.getStart().getY();
    double right = left + rect.getLength();
    double top = bottom + rect.getWidth();

    // Check all edges of the circle against rectangle bounds
    return (circle.center.getX() - circle.radian >= left &&
        circle.center.getY() - circle.radian >= bottom &&
        circle.center.getX() + circle.radian <= right &&
        circle.center.getY() + circle.radian <= top);
}


void testCircle()
{
    Point a(7.5, 3.5, (char*)"pointA"), b(1.5, 2.9, (char*)"pointB"), c(2.3, 2.7, (char*)"pointC");

    // default, show
    Circle circle1, circle2(3.5, (char*)"centerCir2"), circle3(7.5), circle4(7.7, c);
    circle1.show();
    circle2.show();
    circle3.show();
    circle4.show();

    //set, get
    circle1.setAll(2.5, a);
    cout << "circle1 info: " << endl;
    cout << "radian: " << circle1.getRadian() << endl;
    cout << "center:" << endl;
    circle1.getCenter().show();


    circle1.setRadian(5.5);
    circle1.setCenter(b);
    circle1.show();

    cout << "Inside: " << isInsideCircle(c, circle1) << endl;
}

void testCircleRect() {
    Point p(3.5, 4.7);
    Circle circle1(1.0), circle2(2.2, p), circle3(5.5, p);
    Rectangle rect(7.0, 7.7);
    cout << "Is circle1 inside rect? " << isCircleInsideRect(circle1, rect) << endl;
    cout << "Is circle2 inside rect? " << isCircleInsideRect(circle2, rect) << endl;
    cout << "Is circle3 inside rect? " << isCircleInsideRect(circle3, rect) << endl;

}
