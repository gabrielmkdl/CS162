#ifndef POOL_H
#define POOL_H 

//Pool Interface

#include "event.h"

#include <iostream>
#include <string>

class Pool : public Event {

    public:

/*********************************************************************
** Function: Pool()
** Description: constructor for Pool object
** Parameters: none
** Pre-Conditions: event class is properly defined
** Post-Conditions: symbol variable is set to P when new pool object is made
*********************************************************************/ 
        Pool();


/*********************************************************************
** Function: ~Pool()
** Description: destructor for Pool object
** Parameters: none
** Pre-Conditions: event class is properly defined
** Post-Conditions: whenever a pool object goes out of scope, this is called
*********************************************************************/ 
        ~Pool();

    
/*********************************************************************
** Function: print_symbol()
** Description: prints out a P for the symbol of Pool
** Parameters: none
** Pre-Conditions: pure virtual function set up in event
** Post-Conditions: prints out a P
*********************************************************************/ 
        char print_symbol(); 


/*********************************************************************
** Function: print_percepts()
** Description: prints out the percept for Pool
** Parameters: none
** Pre-Conditions: pure virtual function set up in event
** Post-Conditions: prints out the percept for Pool 
*********************************************************************/  
        void print_percepts();


/*********************************************************************
** Function: act()
** Description: action for whenever the adventurer enters a room with a pool in it
** Parameters: none
** Pre-Conditions: pure virtual function set up in event
** Post-Conditions: returns a one which can change whether the adventurer is diving in or getting out of the pool
*********************************************************************/ 
        int act();
};

#endif