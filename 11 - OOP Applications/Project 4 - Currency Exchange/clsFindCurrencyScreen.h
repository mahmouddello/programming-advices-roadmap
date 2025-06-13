#pragma once
#include "clsScreen.h"
#include "clsCurrency.h"
#include "../cpplibs/clsInputValidate.h"

class clsFindCurrencyScreen : protected clsScreen
{
private:
	static void _printCurrencyCard(clsCurrency currency)
	{
		cout << "\nCurrency Card:\n";
		cout << "_____________________________\n";
		cout << "\nCountry    : " << currency.getCountry();
		cout << "\nCode       : " << currency.getCode();
		cout << "\nName       : " << currency.getName();
		cout << "\nRate(1$) = : " << currency.getRate();

		cout << "\n\n_____________________________\n\n";
	}

	static void _displayResults(clsCurrency currency)
	{
		if (!currency.isEmpty())
		{
			cout << "\nCurrency Found :-)" << endl;
			_printCurrencyCard(currency);
		}
		else
			cout << "\nCurrency doesn't exist :-(" << endl;
	}
public:
	static void showFindCurrencyScreen()
	{
		_drawScreenHeader("\t Find Currency Screen");

		cout << "Find by:[1] Code, " << "[2] Country: ";
		short choice = clsInputValidate::readShortNumberBetween(1, 2, "");

		string query = "";

		switch (choice)
		{
		case 1:
			query = clsInputValidate::readString("\nPlease enter currency code: ");
			_displayResults(clsCurrency::findByCode(query));
			break;
		case 2:
			query = clsInputValidate::readString("\nPlease enter country name: ");
			_displayResults(clsCurrency::findByCountry(query));
			break;
		default:
			break;
		}
	}
};

