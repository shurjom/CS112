/*
 * Queue.cpp
 *
 *  Created on: Mar 30, 2016
 *      Author: adams
 */

#include "Queue.h"

Queue::Queue() {
	mySize = 0;
	myFirstPtr = myLastPtr = NULL;
}

Queue::Node::Node(const Item& item, Node * next) {
	myItem = item;
	myNext = next;
}

void Queue::makeCopyOf(const Queue& original) {
	mySize = 0;
	myFirstPtr = myLastPtr = NULL;
	Node* oPtr = original.myFirstPtr;
	while (oPtr) {
		append(oPtr->myItem);
		oPtr = oPtr->myNext;
	}
}

Queue::Queue(const Queue& original) {
	makeCopyOf(original);
}

void Queue::append(const Item& item) {
	if (isFull()) {
		throw overflow_error("Queue::append(): queue is full");
	}

	Node * nPtr = new Node(item, NULL);
	if ( isEmpty() ) {
		myFirstPtr = nPtr;
	} else {
		myLastPtr->myNext = nPtr;
	}
	myLastPtr = nPtr;
	mySize++;
}

Item Queue::remove() {
	if ( isEmpty() ) {
		throw underflow_error("Queue::remove(): queue is empty");
	}

	Item result = myFirstPtr->myItem;
	Node * nPtr = myFirstPtr;
	myFirstPtr = myFirstPtr->myNext;
	nPtr->myNext = NULL;
	delete nPtr;
	mySize--;
	if (mySize == 0) { myLastPtr = NULL; }
	return result;
}


Item Queue::getFirstItem() const {
	if ( isEmpty() ) {
		throw underflow_error("Queue::getFirstItem(): queue is empty");
	}

	return myFirstPtr->myItem;
}

Item Queue::getLastItem() const {
	if ( isEmpty() ) {
		throw underflow_error("Queue::getLastItem(): queue is empty");
	}

	return myLastPtr->myItem;
}

Queue& Queue::operator=(const Queue& rhs) {
	if (this != &rhs) {
		delete myFirstPtr;
		makeCopyOf(rhs);
	}
	return *this;
}
