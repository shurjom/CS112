/* AccountManagerTester.h declares a test-class for class AccountManager.
 * Joel Adams, for CS 112 at Calvin College.
 * Student name: Shurjo Maitra
 * Date: 5.9.16
 */



#ifndef ACCOUNTMANAGERTESTER_H_
#define ACCOUNTMANAGERTESTER_H_

#include "AccountManager.h"
#include <iostream>
#include <cassert>
#include <stdlib.h>
using namespace std;

class AccountManagerTester {
public:
   void runTests();
   void testCreateAndDelete();
   void testChangeUser();
   void testChangePassword();
};

#endif /*ACCOUNTMANAGERTESTER_H_*/
