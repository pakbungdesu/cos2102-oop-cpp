
#pragma once
#include <iostream>
using namespace std;


class Queue {
private:
    int len;
    int count;
    int* arr;

    void allocQueue(int len) {
        deleteQueue();
        this->arr = new int[len];
    }

    void deleteQueue() {
        if (this->arr != nullptr) {
            delete[] this->arr;
        }
    }

public:
    Queue() {
        this->len = 1; // default length is 1
        this->count = 0;
        this->arr = new int[this->len];
    }

    Queue(int len) {
        this->len = len;
        this->count = 0;
        allocQueue(len);
    }

    ~Queue() {
        deleteQueue();
    }

    void showQueue() {
        for (int i = 0; i < this->count; i++) {
            cout << this->arr[i] << endl;
        }
    }

    void resize(int newSize) {
        if (newSize <= 0) {
            newSize = 1; // prevent resizing to 0 or negative sizes
        }
        int* newArr = new int[newSize];
        for (int i = 0; i < this->count; i++) {
            newArr[i] = this->arr[i];
        }

        deleteQueue();
        this->len = newSize;
        this->arr = newArr;
    }


    void insert(int value) {
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

    int remove() {
        if (!isQueueEmpty()) {
            // shrink array
            if (this->count <= this->len / 4) {
                resize(this->len / 2);
            }
            int res = this->arr[0];
            this->count--;
            shiftLeft();
            return res;
        }
        return -9999; // no more items to return
    }


    void shiftLeft() {
        int i;
        for (i = 0; i < this->count; i++) {
            this->arr[i] = this->arr[i + 1];
        }
        this->arr[i] = NULL;
    }

    bool isQueueFull() {
        return this->count >= this->len;
    }


    bool isQueueEmpty() {
        return this->count == 0;
    }

    int countQueueItem() {
        return this->count;
    }

    int currentSize() {
        return this->len;
    }
};

void testQueue()
{
    Queue q1;
    cout << "Is queue full?: " << q1.isQueueFull() << endl;
    cout << "Is queue empty?: " << q1.isQueueEmpty() << endl;

    int arr1[] = { 21, 22, 23, 24, 25, 26, 27, 28, 29, 30 };
    int arr2[] = { 29, 30, 31, 32 };
    Queue q2(10);

    cout << "Enqueue" << endl;
    for (int i = 0; i < 10; i++) {
        q2.insert(arr1[i]);
    }
    q2.showQueue();

    cout << "Is queue full?: " << q2.isQueueFull() << endl;
    cout << "Current size of queue: " << q2.currentSize() << endl;

    cout << "Dequeue" << endl;
    for (int i = 0; i < 9; i++) {
        cout << q2.remove() << endl;
    }
    cout << "Is queue full?: " << q2.isQueueFull() << endl;
    cout << "Current size of queue: " << q2.currentSize() << endl;

    for (int i = 0; i < 4; i++) {
        q2.insert(arr2[i]);
    }

    q2.showQueue();
    cout << "How many items: " << q2.countQueueItem() << endl;
}
