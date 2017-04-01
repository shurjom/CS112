/*
 * main.cpp
 *
 *  Created on: Apr 13, 2016
 *      Author: adams
 */

#include <iostream>
#include <cassert>
using namespace std;

unsigned long long factorial1(unsigned n) {
	unsigned long long result = 1;
	for (unsigned i = 2; i <= n; i++) {
		result *= i;
	}
	return result;
}

unsigned long long factorial2(unsigned n) {
	if (n == 0 || n == 1) {
		return 1;
	} else {
		return factorial2(n-1) * n;
	}
}

double power1(double x, unsigned n) {
	double result = 1.0;
	for (unsigned i = 1; i <= n; i++) {
		result *= x;
	}
	return result;
}

double power2(double x, unsigned n) {
	if ( n == 0 ) {
		return 1.0;
	} else if ( n == 1 ) {
		return x;
	} else {
		double temp = power2(x, n/2);
		double result = temp * temp;
		if ( n % 2 ) {
			result *= x;
		}
		return result;
	}
}


int main() {
	assert( factorial1(0) == 1 );
	assert( factorial1(1) == 1 );
	assert( factorial1(2) == 2 );
	assert( factorial1(3) == 6 );
	assert( factorial1(4) == 24 );
	assert( factorial1(5) == 120 );
	cout << " 0 " << flush;
	assert( factorial2(0) == 1 );
	assert( factorial2(1) == 1 );
	assert( factorial2(2) == 2 );
	assert( factorial2(3) == 6 );
	assert( factorial2(4) == 24 );
	assert( factorial2(5) == 120 );
	cout << " 1 " << flush;

	assert( power1(2, 0) == 1 );
	assert( power1(2, 1) == 2 );
	assert( power1(2, 2) == 4 );
	assert( power1(2, 3) == 8 );
	assert( power1(2, 4) == 16 );
	assert( power1(2, 5) == 32 );
	assert( power1(2, 10) == 1024 );
	assert( power1(3, 0) == 1 );
	assert( power1(3, 1) == 3 );
	assert( power1(3, 2) == 9 );
	assert( power1(3, 3) == 27 );
	assert( power1(10, 2) == 100 );
	assert( power1(10, 6) == 1000000 );
	cout << " 2 " << flush;

	assert( power2(2, 0) == 1 );
	assert( power2(2, 1) == 2 );
	assert( power2(2, 2) == 4 );
	assert( power2(2, 3) == 8 );
	assert( power2(2, 4) == 16 );
	assert( power2(2, 5) == 32 );
	assert( power2(2, 10) == 1024 );
	assert( power2(3, 0) == 1 );
	assert( power2(3, 1) == 3 );
	assert( power2(3, 2) == 9 );
	assert( power2(3, 3) == 27 );
	assert( power2(10, 2) == 100 );
	assert( power2(10, 6) == 1000000 );
	cout << " 3 " << flush;

	cout << " Passed!" << endl;
}


