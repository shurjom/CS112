/*
 * Queue.h
 *
 *  Created on: Mar 30, 2016
 *      Author: adams
 */

#ifndef QUEUE_H_
#define QUEUE_H_

#include <stdexcept>  // underflow_error
using namespace std;

typedef double Item;

class Queue {
public:
	Queue();
	Queue(const Queue& original);
	~Queue() { delete myFirstPtr; }
	bool isEmpty() const { return mySize == 0; }
	bool isFull() const { return false; }
	void append(const Item& item);
	Item remove();
	Item getFirstItem() const;
	Item getLastItem() const;
	Queue& operator=(const Queue& rhs);
private:
	unsigned mySize;
	struct Node {
		Node(const Item& item, Node * next);
		~Node() { delete myNext; }
		Item myItem;
		Node* myNext;
	};
	Node* myFirstPtr;
	Node* myLastPtr;

	void makeCopyOf(const Queue& original);
};

#endif /* QUEUE_H_ */
