//main.cpp
/*
This program contains a class called "GTree", which gives the programmer an object to use, also called "GTree", which works as a regular Tree should.
A Tree is a kind of binary tree, made up of nodes. Each node points to two (2) other nodes, and each of those point to two (2) other nodes, etc.
The program first allows the user to enter up to 100 different number inputs, then it will create a GTree (like a Tree, except I made it) and sort the numbers such that each parent is bigger than their two children. The program can handle numbers from one (1) to one-thousand (1000).

The above description is nearly exactly copied over from my previous Tree project because this project does nearly exactly the same thing. 
This time, however, you are allowed to add, remove, and search for specific numbers throughout the Tree. Also, the medium for the inputs will now be Node structs (named GNode, of course) instead of an int array, sorted using some clever math

bool search(int, GTree*&) - Searches the GTree for the int that was passed in. Returns true if it is found.
void searchFunction(int, GTree*&) - Asks the user what number they want to search for, then 
void addFunction(GTree*&) - Directly asks the user for the character that they want to put into the tree. Then it sends that char to add to the actual add() function.
void removeFunction(GTree*&) - Directly asks the user for the character that they want to remvoe from the tree. Then it sends that char to add to the actual remove() function.
char* consoleFunction(bool&) - Gets the space-terminated string of numbers from the user through the console, then returns it.
char* fileFunction(bool&) - Gets the path of the file which contains the space-terminated string of numbers, then imports and returns that string.
char* getInput(char*, bool&, bool&, GTree*&);

@author Greggory Hickman, March 2020
@version 1.0
 */

#include <iostream>
#include <cstring>
#include <stdio.h>

#include "BattlePack.h"
#include "GTree.h"

#define LEN 100
#define BIGLEN 3000

using namespace std;

bool search(int, GTree*&);
void searchFunction(int, GTree*&);
void addFunction(GTree*&);
void removeFunction(GTree*&);
char* consoleFunction(bool&);
char* fileFunction(bool&);
char* getInput(char*, bool&, bool&, GTree*&);

int main() {
	//Define some variables and objects that we will need throughout the program
	bool quit = false;
	char* inputString; //Initializing as a pointer so that I'm not taking up memory yet
	GTree* tree = new GTree(LEN);
	
	//Greeting, and an introduction to what a max Tree is in case the user doesn't know
	cout << "Welcome to Gregg\'s fabulous Tree program!" << endl <<
	"This program is a kind of number sorter which sorts the numbers given to it in a max Tree formation." <<
	"That means that the highest number will be at the top, and every number branching off of that will be smaller, and so on.";
	
	//The loop that the majority of the program takes place in
	while (!quit) {
		
		bool haveInput = false;
		char cmdin[LEN];
		char* charList; //Once again initializing as a pointer so that I'm not taking up memory yet
		
		//This is the part that lets the user type a command
		while (!haveInput) {
			//List out all of the commands
			cout << 
			"Type \"add\" to add a single number" << endl <<
			"Type \"remove\" to remove a single number" << endl <<
			"Type \"console\" to add a list of numbers" << endl << 
			"Type \"file\" to read a list of numbers from a file" << endl << 
			"Type \"search\" to find out where a specific number resides within the Tree" << endl << 
			"Type \"exit\" to kill the program" << endl;
		
			cout << "> ";
			cin >> cmdin; cin.clear(); cin.ignore(LEN, '\n');
			
			charList = getInput(cmdin, quit, haveInput, tree); //Get the input from the user using a series of prompts
			//Quit if the quit command was run inside of getInput()
			if (quit) {
				return 0;
			}
		}
		
		//Parse the char* input into an int* with each number separated
		int* numStream = parseZTCString(charList, 32);
		
		//Print out the parsed input to show the user exactly what will be used in the Tree
		cout << "Input confirmed: ";
		for (int i = 0; numStream[i] != 0; i++) cout << numStream[i] << " "; //Print all int-ified inputs
		cout << endl << endl;
		
		//Ask to sort into a max Tree (in case somebody wants to expand this code in the future to do things other than just max Tree)
		cout << "Sorting into max Tree..." << endl;
		//GTree tree = maxTreeSort(numStream); //Sort numStream into max Tree
		cout << endl;
		
		//Print current Tree
		//printTree(&tree);
	}
	
	return 0;
}

