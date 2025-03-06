
#include <iostream>
using namespace std;

template <class T>
T findMax(T t1, T t2, T t3) {
    T max_value = t1;
    if (t2 > max_value) {
        max_value = t2;
    }
    if (t3 > max_value) {
        max_value = t3;
    }
    return max_value;
}

template <class T>
class Vector {
    T* data;
    int size;
public:
    Vector() {
        data = nullptr;
        size = 0;
    }

    Vector(int i) {
        size = i;
        data = new T[size];
    }

    Vector(int i, T* arr) {
        size = i;
        data = new T[size];

        for (int j = 0; j < size; j++) {
            data[j] = arr[j];
        }
    }

    ~Vector() {
        delete[] data;
    }

    T& operator[] (int i) {
        return data[i];
    }

    Vector<T>& operator=(Vector<T>& v) {
        if (this != &v){
            if (size != v.size) {
                size = v.size;
                delete[] data;
                data = new T[size];
            }

            for (int i = 0; i < size; i++) {
                data[i] = v.data[i];
            }
        }
        return *this;
    }

    void setData(int i, const T* arr) {
        if (data) {
            delete[] data;
            data = nullptr;
        }
        size = i;
        data = new T[size];
        for (int j = 0; j < size; j++) {
            data[j] = arr[j];
        }
    }

    int getSize() {
        return size;
    }

    T getData(int i) {
        return data[i];
    }

    T findMax() {
        T max = data[0];
        for (int i = 1; i < size; i++) {
            if (data[i] > max) {
                max = data[i];
            }
        }
        return max;
    }

    T findMin() {
        T min = data[0];
        for (int i = 1; i < size; i++) {
            if (data[i] < min) {
                min = data[i];
            }
        }
        return min;
    }

    void show() {
        for (int i = 0; i < size; i++) {
            cout << data[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    cout << "\nTemplate function" << endl;
    cout << findMax(5, 7, 9) << endl;
    cout << findMax(1.5, 10.5, 21.7) << endl;

    cout << "\nTemplate class" << endl;
    Vector<int> vec1;
    int arr1[5] = { 1, 3, 5, 7, 9 };
    vec1.setData(5, arr1);
    vec1.show();
    cout << "Max: " << vec1.findMax() << endl;
    cout << "Min: " << vec1.findMin() << endl;

    Vector<double> vec2;
    double arr2[5] = { 1.5, 2.0, 4.5, 7.5, 7.7 };
    vec2.setData(5, arr2);
    vec2.show();
    cout << "Max: " << vec2.findMax() << endl;
    cout << "Min: " << vec2.findMin() << endl;

    return 0;
}

