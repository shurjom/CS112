/* Vec.cpp defines the methods for Vec, a simple vector class.
 * Student: Aaron Santucci & Shurjo Maitra
 * Date: Feb 23, 2016
 * Begun by: Joel C. Adams, for CS 112 at Calvin College.
 */

#include "Vec.h"


//lab03 Vec class default constructor
Vec::Vec() {
	mySize = 0;
	myArray = NULL;
}

//lab03 Vec class explicit constructor
Vec::Vec(unsigned size) {
	mySize = size;
	myArray = new Item[mySize];
	for (unsigned i = 0; i < mySize; i++)
		myArray[i] = 0;
}

//lab03 Vec class copy constructor
Vec::Vec(const Vec& original) {
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
Vec::~Vec() {
	delete [] myArray;
	myArray = NULL;
	mySize = 0;
}

//lab03 Vec class assignment operator
Vec& Vec::operator=(const Vec& original) {
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
unsigned Vec::getSize() const {
	return mySize;
   }

//lab03 set value to 'it' at 'index'
void Vec::setItem(unsigned index, const Item& it) {
	if (index >= mySize)
		throw range_error ("Index out of range");
	else
		myArray[index] = it;
   }

//lab03 get value of item at 'index'
Item Vec::getItem(unsigned index) const {
	if (index >= mySize)
			throw range_error ("Index out of range");
	else
		return myArray[index];
  }

//lab03 set a Vec class's size
void Vec::setSize(unsigned newSize) {
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
bool Vec::operator==(const Vec& v2) {
	if (mySize == v2.mySize) {
		for (unsigned i = 0; i < mySize; i++)
			if (myArray[i] != v2.myArray[i])
				return false;
		return true;
	}
	return false;
 }

//lab03 ostream output to file
void Vec::writeTo(ostream& out) const {
	for (unsigned i; i < mySize; i++)
		out << myArray[i] << endl;
   }

//lab03 istream read from file into array
void Vec::readFrom(istream& in) {
	for (unsigned i= 0; i < mySize; i++)
		in >> myArray[i];
   }

/* Subscript to retrieve value method
 * @index: an unsigned int that must not be out
 * 			of range for myArray
 * Return: myArray[index]
 */
Item& Vec::operator[] (unsigned index) {
	if (index >= mySize) {
		throw out_of_range ("Invalid Subscript.");
	}
	else {
		return myArray[index];
	}
}

/* Subscript to retrieve value method for constant
 * 		reference values
 * @index: an unsigned int that must not be out
 * 			of range for myArray
 * Return: myArray[index]
 */
Item& Vec::operator[] (unsigned index) const {
	if (index >= mySize) {
		throw out_of_range ("Invalid Subscript.");
	}
	else {
		return myArray[index];
	}
}

/*Inequality operator != checks if myArray and v2.myArray
 * 		are NOT equal
 * @param: v2, a Vec class object
 * Return: true/false
 */
bool Vec::operator !=(const Vec& v2) {
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
void Vec::readFrom(string fileName) {
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
void Vec::writeTo(string fileName) {
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
Vec Vec::operator+(const Vec& v2) {
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
Vec Vec::operator-(const Vec& v2) {
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
double Vec::operator*(const Vec& v2) {
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

