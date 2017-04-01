/* main.cpp is the driver for a Conga line simulation.
 *
 * @author: Joel Adams, for CS 112 at Calvin College.
 *
 * Based on an exercise by Marc LeBlanc from Wheaton College (MS).
 * Student name: Shurjo Maitra
 * Date:3.28.16
 */

#include "CongaLine.h"
#include "ListTester.h"

int main() {
	ListTester lt;
	lt.runTests();
	CongaLine dance("Ann", "Bob");
	dance.run();
}
