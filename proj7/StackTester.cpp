/* StackTester.cpp defines test-methods for the 
 *  dynamically allocated (array) Stack operations
 * Joel Adams, for CS 112 at Calvin College
 * Student Name:Shurjo Maitra
 * Date:3.31.16
 */

#include "StackTester.h"
#include "Stack.h"
#include <iostream>  // cout, cerr, ...
#include <cassert>   // assert()
#include <cstdlib>   // exit()
#include <stdexcept>
using namespace std;

void StackTester::runTests() {
	cout << "Testing Stack class..." << endl;
//	testConstructor();
//	testIsEmpty();
//	testPushAndIsFull();
//	testGetTop();
//	testPop();
//	testCopyConstructor();
//	testAssignment();
//	testDestructor();
	testgetCapacity();
	testsetCapacity();
	testgetSize();
	cout << "All tests passed!" << endl;
}
//
//void StackTester::testConstructor() {
//	cout << "- Testing constructor... " << flush;
//	// invalid parameter
//	try {
//		Stack<double> s1(0);
//		cerr << "\nConstructed stack of size 0\n";
//		exit(1);
//	} catch (StackException& se) {
//		cout << se << flush;
//	}
//	cout << " 1 " << flush;
//	// valid parameter
//	Stack<double> s2(3);
//	cout << " 2 " << flush;
//	cout << " Passed!" << endl;
//}
//
//void StackTester::testIsEmpty() {
//	cout << "- Testing isEmpty()... " << flush;
//	// capacity 1
//	Stack<double> s1(1);
//	assert( s1.isEmpty() );
//	cout << " 1 " << flush;
//	// capacity > 1
//	Stack<double> s2(3);
//	assert( s2.isEmpty() );
//	cout << " 2 " << flush;
//	cout << " Passed!" << endl;
//}
//
//
//void StackTester::testPushAndIsFull() {
//	cout << "- Testing push()... " << flush;
//	// test with capacity 1
//	Stack<double> s1(1);
//	s1.push(11);
//	assert( !s1.isEmpty() );
//	assert( s1.isFull() );
//	try {
//		s1.push(22);
//		cerr << "\npush() worked on a full stack (size 1)\n";
//		exit(1);
//	} catch (StackException& se) {
//		cout << " 1 " << flush;
//	}
//	// test with capacity > 1
//	Stack<double> s2(3);
//	s2.push(11);
//	s2.push(22);
//	s2.push(33);
//	try {
//		s2.push(44);
//		cerr << "\npush() worked on a full stack (size 3)\n";
//		exit(1);
//	} catch (StackException& se) {
//		cout << " 2 " << flush;
//	}
//	cout << " Passed! " << endl;
//}
//
//void StackTester::testGetTop() {
//	cout << "- Testing getTop()... " << flush;
//	// test with empty stack
//	Stack<double> s1(1);
//	try {
//		s1.getTop();
//		cerr << "\ngetTop() worked on empty stack\n";
//		exit(1);
//	} catch (StackException& se) {
//		cout << se << endl;
// 		cout << " 1 " << flush;
//	}
//	// test with capacity 1
//	Stack<double> s2(1);
//	s2.push(11);
//	assert( s2.getTop() == 11 );
//	cout << " 2 " << flush;
//	// test with capacity > 1
//	Stack<double> s3(3);
//	s3.push(11);
//	assert( s3.getTop() == 11 );
//	s3.push(22);
//	assert( s3.getTop() == 22 );
//	s3.push(33);
//	assert( s3.getTop() == 33 );
//	cout << " 3 " << flush;
//	cout << " Passed! " << endl;
//}
//
//void StackTester::testPop() {
//	cout << "- Testing pop()... " << flush;
//	// try empty, capacity 1
//	Stack<double> s1(1);
//	assert( s1.isEmpty() );
//	try {
//		s1.pop();
//		cerr << "\npop() worked on empty stack (size 1)\n";
//		exit(1);
//	} catch (StackException& se) {
//		cout << " 1 " << flush;
//	}
//	 //try empty, capacity > 1
//	Stack<double> s2(3);
//	try {
//		s2.pop();
//		cerr << "\npop() worked on empty stack (size 3)\n";
//		exit(1);
//	} catch (StackException& se) {
//		cout << " 2 " << flush;
//	}
//	// try non-empty, capacity 1
//	Stack<double> s3(1);
//	s3.push(11);
//	assert( s3.getTop() == 11 );
//	assert( s3.pop() == 11 );
//	try {
//		s3.pop();
//		cerr << "\ns3.pop() worked on empty stack (size 1)\n";
//		exit(1);
//	} catch (StackException& se) {
//		cout << " 3 " << flush;
//	}
//	 //try non-empty, capacity > 1
//	Stack<double> s4(3);
//	s4.push(11);
//	s4.push(22);
//	s4.push(33);
//	assert( s4.getTop() == 33 );
//	assert( s4.pop() == 33 );
//	assert( s4.getTop() == 22 );
//	assert( s4.pop() == 22 );
//	assert( s4.getTop() == 11 );
//	assert( s4.pop() == 11 );
//	try {
//		s4.pop();
//		cerr << "\ns4.pop() worked on empty stack (size 3)\n";
//		exit(1);
//	} catch (StackException& se) {
//		cout << " 4 " << flush;
//	}
//	cout << " Passed!" << endl;
//}
//
//void StackTester::testCopyConstructor() {
//	cout << "- Testing copy constructor... " << flush;
//	// minimal empty Stack
//	Stack<double> s1(1);
//	Stack<double> s2(s1);
//	assert( s2.isEmpty() );
//	assert( s2.myArray != NULL );
//	assert( s2.myCapacity == 1 );
//	assert( s2.myArray != s1.myArray );
//	cout << " 1 " << flush;
//	// minimal non-empty Stack
//	Stack<double> s3(1);
//	s3.push(11);
//	Stack<double> s4(s3);
//	assert( !s4.isEmpty() );
//	assert( s4.isFull() );
//	assert( s4.getTop() == 11 );
//	assert( s4.myArray != s3.myArray );
//	cout << " 2 " << flush;
//	// non-minimal, non-empty stack
//	Stack<double> s5(3);
//	s5.push(11);
//	s5.push(22);
//	s5.push(33);
//	Stack<double> s6(s5);
//	assert( s6.myCapacity = s5.myCapacity );
//	assert( s6.myTop == s5.myTop );
//	assert( s6.myArray != s5.myArray );
//	assert( s6.pop() == 33 );
//	assert( s6.pop() == 22 );
//	assert( s6.pop() == 11 );
//	assert( s5.getTop() == 33 );
//	cout << " 3 " << flush;
//	cout << "Passed!" << endl;
//}
//
//void StackTester::testAssignment() {
//	cout << "- Testing assignment... " << flush;
//	// minimal empty Stacks, same size
//	Stack<double> s1(1);
//	Stack<double> s2(1);
//	s2 = s1;
//	assert( s2.isEmpty() );
//	assert( s2.myArray != NULL );
//	assert( s2.myArray != s1.myArray );
//	assert( s2.myCapacity == 1 );
//	cout << " 1 " << flush;
//	// minimal non-empty Stack to empty Stack, same capacity
//	Stack<double> s3(1);
//	s3.push(11);
//	Stack<double> s4(1);
//	s4 = s3;
//	assert( !s4.isEmpty() );
//	assert( s4.isFull() );
//	assert( s4.getTop() == 11 );
//	assert( s4.myArray != s3.myArray );
//	cout << " 2 " << flush;
//	// minimal empty stack to non-empty stack, same capacity
//	Stack<double> s5(1);
//	Stack<double> s6(1);
//	s6.push(11);
//	s6 = s5;
//	assert( s6.isEmpty() );
//	assert( s6.myArray != NULL );
//	assert( s6.myArray != s5.myArray );
//	assert( s6.myCapacity == 1 );
//	cout << " 3 " << flush;
//	// non-minimal non-empty stack to empty stack, different capacities
//	Stack<double> s7(3);
//	s7.push(11);
//	s7.push(22);
//	s7.push(33);
//	Stack<double> s8(2);
//	s8 = s7;
//	assert( s8.myArray != s7.myArray );
//	assert( s8.myCapacity = s7.myCapacity );
//	assert( s8.myTop == s7.myTop );
//	assert( s8.pop() == 33 );
//	assert( s8.pop() == 22 );
//	assert( s8.pop() == 11 );
//	assert( s7.getTop() == 33 );
//	cout << " 4 " << flush;
//	// non-minimal, empty stack to non-empty stack, different capacities
//	Stack<double> s9(2);
//	Stack<double> s10(3);
//	s10.push(11);
//	s10.push(22);
//	s10.push(33);
//	s10 = s9;
//	assert( s10.isEmpty() );
//	assert( s10.myArray != s9.myArray );
//	assert( s10.myCapacity == s10.myCapacity );
//	cout << " 5 " << flush;
//	// self-assignment, minimal size
//	Stack<double> s11(1);
//	s11.push(11);
//	s11 = s11;
//	assert( s11.isFull() );
//	assert( !s11.isEmpty() );
//	cout << " 6 " << flush;
//	// chaining
//	Stack<double> s12(2);
//	s12.push(11);
//	s12.push(22);
//	Stack<double> s13(1);
//	Stack<double> s14(1);
//	s14 = s13 = s12;
//	assert( s14.isFull() );
//	assert( s14.myArray != s13.myArray );
//	assert( s14.myArray != s12.myArray );
//	assert( s14.pop() == 22 );
//	assert( s14.pop() == 11 );
//	assert( s14.isEmpty() );
//	cout << " 7 " << flush;
//      // self-assignment, non-minimal size
//      s13 = s13;
//	assert( !s13.isEmpty() );
//	assert( s13.isFull() );
//	assert( s13.pop() == 22 );
//	assert( s13.pop() == 11 );
//	assert( s13.isEmpty() );
//	cout << " 8 " << flush;
//	cout << "Passed!" << endl;
//}
//
//void StackTester::testDestructor() {
//	cout << "- Testing destructor..." << flush;
//	// minimal, empty
//	Stack<double> s1(1);
//	s1.~Stack();
//	assert( s1.isEmpty() );
//	assert( s1.myArray == NULL );
//	assert( s1.myCapacity == 0 );
//	cout << " 1 " << flush;
//	// minimal, non-empty
//	Stack<double> s2(1);
//	s2.push(11);
//	s2.~Stack();
//	assert( s2.isEmpty() );
//	assert( s2.myArray == NULL );
//	assert( s2.myCapacity == 0 );
//	cout << " 2 " << flush;
//	// non-minimal, empty
//	Stack<double> s3(3);
//	s3.~Stack();
//	assert( s3.isEmpty() );
//	assert( s3.myArray == NULL );
//	assert( s3.myCapacity == 0 );
//	cout << " 3 " << flush;
//	// non-minimal, non-empty
//	Stack<double> s4(3);
//	s4.push(11);
//	s4.push(22);
//	s4.push(33);
//	s4.~Stack();
//	assert( s4.isEmpty() );
//	assert( s4.myArray == NULL );
//	assert( s4.myCapacity == 0 );
//	cout << " 4 " << flush;
//	cout << " Passed!" << endl;
//}


