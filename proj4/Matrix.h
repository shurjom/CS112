/* Matrix.h provides a class for manipulating 2-dimensional vectors.
 * Student Name:Shurjo Maitra
 * Date:3.1.16
 * Begun by: Joel Adams, for CS 112 at Calvin College.
 */


#ifndef MATRIX_H_
#define MATRIX_H_

#include "Vec.h"
#include "MatrixTester.h"

typedef double Item;
template<class Item>

class Matrix {
public:
	Matrix();
	Matrix(unsigned rows, unsigned columns);
	unsigned getRows()const{return myRows;}
	unsigned getColumns()const{return myColumns;}
	const Vec<Item>& operator[](unsigned index) const;
	Vec<Item>& operator[](unsigned index);
	bool operator==(const Matrix<Item>& m2) const;
	bool operator != (const Matrix<Item>& m2) const;
	void writeTo(ostream& out ) const;
	void readFrom(istream& in);
	void writeTo(const string& fileName);
	void readFrom(const string& fileName);
	Matrix<Item> operator + (const Matrix<Item>& rhs) const;
	Matrix<Item> operator - (const Matrix<Item>& rhs) const;
	Matrix<Item> getTranspose() const;
//	Matrix operator * (const Matrix& rhs) const;

private:
	unsigned myRows;
	unsigned myColumns;
	Vec<Vec<Item> > myVec;
	friend class MatrixTester;
};

//lab04 Matrix class default constructor
template<class Item>
Matrix<Item>::Matrix() {
	myRows = myColumns = 0;
}
//lab04 Matrix class explicit constructor
template<class Item>
Matrix<Item>::Matrix(unsigned rows, unsigned columns) {
	myRows = rows;
	myColumns = columns;
	myVec.setSize(rows);
	for (unsigned i = 0; i < rows; i++) {
		myVec[i].setSize(columns);
	}
}
/* Subscript to retrieve value method for constant
 * 		reference values
 * @index: an unsigned int that must not be out
 * 			of range for myVec
 * Return: myVec[index]
 */
template<class Item>
const Vec<Item>& Matrix<Item>::operator[](unsigned index) const {
	if (index >= myRows) throw range_error("Bad Subscript");
	return myVec[index];
}
/* Subscript to retrieve value method
 * @index: an unsigned int that must not be out
 * 			of range for myArray
 * Return: myVec[index]
 */
template<class Item>
Vec<Item>& Matrix<Item>::operator[](unsigned index) {
	if (index >= myRows) throw range_error("Bad Subscript");
	return myVec[index];

}

/*equality operator == checks if myArray and v2.myArray
 * 		are equal
 * @param: m2, a Matrix class object
 * Return: true/false
 */
template<class Item>
bool Matrix<Item>::operator==(const Matrix& m2) const {
   if ( myRows != m2.getRows() || myColumns != m2.getColumns() ) {
        return false;
   } else {
        return myVec == m2.myVec;
   }
}

/*Inequality operator != checks if myArray and v2.myArray
 * 		are NOT equal
 * @param: m2, a Vec class object
 * Return: true/false
 */
template<class Item>
bool Matrix<Item>::operator != (const Matrix<Item>& m2) const {
	   if ( myRows != m2.getRows() || myColumns != m2.getColumns() ) {
	        return true;
	   } else {
	        return !(myVec == m2.myVec);
	   }
	}

/* Matrix readFrom reads values from stream directly
 * 		into myArray; the first values read in the
 * 		stream will be mySize
 */
template<class Item>
void Matrix<Item>::readFrom(istream& in) {
	for (unsigned i = 0; i < myRows; i++) {
		for (unsigned j = 0; j < myColumns; j++)in >> myVec[i][j];
		}
}


/* Matrix writeTo writes values to of myArray into
 * 		out stream; the first values read in the
 * 		stream will be mySize
 */
template<class Item>
void Matrix<Item>::writeTo(ostream& out) const {
	for (unsigned i = 0; i < myRows; i++) {
		for (unsigned j = 0; j < myColumns; j++) {
			out << myVec[i][j] << '\t';
		}
		out << endl;
	}
}
/* Matrix readFrom reads values from a filename directly
 * 		into myArray; the first values read in the
 * 		file will be mySize
 * @filename: a string object, will be used as
 * 		the file read from
 */
template<class Item>
void Matrix<Item>::readFrom(const string& fileName) {
	ifstream in(fileName.c_str());
	in >> myRows;
	in >> myColumns;
	myVec.setSize(myRows);
	for (unsigned i =0; i < myRows; i++) {
		myVec[i].setSize(myColumns);
	}
	readFrom(in);
	in.close();

}

/* Matrix writeTo writes values to of myArray into
 * 		a file filename; the first values read in the
 * 		file will be mySize
 * @filename: a string object, will be used as
 * 		the file written to
 */
template<class Item>
void Matrix<Item>::writeTo(const string& fileName) {
	ofstream fout(fileName.c_str());
	fout << myRows << ' '<< myColumns << endl;
	writeTo(fout);
	fout.close();
}

/*Matrix addition operator adds two matrices and sets a third
 * 		matrix as equal to them
 *@param: m2, a Matrix class object
 *Return: m3, a Matrix class object equal to myArray + v2.myArray
 */
template<class Item>
Matrix<Item> Matrix<Item>::operator + (const Matrix<Item>& rhs) const {
	if(myRows != rhs.myRows || myColumns != rhs.myColumns)
		throw invalid_argument("Only add matrices of same size");
	Matrix<Item> newM(myRows, myColumns);
	for (unsigned i = 0; i < myRows; i++) {
		for (unsigned j = 0; j < myColumns; j++)newM.myVec[i][j] = myVec[i][j] + rhs.myVec[i][j];
	}
	return newM;
}

/*Matrix subtraction operator subtracts two matrices and sets a third
 * 		matrix as equal to them
 *@param: m2, a Matrix class object
 *Return: m3, a Matrix class object equal to the values in
 *		myArray minus the values in v2.myArray
 */
template<class Item>
Matrix<Item> Matrix<Item>::operator - (const Matrix<Item>& rhs) const {
	if(myRows != rhs.myRows || myColumns != rhs.myColumns)
		throw invalid_argument("Only subtract matrices of same size");
	Matrix<Item> newM(myRows, myColumns);
	for (unsigned i = 0; i < myRows; i++) {
		for (unsigned j = 0; j < myColumns; j++)newM.myVec[i][j] = myVec[i][j] - rhs.myVec[i][j];
	}
	return newM;
}

/*Matrix transpose switches the row and column elements
 *@param: m1,m2 Matrix class object
 *Return: m3, a Matrix class object equal to the values in
 *		myArray and v2.myArray with i and j switched around
 */
template<class Item>
Matrix<Item> Matrix<Item>::getTranspose() const {
	Matrix<Item> newM(myColumns, myRows);
	if (myRows == 0) {
		return newM;
	}
	else {
		for (unsigned i = 0; i < myRows; i ++) {
			for (unsigned j = 0; j < myColumns; j ++) {
				newM[j][i] = myVec[i][j];
			}
		}
		return newM;
	}
}

////multiply matrices
//Matrix Matrix::operator * (const Matrix& rhs) const {
//	if(myRows != rhs.myRows || myColumns != rhs.myColumns)
//		throw invalid_argument("Only multiply matrices of same size");
//	Matrix newM(myRows, myColumns);
//	for (unsigned i = 0; i < myRows; i++) {
//		for (unsigned j = 0; j < myColumns; j++)newM.myVec[i][j] = myVec[i][j] * rhs.myVec[i][j];
//	}
//	return newM;
//}


#endif