//Return true if in is found
bool search(int in, GTree*& tree) {
	
}

//Search the tree for a value
void searchFunction(int in, GTree*& tree) {
	
}

//Add to Tree
void addFunction(GTree*& tree) {
	char cInput[LEN];
	int iInput;
	cout << "Add a number..." << endl <<
	"Type in the number to add." << endl;
	
	cin.getline(cInput, LEN);
	
	for (int i = 0; i < ; i++) {
		iInput = (int)(cInput[0]) + 48;
		cout << iInput << endl;
	}
}

void add(int in, GTree*& tree) {
	
}

//Remove from Tree
void removeFunction(GTree*& tree) {
	cout << "Remove a number..." << endl <<
	"Type in the number to remove." << endl;
}

//Read from console
char* consoleFunction(bool& haveInput) {
	
}

//Read from file
char* fileFunction(bool& haveInput) {
	
}

char* getInput(char* cmdin, bool& quit, bool& haveInput, GTree*& tree) {
	char* charList = new char[BIGLEN];
	
	//Add a single input, read in from console
	if (strcmp(cmdin, "add") == 0 || strcmp(cmdin, "a") == 0 || strcmp(cmdin, "A") == 0) {
		addFunction(tree);
	}
	//Read from console
	if (strcmp(cmdin, "console") == 0 || strcmp(cmdin, "c") == 0 || strcmp(cmdin, "C") == 0) {
		cout << "Reading from console..." << endl <<
		"Type in your numbers, each separated by a space." << endl;
		
		//Read in the input from console and put it into charList
		cout << "Console> ";
		cin.getline(charList, BIGLEN);

		//At this point, we have our input (charList). Now, let's confirm that it's what the user wants.
		cout << "Input: " << charList << endl;
		cout << "Confirm Input? (y/n)" << endl;
		cout << "> ";
		char confirm;
		cin >> confirm; cin.clear(); cin.ignore(LEN, '\n');
		
		if (confirm == 'y') {
			haveInput = true;
		}
	}
	//Read from file
	else if (strcmp(cmdin, "file") == 0 || strcmp(cmdin, "f") == 0 || strcmp(cmdin, "F") == 0) {
		char add[LEN];
		FILE* fin = NULL; //Credit to my dad from showing me the FILE libraries from ye olde C
		
		cout << "Reading from file..." << endl <<
		"Input the path to your file. It must be a text file:" << endl;
		
		//Get address
		cout << "File> ";
		cin.getline(add, LEN);
		
		//Get file from address
		fin = fopen(add, "r"); //"r" for read
		
		if (fin != NULL) {
			//Put the contents of the file into charList
			fgets(charList, BIGLEN, fin);
			
			//At this point, we have our input (charList). Now, let's confirm that it's what the user wants before we ship it back out to the main method
			cout << "Input: " << charList << endl;
			cout << "Confirm Input? (y/n)" << endl;
			cout << "> ";
			char confirm;
			cin >> confirm; cin.clear(); cin.ignore(LEN, '\n');
			
			if (confirm == 'y') {
				haveInput = true;
			}
		}
		else {
			cout << "There was an issue opening the file at \"" << add << "\". Please try again" << endl;
		}
		fclose(fin);
		
		delete(fin);
	}
	//Exit
	else if (strcmp(cmdin, "exit") == 0 || strcmp(cmdin, "e") == 0 || strcmp(cmdin, "E") == 0) {
		cout << "Closing program..." << endl;
		quit = true; //Set the bool pointer to true, which will trigger the program to end back in the main method
		return NULL;
	}
	//Invalid command
	else {
		cout << "Command \"" << cmdin << "\" not recognized" << endl;
	}
	cout << endl;
	
	//Return the complete input
	return charList;
}
