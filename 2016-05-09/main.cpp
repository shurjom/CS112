/*
 * main.cpp
 *
 *  Created on: May 9, 2016
 *      Author: adams
 */

#include <iostream>
#include <fstream>
#include <cassert>
#include <set>
#include <map>
using namespace std;

int main() {
	ifstream fin("bigFile.txt");
	assert( fin.is_open() );
	char ch;
	map<char, unsigned> charCounter;
	while(true) {
		fin >> ch;
		if (!fin) break;
		charCounter[ch]++;
	}
	for (map<char,unsigned>::iterator it = charCounter.begin();
			it != charCounter.end(); it++) {
		cout << it->first << ": " << it->second << endl;
	}


//	ifstream fin( "words.txt");
//	assert( fin.is_open() );
//	string word;
//	set<string> dictionary;
//	while(true) {
//		fin >> word;
//		if ( !fin ) break;
//		dictionary.insert(word);
//	}
//	fin.close();
//
//	for (set<string>::iterator it = dictionary.begin();
//			it != dictionary.end(); it++) {
//		cout << *it << endl;
//	}
//
//	while (word != "quit") {
//		cout << "\nEnter a word: ";
//		cin >> word;
//		if ( dictionary.find(word) == dictionary.end() ) {
//			cout << "\n*** " << word
//					<< " is not in the dictionary!\n";
//		}
//	}
}

