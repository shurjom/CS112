/*
 * EmployeeTester.cpp
 *
 *  Created on: Feb 5, 2016
 *      Author: adams
 */

#include "Employee.h"
#include "SalariedEmployee.h"
#include "HourlyEmployee.h"
#include "EmployeeTester.h"
#include <iostream>
#include <fstream>
#include <cassert>
using namespace std;

void EmployeeTester::runTests() {
	cout << "Testing class Employee... " << endl;
	testConstructors();
	testInputOutput();
	cout << "All tests passed!" << endl;
}

void EmployeeTester::testInputOutput() {
	cout << "- readFrom and writeTo... " << flush;
//	Employee emp0, emp1, emp2;
//	ifstream fin( "empData.txt" );
//	assert( fin.is_open() );
//	emp0.readFrom(fin);
//	assert( emp0.getId() == 1 );
//	assert( emp0.getName() == "Anne" );
//	assert( emp0.getVacation() == 21 );
//	cout << " 0 " << flush;
//	emp1.readFrom(fin);
//	assert( emp1.getId() == 2 );
//	assert( emp1.getName() == "Bob" );
//	assert( emp1.getVacation() == 14 );
//	cout << " 1 " << flush;
//	emp2.readFrom(fin);
//	assert( emp2.getId() == 3 );
//	assert( emp2.getName() == "Chris" );
//	assert( emp2.getVacation() == 10 );
//	cout << " 2 " << flush;
//	fin.close();
//	// output
//	ofstream fout("outputData.txt");
//	assert( fout.is_open() );
//	emp0.writeTo(fout);
//	emp1.writeTo(fout);
//	emp2.writeTo(fout);
//	fout.close();
//
//	Employee emp3, emp4, emp5;
//	ifstream fin2( "outputData.txt" );
//	emp3.readFrom(fin2);
//	emp4.readFrom(fin2);
//	emp5.readFrom(fin2);
//	assert( emp3.getId() == 1 );
//	assert( emp3.getName() == "Anne" );
//	assert( emp3.getVacation() == 21 );
//	cout << " 3 " << flush;
//	assert( emp4.getId() == 2 );
//	assert( emp4.getName() == "Bob" );
//	assert( emp4.getVacation() == 14 );
//	cout << " 4 " << flush;
//	assert( emp5.getId() == 3 );
//	assert( emp5.getName() == "Chris" );
//	assert( emp5.getVacation() == 10 );
//	cout << " 5 " << flush;
	// salaried employee input
	ifstream salFin("salariedEmp.txt");
	assert( salFin.is_open() );
	SalariedEmployee salEmp;
	salEmp.readFrom(salFin);
	assert( salEmp.getId() == 1 );
	assert( salEmp.getName() == "Ann" );
	assert( salEmp.getVacation() == 21 );
	assert( salEmp.getSalary() == 2000.00 );
	cout << " 6 " << flush;
	salEmp.readFrom(salFin);
	assert( salEmp.getId() == 3 );
	assert( salEmp.getName() == "Chris" );
	assert( salEmp.getVacation() == 21 );
	assert( salEmp.getSalary() == 1500.00 );
	cout << " 7 " << flush;
	salFin.close();
	HourlyEmployee hourlyEmp;
	ifstream hourlyFin("hourlyData.txt");
	assert( hourlyFin.is_open() );
	hourlyEmp.readFrom( hourlyFin );
	assert( hourlyEmp.getId() == 2 );
	assert( hourlyEmp.getName() == "Bob" );
	assert( hourlyEmp.getVacation() == 14 );
	assert( hourlyEmp.getWage() == 20.00 );
	assert( hourlyEmp.getHours() == 40.0 );
	cout << " 8 " << flush;
	hourlyEmp.readFrom( hourlyFin );
	assert( hourlyEmp.getId() == 4 );
	assert( hourlyEmp.getName() == "Ed" );
	assert( hourlyEmp.getVacation() == 14 );
	assert( hourlyEmp.getWage() == 15.00 );
	assert( hourlyEmp.getHours() == 45.0 );
	cout << " 9 " << flush;
	hourlyFin.close();
	cout << " Passed!" << endl;
}

void EmployeeTester::testConstructors() {
	cout << "- constructors... " << flush;
	// default constructor
//	Employee emp;
//	assert( emp.getId() == 0 );
//	assert( emp.getName() == "" );
//	assert( emp.getVacation() == 0 );
//	cout << " 0 " << flush;
//	// explicit constructor
//	Employee emp1(1, "Anne", 21);
//	assert( emp1.getId() == 1 );
//	assert( emp1.getName() == "Anne" );
//	assert( emp1.getVacation() == 21 );
//	cout << " 1 " << flush;
	// salaried employee, default constructor
	SalariedEmployee salEmp;
	assert( salEmp.getId() == 0 );
	assert( salEmp.getName() == "" );
	assert( salEmp.getVacation() == 0 );
	assert( salEmp.getSalary() == 0.0 );
	cout << " 2 " << flush;
	SalariedEmployee salEmp2(1, "Anne", 21, 2000.00);
	assert( salEmp2.getId() == 1 );
	assert( salEmp2.getName() == "Anne" );
	assert( salEmp2.getVacation() == 21 );
	assert( salEmp2.getSalary() == 2000.0 );
	cout << " 3 " << flush;
	// hourly employee, default constructor
	HourlyEmployee hourlyEmp;
	assert( hourlyEmp.getId() == 0 );
	assert( hourlyEmp.getName() == "" );
	assert( hourlyEmp.getVacation() == 0 );
	assert( hourlyEmp.getWage() == 0.0 );
	assert( hourlyEmp.getHours() == 0.0 );
	cout << " 4 " << flush;
	// hourly employee, explicit constructor
	HourlyEmployee hourlyEmp1(2, "Bob", 14, 20.00, 40.0);
	assert( hourlyEmp1.getId() == 2 );
	assert( hourlyEmp1.getName() == "Bob" );
	assert( hourlyEmp1.getVacation() == 14 );
	assert( hourlyEmp1.getWage() == 20.0 );
	assert( hourlyEmp1.getHours() == 40.0 );
	cout << " 5 " << flush;

	cout << " Passed!" << endl;
}

