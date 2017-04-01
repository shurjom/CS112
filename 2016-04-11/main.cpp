/*
 * main.cpp
 *
 *  Created on: Apr 11, 2016
 *      Author: adams
 */


#include <iostream>
using namespace std;

void move(unsigned n, char src, char dest, char aux) {
	static unsigned count = 1;
	if ( n == 1 ) {
		cout << count++ <<
				". Move the top disk from "
				<< src << " to " << dest << endl;
	} else {
		move(n-1, src, aux, dest);
		move(1, src, dest, aux);
		move(n-1, aux, dest, src);
	}
}

int main() {
	cout << "Hanoi Towers!\n\nEnter the number of disks: ";
	unsigned numDisks;
	cin >> numDisks;
	move(numDisks, 'A', 'B', 'C');
}

