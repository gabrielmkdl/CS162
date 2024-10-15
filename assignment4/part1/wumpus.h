#ifndef WUMPUS_H
#define WUMPUS_H 

//Wumpus Interface

#include "event.h"

#include <iostream>
#include <string> 

class Wumpus : public Event {

    public:

/*********************************************************************
** Function: Wumpus()
** Description: construtor for Wumpus
** Parameters: none
** Pre-Conditions: event class has been properly defined
** Post-Conditions: whenever a Wumpus object is made, the variable symbol is set to W
*********************************************************************/ 
        Wumpus();


/*********************************************************************
** Function: ~Wumpus()
** Description: destructor for Wumpus
** Parameters: none
** Pre-Conditions: event class has properly defined
** Post-Conditions: whenever a Wumpus object goes out of scope, this is called
*********************************************************************/ 
        ~Wumpus();


/*********************************************************************
** Function: print_symbol()
** Description: prints out a W for the symbol of Wumpus
** Parameters: none
** Pre-Conditions: pure virtual function set up in event
** Post-Conditions: prints out a W 
*********************************************************************/ 
        char print_symbol();


/*********************************************************************
** Function: print_percepts()
** Description: prints out the percept for Wumpus
** Parameters: none
** Pre-Conditions: pure virtual function set up in event
** Post-Conditions: prints out the percept for Wumpus 
*********************************************************************/ 
        void print_percepts();


/*********************************************************************
** Function: act()
** Description: action for whenever the adventurer enters a room with a wumpus in it
** Parameters: none
** Pre-Conditions: pure virtual function set up in event
** Post-Conditions: the wumpus wakes up and eats the user
*********************************************************************/ 
        int act();
};
#endif