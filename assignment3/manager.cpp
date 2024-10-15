#include "manager.h"

using namespace std;


Manager::Manager(){

}

Manager::~Manager() {
	
	//checks if there are any memory allocated and deallocates them if so
	if(this->a_arr != nullptr) {
		delete [] this->a_arr;
		this->a_arr = nullptr;
	} 
}

void Manager::populate(ifstream& fin) {

	int num_airports;
	fin >> num_airports;
	this->num_airports = num_airports;
	Airport * a_arr = new Airport [num_airports];
	this->a_arr = a_arr;

	//loops through and populates every airport and flight using the file
	for(int i = 0; i < num_airports; i++) {
		this->a_arr[i].populate_airport(fin);
	}
}

int Manager::init(){

	ifstream fin;
	fin.open("airport.txt");

	//Error opening file?:
	if(!fin.is_open()) {
		cout << "File not found." << endl;
		return 0;
	}

	//populates all the arrays
	Manager::populate(fin);
	fin.close();
	return 1;
}

void Manager::print_menu(){

	cout << endl;
	cout << "1. View all Airports & Flights info" << endl;
	cout << "2. Check flight info" << endl;
	cout << "3. Add a new flight" << endl;
	cout << "4. Cancel a flight" << endl;
	cout << "5. Take off a flight" << endl;
	cout << "6. Print airport stats" << endl;
	cout << "7. Quit" << endl;
	cout << "Your choice: ";
}

int Manager::get_menu_choice() {

	//prints out all the options to the user
	Manager::print_menu();
	int choice = 0;
	cin >> choice;
	
	//makes sure the user inputs a valid option
	while(choice > 7 || choice < 1) {

		cout << endl << "Please enter a valid input between 1-7: ";
		cin >> choice;
		cout << endl;
	}
	return choice;
}

void Manager::print_all(){

	//loop sthrough all the arrays and prints them out to the user
	for(int i = 0; i < this->num_airports; i++) {
		this->a_arr[i].print_airport();	
	}
}

void Manager::check_flight_control() {

	//variable for tracking if the flight was found or not
	int found = 0;
	string input;
	cout << "Enter the flight number: ";
	cin >> input;

	//loops through every airport looking for the flight
	for(int i = 0; i < this->num_airports; i++) {
		found = this->a_arr[i].search(input);
	}

	if(found == 0) {
		cout << "Cannot find your flight" << endl << endl;
	}
}

void Manager::add_flight_control() {

	cout << endl;
	int input;
	cout << "1. Airport A" << endl;
	cout << "2. Airport B" << endl;
	cout << "3. Airport C" << endl;

	//forces the user to pick a valid option
	do
	{
		cout << "Choose an airport: ";
		cin >> input;

	} while (input > 3 || input < 1);
	
	//adds a flight to the airport of the user's choice
	this->a_arr[input - 1].add_a_flight();
}

void Manager::cancel_flight_control() {

	int input;
	int flight;
	cout << endl;
	cout << "1. Airport A" << endl;
	cout << "2. Airport B" << endl;
	cout << "3. Airport C" << endl;

	//forces the user to pick a valid option
	do
	{
		cout << "Choose an airport: ";
		cin >> input;

	} while (input > 3 || input < 1);
	
	//prints all the flights in the airport to the user to let them choose
	this->a_arr[input - 1].print_airport();
	cout << "Choose a flight: ";
	cin >> flight;
	
	//removes the flight at the airport the user has picked
	this->a_arr[input - 1].remove_a_flight(flight - 1);
}

void Manager::take_off_control() {

	int input;
	int flight;
	cout << endl;
	cout << "1. Airport A" << endl;
	cout << "2. Airport B" << endl;
	cout << "3. Airport C" << endl;
	
	//forces the user to pick a valid option
	do
	{
		cout << "Choose an airport: ";
		cin >> input;

	} while (input > 3 || input < 1);

	//prints all the flihgts in the airport to the user to let them choose
	this->a_arr[input - 1].print_airport();
	cout << "Choose a flight: ";
	cin >> flight;

	//checks to see what the destination is and if the flight actually exists
	int dest = this->a_arr[input - 1].check(flight - 1);

	//means there is a destination and the flight does exist
	if(dest != 0) {
		
		//checks to make sure there is enough room for the plane to takeoff to their dest airport
		if(this->a_arr[dest - 1].get_num_flights() == this->a_arr[dest - 1].get_cap()) {
			cout << "Flight unable to takeoff due to airport being full" << endl;
		}

		else {
			
			//moves the flight to the dest airport and removes the flight from its old airport array
			Flight f = this->a_arr[input - 1].take_off(flight - 1, dest);

			//adds the flight to the new airport array
			this->a_arr[dest - 1].add(f);
		}
	}
}

int Manager::destination(int i) {
	
	string airport; 
	int total = 0;

	//all of these if statements convert the "i" to the equivalent string meaning
	if(i == 0) {
		airport = "A";
	}
	else if(i == 1) {
		airport = "B";
	}
	else {
		airport = "C";
	}

	//loops through the airport arrays to see how many flights have the dest as the airport we're targetting
	for(int i = 0; i < this->num_airports; i++) {
		total = total + this->a_arr[i].get_num_dest(airport);
	}
	return total;
}

void Manager::stats_control() {
	
	//loops through all the airports
	for(int i = 0; i < this->num_airports; i++) {
		
		//finds out how many flights have a certain airport as its' destination
		int destination = Manager::destination(i);

		//prints out the stats of each airport
		this->a_arr[i].print_stats(i + 1, destination);
	}
}

void Manager::print_file() {

	ofstream fout;
	fout.open("airport.txt");
	fout << this->num_airports << endl;

	//loops throguh all the airports
	for(int i = 0; i < this->num_airports; i++) {
		
		//prints out every flight in each airport
		this->a_arr[i].print_file(fout);
	}
	fout.close();
}

void Manager::run() {
	
	cout << endl;
	cout << "Welcome to Flight Manager!!" << endl;
	if (Manager::init() != 1)
		return;

	int choice = -1;
	while (choice != 7)
	{
		choice = Manager::get_menu_choice();

		//print all
		if (choice == 1) 
			Manager::print_all();

		//flight info
		else if (choice == 2){
			Manager::check_flight_control();
		}
		//add a new flight
		else if (choice == 3) {
			Manager::add_flight_control();
		}
		//cancel a flight
		else if (choice == 4) {
			Manager::cancel_flight_control();
		}
		//take off a flight
		if (choice == 5){
			Manager::take_off_control();
		}
		//airport stats
		else if (choice == 6) {
			Manager::stats_control();
		}
	}
	
	cout << "Bye!" << endl << endl;
	Manager::print_file();
	return;
}

void Manager::set_num_airports(int num_airports) {
	this->num_airports = num_airports;
}

void Manager::set_a_arr(Airport* a_arr) {
	this->a_arr = a_arr;
}

int Manager::get_num_airports() const {
	return this->num_airports;
}

Airport * Manager::get_a_arr() const {
	return this->a_arr;
}