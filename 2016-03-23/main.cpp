/*
 * main.cpp
 *
 *  Created on: Mar 23, 2016
 *      Author: adams
 */

#include "StackTester.h"
#include "Stack.h"

int main() {
	StackTester st;
	st.runTests();

	cout << "Enter a word: ";
	string word;
	cin >> word;
	Stack<char> charStack;
	for (unsigned i = 0; i < word.size(); ++i) {
		charStack.push(word[i]);
	}
	while ( !charStack.isEmpty() ) {
		cout << charStack.pop();
	}
}

