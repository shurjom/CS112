/* Stack.cpp defines the dynamically allocated (array-based ) Stack operations.
 * Joel Adams, for CS 112 at Calvin College.
 * Student Name: Shurjo Maitra
 * Date: 3.31.16
 */

#include "Stack.h"

/* explicit-value constructor
 * Parameter: size, an unsigned value.
 * Precondition: size > 0.
 * Postcondition: myTop == 0 && myCapacity == size
 *              && myArray contains the address of a dynamic array of 'size' entries.
 */
Stack::Stack(unsigned size) {
	if (size > 0) {
		myTop = 0;
		myCapacity = size;
		myArray = new Item[size];
	} else {
		throw StackException("Stack(size):", "size must be positive!.");
	}
}

/* copy constructor
 * Parameter: original, a Stack (const reference).
 * Postcondition: I am a copy of original.
 */
Stack::Stack(const Stack& original) {
	makeCopyOf(original);
}

/* utility method containing code refactored from
 *  the copy constructor and operator=.
 * Parameter: original, a Stack (const reference).
 * Postcondition: I am a copy of original.
 */
void Stack::makeCopyOf(const Stack& original) {
	myCapacity = original.myCapacity;
	myArray = new Item[myCapacity];

	for (unsigned i = 0; i < myCapacity; i++) {
		myArray[i] = original.myArray[i];
	}
	myTop = original.myTop;
}

/* destructor
 * Postcondition: myCapacity == 0 && myTop == 0
 *             && myArray has been deallocated.
 */
Stack::~Stack() {
	delete[] myArray;
	myArray = NULL;
	myCapacity = 0;
	myTop = 0;
}

/* assignment operator
 * Parameter: original, a Stack (const reference).
 * Postcondition: I am a copy of original
 *              && I have been returned.
 */
Stack& Stack::operator=(const Stack& original) {
	if (this != &original) {
		delete[] myArray;
		makeCopyOf(original);
	}
	return *this;
}

/*isEmpty operator
 * Parameter: stack
 * Postcondition: whether or not I am empty
 */
bool Stack::isEmpty() {
	if (myTop == 0) {
		return true;
	} else {
		return false;
	}
}

/*push operator
 *Parameter: an Item
 *PostCondition: a stack with a new item if there is space
 */
void Stack::push(const Item& it) {
	if (myTop == myCapacity) {
		throw StackException("push()", "stack is full");
	} else {
		for (unsigned i = 0; i < myCapacity; i++) {
			myArray[myTop] = it;
		}
		myTop += 1;
	}
}
/*isFull operator
 * Parameter: stack
 * Postcondition: whether or not I am empty
 */
bool Stack::isFull() {
	if (myTop == myCapacity) {
		return true;
	}
}
/*getTop operator
 * Parameter: a stack
 * Postcondition: value of the item on the top most on stack
 */
Item Stack::getTop() const {
	if (myTop > 0) {
		return myArray[myTop - 1];
	} else {
		throw StackException("getTop()", "stack is empty");
	}
}

/* pop operator
 * Parameter: index
 * Postcondition: stack with the item at index myTop removed
 */
Item Stack::pop() {
	if (isEmpty() == true) {
		throw StackException("pop()", " pop(): stack is empty!");
	} else {
		myTop -= 1;
		return myArray[myTop];
	}

}
