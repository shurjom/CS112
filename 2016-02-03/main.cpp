/*
 * main.cpp
 *
 *  Created on: Feb 3, 2016
 *      Author: adams
 */

#include <iostream>
#include <cassert>
using namespace std;

unsigned factorial(unsigned n) {
	unsigned result = 1;
	for (unsigned number = 2; number <= n; number++) {
		// result = result * number;
		result *= number;
	}
	return result;
}

void exchange(int & a, int & b) {
	int temp = a;
	a = b;
	b = temp;
}

void print(const string & genome) {
	for(unsigned i = 0; i < genome.size(); i++) {
		cout << genome[i];
	}
	cout << "\n";
}


int main() {
	string data = "ACTGACTG";
	print(data);

	int x = 11, y = 22;
	exchange(x, y);
	assert( x == 22);
	assert( y == 11 );

	assert( factorial(0) == 1 );
	assert( factorial(1) == 1 );
	assert( factorial(2) == 2 );
	assert( factorial(3) == 6 );
	assert( factorial(4) == 24 );
	assert( factorial(5) == 120 );

	cout << "Passed all tests!\n";
}


