//GTree.h
/*
This object is a tree of integers, starting with a single parent node. Each node branches off to two (2) other nodes, and could go on indefinetly (or at least while it hasn't run out of allocated memory).
By the way, when I say node, I'm not referring to a struct or anything like that. I'm referring to a single element in the tree, which as you can see, is an int array.
The algorithm for this int array, shown to me by Mr. Galbraith, is such that a parent's two children each reside at (parent's address * 2) and (parent's address * 2 + 1). For example, 4's children are at 8 and 9, and 9's children are at 18 and 19, etc. This works out so that nobody overrides anybody else, and it only uses a single array as storage.

void resetCurrent() - Resets the position of current back to the head.
int get() - Get the token of the current GNode.
int getLeft(int) - Returns the token of the current GNode's left child.
int getRight(int) - Returns the token of the current GNode's left child.
bool currentIsEmpty() - Return true if current is NULL (or undefined).
bool leftIsEmpty() - Returns true if the left child of current is NULL.
bool rightIsEmpty() - Returns true if the right child of current is NULL.
void set(int) - Set the token of the current GNode.
void setLeft(int) - Set the token of the left child. Shorthand for moveLeft() followed by set().
void setRight(int) - Set the token of the right child. Shorthand for moveRight() followed by set().
void moveLeft() - Move current to the left child.
void moveRight() - Move current to the right child.

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
		void resetCurrent();
		int get();
		int getLeft();
		int getRight();
		bool currentIsEmpty();
		bool leftIsEmpty();
		bool rightIsEmpty();
		void set(int);
		void setLeft(int);
		void setRight(int);
		void moveLeft();
		void moveRight();
		
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
	
		GNode* head; //The head of the tree
		GNode* marker; //A marker that the programmer can set anywhere in the tree for later reference.
		GNode* current; //The current GNode that the user is looking at.
};