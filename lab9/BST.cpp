/* BST.cpp defines binary search tree methods.
 * Joel Adams, for CS 112 at Calvin College.
 * Student name: Shurjo Maitra
 * Date: 4.19.16
 */

#include "BST.h"

BST::BST(){
	myNumItems = 0;
	myRoot = NULL;
}

BST::~BST() {
	delete myRoot;
	myRoot = NULL;
	myNumItems = 0;
}

BST::Node::Node(const Item& it) {
	myItem = it;
	myLeft = NULL;
	myRight = NULL;
}

BST::Node::~Node() {
	delete myLeft;
	delete myRight;
}

bool BST::isEmpty() const {
	return myNumItems == 0;
}

unsigned BST::getNumItems() const {
	return myNumItems;
}


void BST::traverseInorder() {
	if ( !isEmpty() ) {
		myRoot->traverseInorder();
	}
}

void BST::Node::traverseInorder() {
	if (myLeft != NULL) {
		myLeft->traverseInorder();
	}
	processItem();
	if (myRight != NULL) {
		myRight->traverseInorder();
	}
}


void BST::traversePreorder() {
	if ( !isEmpty() ) {
		myRoot->traversePreorder();
	}
}

void BST::Node::traversePreorder() {
	processItem();
	if (myLeft != NULL) {
		myLeft->traversePreorder();
	}
	if (myRight != NULL) {
		myRight->traversePreorder();
	}
}

void BST::Node::processItem() {
	cout << ' ' << myItem;
}

void BST::traversePostorder() {
	if ( !isEmpty() ) {
		myRoot->traversePostorder();
	}
}

void BST::Node::traversePostorder() {
	if (myLeft != NULL) {
		myLeft->traversePostorder();
	}
	if (myRight != NULL) {
		myRight->traversePostorder();
	}
	processItem();
}
/*Insert Item method
@param: item
*/
void BST::insert(const Item& it) {
	Node * nNode = new Node(it);
	if (isEmpty()) {
		myRoot = nNode;
	} else if (myRoot != NULL) {
		try {
			myRoot->insert(it);
		} catch (Exception& e) {
			throw(e);
		}
	}
	myNumItems++;
}
/*Insert Item method for Node
 * @param: Item
 * Postcondition: nodes sorted left and right
 * 				  in terms of size compared to preceding node
 */
void BST::Node::insert(const Item& it) {
	Node * nNode = new Node(it);
	if ((nNode->myItem) < myItem) {
		if (myLeft == NULL) {
			myLeft = nNode;
		}
		else {
			myLeft->insert(it);
		}
	}
	else if ((nNode->myItem) > myItem) {
		if (myRight == NULL) {
			myRight = nNode;
		}
		else {
			myRight->insert(it);
		}
	}
	else if ((nNode->myItem ) == myItem) {
		throw Exception("Line 77:", "Item already in BST!");
	}
}
/*Contains method
 * @param: Item
 */
bool BST::contains(const Item& it) const {
	if (isEmpty()) {
		return false;
	}
	myRoot->contains(it);
}

/*Contains method for Node
 * @param: Item
 * Postcondition: bool for if the values is contained
 */
bool BST::Node::contains(const Item& it) const {
	if (it < myItem) {
		if (myLeft == NULL) {
			return false;
		}
		return myLeft->contains(it);
	}
	else if (it > myItem) {
		if (myRight == NULL) {
			return false;
		}
		return myRight->contains(it);
	}
	else if (it == myItem) {
		return true;
	}
}
