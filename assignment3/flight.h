#ifndef FLIGHT_H
#define FLIGHT_H 

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class Flight
{
private: 
	string flight_num;		//flight number
	string curr_loc;		//current airport
	string dest;			//destination 
	int num_pilots;			//number of pilots
	string* pilots;			//pilot array

public:

/*********************************************************************
** Function: Flight()
** Description: Default constructor for the Flight class
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: Flight class is created
*********************************************************************/ 
	Flight();


/*********************************************************************
** Function: Flight & operator=()
** Description: AOO for the Flight class
** Parameters: Flight& obj - flight obj we want to assign to the other flight variable
** Pre-Conditions: flight obj is properly defined
** Post-Conditions: already defined flight object is equal to the parameter flight object
*********************************************************************/ 
	Flight& operator=(const Flight&obj);


/*********************************************************************
** Function: Flight()
** Description: Copy constructor for the Flight class
** Parameters: Flight& obj - flight obj we want to copy to the new defined variable
** Pre-Conditions: flight obj is properly defined
** Post-Conditions: new defined flight object is equal to the parameter flight object
*********************************************************************/ 
	Flight(const Flight& obj);


/*********************************************************************
** Function: ~Flight()
** Description: Destructor for the Flight class
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: Any memory allocated gets deleted once the Flight class goes out of scope
*********************************************************************/ 
	~Flight();


/*********************************************************************
** Function: void populate_flight()
** Description: populates all the information for this flight, transfering the info from the file to the program
** Parameters: ifstream& fin - file where all the information is stored
** Pre-Conditions: the file is opened and has all the information needed
** Post-Conditions: the program has read through all the information in the file into the program
*********************************************************************/ 
	void populate_flight(ifstream& fin);


/*********************************************************************
** Function: void print_flight()
** Description: prints out all the flight information 
** Parameters: none
** Pre-Conditions: flight is properly populated
** Post-Conditions: all the flight's information gets printed out to the user
*********************************************************************/ 
	void print_flight() const;


/*********************************************************************
** Function: int search()
** Description: figures out if the inputted flight number is the same as this flight's number
** Parameters: string - flight number that the user wants to find
** Pre-Conditions: flight is properly populated
** Post-Conditions: returns if the flight number was the same or not
*********************************************************************/ 
	int search(string);


/*********************************************************************
** Function: void make()
** Description: user makes the new flight that they want to add
** Parameters: string - airport that the user wants to add the flight to
** Pre-Conditions: user inputs same data-type when asked
** Post-Conditions: new flight is created and added to the airport array
*********************************************************************/ 
	void make(string);


/*********************************************************************
** Function: void print_file()
** Description: prints all the information of the flight to the new text file
** Parameters: ofstream &fout - file we are trying to write info to
** Pre-Conditions: file exists and is opened, flight is properly populated
** Post-Conditions: the file gains all the flight's information
*********************************************************************/ 
	void print_file(ofstream &fout);


/*********************************************************************
** Function: void set_flight_num()
** Description: mutator for the flight_num variable
** Parameters: string - string that we want to change the flight_num to
** Pre-Conditions: the string is a valid value
** Post-Conditions: flight_num is changed to the parameter
*********************************************************************/ 
	void set_flight_num(string);


/*********************************************************************
** Function: void set_curr_loc()
** Description: mutator for the curr_loc variable
** Parameters: string - string that we want to change the curr_loc to
** Pre-Conditions: the string is a valid value
** Post-Conditions: curr_loc is changed to the parameter
*********************************************************************/ 
	void set_curr_loc(string);


/*********************************************************************
** Function: void set_dest()
** Description: mutator for the dest variable
** Parameters: string - string that we want to change the dest to
** Pre-Conditions: the string is a valid value
** Post-Conditions: dest is changed to the parameter
*********************************************************************/ 
	void set_dest(string);


/*********************************************************************
** Function: void set_num_pilots()
** Description: mutator for the num_pilots variable
** Parameters: int - int that we want to change the num_pilots to
** Pre-Conditions: the int is a valid value
** Post-Conditions: num_pilots is changed to the parameter
*********************************************************************/ 
	void set_num_pilots(const int);


/*********************************************************************
** Function: void set_pilots()
** Description: mutator for the pilots variable
** Parameters: string* - string* that we want to change the pilots to
** Pre-Conditions: the arr is dynamically allocated
** Post-Conditions: pilots is changed to the parameter
*********************************************************************/ 
	void set_pilots(string*);
	

/*********************************************************************
** Function: string get_flight_num()
** Description: accessor for the flight_num variable
** Parameters: none
** Pre-Conditions: flight_num is defined
** Post-Conditions: flight_num is returned
*********************************************************************/
	string get_flight_num() const;


/*********************************************************************
** Function: string get_curr_loc()
** Description: accessor for the curr_loc variable
** Parameters: none
** Pre-Conditions: curr_loc is defined
** Post-Conditions: curr_loc is returned
*********************************************************************/
	string get_curr_loc() const;


/*********************************************************************
** Function: string get_dest()
** Description: accessor for the dest variable
** Parameters: none
** Pre-Conditions: dest is defined
** Post-Conditions: dest is returned
*********************************************************************/
	string get_dest() const;
	

/*********************************************************************
** Function: int get_num_pilots()
** Description: accessor for the num_pilots variable
** Parameters: none
** Pre-Conditions: num_pilots is defined
** Post-Conditions: num_pilots is returned
*********************************************************************/
	int get_num_pilots() const;


/*********************************************************************
** Function: string * get_pilots()
** Description: accessor for the pilots variable
** Parameters: none
** Pre-Conditions: pilots is defined
** Post-Conditions: pilots is returned
*********************************************************************/
	string * get_pilots() const;
};

#endif
