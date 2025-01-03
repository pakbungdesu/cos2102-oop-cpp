
#pragma once
#include <iostream>
#include "../unit4/Point.h"
using namespace std;


class StackPoint {
private:
    int len;
    int count;
    Point* arr;

    void allocStack(int len) {
        deleteStack();
        this->arr = new Point[len];
        for (int i = 0; i < len; ++i) {
            // this->arr[i] = NULL error
            this->arr[i] = Point(); // initialize each Point object
        }
    }

    void deleteStack() {
        if (this->arr != nullptr) {
            delete[] this->arr;
            this->arr = nullptr;// prevent double-deletion
        }
    }

public:
    StackPoint() {
        this->len = 0;
        this->count = 0;
        allocStack(0);
    }

    StackPoint(int len) {
        this->len = len;
        this->count = 0;
        allocStack(len);
    }

    ~StackPoint() {
        deleteStack();
    }

    void showStack() {
        for (int i = this->count - 1; i >= 0; i--) {
            this->arr[i].show();
        }
    }

    void push(Point& value) {
        if (!isStackFull()) {
            this->arr[this->count] = value;
            this->count += 1;
        }
        else {
            cout << "Stack is full." << endl;
        }
    }

    void pop(Point& res) {
        if (!isStackEmpty()) {
            res = this->arr[this->count - 1];
            this->count--;
        }
        else {
            cout << "Stack is empty." << endl;
        }
    }


    bool isStackFull() {
        return this->count >= this->len;
    }

    bool isStackEmpty() {
        return this->arr == nullptr || this->count == 0;
    }

    int countStackItem() {
        return this->count;
    }
};

void testStackPoint()
{
    Point a, b(3.0, 4.0, (char*)"pointB"), c(5.0), d((char*)"pointD"), res;
    StackPoint mystack(4);
    cout << "Is stack empty?: " << mystack.isStackEmpty() << endl;

    mystack.push(a);
    mystack.push(b);
    mystack.push(c);
    mystack.showStack();
    cout << "How many items?: " << mystack.countStackItem() << endl;
    cout << "Is stack empty?: " << mystack.isStackEmpty() << endl;
    cout << "Is stack full?: " << mystack.isStackFull() << endl;

    mystack.push(d);
    mystack.showStack();
    cout << "How many items?: " << mystack.countStackItem() << endl;
    cout << "Is stack empty?: " << mystack.isStackEmpty() << endl;
    cout << "Is stack full?: " << mystack.isStackFull() << endl;

    cout << "Pop items" << endl;
    mystack.pop(res);
    res.show();

    mystack.pop(res);
    res.show();

    mystack.showStack();
}
