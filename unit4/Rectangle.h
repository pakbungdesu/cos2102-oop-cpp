
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
