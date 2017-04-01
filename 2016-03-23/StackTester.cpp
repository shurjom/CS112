/*
 * StackTester.cpp
 *
 *  Created on: Mar 23, 2016
 *      Author: adams
 */

#include "StackTester.h"
#include "Stack.h"
#include <iostream>
#include <cassert>
#include <cstdlib>   // exit()
using namespace std;

void StackTester::runTests() {
	cout << "Testing class Stack... " << endl;
	testConstructors();
	testPushPopGetTop();
	testAssignment();
	cout << "All tests passed!" << endl;
}

void StackTester::testAssignment() {
	cout << "- assignment... " << flush;
	Stack<int> aStack;
	Stack<int> stack1;
	// empty case
	stack1 = aStack;
	assert( stack1.isEmpty() );
	assert( !stack1.isFull() );
	cout << " 0 " << flush;
	// nonempty case
	stack1.push(99);
	stack1.push(98);
	stack1.push(97);
	Stack<int> stack2;
	stack2 = stack1;
	assert( stack2.pop() == 97 );
	assert( stack2.pop() == 98 );
	assert( stack2.pop() == 99 );
	assert( stack2.isEmpty() );
	assert( !stack1.isEmpty() );
	assert( stack1.pop() == 97 );
	assert( stack1.pop() == 98 );
	assert( stack1.pop() == 99 );
	assert( stack1.isEmpty() );
	cout << " 1 " << flush;
	// chaining
	stack1.push(11);
	stack1.push(22);
	stack1.push(33);
	Stack<int> stack3;
	stack3 = stack2 = stack1;
	assert( stack2.pop() == 33 );
	assert( stack2.pop() == 22 );
	assert( stack2.pop() == 11 );
	assert( stack2.isEmpty() );
	assert( stack3.pop() == 33 );
	assert( stack3.pop() == 22 );
	assert( stack3.pop() == 11 );
	assert( stack3.isEmpty() );
	assert( stack1.pop() == 33 );
	assert( stack1.pop() == 22 );
	assert( stack1.pop() == 11 );
	assert( stack1.isEmpty() );
	cout << " 2 " << flush;
	// self-assignment
	stack1.push(11);
	stack1.push(22);
	stack1.push(33);
	stack1 = stack1;
	assert( stack1.pop() == 33 );
	assert( stack1.pop() == 22 );
	assert( stack1.pop() == 11 );
	assert( stack1.isEmpty() );
	cout << " 3 " << flush;

	cout << " Passed!" << endl;
}
void StackTester::testPushPopGetTop() {
	cout << "- push, pop, getTop... " << flush;
	Stack<double> aStack;
	aStack.push(99);
	assert( !aStack.isEmpty() );
	assert( !aStack.isFull() );
	assert( aStack.getTop() == 99 );
	assert( aStack.pop() == 99 );
	assert( aStack.isEmpty() );
	assert( !aStack.isFull() );
	cout << " 0a " << flush;

	try {
		aStack.pop();
		cerr << "Pop() worked on empty Stack";
		exit(1);
	} catch (underflow_error& ufe) {
		cout << " 0b " << flush;
	}

	try {
		aStack.getTop();
		cerr << "getTop() worked on empty Stack";
		exit(1);
	} catch (underflow_error& ufe) {
		cout << " 0c " << flush;
	}

	aStack.push(98);
	aStack.push(97);
	aStack.push(96);
	aStack.push(95);
	aStack.push(94);
	assert( !aStack.isEmpty() );
//	assert( aStack.isFull() );
	assert( aStack.getTop() == 94 );
	assert( aStack.pop() == 94 );
	assert( !aStack.isEmpty() );
	assert( aStack.getTop() == 95 );
	assert( aStack.pop() == 95 );
	assert( !aStack.isEmpty() );
	assert( aStack.getTop() == 96 );
	assert( aStack.pop() == 96 );
	assert( !aStack.isEmpty() );
	assert( aStack.getTop() == 97 );
	assert( aStack.pop() == 97 );
	assert( !aStack.isEmpty() );
	assert( aStack.getTop() == 98 );
	assert( aStack.pop() == 98 );
	assert( aStack.isEmpty() );
	assert( !aStack.isFull() );
	cout << " 1 " << flush;
	cout << " Passed!" << endl;
}

void StackTester::testConstructors() {
	cout << "- constructors... " << flush;
	Stack<double> aStack;
	assert( aStack.isEmpty() );
	assert( !aStack.isFull() );
	cout << " 0 " << flush;
	// copy (empty)
	Stack<double> stack1(aStack);
	assert( stack1.isEmpty() );
	assert( !stack1.isFull() );
	cout << " 1 " << flush;
	// copy (nonempty)
	stack1.push(11);
	stack1.push(22);
	stack1.push(33);
	Stack<double> stack2(stack1);
	assert( !stack2.isEmpty() );
	assert( !stack2.isFull() );
	assert( stack2.pop() == 33 );
	assert( stack2.pop() == 22 );
	assert( stack2.pop() == 11 );
	assert( stack2.isEmpty() );
	assert( !stack1.isEmpty() );
	assert( !stack1.isFull() );
	assert( stack1.pop() == 33 );
	assert( stack1.pop() == 22 );
	assert( stack1.pop() == 11 );
	assert( stack1.isEmpty() );
	cout << " 2 " << flush;

	cout << " Passed!" << endl;
}

