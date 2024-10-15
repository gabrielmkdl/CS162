#ifndef EVENT_H
#define EVENT_H 

using namespace std;

//Event Interface
//Note: this must be an abstract class!

class Event
{

protected:
	char symbol;

public:

/*********************************************************************
** Function: get_symbol()
** Description: accessor for the variable symbol
** Parameters: none
** Pre-Conditions: symbol is initialized and set to a value 
** Post-Conditions: the variable symbol is returned 
*********************************************************************/ 
   char get_symbol() const;


/*********************************************************************
** Function: print_symbol()
** Description: a pure virtual function that prints out the symbol instead of returning it like the previous function
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: every child class has to implement this function
*********************************************************************/ 
   virtual char print_symbol() = 0; 


/*********************************************************************
** Function: print_percepts()
** Description: a pure virtual function that prints the percepts
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: every child class has to implement this function
*********************************************************************/ 
   virtual void print_percepts() = 0;


/*********************************************************************
** Function: act()
** Description: a pure virtual function that represents the action when the adventurer goes into a room with an event
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: every child has to implement this function
*********************************************************************/ 
   virtual int act() = 0;

};
#endif