Name: Gabriel de Leon
ONID: deleong@oregonstate.edu

Description: This program simulates an adventure game. The goal is to collect the hidden gold in the cave and get back to the escape rope alive.
There are numerous dangers in the cave that you can encounter and will be hinted at through percepts. You get to decide how big the cave is by 
inputting the sides of the cave and you can choose if you want to play the game knowing what is at each room or not. You can also input what you want 
to do such as moving a certain direction or shooting an arrow at a specific direciton. The other program calculates how many ways someone can get up a
certaion amount of stairs taking 1, 2, or 3 steps. The program will ask for a number input that represents the number of stairs and you can type in whatever number you want,
though keep in mind that the bigger numbers tend to take a longer time to calculate. 

Instructions: First, make sure you're in the right directory where my code is. To compile and run the wumpus game, cd to part1 and then type in either make or make leak_check. 
The first option will give you an executable named wumpus and you can run that with gdb/valgrind by typing gdb/valgrind wumpus. If you don't want to run with either just type in wumpus.
The second option will automatically run the executable with valgrind. The program will start off with asking how many sides you want the cave to have. It'll force you to input a number between 4-50,
but make sure you only enter an integer as the program will crash if a non-integer is entered. It will then ask you if you want to play in debug mode or not. For this one, it'll handle any answer but please answer
in all lowercase as it won't take "TrUe" for example. It'll only take "true" or "false". It'll then print out some information as well as the game_board and the * represents where you are. Type in what action you want to do
which would be one of the following: w a s d f. It'll only take lowercase, so the program won't allow these inputs: W A S D F. Continue to answer with w a s d f and have fun with the game. 
To compile and run the stairs calculator, cd part2 and then type in make. This will make an executable named stairs and you can then type in stairs to run the program. Please only type in integers and the larger numbers may take a very long time to calcualte (35+). 
Make clean will clear all the objects made in either programs

Limitations: For your inputs, make sure they are the same data types as what they're asking. For the wumpus game, input an integer for the sides, input debug reads strings so the words "false" and "true
need to be typed in all lowercase, the directions/action input only reads the first char of whatever you type and takes lowercase only. There is no way to undo your steps, once you press enter your choice is locked in. For the stairs, please only input integers and not too high of a number. 
Around 35 is when the program starts to take awhile to calculate and I have error handling for anything less than 1. 

6a. The game class has a room object that has a event object. The gold object, pool object, stalactites object, and wumpus object are a event object. A game object has a vector of rooms and each room has an event pointer (could be nullptr)
Event is the abstract class and Gold, Pool, Stalactites, Wumpus are all event classes that are children of the parent class event. 

6b. I made the print_symbol(), print_percepts(), and act() functions all pure virtual functions because every child class has a different symbol/percept/action so they all need to redefine these functions.
I didn't have any virtual functions as I didn't find the need to use a virtual function over the pure virtual functions for any of the three that I made pure virtual.

6c. I only implemented the destructor in classes with memory allocated such as Game and Room as I needed to deallocate the memory after the object got out of scope or else I'd have memory leaks. I didn't implement the other two as I
didn't find any need to copy the objects. I only needed the destructor to deallocate memory, the other two weren't needed.

6d. I thought about breaking down the problem into steps. First, I needed to find the base cases and I found those by thinking about the lowest values the stairs could be and if I needed to recursively solve those/ if there was a way to. 
After figuring out that <1, 1, 2, and 3 are all base cases, I hard coded the values of those four and then knew that the return value after these base cases had to be recursively calling the function. I realized that I could simlulate taking
each step by recursively calling the function three times. One would be n-1 to simulate one step, the second one would be n-2 to simulate two steps, and the third one would be n-3 to simulate the third step. If I added all these steps together
I would find the solution leading to the return statement recursively calling the function three times. 

6e. I found having no memory errors/leaks the hardest because those are the hardest to figure out what the problem is and how to fix it. I had the biggest issue with the Wumpus and when it moved after an arrow was shot as I forgot to delete
the old wumpus in the original room before moving the wumpus. I would add deletes wherever which led to me having a lot more frees than allocated forcing me to look back at my code to figure out where the frees were unneccesary. I used valgrind
and gdb to really help figure out where the errors were specifically leak_check=full as it would tell me how many frees/allocates I had and which lines were giving me the errors. If I were given a second chance, I would use ctrl F to figure out where
I allocate memory such as using the keyword "new" or accessing the event pointers in the rooms, as I spent too long trying to figure out what was wrong instead of just using ctrl F to know exactly where I needed to trace through with gdb. 