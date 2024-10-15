#include "wumpus.h"

#include <iostream>

using namespace std;

//Wumpus Implementation

Wumpus::Wumpus() {
    this->symbol = 'W';
}

Wumpus::~Wumpus() {
}

char Wumpus::print_symbol() {
    return 'W';
}

void Wumpus::print_percepts() {
    cout << "You smell a terrible stench." << endl;
}

int Wumpus::act() {
    cout << "You woke up the Wumpus and it ate you." << endl;
    return 1;
}