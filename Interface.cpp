/*
	Tran, Thompson

	CS A250
	Project (Part D)

	1. SELECTION NAME: Print limited servings
	2. PURPOSE: This selection will print a prompt, asking
	the user to choose a maximum number of servings a
	cookie recipe can have, and based on the user's choice, 
	it will print a list of cookies (name and number of servings
	with the format of maximum calories) with the number of 
	servings less than or equal to the user's choice.
	Assumption: User inputs a number in the given range.
	3. EXPECTED OUTPUT:

-------------------------------------------------------------
	MAXIMUM SERVINGS
-------------------------------------------------------------

What is the maximum # of servings (16-36)? 16

	Nutella Brownies (servings: 16)
	Chocolate Chip Cookies (servings: 16)

	4. TEST CASES:
			Choice 16 (lowest amount)
			Choice 28 (middle amount)
			Choice 36 (max amount)
*/

#include "Interface.h"
#include "CookieList.h"

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

// Definition function displayMenu
void displayMenu()
{
	//                              |             |
	cout << setfill('*') << setw(62) << "" << endl
		<< setfill(' ') << setw(38) << "COOKIE RECIPES" << endl
		<< setfill('*') << setw(62) << "" << endl
		<< endl
		<< "Select one of the following:" << endl
		<< endl
		<< "    a. Print all recipes" << endl
		<< "    b. Print cookie recipe" << endl
		<< "    c. Print cookie calories" << endl
		<< "    d. Print limited calories" << endl
		<< "    e. Print limited servings" << endl
		<< "    f. To exit" << endl
		<< endl
		<< "Enter your choice: ";
}

// Definition function processChoice
void processChoice(CookieList& cookieList)
{	
	char input = 'a';
	int numInput = 0;
	bool done = false;
	bool yesOrNo = false;
	while (!done && cin >> input)
	{
		cout << endl;

		if (yesOrNo)
		{
			switch (input)
			{
				case ('y'):
					displayMenu();
					yesOrNo = false;

					break;
				case ('n'):
					cout << "Thank you for using our software. Good bye!";
					done = true;

					break;
				default:
					cout << "  => Sorry. That is not a selection." << endl
						<< endl
						<< setfill('=') << setw(62) << "" << endl
						<< endl
						<< "Would you like to try again (y/n)? ";

					yesOrNo = true;
			}
		}
		else
		{
			switch (input)
			{
				case ('a'):
					cout << setfill('-') << setw(62) << "" << endl
						<< "    COOKIE RECIPES" << endl
						<< setfill('-') << setw(62) << "" << endl 
						<< endl;

					cookieList.printAllCookies();

					cout << endl
						<< setfill('=') << setw(62) << "" << endl 
						<< endl
						<< "Would you like to continue (y/n)? ";

					yesOrNo = true;

					break;
				case ('b'):
					cout << setfill('-') << setw(62) << "" << endl
						<< "    COOKIE RECIPE" << endl
						<< setfill('-') << setw(62) << "" << endl
						<< endl
						<< "Choose a cookie to view the recipe." << endl
						<< endl;

					cookieList.printCookiesSelection();

					cout << endl << "Your choice: ";

					// choose a number, what to do if not a valid input?
					cin >> numInput;

					cout << endl;

					cookieList.printRecipe(numInput);

					cout << endl
						<< setfill('=') << setw(62) << "" << endl
						<< endl
						<< "Would you like to continue (y/n)? ";
					
					yesOrNo = true;

					break;
				case ('c'):
					cout << setfill('-') << setw(62) << "" << endl
						<< "    COOKIE CALORIES" << endl
						<< setfill('-') << setw(62) << "" << endl
						<< endl
						<< "Choose a cookie # to view number of calories." << endl
						<< endl;

					cookieList.printCookiesSelection();

					cout << endl << "Your choice: ";

					// choose a number, what to do if not a valid input?
					cin >> numInput;

					cout << endl;

					cookieList.printCalories(numInput);

					cout << endl
						<< setfill('=') << setw(62) << "" << endl
						<< endl
						<< "Would you like to continue (y/n)? ";

					yesOrNo = true;

					break;
				case ('d'):
					cout << setfill('-') << setw(62) << "" << endl
						<< "    MAXIMUM CALORIES" << endl
						<< setfill('-') << setw(62) << "" << endl
						<< endl
						<< "What is the maximum # of calories (100-200)? ";

					// choose a number, what to do if not a valid input?
					// is maximum # of calories inclusive?
					cin >> numInput;

					cout << endl;
					
					// coded as non-inclusive
					cookieList.printLimitedCalories(numInput);

					cout << endl
						<< setfill('=') << setw(62) << "" << endl
						<< endl
						<< "Would you like to continue (y/n)? ";

					yesOrNo = true;

					break;
				case ('e'):
					cout << setfill('-') << setw(62) << "" << endl
						<< "    MAXIMUM SERVINGS" << endl
						<< setfill('-') << setw(62) << "" << endl
						<< endl
						<< "What is the maximum # of servings (16-36)? ";

					// choose a number, what to do if not a valid input?
					// is maximum # of calories inclusive?
					cin >> numInput;

					cout << endl;

					// coded as non-inclusive
					cookieList.printLimitedServings(numInput);

					cout << endl
						<< setfill('=') << setw(62) << "" << endl
						<< endl
						<< "Would you like to continue (y/n)? ";

					yesOrNo = true;

					break;
				case ('f'):
					cout << "Thank you for using our software. Good bye!";
					done = true;

					break;
				default:
					cout << "  => Sorry. That is not a selection." << endl
						<< endl
						<< setfill('=') << setw(62) << "" << endl
						<< endl
						<< "Would you like to try again (y/n)? ";
					
					yesOrNo = true;
			}
		}
	}
}