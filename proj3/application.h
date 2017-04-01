/* application for displaying vectors
 * Student: Aaron Santucci & Shurjo Maitra
 * Date: Feb 25, 2016
 * project 3 for CS 112 at Calvin College
 */
#ifndef APPLICATION_H_
#define APPLICATION_H_

#include <iostream>
#include "Vec.h"

using namespace std;

class application {
public:
	application();
	application(const application& origional);

	void display();
	void displayMenu();
	void updatePos();
	void displayPos();
	void dimIn();
	void getVec();
	virtual ~application();

private:
	unsigned myDim;
	Vec myPos;
	Vec myVec;
};

#endif /* APPLICATION_H_ */
