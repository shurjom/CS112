/*
 * ReversePoemTester.cpp defines test-methods for the ReversePoem class
 * Joel Adams, for CS 112 at Calvin College.
 * Student Name:Shurjo Maitra
 * Date:3.31.16
 */

#include "ReversePoemTester.h"
#include "Stack.h"
#include <iostream>  // cout, cerr, ...
#include <cassert>   // assert()
#include <cstdlib>   // exit()
#include <stdexcept>
using namespace std;

void ReversePoemTester::runTests() {
	cout << "Testing ReversePoem class..." << endl;
	testEmptyConstructor();
	testFileConstructor();
	testGetTitle();
	testGetBody();
	testgetBodyReversed();
}

void ReversePoemTester::testEmptyConstructor() {
	cout << "- Testing empty constructor()... " << flush;
	// invalid parameter
//		try {
//			Stack<double> s1(0);
//			cerr << ";
//			exit(1);
//		} catch (StackException& se) {

//		cout << "\nConstructed stack of size 0" << flush;
	cout << " 0 " << flush;
	// valid parameter
	Stack<double> s2(3);
	cout << " 1 " << flush;
	cout << " Passed!" << endl;
}
/*Todo: coming up with and writing test cases.
 *
 */
void ReversePoemTester::testFileConstructor() {
	cout << "- Testing File constructor()... " << flush;
	cout << " 0 " << flush;
	cout << " 1 " << flush;
	cout << " 2 " << flush;
	cout << " Passed!" << endl;
}

/*Todo: coming up with and writing test cases.
 *
 */
void ReversePoemTester::testGetTitle() {
	cout << "- Testing getTitle constructor()... " << flush;
	cout << " 0 " << flush;
	cout << " 1 " << flush;
	cout << " 2 " << flush;
	cout << " Passed!" << endl;
}

/*Todo: coming up with and writing test cases.
 *
 */
void ReversePoemTester::testGetBody() {
	cout << "- Testing getBody constructor()... " << flush;
	cout << " 0 " << flush;
	cout << " 1 " << flush;
	cout << " 2 " << flush;
	cout << " Passed!" << endl;
}

/*Todo: coming up with and writing test cases.
 *
 */
void ReversePoemTester::testgetBodyReversed() {
	cout << "- Testing getBodyReversed constructor()... " << flush;
	cout << " 0 " << flush;
	cout << " 1 " << flush;
	cout << " 2 " << flush;
	cout << " 3a " << flush;
	cout << " 3b " << flush;
	cout << " Passed!" << endl;
}
