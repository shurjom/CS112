/*
 * VecTester.cpp
 *
 *  Created on: Feb 22, 2016
 *      Author: adams
 */

#include "VecTester.h"
#include "Vec.h"
#include <iostream>
#include <cassert>
#include <cstdlib>  // exit()
using namespace std;

void VecTester::runTests() {
	cout << "Testing class Vec..." << endl;
	testConstructors();
	 testAssignment();
	 testSubscript();
	 cout << "All tests passed!" << endl;
}

void testConst(const Vec<unsigned>& v) {
	for (unsigned i = 0; i < 5; i++) {
		assert( v[i] == i+11 );
	}
	cout << " 2 " << flush;

}

void VecTester::testSubscript() {
	cout << "- subscript... " << flush;
	Vec<double> v0;
	try {
		v0[0];
		cerr << "subscript worked on empty Vec";
		exit(1);
	} catch (range_error& re) {
		cout << " 0 " << flush;
	}
	Vec<unsigned> v1(5);
	for (unsigned i = 0 ; i < 5; i++) {
		v1[i] = i+11;
	}
	for (unsigned i = 0; i < 5; i++) {
		assert( v1.myPtr[i] == i+11 );
	}
	cout << " 1 " << flush;
	testConst(v1);
	cout << " Passed!" << endl;
}

void VecTester::testAssignment() {
	cout << "- assignment... " << flush;
	Vec<int> v0;
	Vec<int> v1(5);
	v1 = v0;
	assert( v1.getSize() == 0 );
	assert( v1.myPtr == NULL );
	cout << " 0 " << flush;
	Vec<int> v2(5);
	v2.myPtr[0] = 11;
	v2.myPtr[1] = 22;
	v2.myPtr[2] = 33;
	v2.myPtr[3] = 44;
	v2.myPtr[4] = 55;
	v1 = v2;
	assert( v1.getSize() == 5 );
	assert( v1.myPtr != NULL );
	for (unsigned i = 0; i < 5; i++) {
		assert( v1.myPtr[i] == int((i+1)*11) );
	}
	assert( v1.myPtr != v2.myPtr );
	cout << " 1 " << flush;
	Vec<int> v3;
	v3 = v0 = v1;
	assert( v3.getSize() == 5 );
	assert( v3.myPtr != NULL );
	for (unsigned i = 0; i < 5; i++) {
		assert( v3.myPtr[i] == int((i+1)*11) );
	}
	assert( v3.myPtr != v0.myPtr );
	cout << " 2a " << flush;
	assert( v0.getSize() == 5 );
	assert( v0.myPtr != NULL );
	for (unsigned i = 0; i < 5; i++) {
		assert( v0.myPtr[i] == int((i+1)*11) );
	}
	assert( v0.myPtr != v1.myPtr );
	cout << " 2b " << flush;
	v3 = v3;
	assert( v3.getSize() == 5 );
	assert( v3.myPtr != NULL );
	for (unsigned i = 0; i < 5; i++) {
		assert( v3.myPtr[i] == int((i+1)*11) );
	}
	assert( v3.myPtr != v0.myPtr );
	cout << " 3 " << flush;

	cout << " Passed!" << endl;
}

void VecTester::testConstructors() {
	cout << "- constructors..." << flush;
	// default
	Vec<double> v0;
	assert( v0.getSize() == 0 );
	assert( v0.myPtr == NULL );
	cout << " 0 " << flush;
	// explicit
	Vec<double> v1(5);
	assert( v1.getSize() == 5 );
	assert( v1.myPtr != NULL );
	for (unsigned i = 0; i < 5; i++) {
		assert( v1.myPtr[i] == double() );
	}
	cout << " 1 " << flush;
	// copy constructor
	Vec<double> v2(v0);
	assert( v2.getSize() == 0 );
	assert( v2.myPtr == NULL );
	assert( &v2 != &v0 );
	cout << " 2 " << flush;
	Vec<double> v3(v1);
	assert( v3.getSize() == 5 );
	assert( v3.myPtr != NULL );
	for (unsigned i = 0; i < 5; i++) {
		assert( v3.myPtr[i] == double() );
	}
	assert( &v3 != &v1 );
	assert( v3.myPtr != v1.myPtr );
	cout << " 3 " << flush;


	cout << "Passed" << endl;
}
