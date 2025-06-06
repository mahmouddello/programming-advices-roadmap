#pragma once
#include "clsScreen.h"
#include "clsCurrency.h"
#include "../cpplibs/clsInputValidate.h"
#include "../cpplibs/clsUtil.h"

class clsUpdateCurrencyScreen : protected clsScreen
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

	static void _updateCurrRate(clsCurrency& currency)
	{
		cout << "\nUpdate Currency Rate" << endl;
		cout << "_______________________" << endl;

		currency.updateRate(clsInputValidate::readFloatNumber("\nEnter new rate: "));

		cout << "\nCurrency rate updated sucessfully!" << endl;
	}

public:
	static void showUpdateCurrencyScreen()
	{
		_drawScreenHeader("\t Update Currency Screen");

		string code = clsString::trim(clsInputValidate::readString("\nPlease enter currency code: "));

		while (!clsCurrency::isCurrencyExist(code))
		{
			cout << "\nCurrency is not found! choose another one: ";
			code = clsString::trim(clsInputValidate::readString(""));
		}

		clsCurrency currency = clsCurrency::findByCode(code);

		char confirmation = 'n';
		cout << "\nAre you sure you want to update the rate of this currency? y / n: ";
		cin >> confirmation;

		if (tolower(confirmation) == 'y')
		{
			_updateCurrRate(currency);
			_displayResults(currency);
		}
		else
			cout << "\nOperation is cancled!" << endl;
	}
};

