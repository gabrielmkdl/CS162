#include "game.h"
#include "gold.h"
#include "stalactites.h"
#include "pool.h"
#include "wumpus.h"

#include <iostream>
#include <string>

using namespace std;

//Game Implementation

Game::Game(){

	this->side = 0;
	this->num_arrows = 0;
	this->debug_view = false;
	this->oxygen = 0;
	this->wumpus_alive = true;
	this->picked_gold = 0;
	this->rope_col = 0;
	this->rope_row = 0;
	this->lose = 0;
	this->underwater = 0;
}


Game::~Game(){
}


void Game::set_up(int s){

	//set up the game
	this->side = s;

	this->num_arrows = 3; 	//start with 3 arrows
	
	//sets the oxygen level
	set_oxygen();
	
	// Create the game board: 2D vector of Room objects
	for(int i = 0; i < this->side; i++) {

		vector<Room> row_game_board;
		
		for(int j = 0; j < this->side; j++) {

			Room r;
			row_game_board.push_back(r);
		}
		this->game_board.push_back(row_game_board);
	}

	// randomly insert events (2 pool accesses, 2 stalactites, 1 wumpus, 1 gold)
	// into the board
	int i;
	int j;

	for(int k = 0; k < 6; k++) {

		//keeps generating random rooms in the board until one of them is empty
		do {
			i = rand() % this->side;
			j = rand() % this->side;
		}while(this->game_board[i][j].is_empty()!= true);

		//picks the event to add at this room
		Event* e = pick_event(k);

		//sets the event in this room
		this->game_board[i][j].assign_event(e);
		e = nullptr;
	}

	//places the adventurer
	set_adventurer();
}

void Game::set_adventurer() {

	int i;
	int j;

	//keeps generating random rooms in the board until one of them is empty
	do {
		i = rand() % this->side;
		j = rand() % this->side;
	}while(this->game_board[i][j].is_empty()!= true);
	
	//keeps track of escape rope
	this->rope_row = i;
	this->rope_col = j;

	//sets adventurer into this room
	this->game_board[i][j].set_has_adventurer(true);
}

int Game::side_len() {

	int side = 0;
	
	//forces the user to enter a valid input
	do {
		cout << "Please enter the side length of the cave. Choose a number between 4-50 inclusive: ";
		cin >> side;
	}while(side > 50 || side < 4);
	
	return side;
}

bool Game::debug() {

	string sdebug;

	//forces the user with a true or false
	do {
		cout << "Would you like to play in debug mode? Answer with a true or false: ";
		cin >> sdebug; 
	}while(sdebug != "false" && sdebug != "true");

	if(sdebug == "false") {
		return false;
	}
	
	else {
		return true;
	}
}


Event* Game::pick_event(int k) {
	
	if(k == 0) {
		return new Wumpus;
	}

	else if(k == 1) {
		return new Gold;
	}

	else if(k == 2 || k == 3) {
		return new Pool;
	}

	else {
		return new Stalactites;
	}
}


void Game::set_oxygen() {
	this->oxygen = 2  * this->side;
}

void Game::display_game() const{

	cout << endl << endl;

	//print # of arrows
	cout << "Arrows remaining: " << this->num_arrows << endl;
	
	//print oxygen level: 
	cout << "Oxygen level: " << this->oxygen << endl;

	string line = "";
	for (int i = 0; i < this->side; ++i)
		line += "-----";

	for (int i = 0; i < this->side; ++i) {

		cout << line << endl;
		
		for (int j = 0; j < this->side; ++j) {

			//The first char indicates whether there is a player in that room or not
			//if the room does not have the player, print space " " else, print "*"
			if(this->game_board[i][j].get_has_adventurer() == false) {
				cout << " ";
			}	


			else {
				cout << "*";
			}
	
			//The next two chars indicate the event in the room
			//if the room does not have an event, print "  ||" (2 spaces + ||)
			if(this->game_board[i][j].is_empty() ==  true) {

				if(i == this->rope_row && j == this->rope_col && this->debug_view == true) {
					cout << "~ ||";
				}
				
				else {
					cout << "  ||";
				}
			}

			else {

				if(this->debug_view == true) {
					Event* e = this->game_board[i][j].get_event();
					cout << e->print_symbol();
					cout << " ||";
				}

				else {
					cout << "  ||";
				}
			} 
		}
		cout << endl;
	}
	cout << line << endl;
}

