/* ListTester.h declares the test-class for class List.
 * Student Name:Shurjo Maitra
 * Date:3.8.16
 * Joel Adams, for CS 112 at Calvin College.
 */

#ifndef LISTTESTER_H_
#define LISTTESTER_H_

class ListTester {
public:
	void runTests();
	void testDefaultConstructor();
	void testNodeDefaultConstructor();
	void testNodeExplicitConstructor();
	void testAppend();
	void testDestructor();
	void testCopyConstructor();
	void testAssignment();
	void testEquality();
	void testInequality();
	void testWriteToStream()const;
	void testReadFromString()const;
	void testGetIndexOf();
	void testRemove();
    void testReadFrom();
    void testWriteToString();
    void testPrepend();
    void testInsertion();

};

#endif /*LISTTESTER_H_*/
