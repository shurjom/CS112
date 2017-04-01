/*
 * HourlyEmployee.h
 *
 *  Created on: Feb 10, 2016
 *      Author: adams
 */

#ifndef HOURLYEMPLOYEE_H_
#define HOURLYEMPLOYEE_H_

#include "Employee.h"

class HourlyEmployee : public Employee {
public:
	HourlyEmployee();
	HourlyEmployee(unsigned id, const string& name,
			         unsigned vacationDays,
					 double wage, double hours);
	double getWage() const;
	double getHours() const;
	virtual void readFrom(istream& in);
	virtual double getPay() const;
private:
	double myWage;
	double myHours;
};

#endif /* HOURLYEMPLOYEE_H_ */
