#include "airport.h"

using namespace std;

Airport::Airport() {
	
}

Airport::~Airport() {

	//checks if there are any memory allocated and deallocates them if so
	if(this->f_arr != nullptr) {
		delete [] this->f_arr;
		this->f_arr = nullptr;
	} 
}

void Airport::populate_airport(ifstream& fin){

	string name;
	int num_flights, cap;
	fin >> name;
	fin >> num_flights;
	fin >> cap; 
	this->name = name;
	this->num_flights = num_flights;
	this->cap = cap;
	this->f_arr = new Flight [this->cap];

	//loops through and populates every airport and flight using the file
	for(int i = 0; i < this->num_flights; i++) {
		this->f_arr[i].populate_flight(fin);
	}
}

void Airport::add_a_flight() {
	
	//checks to see if the airport is full
	if(this->num_flights == this->cap) {
		cout << "Cannot add more flights to this airport" << endl;
	}

	else {

		//makes the new flight and adds it to the airport array
		this->f_arr[this->num_flights].make(this->name);

		//increments the flight number by one
		this->num_flights = this->num_flights + 1;
	}
}

void Airport::remove_a_flight(int idx) {

	//checks to see if the flight exists
	if(idx >= this->num_flights || idx < 0) {
		cout << "Unable to remove the element as flight doesn't exist." << endl;
	}
	
	else {

		cout << "The following flight has been cancelled:" << endl;
		cout << "----------------------" << endl; 

		//prints out the flight that was removed
		this->f_arr[idx].print_flight();

		//moves the existing flights to the left 
		for(int i = idx + 1; i < this->num_flights; i++) {
			this->f_arr[i - 1] = this->f_arr[i];
		}
		this->num_flights = this->num_flights - 1;

	}
}

void Airport::remove(int idx) {
	
	//moves the existing flights to the left without printing out the cout statement above
	for(int i = idx + 1; i < this->num_flights; i++) {
		this->f_arr[i - 1] = this->f_arr[i];
	}
	this->num_flights = this->num_flights - 1;
}

int Airport::check(int idx) {

	//checks to see if the flight exists
	if(idx >= this->num_flights || idx < 0) {
		cout << "Unable to take off as the flight doesn't exist." << endl;
		return 0;
	}	

	else {

		//finds the destination that the flight is going to
		string dest = this->f_arr[idx].get_dest();
		
		if(dest == "A") {
			return 1;
		}

		if(dest == "B") {
			return 2;
		}

		if(dest == "C") {
			return 3;
		}
	}	
	return 0;
}

Flight Airport::take_off(int idx, int dest) {

	cout << "The following flight has been taken off:" << endl;
	cout << "----------------------" << endl; 
	this->f_arr[idx].print_flight();
	Flight f = f_arr[idx];

	string curr;
	if(dest == 1) {
		curr = "A";
	}

	else if(dest == 2) {
		curr = "B";
	}

	else {
		curr = "C";
	}

	//changes the curr location to the destination airport
	f.set_curr_loc(curr);

	//removes the flight from the original array
	Airport::remove(idx);
	return f;
}

int Airport::search(string input) {

	//variable that keeps track if the flight was found in this airport or not
	int valid = 0;

	for(int i = 0; i < this->num_flights; i++) {
		
		//searches for the flight in the array
		int found = this->f_arr[i].search(input);
		
		if(found == 1) {
			valid = 1;
		}
	}
	return valid;
}

void Airport::add(Flight f) {

	//adds the takeoff flight to the destination airport
	this->f_arr[this->num_flights] = f;
	this->num_flights = this->num_flights + 1;
}

int Airport::get_num_dest(string airport) {

	int num_dest = 0;

	//checks to see how many flights in this airport have a certain destination
	for(int i = 0; i < this->num_flights; i++) {
		if(airport == this->f_arr[i].get_dest()) {
			num_dest++;
		}
	}
	return num_dest;
}

void Airport::print_stats(int idx, int destination) {

	string airport;
	if(idx == 1) {
		airport = "A";
	}
	else if(idx == 2) {
		airport = "B";
	}
	else {
		airport = "C";
	}

	cout << endl << "Airport " << airport << endl;
	cout << "capacity: " << get_cap() << endl;
	cout << "Listed as destination: " << destination << " flights" << endl << endl;
}

void Airport::print_airport() {

	cout << endl << endl;
	cout << "**********************************" << endl;
	cout << "******Airport Name: " << this->name << "******" << endl;
	cout << "Capacity: " << this->cap << endl;
	int num_flights = this->num_flights;
	
	//loops through all the flights in the array
	for(int i = 0; i < this->num_flights; i++) {

		cout << "Flight " << i+1 << ":" << endl;
		this->f_arr[i].print_flight();
	}
}

void Airport::print_file(ofstream &fout) {

	fout << this->name << " ";
	fout << this->num_flights << " ";
	fout << this->cap << endl;

	//loops through all the flights in the array
	for(int i = 0; i < this->num_flights; i++) {
		this->f_arr[i].print_file(fout);
	}
}

void Airport::set_name(string name) {
	this->name = name;
}

void Airport::set_num_flights(int num_flights) {
	this->num_flights = num_flights;
}

void Airport::set_cap(int cap) {
	this->cap = cap;
}

void Airport::set_f_arr(Flight * f_arr) {
	this->f_arr = f_arr;
}

string Airport::get_name() const {
	return this->name;
}

int Airport::get_num_flights() const {
	return this->num_flights;
}

int Airport::get_cap() const {
	return this->cap;
}

Flight * Airport::get_f_arr() const {
	return this->f_arr;
}