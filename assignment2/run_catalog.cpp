/*********************************************************************
** Program Filename: run_catalog.cpp
** Author: Gabriel de Leon
** Date: 2/11/24
** Description: Make a music catalog that takes in a file text and creates playlists which the user can browse through. The program keeps running until prompted otherwise.
** Input: file_name with all the playlist information, age of the user, what they want to do in the catalog, printing option, and file name if wanting to print results on new file
** Output: display all the songs except explicit songs for 19 and younger, find a song in the catalog, find songs of a specific genre in the catalog, and time length of each playlist
*********************************************************************/



#include "catalog.h"
#include <iostream>
#include <fstream>

using namespace std;


int main() {

	string run = "0";
	ifstream file;
	string file_name;
	cout << "Enter the playlist info file name: ";
	cin >> file_name;
	file.open(file_name);

	//checks if a valid file name is given
	if(!file.is_open()) {
		cout << "File not found." << endl;
		return 1;
	}

	int playlists;
	file >> playlists;
	
	//creates all the playlist and song arrays
	Playlist * arr = setup(file, playlists);

	//sets up the age int
	int users_age = age();
	file.close();
	
	//makes the program continue to run until prompted otherwise
    do
    {
		//simulates the whole music catalog program 
		run = options(arr, playlists, users_age);

    } while (run != "6");

	delete_info(arr, playlists);
	return 0;
}