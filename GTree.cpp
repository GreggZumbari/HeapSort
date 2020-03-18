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


void GTree::resetCurrent() {
	current = head;
}

int GTree::get() {
	return current->token;
}

int GTree::getLeft() {
	return current->left->token;
}

int GTree::getRight() {
	return current->right->token;
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

void GTree::set(int value) {
	current->token = value;
}

void GTree::setLeft(int value) {
	GNode newNode;
	newNode.token = value;
	current->left = &newNode;
}

void GTree::setRight(int value) {
	GNode newNode;
	newNode.token = value;
	current->right = &newNode;
}

void GTree::moveLeft() {
	current = current->left;
}

void GTree::moveRight() {
	current = current->right;
}