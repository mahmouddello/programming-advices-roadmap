#pragma once
#include "clsScreen.h"
#include "clsBankClient.h"
#include "../cpplibs/clsInputValidate.h"

class clsUpdateClientScreen : protected clsScreen
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
	static void showUpdateClientScreen()
	{
		_drawScreenHeader("\t Update Client Screen");
		
		string accountNumber = "";

		string message = "Please enter client's account number: ";
		accountNumber = clsInputValidate::readString(message);

		// while client doesn't exist
		while (!clsBankClient::isClientExist(accountNumber))
		{
			cout << "\nAccount number not found, choose another one: ";
			accountNumber = clsInputValidate::readString("");
		}

		clsBankClient client = clsBankClient::find(accountNumber);
		_printClient(client);

		cout << "\n\nUpdate Client Info:";
		cout << "\n____________________\n";

		clsBankClient::readClientInfo(client);

		clsBankClient::enSaveResults saveResult;
		saveResult = client.save();

		switch (saveResult)
		{
		case  clsBankClient::enSaveResults::svSucceeded:
		{
			cout << "\nAccount Updated Successfully :-)\n";
			_printClient(client);
			break;
		}
		case clsBankClient::enSaveResults::svFailedEmptyObject:
		{
			cout << "\nError account was not saved because it's Empty";
			break;
		}
		default:
			break;
		}
	}
};
