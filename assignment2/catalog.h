#include <iostream>
#include <fstream>

using namespace std;

//a struct to hold info of a Playlist
struct Playlist {
	string name;        //name of the playlist, one word
	int num_song;       //number of songs in the playlist
	struct Song *s;     //an array that holds all songs in the playlist
	float total_len;    //total length of the playlist
};

//a struct to hold info of a Song
struct Song {
	string name;		//name of the song, one word
	string artist;		//name of the artist, one word
	int year_release;	//the year of release
	float length;		//length of the song
	string genre;		//genre of the song, one word
	string res;			//"E" or "none" for restriction level
};


/**************************************************
 * Name: create_playlists()
 * Description: This function will dynamically allocate
				an array of playlists (of the requested size)
 * Parameters: int - size of the array
 * Pre-conditions: none
 * Post-conditions: a Playlist array of requested size is created and return
 ***********************************************/
Playlist* create_playlists(int size);


/**************************************************
 * Name: populate_one_list()
 * Description: This function will fill a single playlist struct 
				with information that is read in from the file
 * Parameters:  Playlist* - pointer to the Playlist array
				int - index of the Playlist in the array to be filled 
				ifstream& - input file to get the Playlist information
 * Pre-conditions: Playlist array has been allocated; 
				 provided index is less than the array size
 * Post-conditions: a Playlist at provided index is populated
 ***********************************************/
void populate_one_list(Playlist * arr, int index, ifstream &file); 


/**************************************************
 * Name: create_songs()
 * Description: This function will dynamically allocate
				an array of songs (of the requested size)
 * Parameters: int - size of the array
 * Pre-conditions: none
 * Post-conditions: a Song array of requested size is created and return
 ***********************************************/
Song* create_songs(int size);


/**************************************************
 * Name: populate_one_song()
 * Description: This function will fill a single song struct 
				with information that is read in from the file
 * Parameters:  Song* - pointer to the Song array
				int - index of the Song in the array to be filled 
				ifstream& - input file to get the Song information
 * Pre-conditions: Song array has been allocated; 
				 provided index is less than the array size
 * Post-conditions: a Song at provided index is populated
 ***********************************************/
void populate_one_song(Song * arr, int index, ifstream &file); 


/**************************************************
 * Name: delete_info()
 * Description: This function will  delete all the memory that was dynamically allocated
 * Parameters: Playlist* - the Playlist array
 *             int - size of the array
 * Pre-conditions: the provided Playlist array hasn't been freed yet
 * Post-conditions: the Playlist array, with all Songs inside, is freed
 ***********************************************/
void delete_info(Playlist * arr, int size);


/*********************************************************************
** Function: swap()
** Description: This function swaps two song values with each other
** Parameters: Song *x/*y - both refereneces to a song variable
** Pre-Conditions: the song variables x and y have both been defined
** Post-Conditions: swaps the two variables around in the array 
*********************************************************************/
void swap(Song *x, Song *y);


/*********************************************************************
** Function: bubble_sort()
** Description: This function will sort through the entire array
** Parameters: Playlist * arr - array with all the playlists which contains all the songs
			   int size - number of playlist arrays
** Pre-Conditions: arr is fully populated, size has been correctly defined
** Post-Conditions: sorts the playlists of songs by year of release, newest to oldest
*********************************************************************/
void bubble_sort(Playlist * arr, int size);


/*********************************************************************
** Function: setup()
** Description: This function will setup the entire catalog of playlist/song arrays reading in all the details in the text into the arrays
** Parameters: ifstream &file - file with all the information
			   int num - number of playlists in the text file
** Pre-Conditions: file has all the information needed for each array, file has already been opened and valid
** Post-Conditions: The Playlist arrays and Song arrays are all populated
*********************************************************************/
Playlist*setup(ifstream &file, int num);


/*********************************************************************
** Function: setup()
** Description: This function will setup the entire catalog of playlist/song arrays reading in all the details in the text into the arrays
** Parameters: ifstream &file - file with all the information
			   int num - number of playlists in the text file
** Pre-Conditions: file has all the information needed for each array, file has already been opened and valid
** Post-Conditions: The Playlist arrays and Song arrays are all populated
*********************************************************************/
Playlist*setup(ifstream &file, int num);


/*********************************************************************
** Function: print_option()
** Description: This function figures out whether the user wants the information to put outputted on the console or a text file
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: The user has either picked the console or a text file to get their information printed to
*********************************************************************/
string print_option();


