/*
 * main.cpp
 *
 *  Created on: Feb 5, 2016
 *      Author: adams
 */

#include "EmployeeTester.h"
#include "Employee.h"
#include "SalariedEmployee.h"
#include "HourlyEmployee.h"
#include <fstream>
#include <cassert>
using namespace std;

int main() {
	EmployeeTester et;
	et.runTests();

	cout << "Welcome to the payroll!" << endl;
	ifstream fin("payrollData.txt");
	assert( fin.is_open() );

	string empType;
	Employee * empPtr = NULL;
	while (true) {
		fin >> empType;
		if (!fin) break;
		if ( empType == "Salaried" ) {
			empPtr = new SalariedEmployee();
		} else if ( empType == "Hourly" ) {
			empPtr = new HourlyEmployee();
		} else {
			cerr << "bad employee type: " << empType;
		}
//		cout << empPtr << endl;
		empPtr->readFrom(fin);
//		assert( empPtr->getName() == "Ann" );
//		assert( empPtr->getId() == 1 );
//		assert( empPtr->getVacation() == 21 );

		// compute pay
		cout << empPtr->getName() << "\t"
				<< empPtr->getPay()
				<< endl;

		delete empPtr;
	}
}


