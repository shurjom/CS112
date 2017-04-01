/*
 * BST.cpp
 *
 *  Created on: Apr 18, 2016
 *      Author: adams
 */

#include "BST.h"

BST::BST() {
	myRootPtr = NULL;
	myCount = 0;
}

void BST::makeCopyOf(const BST& original) {
	myCount = original.myCount;
	if (original.myRootPtr == NULL) {
		myRootPtr = NULL;
	} else {
		myRootPtr = new Node(original.myRootPtr);
	}
}

BST::BST(const BST& original) {
	makeCopyOf(original);
}

// recursive Node constructor using
//  the preorder traversal pattern
BST::Node::Node(Node* oPtr) {
	if (oPtr) {
		myItem = oPtr->myItem;    // process item
		if (oPtr->myLeftPtr) {    // preorder left
			myLeftPtr = new Node(oPtr->myLeftPtr);
		} else {
			myLeftPtr = NULL;
		}
		if (oPtr->myRightPtr) {   // preorder right
			myRightPtr = new Node(oPtr->myRightPtr);
		} else {
			myRightPtr = NULL;
		}
	}
}

void BST::insert(const Item& item) {
	if (myCount == 0) {
		myRootPtr = new Node(item);
	} else {
		myRootPtr->nodeInsert(item);
	}
	myCount++;
}

void BST::Node::nodeInsert(const Item& item) {
	if (item < myItem) {
		if (myLeftPtr == NULL) {
			myLeftPtr = new Node(item);
		} else {
			myLeftPtr->nodeInsert(item);
		}
	} else if (item > myItem) {
		if (myRightPtr == NULL) {
			myRightPtr = new Node(item);
		} else {
			myRightPtr->nodeInsert(item);
		}
	} else {
		// throw exception
	}
}

BST& BST::operator=(const BST& rhs) {
	if (this != &rhs) {
		delete myRootPtr;
		makeCopyOf(rhs);
	}
	return *this;
}