bool Game::check_win() const{
	//check if game over/win
	if(this->picked_gold == 1 && this->game_board[this->rope_row][this->rope_col].get_has_adventurer() == true && this->underwater == 0) {
		cout << "You successfully made it back to the escape rope with the hidden treasure and made it out safely." << endl;
		return true;
	}

	else {
		return false;
	}
}

void Game::check_percepts() {

	//coordinates of which room the adventurer is in
	int i = 0;
	int j = 0;
	find_adventurer(i, j);

	//checks the percepts of each room next to the adventurer
	percepts(i-1,j);
	percepts(i+1,j);
	percepts(i,j+1);
	percepts(i,j-1);
}

void Game::percepts(int i, int j) {

	//checks to see if the room is in the boundaries of the cave
	if(i == -1 || j == -1 || i == this->side || j == this->side) {
		return;
	}

	//checks if the room has an event in it
	else if(this->game_board[i][j].is_empty() == true) {
		return;
	}

	//prints the percept if the room wasn't empty
	else {
			Event* e = this->game_board[i][j].get_event();
			e->print_percepts();
	}
}

void Game::find_adventurer(int &i, int &j) {

	//loops through all the vectors 
	for(int k = 0; k < this->side; k++) {
	
		for(int l = 0; l < this->side; l++) {
			
			//checks if the room has the adventurer and changes the parameters to the room coords if so
			if(this->game_board[k][l].get_has_adventurer() == true) {
				i = k;
				j = l;
				return;
			}
		}
	}
}

void Game::find_wumpus(int &i, int &j) {

	//loops through all the vecotrs
	for(int k = 0; k < this->side; k++) {

		for(int l = 0; l < this->side; l++) {

			//checks if the room has an event
			if(this->game_board[k][l].is_empty() == false) {

				Event* e = this->game_board[k][l].get_event();
				
				//if the event prints out a W, then it has to be a Wumpus and chagnes the parameters to the room coords
				if(e->get_symbol() == 'W') {
					i = k;
					j = l;
					return;
				}
			}
		}
	}
}


char Game::get_dir(){

	//get direction of arrow:
	char dir;
	
	cout << "Fire an arrow...." << endl;
	cout << "W-up" << endl;
	cout << "A-left" << endl;
	cout << "S-down" << endl;
	cout << "D-right" << endl;
	
	//forces the user to give a valid input
	do {
		cout << "Enter direction: " << endl;
		cin >> dir;
		cin.ignore(256, '\n');
	}while(dir != 'w' && dir != 'a' && dir != 's' && dir != 'd');

	return dir;
}

//I think that this function is fine being over 15 lines b/c it's the same thing over and over again just checking each room next to the position up/down/left/right
//It's a switch case with a lot of if/else statements that increases the line count
void Game::rand_dir(int& i, int& j) {

	//checks if there is at least one empty room next to the wumpus
	if(check_up(i, j) || check_down(i, j) || check_left(i, j) || check_right(i, j)) {

		//randomly picks one of the four rooms
		int a = rand() % 4;
		
		//if the room is empty, than the wumpus moves to that room else run the function again
		//the function keeps running until an empty room is found
		switch(a){
			case 0: 
				if(check_up(i, j)) {
					i--;
					break;
				}
				else {
					rand_dir(i, j);
					break;
				}
			case 1:
				if(check_right(i, j)) {
					j++;
					break;
				}
				else {
					rand_dir(i, j);
					break;
				}			
			case 2:
				if(check_down(i, j)) {
					i++;
					break;
				}
				else {
					rand_dir(i, j);
					break;
				}
			case 3:
				if(check_left(i, j)) {
					j--;
					break;
				}
				else {
					rand_dir(i, j);
					break;
				}
			default:
				break;
		}
	}
	else {
		return;
	}
}

