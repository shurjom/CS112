/* Vec.h provides a simple vector class named Vec.
 * Student Name:Shurjo Maitra
 * Date:3.1.16
 * Begun by: Joel Adams, for CS 112 at Calvin College.
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



template <class Item>
class Vec {
public:
	Vec();
	virtual ~Vec();
	Vec(unsigned size);
	Vec(const Vec& original);
	Vec<Item>& operator = (const Vec<Item>& original);
	unsigned getSize() const;
	void setItem(unsigned index, const Item& it);
	Item getItem(unsigned index) const;
	void setSize(unsigned newSize);
	bool operator==(const Vec<Item>& v2)const;
	void writeTo(ostream& out) const;
	void readFrom(istream& in);
	Item& operator[] (unsigned index);
	const Item& operator[](unsigned index)const;
	bool operator != (const Vec& v2);
	void readFrom(string fileName);
	void writeTo(string fileName);
	Vec<Item> operator + (const Vec<Item>& v2);
	Vec<Item> operator - (const Vec<Item>& v2);
	double operator * (const Vec& v2);

private:
	unsigned mySize;
	Item * myArray;
	friend class VecTester;

};

//lab03 Vec class default constructor
template<class Item>
Vec<Item>::Vec() {
	mySize = 0;
	myArray = NULL;
}

//lab03 Vec class explicit constructor
template<class Item>
Vec<Item>::Vec(unsigned size) {
	mySize = size;
	myArray = new Item[mySize];
	for (unsigned i = 0; i < mySize; i++)
		myArray[i] = 0;
}

//lab03 Vec class copy constructor
template<class Item>
Vec<Item>::Vec(const Vec& original) {
	mySize = original.mySize;
	if (original.mySize > 0) {
		myArray  = new Item [mySize];
		for (unsigned i = 0; i < mySize; i++)
			myArray[i] = original.myArray[i];
	}
	else
		myArray = NULL;
}

//lab03 Vec class deconstructor
template<class Item>
Vec<Item>::~Vec() {
	delete [] myArray;
	myArray = NULL;
	mySize = 0;
}

//lab03 Vec class assignment operator
template<class Item>
Vec<Item>& Vec<Item>::operator=(const Vec<Item>& original) {
	if (myArray != original.myArray) {
		if (mySize > 0) {
			delete [] myArray;
			myArray = NULL;
		}
		if (original.mySize > 0)
			myArray = new Item [original.mySize];
		mySize = original.mySize;
	}
	for (unsigned i = 0; i < mySize; i++)
		myArray[i] = original.myArray[i];
    return *this;
}

//lab03 return mySize
template<class Item>
unsigned Vec<Item>::getSize() const {
	return mySize;
   }

//lab03 set value to 'it' at 'index'
template<class Item>
void Vec<Item>::setItem(unsigned index, const Item& it) {
	if(mySize>index){myArray[index]=it;}
	else {throw std::range_error("index outside of range");}
}

//lab03 get value of item at 'index'
template<class Item>
Item Vec<Item>::getItem(unsigned index) const {
	if(mySize>index)return myArray[index];
	else throw std::range_error("index outside of range");
}

//lab03 set a Vec class's size
template<class Item>
void Vec<Item>::setSize(unsigned newSize) {
	if (newSize == 0) {
		delete [] myArray;
		myArray = NULL;
		mySize = 0;
	}
	else if (mySize == newSize)
		mySize = newSize;
	else {
		Item * newArray = new Item[newSize];
		if (mySize < newSize){
			for (unsigned i = 0; i < mySize; i++)
				newArray[i] = myArray[i];
			for (unsigned i = mySize; i < newSize; i++)	// TODO Auto-generated constructor stub

				newArray[i] = 0;
		}
		else {
			for (unsigned i = 0; i < newSize; i++)
				newArray[i] = myArray[i];
		}
		mySize = newSize;
		delete [] myArray;
		myArray = newArray;
	}
   }

//lab03 test for equality b/t left operend and v2
template<class Item>
bool Vec<Item>::operator==(const Vec& v2) const{
	if(myArray==v2.myArray)return true;
	else if(mySize!=v2.mySize)return false;
	for(unsigned i=0;i<mySize;i++){
		if(v2.myArray[i]!=myArray[i])return false;
	}
	return true;
}

//lab03 ostream output to file
template<class Item>
void Vec<Item>::writeTo(ostream& out) const {
	for (unsigned i; i < mySize; i++)
		out << myArray[i] << endl;
   }

//lab03 istream read from file into array
template<class Item>
void Vec<Item>::readFrom(istream& in) {
	for (unsigned i= 0; i < mySize; i++)
		in >> myArray[i];
   }

/* Subscript to retrieve value method
 * @index: an unsigned int that must not be out
 * 			of range for myArray
 * Return: myArray[index]
 */
