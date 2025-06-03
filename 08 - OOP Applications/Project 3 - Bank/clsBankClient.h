#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include "clsPerson.h"
#include "../cpplibs/clsString.h"
#include "../cpplibs/clsInputValidate.h"

using namespace std;

class clsBankClient : public clsPerson
{
private:
	const enum enMode { emptyMode = 0, updateMode = 1, addNewMode = 2 };
	enMode _mode;

	string _accountNumber;
	string _pinCode;
	double _accountBalance;
	bool _markForDelete = false;

	static string _converClientObjectToLine(clsBankClient client, string seperator = "#//#")
	{

		string stClientRecord = "";
		stClientRecord += client.firstName + seperator;
		stClientRecord += client.lastName + seperator;
		stClientRecord += client.email + seperator;
		stClientRecord += client.phoneNumber + seperator;
		stClientRecord += client.getAccountNumber() + seperator;
		stClientRecord += client.pinCode + seperator;
		stClientRecord += to_string(client.accountBalance);

		return stClientRecord;

	}

	static clsBankClient _convertLineToClientObject(string line, string seperator = "#//#")
	{
		vector<string> vClientData;
		vClientData = clsString::split(line, seperator);

		return clsBankClient(enMode::updateMode, vClientData[0], vClientData[1],
			vClientData[2], vClientData[3], vClientData[4],
			vClientData[5], stod(vClientData[6]));
	}

	static vector <clsBankClient> _loadClientsDataFromFile()
	{

		vector <clsBankClient> vClients;

		fstream MyFile;
		MyFile.open("clients.txt", ios::in);//read Mode

		if (MyFile.is_open())
		{
			string line;
			while (getline(MyFile, line))
			{

				clsBankClient Client = _convertLineToClientObject(line);

				vClients.push_back(Client);
			}

			MyFile.close();

		}

		return vClients;

	}

	static void _saveCleintsDataToFile(vector <clsBankClient> vClients)
	{

		fstream MyFile;
		MyFile.open("clients.txt", ios::out);//overwrite

		string DataLine;

		if (MyFile.is_open())
		{

			for (clsBankClient C : vClients)
			{
				if (!C._markForDelete)
				{
					DataLine = _converClientObjectToLine(C);
					MyFile << DataLine << endl;
				}
			}
			MyFile.close();
		}
	}

	static clsBankClient _getEmptyClientObject()
	{
		return clsBankClient(enMode::emptyMode, "", "", "", "", "", "", 0);
	}

	void _addDataLineToFile(string dataLine)
	{
		fstream MyFile;
		MyFile.open("clients.txt", ios::out | ios::app);

		if (MyFile.is_open())
		{

			MyFile << dataLine << endl;

			MyFile.close();
		}
	}

	void _update()
	{
		vector<clsBankClient> _vClients = _loadClientsDataFromFile();
		for (clsBankClient& client : _vClients)
		{
			if (client.getAccountNumber() == this->getAccountNumber())
			{
				client = *this;
				break;
			}
		}

		_saveCleintsDataToFile(_vClients);
	}

	void _addNew()
	{
		_addDataLineToFile(_converClientObjectToLine(*this));
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

	static clsBankClient find(string accountNumber)
	{

		fstream MyFile;
		MyFile.open("clients.txt", ios::in);//read Mode

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
		fstream MyFile;
		MyFile.open("clients.txt", ios::in);//read Mode

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

	const enum enSaveResults { svFailedEmptyObject = 0, svSucceeded = 1, svFailedBecauseAccountExist = 2 };

	static clsBankClient getAddNewClientObject(string accountNumber)
	{
		return clsBankClient(enMode::addNewMode, "", "", "", "", accountNumber, "", 0);
	}

	enSaveResults save()
	{
		switch (_mode)
		{
			case enMode::emptyMode:
			{
				if (isEmpty())
					return enSaveResults::svFailedEmptyObject;
			}
			case enMode::updateMode:
			{
				_update();
				return enSaveResults::svSucceeded;
			}
			case enMode::addNewMode:
			{
				if (isClientExist(_accountNumber))
					return enSaveResults::svFailedBecauseAccountExist;
				
				_addNew();
				
				// update the mode, becuase object is added to file, and it's still in memory
				_mode = enMode::updateMode;
				return enSaveResults::svSucceeded;
			}
		}
	}

	bool deleteClient()
	{
		vector<clsBankClient> _vClients = _loadClientsDataFromFile();

		for (clsBankClient& client : _vClients)
		{
			if (client.getAccountNumber() == this->getAccountNumber())
			{
				client._markForDelete = true;
				*this = _getEmptyClientObject(); // empty the object.
				_saveCleintsDataToFile(_vClients); // save 
				return true;
			}
		}

		return false; // no client found
	}

	static vector<clsBankClient> getClientsList()
	{
		return _loadClientsDataFromFile();
	}

	static double getTotalBalance()
	{
		vector<clsBankClient> vClients = _loadClientsDataFromFile();	
		double sum = 0;

		for (clsBankClient c : vClients)
		{
			sum += c.accountBalance;
		}

		return sum;
	}

	bool deposit(double amount)
	{
		if (amount <= 0.0)
			return false;

		accountBalance += amount;
		save();
		return true;
	}

	bool withdraw(double amount)
	{
		if (amount <= 0.0 || amount > accountBalance)
			return false;

		accountBalance -= amount;
		save(); // Persist changes
		return true;
	}

	bool transferMoneyTo(clsBankClient receiverClient, double amount)
	{
		return this->withdraw(amount) && receiverClient.deposit(amount);
	}

	void refresh()
	{
		*this = clsBankClient::find(this->_accountNumber);
	}
};

