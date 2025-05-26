#pragma once
#include "clsScreen.h"
#include "clsBankClient.h"
#include "../cpplibs/clsInputValidate.h"

class clsDeleteClientScreen : protected clsScreen
{
private:
	static void _print(clsBankClient client)
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
	static void showDeleteClientScreen()
	{
		string accountNumber = "";

		string message = "Please enter client's account number: ";
		accountNumber = clsInputValidate::readString(message);

		// While client doesn't exist
		while (!clsBankClient::isClientExist(accountNumber))
		{
			cout << "\nAccount number is associated to another user, choose another one: ";
			accountNumber = clsInputValidate::readString("");
		}

		clsBankClient client = clsBankClient::find(accountNumber);
		client.print();

		char confirmation = 'n';
		cout << "\nAre you sure you want to delete this client? y / n: ";
		cin >> confirmation;

		if (tolower(confirmation) == 'y')
		{
			if (client.deleteClient())
			{
				cout << "\nClient deleted successfully!" << endl;
				_print(client);
			}
			else
			{
				cout << "Client wasn't deleted, error occured!" << endl;
			}
		}
	}
};
