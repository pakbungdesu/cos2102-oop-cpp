

#include <iostream>
#include "Circle.h"
#include "../unit5/Rectangle.h"
using namespace std;


int main()
{
	int choice;
	do {
		cout << "Select a number of class for testing\n1 - Rectangle\n2 - Circle\n3 - Is Circle inside Rectangle?" << endl;
		cin >> choice;
	} while (choice < 1 || choice > 3);


	void (*pf[])() = { testRectangle, testCircle, testCircleRect};
	pf[choice - 1]();
	return 0;
}


