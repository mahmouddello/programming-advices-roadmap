#pragma once
#include "clsScreen.h"
#include "clsBankClient.h"
#include "../cpplibs/clsInputValidate.h"

class clsDepositScreen : protected clsScreen
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
	static void showDepositScreen()
	{
		_drawScreenHeader("Deposit Screen");

		string accountNumber = "";

		string message = "Please enter client's account number: ";
		accountNumber = clsInputValidate::readString(message);

		while (!clsBankClient::isClientExist(accountNumber))
		{
			cout << "\nAccount was not found, enter another account number: ";
			accountNumber = clsInputValidate::readString("");
		}

		clsBankClient client = clsBankClient::find(accountNumber);

		_printClient(client);

		double amount = 0.0;
		char confirm = 'n';

		amount = clsInputValidate::readDoubleNumber("Enter an amount to deposit: ");

		cout << "\nAre you sure you want to deposit this amount? y / n: ";
		cin >> confirm;

		if (tolower(confirm) == 'y')
		{
			if (client.deposit(amount))
			{
				cout << "Amount deposited successfully!\n";
				cout << "New Balance: " << client.accountBalance << endl;
			}
			else
				cout << "\nDeposit failed! Amount must be greater than 0!" << endl;
		}
		else
		{
			cout << "\nOperation was canceled!" << endl;
		}
	}
};

