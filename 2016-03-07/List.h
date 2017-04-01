/*
 * List.h
 *
 *  Created on: Mar 7, 2016
 *      Author: adams
 */

#ifndef LIST_H_
#define LIST_H_

#include <iostream>
#include <vector>
using namespace std;

typedef double Item;

class List {
public:
	List();
	List(const vector<Item>& v);
	List(const List& original);
	virtual ~List();

	unsigned getSize() const { return mySize; }
	void append(const Item& item);
	void prepend(const Item& item);
	List& operator=(const List& rhs);
private:
	struct Node {
		Node(const Item& it, Node* next);
		~Node() { // cout << "\nreclaiming node containing " << myItem << flush;
		    		delete myNextPtr; }
		Item   myItem;
		Node * myNextPtr;
	};
	unsigned mySize;
	Node *   myFirstPtr;
	Node *   myLastPtr;

	void makeCopyOf(const List& original);

	friend class ListTester;
};

#endif /* LIST_H_ */
