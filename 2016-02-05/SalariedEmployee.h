/*
 * SalariedEmployee.h
 *
 *  Created on: Feb 10, 2016
 *      Author: adams
 */

#ifndef SALARIEDEMPLOYEE_H_
#define SALARIEDEMPLOYEE_H_

#include "Employee.h"

class SalariedEmployee : public Employee {
public:
	SalariedEmployee();
	SalariedEmployee(unsigned id, const string& name,
					unsigned vacationDays, double salary);
	double getSalary() const;
	virtual void readFrom(istream& in);
	virtual double getPay() const;
private:
	double mySalary;
};

#endif /* SALARIEDEMPLOYEE_H_ */
