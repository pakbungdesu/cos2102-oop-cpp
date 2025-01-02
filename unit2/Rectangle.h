#pragma once
#include <iostream>
using namespace std;

class Rectangle {
private:
    static int num;
    double width;
    double length;

public:
    Rectangle() {
        num++;
        setAll(0.0, 0.0);
    }

    Rectangle(double x, double y) {
        num++;
        setAll(x, y);
    }

    ~Rectangle() {
        num--;
        cout << num << endl;
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

    double getWidth() {
        return this->width;
    }

    double getLength() {
        return this->length;
    }

    void show() {
        cout << "width = " << this->width << endl;
        cout << "length = " << this->length << endl;
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

void testRectangle()
{
    cout << "Remaining objects: " << Rectangle::count() << endl;

    // default constructor
    Rectangle rect1;
    cout << "Rectangle 1:" << endl;
    rect1.show();
    cout << "area = " << rect1.area() << endl;
    cout << "perimeter = " << rect1.perimeter() << endl;

    cout << "Remaining objects: " << Rectangle::count() << endl;

    // constructor overloading
    Rectangle rect2(5.0, 3.0);
    cout << "Rectangle 2:" << endl;
    rect2.show();
    cout << "area = " << rect2.area() << endl;
    cout << "perimeter = " << rect2.perimeter() << endl;

    cout << "Remaining objects: " << Rectangle::count() << endl;

    // set, show
    rect1.setWidth(2.0);
    rect1.setLength(4.0);
    cout << "Rectangle 1 (after setting):" << endl;
    rect1.show();
    cout << "area = " << rect1.area() << endl;
    cout << "perimeter = " << rect1.perimeter() << endl;

    // get
    rect2.setAll(5.5, 4.5);
    cout << "Rectangle 2 (after setting):" << endl;
    cout << "width = " << rect2.getWidth() << endl;
    cout << "length = " << rect2.getLength() << endl;
    cout << "area = " << rect2.area() << endl;
    cout << "perimeter = " << rect2.perimeter() << endl;

    cout << "Remaining objects: " << Rectangle::count() << endl;
}
