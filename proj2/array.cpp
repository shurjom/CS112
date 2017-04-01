/* array.cpp defines "C style" array operations
 * Name:Shurjo Maitra
 * Date:2.22.16
 * Begun by: Joel Adams, for CS 112 at Calvin College.
 */
 
#include "array.h"

//creates an empty array
void initialize(double *a, int size) {
	int val = 0;
	for (int i = 0; i < size; i++) {
		val = i+1;
		a[i] = val;
	}
}
//prints out whatever is in the array
void print(double *a, int size) {
	for (int i = 0; i < size; i++) {
		cout << *a << '\t';
		a++;
	}
}		

//averages all the objects in the array
double average(double *a, int size) {
	double sum = 0;
	for (int x = 0; x < size; x++) {
		sum += *a;
		a++;

	}
	return sum/size;
}

//sums up all the numbers in the array
double sum(double *a, int size) {
	double sum = 0;
	for (int i = 0; i < size; i++) {
		sum = sum + *a;
		a++;
	}
	return sum;
}

//reads in size of integers and stores them
void read(istream& in, double *a, int size) {
	for (int i = 0; i < size; i++) {
		in >> *a;
		a++;
}
}

//fills in part of the array with new numbers
void fill(const string& fileName, double *&a, int &numValues) {
	ifstream fin(fileName.c_str());
	assert (fin.is_open());
	fin >> numValues;
	double * newArray = new double[numValues];
	*&a = newArray;
	for(int i = 0; i < numValues; i++) {
		fin >> *&a[i];
	}
	fin.close();
}


//resizes the array, truncates the rest
void resize(double *&a, int oldSize, int newSize) {
	double * newArray = new double[newSize];
	if (newSize > oldSize) {
		for (int i = 0; i < oldSize; i++) {
		newArray[i] = a[i];
		}
	}
	if (newSize < oldSize) {
		for (int i = 0; i < newSize; i++) {
			newArray[i] = a[i];
		}
	}
	delete [] a;
	a = newArray;
}

//concatenates new numbers to the array
void concat(double *a1, int size1, double *a2, int size2, double *&a3, int &size3) {
	if (a3 != NULL) {
		delete [] a3;
	}
	size3 = size1 + size2;
	a3 = new double[size3];

	for (int i = 0; i < size1; i++) {
		a3[i] = a1[i];
	}
	for (int i = 0; i < size2; i++) {
		a3[i + size1] = a2[i];
	}
}