/*********************************************************************
** Function: print_console()
** Description: Prints all the song's information to the console
** Parameters: Playlist * arr - array with all the playlists which contains all the songs
			   int index - index of the playlist that contains the song needed
			   int song_num - index of the song inside the song array
** Pre-Conditions: arr is fully populated, index/song_num isn't past the array's size
** Post-Conditions: returns to the console all the song's information 
*********************************************************************/
void print_console(Playlist * arr, int index, int song_num);


/*********************************************************************
** Function: print_file()
** Description: Prints all the song's information into a file
** Parameters: Playlist * arr - array with all the playlists which contains all the songs
			   int index - index of the playlist that contains the song needed
			   int song_num - index of the song inside the song array
			   ofstream &fout - file where the user wants their information printed to
** Pre-Conditions: arr is fully populated, index/song_num isn't past the array's size, file is opened before funciton call
** Post-Conditions: returns to the chosen file all the song's information
*********************************************************************/
void print_file(Playlist * arr, int index, int song_num, ofstream &fout);


/*********************************************************************
** Function: display_song()
** Description: displays all the songs in the catalog to the user except the explicit songs if the user is 19 or younger
** Parameters: Playlist * arr - array with all the playlists which contains all the songs
			   int size - number of playlist arrays
			   int age - age of the user 
** Pre-Conditions: arr is fully populated, size and age are valid inputs and defined
** Post-Conditions: displays all the songs to the console except explicit songs for users 19 and younger
*********************************************************************/
void display_song(Playlist * arr, int size, int age);


/*********************************************************************
** Function: search_song()
** Description: Searches the catalog for a song that the user inputs
** Parameters: Playlist * arr - array with all the playlists which contains all the songs
			   int size - number of playlist arrays
** Pre-Conditions: arr is fully populated, size has been correctly defined
** Post-Conditions: displays the song's information if found to the user's chosen method or given error message otherwise 
*********************************************************************/
void search_song(Playlist * arr, int size);


/*********************************************************************
** Function: search_genre()
** Description: Searches the catalog for songs with the genre that the user inputs
** Parameters: Playlist * arr - array with all the playlists which contains all the songs
			   int size - number of playlist arrays
** Pre-Conditions: arr is fully populated, size has been correctly defined
** Post-Conditions: prints out every song with the genre that the user wants, or given error message otherwise
*********************************************************************/
void search_genre(Playlist * arr, int size);


/*********************************************************************
** Function: playlists_length()
** Description: Calculates the time length of each playlist
** Parameters: Playlist * arr - array with all the playlists which contains all the songs
			   int size - number of playlist arrays
** Pre-Conditions: arr is fully populated, size has been correctly defined
** Post-Conditions: prints out each playlist's length to the user's chosen output method
*********************************************************************/
void playlists_length(Playlist * arr, int size);


/*********************************************************************
** Function: sort()
** Description: prints out the results of the sorting
** Parameters: Playlist * arr - array with all the playlists which contains all the songs
			   int size - number of playlist arrays
** Pre-Conditions: arr is fully populated, size has been correctly defined
** Post-Conditions: prints out every sorted playlist to the user's chosen method
*********************************************************************/
void sort(Playlist * arr, int size);


/*********************************************************************
** Function: choice()
** Description: calls on other functions depending on user's choice
** Parameters: int path - the user's input/choice for which option they wanted to do
			   Playlist * arr - array with all the playlists which contains all the songs
			   int size - number of playlist arrays
			   int age - user's age
** Pre-Conditions: arr is fully populated, size has been correctly defined, path/age are both valid inputs
** Post-Conditions: runs whichever option the user chose
*********************************************************************/
void choice(int path, Playlist * arr, int size, int age);


/*********************************************************************
** Function: conversion()
** Description: Checks if the input was an integer and converts the string into an integer if valid
** Parameters: string input - user's input 
** Pre-Conditions: none 
** Post-Conditions: converts the string to an integer if the string was an integer, else returns an invalid input
*********************************************************************/
int conversion(string input);


/*********************************************************************
** Function: age()
** Description: asks for the user's age and makes sure it is above 0
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: gets a positive integer for the user's age
*********************************************************************/
int age();


/*********************************************************************
** Function: options()
** Description: makes the user pick one of the options listed
** Parameters: Playlist * arr - array with all the playlists which contains all the songs
			   int size - number of playlist array
			   int age - user's age
** Pre-Conditions: arr is fully populated, size has been correctly defined, age is a valid input
** Post-Conditions: runs the option that the user picked
*********************************************************************/
string options(Playlist * arr, int size, int age);
