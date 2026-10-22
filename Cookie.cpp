/*
	Tran, Thompson

	CS A250
	Project (Part A)
*/

#include "Cookie.h"

#include <iostream>
using namespace std;

string Cookie::getName() const
{
	return name;
}

size_t Cookie::getCalories() const
{
	return calories;
}

size_t Cookie::getServings() const
{
	return servings;
}

set<string> Cookie::getIngredients() const
{
	return ingredients;
}

Cookie Cookie::getCookie() const
{
	return *this;
}

void Cookie::setName(const string& newName)
{
	name = newName;
}

void Cookie::setCalories(size_t newCalories)
{
	calories = newCalories;
}
void Cookie::setServings(size_t newServings)
{
	servings = newServings;
}

void Cookie::setIngredients(const vector<string>& newIngredients)
{
	if (!ingredients.empty())
	{
		ingredients.clear();
	}

	vector<string>::const_iterator iter = newIngredients.begin();
	vector<string>::const_iterator end = newIngredients.end();
	while (iter != end)
	{
		ingredients.insert(*iter);

		++iter;
	}
}

void Cookie::printRecipe() const
{
	cout << "    Recipe for " << name << endl
		<< "        Servings: " << servings << endl
		<< "        Ingredients:";

	printIngredients();

	cout << endl;
}

void Cookie::printIngredients() const
{
	set<string>::iterator iter = ingredients.begin();
	size_t ingredientsSize = ingredients.size();
	for (size_t i = 0; i < ingredientsSize - 1; ++i)
	{
		cout << " " << *iter << ",";

		++iter;
	}

	cout << " " << *iter;
}

void Cookie::printCalories() const
{
	cout << "    " << name << " (calories: " << calories << ")" << endl;
}

void Cookie::printServings() const
{
	cout << "    " << name << " (servings: " << servings << ")" << endl;
}