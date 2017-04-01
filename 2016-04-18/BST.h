/*
 * BST.h
 *
 *  Created on: Apr 18, 2016
 *      Author: adams
 */

#ifndef BST_H_
#define BST_H_

#include <iostream>
using namespace std;

typedef double Item;

class BST {
public:
	BST();
	BST(const BST& original);
	virtual ~BST() { delete myRootPtr; }
	unsigned getNumItems() const { return myCount; }
	void insert(const Item& item);
	BST& operator=(const BST& rhs);

private:
	struct Node {
		Item   myItem;
		Node * myLeftPtr;
		Node * myRightPtr;

		Node() { myItem = Item(); myLeftPtr = myRightPtr = NULL; }
		Node(const Item& item) { myItem = item; myLeftPtr = myRightPtr = NULL; }
		Node(Node* oPtr);
		~Node() { delete myLeftPtr; delete myRightPtr; }
		void nodeInsert(const Item& item);
	};

	Node *   myRootPtr;
	unsigned myCount;

	void makeCopyOf(const BST& original);

	friend class BST_Tester;
};

#endif /* BST_H_ */
