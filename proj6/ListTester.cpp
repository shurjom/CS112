/* ListTester.cpp defines the test methods for class List.
 * Student Name:Shurjo Maitra
 * Date:3.8.16
 * Joel Adams, for CS 112 at Calvin College.
 */


#include "ListTester.h" // ListTester
#include "List.h"       // List
#include <iostream>     // cin, cout
#include <cassert>      // assert()
#include <cstdlib>      // exit()
#include <stdexcept>    // underflow_error
using namespace std;

void ListTester::runTests() {
	cout << "Running List tests..." << endl;
//	testDefaultConstructor();
//	testNodeDefaultConstructor();
//	testNodeExplicitConstructor();
//	testAppend();
//	testDestructor();
//	testCopyConstructor();
//	testAssignment();
//	testGetIndexOf();
//    testEquality();
//    testPrepend();
//    testInsertion();
//	testInequality();
//	testWriteToString();
//	testReadFrom();
//	testReadFromString();
//	testWriteToStream();
//	testRemove();
	testInsertBefore();
	testInsertAfter();
	testOutput();
	cout << "All tests passed!" << endl;
}

//void ListTester::testDefaultConstructor() {
//	cout << "Testing List default constructor... " << flush;
//	List<double> aList;
//	assert( aList.mySize == 0 );
//	assert( aList.myFirst == NULL );
//	assert( aList.myLast == NULL );
//	cout << "Passed!" << endl;
//}
//
//void ListTester::testNodeDefaultConstructor() {
//	cout << "Testing Node default constructor... " << flush;
//	List<double>::Node aNode;
//	assert( aNode.myItem == 0 );
//	assert( aNode.myNext == NULL );
//	cout << "Passed!" << endl;
//}
//
//void ListTester::testNodeExplicitConstructor() {
//	cout << "Testing Node explicit constructor... " << flush;
//	List<double>::Node n1(11, NULL);
//	assert( n1.myItem == 11 );
//	assert( n1.myNext == NULL );
//	cout << " 1 " << flush;
//
//	List<double>::Node *n3 = new List<double>::Node(33, NULL);
//	List<double>::Node n2(22, n3);
//	assert( n2.myItem == 22 );
//	assert( n2.myNext == n3 );
//	cout << " 2 " << flush;
//	cout << "Passed!" << endl;
//}
//
//void ListTester::testAppend() {
//	cout << "Testing append()... " << flush;
//	// empty List
//	List<double> aList;
//	assert( aList.getSize() == 0 );
//	assert( aList.myFirst == NULL );
//	assert( aList.myLast == NULL );
//	try {
//		aList.getFirst();
//		cerr << "getFirst() worked on empty list" << endl;
//		exit(1);
//	} catch (underflow_error&) {
//		cout << " 0a " << flush;
//	}
//	try {
//		aList.getLast();
//		cerr << "getLast() worked on empty list" << endl;
//		exit(1);
//	} catch (underflow_error&) {
//		cout << " 0b " << flush;
//	}
//	// append to empty list
//	aList.append(11);
//	assert( aList.getSize() == 1 );
//	assert( aList.myFirst != NULL );
//	assert( aList.myLast == aList.myFirst );
//	assert( aList.getFirst() == 11 );
//	assert( aList.getLast() == 11 );
//	assert( aList.myFirst->myNext == NULL );
//	cout << " 1 " << flush;
//	// append to a list containing 1 Item
//	aList.append(22);
//	assert( aList.getSize() == 2 );
//	assert( aList.myFirst != NULL );
//	assert( aList.myLast != NULL );
//	assert( aList.myFirst != aList.myLast );
//	assert( aList.getFirst() == 11 );
//	assert( aList.getLast() == 22 );
//	assert( aList.myFirst->myNext != NULL );
//	assert( aList.myLast->myNext == NULL );
//	cout << " 2 " << flush;
//	// append to a list containing 2 Items
//	aList.append(33);
//	assert( aList.getSize() == 3 );
//	assert( aList.myFirst != NULL );
//	assert( aList.myLast != NULL );
//	assert( aList.getFirst() == 11 );
//	assert( aList.getLast() == 33 );
//	assert( aList.myFirst->myNext->myItem == 22 );
//	assert( aList.myLast->myNext == NULL );
//	cout << " 3 " << flush;
//	cout << "Passed!" << endl;
//}
//
//void ListTester::testDestructor() {
//	cout << "Testing destructor... " << flush;
//	List<double> aList;
//	aList.~List();
//	assert( aList.getSize() == 0 );
//	assert( aList.myFirst == NULL );
//	assert( aList.myLast == NULL );
//	cout << " 1 " << flush;
//
//	aList.append(11);
//	aList.append(22);
//	aList.append(33);
//	aList.~List();
//	assert( aList.getSize() == 0 );
//	assert( aList.myFirst == NULL );
//	assert( aList.myLast == NULL );
//	cout << " 2 " << flush;
//	cout << "Passed!  But double-check for memory leaks!" << endl;
//}
//
//void ListTester::testCopyConstructor() {
//	cout << "Testing copy constructor... " << flush;
//	// copy empty list
//	List<double> list1;
//	List<double> list2(list1);
//	assert( list2.getSize() == 0 );
//	assert( list2.myFirst == NULL );
//	assert( list2.myLast == NULL );
//	cout << " 1 " << flush;
//
//	// copy nonempty list
//	List<double> list3;
//	list3.append(11);
//	list3.append(22);
//	list3.append(33);
//	List<double> list4(list3);
//	assert( list4.getSize() == 3 );
//	assert( list4.getFirst() == 11 );
//	assert( list4.getLast() == 33 );
//	assert( list4.myFirst->myNext->myItem == 22 );
//	assert( list4.myFirst != list3.myFirst );
//	assert( list4.myLast != list3.myLast );
//	cout << " 2 " << flush;
//	cout << "Passed!" << endl;
//}
//
//void ListTester::testAssignment() {
//	cout << "Testing assignment... " << flush;
//	// empty to empty assignment
//	List<double> list1;
//	List<double> list2;
//	list2 = list1;
//	assert( list2.getSize() == 0 );
//	assert( list2.myFirst == NULL );
//	assert( list2.myLast == NULL );
//	cout << " 1 " << flush;
//
//	// non-empty to empty assignment
//	List<double> list3;
//	list3.append(11);
//	list3.append(22);
//	list3.append(33);
//	List<double> list4;
//	list4 = list3;
//	assert( list4.getSize() == 3 );
//	assert( list4.getFirst() == 11 );
//	assert( list4.getLast() == 33 );
//	assert( list4.myFirst->myNext->myItem == 22 );
//	cout << " 2 " << flush;
//
//	// equal-sized non-empty to non-empty assignment
//	List<double> list5;
//	list5.append(44);
//	list5.append(55);
//	list5.append(66);
//	list5 = list3;
//	assert( list5.getSize() == 3 );
//	assert( list5.getFirst() == 11 );
//	assert( list5.getLast() == 33 );
//	assert( list5.myFirst->myNext->myItem == 22 );
//	cout << " 3 " << flush;
//
//	// empty to non-empty assignment
//	List<double> list6;
//	list6.append(44);
//	list6.append(55);
//	list6.append(66);
//	List<double> list7;
//	list6 = list7;
//	assert( list6.getSize() == 0 );
//	assert( list6.myFirst == NULL );
//	assert( list6.myLast == NULL );
//	cout << " 4 " << flush;
//
//	// unequal-sized non-empty to non-empty assignment
//	List<double> list8;
//	list8.append(44);
//	list8.append(55);
//	list8.append(66);
//	list8.append(77);
//	list8 = list3;
//	assert( list8.getSize() == 3 );
//	assert( list8.getFirst() == 11 );
//	assert( list8.getLast() == 33 );
//	assert( list8.myFirst->myNext->myItem == 22 );
//	cout << " 5 " << flush;
//
//	// assignment chaining
//	List<double> list9;
//	list9.append(44);
//	list9.append(55);
//	list9.append(66);
//	list9.append(77);
//	List<double> list10;
//	list10 = list9 = list8;
//	assert( list10.getSize() == 3 );
//	assert( list10.getFirst() == 11 );
//	assert( list10.getLast() == 33 );
//	assert( list10.myFirst->myNext->myItem == 22 );
//	cout << " 6 " << flush;
//
//	// self-assignment (stupid, but possible)
//	List<double> list11;
//	list11.append(11);
//	list11.append(22);
//	list11.append(33);
//	//list11 = list11;
//	assert( list11.getSize() == 3 );
//	assert( list11.getFirst() == 11 );
//	assert( list11.getLast() == 33 );
//	assert( list11.myFirst->myNext->myItem == 22 );
//	cout << " 7 " << flush;
//
//	cout << "Passed!  But double-check for memory leaks!" << endl;
//}
//
//void ListTester::testEquality() {
//	cout << "Testing equality... " << flush;
//	// two empty lists
//	List<double> list1;
//	List<double> list2;
//	assert( list1 == list1 );
//	cout << " 1 " << flush;
//
//	// a non-empty list
//	List<double> list3;
//	list3.append(33);		// [33]
//	assert( !(list3 == list1) );
//	cout << " 2 " << flush;
//
//	// equal, non-empty lists of the same size
//	List<double> list4;
//	list4.append(33);		// [33]
//	assert( list4 == list3 );
//	assert( list3 == list4 );
//	cout << " 3 " << flush;
//
//	// unequal, non-empty lists of the same size
//	list3.append(55);		// [33,55]
//	List<double> list5;
//	list5.append(44);		// [44]
//	list5.append(55);		// [44,55]
//	assert( !(list5 == list3) );
//	assert( !(list3 == list5) );
//	cout << " 4 " << flush;
//
//	// unequal non-empty lists of different sizes
//	list4.append(44);		// [33,44]
//	list4.append(55);		// [33,44,55]
//	assert( !(list4 == list5) );
//	assert( !(list5 == list4) );
//	assert( !(list5 == list3) );
//	cout << " 5 " << flush;
//
//	cout << "Passed!" << endl;
//}
//
//void ListTester::testInequality() {
//	cout << "Testing Inequality... " << flush;
//	// two empty lists
//	List<double> list1;
//	List<double> list2;
//	assert( !(list1 != list1) );
//	cout << " 1 " << flush;
//
//	// a non-empty list
//	List<double> list3;
//	list3.append(33);		// [33]
//	assert(list3 != list1);
//	cout << " 2 " << flush;
//
//	// equal, non-empty lists of the same size
//	List<double> list4;
//	list4.append(44);		// [33]
//	assert( list4 != list3 );
//	assert( list3 != list4 );
//	cout << " 3 " << flush;
//
//	// unequal, non-empty lists of the same size
//	list3.append(55);		// [33,55]
//	List<double> list5;
//	list5.append(44);		// [44]
//	list5.append(55);		// [44,55]
//	assert (list5 != list3);
//	assert (list3 != list5);
//	cout << " 4 " << flush;
//
//	// unequal non-empty lists of different sizes
//	list4.append(44);		// [33,44]
//	list4.append(55);		// [33,44,55]
//	assert (list4 != list5);
//	assert(list5 != list4);
//	assert(list5 != list3);
//	cout << " 5 " << flush;
//
//	cout << "Passed!" << endl;
//}
//
//void ListTester::testWriteToStream() const {
//	cout << "Testing writeTo(ostream)... " << flush;
//	List<double> List1;
//	assert( List1.getSize() == 0 );
//	assert( List1.myFirst == NULL );
//	assert( List1.myLast == NULL );
//	// append to empty list
//	List1.append(11);
//	List1.append(22);
//	List1.append(33);//[11,22,33]
//	assert(List1.mySize == 3);
//	cout << " 1 " << flush;
//
//	// write to an ofstream instead of cout, to automate the test
//	ofstream fout("ListStreamOut.txt");//writing to file "ListStreamOut.txt
//	assert( fout.is_open() );//assert if open
//	List1.writeTo(fout);//use WriteTo method
//	fout.close();//close stream
//	cout << "Passed! See 'ListStreamOut.txt' for values..." <<
//			flush;
//
//	List<double> List2;//create new empty list
//	assert( List2.getSize() == 0 );//make sure new list is empty
//	assert( List2.myFirst == NULL );
//	assert( List2.myLast == NULL );
//	//check to see if values passed into file is correct
//	List2.readFrom("ListStreamOut.txt");
//	cout << List2.getSize() << endl;
//
//	assert(List2.getSize() == 3);//check
//	assert(List2.getFirst() == 11);
//	assert(List2.getLast() == 33);
//	assert(List2.myFirst->myNext-> myItem == 22);//check for myItem in 2nd node
//	cout << " 2 " << flush;
//	cout << "Passed!" << endl;
//
//}
//
//void ListTester::testReadFromString() const {
//	cout << "Testing readFrom()... " << flush;
//	List<double> List3;
//	List3.readFrom("ListStreamOut.txt");//call function
//	cout << " 1 " << flush;
//	List3.writeTo(cout);
//	assert( List3.getSize() == 3 );
//	assert( List3.myFirst != NULL );
//	assert( List3.getFirst() == 11 );
//	assert( List3.getLast() == 33 );
//	assert( List3.myFirst->myNext->myItem == 22);//check for myItem in 2nd node
//	cout << "Passed!" << endl;
//
//}
//
//void ListTester::testGetIndexOf() {
//	cout << "Testing GetIndexOf()... " << flush;
//	List<double> list1;
//	list1.append(11);
//	list1.append(22);
//	list1.append(33);
//	list1.append(33); //[11,22,33,33]
//
//
//	int index = list1.getIndexOf(11);//call function
//	assert(index == 0);//check to see if index is correct
//	index = list1.getIndexOf(22);//call function
//	assert(index == 1);
//	index = list1.getIndexOf(33);//call function
//	assert(index == 2);
//	cout << " 1 " << flush;
//	assert(index != 3);
//	cout << " 2 " << flush;
//
//	//if item not available
//	List<double> list2;
//	list2.append(11);
//	list2.append(22);
//	list2.append(33);
//	assert(list2.getSize() == 3);
//	int index2 = list2.getIndexOf(44);//call function
//	assert(index2 == -1);
//	cout << " 3 " << flush;
//	cout << "Passed!" << endl;
//
//}
//
//void ListTester::testRemove(){
//	cout << "Testing remove()... " << flush;
//	List<double> alist;//empty list
//	alist.append(11);
//	alist.append(22);
//	alist.append(33);
//	Item it = alist.remove(8);//index greater than list
//	assert(it == 33);
//	assert(alist.getSize()==2);
//	cout << " 1 " << flush;
//
//	List<double> blist;
//	blist.append(44);
//	blist.append(55);
//	blist.append(66);
//	blist.append(77);
//	Item it2 = blist.remove(0);
//	assert(it2 == 44);
//
//	assert(blist.getFirst()== 55);
//	assert(blist.getLast()==77);
//	cout << " 2 " << flush;
//
//	List<double> clist;
//	clist.append(11);
//	clist.append(11);
//	clist.append(22);
//	clist.append(33);
//	Item it3 = clist.remove(3);
//	assert(it3 == 33);
//	cout << " 3 " << flush;
//
//	List<double> dlist;
//	dlist.append(11);
//	dlist.append(11);
//	dlist.append(22);
//	dlist.append(33);
//	Item it4 = dlist.remove(1);
//	assert(it4 == 11);
//	assert(clist.getSize()==3);
//	assert(clist.getFirst()==11);
//	cout << " 4 " << flush;
//
//	cout << "Passed!" << endl;
//}
//
//void ListTester::testReadFrom() {
//    cout << "Testing ReadFrom()..." << flush;
//
//    //reading to an empty string
//    List<double> list1;
//    ifstream fin("list.txt");
//    list1.readFrom(fin);
//
//    assert (list1.getSize() == 3);
//
//    List<double> list2;
//    list2.append(11);
//    list2.append(22);
//    list2.append(33);
//    assert(list1 == list2);
//
//    cout << " 1 " << flush;
//
//    //reading to an non-empty
//    List<double> list3;
//    ifstream in("List2.txt");
//    list3.readFrom(in);
//
//    assert(list3.getSize() != 0);
//    assert(list3.getSize() == 3);
//    assert(list3 == list2);
//    assert(list3 == list1);
//    cout << " 2 " << flush;
//    cout << "Passed" << endl;
//}
//
//void ListTester::testWriteToString() {
//    cout << "Testing writeTo() a file... " << flush;
//
//
//    List<double> list1;
//    ifstream fin1("ListStreamOut.txt");
//    list1.readFrom(fin1);
//    string fileName = "list2.txt";
//    list1.writeTo(fileName);
//
//    ifstream fin2("list2.txt");
//    List<double> list2;
//    list2.readFrom(fin2);
//
//    assert(list1 == list2);
//
//    cout << "Passed!" << endl;
//}
//
//void ListTester::testPrepend() {
//    cout << "Testing prepend()... " << flush;
//    //Empty list
//    List<double> list1;
//    list1.prepend(11);
//
//    assert(list1.getSize() == 1);
//    assert(list1.myFirst->myItem == 11);
//    assert(list1.myLast->myItem == 11);
//    assert(list1.myFirst->myNext == NULL);
//    cout << " 1 " << flush;
//
//    //Non-empty list
//    List<double> list2;
//    list2.append(22);
//    list2.prepend(11);
//
//    assert(list2.getSize() == 2);
//    assert(list2.myFirst->myItem == 11);
//    assert(list2.myFirst->myNext->myItem == 22);
//    assert(list2.myFirst->myNext == list2.myLast);
//    cout << " 2 " << flush;
//
//    cout << "Passed!" << endl;
//
//}
//
//void ListTester::testInsertion() {
//    cout << "Testing Insert()... " << flush;
//
//    //Empty list
//    List<double> list1;
//    list1.insert(11, 0);
//
//    assert(list1.getSize() == 1);
//    assert(list1.myFirst->myItem == 11);
//    assert(list1.myLast->myItem == 11);
//    assert(list1.myFirst->myNext == NULL);
//    cout << " 1 " << flush;
//
//    //test negative indices for lists with existing elements
//    List<double> list2;
//    list2.append(22);
//    list2.insert(11, -1);
//    assert(list2.getSize() == 2);
//    assert(list2.myFirst->myItem == 11);
//    assert(list2.myFirst->myNext->myItem == 22);
//    assert(list2.myFirst->myNext == list2.myLast);
//    cout << " 2 " << flush;
//
//    //test indices greater than max index for lists with existing elements
//    List<double> list3;
//    list3.append(11);
//    list3.insert(22, 5);
//
//    assert(list3.getSize() == 2);
//    assert(list3.myFirst->myItem == 11);
//    assert(list3.myFirst->myNext == list3.myLast);
//    assert(list3.myLast->myItem == 22);
//    assert(list3.myLast->myNext == NULL);
//    cout << " 3 " << flush;
//
//    //test index that is between 0 and the number of elements.
//    List<double> list4;
//    list4.append(11);
//    list4.append(33);
//
//    list4.insert(22, 1);
//
//    assert(list4.getSize() == 3);
//    assert(list4.myFirst->myItem == 11);
//    assert(list4.myFirst->myNext->myItem == 22);
//    assert(list4.myFirst->myNext->myNext->myItem == 33);
//    assert(list4.myLast->myItem == 33);
//
//    cout << "Passed!" << endl;
//
//}

