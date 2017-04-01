/*
 * SalariedEmployee.cpp
 *
 *  Created on: Feb 10, 2016
 *      Author: adams
 */

#include "SalariedEmployee.h"

SalariedEmployee::SalariedEmployee()
 : Employee()
{
	mySalary = 0.0;
}

SalariedEmployee::SalariedEmployee(unsigned id,
		                             const string& name,
					                 unsigned vacationDays,
									 double salary)
: Employee(id, name, vacationDays) //, mySalary(salary)
{
	mySalary = salary;
}

double SalariedEmployee::getSalary() const {
	return mySalary;
}

void SalariedEmployee::readFrom(istream& in) {
	Employee::readFrom(in);
	in >> mySalary;
}

double SalariedEmployee::getPay() const {
	return mySalary;
}
