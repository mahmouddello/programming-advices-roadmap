#pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include "../cpplibs/clsString.h"

using namespace std;

class clsCurrency
{
private:

	enum enMode {emptyMode = 0, updateMode = 1};
	enMode _mode;

	string _country;
	string _code;
	string _name;
	float _rate;

	static clsCurrency _getEmptyCurrencyObject()
	{
		return clsCurrency(enMode::emptyMode, "", "", "", 0);
	}

	static clsCurrency _convertLineToCurrencyObject(const string& line)
	{
		vector<string> vCurrency = clsString::split(line, "#//#");
		
		return clsCurrency(enMode::updateMode, vCurrency[0], vCurrency[1], vCurrency[2], stof(vCurrency[3]));
	}

	static string _converCurrencyObjectToLine(clsCurrency currency, string seperator = "#//#")
	{

		string record = "";
		record += currency.getCountry() + seperator;
		record += currency.getCode() + seperator;
		record += currency.getName() + seperator;
		record += to_string(currency.getRate()) + seperator;

		return record;

	}

	static vector<clsCurrency> _loadCurrencyDataFromFile()
	{
		vector<clsCurrency> vData;
		string line;
		fstream file;

		file.open("currencies.txt", ios::in);
		if (file.is_open())
		{

			while (getline(file, line))
			{
				vData.push_back(_convertLineToCurrencyObject(line));
			}

			file.close();
		}

		return vData;
	}

	static void _saveCurrenciesDataToFile(vector<clsCurrency> vData)
	{
		fstream file;

		file.open("currencies.txt", ios::out);
		if (file.is_open())
		{
			for (clsCurrency curr : vData)
			{
				file << _converCurrencyObjectToLine(curr) << endl;
			}

			file.close();
		}
	}

	void _update()
	{
		vector<clsCurrency> currencies = _loadCurrencyDataFromFile();

		for (clsCurrency& curr : currencies)
		{
			if (curr.getCode() == this->getCode())
			{
				curr = *this;
				_saveCurrenciesDataToFile(currencies);
				break;
			}
		}
	}

public:

	clsCurrency(enMode mode, const string& country, const string& code,
		const string& name, float rate)
		: _mode(mode), _country(country), _code(code), _name(name), _rate(rate) {
	}


	// Read Only Properties (country, code, name)
	string getCountry()
	{
		return this->_country;
	}

	string getCode()
	{
		return this->_code;
	}

	string getName()
	{
		return this->_name;
	}

	float getRate()
	{
		return this->_rate;
	}

	void updateRate(float rate)
	{
		this->_rate = rate;
		_update();
	}

	bool isEmpty()
	{
		return (this->_mode == enMode::emptyMode);
	}

	static clsCurrency findByCode(string currencyCode)
	{
		vector<clsCurrency> currenciesList = _loadCurrencyDataFromFile();
		currencyCode = clsString::lowerAllLetters(currencyCode);

		for (clsCurrency currency : currenciesList)
		{
			if (clsString::lowerAllLetters(currency.getCode()) == currencyCode)
				return currency;
		}

		return _getEmptyCurrencyObject();
	}

	static clsCurrency findByCountry(string country)
	{
		vector<clsCurrency> currenciesList = _loadCurrencyDataFromFile();
		country = clsString::lowerAllLetters(country);

		for (clsCurrency currency : currenciesList)
		{
			if (clsString::lowerAllLetters(currency.getCountry()) == country)
				return currency;
		}

		return _getEmptyCurrencyObject();
	}

	static bool isCurrencyExist(string currencyCode)
	{
		return !clsCurrency::findByCode(currencyCode).isEmpty();
	}

	static vector<clsCurrency> getCurrenciesList()
	{
		return _loadCurrencyDataFromFile();
	}

	static bool isSameCurrency(clsCurrency currency1, clsCurrency currency2)
	{
		return clsString::upperAllLetters(currency1.getCode()) == clsString::upperAllLetters(currency2.getCode());
	}

	float exchange(clsCurrency currency2, float amount)
	{
		if (!isSameCurrency(*this, currency2))
		{
			if (clsString::upperAllLetters(this->getCode()) == "USD")
			{
				return amount * currency2.getRate();
			}

			else if (clsString::upperAllLetters(currency2.getCode()) == "USD")
			{
				return amount / this->getRate();
			}

			else
				return amount * currency2.getRate() / this->getRate();
		}
		else
		{
			cout << "\nYou can't exchange amount from the same currency!" << endl;
			return -1;
		}
	}
};

