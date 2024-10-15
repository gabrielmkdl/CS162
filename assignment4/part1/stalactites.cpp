#include "stalactites.h"

#include <iostream>

using namespace std;

//Stalactites Implementation

Stalactites::Stalactites() {
    this->symbol = 'S';
}

Stalactites::~Stalactites() {
}
char Stalactites::print_symbol() {
    return 'S';
}

void Stalactites::print_percepts() {
    cout << "You hear water dripping." << endl;
}

int Stalactites::act() {

    //chooses between a 0 or 1 creating a 50/50 chance
    int r = rand() % 2;
    
    //returning a 1 means that the user has lost
    if(r == 1) {
        cout << "A stalactite fell from the ceiling and hit your head." << endl;
        return 1;
    }

    //returning a 0 means that the user hasn't lost
    else {
        cout << "A stalactite fell from the ceiling and narrowly missed your head." << endl;
        return 0;
    }
}