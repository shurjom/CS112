/*ReversePoem.cpp provides (dynamic-array-based) ReversePoem methods
 * Joel Adams, for CS 112 at Calvin College.
 * Student Name:Shurjo Maitra
 * Date:3.31.16
 */

#include "ReversePoem.h"
using namespace std;

/*ReversePoem() empty constructor
 */
ReversePoem::ReversePoem() {
}

/*ReversePoem() constructor when a file is used as input
 *@param: fileName from which data is extracted
 *PostCondition: info on title, author, etc
 */
ReversePoem::ReversePoem(const string &file) {
	ifstream svar(file.c_str());
	string x;
	getline(svar, x);
	myTitle = x;
	getline(svar, x);
	myAuthor = x;
	getline(svar, x);
	Stack<string> myStack(1);
	while (!svar.eof()) {
		getline(svar, x);
		if (x != "") {
			try {
				myStack.push(x);
			} catch (StackException& se) {
				myStack.setCapacity(myStack.getCapacity() * 2);
				myStack.push(x);
			}
			myBody += x += "\n";
		}
	}
	while (!myStack.isEmpty()) {
		myRevBody += myStack.pop() += "\n";
	}
}

/*getTitle() method
 *Return: myTitle
 */
string ReversePoem::getTitle() {
	return myTitle;
}

/*getAuthor() method
 *Return: myAuthor
 */
string ReversePoem::getAuthor() {
	return myAuthor;
}

/*getBody() method
 *Return: myBody
 */
string ReversePoem::getBody() {
	return myBody;
}

/*getBodyReversed() method
 *Return: myRevBody
 */
string ReversePoem::getBodyReversed() {
	return myRevBody;
}
