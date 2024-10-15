/*********************************************************************
** Program Filename: recurse.cpp
** Author: Gabriel de Leon
** Date: 3/18/24
** Description: figures out how many ways someone can get up a certain amount of stairs using 1, 2, or 3 steps.
** Input: int n - number of stairs they want to go up
** Output: How many ways to go up n number of stairs
*********************************************************************/

#include <iostream>

#include "stairs.h"s

using namespace std;

int main() {
    int n;
    cout << "Enter the number of stairs: ";
    cin >> n; 
    cout << ways_to_top(n) << endl;
}
