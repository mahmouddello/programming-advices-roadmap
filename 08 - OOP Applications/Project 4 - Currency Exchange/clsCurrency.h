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

	void _update()
	{
		vector<clsCurrency> currencies = _loadCurrencyDataFromFile();

		for (clsCurrency& curr : currencies)
		{
			if (curr.getCode() == this->getCode())
			{
				curr = *this;
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
};