void Game::wumpus_move_arrow(){

	//after a missed arrow, 75% chance that the wumpus is moved to a different room
	int a = rand() % 4;

	//checks to see if the 75% was rolled successfully and the wumpus is still alive 
	if(a != 0 && this->wumpus_alive == true) {

		//finds the coords of the room where the wumpus is
		int i;
		int j;
		find_wumpus(i, j);

		//chooses a random direction for the wumpus to go
		int k = i;
		int l = j;
		rand_dir(i, j);

		//if the coords weren't changed then that means there are no empty rooms neighboring to the wumpus	
		if(k == i && l == j) {
			return;
		}

		else{
			
			//deletes the old wumpus and moves the wumpus to the new room
			delete this->game_board[k][l].get_event();
			this->game_board[k][l].assign_event(nullptr);
			Event* e = new Wumpus;
			this->game_board[i][j].assign_event(e);
		}
	}
}

void Game::fire_arrow(){

	// The player may fire arrow if they have enough arrows and aren't underwater
	if(this->num_arrows > 0 && this->underwater != 1) {

		//gets the direction where the user wants to shoot the arrow
		char dir = get_dir();

		//finds where the adventurer is		
		int i;
		int j;
		find_adventurer(i, j);

		if(dir == 'w') {
			fire_up(i, j);
		}

		else if(dir == 'a') {
			fire_left(i, j);
		}

		else if(dir == 's') {
			fire_down(i, j);
		}
		
		else {
			fire_right(i, j);
		}
		
		//moves the wumpus if needed
		wumpus_move_arrow();
		this->num_arrows--;
	}

	else if(this->num_arrows == 0){
		cout << "You have no more arrows left to shoot." << endl;
		return;
	}
	
	else {
		cout << "You can't shoot arrows while underwater." << endl;
	}
}

void Game::fire_up(int i, int j) {

	//checks three rooms above
	for(int k = 1; k < 4; k++) {

		//checks to make sure the room exists
		if(i - k != this->side && i - k > -1) {
			
			//checks if the room is empty 
			if(this->game_board[i - k][j].is_empty() == false) {

				Event* e = this->game_board[i - k][j].get_event();
				
				//checks if the room has the wumpus and if so kills it
				if(e->get_symbol() == 'W') {
					
					delete e;
					this->game_board[i - k][j].assign_event(nullptr);
					this->wumpus_alive = false;
					cout << "The wumpus was killed " << k << " above you." << endl;
					break;
				}

				else{
					cout << "The room " << k << " above is empty." << endl;
				}
			}

			else{
				cout << "The room " << k << " above is empty." << endl;
			} 
		}

		else {
			cout << "Arrow hit a wall." << endl;
			break;
		}
	}
} 

void Game::fire_right(int i, int j) {

	//checks three rooms to the right
	for(int k = 1; k < 4; k++) {

		//checks to make sure the room exists
		if(j + k != this->side && j + k > -1) {
			
			//checks if the room has an event
			if(this->game_board[i][j + k].is_empty() == false) {

				Event* e = this->game_board[i][j + k].get_event();
				
				//checks if the room has the wumpus and if so kills it
				if(e->get_symbol() == 'W') {
					
					delete e;
					this->game_board[i][j + k].assign_event(nullptr);
					this->wumpus_alive = false;
					cout << "The wumpus was killed " << k << " to your right." << endl;
					break;
				}

				else{
					cout << "The room " << k << " to your right is empty." << endl;
				}
			}

			else {
				cout << "The room " << k << " to your right is empty." << endl;
			}
		}

		else {
			cout << "Arrow hit a wall." << endl;
			break;
		}
	}
} 

