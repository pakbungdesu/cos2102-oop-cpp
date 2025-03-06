

#pragma once
#include <iostream>
using namespace std;
#define M_PI 3.141592

// Point -----------------------------
class Point {
private:
    double x;
    double y;

public:
    Point() {
        setAll(0, 0);
    }

    Point(double x, double y) {
        setAll(x, y);
    }

    Point(double x) {
        setX(x);
        setY(0);
    }

    ~Point() {}

    void setAll(double x, double y) {
        this->x = x;
        this->y = y;
    }

    void setX(double x) {
        this->x = x;
    }

    void setY(double y) {
        this->y = y;
    }

    double getX() {
        return this->x;
    }

    double getY() {
        return this->y;
    }

    void show() {
        cout << "x = " << this->x << endl;
        cout << "y = " << this->y << endl;
    }

    friend istream& operator>>(istream& is, Point& point);
};

istream& operator>>(istream& is, Point& point) {
    double x, y;
    cout << "Insert x: "; is >> x;
    cout << "Insert y: "; is >> y;
    point.setAll(x, y);
    return is;
}

ostream& operator<<(ostream& os, Point& point) {
    point.show();
    return os;
}

// Shape -----------------------------
class Shape {
public:
    virtual void show() = 0;
    virtual double area() = 0;
    virtual istream& input(istream&) = 0;
};


// ThreeDimensional --------------------
class ThreeDimensioanl : public Shape {
public:
    virtual double volume() = 0;
};

// Cylinder ---------------------------
class Cylinder : public ThreeDimensioanl {
    double radian;
    double height;
    Point center;
public:
    Cylinder() {
        radian = 0;
        height = 0;
    }

    Cylinder(double r, double h, Point c) {
        radian = r;
        height = h;
        center = c;
    }

    Cylinder(double r, double h) {
        radian = r;
        height = h;
    }

    Cylinder(double r) {
        radian = r;
        height = 0;
    }

    Cylinder(Point c) {
        radian = 0;
        height = 0;
        center = c;
    }

    ~Cylinder() {}

    void setAll(double r, double h, Point& p) {
        radian = r;
        height = h;
        center = p;
    }

    void setRadian(double r) {
        radian = r;
    }

    void setHeight(double h) {
        height = h;
    }

    void setCenter(Point& p) {
        center = p;
    }

    double getRadian() {
        return radian;
    }

    double getHeight() {
        return height;
    }

    Point getCenter() {
        return center;
    }

    void show() {
        cout << "Center point: " << endl;
        center.show();
        cout << "Radian: " << radian << endl;
        cout << "Height: " << height << endl;
    }

    istream& input(istream& is) {
        Point cen;
        double rad, ht;
        is >> cen; setCenter(cen);
        cout << "Insert radian: "; is >> rad; setRadian(rad);
        cout << "Insert height: "; is >> ht; setHeight(ht);
        return is;
    }

    double volume() {
        return M_PI * radian * radian * height;
    }

    double area() override {
        return 2 * M_PI * radian * (radian + height);
    }
};

// Sphere -----------------------------
class Sphere : public ThreeDimensioanl {
    double radian;
    Point center;
public:
    Sphere() {
        radian = 0;
    }

    Sphere(double r, Point c) {
        radian = r;
        center = c;
    }

    Sphere(double r) {
        radian = r;
    }

    Sphere(Point c) {
        radian = 0;
        center = c;
    }

    ~Sphere() {}

    void setAll(double r, Point& p) {
        radian = r;
        center = p;
    }

    void setRadian(double r) {
        radian = r;
    }

    void setCenter(Point& p) {
        center = p;
    }

    double getRadian() {
        return radian;
    }

    Point getCenter() {
        return center;
    }

    void show() {
        cout << "Center point: " << endl;
        center.show();
        cout << "Radian: " << radian << endl;
    }

    istream& input(istream& is) {
        Point cen;
        double rad;
        is >> cen; setCenter(cen);
        cout << "Insert radian: "; is >> rad; setRadian(rad);
        return is;
    }

    double volume() {
        return (4.0 / 3.0) * M_PI * radian * radian * radian;
    }

    double area() override {
        return 4 * M_PI * radian * radian;
    }

};

