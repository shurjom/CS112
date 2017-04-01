/*
 * Stack.h
 *
 *  Created on: Mar 23, 2016
 *      Author: adams
 */

#ifndef STACK_H_
#define STACK_H_

#include <iostream>
#include <stdexcept>  // underflow_error
using namespace std;

template<class Item>
class Stack {
public:
	Stack();
	Stack(const Stack<Item>& original);
	~Stack() { delete myTopPtr; }
	bool isEmpty() const { return myTopPtr == NULL; }
	bool isFull() const { return false; }
	void push(const Item& item);
	Item getTop() const;
	Item pop();
	Stack<Item>& operator=(const Stack<Item>& rhs);
private:
	struct Node {
		Node(const Item& item, Node* next);
		~Node() { //cout << "\ndeleting node containing " << myItem << endl;
		          delete myNext; }
		Item myItem;
		Node* myNext;
	};
	Node* myTopPtr;

	void makeCopyOf(const Stack& original);
};

template<class Item>
Stack<Item>::Stack() {
	myTopPtr = NULL;
}

template<class Item>
void Stack<Item>::makeCopyOf(const Stack<Item>& original) {
	Node* oPtr = original.myTopPtr;
	Node* nPtr = NULL;
	if (oPtr != NULL) {
		myTopPtr = new Node(oPtr->myItem, NULL);
		oPtr = oPtr->myNext;
		nPtr = myTopPtr;
	} else {
		myTopPtr = NULL;
	}
	while (oPtr) {
		nPtr->myNext = new Node(oPtr->myItem, NULL);
		oPtr = oPtr->myNext;
		nPtr = nPtr->myNext;
	}
}

template<class Item>
Stack<Item>::Stack(const Stack<Item>& original) {
	makeCopyOf(original);
}

template<class Item>
Stack<Item>::Node::Node(const Item& item, Node* next) {
	myItem = item;
	myNext = next;
}

template<class Item>
void Stack<Item>::push(const Item& item) {
	myTopPtr = new Node(item, myTopPtr);
}

template<class Item>
Item Stack<Item>::getTop() const {
	if ( isEmpty() ) {
			throw underflow_error("Stack::getTop(): stack is empty");
		}
	return myTopPtr->myItem;
}

template<class Item>
Item Stack<Item>::pop() {
	if ( isEmpty() ) {
		throw underflow_error("Stack::pop(): stack is empty");
	}

	Item result = myTopPtr->myItem;
	Node * tempPtr = myTopPtr;
	myTopPtr = myTopPtr->myNext;
	tempPtr->myNext = NULL;
	delete tempPtr;
	return result;
}

template<class Item>
Stack<Item>& Stack<Item>::operator=(const Stack<Item>& rhs) {
	if (this != &rhs) {
		delete myTopPtr;
		makeCopyOf(rhs);
	}
	return *this;
}


#endif /* STACK_H_ */
