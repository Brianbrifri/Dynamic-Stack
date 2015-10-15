#include<iostream>
#include "DynamicStack.h"

using namespace std;


//Destructor
DynamicStack::~DynamicStack() {
	StackNode *nodePtr, *nextNode;

	nodePtr = top;

	while (nodePtr != NULL) {
		nextNode = nodePtr->next;
		delete nodePtr;
		nodePtr = nextNode;
	}
}

//Member functions
void DynamicStack::push(double num) {
	StackNode *newNode;

	newNode = new StackNode;
	newNode->value = num;
	
	if(isEmpty()) {
		top = newNode;
		newNode->next = NULL;
	}

	else {
		newNode->next = top;
		top = newNode;
	}
}

void DynamicStack::pop(double &num) {
	
	StackNode *temp;
	
	if(isEmpty()) {
		cout << "The stack is empty." << endl;
	}
	
	else {
		num = top->value;
		temp = top->next;
		delete top;
		top = temp;
	}
}	

bool DynamicStack::isEmpty() const {

	bool status;

	if(!top) {
		status = true;
	}

	else {
		status = false;
	}

	return status;
}
