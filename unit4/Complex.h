
#pragma once
#include <iostream>
#include <cmath>
using namespace std;


class Complex {
private:
	static int num;
	double x; // real part
	double y; // imaginary part

public:
	Complex() {
		num++;
		this->x = 0.0;
		this->y = 0.0;
	}

	Complex(double x) {
		num++;
		this->x = x;
		this->y = 0.0;
	}

	Complex(double x, double y) {
		num++;
		this->x = x;
		this->y = y;
	}

	~Complex() {
		num--;
		cout << num << endl;
	}

	static int count() {
		return num;
	}

	void setX(double x) {
		this->x = x;
	}

	void setY(double y) {
		this->y = y;
	}

	void setAll(double x, double y) {
		this->x = x;
		this->y = y;
	}

	double getX() {
		return this->x;
	}

	double getY() {
		return this->y;
	}

	void show() {
		cout << "Real part: " << this->x << endl;
		cout << "Imaginary part: " << this->y << endl;
	}

	double length() {
		return sqrt(pow(this->x, 2) + pow(this->y, 2));
	}

	void plus(Complex& c1, Complex& c2, Complex& result) {
		// result->x = resX error
		double resX = c1.getX() + c2.getX();
		double resY = c1.getY() + c2.getY();

		result.setAll(resX, resY);

		// this* = result; error
		this->setAll(resX, resY);
		// or (*this).setAll(resX, resY);
		// or this->x = resX; this->y = resY;
	}
};

int Complex::num;

void testComplex()
{
	Complex a, b(1.0, 1.0);
	a.show();
	a.setX(3.0);
	a.setY(4.0);
	cout << "Complex a after setting" << endl;
	cout << "Real part: " << a.getX() << endl;
	cout << "Imaginary part: " << a.getY() << endl;


	b.show();
	cout << "Length of b: " << b.length() << endl;

	cout << "Complex b after setting" << endl;
	b.setAll(6.0, 8.0);
	b.show();
	cout << "Length of b: " << b.length() << endl;

	cout << Complex::count() << endl;
	Complex c, d;
	cout << Complex::count() << endl;
	c.plus(a, b, d);
	c.show();
	d.show();
}
