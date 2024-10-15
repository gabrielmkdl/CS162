#ifndef GOLD_H
#define GOLD_H 

//Gold Interface

#include "event.h"

#include <iostream>
#include <string>

class Gold : public Event {

    public:

/*********************************************************************
** Function: Gold()
** Description: construtor for gold
** Parameters: none
** Pre-Conditions: event class has been properly defined
** Post-Conditions: whenever a gold object is made, the variable symbol is set to G
*********************************************************************/ 
        Gold();


/*********************************************************************
** Function: ~Gold()
** Description: destructor for gold
** Parameters: none
** Pre-Conditions: event class has properly defined
** Post-Conditions: whenever a gold object goes out of scope, this is called
*********************************************************************/ 
        ~Gold();


/*********************************************************************
** Function: print_symbol()
** Description: prints out a G for the symbol of Gold
** Parameters: none
** Pre-Conditions: pure virtual function set up in event
** Post-Conditions: prints out a G
*********************************************************************/ 
        char print_symbol();


/*********************************************************************
** Function: print_percepts()
** Description: prints out the percept for Gold
** Parameters: none
** Pre-Conditions: pure virtual function set up in event
** Post-Conditions: prints out the percept for Gold 
*********************************************************************/ 
        void print_percepts();


/*********************************************************************
** Function: act()
** Description: action for whenever the adventurer enters a room with gold in it
** Parameters: none
** Pre-Conditions: pure virtual function set up in event
** Post-Conditions: picks up the gold and returns a one
*********************************************************************/ 
        int act();
};
#endif