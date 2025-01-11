
#pragma once
#include <iostream>
#include <cmath>
#include "../unit5/Point.h"
using namespace std;


int typeToVertex(char* type) {

    if (type == (char*)"line") {
        // Suppose using start and end points of a line
        return 2;
    }
    else if (type == (char*)"triangle") {
        return 3;
    }
    else if (type == (char*)"rectangle") {
        return 4;
    }
    else {
        return 0; // Suppose it is circle
    }
}

char* vertexToType(int vertex) {
    if (vertex == 2) {
        return (char*)"line";
    }
    else if (vertex == 3) {
        return (char*)"triangle";
    }
    else if (vertex == 4) {
        return (char*)"rectangle";
    }
    else {
        return (char*)"circle";
    }
}


class Shape {
private:
    char type[20];
    int numVertex;
    Point* point;

    void deleteArr() {
        if (this->point != nullptr) {
            delete[] this->point;
            this->point = nullptr;
        }
    }

    void allocArr(int len) {
        deleteArr();
        Point* arr = new Point[len];
        for (int i = 0; i < len; i++) {
            arr[i] = Point();
        }
        this->point = arr;
    }

public:
    Shape() {
        strcpy_s(this->type, sizeof(this->type), (char*)"circle");
        this->numVertex = 1;
        allocArr(1);
    }

    Shape(Point point) {
        strcpy_s(this->type, sizeof(this->type), (char*)"circle");
        this->numVertex = 1;
        allocArr(1);
        this->setPoint1(0, point);
    }

    Shape(char* type) {
        strcpy_s(this->type, sizeof(this->type), type);
        this->numVertex = typeToVertex(type);
        allocArr(numVertex);
    }

    ~Shape() {}

    void setPoint1(int idx, Point new_point) {
        if (idx < this->numVertex) {
            this->point[idx] = new_point;
        }
        else {
            cout << "Invalid index." << endl;
        }
    }

    void setPoint2(int idx, double x, double y, char* name) {
        if (idx < this->numVertex) {
            this->point[idx].setAll(x, y, name);
        }
        else {
            cout << "Invalid index." << endl;
        }
    }

    char* getType() {
        return this->type;
    }

    Point getPoint(int idx) {
        return this->point[idx];
    }

    void showShape() {
        cout << "\nShape info." << endl;
        cout << "Type: " << this->type << endl;
        cout << "Number of points: " << this->numVertex << endl;
        for (int i = 0; i < this->numVertex; i++) {
            cout << "Point " << i + 1 << endl;
            this->getPoint(i).show();
        }
    }
};

class Triangle : public Shape {
private:
    Point centroid;
    double lt1;
    double lt2;
    double lt3;
    double perimeter;

    void setLT(int lt, int x1, int y1, int x2, int y2) {
        double res = sqrt(pow((this->getPoint(x1).getX() - this->getPoint(x2).getX()), 2) +
            pow((this->getPoint(y1).getY() - this->getPoint(y2).getY()), 2));

        if (lt == 1) {
            this->lt1 = res;
        }
        else if (lt == 2) {
            this->lt2 = res;
        }
        else {
            this->lt3 = res;
        }
    }

public:
    Triangle() : Shape((char*)"triangle") {
        setCentroid();
        setLT(1, 0, 0, 1, 1);
        setLT(2, 1, 1, 2, 2);
        setLT(3, 2, 2, 0, 0);
        setPerimeter();

    }

    Triangle(Point p1, Point p2, Point p3) : Shape((char*)"triangle") {
        this->setPoint1(0, p1);
        this->setPoint1(1, p2);
        this->setPoint1(2, p3);
        setCentroid();
        setLT(1, 0, 0, 1, 1);
        setLT(2, 1, 1, 2, 2);
        setLT(3, 2, 2, 0, 0);
        setPerimeter();
    }

    Triangle(Point* point, int arraySize) : Shape((char*)"triangle") {
        int maxSize = 3;
        if (arraySize < maxSize) {
            cout << "Invalid range of dynamic array. Program creates default values for Triangle instead." << endl;
            Point randomP;
            this->setPoint1(0, randomP);
            this->setPoint1(1, randomP);
            this->setPoint1(2, randomP);
        }
        else {
            this->setPoint1(0, point[0]);
            this->setPoint1(1, point[1]);
            this->setPoint1(2, point[2]);
        }
        setCentroid();
        setLT(1, 0, 0, 1, 1);
        setLT(2, 1, 1, 2, 2);
        setLT(3, 2, 2, 0, 0);
        setPerimeter();
    }


    ~Triangle() {}

    void setPerimeter() {
        this->perimeter = this->lt1 + this->lt2 + this->lt3;
    }

    void setCentroid() {
        double x = (this->getPoint(0).getX() + this->getPoint(1).getX() + this->getPoint(2).getX()) / 3.0;
        double y = (this->getPoint(0).getY() + this->getPoint(1).getY() + this->getPoint(2).getY()) / 3.0;
        this->centroid.setAll(x, y, (char*)"centroid");
    }

    Point getCentroid() {
        return this->centroid;
    }

    double getPerimeter() {
        return this->perimeter;
    }

    void showTriangle() {
        this->showShape();
        cout << "Perimeter: " << getPerimeter() << endl;
        cout << "Centroid info." << endl;
        this->centroid.show();
    }
};

class Rectangle : public Shape {
private:
    double lr1;
    double lr2;
    double lr3;
    double lr4;
    double perimeter;

