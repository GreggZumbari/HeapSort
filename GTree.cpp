//GTree.cpp

#include "GTree.h"

//Constructor
GTree::GTree() {
	head = new GNode();
	current = head;
}

GTree::~GTree() {
	delete(head);
}

int GTree::getCurrent() {
	return current->token;
}

int GTree::getLeft() {
	return current->left->token;
}

int GTree::getRight() {
	return current->right->token;
}

bool GTree::currentIsEmpty() {
	//If the current token is -1, that means that it hasn't been assigned a value yet, and is thus considered null
	//If current is just straight up NULL then yeah, it's gonna be considered null.
	if (current == NULL || current->token == -1) 
		return true;
	else 
		return false;
}

bool GTree::leftIsEmpty() {
	//If the current token is -1, that means that it hasn't been assigned a value yet, and is thus considered null
	//If current is just straight up NULL then yeah, it's gonna be considered null.
	if (current->left == NULL || current->left->token == -1) 
		return true;
	else 
		return false;
}

bool GTree::rightIsEmpty() {
	//If the current token is -1, that means that it hasn't been assigned a value yet, and is thus considered null
	//If current is just straight up NULL then yeah, it's gonna be considered null.
	if (current->right == NULL || current->right->token == -1) 
		return true;
	else 
		return false;
}

void GTree::setHead(int value) {
	// Bug: Cannot redefine the thing that current is pointing to, can only starting pointing at something else.
	head->token = value;
}

void GTree::setLeft(int value) {
	GNode* newNode = new GNode();
	newNode->token = value;
	current->left = newNode;
}

void GTree::setRight(int value) {
	GNode* newNode = new GNode();
	newNode->token = value;
	current->right = newNode;
}

void GTree::moveLeft() {
	current = current->left;
}

void GTree::moveRight() {
	current = current->right;
}

void GTree::resetCurrent() {
	current = head;
}

void GTree::printTree() {
	//Print the tree
	/*
	cout << "Control Print: " << endl;
	cout << "Generation 1: " << head->token << endl;
	if (current->left != NULL) {
		cout << "Generation 2: " << getLeft();
	}
	if (current->right != NULL) {
		cout << ", " << getRight() << endl;
	}
	else {
		cout << endl;
	}
	*/
	//Starting out at the first generation
	int generation = 1;
	
	cout << "Real Print: " << endl;
	//Check both children of the head
	checkChildren(head, generation);
}

void GTree::checkChildren(GNode*& node, int generation) {
	
	//Print out the current token after both children have been completely dealt with
	cout << "Generation " << generation << ": " << node->token << endl;
	
	//If the left child isn't NULL, check both of their children
	if (node->left != NULL) {
		//cout << "Left" << endl;
		checkChildren(node->left, ++generation); //Check the next generation
		generation--;
	}
	//If the right child isn't NULL, check both of their children
	if (node->right != NULL) {
		//cout << "Right" << endl;
		checkChildren(node->right, ++generation);
		generation--;
	}
}