#include "catalog.h"
#include <iostream>
#include <fstream>

using namespace std;



Playlist * create_playlists(int size) {

    Playlist * arr = new Playlist [size];
    return arr;
}



void populate_one_list(Playlist * arr, int index, ifstream &file) {

    file >> arr[index].name;
    file >> arr[index].num_song;
    arr[index].s = create_songs(arr[index].num_song);
}



Song* create_songs(int size) {

    Song * arr = new Song [size];
    return arr;
}



void populate_one_song(Song * arr, int index, ifstream &file) {

    file >> arr[index].name;
    file >> arr[index].artist;
    file >> arr[index].year_release;
    file >> arr[index].length;
    file >> arr[index].genre;
    file >> arr[index].res;	
}



void delete_info(Playlist * arr, int size) {

    //deletes all the song arrays
    for (int i = 0; i < size; i++) {

        delete [] arr[i].s;
        arr[i].s = NULL;
    }

    delete [] arr;
    arr = NULL;
}



void swap(Song *x, Song *y) {

    Song temp = *x;
    *x = *y;
    *y = temp;
}



void bubble_sort(Playlist * arr, int size) {
    
    //loops through all the playlist arrays
    for (int i = 0; i < size; i++) {

        bool swapped;
        //loops through every single song in the song array
        for(int j = 0; j < arr[i].num_song - 1; j++) {

            //helps cut down the sorting as we only need to go half way before starting at the next index
            for(int k = 0; k < arr[i].num_song - j - 1; k++) {

                //swaps the songs if the one ahead was released after the one at the current position
                if(arr[i].s[k].year_release < arr[i].s[k + 1].year_release) {

                    swap(arr[i].s[k], arr[i].s[k + 1]);
                    swapped = true;
                }
            }

            //if nothing swapped then we can assume the array has been sorted
            if(swapped == false) {
                break;
            }
        }
    }   
}



Playlist*setup(ifstream &file, int num) {

    Playlist * arr = create_playlists(num);
    
    //outer for loop creates the playlist arrays
    for(int i = 0; i < num; i++) {

        populate_one_list(arr, i, file);
        
        //inner for loop creates all the song arrays inside the playlist arrays
        for(int j = 0; j < arr[i].num_song; j++) {

            populate_one_song(arr[i].s, j, file);
        }
    }

    return arr;
}



string print_option() {

    string print_out;
    cout << "How would you like the information displayed?" << endl;
   
   //forces the user to answer with a 1 or 2
    do
    {
        cout << "1. Print to screen (Press 1)" << endl;
        cout << "2. Print to file (Press 2)" << endl;
        cout << "Your Choice: ";
        cin >> print_out;
        cout << endl;

    } while (print_out != "1" && print_out != "2");
    
    return print_out;
}



void print_console(Playlist * arr, int index, int song_num) {

    cout << "Name: " << arr[index].s[song_num].name << endl;
    cout << "Artist: " << arr[index].s[song_num].artist << endl;
    cout << "Year Released: " << arr[index].s[song_num].year_release << endl;
    cout << "Length: " << arr[index].s[song_num].length << endl;	
    cout << "Genre: " << arr[index].s[song_num].genre << endl;
    cout << "Restriction: " << arr[index].s[song_num].res << endl;
    cout << endl;
}



void print_file(Playlist * arr, int index, int song_num, ofstream &fout) {

    fout << "Name: " << arr[index].s[song_num].name << endl;
    fout << "Artist: " << arr[index].s[song_num].artist << endl;
    fout << "Year Released: " << arr[index].s[song_num].year_release << endl;
    fout << "Length: " << arr[index].s[song_num].length << endl;	
    fout << "Genre: " << arr[index].s[song_num].genre << endl;
    fout << "Restriction: " << arr[index].s[song_num].res << endl;
    fout << endl;
}



void display_song(Playlist * arr, int size, int age) {

    //goes through all the playlist arrays
    for(int i = 0; i < size; i++) {
        
        //goes through all the song arrays inside the playlist arrays
        for(int j = 0; j < arr[i].num_song; j++) {

            //checks if the user is 19 or younger and filters out all the explicit songs if so
            if(age < 20) {
                
                //checks the restriction on each song
                if(arr[i].s[j].res == "None") {

                    cout << "Title: " << arr[i].s[j].name;
                    cout << "   Artist Name: " << arr[i].s[j].artist << endl;
                }
            }
            
            //for users older than 19 who don't need to be filtered
            else {

                cout << "Title: " << arr[i].s[j].name;
                cout << "   Artist Name: " << arr[i].s[j].artist << endl;
            }
        }
    }
    cout << endl << endl;
}



void search_song(Playlist * arr, int size) {

    //keeps track of if the user's song was found
    int found = 0;

    //figures out where the user wants to print their information
    string output = print_option();
    string input;
    cout << "What song do you want to search for: ";
    cin >> input;

    //goes through all the playlist arrays
    for(int i = 0; i < size; i++) {

        //goes through all the song arrays inside the playlist arrays
        for(int j = 0; j < arr[i].num_song; j++) {

            if(input == arr[i].s[j].name) {

                found = 1;
                
                //for printing to console
                if(output == "1") {

                    cout << "Here is the info of the song:" << endl;
                    print_console(arr, i, j);
                }

                //printing to a file
                else {

                    string file_name;
                    cout << "What file do you want to print your output to: ";
                    cin >> file_name;
                    ofstream fout;
                    fout.open(file_name, ios::app);
                    fout << "Here is the info of the song:" << endl;
                    print_file(arr, i, j, fout);
                    fout.close();
                }
            }
        }
    }

    if(found == 0) {
        cout << "Song not found." << endl;
    }
    cout << endl;
}



