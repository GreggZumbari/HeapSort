//main.cpp
/*
This program contains a class called "GTree", which gives the programmer an object to use, also called "GTree", which works as a regular heap should.
A Heap is a kind of binary tree, made up of nodes. Each node points to two (2) other nodes, and each of those point to two (2) other nodes, etc.
The program first allows the user to enter up to 100 different number inputs, then it will create a GTree (like a heap, except I made it) and sort the numbers such that each parent is bigger than their two children. The program can handle numbers from one (1) to one-thousand (1000).

The above description is nearly exactly copied over from my previous heap project because this project does nearly exactly the same thing. 
This time, however, you are allowed to add, remove, and search for specific numbers throughout the Heap. Also, the medium for the inputs will now be Node structs (named GNode, of course) instead of an int array, sorted using some clever math

void insertToken(GTree& heap, int address, int newToken) - A recursive method which takes an address of a GTree and a new token which must be sorted into it correctly to create a correct max heap. It also calls in the pointer to the GTree in question. This method should only be used within the maxHeapSort method.
GTree maxHeapSort(int*) - Input an array on ints and put them into a heap, sorted such that the heap is a max heap.
void printHeap(GTree) - Print out the passed in heap in a visual manner
void add(int) - Add a number to the heap

@author Greggory Hickman, March 2020
@version 1.0
 */

#include <iostream>
#include <cstring>

#include "BattlePack.h"

void add(int);

int main() {
	int main() {
	
	//Define some variables and objects that we will need throughout the program
	bool quit = false;
	
	char* inputString; //Initializing as a pointer so that I'm not taking up memory yet
	
	//Greeting, and an introduction to what a max heap is in case the user doesn't know
	cout << "Welcome to Gregg\'s fabulous heap program!" << endl <<
	"This program is a kind of number sorter which sorts the numbers given to it in a max heap formation." <<
	"That means that the highest number will be at the top, and every number branching off of that will be smaller, and so on.";
	
	//The loop that the majority of the program takes place in
	while (!quit) {
		
		bool haveInput = false;
		char cmdin[LEN];
		
		//This is the part that lets the user type a command
		while (!haveInput) {
			
			//List out all of the commands
			cout << 
			"Type \"add\" to add a single number"
			"Type \"remove\" to remove a single number"
			"Type \"console\" to add a list of numbers" << endl << 
			"Type \"file\" to read a list of numbers from a file" << endl << 
			"Type \"search\" to find out where a specific number resides within the heap" << endl << 
			"Type \"exit\" to kill the program" << endl;
		
			cout << "> ";
			cin >> cmdin; cin.clear(); cin.ignore(LEN, '\n');
			
			cout << endl;
			
			if (strcmp(cmdin, "console") == 0 || strcmp(cmdin, "c") == 0 || strcmp(cmdin, "C") == 0) {
		}
		numList = getInput(quit); //Get the input from the user using a series of prompts
		//Quit if the quit command was run inside of getInput()
		if (quit) {
			return 0;
		}
		
		//Parse the char* input into an int* with each number separated
		int* numStream = parseInput(numList);
		
		//Print out the parsed input to show the user exactly what will be used in the heap
		cout << "Input confirmed: ";
		for (int i = 0; numStream[i] != 0; i++) cout << numStream[i] << " "; //Print all int-ified inputs
		cout << endl << endl;
		
		//Ask to sort into a max heap (in case somebody wants to expand this code in the future to do things other than just max heap)
		cout << "Sorting into max heap..." << endl;
		GTree heap = maxHeapSort(numStream); //Sort numStream into max heap
		cout << endl;
		
		//Print current heap
		printHeap(&heap);
	}
	
	return 0;
}

void add(int input) {
	//Add to heap
}

char* getInput(bool& quit) {
	char* numList = new char[BIGLEN];
	
	//Add a single input, read in from console
	if (strcmp(cmdin, "add") == 0 || strcmp(cmdin, "a") == 0 || strcmp(cmdin, "A") == 0) {
		cout << "Reading from console..." << endl <<
		"Type in your number." << endl;
	}
	//Read from console
	if (strcmp(cmdin, "console") == 0 || strcmp(cmdin, "c") == 0 || strcmp(cmdin, "C") == 0) {
		cout << "Reading from console..." << endl <<
		"Type in your numbers, each separated by a space." << endl;
		
		//Read in the input from console and put it into numList
		cout << "Console> ";
		cin.getline(numList, BIGLEN);

		//At this point, we have our input (numList). Now, let's confirm that it's what the user wants.
		cout << "Input: " << numList << endl;
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
			//Put the contents of the file into numList
			fgets(numList, BIGLEN, fin);
			
			//At this point, we have our input (numList). Now, let's confirm that it's what the user wants before we ship it back out to the main method
			cout << "Input: " << numList << endl;
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
}
	
	//Return the complete input
	return numList;
}