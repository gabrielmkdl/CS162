/*********************************************************************
** Program Filename: main.cpp
** Author: Gabriel de Leon
** Date: 3/18/24
** Description: Write a program that simulates an adventure game. The goal is to collect the hidden gold in the cave and get back to the escape rope alive. There are numerous dangers in the cave that the user can encounter and will be hinted at through percepts. 
** Input: int side length - how long the sides of the cave are
		  bool debug - whether the symbols are printed to the user or not
		  char input - what the user wants to do like move which direction or shoot an arrow at which direction
** Output: displays the game as it is played and ultimately either tells them that they won by escaping and grabbing the gold or how they lost/died
*********************************************************************/


#include <iostream>
#include <cstdlib>
#include <ctime>
#include "game.h"

using namespace std;


int main()
{
	//set the random seed
	srand(time(NULL));
	int side_len;
	bool debug;
	Game g;

	//get one input: side length of the cave
	side_len = g.side_len();

	//get the 2nd input --> debug mode or not
	debug = g.debug();

	//Play game
	g.play_game(side_len, debug);

	return 0;
}