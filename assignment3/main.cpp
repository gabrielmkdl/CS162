/*********************************************************************
** Program Filename: main.cpp
** Author: Gabriel de Leon
** Date: 2/25/24
** Description: Write a program that simulates air traffic control systems. The program must run at least once and continue until prompted otherwise. After the program is done, write a new file for the airports.
** Input: What option they want to choose, # of flight they want to remove/takeoff, info about the flight they want to add.
** Output: Depends on what the user wants to have displayed, but needs to have a new file created at the end.
*********************************************************************/


#include <iostream>
#include "manager.h"

using namespace std;

int main()
{
	Manager m;
	m.run();
	return 0;
}