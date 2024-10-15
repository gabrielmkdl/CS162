#ifndef STALACTITES_H
#define STALACTITES_H 

//Stalactites Interface

#include "event.h" 

#include <iostream>
#include <string>

class Stalactites : public Event {

    public:


/*********************************************************************
** Function: Stalactites()
** Description: construtor for Stalactites
** Parameters: none
** Pre-Conditions: event class has been properly defined
** Post-Conditions: whenever a statalactite object is made, the variable symbol is set to S
*********************************************************************/ 
        Stalactites();


/*********************************************************************
** Function: ~Stalactites()
** Description: destructor for Stalactites
** Parameters: none
** Pre-Conditions: event class has properly defined
** Post-Conditions: whenever a Stalactites object goes out of scope, this is called
*********************************************************************/ 
        ~Stalactites();


/*********************************************************************
** Function: print_symbol()
** Description: prints out a S for the symbol of Stalactites
** Parameters: none
** Pre-Conditions: pure virtual function set up in event
** Post-Conditions: prints out a S 
*********************************************************************/ 
        char print_symbol();


/*********************************************************************
** Function: print_percepts()
** Description: prints out the percept for Stalactites
** Parameters: none
** Pre-Conditions: pure virtual function set up in event
** Post-Conditions: prints out the percept for Stalactites 
*********************************************************************/ 
        void print_percepts();


/*********************************************************************
** Function: act()
** Description: action for whenever the adventurer enters a room with a stalactite in it
** Parameters: none
** Pre-Conditions: pure virtual function set up in event
** Post-Conditions: 50/50 chance of the user dying or not and returns a int that signifies that
*********************************************************************/    
        int act();
};
#endif
