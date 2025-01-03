
#include <iostream>
#include "Date.h"
#include "../unit2/Point.h";
#include "../unit2/Rectangle.h"
using namespace std;

int main()
{
    int choice;

    do {
        cout << "Select a number of class for testing\n1 - Point\n2 - Rectangle\n3 - Date" << endl;
        cin >> choice;
    } while (choice < 1 || choice > 3);
    

    void (*pf[])() = { testPoint, testRectangle, testDate };
    pf[choice - 1]();
}

