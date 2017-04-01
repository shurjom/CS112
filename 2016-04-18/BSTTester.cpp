/*
 * BSTTester.cpp
 *
 *  Created on: Apr 18, 2016
 *      Author: adams
 */

#include "BSTTester.h"
#include "BST.h"
#include <cassert>
using namespace std;

void BST_Tester::runTests() {
	cout << "Testing class BST... " << endl;
	testConstructors();
	testInsert();
	cout << "All tests passed!" << endl;
}

void BST_Tester::testInsert() {
	cout << "- insert()... " << flush;
	BST bst;
	bst.insert(55);
	assert( bst.getNumItems() == 1 );
	assert( bst.myRootPtr != NULL );
	assert( bst.myRootPtr->myItem == 55 );
	assert( bst.myRootPtr->myLeftPtr == NULL );
	assert( bst.myRootPtr->myRightPtr == NULL );
	cout << " 0 " << flush;
	bst.insert(33);
	assert( bst.getNumItems() == 2 );
	assert( bst.myRootPtr != NULL );
	assert( bst.myRootPtr->myItem == 55 );
	assert( bst.myRootPtr->myLeftPtr != NULL );
	assert( bst.myRootPtr->myRightPtr == NULL );
	assert( bst.myRootPtr->myLeftPtr->myItem == 33 );
	assert( bst.myRootPtr->myLeftPtr->myLeftPtr == NULL );
	assert( bst.myRootPtr->myLeftPtr->myRightPtr == NULL );
	cout << " 1 " << flush;
	bst.insert(77);
	assert( bst.getNumItems() == 3 );
	assert( bst.myRootPtr != NULL );
	assert( bst.myRootPtr->myItem == 55 );
	assert( bst.myRootPtr->myLeftPtr != NULL );
	assert( bst.myRootPtr->myRightPtr != NULL );
	assert( bst.myRootPtr->myLeftPtr->myItem == 33 );
	assert( bst.myRootPtr->myLeftPtr->myLeftPtr == NULL );
	assert( bst.myRootPtr->myLeftPtr->myRightPtr == NULL );
	assert( bst.myRootPtr->myRightPtr->myItem == 77 );
	assert( bst.myRootPtr->myRightPtr->myLeftPtr == NULL );
	assert( bst.myRootPtr->myRightPtr->myRightPtr == NULL );
	cout << " 2 " << flush;
	bst.insert(44);
	assert( bst.getNumItems() == 4 );
	assert( bst.myRootPtr != NULL );
	assert( bst.myRootPtr->myItem == 55 );
	assert( bst.myRootPtr->myLeftPtr != NULL );
	assert( bst.myRootPtr->myRightPtr != NULL );
	assert( bst.myRootPtr->myLeftPtr->myItem == 33 );
	assert( bst.myRootPtr->myLeftPtr->myLeftPtr == NULL );
	assert( bst.myRootPtr->myLeftPtr->myRightPtr != NULL );
	assert( bst.myRootPtr->myRightPtr->myItem == 77 );
	assert( bst.myRootPtr->myRightPtr->myLeftPtr == NULL );
	assert( bst.myRootPtr->myRightPtr->myRightPtr == NULL );
	assert( bst.myRootPtr->myLeftPtr->myRightPtr->myItem == 44 );
	assert( bst.myRootPtr->myLeftPtr->myRightPtr->myLeftPtr == NULL );
	assert( bst.myRootPtr->myLeftPtr->myRightPtr->myRightPtr == NULL );
	cout << " 3 " << flush;

	cout << " Passed!" << endl;
}

void BST_Tester::testConstructors() {
	cout << "- constructors... " << flush;
	BST bst;
	assert( bst.getNumItems() == 0 );
	assert( bst.myRootPtr == NULL );
	cout << " 0 " << flush;
	// copy constructor
	BST bst1(bst);
	assert( bst1.getNumItems() == 0 );
	assert( bst1.myRootPtr == NULL );
	cout << " 1 " << flush;
	bst.insert(44);
	bst.insert(22);
	bst.insert(66);
	BST bst2(bst);
	assert( bst2.getNumItems() == 3 );
	assert( bst2.myRootPtr != NULL );
	assert( bst2.myRootPtr->myItem == 44 );

	assert( bst2.myRootPtr->myLeftPtr->myItem == 22 );
	assert( bst2.myRootPtr->myLeftPtr->myLeftPtr == NULL );
	assert( bst2.myRootPtr->myLeftPtr->myRightPtr == NULL );

	assert( bst2.myRootPtr->myRightPtr->myItem == 66 );
	assert( bst2.myRootPtr->myRightPtr->myLeftPtr == NULL );
	assert( bst2.myRootPtr->myRightPtr->myRightPtr == NULL );
	// check for deep copy
	assert( bst2.myRootPtr != bst.myRootPtr );
	assert( bst2.myRootPtr->myLeftPtr != bst.myRootPtr->myLeftPtr );
	assert( bst2.myRootPtr->myRightPtr != bst.myRootPtr->myRightPtr );
	cout << " 2 " << flush;

	cout << " Passed!" << endl;
}
