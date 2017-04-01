/*
 * Vec.h
 *
 *  Created on: Feb 22, 2016
 *      Author: adams
 */

#ifndef VEC_H_
#define VEC_H_

#include <iostream>
#include <stdexcept>
using namespace std;

template<class Item>
class Vec {
public:
	Vec();
	Vec(unsigned size);
	Vec(const Vec<Item>& original);
	~Vec();
	unsigned getSize() const { return mySize; }
	Vec<Item>& operator=(const Vec<Item>& original);
	Item& operator[](unsigned index);             // write
	const Item& operator[](unsigned index) const; // read
private:
	unsigned mySize;
	Item *   myPtr;

	void makeCopyOf(const Vec<Item>& original);

	friend class VecTester;
};

template<class Item>
Vec<Item>::Vec() {
	mySize = 0;
	myPtr = NULL;
}

template<class Item>
Vec<Item>::Vec(unsigned size) {
	mySize = size;
	myPtr = new Item[size]();
//	for (unsigned i = 0; i < size; i++) {
//		myPtr[i] = Item();
//	}
}

template<class Item>
void Vec<Item>::makeCopyOf(const Vec<Item>& original) {
	mySize = original.mySize;
	if (original.myPtr == NULL) {
		myPtr = NULL;
	} else {
		myPtr = new Item[original.mySize];
		for (unsigned i = 0; i < mySize; i++) {
			myPtr[i] = original.myPtr[i];
		}
	}
}

template<class Item>
Vec<Item>::Vec(const Vec<Item>& original) {
	makeCopyOf(original);
}

template<class Item>
Vec<Item>::~Vec() {
	delete [] myPtr;
//	cout << "\ndestructor fired" << endl;
}

template<class Item>
Vec<Item>& Vec<Item>::operator=(const Vec<Item>& original) {
	if (this != &original) {
		delete [] myPtr;
		makeCopyOf(original);
	}
	return *this;
}

template<class Item>
Item& Vec<Item>::operator[](unsigned index) {
	if (index >= mySize) {
		throw range_error("Vec::operator[]: index too large");
	}
	return myPtr[index];
}

template<class Item>
const Item& Vec<Item>::operator[](unsigned index) const {
	if (index >= mySize) {
		throw range_error("Vec::operator[]: index too large");
	}
	return myPtr[index];
}


#endif /* VEC_H_ */
