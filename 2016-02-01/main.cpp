/*
 * main.cpp
 *
 *  Created on: Feb 1, 2016
 *      Author: adams
 */

#include<iostream>  // cin, cout, ...
#include <fstream>  // ifstream, ofstream, ...
#include <cassert>  // assert()
#include <cmath>    // sqrt()
using namespace std;

int main() {
	ifstream fin("numbers.txt");
	assert( fin.is_open() );
	ofstream fout( "roots.txt");
	assert( fout.is_open() );

	double number;
	while (true) {
		fin >> number;
		if ( fin.eof() ) break;
		fout << sqrt(number) << '\n';
	}
	fin.close();
	fout.close();

	cout << "Processing complete! See 'roots.txt' for results.";

//	cout << "Enter your name: ";
//	string name;
//	cin >> name;
//	cerr << "Welcome to CS 112, " << name << "!";
}


