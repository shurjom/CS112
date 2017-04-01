/* application for displaying vectors
 * Student: Aaron Santucci & Shurjo Maitra
 * Date: Feb 25, 2016
 * project 3 for CS 112 at Calvin College
 */

#include "application.h"
#include "Vec.h"

/*class constructor for application
 * initializes vector variables (myPos and myVec)
 */
application::application() {
	dimIn();
	myPos = Vec(myDim);
	myVec = Vec(myDim);
	getVec();
	display();
}

/*display() pools together functions to display the
 * menus and receive input from the user
 */
void application::display() {
	cout << endl;
	unsigned q = 0;
	while (q != 3) {
		cout << "Dimensions: " << myDim << endl;;
		cout << endl;
		displayMenu();
		cin >> q;
		if (q == 1)
			updatePos();
		else if (q == 2)
			displayPos();
		else
			cout << "Please enter a valid option!" << endl;
	}
	cout << "...Quitting..." << endl;
}

/*displayMenu() prints out the main menu for the
 * application
 */
void application::displayMenu() {
	cout << "Vector Application Program!" << endl <<
			"1. Add to vector" << endl <<
			"2. Output Position" << endl <<
			"3. Quit" << endl;
}

/* updates the position (sum of vectors entered)
 * using Vec +operator
 */
void application::updatePos() {
	Vec temp(myVec);
	cout << "Input new vector; " << myDim << " dimensions needed: " << endl;
	for (unsigned i=0; i < myDim; i++) {
		cout << "Index " << i << ": ";
		cin >> myVec[i];
	}
	myPos = myVec + temp;
}

//Print the position of the vector myPos
void application::displayPos() {
	cout << "Postion: ";
	for (unsigned i=0; i < myDim; i++)
		cout << myPos[i] << " ";
	cout << endl;
}

//dimIn retrieve the number of dimensions from the user
void application::dimIn() {
	cout << "Input number of dimensions for vector: ";
	cin >> myDim;
}

/*getVec prompts and receives input from the user at the
 * start of the application in order to get a starting position
 */
void application::getVec() {
	cout << "Input starting position; " << myDim << " dimensions needed: " << endl;
	for (unsigned i=0; i < myDim; i++){
		cout << "Index " << i << ": ";
		cin >> myVec[i];
	}
	myPos = myVec;
}

application::~application() {
	// TODO Auto-generated destructor stub
}

