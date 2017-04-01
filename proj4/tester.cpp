/* tester.cpp drives the testing of our Vec template and Matrix class.
 * Student Name:Shurjo Maitra
 * Date:3.1.16
 * Begun by: Joel Adams, for CS 112 at Calvin College.
 */

#include "VecTester.h"
#include "MatrixTester.h"

int main() {
//	VecTester vt;
//	vt.runTests();

	/*display() pools together functions to display the
	 * menus and receive input from the user
	 */
	cout << "Run Tests? Y/N\nOption:" << endl;
	char a;
	cin >> a;
	if (a == 'y' || a == 'Y') {
		MatrixTester mt;
		mt.runTests();
	}
	/*displayMenu() prints out the main menu for the
	 * application
	 */
	cout << "Welcome to the matrix application." << endl;
	while (true) {
		cout
				<< "Please choose an operation\n 1. + Addition\n 2. - Subtraction\n 3. Transpose\n 4. exit\n Option:"
				<< flush;
		int i1;
		cin >> i1;
		/*exits the program if option 4 is select
		 */
		if (i1 == 4) {
			cout << "You quit";
			break;
		}
		Matrix<double> mat1;
		cout << "Enter the file name for 1st Matrix:";
		string fileName;
		cin >> fileName;
		mat1.readFrom(fileName);
		mat1.writeTo(cout);
		/* outputs the value of a third matrix
		 * using Matrix + operator or the Matrix - operator
		 */
		if (i1 == 1 || i1 == 2) {
			cout << "Enter the filename for the 2nd Matrix: ";
			Matrix<double> mat2;
			cin >> fileName;
			mat2.readFrom(fileName);
			mat2.writeTo(cout);

			cout << "The result is:\n";

			Matrix<double> mat3;
			if (i1 == 1)
				mat3 = mat1 + mat2;
			else if (i1 == 2)
				mat3 = mat1 - mat2;
			mat3.writeTo(cout);
		}
		/* outputs the value of a third matrix
			 * which transposes two matrices contained files
			 */
		else if (i1 == 3) {
			cout << "Transposition is:\n";
			Matrix<double> mat4;
			mat4 = mat1.getTranspose();
			mat4.writeTo(cout);
		}

	}

}

