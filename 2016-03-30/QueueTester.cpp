/*
 * QueueTester.cpp
 *
 *  Created on: Mar 30, 2016
 *      Author: adams
 */

#include "QueueTester.h"
#include "Queue.h"
#include <iostream>
#include <cassert>
#include <cstdlib>     // exit()
using namespace std;

void QueueTester::runTests() {
	cout << "Testing class Queue..." << endl;
	testConstructors();
	testAppendAndRemove();
	testAssignment();
	cout << "All tests passed!" << endl;
}

void QueueTester::testAssignment() {
	cout << "- assignment... " << flush;
	// empty case
	Queue q0, q1;
	q1 = q0;
	assert( q1.isEmpty() );
	assert( !q1.isFull() );
	cout << " 0 " << flush;
	// non-empty case
	q1.append(11);
	q1.append(22);
	q1.append(33);
	Queue q2;
	q2 = q1;
	assert( q2.remove() == 11 );
	assert( q2.remove() == 22 );
	assert( q2.remove() == 33 );
	assert( q2.isEmpty() );
	assert( !q1.isEmpty() );
	cout << " 1a " << flush;
	assert( q1.remove() == 11 );
	assert( q1.remove() == 22 );
	assert( q1.remove() == 33 );
	assert( q1.isEmpty() );
	cout << " 1b " << flush;
	// chaining
	q1.append(11);
	q1.append(22);
	q1.append(33);
	q2 = q0 = q1;
	assert( q2.remove() == 11 );
	assert( q2.remove() == 22 );
	assert( q2.remove() == 33 );
	assert( q2.isEmpty() );
	assert( !q1.isEmpty() );
	assert( !q0.isEmpty() );
	cout << " 2a " << flush;
	assert( q0.remove() == 11 );
	assert( q0.remove() == 22 );
	assert( q0.remove() == 33 );
	assert( q0.isEmpty() );
	assert( !q1.isEmpty() );
	cout << " 2b " << flush;
	assert( q1.remove() == 11 );
	assert( q1.remove() == 22 );
	assert( q1.remove() == 33 );
	assert( q1.isEmpty() );
	cout << " 2c " << flush;
	// self-assignment
	q1.append(11);
	q1.append(22);
	q1.append(33);
	q1 = q1;
	assert( !q1.isEmpty() );
	assert( q1.remove() == 11 );
	assert( q1.remove() == 22 );
	assert( q1.remove() == 33 );
	assert( q1.isEmpty() );
	cout << " 3 " << flush;

	cout << " Passed!" << endl;
}

void QueueTester::testAppendAndRemove() {
	cout << "- append() and remove()... " << flush;
	Queue qu;
	qu.append(11);
	assert( !qu.isEmpty() );
	assert( !qu.isFull() );
	assert( qu.getFirstItem() == 11 );
	assert( qu.getLastItem() == 11 );
	assert( qu.remove() == 11 );
	cout << " 0 " << flush;
	qu.append(22);
	qu.append(33);
	assert( qu.getLastItem() == 33 );
	qu.append(44);
	assert( qu.getLastItem() == 44 );
	qu.append(55);
	assert( qu.getLastItem() == 55 );
	qu.append(66);
	assert( !qu.isEmpty() );
//	assert( qu.isFull() );
//	try {
//		qu.append(77);
//		cerr << "Append() worked on full queue";
//		exit(1);
//	} catch (overflow_error& ofe) {
//		cout << "1 " << flush;
//	}
	assert( qu.getFirstItem() == 22 );
	assert( qu.getLastItem() == 66 );
	assert( qu.remove() == 22 );
	assert( !qu.isFull() );
	assert( qu.getFirstItem() == 33 );
	assert( qu.getLastItem() == 66 );
	assert( qu.remove() == 33 );
	assert( qu.getFirstItem() == 44 );
	assert( qu.getLastItem() == 66 );
	assert( qu.remove() == 44 );
	assert( qu.getFirstItem() == 55 );
	assert( qu.getLastItem() == 66 );
	assert( qu.remove() == 55 );
	assert( qu.getFirstItem() == 66 );
	assert( qu.getLastItem() == 66 );
	assert( qu.remove() == 66 );
	assert( qu.isEmpty() );
	assert( !qu.isFull() );
	cout << " 2 " << flush;
	try {
		qu.remove();
		cerr << "Remove worked on empty queue";
		exit(1);
	} catch (underflow_error& ufe) {
		cout << " 3 " << flush;
	}

	cout << " Passed!" << endl;
}

void QueueTester::testConstructors() {
	cout << "- constructors... " << flush;
	Queue qu;
	assert( qu.isEmpty() );
	assert( !qu.isFull() );
	cout << " 0 " << flush;
	// copy constructor
	Queue q1(qu);
	assert( q1.isEmpty() );
	assert( !q1.isFull() );
	cout << " 1 " << flush;
	q1.append(99);
	q1.append(88);
	q1.append(77);
	Queue q2(q1);
	assert( q2.remove() == 99 );
	assert( q2.remove() == 88 );
	assert( q2.remove() == 77 );
	assert( q2.isEmpty() );
	assert( !q1.isEmpty() );
	cout << " 2a " << flush;
	assert( q1.remove() == 99 );
	assert( q1.remove() == 88 );
	assert( q1.remove() == 77 );
	assert( q1.isEmpty() );
	cout << " 2b " << flush;

	cout << " Passed!" << endl;
}
