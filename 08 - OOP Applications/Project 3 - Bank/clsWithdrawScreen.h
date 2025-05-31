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

		double amount = 0.0;
		char confirm = 'n';

		amount = abs(clsInputValidate::readDoubleNumber("Enter an amount to withdraw: "));

		while (amount > client.accountBalance)
		{
			cout << "Entered amount exceeds account's balance! enter another amount: ";
			amount = abs(clsInputValidate::readDoubleNumber(""));
		}
		cout << "Are you sure you want to deposit this amount? y / n: ";
		cin >> confirm;


		if (tolower(confirm) == 'y')
		{
			client.withdraw(amount);
			cout << "Amount withdrawed successfully!\n";
			cout << "New Balance: " << client.accountBalance << endl;
		}

		else
		{
			cout << "\nOperation was canceled!" << endl;
		};

	}
};

