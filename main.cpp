//main.cpp
/*
This program contains a class called "GTree", which gives the programmer an object to use, also called "GTree", which works as a regular Tree should.
A Tree is a kind of binary tree, made up of nodes. Each node points to two (2) other nodes, and each of those point to two (2) other nodes, etc.
The program first allows the user to enter up to 100 different number inputs, then it will create a GTree (like a Tree, except I made it) and sort the numbers such that each parent is bigger than their two children. The program can handle numbers from one (1) to one-thousand (1000).

The above description is nearly exactly copied over from my previous Tree project because this project does nearly exactly the same thing. 
This time, however, you are allowed to add, remove, and search for specific numbers throughout the Tree. Also, the medium for the inputs will now be Node structs (named GNode, of course) instead of an int array, sorted using some clever math

void insertToken(GTree& tree, int address, int newToken);
GTree maxTreeSort(int*);
void printTree(GTree*);
int* parseInput(char*);
char* getInput(bool&);

@author Greggory Hickman, March 2020
@version 1.0
 */

#include <iostream>
#include <cstring>
#include <stdio.h>
#include <math.h>

#include "BattlePack.h"
#include "GTree.h"

using namespace std;

void insertToken(GTree& tree, int address, int newToken);
GTree maxTreeSort(int*);
void printTree(GTree*);
int* parseInput(char*);
char* getInput(bool&);

int main() {
	
	//Define some variables and objects that we will need throughout the program
	bool quit = false;
	char* inputString;
	
	//Greetingd, and an introduction to what a tree is in case the user doesn't know
	cout << "Welcome to Gregg\'s fabulous Tree program!" << endl <<
	"This program is a kind of number sorter which sorts the numbers given to it in a tree formation." <<
	"Each number will always have a lower number branching off to the left, and a higher number branching off to the right." << endl;
	
	//The loop that the majority of the program takes place in
	while (!quit) {
		inputString = getInput(quit); //Get the input from the user using a series of prompts
		//Quit if the quit command was run inside of getInput()
		if (quit) {
			return 0;
		}
		
		//Parse the char* input into an int* with each number separated
		int* numStream = parseInput(inputString);
		
		//Print out the parsed input to show the user exactly what will be used in the tree
		cout << "Input confirmed: ";
		for (int i = 0; numStream[i] != 0; i++) cout << numStream[i] << " "; //Print all int-ified inputs
		cout << endl << endl;
		
		//Ask to sort into a max tree (in case somebody wants to expand this code in the future to do things other than just max tree)
		cout << "Sorting into max tree..." << endl;
		GTree tree = maxTreeSort(numStream); //Sort numStream into max tree
		cout << endl;
		
		//Print current tree
		printTree(&tree);
	}
	
	return 0;
}

void insertToken(GTree* tree, int address, int newToken) {
	//cout << "New Token: " << newToken << ", ";
	//printTree(tree);
	
	//Replace the current token at address with input[i]
	int oldToken = tree->get(address);
	tree->set(address, newToken);
	
	//Start the cycle again if necesary
	//If the old token wasn't 0 (this is here because without it, the zeroes all the way down the chain would compare themselves to each other needlessly, which would be super-mega inefficient)
	if (oldToken != 0) {
		//If either child doesn't exist yet, set the oldToken as the new child
		if (tree->getChild1(address) == 0) {
			tree->setChild1(address, oldToken);
			return;
		}
		if (tree->getChild2(address) == 0) {
			tree->setChild2(address, oldToken);
			return;
		}
		
		//Otherwise, start the cycle again
		insertToken(tree, (address + 1) * 2 - 1, oldToken);
	}
}

GTree maxTreeSort(int* input) {
	
	GTree tree(BIGLEN);
	//For future reference, the "boss parent" is the very first node; the one which all others lead back to
	//
	//For every token in input...
	for (int i = 0; input[i] != 0; i++) { //i is iterator for input
		for (int j = 0; j < LEN; j++) { //j is iterator for tree
			//... and go through the tree from left to right until a token of lower magnitude than the current number from input is found.
			//At which point replace the new token with the old, then recursively sort down the tree from that point.
			if (input[i] >= tree.get(j)) {
				//Sort the new token and all of its children
				insertToken(&tree, j, input[i]);
				break;
			}
		}
	}
	
	return tree;
}

