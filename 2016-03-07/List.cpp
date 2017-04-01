/*
 * List.cpp
 *
 *  Created on: Mar 7, 2016
 *      Author: adams
 */

#include "List.h"

List::List() {
	mySize = 0;
	myFirstPtr = myLastPtr = NULL;
}

List::List(const vector<Item>& v) {
	myFirstPtr = myLastPtr = NULL;
	mySize = 0;
	for (unsigned i = 0; i < v.size(); i++) {
		append( v[i] );
	}
}

List::Node::Node(const Item& it, Node* next) {
	myItem = it;
	myNextPtr = next;
}

void List::makeCopyOf(const List& original) {
	mySize = 0;
	myFirstPtr = myLastPtr = NULL;
	Node* oPtr = original.myFirstPtr;
	while (oPtr) {
		append(oPtr->myItem);
		oPtr = oPtr->myNextPtr;
	}
}

List::List(const List& original) {
	makeCopyOf(original);
}

List::~List() {
	delete myFirstPtr;
//	Node * delPtr = myFirstPtr;
//	Node* nextPtr = NULL;
//	while (delPtr) {
////		cout << "\nDeleting the node containing "
////				<< delPtr->myItem << flush;
//		nextPtr = delPtr->myNextPtr;
//		delete delPtr;
//		delPtr = nextPtr;
//	}
}

void List::append(const Item& item) {
	Node * nPtr = new Node(item, NULL);
	if (mySize == 0) {
		myFirstPtr = nPtr;
	} else {
		myLastPtr->myNextPtr = nPtr;
	}
	mySize++;
	myLastPtr = nPtr;
}

void List::prepend(const Item& item) {
	Node * newNode = new Node(item, myFirstPtr);
	myFirstPtr = newNode;
	if ( mySize == 0 ) {
		myLastPtr = newNode;
	}
	mySize++;
}

List& List::operator=(const List& rhs) {
	if (this != &rhs) {
		delete myFirstPtr; // recursive chain reaction
		makeCopyOf(rhs);
	}
	return *this;
}
