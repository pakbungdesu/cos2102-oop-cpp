
#pragma once
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class PascalTriangle {
private:
    int size;
    int** arr;

    void deletePascal() {
        if (this->arr) {
            for (int i = 0; i < this->size; i++) {
                delete[] this->arr[i];
            }
            delete[] this->arr;
        }
    }

    void allocPascal(int newSize) {
        deletePascal();
        this->arr = new int* [newSize];

        for (int i = 0; i < newSize; i++) {
            this->arr[i] = new int[newSize];
        }
    }

    void setDefault() {
        for (int i = 0; i < this->size; i++) {
            for (int j = 0; j < this->size; j++) {
                this->arr[i][j] = 0;
            }
        }
    }

public:
    PascalTriangle() {
        this->size = 0;
        this->arr = nullptr;
    }

    PascalTriangle(int size) {
        this->size = size;
        allocPascal(size);
        setDefault();
    }

    void resetSize(int newSize) {
        allocPascal(newSize);
        this->size = newSize;
        setDefault();
    }

    void process() {
        this->arr[0][0] = 1;
        for (int i = 1; i < this->size; i++) {
            this->arr[i][0] = 1;

            for (int j = 1; j < i + 1; j++) {
                this->arr[i][j] = this->arr[i - 1][j - 1] + this->arr[i - 1][j];
            }
        }
    }

    void showPascal() {
        // find the maximum value to determine spacing
        int maxVal = arr[0][0];
        for (int i = 0; i < this->size; i++) {
            for (int j = 0; j < this->size; j++) {
                if (arr[i][j] > maxVal) {
                    maxVal = arr[i][j];
                }
            }
        }

        // the width based on the number of digits in the maximum value
        int width = to_string(maxVal).length() + 1;

        for (int i = 0; i < this->size; i++) {
            for (int j = 0; j < this->size; j++) {
                cout << setw(width) << this->arr[i][j];
            }
            cout << endl;
        }
    }
};

void testPascal()
{
    PascalTriangle a(4);
    a.process();
    a.showPascal();

    cout << endl << "Extend size" << endl;
    a.resetSize(6);
    a.process();
    a.showPascal();

    cout << endl << "Shrink size" << endl;
    a.resetSize(3);
    a.process();
    a.showPascal();
}