#ifndef GAME_H
#define GAME_H 

#include <vector>
#include <iostream> 
#include <string>
#include "room.h"

using namespace std;

//Game interface 
class Game {

	private:
	
		//declare a 2D vector of Room objects:
		vector <vector<Room> > game_board;

		//other member variables:
		int side; 				//side of the board
		int num_arrows; 		//keep track of number of errors remaining
		bool debug_view;		//debug mode or not
		int oxygen;				//oxygen level
		bool wumpus_alive;		//keeps track if the wumpus is alive
		int picked_gold;		//keeps track if the gold was picked up or not
		int rope_row;			//keeps track of what row the starting position was, which is where the rope is
		int rope_col;			//keeps track of what columnn the starting position was, which is where the rope is
		int lose;				//keeps track if the user has lost the game or not
		int underwater;			//keeps track if the user is underwater or not

	public:
		
/*********************************************************************
** Function: Game()
** Description: Constructor for game object
** Parameters: none
** Pre-Conditions: room class is properly defined
** Post-Conditions: all the variables are set to a predefined value whenever a new Game object is made
*********************************************************************/ 
		Game();


/*********************************************************************
** Function: ~Game()
** Description: Destructor for game object
** Parameters: none
** Pre-Conditions: game object is properly defined
** Post-Conditions: whenever a game object goes out of scope, this is called
*********************************************************************/ 
		~Game();
		

/*********************************************************************
** Function: set_up()
** Description: sets up the game
** Parameters: int - how long the sides of the cave are
** Pre-Conditions: parameter is defined correctly
** Post-Conditions: the game is set up with all the events, adventurer, board, variables defined properly
*********************************************************************/ 
		void set_up(int);


/*********************************************************************
** Function: set_adventurer()
** Description: places the adventurer into a random empty room in the board
** Parameters: none
** Pre-Conditions: game_board is properly set up
** Post-Conditions: sets the adventurer into a random empty room on the board and keeps track of the escape rope location
*********************************************************************/ 
		void set_adventurer();


/*********************************************************************
** Function: side_len()
** Description: gets the user's input for how long the sides of the cave are
** Parameters: none
** Pre-Conditions: game object is properly defined
** Post-Conditions: a valid user input is returned, integer between 4-50
*********************************************************************/ 
		int side_len();


/*********************************************************************
** Function: debug() 
** Description: gets the user's input if they want to play in debug mode
** Parameters: none
** Pre-Conditions: game object is properly defined
** Post-Conditions: a valid user input is returned, either true or false
*********************************************************************/
		bool debug();


/*********************************************************************
** Function: pick_event()
** Description: returns an event depending on what the parameter is
** Parameters: int - integer between 0-5 that chooses which event is returned
** Pre-Conditions: parameter is properly defined
** Post-Conditions: returns an event depending on the parameter
*********************************************************************/ 
		Event* pick_event(int);

	
/*********************************************************************
** Function: set_oxygen()
** Description: sets the oxygen variable up
** Parameters: none
** Pre-Conditions: game object is properly defined
** Post-Conditions: sets up the variable oxygen to 2 * side 
*********************************************************************/ 
		void set_oxygen();


/*********************************************************************
** Function: display_game()
** Description: displays the game_board to the user
** Parameters: none
** Pre-Conditions: game_board is properly set up
** Post-Conditions: game_board is displayed to the user
*********************************************************************/ 
		void display_game() const;


/*********************************************************************
** Function: check_win()
** Description: checks to see if the user has won 
** Parameters: none
** Pre-Conditions: everything is working correctly in the game
** Post-Conditions: returns if the user has won or not
*********************************************************************/ 
		bool check_win() const;


/*********************************************************************
** Function: check_percepts()
** Description: finds the user's coordinates and then checks if there are percepts in the neighboring rooms
** Parameters: none
** Pre-Conditions: game_board is properly set up
** Post-Conditions: percepts are printed if needed
*********************************************************************/ 
		void check_percepts();


/*********************************************************************
** Function: percepts()
** Description: checks if the room has an event and prints the percept if so
** Parameters: int - row coordinate of the room
			   int - columnn coordinate of the room
** Pre-Conditions: game_board is properly set up
** Post-Conditions: percepts are printed if needed
*********************************************************************/ 
		void percepts(int, int);


/*********************************************************************
** Function: find_adventurer()
** Description: finds which room has the adventurer
** Parameters: int& - int variable that will be changed to the row coordinate of where the adventurer is
			   int& - int variable that will be changed to the columnn cordinate of where the adventurer is
** Pre-Conditions: game_board is properly set up
** Post-Conditions: the parameters are changed to the coordinates of the adventurer
*********************************************************************/ 
		void find_adventurer(int&, int&);


/*********************************************************************
** Function: find_wumpus()
** Description: finds which room has the wumpus
** Parameters:  int& - int variable that will be changed to the row coordinate of where the wumpus is
			    int& - int variable that will be changed to the columnn cordinate of where the wumpus is
** Pre-Conditions: game_board is properly set up
** Post-Conditions: the parameters are changed to the coordinates of the wumpus
*********************************************************************/ 
		void find_wumpus(int&, int&);


/*********************************************************************
** Function: get_dir()
** Description: gets the direction of the arrow shot
** Parameters: none
** Pre-Conditions: has at least one arrow to shoot
** Post-Conditions: returns a valid input (wasd) of where the arrow is going to be shot
*********************************************************************/ 
		char get_dir();


/*********************************************************************
** Function: rand_dir()
** Description: chooses a random direction in which the wumpus is going to go to
** Parameters: int& - int variable that will be changed to the row coordinate of where the wumpus is going to go
			   int& - int variable that will be changed to the column coordinate of where the wumpus is going to go
** Pre-Conditions: game_board is properly defined
** Post-Conditions: the coordinates are changed to whatever room the wumpus is going to go to
*********************************************************************/ 
		void rand_dir(int&, int&);


/*********************************************************************
** Function: wumpus_move_arrow()
** Description: when an arrow is shot, the wumpus has a chance to move and this function simulates that
** Parameters: none
** Pre-Conditions: game_board is properly set up
** Post-Conditions: the wumpus either stays at the same room (25%) or moves to a neighboring room (75%)
*********************************************************************/ 
		void wumpus_move_arrow();


/*********************************************************************
** Function: fire_arrow()
** Description: fires the arrow wherever the user wants
** Parameters: none
** Pre-Conditions: game_board is properly set up
** Post-Conditions: shoots the arrow
*********************************************************************/ 
		void fire_arrow();


/*********************************************************************
** Function: fire_up()
** Description: fires the arrow above the adventurer
** Parameters: int - row coordinate of where the adventurer is
			   int - columnn coordinate of where the adventurer is
** Pre-Conditions: game_board is properly set up
** Post-Conditions: arrow is shot through the three rooms above the adventurer
*********************************************************************/ 
		void fire_up(int, int);


/*********************************************************************
** Function: fire_right()
** Description: fires the arrow to the right of the adventurer
** Parameters: int - row coordinate of where the adventurer is
			   int - columnn coordinate of where the adventurer is
** Pre-Conditions: game_board is properly set up
** Post-Conditions: arrow is shot through the three rooms to the right of the adventurer
*********************************************************************/ 
		void fire_right(int, int);


/*********************************************************************
** Function: fire_down()
** Description: fires the arrow below the adventurer
** Parameters: int - row coordinate of where the adventurer is
			   int - columnn coordinate of where the adventurer is
** Pre-Conditions: game_board is properly set up
** Post-Conditions: arrow is shot through the three rooms below the adventurer
*********************************************************************/ 
		void fire_down(int, int);


/*********************************************************************
** Function: fire_left()
** Description: fires the arrow to the left of the adventurer
** Parameters: int - row coordinate of where the adventurer is
			   int - columnn coordinate of where the adventurer is
** Pre-Conditions: game_board is properly set up
** Post-Conditions: arrow is shot through the three rooms to the left of the adventurer
*********************************************************************/ 
		void fire_left(int, int);


/*********************************************************************
** Function: move_up()
** Description: moves the adventurer up one room
** Parameters: none
** Pre-Conditions: game_board is properly set up
** Post-Conditions: adventurer is moved one room up
*********************************************************************/
		void move_up();


/*********************************************************************
** Function: move_down()
** Description: moves the adventurer down one room
** Parameters: none
** Pre-Conditions: game_board is properly set up
** Post-Conditions: adventurer is moved one room down
*********************************************************************/
		void move_down();


/*********************************************************************
** Function: move_left()
** Description: moves the adventurer left one room
** Parameters: none
** Pre-Conditions: game_board is properly set up
** Post-Conditions: adventurer is moved one room left
*********************************************************************/
		void move_left();


/*********************************************************************
** Function: move_right()
** Description: moves the adventurer right one room
** Parameters: none
** Pre-Conditions: game_board is properly set up
** Post-Conditions: adventurer is moved one room right
*********************************************************************/
		void move_right();

	
/*********************************************************************
** Function: move()
** Description: calls the function that the user wants to do (move or fire arrow)
** Parameters: char - input that the user wants to do
** Pre-Conditions: input is properly defined
** Post-Conditions: the program does what the user inputted through that character
*********************************************************************/
		void move(char);


/*********************************************************************
** Function: check_up()
** Description: checks if the room above exists and/or if it's empty
** Parameters: none
** Pre-Conditions: game_board is set up properly
** Post-Conditions: returns if the room exists and/or if it's empty
*********************************************************************/
		bool check_up(int, int);


/*********************************************************************
** Function: check_right()
** Description: checks if the room to the right is exist and/or if it's empty
** Parameters: none
** Pre-Conditions: game_board is set up properly
** Post-Conditions: returns if the room exists and/or if it's empty
*********************************************************************/
		bool check_right(int, int);


/*********************************************************************
** Function: check_down()
** Description: checks if the room below exists and/or if it's empty
** Parameters: none
** Pre-Conditions: game_board is set up properly
** Post-Conditions: returns if the room exists and/or if it's empty
*********************************************************************/
		bool check_down(int, int);
		
		
/*********************************************************************
** Function: check_left()
** Description: checks if the room to the left is exist and/or if it's empty
** Parameters: none
** Pre-Conditions: game_board is set up properly
** Post-Conditions: returns if the room exists and/or if it's empty
*********************************************************************/		
		bool check_left(int, int);


/*********************************************************************
** Function: get_input()
** Description: makes the user pick what action they want to do
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: returns what the user wants to do
*********************************************************************/
		char get_input();


/*********************************************************************
** Function: action()
** Description: changes variables depending on what event is in the room 
** Parameters: Event* - pointer to the event that is currently being encountered
			   int - returned value that changes the variables values, either a 1 or 0
** Pre-Conditions: game_board is set up properly
** Post-Conditions: depends on the event that's being encountered, but performs the event's action
*********************************************************************/
		void action(Event*, int);


/*********************************************************************
** Function: event()
** Description: determines if the event in the room is encountered or not and then performs it if so
** Parameters: int - row coordinate of the room with the event
			   int - columnn coordinate of the room with the event
** Pre-Conditions: game_board is properly set up
** Post-Conditions: determines if the event is performed or not and performs it if so
*********************************************************************/
		void event(int, int);


/*********************************************************************
** Function: play_game()
** Description: sets up the entire game and plays out the entire game until the user wins or loses
** Parameters: int - number of sides in the cave
			   bool - whether the user wants to play in debug mode or not
** Pre-Conditions: parameters are properly defined
** Post-Conditions: entire program is ran and the whole game is played out
*********************************************************************/
		void play_game(int, bool);
};
#endif