void printTree(GTree* tree) {
	//A semi-okay method for displaying the tree
	/*
	cout << "&tree in printTree" << tree.tree << endl;
	bool odd = false;
	for (int i = 0; i < LEN; i++) {
		char child;
		if (odd == true)
			child = 'a';
		else
			child = 'b';
		
		cout << "After New C1: " << tree.tree[i] << endl << endl;
		if (i == 0) {
			cout << "Master parent: " << tree.getParent(i) << endl;
		}
		else {
			cout << "Pair " << (i + 3) / 2 << child << ": " << tree.getParent(i) << endl;
		}
		odd = !odd;
		
		cout << "After New C2: " << tree.tree[i] << endl << endl;
	}
	*/
	
	//A much better method for displaying the tree
	int limit = -1;
	int generation = 0;
	bool even = true;
	cout << "Note: Numbers that come from the same parent are held together by parentheses, e.g. (4 2)." << endl;
	
	cout << "Tree Tree: ";
	//An algorithm for separating the generations properly
	for (int i = 0; i < BIGLEN; i++) {
		//If there are no more tokens, then just stop printing empty slots
		if (i > tree->getHighest()) {
			break;
		}
		//If generation is over, start a new line
		//i >= (limit * 2 - 1) works out to always be true on the very first loop because limit starts out as a negative number, as well as on every cycle at any positive integer x for 2^x amount of iterations after that (e.x. is true at iteration 1, 2, 4, 8, 16, 32, 64, etc.)
		if (i >= limit * 2 - 1) {
			cout << endl;
			cout << "Generation " << ++generation << ": "; //Announce the new generation
			limit = i + 1;
		}
		/*
		Everything after this point only exists to make the tree UI readable
		*/
		//If the token is not empty, print it to console.
		if (!tree->isEmpty(i)) {
			//If the token address is odd or if it is the master parent, put an open parenthesis before it
			if (!even || generation == 1) {
				cout << "(";
			}
			
			cout << tree->get(i);
			
			//If the token address is even, put a close parenthesis after it, and indent the next set
			//Or if the token address is odd but the token has no sibbling, put a close parenthesis after it as well
			if (even || tree->isEmpty(i + 1)) { 
				cout << ")";
			}
		}
		//If the token is empty, but the generation is not over (so that any gaps in between child groups don't cause parent-child mix up visually)
		else {
			cout << "()";
		}
		
		cout << " ";
		even = !even; //Reverse polarity of even
	}
	cout << endl << endl;
	
}

int* parseInput(char* inputString) {
	char* current = new char[LEN];
	int* numStream = new int[LEN];
	
	//Clear pesky leftover ram from pointer arrays
	
	clearCString(current, LEN);
	for (int i = 0; i < LEN; i++) {
		numStream[i] = 0;
	}
	
	//cout << "Starting inputString: " << inputString << endl;
	//cout << "Starting current: " << current << endl;
	
	//Parse the input
	int j = 0; //Iterator for current
	int k = 0; //Iterator for numStream
	for (int i = 0; i < BIGLEN + 1; i++) {
		//If we have hit the 100 number max limit
		if (k >= LEN - 1) {
			break;
		}
		//If is number
		if (inputString[i] >= 48 && inputString[i] <= 57) {
			//Add the digit to the end of the current multi-digit number
			current[j] = inputString[i];
			j++;
		}
		//If is space
		else if (inputString[i] == 32) {
			if (j != 0) {
				//cout << "Space: " << current << endl;
				//current contains the number that we want to convert to an integer
				int next = 0;
				
				//Iterate backwards through current
				for (int l = j - 1; l >= 0; l--) {
					//Convert the char* to int one unit place at a time by adding each value * 10^place. For example, when in the hundred's place, place = 2.
					next += (current[l] - 48) * round(pow(10, j - l - 1));
				}
				//cout << "Next: " << next << endl;
				numStream[k] = next;
				j = 0;
				k++;
				
				clearCString(current, LEN);
			}
		}
		//If is null
		else if (inputString[i] == 0) {
			if (j != 0) {
				//cout << "Null: " << current << endl;
				//current contains the number that we want to convert to an integer
				int next = 0;
				
				//Iterate backwards through current
				for (int l = j - 1; l >= 0; l--) {
					//Convert the char* to int one unit place at a time by adding each value * 10^place. For example, when in the hundred's place, place = 2.
					next += (current[l] - 48) * round(pow(10, j - l - 1));
				}
				numStream[k] = next;
				break;
			}
		}
	}
	delete(current);
	
	return numStream;
}

char* getInput(bool& quit) {
	
	bool haveInput = false;
	char cmdin[LEN];
	char* inputString = new char[BIGLEN];
	
	//Stay in this section until we have the input
	while (!haveInput) {
		//Clear both of our big boy cstrings
		clearCString(inputString, BIGLEN);
	
		//Ask how the user wants to input the numbers
		cout << "Type \"console\" to type your numbers straight into the console " << endl << 
		"Type \"file\" to read from file " << endl << 
		"Type \"exit\" to kill the program" << endl;
	
		cout << "> ";
		cin >> cmdin; cin.clear(); cin.ignore(LEN, '\n');
		
		cout << endl;
		//Read from console
		if (strcmp(cmdin, "console") == 0 || strcmp(cmdin, "c") == 0 || strcmp(cmdin, "C") == 0) {
			cout << "Reading from console..." << endl <<
			"Input your number inputs, each separated by a space" << endl;
			
			//Read in the input from console and put it into inputString
			cout << "Console> ";
			cin.getline(inputString, BIGLEN);
	
			//At this point, we have our input (inputString). Now, let's confirm that it's what the user wants.
			cout << "Input: " << inputString << endl;
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
				//Put the contents of the file into inputString
				fgets(inputString, BIGLEN, fin);
				
				//At this point, we have our input (inputString). Now, let's confirm that it's what the user wants before we ship it back out to the main method
				cout << "Input: " << inputString << endl;
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
	return inputString;
}