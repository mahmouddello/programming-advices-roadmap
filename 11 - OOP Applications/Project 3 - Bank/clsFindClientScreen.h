#pragma once
#include "clsBankClient.h"
#include "clsScreen.h"

class clsFindClientScreen : protected clsScreen
{
private:
	static void _printClient(clsBankClient client)
	{
		cout << "\nClient Card:";
		cout << "\n___________________";
		cout << "\nFirstName   : " << client.firstName;
		cout << "\nLastName    : " << client.lastName;
		cout << "\nFull Name   : " << client.getFullName();
		cout << "\nEmail       : " << client.email;
		cout << "\nPhone       : " << client.phoneNumber;
		cout << "\nAcc. Number : " << client.getAccountNumber();
		cout << "\nPassword    : " << client.getPinCode();
		cout << "\nBalance     : " << client.getAccountBalance();
		cout << "\n___________________\n";
	}

public:
	static void showFindClientScreen()
	{
		_drawScreenHeader("\t Find Client Screen");

		string accountNumber = "";

		string message = "Please enter client's account number: ";
		accountNumber = clsInputValidate::readString(message);

		// while client doesn't exist
		while (!clsBankClient::isClientExist(accountNumber))
		{
			cout << "\nAccount was not found, choose another one: ";
			accountNumber = clsInputValidate::readString("");
		}

		clsBankClient client = clsBankClient::find(accountNumber);
		
		if (!client.isEmpty())
		{
			cout << "\nClient found :-)" << endl;
			_printClient(client);
		}
		else
		{
			cout << "\nClient was not found :-(" << endl;
		}
	}
};

