/* main.cpp tests the classes in our project.
 * Student Name:Shurjo Maitra
 * Date:2.8.16
 * Begun by: Joel Adams, for CS 112 at Calvin College.
 */
#ifndef SONG_H
#define SONG_H

#include <string>
using namespace std;

class Song {
public:
	Song();
	Song(const string& title, const string& artist, unsigned year);
	void readFrom(istream& in);
	void writeTo(ostream& out) const;
	string getTitle() const;
	string getArtist() const;
	unsigned getYear() const;
private:
	string myTitle;
	string myArtist;
	unsigned myYear;
};

#endif /*SONG_H_*/
