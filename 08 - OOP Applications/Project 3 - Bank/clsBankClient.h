#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include "clsPerson.h"
#include "../cpplibs/clsString.h"

using std::string;
using std::vector;

class clsBankClient : public clsPerson
{
private:
	const enum enMode {emptyMode = 0, updateMode = 1};
	enMode _mode;

	string _accountNumber;
	string _pinCode;
	double _accountBalance;

	static clsBankClient _convertLineToClientObject(string line, string seperator = "#//#") 
	{
		vector<string> vClientData;
		vClientData = clsString::split(line, seperator);

		return clsBankClient(enMode::updateMode, vClientData[0], vClientData[1],
			vClientData[2], vClientData[3], vClientData[4],
			vClientData[5], stod(vClientData[6]));
	}

	static clsBankClient _getEmptyClientObject()
	{
		return clsBankClient(enMode::emptyMode, "", "", "", "", "", "", 0);
	}
public:
	clsBankClient(
		enMode mode, 
		string firstName, 
		string lastName,
		string email,
		string phoneNumber, 
		string accountNumber,
		string pinCode,
		double accountBalance
	)
	: clsPerson(firstName, lastName, email, phoneNumber)
	{
		_mode = mode;
		_accountNumber = accountNumber;
		_pinCode = pinCode;
		_accountBalance = accountBalance;
	}

	bool isEmpty()
	{
		return (_mode == enMode::emptyMode);
	}

	// Read only property
	string getAccountNumber()
	{
		return _accountNumber;
	}

	// property set
	void setPinCode(string pinCode)
	{
		_pinCode = pinCode;
	}

	// property get
	string getPinCode()
	{
		return _pinCode;
	}

	__declspec(property(get = getPinCode, put = setPinCode)) string pinCode;

	// property set
	void setAccountBalance(double accountBalance)
	{
		_accountBalance = accountBalance;
	}

	// property get
	double getAccountBalance()
	{
		return _accountBalance;
	}

	__declspec(property(get = getAccountBalance, put = setAccountBalance)) double accountBalance;

	void print()
	{
		cout << "\nClient Card:";
		cout << "\n___________________";
		cout << "\nFirstName   : " << firstName;
		cout << "\nLastName    : " << lastName;
		cout << "\nFull Name   : " << getFullName();
		cout << "\nEmail       : " << email;
		cout << "\nPhone       : " << phoneNumber;
		cout << "\nAcc. Number : " << _accountNumber;
		cout << "\nPassword    : " << _pinCode;
		cout << "\nBalance     : " << _accountBalance;
		cout << "\n___________________\n";
	}

	static clsBankClient find(string accountNumber)
	{

		std::fstream MyFile;
		MyFile.open("clients.txt", std::ios::in);//read Mode

		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line))
			{
				clsBankClient Client = _convertLineToClientObject(Line);
				if (Client.getAccountNumber() == accountNumber)
				{
					MyFile.close();
					return Client;
				}

			}

			MyFile.close();

		}

		return _getEmptyClientObject();
	}

	static clsBankClient find(string accountNumber, string pinCode)
	{
		std::fstream MyFile;
		MyFile.open("clients.txt", std::ios::in);//read Mode

		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line))
			{
				clsBankClient Client = _convertLineToClientObject(Line);
				if (Client.getAccountNumber() == accountNumber && Client.getPinCode() == pinCode)
				{
					MyFile.close();
					return Client;
				}

			}

			MyFile.close();

		}

		return _getEmptyClientObject();
	}

	static bool isClientExist(string accountNumber)
	{
		clsBankClient client = clsBankClient::find(accountNumber);

		return (!client.isEmpty()); // if exist, emptyMode = 0, !emptyMode = 1 -> true
	}
};

