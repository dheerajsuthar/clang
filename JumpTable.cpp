//
//  JumpTable.cpp
//
//
//  Created by Dheeraj Suthar on 03/01/19.
//

#include "JumpTable.hpp"
#include <iostream>
using namespace std;
void funa() { cout << "Called func a." << endl; }
void funb() { cout << "Called func b." << endl; }
void func() { cout << "Called func c." << endl; }
void fund() { cout << "Called func d." << endl; }

void (*funcs[])() = {funa, funb, func, fund, nullptr};

char prompt()
{
    cout << "Choose option\n";
    cout << "1. funa\n";
    cout << "2. funa\n";
    cout << "3. funa\n";
    cout << "4. funa\n";
    char choice;
    cin >> choice;
    return choice;
}
int main()
{
    //test (sing function call)
    void (*funp)() = funb;
    funp();
    char choice = prompt();
    choice -= '0';
    if (choice <= 4 && choice >= 1)
    {
        // both works
        // funcs[choice-1]();
        (*funcs[choice-1])();
    }
    else
    {
        cout << "Wrong choice!\n";
    }
    return 0;
}
