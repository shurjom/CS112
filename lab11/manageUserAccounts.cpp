/* manageUserAccounts.cpp contains the "driver" for class AccountManager.
 * Joel Adams, for CS 112 at Calvin College.
 * Student name: Shurjo Maitra
 * Date: 5.9.16
 */


#include "AccountManager.h"

int main() {
	AccountManager manager("accountInfo.txt");
	manager.run();
}
