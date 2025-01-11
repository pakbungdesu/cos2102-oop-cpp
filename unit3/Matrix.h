
#pragma once
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

class Matrix {
private:
    int size; // size start at 1
    int** arr;

    void deleteMatrix() {
        if (this->arr) { // check for nullptr
            for (int i = 0; i < this->size; i++) {
                delete[] this->arr[i];
            }
            delete[] this->arr;
        }
    }

    void allocMatrix(int new_n) {
        deleteMatrix(); // delete the old

        // allocate the new
        this->arr = new int* [new_n];
        for (int i = 0; i < new_n; i++) {
            arr[i] = new int[new_n];
        }
    }

    //void allocArr(int**& arr, int old_n, int new_n) {
    //    deleteArr(arr, old_n); // delete the old

    //    // allocate the new
    //    arr = new int *[new_n]; 
    //    for (int i = 0; i < new_n; i++) {
    //        arr[i] = new int[new_n];
    //    }
    //}

public:
    Matrix() {
        this->size = 0;
        this->arr = nullptr;
    }

    Matrix(int n) {
        this->size = n;
        // this->arr = nullptr;
        allocMatrix(n);
    }


    void setValue(int i, int j, int value) {
        if (i >= 0 && i < size && j >= 0 && j < size) {
            this->arr[i][j] = value;
        }
        else {
            throw out_of_range("Index out of bounds");
        }
    }


    void setAllValue() {
        int value;
        for (int i = 0; i < this->size; i++) {
            for (int j = 0; j < this->size; j++) {
                cout << "Insert value for index (" << i << "," << j << "): ";
                cin >> value;
                setValue(i, j, value);
            }
        }
    }

    int get(int i, int j) {
        return this->arr[i][j];
    }

    void show() {
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

    void reset(int new_n) {
        allocMatrix(new_n);
        this->size = new_n;
        setAllValue();
    }

    void extend(int newSize) {
        int value;
        int** newArr = new int* [newSize];

        for (int i = 0; i < newSize; i++) {
            newArr[i] = new int[newSize];
        }
        // copy and fill new data
        for (int i = 0; i < this->size; i++) {
            for (int j = 0; j < this->size; j++) {
                newArr[i][j] = this->arr[i][j];
            }

            for (int j = this->size; j < newSize; j++) {
                cout << "Insert extend value for index (" << i << "," << j << "): ";
                cin >> value;
                newArr[i][j] = value;
            }
        }

        for (int i = this->size; i < newSize; i++) {
            for (int j = 0; j < newSize; j++) {
                cout << "Insert extend value for index (" << i << "," << j << "): ";
                cin >> value;
                newArr[i][j] = value;
            }
        }

        deleteMatrix();
        this->arr = newArr;
        this->size = newSize;
    }


    void shrink(int newSize) {
        if (newSize > this->size) {
            throw invalid_argument("Cannot shrink to a larger size");
        }

        int** newArr = new int* [newSize];
        for (int i = 0; i < newSize; i++) {
            newArr[i] = new int[newSize];
            for (int j = 0; j < newSize; j++) {
                newArr[i][j] = this->arr[i][j];
            }
        }

        deleteMatrix();
        this->size = newSize;
        this->arr = newArr;
    }


    int trace() {
        int res = 0;
        for (int i = 0; i < this->size; i++) {
            res += this->arr[i][i];
        }
        return res;
    }
};

void testMatrix()
{

    Matrix a(3);
    a.setAllValue();
    a.show();

    a.setValue(1, 1, 10);
    a.show();

    a.shrink(2);
    a.show();
    a.extend(4);
    a.show();

    cout << "Trace value: " << a.trace() << endl;
    cout << "Get value at (1, 1): " << a.get(1, 1) << endl;
}