void Game::fire_down(int i, int j) {

	//checks three rooms below
	for(int k = 1; k < 4; k++) {

		//checks if the room exists
		if(i + k != this->side && i + k > -1) {
			
			//checks if the room is empty
			if(this->game_board[i + k][j].is_empty() == false) {

				Event* e = this->game_board[i + k][j].get_event();
				
				//checks if the room has the wumpus and if so kills it
				if(e->get_symbol() == 'W') {

					delete e;
					this->game_board[i + k][j].assign_event(nullptr);
					this->wumpus_alive = false;
					cout << "The wumpus was killed " << k << " below you." << endl;
					break;
				}

				else{
					cout << "The room " << k << " below is empty." << endl;
				}
			}
			else{
				cout << "The room " << k << " below is empty." << endl;
			}
		}

		else {
			cout << "Arrow hit a wall." << endl;
			break;
		}
	}
} 

void Game::fire_left(int i, int j) {

	//checks three rooms to the left
	for(int k = 1; k < 4; k++) {

		//checks if the room exists
		if(j - k != this->side && j - k > -1) {
			
			//checks if the room is empty
			if(this->game_board[i][j - k].is_empty() == false) {

				Event* e = this->game_board[i][j - k].get_event();
				
				//checks if the room has the wumpus and kills it if so
				if(e->get_symbol() == 'W') {
					
					delete e;
					this->game_board[i][j - k].assign_event(nullptr);
					this->wumpus_alive = false;
					cout << "The wumpus was killed " << k << " to your left." << endl;
					break;
				}

				else{
					cout << "The room " << k << " to your left is empty." << endl;
				}
			}

			else{
				cout << "The room " << k << " to your left is empty." << endl;
			}
		}

		else {
			cout << "Arrow hit a wall." << endl;
			break;
		}
	}
} 

void Game::move_up() {
	
	//finds where the adventurer is
	int i;
	int j;
	find_adventurer(i, j);

	//checks to see if the adventurer can go up
	if(i - 1 == -1) {
		cout << "There's a wall bloking the way." << endl;
	}

	//moves adventurer up if able to 
	else {
		this->game_board[i][j].set_has_adventurer(false);
		this->game_board[i - 1][j].set_has_adventurer(true);
	}
}

void Game::move_down() {
	
	//finds where the adventurer is
	int i;
	int j;
	find_adventurer(i, j);

	//checks to see if the adventurer can go down
	if(i + 1 == this->side) {
		cout << "There's a wall bloking the way." << endl;
	}

	//moves adventurer down if able to
	else {
		this->game_board[i][j].set_has_adventurer(false);
		this->game_board[i + 1][j].set_has_adventurer(true);
	}
}

void Game::move_left() {
	
	//finds where the adventurer is 
	int i;
	int j;
	find_adventurer(i, j);

	//checks to see if the adventurer can go left
	if(j - 1 == -1) {
		cout << "There's a wall bloking the way." << endl;
	}

	//moves adventurer left if able to 
	else {
		this->game_board[i][j].set_has_adventurer(false);
		this->game_board[i][j - 1].set_has_adventurer(true);
	}
}

void Game::move_right() {
	
	//finds where the adventurer is
	int i;
	int j;
	find_adventurer(i, j);

	//checks to see if the adventurer can go right
	if(j + 1 == this->side) {
		cout << "There's a wall bloking the way." << endl;
	}

	//moves adventurer right if able to
	else {
		this->game_board[i][j].set_has_adventurer(false);
		this->game_board[i][j + 1].set_has_adventurer(true);
	}
}

void Game::move(char c) {

	// Handle player's action: move or fire an arrow
	if (c == 'f'){
		Game::fire_arrow();
		return;
	}

	switch(c){
		case 'w':
			Game::move_up();
			break;
		case 'a':
			Game::move_left();
			break;
		case 's':
			Game::move_down();
			break;
		case 'd':
			Game::move_right();
			break;
	}
}