template<class Item>
Item& Vec<Item>::operator[] (unsigned index){
	if(index>=mySize)throw range_error("Bad Subscript");
	return myArray[index];
}

/* Subscript to retrieve value method for constant
 * 		reference values
 * @index: an unsigned int that must not be out
 * 			of range for myArray
 * Return: myArray[index]
 */
template<class Item>
const Item& Vec<Item>::operator[](unsigned index)const{
	if(index>=mySize)throw range_error("Bad Subscript");
	return myArray[index];
}

/*Inequality operator != checks if myArray and v2.myArray
 * 		are NOT equal
 * @param: v2, a Vec class object
 * Return: true/false
 */
template<class Item>
bool Vec<Item>::operator !=(const Vec& v2) {
	if (mySize != v2.mySize) {
		return true;
	}
	for (unsigned i = 0; i < mySize; i++) {
		if (myArray[i] != v2.myArray[i]) {
			return true;
		}
	}
	return false;
}

/* Vec readFrom reads values from a filename directly
 * 		into myArray; the first values read in the
 * 		file will be mySize
 * @filename: a string object, will be used as
 * 		the file read from
 */
template<class Item>
void Vec<Item>::readFrom(string fileName) {
	ifstream fin(fileName.c_str());
	fin >> mySize;
	myArray = new Item[mySize];
	for (unsigned i = 0; i <= mySize; i++) {
		fin >> myArray[i];
	}
	fin.close();
}

/* Vec writeTo writes values to of myArray into
 * 		a file filename; the first values read in the
 * 		file will be mySize
 * @filename: a string object, will be used as
 * 		the file written to
 */
template<class Item>
void Vec<Item>::writeTo(string fileName) {
	ofstream fout(fileName.c_str());
	assert(fout.is_open());
	fout << mySize << '\n';
	for (unsigned i = 0; i < mySize; i++) {
		fout << myArray[i] << '\n';
	}
	fout.close();
}

/*Vector addition operator adds two vectors and sets a third
 * 		vector as equal to them
 *@param: v2, a Vec class object
 *Return: v3, a Vec class object equal to myArray + v2.myArray
 */
template<class Item>
Vec<Item> Vec<Item>::operator+(const Vec<Item>& v2) {
	Vec v3(mySize);
	if (mySize != v2.mySize) {
		throw invalid_argument("Invalid Argument.");
	} else if (v2.mySize == 0) {
		return v3;
	}
	for (unsigned i = 0; i < mySize; i++) {
		v3.myArray[i] = myArray[i] + v2.myArray[i];
	}
	return v3;
}

/*Vector subtraction operator subtracts two vectors and sets a third
 * 		vector as equal to them
 *@param: v2, a Vec class object
 *Return: v3, a Vec class object equal to the values in
 *		myArray minus the values in v2.myArray
 */
template<class Item>
Vec<Item> Vec<Item>::operator-(const Vec<Item>& v2) {
	Vec v3(mySize);
	if (mySize != v2.mySize) {
		throw invalid_argument("Invalid Argument!");
	} else if (v2.mySize == 0) {
		return v3;
	}
	for (unsigned i = 0; i < mySize; i++) {
		v3.myArray[i] = myArray[i] - v2.myArray[i];
	}
	return v3;
}

/*Vector dot operator multiplies two vectors and sets a third
 * 		vector as equal to them
 *@param: v2, a Vec class object
 *Return: v3, a Vec class object equal to the values in
 *		myArray * the values in v2.myArray
 */
template<class Item>
double Vec<Item>::operator*(const Vec& v2) {
	Vec v3(mySize);
	double dProd = 0;
	if (mySize != v2.mySize) {
		throw invalid_argument("Invalid Argument.");
		}
		else if (v2.mySize == 0) {
		return 0;
		}
		for (unsigned i = 0; i < mySize; i++) {
		v3.myArray[i] = myArray[i] * v2.myArray[i];
		}
	for (unsigned i = 0; i < mySize; i++) {
		dProd = dProd + v3.myArray[i];
	}
	return dProd;
}
#endif /*VEC_H_*/
