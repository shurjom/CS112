/*ReversePoem.h provides a (dynamic-stack-based) ReversePoem class.
 * Joel Adams, for CS 112 at Calvin College.
 * Student Name:Shurjo Maitra
 * Date:3.31.16
 *
 * Invariant: myTop == 0 && isEmpty() && !isFull()
 *         || myTop == myCapacity && !isEmpty() && isFull()
 *         || myTop > 0 && myTop < myCapacity && !isEmpty() && !isFull().
 * Notes:
 * 1. Member myTop always contains the index of the next empty space in myArray
 *        (the index of the array element into which the next pushed item will be placed).
 * 2. Sending push() to a full Stack throws the exception Stack::Overflow.
 * 3. Sending pop() or getTop() to an empty Stack throws the exception Stack::Underflow.
 */

#ifndef REVERSEPOEM_H_
#define REVERSEPOEM_H_

#include <string>
#include <iostream>
#include<iostream>
#include <fstream>
#include <ostream>
#include <istream>
#include <iostream>
#include <stdexcept>
#include <cassert>
#include <stdlib.h>
#include "Stack.h"

using namespace std;

typedef string Item;

class ReversePoem {
public:
	ReversePoem();
	ReversePoem(const string &filen);
	string getTitle();
	string getAuthor();
	string getBody();
	string getBodyReversed();

private:
string myFile;
string myTitle;
string myAuthor;
string myBody;
string myRevBody;
};

#endif /* REVERSEPOEM_H_ */
