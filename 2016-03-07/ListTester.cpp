/*
 * ListTester.cpp
 *
 *  Created on: Mar 7, 2016
 *      Author: adams
 */

#include "ListTester.h"
#include "List.h"
#include <iostream>
#include <cassert>
using namespace std;

void ListTester::runTests() {
	cout << "Testing class List..." << endl;
	testConstructors();
	testAppend();
	testPrepend();
	cout << "All tests passed!" << endl;
}

void ListTester::testPrepend() {
	cout << "- prepend... " << flush;
	List aList;
	aList.prepend(99);
	assert( aList.getSize() == 1 );
	assert( aList.myFirstPtr->myItem == 99 );
	assert( aList.myLastPtr->myItem == 99 );
	assert( aList.myLastPtr->myNextPtr == NULL );
	cout << " 0 " << flush;
	aList.prepend(98);
	assert( aList.getSize() == 2 );
	assert( aList.myFirstPtr->myItem == 98 );
	assert( aList.myFirstPtr->myNextPtr == aList.myLastPtr );
	assert( aList.myLastPtr->myItem == 99 );
	assert( aList.myLastPtr->myNextPtr == NULL );
	cout << " 1 " << flush;
	aList.prepend(97);
	assert( aList.getSize() == 3 );
	assert( aList.myFirstPtr->myItem == 97 );
	assert( aList.myFirstPtr->myNextPtr != aList.myLastPtr );
	assert( aList.myFirstPtr->myNextPtr->myItem == 98 );
	assert( aList.myFirstPtr->myNextPtr->myNextPtr == aList.myLastPtr );
	assert( aList.myLastPtr->myItem == 99 );
	assert( aList.myLastPtr->myNextPtr == NULL );
	cout << " 2 " << flush;

	cout << " Passed!" << endl;
}

void ListTester::testAppend() {
	cout << "- append... " << flush;
	List aList;
	aList.append(11);
	assert( aList.getSize() == 1 );
	assert( aList.myFirstPtr->myItem == 11 );
	assert( aList.myLastPtr->myItem == 11 );
	assert( aList.myLastPtr->myNextPtr == NULL );
	cout << " 0 " << flush;
	aList.append(22);
	assert( aList.getSize() == 2 );
	assert( aList.myFirstPtr->myItem == 11 );
	assert( aList.myFirstPtr->myNextPtr == aList.myLastPtr );
	assert( aList.myLastPtr->myItem == 22 );
	assert( aList.myLastPtr->myNextPtr == NULL );
	cout << " 1 " << flush;
	aList.append(33);
	assert( aList.getSize() == 3 );
	assert( aList.myFirstPtr->myItem == 11 );
	assert( aList.myFirstPtr->myNextPtr != aList.myLastPtr );
	assert( aList.myFirstPtr->myNextPtr->myItem == 22 );
	assert( aList.myFirstPtr->myNextPtr->myNextPtr == aList.myLastPtr );
	assert( aList.myLastPtr->myItem == 33 );
	assert( aList.myLastPtr->myNextPtr == NULL );
	cout << " 2 " << flush;
	cout << " Passed!" << endl;
}

void ListTester::testConstructors() {
	cout << "-constructors... " << flush;
	List aList0;
	assert( aList0.getSize() == 0 );
	assert( aList0.myFirstPtr == NULL );
	assert( aList0.myLastPtr == NULL );
	cout << " 0 " << flush;
	// explicit
	vector<double> aVector0;
	List aList1(aVector0);
	assert( aList1.myFirstPtr == NULL );
	assert( aList1.myLastPtr == NULL );
	assert( aList1.mySize == 0 );
	cout << " 1a " << flush;
	vector<double> aVector1;
	aVector1.push_back(11);
	aVector1.push_back(22);
	aVector1.push_back(33);
	List aList1b(aVector1);
	assert( aList1b.getSize() == 3 );
	assert( aList1b.myFirstPtr->myItem == 11 );
	assert( aList1b.myFirstPtr->myNextPtr != aList1b.myLastPtr );
	assert( aList1b.myFirstPtr->myNextPtr->myItem == 22 );
	assert( aList1b.myFirstPtr->myNextPtr->myNextPtr == aList1b.myLastPtr );
	assert( aList1b.myLastPtr->myItem == 33 );
	assert( aList1b.myLastPtr->myNextPtr == NULL );
	cout << " 1b " << flush;

	// copy
	List aList2(aList0);
	assert( aList2.getSize() == 0 );
	assert( aList2.myFirstPtr == NULL );
	assert( aList2.myLastPtr == NULL );
	cout << " 2 " << flush;
	List aList3;
	aList3.append(11);
	aList3.append(22);
	aList3.append(33);
	List aList4(aList3);
	assert( aList4.getSize() == 3 );
	assert( aList4.myFirstPtr->myItem == 11 );
	assert( aList4.myFirstPtr->myNextPtr != aList4.myLastPtr );
	assert( aList4.myFirstPtr->myNextPtr->myItem == 22 );
	assert( aList4.myFirstPtr->myNextPtr->myNextPtr == aList4.myLastPtr );
	assert( aList4.myLastPtr->myItem == 33 );
	assert( aList4.myLastPtr->myNextPtr == NULL );
	assert( aList4.myFirstPtr != aList3.myFirstPtr);
	assert( aList4.myLastPtr != aList3.myLastPtr);
	cout << " 3 " << flush;
	cout << " Passed!" << endl;
}
