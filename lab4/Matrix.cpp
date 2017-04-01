/* Matrix.cpp defines Matrix class methods.
 * Student Name:Shurjo Maitra
 * Date:3.1.16
 * Begun by: Joel Adams, for CS 112 at Calvin College.
 */

#include "Matrix.h"
#include "MatrixTester.h"

//lab03 Matrix class default constructor
Matrix::Matrix() {
	myRows = myColumns = 0;
}
//lab03 Matrix class explicit constructor
Matrix::Matrix(unsigned rows, unsigned columns) {
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
const Vec<Item>& Matrix::operator[](unsigned index) const {
	if (index >= myRows) throw range_error("Bad Subscript");
	return myVec[index];
}
/* Subscript to retrieve value method
 * @index: an unsigned int that must not be out
 * 			of range for myArray
 * Return: myVec[index]
 */
Vec<Item>& Matrix::operator[](unsigned index) {
	if (index >= myRows) throw range_error("Bad Subscript");
	return myVec[index];

}

//lab04 test for equality b/t left operand and m2
bool Matrix::operator==(const Matrix& m2) const {
   if ( myRows != m2.getRows() || myColumns != m2.getColumns() ) {
        return false;
   } else {
        return myVec == m2.myVec;
   }
}