void StackTester::testgetSize() {
	cout << "- Testing getSize()..." << flush;
	// test with capacity 1
	Stack<double> s1(1);
	s1.push(11);
	assert( !s1.isEmpty() );
	assert( s1.isFull() );
	assert( s1.getSize() == 1);
	cout << " 1 " << flush;
	// test with capacity > 1
	Stack<double> s2(3);
	s2.push(11);
	s2.push(22);
	s2.push(33);
	assert( s2.getSize() == 3);
	cout << " 2 " << flush;
	// another test with capacity > 1
	Stack<double> s3(4);
	s3.push(-1);
	s3.push(11);
	s3.push(22);
	assert ( s3.getSize() == 3);
	cout << " 3 " << flush;
	cout << " Passed! " << endl;
}


void StackTester::testgetCapacity() {
	cout << "- Testing getCapacity()..." << flush;
	// test with capacity 1
	Stack<double> s1(1);
	s1.push(11);
	assert( !s1.isEmpty() );
	assert( s1.isFull() );
	assert( s1.getCapacity() == 1);
	cout << " 1 " << flush;
	// test with capacity > 1
	Stack<double> s2(3);
	s2.push(11);
	s2.push(22);
	s2.push(33);
	assert( s2.getCapacity() == 3);
	cout << " 2 " << flush;
	// another test with capacity > 1
	Stack<double> s3(4);
	s3.push(-1);
	s3.push(11);
	s3.push(22);
	s3.push(100);
	assert ( s3.getCapacity() == 4);
	cout << " 3 " << flush;
	cout << " Passed! " << endl;
}


void StackTester::testsetCapacity() {
	cout << "- Testing setCapacity()..." << flush;
	// try empty, setcapacity 0
	Stack<double> s0(1);
	s0.push(11);
	try {
		s0.setCapacity(0);
		cerr << "\nsetCapacity() worked on stack with size 1\n";
		exit(1);
	} catch (StackException& se) {
		cout << " 0 " << flush;
	}
	Stack<double> s1(4);
	s1.push(11);
	s1.push(22);
	s1.push(33);
	assert( s1.getCapacity() == 4 );
	assert( s1.getSize() == 3);
	s1.setCapacity(3);
	assert( s1.getCapacity() == 3);
	assert( s1.getSize() == 3);
	cout << " 1 " << flush;
	try {
		s1.setCapacity(1);
		cerr << "\nsetCapacity() worked on stack with greater size\n";
		exit(1);
	} catch (StackException& se) {
		cout << " 2 " << flush;
	}
	cout << " Passed! " << endl;
}
