
#include <iostream>
#include <iomanip>
#include <string>
#include "MyRect.h"
#include "Queue.h"
#include "Stack.h"
#include "Matrix.h"
#include "PascalTriangle.h"
using namespace std;


int main()
{

    int choice;

    do {
        cout << "Select a number of class for testing\n1 - Stack\n2 - Queue\n3 - Matrix\n4 - MyRect\n5 - PascalTriangle" << endl;
        cin >> choice;
    } while (choice < 1 || choice > 5);


    void (*pf[])() = { testStack, testQueue, testMatrix, testMyRect, testPascal};
    pf[choice - 1]();
    return 0;
    
}


