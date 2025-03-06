


#include <iostream>
using namespace std;

class Rectangle {
private:
    double width;
    double length;


public:
    void setAll(double w, double l) {
        this->width = w;
        this->length = l;
    }

    Rectangle() {
        setAll(0.0, 0.0);
    }

    Rectangle(double x, double y) {
        setAll(x, y);
    }

    double& operator[] (int i) {
        if (i != 0 && i != 1) {
            cout << "Invalid range." << endl;
            exit(1);
        }
        return (i == 0) ? width : length;
    }

    double& operator()() {
        return width;
    }

    double& operator()(int i) {
        if (i != 0 && i != 1) {
            cout << "Invalid range." << endl;
            exit(1);
        }
        return (i == 0) ? width : length;
    }

    double& operator()(int i, int j) {
        return ((i + j) % 2 == 0) ? width : length;
    }

    ~Rectangle() {}

    Rectangle operator++() { // prefix
        ++width;
        return *this;
    }

    Rectangle operator++(int) { // postfix
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

};

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
    // --------------- operator ++, --
    Rectangle r1(2, 3), r2(3, 4), r3;
    r3 = ++r1;
    r3.show();
    r1.show();

    r3 = r2++;
    r3.show();
    r2.show();

    for (int i = 0; i < 3; i++) {
        r3 = --r1;
        r3.show();
        r1.show();
    }


    for (int i = 0; i < 5; i++) {
        r3 = r2--;
        r3.show();
        r2.show();
    }

    check("r1 > r2", r1 > r2);
    check("r1 >= r2", r1 >= r2);
    check("r1 < r2", r1 < r2);
    check("r1 <= r2", r1 <= r2);
    check("r1 != r2", r1 != r2);

    // --------------- operator []
    Rectangle myarr[3] = { r1, r2, r3 };

    for (int i = 0; i < 3; i++) {
        cout << "myarr[" << i << "] width: " << myarr[i][0] << ", length : " << myarr[i][1] << endl;
    }

    for (int i = 0; i < 3; i++) {
        myarr[i][0] = i + 1.5;
        myarr[i][1] = i + 2.5;
    }

    for (int i = 0; i < 3; i++) {
        cout << "myarr[" << i << "] width: " << myarr[i][0] << ", length : " << myarr[i][1] << endl;
    }

    // --------------- operator ()
    for (int i = 0; i < 3; i++) {
        cout << "myarr() width: " << myarr[i]() << endl;
        cout << "myarr(" << i << ") width: " << myarr[i](0) << ", length : " << myarr[i](1) << endl;
    }

    for (int i = 0; i < 3; i++) {
        myarr[i](0) = i * 5;
        myarr[i](1) = i * 10;
    }

    for (int i = 0; i < 3; i++) {
        cout << "myarr() width: " << myarr[i]() << endl;
        cout << "myarr(" << i << ") width: " << myarr[i](0) << ", length : " << myarr[i](1) << endl;
    }
}
