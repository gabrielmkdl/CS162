#ifndef ROOM_H
#define ROOM_H 

#include "event.h"

using namespace std;

//Room Interface
class Room {

	private: 
		Event *e; //event object pointer
		bool has_adventurer; //keeps track of the location of the adventurer in which room through this boolean

	public:

/*********************************************************************
** Function: Room()
** Description: Constructor for Room object
** Parameters: none
** Pre-Conditions: event class is properly defined
** Post-Conditions: variable e is set to nullptr and has_adventurer is set to false whenever a new room object is made
*********************************************************************/ 
		Room();


/*********************************************************************
** Function: ~Room() 
** Description: Destructor for Room object 
** Parameters: none
** Pre-Conditions: Event class is properly defined
** Post-Conditions: whenever a room object goes out of scope, this is called
*********************************************************************/ 
		~Room();


/*********************************************************************
** Function: get_event()
** Description: accessor for variable e
** Parameters: none
** Pre-Conditions: variable e is properly defined
** Post-Conditions: returns the variable e
*********************************************************************/ 
		Event* get_event() const;


/*********************************************************************
** Function: get_has_adventurer()
** Description: accessor for variable has_adventurer
** Parameters: none
** Pre-Conditions: variable has_adventurer is properly defined
** Post-Conditions: returns the variable has_adventurer
*********************************************************************/ 
		bool get_has_adventurer() const;


/*********************************************************************
** Function: set_has_adventurer()
** Description: mutator for the variable has_adventurer
** Parameters: bool - boolean that we want the variable has_adventurer to be
** Pre-Conditions: parameter is properly defined
** Post-Conditions: has_adventurer is set to the parameter
*********************************************************************/ 
		void set_has_adventurer(const bool);


/*********************************************************************
** Function: assign_event()
** Description: mutator for the variable e
** Parameters: Event* - event pointer that we want the variable e to be
** Pre-Conditions: parameter is properly defined
** Post-Conditions: variable e is set to the parameter
*********************************************************************/ 
		void assign_event(Event*);


/*********************************************************************
** Function: is_empty()
** Description: checks to see if the room has an event in it or not
** Parameters: none
** Pre-Conditions: room is properly defined
** Post-Conditions: returns a boolean value of if the room is empty or not
*********************************************************************/ 
		bool is_empty() const;
};

#endif