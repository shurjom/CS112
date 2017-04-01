/* array.h declares "C style" array operations.
 * Name:Shurjo Maitra
 * Date:2.22.16
 * Begun by: Joel Adams, for CS 112 at Calvin College.
 */
 
#include <iostream>
#include <cassert>
#include <fstream>
using namespace std;

void initialize(double *a, int size);

void print(double *a, int size);

double average(double *a, int size);

double sum(double *a, int size);

void read(istream& in, double *a, int size);

void fill(const string& fileName, double *&a, int &numValues);

void resize(double *&a, int oldSize, int newSize);

void concat(double *a1, int size1, double *a2, int size2, double *&a3, int &size3);
