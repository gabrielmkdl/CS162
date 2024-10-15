#include "room.h"

using namespace std;

//Room Implementation


Room::Room() {
    this->e = nullptr; 
    this->has_adventurer = false;
}

Room::~Room() {
    
    //checks to see if the pointer is pointing to something
    if(this->e != nullptr) {
        delete this->e;
        this->e = nullptr;
    }
}


Event* Room::get_event() const {
    return this->e;
}

bool Room::get_has_adventurer() const{
    return this->has_adventurer;
}

void Room::set_has_adventurer(const bool b) {
    this->has_adventurer = b;
}

void Room::assign_event(Event * e) {
    this->e = e;
} 

bool Room::is_empty() const{

    //if nullptr then no event is in this room
    if(e == nullptr) {
        return true;
    }
    
    else {
        return false; 
    }
}