#pragma once
#include <iomanip>
#include <iostream>
#include "clsScreen.h"
#include "clsCurrency.h"

using namespace std;

class clsListCurrenciesScreen : protected clsScreen
{
private:
	static void _drawTable()
	{
		// Top border
		cout << "    " << string(110, '=') << "\n";

		// Header row
		cout << setw(8) << left << ""
			<< "| " << setw(35) << left << "Country"
			<< "| " << setw(10) << left << "Code"
			<< "| " << setw(40) << left << "Name"
			<< "| " << setw(10) << left << "Rate/($1)"
			<< "|\n";

		// Divider line
		cout << "    " << string(110, '=') << "\n";
	}

public:
	static void showListCurrenciesScreen()
	{
		vector<clsCurrency> vCurrenciesList = clsCurrency::getCurrenciesList();

		string title = "\t Currencies List Screen";
		string subtitle = "\t   (" + to_string(vCurrenciesList.size()) + ") Currencies";
		_drawScreenHeader(title, subtitle);

		if (vCurrenciesList.size() <= 0)
		{
			cout << "No currencies available on the system!\n" << endl;
			return;
		}

		else
		{
			_drawTable();

			for (clsCurrency currency : vCurrenciesList)
			{
				cout << setw(8) << left << ""
					<< "| " << setw(35) << left << currency.getCountry()
					<< "| " << setw(10) << left << currency.getCode()
					<< "| " << setw(40) << left << currency.getName()
					<< "| " << setw(10) << left << currency.getRate()
					<< "|\n";
			}
		}
	}
};

