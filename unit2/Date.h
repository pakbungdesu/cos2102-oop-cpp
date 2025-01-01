#pragma once
#include <iostream>
using namespace std;

class Date {
private:
    static int num;
    int date;
    int month;
    int year;

public:
    Date() {
        num++;
        this->date = 1;
        this->month = 1;
        this->year = 2025;
    }

    Date(int date) {
        num++;
        this->date = date;
        setMonth(1);
        setYear(2025);
    }

    Date(int date, int month) {
        num++;
        this->date = date;
        this->month = month;
        setYear(2025);
    }

    Date(int date, int month, int year) {
        num++;
        setAll(date, month, year);
    }

    void setDate(int date) {
        this->date = date;
    }

    void setMonth(int month) {
        this->month = month;
    }

    void setDateMonth(int date, int month) {
        this->date = date;
        this->month = month;
    }

    void setYear(int year) {
        this->year = year;
    }

    void setAll(int date, int month, int year) {
        this->date = date;
        this->month = month;
        this->year = year;
    }

    int getDate() {
        return this->date;
    }

    int getMonth() {
        return this->month;
    }

    int getYear() {
        return this->year;
    }

    void show() {
        cout << "Date: " << this->date << endl;
        cout << "Month: " << this->month << endl;
        cout << "Year: " << this->year << endl;
    }

    int daysInMonth() {
        int res;
        bool leap_year = false;
        if (this->year % 400 == 0) {
            leap_year = true;
        }

        if (this->year % 4 == 0 && this->year % 100 != 0) {
            leap_year = true;
        }

        if (leap_year) {
            switch (this->month) {
            case 1: case 3: case 5: case 7: case 8: case 10: case 12:
                res = 31;
                break;
            case 4: case 6: case 9: case 11:
                res = 30;
                break;
            case 2:
                res = 29;
                break;
            default:
                res = -1; // invalid month
                break;
            }
        }
        else {
            switch (this->month) {
            case 1: case 3: case 5: case 7: case 8: case 10: case 12:
                res = 31;
                break;
            case 4: case 6: case 9: case 11:
                res = 30;
                break;
            case 2:
                res = 28;
                break;
            default:
                res = -1; // invalid month
                break;
            }
        }
        return res;
    }

    ~Date() {
        num--;
        cout << "Remaining objects: " << num << endl;
    }

    static int count() {
        return num;
    }
};

int Date::num;

void testDate()
{
    // Default constructor, get
    cout << Date::count() << endl; // 0
    Date a;
    cout << "object a" << endl;
    cout << "Date: " << a.getDate() << endl;
    cout << "Month: " << a.getMonth() << endl;
    cout << "Year: " << a.getYear() << endl;


    cout << Date::count() << endl; // 1

    // Constructor overloading, set, show
    Date b(1), c(1, 15), d(14, 2, 2024);
    cout << Date::count() << endl; // 4

    // b
    cout << "object b" << endl;
    b.show();
    cout << "Days in month of b: " << b.daysInMonth() << endl;

    // c
    cout << "object c" << endl;
    c.show();
    cout << "Days in month of c: " << c.daysInMonth() << endl;

    cout << "object c (after new setting)" << endl;
    c.setDateMonth(9, 6);
    c.show();
    cout << "Days in month of c: " << c.daysInMonth() << endl;

    // d
    cout << "object d" << endl;
    d.show();
    cout << "Days in month of d: " << d.daysInMonth() << endl;
}


