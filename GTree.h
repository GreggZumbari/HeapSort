//GTree.h
/*
This object is a tree of integers, starting with a single parent node. Each node branches off to two (2) other nodes, and could go on indefinetly (or at least while it hasn't run out of allocated memory).
By the way, when I say node, I'm not referring to a struct or anything like that. I'm referring to a single element in the tree, which as you can see, is an int array.
The algorithm for this int array, shown to me by Mr. Galbraith, is such that a parent's two children each reside at (parent's address * 2) and (parent's address * 2 + 1). For example, 4's children are at 8 and 9, and 9's children are at 18 and 19, etc. This works out so that nobody overrides anybody else, and it only uses a single array as storage.

int getCurrent() - Get the token of the current GNode.
int getLeft(int) - Returns the token of the current GNode's left child.
int getRight(int) - Returns the token of the current GNode's left child.
bool headIsEmpty() - Return true if head is undefined.
bool leftIsEmpty() - Returns true if the left child of current is NULL.
bool rightIsEmpty() - Returns true if the right child of current is NULL.
void setHead(int) - Set the token of the head.
void setLeft(int) - Set the token of the left child. Shorthand for moveLeft() followed by set().
void setRight(int) - Set the token of the right child. Shorthand for moveRight() followed by set().
void moveLeft() - Move current to the left child.
void moveRight() - Move current to the right child.
void resetCurrent() - Resets the position of current back to the head.
void printTree() - Print out the whole tree to console in a visual format. It does so by checking the first node's children, and then by checking each of their children, and then by checking each of their children, etc. until you have reached the very bottom of the list, in which case instead of checking the new non-existant children, it will go on to print out the last node's token, and then it will recursively work its way backwards through each recursive function, printing out each parent as it goes, until it gets back to the very top, at which point it will simply print the head.

@author Greggory Hickman, February 2020
@version 1.0
 */
 
#include <iostream>

using namespace std;

class GTree {
	public:
		//Constructor & Destructor
		GTree();
		~GTree();
		
		//Functions
		int getCurrent();
		int getLeft();
		int getRight();
		bool headIsEmpty();
		bool leftIsEmpty();
		bool rightIsEmpty();
		void setHead(int);
		void setLeft(int);
		void setRight(int);
		void moveLeft();
		void moveRight();
		void resetCurrent();
		void printTree();
		
	private:
		struct GNode {
			int token;
			GNode* left;
			GNode* right;
			
			GNode() {
				token = -1;
				left = NULL;
				right = NULL;
			}
		};
		
		//Private function meant to be used recursively
		//Call this function for any existing children of the inputted GNode, then print out the inputted GNode's token.
		void checkChildren(GNode*&, int);
	
		//Class variables
		GNode* head; //The head of the tree
		GNode* marker; //A marker that the programmer can set anywhere in the tree for later reference.
		GNode* current; //The current GNode that the user is looking at.
};