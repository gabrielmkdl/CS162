/*********************************************************************
** Program Filename: assignment1.cpp
** Author: Gabriel de Leon
** Date:1/26/2024
** Description: Write a program that simulates the three point contest in the NBA for N players. Runs at least once and continues until the user stops the program.
** Input: The money-ball rack position, the shooting ability for each player, a play again or quit input, and number of players
** Output: The shooting outcomes of each rack, score of each rack, total score, and the game winner
*********************************************************************/


#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;


/*********************************************************************
** Function: int players
** Description: takes the users input for the number of players and makes sure it's above 1
** Parameters: none
** Pre-Conditions: inputted values are integers
** Post-Conditions: takes valid inputs for the amount of players playing in this game 
*********************************************************************/ 


int players() {

    int num = 0;
    
    //sets up the number of players in the game
    do
    {
        cout << "How many players do you want in this game. Please enter a number greater than 1: ";
        cin >> num;

    } while (num<2);
    
    cout << endl;
    return num;

}


/*********************************************************************
** Function: void setup
** Description: takes the users input for their money-ball rack position and shooting ability and makes sure it"s in the given range
** Parameters: int &money and int &shooting
** Pre-Conditions: inputted values are integers
** Post-Conditions: takes valid inputs for the shooting ability and money-ball rack position and changes the original values in main 
*********************************************************************/ 


void setup(int &money, int &shooting) {

    //sets up the money-ball rack position
    do
    {
        cout << "Where do you want to put your money-ball rack? Enter 1-5: ";
        cin >> money;

    } while (money < 1 || money > 5);

    //sets up the shooting ability
    do
    {
        cout << "Enter your shooting ability, from 1 to 99: ";
        cin >> shooting;
    
    } while (shooting < 1 || shooting > 99);   
    
    cout << endl << endl;

}


/*********************************************************************
** Function: int shot
** Description: determines whether the shot attempt was successful or not by generating a random number and comparing that to the shooting ability
** Parameters: int shooting
** Pre-Conditions: inputted values are integers in the valid range
** Post-Conditions: returns either a 1 for a made shot or a 0 for a missed shot
*********************************************************************/ 


int shot(int shooting) {

    int random = rand() % 101;

    if (shooting >= random) {
        return 1;
    }

    else {
        return 0;
    }

}


/*********************************************************************
** Function: void money_letter_conversion
** Description: takes the array of made/missed shots from the money ball rack and converts the shots into an M or X for a made/missed shot
** Parameters: int array[]
** Pre-Conditions: array has five values in it and all the values are either a 1 or 0
** Post-Conditions: prints out M's and X's to the user to show if they made or missed the shots on the money-ball rack
*********************************************************************/ 


void money_letter_conversion(int array[]) {

    //loops through array
    for (int i = 0; i < 5; i++) {
        
        //made shot
        if (array[i] == 1) {
            cout << "M ";
        }

        //missed shot
        else {
            cout << "X ";
    
        }

    }
    
    cout << " | ";

}


/*********************************************************************
** Function: int money_rack
** Description: creates an array that takes in whether each shot was made or missed and calculates the total score for the money-ball rack and prints it out to the user
** Parameters: int shooting and int position
** Pre-Conditions: inputted values are integers in the valid range
** Post-Conditions: prints out the total score for the rack and creates an array with all five attempted shots for the money-ball rack
*********************************************************************/ 


int money_rack(int shooting, int position) {

    int rack_score = 0;
    int *rack = new int [5];
    
    //simulates five shots
    for (int i = 0; i < 5; i++) {
    
        int attempt = shot(shooting);
        rack[i] = attempt;
        rack_score += attempt * 2;
    
    }

    cout << "Rack " << position << " : ";
    money_letter_conversion(rack);
    cout << rack_score << " pts" << endl;

    delete [] rack;
    rack = NULL;

    return rack_score;

}


/*********************************************************************
** Function: void letter_conversion
** Description: takes the array of made/missed shots from all the regular racks and converts the shots into a M or O or X 
** Parameters: int array[]
** Pre-Conditions: array has five values and all the values are either a 1 or 0
** Post-Conditions: prints out M's, O's, or X's to the user to show what shots they made
*********************************************************************/ 


void letter_conversion(int array[]) {

    //loops through array
    for (int i = 0; i < 5; i++) {
        
        //made shot
        if (array[i] == 1) {
            
            //money ball shot
            if (i == 4) {
                cout << "M ";
            }

            //regular shot
            else {
                cout << "O ";
            }
    
        }
    
        //missed shot
        else {
            cout << "X ";
        }
    
    }
    
    cout << " | ";

}


