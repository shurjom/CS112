/*
 * Employee.h
 *
 *  Created on: Feb 5, 2016
 *      Author: adams
 */

#ifndef EMPLOYEE_H_
#define EMPLOYEE_H_

#include <string>
#include <iostream>
using namespace std;

class Employee {
public:
	Employee();
	Employee(unsigned id, const string& name, unsigned vacationDays);
	unsigned getId() const;
	string getName() const;
	unsigned getVacation() const;
	virtual void readFrom(istream& in);
	void writeTo(ostream& out) const;
//	virtual double getPay() const { return 0.0 ; }
	virtual double getPay() const = 0; // abstract!
private:
	unsigned myId;
	string   myName;
	unsigned myVacationDays;
};

#endif /* EMPLOYEE_H_ */