bool Game::check_up(int i, int j) {	
	
	//checks if there is a room above
	if(i - 1 == -1) {
		return false;
	}

	//returns if the room above is empty or not
	else {
		return this->game_board[i - 1][j].is_empty();
	}
}

bool Game::check_right(int i, int j) {	
	
	//checks if there is a room to the right
	if(j + 1 == this->side) {
		return false;
	}

	//returns if the room to the right is empty or not
	else {
		return this->game_board[i][j + 1].is_empty();
	}
}

bool Game::check_down(int i, int j) {	

	//checks if there is a room below
	if(i + 1 == this->side) {
		return false;
	}

	//returns if the room below is empty or not
	else {
		return this->game_board[i + 1][j].is_empty();
	}
}

bool Game::check_left(int i, int j) {	

	//checks if there is a room to the left
	if(j - 1 == -1) {
		return false;
	}

	//returns if the room to the left is empty
	else {
		return this->game_board[i][j - 1].is_empty();
	}
}

char Game::get_input(){

	//get action, move direction or firing an arrow
	char c;

	cout << endl << endl << "Player move..." << endl << endl;
	cout << "W-up" << endl;
	cout << "A-left" << endl;
	cout << "S-down" << endl;
	cout << "D-right" << endl;
	cout << "f-fire an arrow" << endl;

	//forces the user to input a valid character (wasdf)
	do{
		cout << "Enter a valid input: " << endl;
		cin >> c;
		cin.ignore(256, '\n');
	}while(c != 'w' && c != 'a' && c != 's' && c != 'd' && c != 'f');

	cout << endl;
	return c;
}

void Game::action(Event* e, int a) {

	//changes the picked_gold to true (1)
	if(e->get_symbol() == 'G') {
		this->picked_gold = a;
	}

	//changes the lose to true (1)
	else if(e->get_symbol() == 'W') {
		this->lose = a;
	}

	//changes the lose to true or false (1 or 0)
	else if(e->get_symbol() == 'S') {
		this->lose = a;
	}

	//has to be pool
	else {

		//if not underwater then the user goes underwater (1)
		if(this->underwater == 0) {

			this->underwater += a;
			cout << "You dive into a pool and start exploring underwater." << endl;
		}
		
		//underwater already, so they get out and oxygen resets
		else {

			this->underwater -= a;
			cout << "You climb out of the pool and are out of the water." << endl;
			set_oxygen();
		}
	}
}

void Game::event(int i, int j) {

	Event* e = this->game_board[i][j].get_event();

	//if the wumpus was visited
	if(e->get_symbol() == 'W' && this->underwater == 0) {
		if(e != nullptr) {
			action(e, e->act());
		}
	}

	//if the user is underwater and they visited an event that wasn't a pool
	else if(e->get_symbol() != 'P' && this->underwater == 1);
	
	//encounters the event
	else {

		action(e, e->act());

		if(e->get_symbol() != 'P') {
			delete e;
			this->game_board[i][j].assign_event(nullptr);
		}
	}
}


void Game::play_game(int s, bool d) {

	//sets up game
	Game::set_up(s);
	this->debug_view = d;

	char input, arrow_input;
	
	//while the user hasn't won or lost yet
	while (Game::check_win() == false && this->lose != 1){

		//docks down oxygen if underwater (1)
		if(this->underwater == 1) {
			this->oxygen = this->oxygen - 1;
		}
	
		//print game board
		Game::display_game();

		//display percerts around player's location
		check_percepts();

		//Player move...
		//1. get input
		input = Game::get_input();

		//2. move player
		Game::move(input);
		
		//3. may or may not encounter events

		//finds where the adventurer is
		int i;
		int j;
		find_adventurer(i, j);

		if(!this->game_board[i][j].is_empty()) {
			event(i, j);
		}

		//checks to see if the player is going to drown or not
		if(this->oxygen == 1) {
			cout << "You spent too much time underwater and ended up drowning." << endl;
			break;
		}
	}
	return;
}