void ListTester::testInsertBefore() {
	cout << "Testing insertBefore()..." << flush;

	// empty list
	List<string> list1;
	list1.insertBefore("Koko", "Lolo");
	assert(list1.mySize == 0);
	assert(list1.insertBefore("Koko", "Lolo") == false);
	cout << " 0 " << flush;

	// a non-empty list
	List<string> list2;
	list2.append("Momo");
	list2.insertBefore("Momo", "Dodo");
	assert(list2.getIndexOf("Momo") == 1);
	cout << " 1 " << flush;

	// a larger non-empty list
	List<string> list3;
	list3.append("Roro");
	list3.append("Popo");
	list3.append("Nono");
	list3.append("Zozo");
	assert(list3.insertBefore("Nono", "yoyo"));
	cout << " 2a " << flush;
	assert(list3.mySize == 5);
	cout << " 2b " << flush;
	assert(list3.getIndexOf("Hoho") == -1);
	cout << " 3 " << flush;

	cout << "Passed!" << endl;
}

void ListTester::testInsertAfter() {
	cout << "Testing insertAfter()..." << flush;

	// empty list
	List<string> list1;
	list1.insertAfter("Koko", "Lolo");
	assert(list1.mySize == 0);
	assert(list1.insertBefore("Koko", "Lolo") == false);
	cout << " 0 " << flush;

	// a non-empty list
	List<string> list2;
	list2.append("Popo");
	list2.insertAfter("Popo", "Bobo");
	assert(list2.getIndexOf("Bobo") == 1);
	cout << " 1 " << flush;

	// a larger non-empty list
	List<string> list4;
	list4.append("Roro");
	list4.append("Popo");
	list4.append("Coco");
	list4.append("Zozo");
	assert(list4.insertAfter("Coco", "Dodo"));
	assert(list4.mySize == 5);
	assert(list4.getIndexOf("Dodo") == 3);
	cout << " 2 " << flush;

	cout << "Passed!" << endl;
}

void ListTester::testOutput() {
	cout << "Testing operator<<()..." << flush;

	List<double> list1;
	list1.append(10);
	list1.append(100);
	list1.append(1000);
	list1.append(10000);
	list1.append(100000);
	assert(list1.mySize == 5);
	cout << " 0 " << flush;
//	cout << list1 << flush;
	cout << " 1 " << flush;
	cout << "Passed!" << endl;
}
