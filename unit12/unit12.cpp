
#include <iostream>
#include <cmath>
using namespace std;


class MyException : public exception {
    int value;
public:
    MyException() {
        value = 3;
    }

    MyException(int i) {
        value = i;
    }

    virtual const char* what() const throw() {

        if (value < -1) {
            return "i or j in (i, j) operator should be positive";
        }
        else if (value < 0) {
            return "width or length is negative";
        }
        else if (value == 0) {
            return "zero division error";
        }
        else if (value == 1) {
            return "index of [] operator should be either 0 or 1";
        }
        else if (value == 2) {
            return "result of (i, j) operator should be integer";
        }
        else {
            return "exception was thrown";
        }
    }
};

class Rectangle {
private:
    double width;
    double length;

public:
    void setAll(double w, double l) {
        if (w < 0 || l < 0) {
            throw MyException(-1);
        }
        width = w;
        length = l;
    }

    Rectangle() {
        setAll(0, 0);
    }

    Rectangle(double x, double y) {
        setAll(x, y);
    }

    Rectangle operator + (Rectangle rec) {
        return Rectangle(width + rec.getWidth(), length + rec.getLength());
    }

    Rectangle operator - (Rectangle rec) {
        return Rectangle(width - rec.getWidth(), length - rec.getLength());
    }

    Rectangle operator * (Rectangle rec) {
        return Rectangle(width * rec.getWidth(), length * rec.getLength());
    }

    Rectangle operator / (Rectangle rec) {
        if (rec.getWidth() == 0 || rec.getLength() == 0) {
            throw MyException(0);
        }
        return Rectangle(width / rec.getWidth(), length / rec.getLength());
    }

    double& operator[] (int i) {
        if (i != 0 && i != 1) {
            throw MyException(1);
        }
        return (i == 0) ? width : length;
    }

    double& operator()() {
        return width;
    }

    double& operator()(int i) {
        if (i != 0 && i != 1) {
            throw MyException(1);
        }
        return (i == 0) ? width : length;
    }

    int operator()(int i, int j) {
        double res = (i + j) * 1.0 / j;

        if (fmod(res, 1.0) != 0.0) { // double
            throw MyException(2);
        }
        else if (res < 0) {
            throw MyException(-2);
        }
        return (int)res;
    }

    ~Rectangle() {}

    Rectangle operator++() { // prefix
        ++width;
        return *this;
    }

    Rectangle operator++(int) { // postfix
        if (width > 20) {
            throw 20;
        }
        return Rectangle(width++, length);
    }

    friend Rectangle operator--(Rectangle& other) { // prefix
        if (other.length > 1) {
            --other.length;
        }
        return other;
    }

    friend Rectangle operator--(Rectangle& other, int) { // postfix
        Rectangle res = other;
        if (other.length > 1) {
            other.length--;
        }
        return res;
    }

    bool operator <(Rectangle other) {
        return area() < other.area();
    }

    bool operator <=(Rectangle other) {
        return area() <= other.area();
    }

    bool operator >(Rectangle other) {
        return area() > other.area();
    }

    bool operator >=(Rectangle other) {
        return area() >= other.area();
    }

    bool operator !=(Rectangle other) {
        return area() != other.area();
    }

    void setWidth(double width) {
        width = width;
    }

    void setLength(double length) {
        length = length;
    }

    double getWidth() {
        return width;
    }

    double getLength() {
        return length;
    }

    void show() {
        cout << "width = " << width << endl;
        cout << "length = " << length << endl;
    }

    double area() {
        return width * length;
    }

    double perimeter() {
        return (width + length) * 2.0;
    }

    friend ostream& operator<<(ostream& os, Rectangle& rec);
};

class MyRect : public Rectangle {
    int n;
public:
    MyRect() {
        n = 1;
    }

    MyRect(int i) {
        n = i;
    }

    MyRect(int i, double width, double length) : Rectangle(width, length) {
        n = i;
    }

    ~MyRect(){}

    void setN(int i) {
        n = i;
    }

    int getN() {
        return n;
    }

    void show() {
        cout << "n = " << n << endl;
    }
};

ostream& operator<<(ostream& os, Rectangle& rec) {
    if (rec.getWidth() >= 2) {
        throw 2;
    }
    else if (rec.getWidth() >= 5.5) {
        throw 5.5;
    }
    else {
        throw "exceed";
    }
    rec.show();
    return os;
}

void innerFunc(int val) {
    if (val < 0) {
        throw - 1;
    }
}

int outerFunc(int val) {
    try {
        if (val < 0) {
            innerFunc(val);
        }
        else {
            return val;
        }
    }
    catch (int x) {
        cout << "Caught negative exception: " << x << endl;
        throw x;
    }
}


void check(string output, bool condition) {
    if (condition) {
        cout << output << " is true." << endl;
    }
    else {
        cout << output << " is false." << endl;
    }
}

int main()
{ 

    // ----------- 12.1, 12.2
    try {
        Rectangle r1(2.5, 3);
        cout << r1;
    }
    catch (int i) {
        cout << "Caught int exception: " << i << endl;
    }
    catch (double d) {
        cout << "Caught double exception: " << d << endl;
    }
    catch (...) {
        cout << "Outer exception caught." << endl;
    }


    // ----------- 12.3
    try {
        MyRect m(4, 5, 6);
        throw m;
    }
    catch (MyRect) {
        cout << "Exception caught: MyRect" << endl;
    }
    catch (Rectangle) {
        cout << "Exception caught: Rectangle" << endl;
    }
    catch (...) {
        cout << "Outer exception caught." << endl;
    }

    try {
        MyRect m(2);
        throw m;
    }
    catch (Rectangle) {
        cout << "Exception caught: Rectangle" << endl;
    }
    catch (MyRect) {
        cout << "Exception caught: MyRect" << endl;
    }
    catch (...) {
        cout << "Outer exception caught." << endl;
    }


    // ----------- 12.4
    try {
        Rectangle r1(2, -1);
        outerFunc(r1.getWidth());
        outerFunc(r1.getLength());
    }
    catch (MyException& e) {
        cout << "Exception caught: " << e.what() << endl;
    }


    // ----------- 12.6
    Rectangle r1(5, 7), r2(6, 4), r3, r4;
    try {
        try {
            try {
                r3 = r1 + r2;
            }
            catch (MyException& e) {
                cout << "Exception caught: " << e.what() << endl;
            }
            r3 = r3 / r4;
        }
        catch (MyException& e) {
            cout << "Exception caught: " << e.what() << endl;
        }
    }
    catch (MyException& e) {
        cout << "Exception caught: " << e.what() << endl;
    }
    catch (...) {
        cout << "Outer exception caught." << endl;
    }
}
