#pragma once
#include "clsScreen.h"
#include "clsCurrency.h"
#include "../cpplibs/clsInputValidate.h"

class clsCurrencyCalculatorScreen : protected clsScreen
{
private:
	static clsCurrency _readCurrencyCode(string message)
	{
		string code = clsString::trim(clsInputValidate::readString(message));

		while (!clsCurrency::isCurrencyExist(code))
		{
			cout << "Currency with code [" << code << "] not found! choose another code: ";
			code = clsString::trim(clsInputValidate::readString(""));
		}

		return clsCurrency::findByCode(code);
	}

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

	static void _printConversion(clsCurrency from, clsCurrency to, float amount, float result)
	{
		cout << "\nConverting from:\n";
		_printCurrencyCard(from);

		cout << "\nConverting to:\n";
		_printCurrencyCard(to);

		cout << amount << " " << from.getCode() << " = " << result << " " << to.getCode() << "\n";
	}

public:
	static void showCurrencyCalculatorScreen()
	{
		_drawScreenHeader("\t Currency Exchange Screen");
		
		clsCurrency currency1 = _readCurrencyCode("\nPlease enter currency 1 code: ");
		clsCurrency currency2 = _readCurrencyCode("\nPlease enter currency 2 code: ");

		float amount = abs(clsInputValidate::readFloatNumber("\nEnter amount to exchange: "));
		float result = currency1.exchange(currency2, amount);
		
		if (result != -1)
		{
			_printConversion(currency1, currency2, amount, result);
		}
	}
};

