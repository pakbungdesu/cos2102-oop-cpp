
#pragma once
#include <iostream>
#include "../unit5/Point.h"
using namespace std;


class Rectangle {
private:
    static int num;
    Point start;
    double width;
    double length;

public:
    Rectangle() {
        num++;
        setAll(0.0, 0.0);
        this->start = Point((char*)"start");
    }

    Rectangle(double width, double length) {
        num++;
        setAll(width, length);
        this->start = Point((char*)"start");
    }

    Rectangle(double width, double length, Point point) {
        num++;
        setAll(width, length);
        this->start = point;
    }

    Rectangle(double width, double length, double x, double y) {
        num++;
        setAll(width, length);
        this->start = Point(x, y, (char*)"start");
    }

    ~Rectangle() {
        num--;
    }

    void setAll(double width, double length) {
        this->width = width;
        this->length = length;
    }

    void setWidth(double width) {
        this->width = width;
    }

    void setLength(double length) {
        this->length = length;
    }

    void setStart(Point& point) {
        this->start = point;
    }

    double getWidth() {
        return this->width;
    }

    double getLength() {
        return this->length;
    }

    Point getStart() {
        return this->start;
    }

    void show() {
        cout << "width = " << this->width << endl;
        cout << "length = " << this->length << endl;
        cout << "starting point" << endl;
        this->start.show();
    }

    double area() {
        return this->width * this->length;
    }

    double perimeter() {
        return (this->width + this->length) * 2.0;
    }

    static int count() {
        return num;
    }
};

int Rectangle::num;

bool isInsideRect(Point point, Rectangle rect) {
    double right = rect.getStart().x + rect.getLength();
    double top = rect.getStart().y + rect.getWidth();

    return (rect.getStart().x <= point.x && point.x <= right) &&
        (rect.getStart().y <= point.y && point.y <= top);
}


void testRectangle() {
    Point start((char*)"start"), check1(1.0, 1.0, (char*)"check1"), check2(10.5, 11.5, (char*)"check2");
    Rectangle rect1(4.0, 5.0, start), rect2(5.5, 7.0, 8.0, 9.5);

    rect1.show();
    cout << check1.getName() << " is inside rect1? " << isInsideRect(check1, rect1) << endl;
    cout << check2.getName() << " is inside rect1? " << isInsideRect(check2, rect1) << endl;

    cout << endl;
    rect2.show();
    cout << check1.getName() << " is inside rect2? " << isInsideRect(check1, rect2) << endl;
    cout << check2.getName() << " is inside rect2? " << isInsideRect(check2, rect2) << endl;

}
