/* Vec.cpp defines the methods for Vec, a simple vector class.
 * Student:Shurjo Maitra
 * Date:2.23.16
 * Begun by: Joel C. Adams, for CS 112 at Calvin College.
 */

#include "Vec.h"
#include <cstdlib>
#include <stdexcept>

//initializes empty vector and sets size
Vec::Vec() {
	mySize = 0;
	myArray = NULL;
}

//destroys the vector and resets to empty
Vec::~Vec() {
	delete[] myArray;
	myArray = NULL;
	mySize = 0;
}

//constructs with explicit value
Vec::Vec(unsigned size) {
	mySize = size;
	myArray = new Item[mySize]();

}
//copies one vector to a new one
Vec::Vec(const Vec& original) {
	mySize = original.mySize;
	if (original.mySize > 0) {
		myArray = new Item[mySize];
		for (unsigned i = 0; i < mySize; i++) {
			myArray[i] = original.myArray[i];
		}
	} else {
		myArray = NULL;
	}
}

//copies one vector by item and checks size
Vec& Vec::operator=(const Vec& original) {
	if (this != &original) {
		if (mySize > 0) {
			delete[] myArray;
			myArray = NULL;
		}
		if (original.mySize > 0) {
			myArray = new Item[original.mySize];
		}
		mySize = original.mySize;
	}
	for (unsigned i = 0; i < mySize; i++) {
		myArray[i] = original.myArray[i];
	}
	return *this;
}

//obtains the size of the vector
unsigned Vec::getSize() const {
	return mySize;
}

//sets a particular item in the vector to a certain value
void Vec::setItem(unsigned index, const Item& it) {
	if (index >= mySize){
		throw range_error("Out of range");
	}
	else {
		myArray[index] = it;
	}
}

//gets a value of an item at a particular index in vector
Item Vec::getItem(unsigned index) const {
	if (index >= mySize) {
		throw range_error("Out of range");
	}
	else {
		return myArray[index];
	}
}

//sets the size of an vector
void Vec::setSize(unsigned newSize) {
	if (mySize != newSize) {
		if (newSize == 0) {
			delete [] myArray;
			myArray = NULL;
			mySize = 0;
		}
		else {
			Item* newArray = new Item[newSize];
			if (mySize < newSize) {
				for (unsigned i = 0; i < mySize; i++) {
					newArray[i] = myArray[i];
				}
				for (unsigned i = mySize; i < newSize; i++) {
					newArray[i] = 0;
				}
			}
			else {
				for (unsigned i = 0; i < newSize; i++) {
					newArray[i] = myArray[i];
				}
			}
			mySize = newSize;
			delete [] myArray;
			myArray = newArray;
		}
	}
}

//finds out if items in vector are equal
bool Vec::operator==(const Vec& v2) {
	if (mySize != v2.mySize) {
		return false;
	}
	for (unsigned i = 0; i < mySize; i++) {
		if (myArray[i] != v2.myArray[i]) {
			return false;
		}
	}
	return true;
}

//outputs items in a vector to a text file
void Vec::writeTo(ostream& out) const {
	for (unsigned i = 0; i < mySize; i++) {
		out << myArray[i] << "\n";
	}
}

//reads in values to indices in the vector
void Vec::readFrom(istream& in) {
	for (unsigned i = 0; i < mySize; i++) {
		in >> myArray[i];
	}
}

