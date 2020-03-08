//GTree.cpp

#include "GTree.h"

//Constructor
GTree::GTree(int LENGTH) {
	this->LENGTH = LENGTH;
	heap = new int[LENGTH];
	
	//Set all initial values to be 0, which is my version of null for this project because real numbers can only be from 1 to 1000
	for (int i = 0; i < LENGTH; i++) {
		heap[i] = 0;
	}
	
	highest = 0;
}

GTree::~GTree() {
	delete(heap);
}

int GTree::getHighest() {
	return highest;
}

int GTree::getParent(int address) {
	if (address < LENGTH) {
		return heap[address];
	}
	return -1; //Return -1 if the program tries to access an address which isn't allocated in memory
}

int GTree::getChild1(int address) {
	if ((address + 1) * 2 - 1 < LENGTH) {
		return heap[(address + 1) * 2 - 1];
	}
	return -1; //Return -1 if the program tries to access an address which isn't allocated in memory
}
		
int GTree::getChild2(int address) {
	if ((address + 1) * 2 < LENGTH) {
		return heap[(address + 1) * 2];
	}
	return -1; //Return -1 if the program tries to access an address which isn't allocated in memory
}

bool GTree::isEmpty(int address) {
	if (heap[address] == 0) {
		return true;
	}
	else {
		return false;
	}
}

void GTree::setParent(int address, int value) {
	if (address < LENGTH) {
		//Set that value
		heap[address] = value;
		
		//Update highest if necesary
		if (address > highest) {
			highest = address;
		}
	}
}

void GTree::setChild1(int address, int value) {
	if ((address + 1) * 2 - 1 < LENGTH) {
		heap[(address + 1) * 2 - 1] = value;
		
		if ((address + 1) * 2 - 1 > highest) {
			highest = (address + 1) * 2 - 1;
		}
	}
}

void GTree::setChild2(int address, int value) {
	if ((address + 1) * 2 < LENGTH) {
		heap[(address + 1) * 2] = value;
		
		if ((address + 1) * 2 > highest) {
			highest = (address + 1) * 2;
		}
	}
}
