#pragma once
#include "clsScreen.h"
#include "clsBankClient.h"
#include "../cpplibs/clsInputValidate.h"

class clsTransferScreen : protected clsScreen
{
private:
	static clsBankClient _getBankClient(string message)
	{
		string accountNumber = "";
		accountNumber = clsInputValidate::readString(message);

		// While client already exist
		while (!clsBankClient::isClientExist(accountNumber))
		{
			cout << "\nAccount not found! Choose another account number: ";
			accountNumber = clsInputValidate::readString("");
		}

		return clsBankClient::find(accountNumber);
	}

	static void _printClient(clsBankClient client)
	{
		cout << "\n\nClient Card:";
		cout << "\n___________________";
		cout << "\nFull Name   : " << client.getFullName();
		cout << "\nAcc. Number : " << client.getAccountNumber();
		cout << "\nBalance     : " << client.getAccountBalance();
		cout << "\n___________________\n";
	}
public:
	static void showTransferScreen()
	{
		_drawScreenHeader("\t Transfer Screen");

		clsBankClient client1 = _getBankClient("\nPlease enter an account number to transfer from: ");
		_printClient(client1);

		clsBankClient client2 = _getBankClient("\nPlease enter an account number to transfer to: ");

		while (client1.getAccountNumber() == client2.getAccountNumber())
		{
			cout << "\nYou can't transfer money to yourself! Try another account" << endl;
			client2 = _getBankClient("\nPlease enter an account number to transfer to: ");
		}

		_printClient(client2);


		double amount = 0;
		amount = clsInputValidate::readDoubleNumberBetween(0, client1.accountBalance, "\nEnter amount to transfer: ", "Amount either exceeds balance, or less than 0!\n");

		char confirmation = 'n';
		cout << "\nAre you sure you want to transfer this amount? y / n: ";
		cin >> confirmation;

		if (tolower(confirmation) == 'y')
		{
			if (client1.transferMoneyTo(client2, amount))
			{
				cout << "\nTransfer done sucessfully, New Balances:\n";
				_printClient(client1);

				client2.refresh();
				_printClient(client2);
			}
			else
				cout << "\nTransfer operation failed!" << endl;
		}
		else
			cout << "\nOperation was canceled!" << endl;
	}
};

