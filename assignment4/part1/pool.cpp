#include "pool.h"

#include <iostream>

using namespace std;

//Pool Implementation

Pool::Pool() {
    this->symbol = 'P';
}

Pool::~Pool() {
}

char Pool::print_symbol() {
    return 'P';
}

void Pool::print_percepts() {
    cout << "You hear wind blowing." << endl;
}

int Pool::act() {
    return 1;
}