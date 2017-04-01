/* List.h contains the class declarations and methods
 * Student Name:Shurjo Maitra
 * Date:3.8.16
 * Joel Adams, for CS 112 at Calvin College.
 */

#include <iostream>
#include <stdexcept>
#include <fstream>
#include <cassert>
#include <cstdlib>

using namespace std;
typedef double Item;

class List {
public:
	List();
	int getSize() const;
	Item getFirst() const;
	Item getLast() const;
	void append (const Item& it);
	virtual ~List();
	List(const List& original);
	List& operator=(const List& original);
private:
	struct Node {
		int myItem;
		Node* myNext;
		Node();
		Node(int it, Node* next);
		virtual ~Node();
	};
	int mySize;
	Node* myFirst;
	Node* myLast;
	friend class ListTester;
};

/*Default constructor method creates a List
 * Return: empty list with size = 0
 */
List::List() {
	mySize = 0;
	myFirst = NULL;
	myLast = NULL;
}

/*Node Default constructor method creates a List
 * Return: empty list with size = 0 with linked nodes
 */
List::Node::Node() {
	myItem = 0;
	myNext = NULL;
}
/*Node Explicit constructor method creates a List
 * Return: empty list with size = 0 with linked nodes explicitly
 */
List::Node::Node(int it, Node* next) {
	myItem = it;
	myNext = next;
}

/*getSize constructor for list class
 * Return: size of list
 */
int List::getSize() const {
	return mySize;
}

/*getFirst constructor for list class
 * Return: gets the first value in the list and returns it into myItem
 */
Item List::getFirst() const {
	if (mySize < 0 || myFirst == NULL) {
		throw underflow_error("Size of List is too small");
	}
	else {
		return myFirst -> myItem;
	}
}
/*getLast constructor for list class
 * Return: gets the last value in the list and returns it into myItem
 */
Item List::getLast() const {
	if (mySize < 0 || myLast == NULL) {
		throw underflow_error("Size of List can't be negative");
	}
	else {
		return myLast -> myItem;
	}
}

/*Append operator for list class
 * Param: nodePtr
 * Return: list with item added at the end
 */
void List::append(const Item& it) {
	Node * nodePtr = new Node(it, NULL);
	if (mySize == 0) {
		myFirst = nodePtr;
	}
	else {
		myLast -> myNext = nodePtr;
	}
	myLast = nodePtr;
	mySize ++;
}

/*Destructor for list class
 * Return: empty list
 */
List::~List() {
   delete myFirst;          // delete first node, invoking ~Node() (does nothing if myFirst == NULL)
   myFirst = myLast = NULL; // clear myFirst and myLast (optional)
   mySize = 0;              // clear mySize (optional)
}

/*Node destructor for list class
 * Return: empty node
 */
List::Node::~Node() {
   delete myNext;  // delete the next node, invoking ~Node() in it
                   // (does nothing if myNext == NULL)
   myNext = NULL;  // clear myNext (optional)
   myItem = 0;     // clear myItem (optional)
}

/*Copy constructor for list class
 * Return: list copied and stored in nodes
 */
List::List(const List& original) {
   myFirst = myLast = NULL;          //  set pointers
   mySize = 0;                       //   and size to 'empty' values
   if (original.getSize() > 0) {     //  if there are nodes to copy:
      Node* oPtr = original.myFirst; //  start at the first node
      while (oPtr != NULL) {         //  while there are more nodes:
         append(oPtr->myItem);       //   append the item in that node
         oPtr = oPtr->myNext;        //   advance to next node
      }
   }
}

/* Assignment operator for list class
 * checks if list is equal to another list
 * Param: list pointers
 */
List& List::operator = (const List& original) {
	if (this != &original) {
		delete myFirst;
		myFirst = myLast = NULL;
		mySize = 0;
		if (original.getSize() > 0) {
			Node* oPtr = original.myFirst;
			while (oPtr != NULL) {
				append(oPtr -> myItem);
				oPtr = oPtr -> myNext;
			}
		}
	}
	return *this;
}

