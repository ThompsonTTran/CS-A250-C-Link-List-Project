/*
	Tran, Thompson

	CS A250
	Project (Part B)
*/

#include "CookieList.h"

#include <iostream>
using namespace std;

void CookieList::addCookie(const Cookie& newCookie)
{
	if (count == 0)
	{
		first = new Node(newCookie, nullptr);
		last = first;
	}
	else
	{
		Node* cookieNode = new Node(newCookie, nullptr);
		last->setNext(cookieNode);
		last = last->getNext();
	}

	++count;
}

void CookieList::addCookie(const string& newName, size_t newCalories,
	size_t newServings, const set<string>& newIngredients)
{
	Cookie newCookie(newName, newCalories, newServings, newIngredients);

	addCookie(newCookie);
}

size_t CookieList::getCount() const
{
	return count;
}

bool CookieList::isEmpty() const
{
	return (count == 0);
}

bool CookieList::searchCookie(const string& searchName) const
{
	Node* current = first;
	while (current != nullptr)
	{
		if (current->getCookie().getName() == searchName)
		{
			return true;
		}

		current = current->getNext();
	}

	return false;
}

void CookieList::printAllCookies() const
{
	if (count != 0)
	{
		Node* current = first;
		while (current != nullptr)
		{
			cout << "    " << current->getCookie().getName() << endl;

			current = current->getNext();
		}
	}
	else
	{
		cout << "No Cookies!";
	}
}

void CookieList::printCookiesSelection() const
{
	Node* current = first;
	size_t i = 1;

	while (current != nullptr)
	{
		cout << "    " << i << ": " << current->getCookie().getName() << endl;

		++i;
		current = current->getNext();
	}
}

void CookieList::printRecipe(size_t cookieSelection) const
{
	Node* selection = getCookieLocation(cookieSelection);
	
	selection->getCookie().printRecipe();
}

void CookieList::printCalories(size_t cookieSelection) const
{
	Node* selection = getCookieLocation(cookieSelection);

	selection->getCookie().printCalories();
}

void CookieList::printLimitedCalories(size_t maxCalories) const
{
	Node* current = first;
	while (current != nullptr)
	{
		if (current->getCookie().getCalories() <= maxCalories)
		{
			current->getCookie().printCalories();
		}

		current = current->getNext();
	}
}

void CookieList::printLimitedServings(size_t maxServings) const
{
	Node* current = first;
	while (current != nullptr)
	{
		if (current->getCookie().getServings() <= maxServings)
		{
			current->getCookie().printServings();
		}

		current = current->getNext();
	}
}

void CookieList::clearList()
{
	if (count != 0)
	{
		Node* current = first;
		Node* trailCurrent = first;
		while (current != nullptr)
		{
			current = current->getNext();

			delete trailCurrent;

			trailCurrent = current;
		}

		first = nullptr;
		last = nullptr;
		count = 0;
	}
}

CookieList::~CookieList()
{
	if (count != 0)
	{
		clearList();
	}
}

CookieList::CookieList(const CookieList& otherCookieList)
{
	count = 0;
	first = nullptr;
	last = nullptr;

	Node* current = otherCookieList.first;

	while (current != nullptr)
	{
		addCookie(current->getCookie());

		current = current->getNext();
	}
}

CookieList& CookieList::operator=(const CookieList& rightSideCookieList)
{
	if (&rightSideCookieList == this)
	{
		cerr << "Attempted assignment to itself.";
	}
	else
	{
		if (count != 0)
		{
			this->clearList();
		}

		if (rightSideCookieList.count > 0)
		{
			Node* current = rightSideCookieList.first;

			while (current != nullptr)
			{
				addCookie(current->getCookie());

				current = current->getNext();
			}
		}
	}

	return *this;
}

Node* CookieList::getCookieLocation(size_t cookieSelection) const
{
	Node* current = first;
	for (size_t i = 1; i < cookieSelection; ++i)
	{
		current = current->getNext();
	}

	return current;
}