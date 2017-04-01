/* Vec.h provides a simple vector class named Vec.
 * Student: Aaron Santucci & Shurjo Maitra
 * Date: Feb 23, 2016
 * Begun by: Joel C. Adams, for CS 112 at Calvin College.
 */

#ifndef VEC_H_
#define VEC_H_

#include <iostream>
#include <cstdlib>
#include <stdexcept>
#include <fstream>
#include <ostream>
#include <cassert>
using namespace std;

typedef double Item;

class Vec {
public:
	Vec();
	virtual ~Vec();
	Vec(unsigned size);
	Vec(const Vec& original);
	Vec& operator = (const Vec& original);
	unsigned getSize() const;
	void setItem(unsigned index, const Item& it);
	Item getItem(unsigned index) const;
	void setSize(unsigned newSize);
	bool operator == (const Vec& v2);
	void writeTo(ostream& out) const;
	void readFrom(istream& in);
	Item& operator [] (unsigned index);
	Item& operator [] (unsigned index) const;
	bool operator != (const Vec& v2);
	void readFrom(string fileName);
	void writeTo(string fileName);
	Vec operator + (const Vec& v2);
	Vec operator - (const Vec& v2);
	double operator * (const Vec& v2);

private:
	unsigned mySize;
	Item * myArray;
	friend class VecTester;
	friend class application;
};

#endif /*VEC_H_*/
