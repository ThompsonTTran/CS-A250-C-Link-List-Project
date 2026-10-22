/*
	Tran, Thompson

	CS A250
	Project (Part D)
*/

#include "CookieList.h"
#include "Testing.h"
#include "CookieDB.h"
#include "Interface.h"

#include <iostream>
using namespace std;

int main()
{
	CookieList listOfCookies;
	createCookieList(listOfCookies);

	displayMenu();
	processChoice(listOfCookies);
	
	cout << endl;
	system("Pause");
	return 0;
}