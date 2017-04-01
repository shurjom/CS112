/*
 * Employee.cpp
 *
 *  Created on: Feb 5, 2016
 *      Author: adams
 */

#include "Employee.h"

Employee::Employee() {
	myName = "";
	myId = myVacationDays = 0;

}

Employee::Employee(unsigned id, const string& name, unsigned vacationDays) {
	myId = id;
	myName = name;
	myVacationDays = vacationDays;
}

unsigned Employee::getId() const {
	return myId;
}

string Employee::getName() const {
	return myName;
}

unsigned Employee::getVacation() const {
	return myVacationDays;
}

void Employee::readFrom(istream& in) {
	in >> myId >> myName >> myVacationDays;
}

void Employee::writeTo(ostream& out) const {
	out << myId << '\n'
			<< myName << '\n'
			<< myVacationDays << '\n';
}