/*********************************************************************
** Function: int single_rack
** Description: creates an array that takes in whether each shot was made or missed and calculates the total score for the regular racks and prints it out to the user
** Parameters: int shooting and int position
** Pre-Conditions: inputted values are integers in the valid range
** Post-Conditions: prints out the total score for the rack and creates an array with all five attempted shots for each regular rack
*********************************************************************/ 


int single_rack(int shooting, int position) {

    int rack_score = 0;
    int *rack = new int [5];
    
    //simulates five shots
    for (int i = 0; i < 5; i++) {
    
        int attempt = shot(shooting);
        rack[i] = attempt;

        //money ball shot
        if (i == 4) {
            rack_score += attempt * 2;
        }

        else {
            rack_score += attempt;
        }
    
    }
    
    cout << "Rack " << position << " : ";
    letter_conversion(rack);
    cout << rack_score << " pts" << endl;

    delete [] rack;
    rack = NULL;

    return rack_score;

}


/*********************************************************************
** Function: int multiple_rack
** Description: simulates all five racks, including the money-ball rack, and prints out the total score for the player
** Parameters: int money and int shooting
** Pre-Conditions: inputed values are integers in the valid range
** Post-Conditions: prints out the total score of the game for each player
*********************************************************************/ 


int multiple_rack(int money, int shooting) {
    
    int total = 0;
    
    //simulates all five racks
    for (int i = 1; i < 6; i++) {
    
        //money ball rack
        if (i == money) {
            total += money_rack(shooting, i);
        }
    
        //regular racks
        else {
            total += single_rack(shooting, i);
        }
    
    }
    
    cout << endl << "Total: " << total << endl << endl<< endl;
    return total;

}


/*********************************************************************
** Function: void winner
** Description: determines the winner of the basketball game
** Parameters: int array[] and int players
** Pre-Conditions: the array has the same amount of values as the variable 'players' and all of the values are integers as well. 
** Post-Conditions: prints to the user who won the game or if it was a tie game
*********************************************************************/ 


void winner(int array[], int players) {

    int top_score = 0;
    int pos = 0;
    int tie = 0;

    //runs through every single player's scores
    for (int i = 1; i <= players; i++) {
        
        //finds the player with the highest score
        if (array[i] > top_score) {
            top_score = array[i];
            pos = i;
        }

        //in case two or more players have the same score
        else if (array[i] == top_score) {
            tie = array[i];
        }

    }
    
    if (top_score == tie) {
        cout << "Tie game!" << endl;
    }

    else {
        cout << "Player " << pos << " wins with " << top_score << " pts!" << endl;
    }

}


/*********************************************************************
** Function: void again
** Description: asks the user if they want to play again and prompts until a valid response
** Parameters: int &replay
** Pre-Conditions: inputted value is an integer
** Post-Conditions: takes a valid input for the replay variable and changes the original variable in the main function
*********************************************************************/ 


void again(int &replay) {

    cout << endl;

    //forces the player to answer with a 0 or 1
    do
    {
        cout << "Do you want to play again? 1-yes 0-no: ";
        cin >> replay; 

    } while (replay != 0 && replay != 1);
    
    cout << endl;

}


/*********************************************************************
** Function: int main
** Description: runs the whole program at least once and continues to until the user wants to quit. Calls on the functions that simulate the game twice, once for each player
** Parameters: none
** Pre-Conditions: all the functions are working correctly and inputted values are integers
** Post-Conditions: simulates the entire game and continues to run until told not to
*********************************************************************/ 


int main() {

    int rerun;
    
    do
    {
        //different seed each run which makes the random values completely random
        srand(time(NULL));

        //sets up number of players playing and the array that takes in all the total scores
        int playing = players();
        int *total_score = new int [playing];

        cout << endl << "Welcome to the basketball shooting contest!" << endl << endl;

        //sets up the game for N players
        for (int i = 1; i <= playing; i++) {
            
            int money_ball_rack = 0;
            int shooting_ability = 0;
            cout << "Player " << i << ": " << endl;
            
            //changes the variables and sets up them
            setup(money_ball_rack, shooting_ability);
            
            //simulates the entire game through this one function call
            int score = multiple_rack(money_ball_rack, shooting_ability);

            //adds all the player's score to an array to make comparison easier
            total_score[i] = score;

        }

        //figures out winner of the basketball game
        winner(total_score, playing);

        //asks if the user wants to play again
        again(rerun);
    
        delete [] total_score;
        total_score = NULL;

    } while (rerun == 1);

}