
#pragma once
#include <iostream>
#include "Rectangle.h"
using namespace std;

class QueueRectangle {
private:
    int len;
    int count;
    Rectangle* arr;

    void allocQueue(int len) {
        deleteQueue();
        this->arr = new Rectangle[len];

        for (int i = 0; i < len; i++) {
            this->arr[i] = Rectangle();
        }
    }

    void deleteQueue() {
        if (this->arr != nullptr) {
            delete[] this->arr;
        }
    }

public:
    QueueRectangle() {
        this->len = 0;
        this->count = 0;
        this->arr = nullptr;
    }

    QueueRectangle(int len) {
        this->len = len;
        this->count = 0;
        allocQueue(len);
    }

    ~QueueRectangle() {
        deleteQueue();
    }

    void showQueue() {
        for (int i = 0; i < this->count; i++) {
            this->arr[i].show();
        }
    }

    void resize(int newSize) {
        if (newSize <= 0) {
            newSize = 1; // prevent resizing to 0 or negative sizes
        }
        Rectangle* newArr = new Rectangle[newSize];
        for (int i = 0; i < this->count; i++) {
            newArr[i] = this->arr[i];
        }

        deleteQueue();
        this->len = newSize;
        this->arr = newArr;
    }


    void insert(Rectangle& value) {
        if (!isQueueFull()) {
            this->arr[this->count] = value;
            this->count++;
        }
        else {
            // extend array
            resize(this->len * 2);
            this->arr[this->count] = value;
            this->count++;
        }
    }

    void remove(Rectangle& result) {
        if (!isQueueEmpty()) {
            // shrink array
            if (this->count - 1 <= this->len / 4) {
                resize(this->len / 2);
            }
            result = this->arr[0];
            this->count--;
            shiftLeft();
        }
        else {
            cout << "No more items to return." << endl;
        }
    }


    void shiftLeft() {
        int i;
        for (i = 0; i < this->count; i++) {
            this->arr[i] = this->arr[i + 1];
        }
        this->arr[i] = Rectangle(); // clear the last element
    }

    bool isQueueFull() {
        return this->count >= this->len;
    }


    bool isQueueEmpty() {
        return this->arr == nullptr || this->count == 0;
    }

    int countQueueItem() {
        return this->count;
    }

    int currentSize() {
        return this->len;
    }
};


void testQueueRect()
{
    Rectangle a, b(3.0, 4.0), c(5.0, 6.0), d(7.0, 8.0), res;
    QueueRectangle myq(2);
    cout << "Is queue empty?: " << myq.isQueueEmpty() << endl;

    myq.insert(a);
    myq.insert(b);
    cout << "Is queue empty?: " << myq.isQueueEmpty() << endl;
    cout << "Is queue full?: " << myq.isQueueFull() << endl;
    cout << "How many items?: " << myq.countQueueItem() << endl;
    cout << "Current size?: " << myq.currentSize() << endl;

    myq.insert(c);
    myq.showQueue();
    cout << "Is queue empty?: " << myq.isQueueEmpty() << endl;
    cout << "Is queue full?: " << myq.isQueueFull() << endl;
    cout << "How many items?: " << myq.countQueueItem() << endl;
    cout << "Current size?: " << myq.currentSize() << endl;

    myq.insert(d);
    myq.showQueue();
    cout << "Is queue empty?: " << myq.isQueueEmpty() << endl;
    cout << "Is queue full?: " << myq.isQueueFull() << endl;
    cout << "How many items?: " << myq.countQueueItem() << endl;
    cout << "Current size?: " << myq.currentSize() << endl;

    cout << "Dequeue" << endl;
    for (int i = 0; i < 3; i++) {
        if (!myq.isQueueEmpty()) {
            myq.remove(res);
            res.show();
        }
    }

    cout << "Is queue empty?: " << myq.isQueueEmpty() << endl;
    cout << "Is queue full?: " << myq.isQueueFull() << endl;
    cout << "How many items?: " << myq.countQueueItem() << endl;
    cout << "Current size?: " << myq.currentSize() << endl;

}