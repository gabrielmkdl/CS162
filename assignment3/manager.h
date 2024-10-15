#ifndef MANAGER_H
#define MANAGER_H 

#include "airport.h"
#include <iostream>
#include <fstream>

using namespace std;

class Manager
{
private:
	int num_airports;	//number of airports
	Airport* a_arr;		//airport array

public:

/*********************************************************************
** Function: Manager()
** Description: Default constructor for the Manager class
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: Manager class is created
*********************************************************************/ 
	Manager();


/*********************************************************************
** Function: ~Manager() 
** Description: Destructor for the Manager class
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: Any memory allocated gets deleted once the Manager class goes out of scope
*********************************************************************/ 	
	~Manager();


/*********************************************************************
** Function: void populate
** Description: populates all the airports and flights, transfering the info from the file to the program
** Parameters: ifstream& fin - file where all the information is stored
** Pre-Conditions: the file is opened and has all the information needed
** Post-Conditions: the program has read through all the information in the file into the program
*********************************************************************/ 
	void populate(ifstream& fin);


/*********************************************************************
** Function: int init()
** Description: opens the file, checks if the file is there, and then calls on other functions to populate the program
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: file is opened and all the arrays are populated, unless the file doesn't exist
*********************************************************************/ 
	int init();


/*********************************************************************
** Function: void print_menu()
** Description: prints out all the options to the user
** Parameters: none
** Pre-Conditions: none 
** Post-Conditions: options are printed to user and prompts user for option
*********************************************************************/
	void print_menu();


/*********************************************************************
** Function: int get_menu_choice()
** Description: gets the user's input and makes sure it's valid
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: the user has make a valid choice 
*********************************************************************/	
	int get_menu_choice();
	

/*********************************************************************
** Function: void print_all()
** Description: loops through all the airports to print all of them out
** Parameters: none
** Pre-Conditions: all the variables, num_airport and a_arr have been properly populated
** Post-Conditions: all the flights are printed out to the user
*********************************************************************/	
	void print_all();


/*********************************************************************
** Function: void check_flight_control()
** Description: gets the user's input for the flight number and checks every airport for the flight number
** Parameters: none
** Pre-Conditions: all the arrays are properly populated
** Post-Conditions: the flight is either found and printed to the user or an error message is printed out
*********************************************************************/	
	void check_flight_control();


/*********************************************************************
** Function: void add_flight_control()
** Description: gets the user's input on what airport they want to add a flight to and then tries to add one
** Parameters: none
** Pre-Conditions: arrays are properly populated
** Post-Conditions: the flight is either added or an error message is printed out
*********************************************************************/	
	void add_flight_control();


/*********************************************************************
** Function: void cancel_flight_optoion
** Description: gets the user's input on what flight they want to remove and tries to remove it
** Parameters: none
** Pre-Conditions: arrays are properly populated
** Post-Conditions: the flight is either removed or an error message is printed out
*********************************************************************/	
	void cancel_flight_control();


/*********************************************************************
** Function: void take_off_control()
** Description: get the user's input on what flight they want to takeoff and tries to takeoff the plane
** Parameters: none
** Pre-Conditions: arrays are properly populated
** Post-Conditions: the flight is either taken off and is in the new array and off the old one or an error message is printed out
*********************************************************************/
	void take_off_control();


/*********************************************************************
** Function: int destination()
** Description: founds out how many flights have a certain airport as its' destination
** Parameters: int i - airport that we are trying to find how many flights have it as its' destination
** Pre-Conditions: arrays are properly populated
** Post-Conditions: the number of flights that have this airport as its' destination is returned
*********************************************************************/	
	int destination(int i);


/*********************************************************************
** Function: stats_control()
** Description: prints out all the stats for each airport
** Parameters: none
** Pre-Conditions: arrays are properly populated
** Post-Conditions: prints out all the stats to the user
*********************************************************************/
	void stats_control();


/*********************************************************************
** Function: void print_file()
** Description: prints out the new arrays to the airport file
** Parameters: none
** Pre-Conditions: arrays are properly populated
** Post-Conditions: print out the new arrays to the airport file 
*********************************************************************/
	void print_file();


/*********************************************************************
** Function: void run()
** Description: runs the whole program
** Parameters: none
** Pre-Condition: all the functions work properly
** Post-Conditions: the whole program is ran depending on what the user picks
*********************************************************************/
	void run();


/*********************************************************************
** Function: void set_num_airports()
** Description: mutator for the num_airport variable
** Parameters: int - number that we want to change the variable num_airport to
** Pre-Conditions: num_airports is a valid value
** Post-Conditions: num_airports is changed to the parameter
*********************************************************************/
	void set_num_airports(int);	


/*********************************************************************
** Function: void set_a_arr()
** Description: mutator for the a_arr variable
** Parameters: Airport * - arr that we want to change the variable to
** Pre-Conditions: the arr is dynamically allocated
** Post-Conditions: a_arr is changed to the parameter
*********************************************************************/
	void set_a_arr(Airport*);


/*********************************************************************
** Function: int get_num_airports()
** Description: accessor for the num_airports variable
** Parameters: none
** Pre-Conditions: num_airports is defined
** Post-Conditions: num_airports is returned
*********************************************************************/
	int get_num_airports() const;


/*********************************************************************
** Function: Airport * get_a_arr()
** Description: accessor for the a_arr variable
** Parameters: none
** Pre-Conditions: a_arr is defined
** Post-Conditions: a_arr is returned
*********************************************************************/
	Airport * get_a_arr() const;
	
};
#endif