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

bool GTree::headIsEmpty() {
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
	
	cout << "Tree: " << endl << "---" << endl;
	//Make sure that there is something in the tree before we go and print it
	if (!headIsEmpty()) {
		//Check both children of the head
		cout << "Generation 1: " << head->token << endl;
		checkChildren(head, generation);
	}
	else {
		cout << "EMPTY" << endl;
	}
	cout << "---" << endl << endl;
}

//Private function
void GTree::checkChildren(GNode*& node, int generation) {
	
	//If the left child isn't NULL, check both of their children
	if (node->left != NULL) {
		//Print out the next node's token now so that we can specify which direction that it is in relation to the current node
		cout << "Generation " << ++generation << " (Left): " << node->left->token << endl;
		
		//Check the children of the left node
		checkChildren(node->left, generation); //Check the next generation
		generation--;
	}
	//If the right child isn't NULL, check both of their children
	if (node->right != NULL) {
		//Print out the next node's token now so that we can specify which direction that it is in relation to the current node
		cout << "Generation " << ++generation << " (Right): " << node->right->token << endl;
		
		//Check the children of the right node
		checkChildren(node->right, generation);
		generation--;
	}
}

int GTree::numberCount(int value) {
	count = 0;
	//Check both children of the head
	searchChildren(head, value);
	return count;
}	

//Private function
void GTree::searchChildren(GNode*& node, int number) {
	//If the current token is the number that we're searching for
	if (node->token == number) {
		//Increment the counter
		count++;
	}
	//If the left child isn't NULL, check both of their children
	if (node->left != NULL) {
		//Check the children of the left node
		searchChildren(node->left, number); //Check the next generation
	}
	//If the right child isn't NULL, check both of their children
	if (node->right != NULL) {
		//Check the children of the right node
		searchChildren(node->right, number);
	}
}

void GTree::removeNumber(int value) {
	deleteChildren(head, value);
	return;
}

//Private function
void GTree::deleteChildren(GNode*& node, int numberToRemove) {
	//If one of the children's tokens is the number that we want to remove
	if (node->left->token == numberToRemove) {
		
	}
	if (node->right->token == numberToRemove) {
		
	}
	//If the left child isn't NULL, check both of their children
	if (node->left != NULL) {
		//Check the children of the left node
		searchChildren(node->left, numberToRemove); //Check the next generation
	}
	//If the right child isn't NULL, check both of their children
	if (node->right != NULL) {
		//Check the children of the right node
		searchChildren(node->right, numberToRemove);
	}
}

void GTree::removeNode(GNode*& node) {
	
}