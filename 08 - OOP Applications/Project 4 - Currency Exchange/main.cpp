#include <iostream>
#include "clsCurrency.h"

void _printCurrencyCard(clsCurrency currency)
{
	cout << "\nCurrency Card:\n";
	cout << "_____________________________\n";
	cout << "\nCountry    : " << currency.getCountry();
	cout << "\nCode       : " << currency.getCode();
	cout << "\nName       : " << currency.getName();
	cout << "\nRate(1$) = : " << currency.getRate();

	cout << "\n\n_____________________________\n\n";
}

int main()
{
	clsCurrency currency1 = clsCurrency::findByCode("syp");

	if (currency1.isEmpty())
		cout << "\nCurrency not found!" << endl;
	else
		_printCurrencyCard(currency1);


	clsCurrency currency2 = clsCurrency::findByCountry("Syrian Arab Republic");

	if (currency2.isEmpty())
		cout << "\nCurrency not found!" << endl;
	else
		_printCurrencyCard(currency2);

	// We are not saving to file yet
	currency1.updateRate(8500);
	_printCurrencyCard(currency1);

	return 0;
}