void search_genre(Playlist * arr, int size) {

    //keeps track on if the genre was found in the catalog
    int found = 0;

    //figures out where the user wants to print their information
    string output = print_option();
    string file_name;
    ofstream fout;
    
    //gets the file that the user wants information printed to if the user chose this option
    if(output == "2") {

        cout << "What file do you want to print your output to: ";
        cin >> file_name;
    }

    string input;
    cout << "What genre do you want to search for: ";
    cin >> input;
    cout << endl;

    //goes through all the playlist arrays
    for(int i = 0; i < size; i++) {

        //goes through all the song arrays inside the playlist arrays
        for(int j = 0; j < arr[i].num_song; j++) {
            
            if(input == arr[i].s[j].genre) {
                
                found = 1;
                
                //prints to console
                if(output == "1") {
                    cout << "Here is the info of the song:" << endl;
                    print_console(arr, i, j);
                }

                //prints to file
                else {
                    
                    fout.open(file_name, ios::app);
                    fout << "Here is the info of the song:" << endl;
                    print_file(arr, i, j, fout);
                    fout.close();
                }
            }
        }
    }

    if(found == 0) {
        cout << "Genre not found." << endl;
    }
    cout << endl;    
}



void playlists_length(Playlist * arr, int size) {

    //figures out where the user wants to print their information
    string output = print_option();
    string file_name;
    ofstream fout;
    float length;
    
    //gets the file the user wants to print their information to if choosing this option
    if(output == "2") {

        cout << "What file do you want to print your output to: ";
        cin >> file_name;
    }
    
    //goes through every playlist array
    for(int i = 0; i < size; i++) {
        
        length = 0;

        //goes through every song array inside each playlist array 
        for(int j = 0; j < arr[i].num_song; j++) {
            length += arr[i].s[j].length;
        }

        arr[i].total_len = length;
        
        //prints to console
        if(output == "1") {

            cout << "Playlist Name: " << arr[i].name << endl;
            cout << "Total Length of Playlist: " << arr[i].total_len << endl << endl;
        }

        //prints to file
        else {

            fout.open(file_name, ios::app);
            fout << "Playlist Name: " << arr[i].name << endl;
            fout << "Total Length of Playlist: " << arr[i].total_len << endl << endl;
            fout.close();
        }
    }
}



void sort(Playlist * arr, int size) {

    //figures out where the user wants to print their information
    string output = print_option();
    string file_name;
    ofstream fout;
    
    //gets the file the user wants to print their information to if choosing this option
    if(output == "2") {

        cout << "What file do you want to print your output to: ";
        cin >> file_name;
    }
    
    //sorts the arrays
    bubble_sort(arr, size);

    //goes through every playlist array
    for(int i = 0; i < size; i++) {   
        
        if(output == "1") {
            cout << "Playlist: " << arr[i].name << endl << endl;
        }

        else {

            fout.open(file_name, ios::app);
            fout << "Playlist: " << arr[i].name << endl << endl;
            fout.close();
        }

        //goes through every song array 
        for(int j = 0; j < arr[i].num_song; j++) {

            //prints to console 
            if(output == "1") {

                cout << "Here is the info of each song:" << endl;
                print_console(arr, i, j);
            }

            //prints to file
            else {

                fout.open(file_name, ios::app);
                fout << "Here is the info of each song:" << endl;
                print_file(arr, i, j, fout);
                fout.close();
            }
        }
    }
}



void choice(int path, Playlist * arr, int size, int age) {

    if(path == 1) {
        display_song(arr, size, age);
    }

    else if(path == 2) {
        search_song(arr, size);
    }

    else if(path == 3) {
        search_genre(arr, size);
    }

    else if(path == 4){
        playlists_length(arr, size);
    }

    else {
        sort(arr,size);
    }
}



int conversion(string input) {

    int valid = 1;
    
    //loops through every single character of the input
    for(int i = 0; i < input.length(); i++) {

        //checks to see if each character is a digit 
        if (!isdigit(input[i])) {

            valid = 0;
            break;
        }
    }

    //if the inputted string was a digit
    if(valid == 1) {
        return stoi(input);
    } 

    //invalid inputs
    else {
        return 0;
    }  
}



int age() {

    int num_age = 0;

    //makes sure the user inputs a positive integer for their age
    while (num_age<1) {

        string age;
        cout << "Enter your age (a number above 0): " ;
        cin >> age;     

        //checks if the string is an integer and converts it into an int if so
        num_age = conversion(age);
    }

    cout << endl << endl;
    return num_age;
}



string options(Playlist * arr, int size, int age) {

    int num_option;
    string str_option;
    
    //makes sure the user inputs a valid option
    do
    {
        cout << "Which option would you like to choose?" << endl;
        cout << "1. Display all songs " << endl;
        cout << "2. Search for a song to play " << endl;
        cout << "3. Search Songs by Genre " << endl;
        cout << "4. Display lenght of all playlists " << endl;
        cout << "5. Sort songs by year of release " << endl;
        cout << "6. Quit" << endl;
        cout << "Your Choice: ";
        cin >> str_option;

        //checks if the string is an integer and converts it into an int if so
        num_option = conversion(str_option);
        cout << endl;
    } while (num_option > 6 || num_option < 1);

    //6 is the quit option, so runs the catalog otherwise 
    if(num_option != 6) {
        choice(num_option, arr, size, age);
    }

    return str_option;
}