    void setLR(int lr, int x1, int y1, int x2, int y2) {
        double res = sqrt(pow((this->getPoint(x1).getX() - this->getPoint(x2).getX()), 2) +
            pow((this->getPoint(y1).getY() - this->getPoint(y2).getY()), 2));

        if (lr == 1) {
            this->lr1 = res;
        }
        else if (lr == 2) {
            this->lr2 = res;
        }
        else if (lr == 3) {
            this->lr3 = res;
        }
        else {
            this->lr4 = res;
        }
    }

public:
    Rectangle() : Shape((char*)"rectangle") {
        this->lr1 = 0;
        this->lr2 = 0;
        this->lr3 = 0;
        this->lr4 = 0;
        setPerimeter();
    }

    Rectangle(Point p1, Point p2, Point p3, Point p4) : Shape((char*)"rectangle") {
        this->setPoint1(0, p1);
        this->setPoint1(1, p2);
        this->setPoint1(2, p3);
        this->setPoint1(3, p4);
        setLR(1, 0, 0, 1, 1);
        setLR(2, 1, 1, 2, 2);
        setLR(3, 2, 2, 3, 3);
        setLR(4, 3, 3, 0, 0);
        setPerimeter();
    }

    Rectangle(Point* point, int arraySize) : Shape((char*)"rectangle") {
        int maxSize = 4;
        if (arraySize < maxSize) {
            cout << "Invalid range of dynamic array. Program creates default values for Reactangle instead." << endl;
        }
        else {
            this->setPoint1(0, point[0]);
            this->setPoint1(1, point[1]);
            this->setPoint1(2, point[2]);
            this->setPoint1(3, point[3]);
        }
        setLR(1, 0, 0, 1, 1);
        setLR(2, 1, 1, 2, 2);
        setLR(3, 2, 2, 3, 3);
        setLR(4, 3, 3, 0, 0);
        setPerimeter();
    }

    ~Rectangle() {}

    void setPerimeter() {
        this->perimeter = this->lr1 + this->lr2 + this->lr3 + this->lr4;
    }

    double getPerimeter() {
        return this->perimeter;
    }

    void showRectangle() {
        this->showShape();
        cout << "Perimeter: " << getPerimeter() << endl;
    }

};

class Circle : public Shape {

private:
    double radian;
public:
    Circle() : Shape() {
        this->radian = 0.0;
    }

    Circle(double r, Point& c) : Shape(c) {
        this->radian = r;
        this->setPoint1(0, c);
    }

    Circle(double r) : Shape() {
        this->radian = r;
    }

    Circle(Point& c) : Shape(c) {
        this->radian = 0.0;
    }

    ~Circle() {}

    void setRadian(double r) {
        this->radian = r;
    }

    double getRadian() {
        return this->radian;
    }

    void showCircle() {
        this->showShape();
        cout << "Radian: " << this->radian << endl;
    }
};

void testShape() {
    // Test Circle
    cout << "Testing Circle:\n";
    Circle circle1;
    circle1.showCircle();

    Circle circle2(5.0);
    circle2.showCircle();

    Point center(3, 4);
    Circle circle3(center);
    circle3.showCircle();

    Circle circle4(5.0, center);
    circle4.showCircle();

    circle4.setRadian(7.0);
    cout << "Updated radius of circle4: " << circle4.getRadian() << endl;

    // Test Triangle
    cout << "\nTesting Triangle:\n";
    Point p1(1, 1), p2(2, 3), p3(4, 1);

    Triangle triangle1;
    triangle1.showTriangle();

    Triangle triangle2(p1, p2, p3);
    triangle2.showTriangle();

    Point* tri_points = new Point[3];
    tri_points[0] = p1;
    tri_points[1] = p2;
    tri_points[2] = p3;

    Triangle triangle3(tri_points, 3);
    triangle3.showTriangle();

    // Test invalid dynamic array for Triangle
    Point* invalid_tri_points = new Point[2]; // Incorrect size (2 instead of 3)
    invalid_tri_points[0] = p1;
    invalid_tri_points[1] = p2;

    cout << "\nTesting Triangle with invalid dynamic array:\n";
    Triangle invalid_triangle(invalid_tri_points, 2);
    invalid_triangle.showTriangle();


    // Test Rectangle
    cout << "\nTesting Rectangle:\n";
    Point r1(0, 0), r2(3, 0), r3(3, 2), r4(0, 2);

    Rectangle rectangle1;
    rectangle1.showRectangle();

    Rectangle rectangle2(r1, r2, r3, r4);
    rectangle2.showRectangle();

    Point* rect_points = new Point[4];
    rect_points[0] = r1;
    rect_points[1] = r2;
    rect_points[2] = r3;
    rect_points[3] = r4;

    Rectangle rectangle3(rect_points, 4);
    rectangle3.showRectangle();

    // Test invalid dynamic array for Rectangle
    Point* invalid_rect_points = new Point[3]; // Incorrect size (3 instead of 4)
    invalid_rect_points[0] = r1;
    invalid_rect_points[1] = r2;
    invalid_rect_points[2] = r3;

    cout << "\nTesting Rectangle with invalid dynamic array:\n";
    Rectangle invalid_rectangle(invalid_rect_points, 3); // Should create a default rectangle
    invalid_rectangle.showShape();

    // Clean up dynamic memory
    delete[] tri_points;
    delete[] rect_points;
    delete[] invalid_tri_points;
    delete[] invalid_rect_points;
}

