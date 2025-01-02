
#pragma once
#include <iostream>
#include "../unit2/Rectangle.h"
using namespace std;


class MyRect {
private:
    int row, col;
    Rectangle** arr;

    void allocateArr(int row, int col) {
        this->row = row;
        this->col = col;
        this->arr = new Rectangle * [row];

        for (int i = 0; i < row; i++) {
            this->arr[i] = new Rectangle[col];
        }
    }

    void deleteArr() {
        if (this->arr != nullptr) {
            for (int i = 0; i < this->row; i++) {
                delete[] this->arr[i];
            }
            delete[] this->arr;
            this->arr = nullptr;
            this->row = 0;
            this->col = 0;
        }
    }

public:
    MyRect() {
        this->arr = nullptr;
        this->row = 0;
        this->col = 0;
    }

    MyRect(int row, int col) {
        allocateArr(row, col);
    }

    ~MyRect() {
        deleteArr();
    }

    void reset(int row, int col) {
        deleteArr();
        allocateArr(row, col);
    }

    void setRectAll() {
        double width, length;
        for (int i = 0; i < this->row; i++) {
            for (int j = 0; j < this->col; j++) {
                // input
                cout << "Rectangle row " << i + 1 << " col " << j + 1 << endl;
                cout << "Insert width: "; cin >> width;
                cout << "Insert length: "; cin >> length;

                // set
                this->arr[i][j].setAll(width, length);
            }
        }
    }

    void setRect1(int row, int col, double width, double length) {
        this->arr[row][col].setAll(width, length);
    }

    void setRect2(int row, int col, Rectangle rec) {
        this->arr[row][col] = rec;
        // this->arr[row][col].setAll(rec.getWidth(), rec.getLength());
    }

    Rectangle getRect(int row, int col) {
        return this->arr[row][col];
    }

    void showRect() {
        for (int i = 0; i < this->row; i++) {
            for (int j = 0; j < this->col; j++) {
                cout << "Rectangle row " << i + 1 << " col " << j + 1 << endl;
                // getRect(i, j).show();
                this->arr[i][j].show();
            }
        }
    }
};

void testMyRect()
{
    int row = 2, col = 2;
    cout << "Rectangle objects: " << Rectangle::count() << endl;

    // default
    MyRect *a = new MyRect;
    a->showRect();
    cout << "Rectangle objects: " << Rectangle::count() << endl;

    delete a;
    cout << "Rectangle objects: " << Rectangle::count() << endl;

    a = new MyRect(row, col);
    a->setRectAll();
    (*a).showRect();
    cout << "Rectangle objects: " << Rectangle::count() << endl;

    // getRect
    Rectangle myRectangle = a->getRect(1, 1);
    myRectangle.setAll(7.5, 5.3);
    myRectangle.show();
    cout << "Rectangle objects: " << Rectangle::count() << endl;

    // reset, set
    a->setRect1(1, 1, 2.5, 3.5);
    (*a).showRect();
    cout << "Rectangle objects: " << Rectangle::count() << endl;

    a->setRect2(1, 1, myRectangle);
    (*a).showRect();
    cout << "Rectangle objects: " << Rectangle::count() << endl;

}


