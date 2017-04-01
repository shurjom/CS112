/*
 * HourlyEmployee.cpp
 *
 *  Created on: Feb 10, 2016
 *      Author: adams
 */

#include "HourlyEmployee.h"

HourlyEmployee::HourlyEmployee()
 : Employee()
{
	myWage = myHours = 0.0;
}

HourlyEmployee::HourlyEmployee(unsigned id, const string& name,
			         unsigned vacationDays,
					 double wage, double hours)
: Employee(id, name, vacationDays)
{
	myWage = wage;
	myHours = hours;
}

double HourlyEmployee::getWage() const {
	return myWage;
}

double HourlyEmployee::getHours() const {
	return myHours;
}

void HourlyEmployee::readFrom(istream& in) {
	Employee::readFrom(in);
	in >> myWage >> myHours;
}

double HourlyEmployee::getPay() const {
	double pay = myWage * myHours;
	if (myHours > 40) {
		pay += (0.5 * (myHours - 40) * myWage);
	}
	return pay;
}
