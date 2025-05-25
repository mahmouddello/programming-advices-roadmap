#include <iostream>
#include "clsBankClient.h"
#include "../cpplibs/clsInputValidate.h"

using namespace std;

void readClientInfo(clsBankClient& client)
{
	// seperating UI from object, reads from console and stores in the object
	client.firstName = clsInputValidate::readString("Enter first name: ");
	client.lastName = clsInputValidate::readString("Enter last name: ");
	client.email = clsInputValidate::readString("Enter email: ");
	client.phoneNumber = clsInputValidate::readString("Enter phone number: ");
	client.pinCode = clsInputValidate::readString("Enter pincode: ");
	client.accountBalance = clsInputValidate::readDoubleNumber("Enter account balance: ");
}

void updateClient()
{
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
	client.print();

	cout << "\n\nUpdate Client Info:";
	cout << "\n____________________\n";

	// We can choose what we want to update, e.g.: here we updated all info
	readClientInfo(client);

	// save phase
	clsBankClient::enSaveResults saveResult;
	saveResult = client.save();

	switch (saveResult)
	{
	case  clsBankClient::enSaveResults::svSucceeded:
	{
		cout << "\nAccount Updated Successfully :-)\n";
		client.print();
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

int main()
{
	updateClient();
	return 0;
}