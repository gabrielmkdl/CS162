#include "flight.h"

using namespace std;

Flight::Flight() {
	
}

Flight& Flight::operator=(const Flight& obj) {

	//checks to see if both objects are the same bc if so there's no point in copying
	if(this != &obj) {

		this->flight_num = obj.flight_num;
		this->curr_loc = obj.curr_loc;
		this->dest = obj.dest;
		this->num_pilots = obj.num_pilots;

		//deletes any memory that was allocated 
		if (this->pilots != nullptr) {
			delete [] this->pilots;
		}

		this->pilots = new string [this->num_pilots];
		
		for(int i = 0; i < this->num_pilots; i++) {
			this->pilots[i] = obj.pilots[i];
		}
	}
	return *this;
}

Flight::Flight(const Flight& obj) {

	this->flight_num = obj.flight_num;
	this->curr_loc = obj.curr_loc;
	this->dest = obj.dest;
	this->num_pilots = obj.num_pilots;	
	this->pilots = new string [this->num_pilots];
	
	for(int i = 0; i < this->num_pilots; i++) {
		this->pilots[i] = obj.pilots[i];
	}
}

Flight::~Flight() {
	
	//checks if there are any memory allocated and deallocates them if so
	if(this->pilots != nullptr) {
		delete [] this->pilots;
		this->pilots = nullptr;
	}
}
void Flight::populate_flight(ifstream& fin) {

	//populates the flights with the information from the file
	string flight_num, curr_loc, dest;
	int num_pilots;
	fin >> flight_num;
	fin >> curr_loc;
	fin >> dest;
	fin >> num_pilots;
	this->flight_num = flight_num;
	this->curr_loc = curr_loc;
	this->dest = dest;
	this->num_pilots = num_pilots;
	string * pilots = new string [num_pilots];
	this->pilots = pilots;

	//populates the pilots array
	for(int i = 0; i < num_pilots; i++) {
		string temp;
		fin >> temp;
		pilots[i] = temp;
	}
}

void Flight::print_flight() const {
	
	cout << "----------------------" << endl;
	cout << "Flight #: "  << this->flight_num << endl;
	cout << "Current at: " << this->curr_loc << endl;
	cout << "Destination: " << this->dest << endl;
	int num_pilots = this->num_pilots;
	string * pilots = this->pilots;

	for(int i = 0; i < num_pilots; i++) {

		cout << "Pilot " << i+1 << ": " << pilots[i] << endl;
	}
	cout << "----------------------" << endl << endl;
}

int Flight::search(string input) {

	string flight_num = this->flight_num;

	//checks to see if the inputted flight number equals this flight's flight number
	if(input == flight_num) {

		cout << "Flight Found!" << endl;

		//prints out all the info of this flight
		Flight::print_flight();
		return 1;
	}
	return 0;
}

void Flight::make(string name) {

	string flight_num, dest;
	int num_pilots;
	this->curr_loc = name;
	
	cout << "Enter flight no.: ";
	cin >> flight_num;
	this->flight_num = flight_num;
	
	cout << "Enter destination: ";
	cin >> dest;
	this->dest = dest;

	cout << "Number of pilots: ";
	cin >> num_pilots;
	this->num_pilots = num_pilots;
	string * pilots = new string [num_pilots];

	for(int i = 0; i < num_pilots; i++) {

		string name;
		cout << "Enter name for pilot " << i+1 << ": ";
		cin >> name;
		pilots[i] = name;
	}

	this->pilots = pilots;
	cout << endl << "The flight has been added!" << endl;
}

void Flight::print_file(ofstream &fout) {

	fout << this->flight_num << " ";
	fout << this->curr_loc << " ";
	fout << this->dest << " ";
	fout << this->num_pilots << " ";
	
	for(int i = 0; i < this->num_pilots; i++) {
		fout << this->pilots[i] << " ";
	}
	fout << endl;
}

void Flight::set_flight_num(string flight_num) {
	this->flight_num = flight_num;
}

void Flight::set_curr_loc(string curr_loc) {
	this->curr_loc = curr_loc;
}

void Flight::set_dest(string dest) {
	this->dest = dest;
}

void Flight::set_num_pilots(const int num_pilots) {
	this->num_pilots = num_pilots;
}

void Flight::set_pilots(string * pilots) {
	this->pilots = pilots;
}

string Flight::get_flight_num() const {
	return this->flight_num;
}

string Flight::get_curr_loc() const {
	return this->curr_loc;
}

string Flight::get_dest() const {
	return this->dest;
}

int Flight::get_num_pilots() const {
	return this->num_pilots;
}

string * Flight::get_pilots() const {
	return this->pilots;
}
