#ifndef AIRPORT_H
#define AIRPORT_H 

#include <iostream>
#include <string>
#include <fstream>

#include "flight.h"

using namespace std;

class Airport
{
private:
	string name;		//airport name
	int num_flights;	//number of flights
	int cap;			//capacity
	Flight *f_arr;		//flight array

public:

/*********************************************************************
** Function: Airport()
** Description: Default constructor for the Airport class 
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: Airport class is created
*********************************************************************/
	Airport();


/*********************************************************************
** Function: ~Airport()
** Description: Destructor for the Airport class
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: Any memory allocated gets deleted once the Airport class goes out of scope
*********************************************************************/
	~Airport();


/*********************************************************************
** Function: void populate_airport()
** Description: populates all the airports and flights, transfering the info from the file to the program
** Parameters: ifstream& fin - file where all the information is stored
** Pre-Conditions: the file is opened and has all the information needed
** Post-Conditions: the program has read through all the information in the file into the program
*********************************************************************/
	void populate_airport(ifstream& fin);


/*********************************************************************
** Function: void add_a_flight()
** Description: creates a new flight (user inputted) and adds to the airport
** Parameters: none
** Pre-Conditions: array is properly populated, user inputs same data type answer
** Post-Conditions: a new flight that the user created is added
*********************************************************************/ 
	void add_a_flight();


/*********************************************************************
** Function: void remove_a_flight
** Description: removes a flight that the user picked
** Parameters: int idx - index of the flight that's getting removed
** Pre-Conditions: array is properly populated
** Post-Conditions: removes the flight from the array and moves the remaining elements to the left
*********************************************************************/ 
	void remove_a_flight(int idx);


/*********************************************************************
** Function: void remove()
** Description: removes the flight without printing out the cout statements like the previous one
** Parameters: int idx - index of the flight that's getting removed
** Pre-Conditions: array is properly populated
** Post-Conditions: removes the flight from the array and moves the remaining elements to the left 
*********************************************************************/ 
	void remove(int idx);


/*********************************************************************
** Function: int check()
** Description: finds the destination of the flight that is taking off
** Parameters: int idx - index of the flight that's taking off
** Pre-Conditions: array is properly populated
** Post-Conditions: the destination of the flight is returned
*********************************************************************/ 
	int check(int idx);


/*********************************************************************
** Function: Flight take_off()
** Description: takes the flight and removes it from the original array
** Parameters: int idx - index of the flight that's taking off
			   int dest - destination of the flight in integer value
** Pre-Conditions: array is properly populated
** Post-Conditions: flight is removed from original array and the current location is changed
*********************************************************************/ 
	Flight take_off(int idx, int dest);


/*********************************************************************
** Function: int search()
** Description: searches for a flight in the airport array
** Parameters: string - flight number that the user wants to find
** Pre-Conditions: array is properly populated
** Post-Conditions: returns if the flight was found or not
*********************************************************************/ 
	int search(string);


/*********************************************************************
** Function: void add()
** Description: adds the flight to the new airport
** Parameters: Flight f - new flight that's going to the their destination airport
** Pre-Conditions: array is properly populated
** Post-Conditions: flight is added to the destination airport
*********************************************************************/ 
	void add(Flight f);


/*********************************************************************
** Function: int get_num_dest()
** Description: finds how many flights have this airport as its' destination
** Parameters: string airport - airport that I want to find the stats for 
** Pre-Conditions: array is properly populated, airport exists
** Post-Conditions: returns how many flights have this airport as the destination
*********************************************************************/ 
	int get_num_dest(string airport);


/*********************************************************************
** Function: void print_stats()
** Description: prints the stats of the airport
** Parameters: int idx - the airport that is being printed the stats
			   int destination - number of flights that have this airport as its' destination
** Pre-Conditions: array is properly populated
** Post-Conditions: returns all the stats of the airport
*********************************************************************/ 
	void print_stats(int idx, int destination);


/*********************************************************************
** Function: void print_airport()
** Description: prints out all the flights in the airport
** Parameters: none
** Pre-Conditions: array is properly populated
** Post-Conditions: all the flights are printed out to the user
*********************************************************************/ 
	void print_airport();


/*********************************************************************
** Function: void print_file()
** Description: prints all the airport and flight information to the new text file
** Parameters: ofstream &fout - file we are trying to write info to
** Pre-Conditions: file exists and is opened, array is properly populated
** Post-Conditions: the file gains all the information about the airports and flights
*********************************************************************/ 
	void print_file(ofstream &fout);
	

/*********************************************************************
** Function: void set_name()
** Description: mutator for the name variable
** Parameters: string - string that we want to change the name to
** Pre-Conditions: the string is a valid value
** Post-Conditions: name is changed to the parameter
*********************************************************************/ 
	void set_name(string);


/*********************************************************************
** Function: void set_num_flights()
** Description: mutator for the num_flights variable
** Parameters: int - int that we want to change the num_flights to
** Pre-Conditions: the int is a valid value
** Post-Conditions: num_flights is changed to the parameter
*********************************************************************/ 
	void set_num_flights(int);


/*********************************************************************
** Function: void set_cap()
** Description: mutator for the cap variable
** Parameters: int - int that we want to change the cap to
** Pre-Conditions: the int is a valid value
** Post-Conditions: cap is changed to the parameter
*********************************************************************/ 
	void set_cap(int);


/*********************************************************************
** Function: void set_f_arr()
** Description: mutator for the f_arr variable
** Parameters: Flight * - Flight array that we want to change f_arr to
** Pre-Conditions: the arr is dynamically allocated
** Post-Conditions: f_arr is changed to the parameter
*********************************************************************/ 
	void set_f_arr(Flight *);


/*********************************************************************
** Function: string get_name()
** Description: accessor for the name variable
** Parameters: none
** Pre-Conditions: name is defined
** Post-Conditions: name is returned
*********************************************************************/
	string get_name() const;


/*********************************************************************
** Function: int get_num_flights()
** Description: accessor for the num_flights variable
** Parameters: none
** Pre-Conditions: num_flights is defined
** Post-Conditions: num_flights is returned
*********************************************************************/
	int get_num_flights() const;


/*********************************************************************
** Function: int get_cap()
** Description: accessor for the cap variable
** Parameters: none
** Pre-Conditions: cap is defined
** Post-Conditions: cap is returned
*********************************************************************/
	int get_cap() const; 


/*********************************************************************
** Function: Flight * get_f_arr()
** Description: accessor for the f_arr variable
** Parameters: none
** Pre-Conditions: f_arr is defined
** Post-Conditions: f_arr is returned
*********************************************************************/
	Flight * get_f_arr() const;

};
#endif