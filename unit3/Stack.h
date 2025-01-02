
#pragma once
#include <iostream>
using namespace std;


class Stack {
private:
    int len;
    int count;
    int* arr;

    void allocStack(int len) {
        deleteStack();
        this->arr = new int[len];
        cout << "Allocate memory for stack successfully." << endl;
    }

    void deleteStack() {
        if (this->arr != nullptr) {
            delete[] this->arr;
        }
        cout << "Delete a stack successfully." << endl;;
    }

public:
    Stack() {
        this->len = 0;
        this->count = 0;
        allocStack(0);
    }

    Stack(int len) {
        this->len = len;
        this->count = 0;
        allocStack(len);
    }

    ~Stack() {
        showStack();
        deleteStack();
    }

    void showStack() {
        for (int i = this->count - 1; i >= 0; i--) {
            cout << this->arr[i] << endl;
        }
    }

    void push(int value) {
        if (!isStackFull()) {
            this->arr[this->count] = value;
            this->count += 1;
        }
        else {
            cout << "Stack is full." << endl;
        }
    }

    int pop() {
        if (!isStackEmpty()) {
            int res = this->arr[this->count - 1];
            this->count--;
            return res;
        }
        return -9999; // no more items to return
    }

    bool isStackFull() {
        return this->count >= this->len;
    }

    bool isStackEmpty() {
        return this->count == 0;
    }

    int countStackItem() {
        return this->count;
    }
};

void testStack()
{
    const int length = 7;
    int my_arr[length] = { 11, 12, 13, 14, 15, 16, 17 };
    Stack mystack(length);

    for (int i = 0; i < length; i++) {
        mystack.push(my_arr[i]);
    }

    cout << "How many items?: " << mystack.countStackItem() << endl;
    cout << "Is stack empty?: " << mystack.isStackEmpty() << endl;
    cout << "Is stack full?: " << mystack.isStackFull() << endl;

    cout << "Pop 3 elements" << endl;
    for (int i = 0; i < 3; i++) {
        cout << mystack.pop() << endl;
    }

    cout << "How many items?: " << mystack.countStackItem() << endl;
    cout << "Is stack empty?: " << mystack.isStackEmpty() << endl;
    cout << "Is stack full?: " << mystack.isStackFull() << endl;

}