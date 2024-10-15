#include "gold.h"

#include <iostream>

using namespace std;

//Gold Implementation

Gold::Gold() {
    this->symbol = 'G';
}

Gold::~Gold() {
}

char Gold::print_symbol() {
    return 'G';
}

void Gold::print_percepts() {
    cout << "You see a glimmer nearby." << endl;
}

int Gold::act() {
    cout << "You find a pile of gold and you pick it up." << endl;
    return 1;
}