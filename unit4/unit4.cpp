
#include <iostream>
#include "../unit4/Point.h"
#include "../unit4/Matrix.h"
#include "Complex.h"
#include "QueueRect.h"
#include "StackPoint.h"
using namespace std;


int main()
{
	int choice;

	do {
		cout << "Select a number of class for testing\n1 - Point\n2 - Complex\n3 - StackPoint\n4 - QueueRectangle\n5 - Matrix" << endl;
		cin >> choice;
	} while (choice < 1 || choice > 5);


	void (*pf[])() = { testPoint, testComplex, testStackPoint, testQueueRect, testMatrix};
	pf[choice - 1]();
	return 0;
}

