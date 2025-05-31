#pragma once
#include "clsScreen.h"
#include "clsBankClient.h"
#include "../cpplibs/clsInputValidate.h"

class clsWithdrawScreen : protected clsScreen
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
	static void showWithdrawScreen()
	{
		_drawScreenHeader("Withdraw Screen");

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

		double amount = clsInputValidate::readDoubleNumber("Enter an amount to withdraw: ");
		char confirm = 'n';

		cout << "\nAre you sure you want to withdraw this amount? y / n: ";
		cin >> confirm;

		if (tolower(confirm) == 'y')
		{
			if (client.withdraw(amount))
			{
				cout << "Amount withdrawn successfully!\n";
				cout << "New Balance: " << client.accountBalance << endl;
			}
			else
			{
				cout << "Withdrawal failed! Either the amount is invalid or exceeds the balance.\n";
			}
		}
		else
		{
			cout << "\nOperation was canceled!" << endl;
		}
	}
};

