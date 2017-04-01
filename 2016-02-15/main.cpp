/*
 * main.cpp
 *
 *  Created on: Feb 15, 2016
 *      Author: adams
 */


#include <iostream>
using namespace std;

typedef int Item;

void print( int* arr, unsigned size) {
	for (unsigned i = 0; i < size; i++) {
		cout << arr[i] << ' ';
//		cout << *arr << ' ';
//		arr++;
	}
	cout << endl;
}

#define SIZE 5

int main() {
	int a[SIZE] = {99, 98, 97, 96, 95};
//	a = {99, 98, 97, 96, 95};
	print(a, SIZE);

	int * aPtr = new int[SIZE];
	print(aPtr, SIZE);

	cout << a << " " << sizeof(Item) << endl
			<< &aPtr << endl
			<< aPtr << endl
//		 << &(a[0]) << " " << a[0] << endl
//		 << &(a[1]) << " " << a[1] << endl
//		 << &(a[2]) << " " << a[2] << endl
		 << endl;
	delete [] aPtr;

}

