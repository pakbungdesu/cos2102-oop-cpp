
#include <iostream>
#include "Person.h"
#include "Shape.h"
using namespace std;


int main() {
	int choice;
	do {
		cout << "Select a number of class for testing\n1 - Person\n2 - Shape" << endl;
		cin >> choice;
	} while (choice < 1 || choice > 2);


	void (*pf[])() = { testPerson, testShape };
	pf[choice - 1]();
    return 0;
}

