#pragma once
#include <iostream>
#include "clsBankClient.h"
#include "clsScreen.h"
#include "../cpplibs/clsInputValidate.h"

using namespace std;

class clsAddNewClientScreen : protected clsScreen
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

	static void _readClientInfo(clsBankClient& client)
	{
		// seperating UI from object, reads from console and stores in the object
		client.firstName = clsInputValidate::readString("Enter first name: ");
		client.lastName = clsInputValidate::readString("Enter last name: ");
		client.email = clsInputValidate::readString("Enter email: ");
		client.phoneNumber = clsInputValidate::readString("Enter phone number: ");
		client.pinCode = clsInputValidate::readString("Enter pincode: ");
		client.accountBalance = clsInputValidate::readDoubleNumber("Enter account balance: ");
	}

	
public:
	static void showAddNewClientScreen()
	{

		_drawScreenHeader("\t Add New Client Screen");

		string accountNumber = "";

		string message = "Please enter client's account number: ";
		accountNumber = clsInputValidate::readString(message);

		// While client already exist
		while (clsBankClient::isClientExist(accountNumber))
		{
			cout << "\nAccount number is associated to another user, choose another one: ";
			accountNumber = clsInputValidate::readString("");
		}

		clsBankClient newClient = clsBankClient::getAddNewClientObject(accountNumber);

		_readClientInfo(newClient);

		clsBankClient::enSaveResults saveResult = newClient.save();

		switch (saveResult)
		{
		case  clsBankClient::enSaveResults::svSucceeded:
		{
			cout << "\nAccount Created Successfully :-)\n";
			_printClient(newClient);
			break;
		}
		case clsBankClient::enSaveResults::svFailedBecauseAccountExist:
		{
			cout << "\nError account was not saved because account number is used!\n";
			break;
		}
		case clsBankClient::enSaveResults::svFailedEmptyObject:
		{
			cout << "\nError account was not saved because it's Empty!\n";
			break;
		}
		default:
			break;
		}
	}
};