// TwoDimensional --------------------
class TwoDimensional : public Shape {
};

// Triangle --------------------------
class Triangle : public TwoDimensional {
    double base, height;
public:
    Triangle() {
        base = 0;
        height = 0;
    }

    Triangle(double wd, double ht) {
        base = wd;
        height = ht;
    }

    ~Triangle() {}

    void setBase(double bs) {
        base = bs;
    }

    void setHeight(double ht) {
        height = ht;
    }

    double getBase() {
        return base;
    }

    double getHeight() {
        return height;
    }

    void show() {
        cout << "Base: " << base << endl;
        cout << "Height: " << height << endl;
    }

    istream& input(istream& is) {
        double bs, ht;
        cout << "Insert base: "; is >> bs;
        cout << "Insert height: "; is >> ht;
        setBase(bs);
        setHeight(ht);
        return is;
    }

    double area() override {
        return 0.5 * base * height;
    }
};

// Rectangle --------------------------
class Rectangle : public TwoDimensional {
    double width, length;
public:
    Rectangle() {
        width = 0;
        length = 0;
    }
    Rectangle(double wd, double lg) {
        width = wd;
        length = lg;
    }

    ~Rectangle() {}

    void setWidth(double wd) {
        width = wd;
    }

    void setLength(double lg) {
        length = lg;
    }

    double getWidth() {
        return width;
    }

    double getLength() {
        return length;
    }

    void show() {
        cout << "Width: " << width << endl;
        cout << "Length: " << length << endl;
    }

    istream& input(istream& is) {
        double wd, lg;
        cout << "Insert width: "; is >> wd;
        cout << "Insert length: "; is >> lg;
        setWidth(wd);
        setLength(lg);
        return is;
    }

    double area() override {
        return width * length;
    }

};

// Circle -----------------------------
class Circle : public TwoDimensional {
private:
    double radian;
    Point center;
public:
    Circle() {
        this->radian = 0;
    }

    Circle(double r, Point& c) {
        this->radian = r;
        this->center = c;
    }

    Circle(double r) {
        this->radian = r;
    }

    Circle(Point& c) {
        this->radian = 0.0;
        this->center = c;
    }

    ~Circle() {}

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
        cout << "Center point: " << endl;
        this->center.show();
        cout << "Radian: " << this->radian << endl;
    }

    istream& input(istream& is) {
        Point cen;
        double rad;
        is >> cen; setCenter(cen);
        cout << "Insert radian: "; is >> rad; setRadian(rad);
        return is;
    }

    double area() override {
        return M_PI * radian * radian;
    }
};


istream& operator>>(istream& is, Shape& shape) {
    shape.input(is);
    return is;
}

void func(Shape& shape) {
    shape.show();
}

void test10_4() {

    cout << "Circle info." << endl;
    Circle cir1;
    cin >> cir1;

    cout << "Rectangle info." << endl;
    Rectangle rec1;
    cin >> rec1;

    cout << "Triangle info." << endl;
    Triangle tri1;
    cin >> tri1;

    TwoDimensional* arr2D[3] = { &cir1, &rec1, &tri1 };
    for (int i = 0; i < 3; i++) {
        cout << "2D Shape " << i + 1 << endl;
        func(*arr2D[i]);
        cout << "Area: " << arr2D[i]->area() << endl;
    }

    cout << "Cylinder info." << endl;
    Cylinder cyl1;
    cin >> cyl1;

    cout << "Sphere info." << endl;
    Sphere sph1;
    cin >> sph1;

    ThreeDimensioanl* arr3D[2] = { &cyl1, &sph1 };
    for (int i = 0; i < 2; i++) {
        cout << "3D Shape " << i + 1 << endl;
        func(*arr3D[i]);
        cout << "Volume: " << arr3D[i]->volume() << endl;
        cout << "Area: " << arr3D[i]->area() << endl;
    }

    Shape* s[5] = { &cir1, &rec1, &tri1 , &cyl1, &sph1 };
    for (int i = 0; i < 5; i++) {
        cout << "Shape " << i + 1 << endl;
        func(*s[i]);
        cout << "Area: " << s[i]->area() << endl;
    }
}
