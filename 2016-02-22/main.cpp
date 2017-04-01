/*
 * main.cpp
 *
 *  Created on: Feb 22, 2016
 *      Author: adams
 */

#include "VecTester.h"
#include <iostream>
#include <cassert>
using namespace std;

template<class someType>
void exchange(someType& a, someType& b) {
	someType t = a; a = b; b = t;
}

int main() {
	VecTester vt;
	vt.runTests();

	cout << "\nChecking exchange... " << endl;
	int x = 11; int y = 22;
	exchange(x, y);
	assert( x == 22 );
	assert( y == 11 );
	double w = 99; double z = 98;
	exchange(w, z);
	assert( w == 98 );
	assert( z == 99 );

	cout << " Passed!" << endl;
}


