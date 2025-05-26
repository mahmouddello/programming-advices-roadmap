#include <iostream>
#include "clsBankClient.h"
#include "clsMainScreen.h"
#include "../cpplibs/clsInputValidate.h"

using namespace std;

//void updateClient()
//{
//	string accountNumber = "";
//
//	string message = "Please enter client's account number: ";
//	accountNumber = clsInputValidate::readString(message);
//
//	// while client doesn't exist
//	while (!clsBankClient::isClientExist(accountNumber))
//	{
//		cout << "\nAccount number not found, choose another one: ";
//		accountNumber = clsInputValidate::readString("");
//	}
//
//	clsBankClient client = clsBankClient::find(accountNumber);
//	client.print();
//
//	cout << "\n\nUpdate Client Info:";
//	cout << "\n____________________\n";
//
//	// We can choose what we want to update, e.g.: here we updated all info
//	readClientInfo(client);
//
//	// save phase
//	clsBankClient::enSaveResults saveResult;
//	saveResult = client.save();
//
//	switch (saveResult)
//	{
//	case  clsBankClient::enSaveResults::svSucceeded:
//	{
//		cout << "\nAccount Updated Successfully :-)\n";
//		client.print();
//		break;
//	}
//	case clsBankClient::enSaveResults::svFailedEmptyObject:
//	{
//		cout << "\nError account was not saved because it's Empty";
//		break;
//	}
//	default:
//		break;
//	}
//}
//
//void printClientRecordBalanceLine(clsBankClient client)
//{
//
//	cout << "| " << setw(15) << left << client.getAccountNumber();
//	cout << "| " << setw(40) << left << client.getFullName();
//	cout << "| " << setw(12) << left << client.accountBalance;
//
//}
//
//void showTotalBalances()
//{
//
//	vector <clsBankClient> vClients = clsBankClient::getClientsList();
//
//	cout << "\n\t\t\t\t\tBalances List (" << vClients.size() << ") Client(s).";
//	cout << "\n_______________________________________________________";
//	cout << "_________________________________________\n" << endl;
//
//	cout << "| " << left << setw(15) << "Accout Number";
//	cout << "| " << left << setw(40) << "Client Name";
//	cout << "| " << left << setw(12) << "Balance";
//	cout << "\n_______________________________________________________";
//	cout << "_________________________________________\n" << endl;
//
//	double TotalBalances = clsBankClient::getTotalBalance();
//
//	if (vClients.size() == 0)
//		cout << "\t\t\t\tNo Clients Available In the System!";
//	else
//	{
//		for (clsBankClient Client : vClients)
//		{
//			printClientRecordBalanceLine(Client);
//			cout << endl;
//		}
//
//		cout << "\n_______________________________________________________";
//		cout << "_________________________________________\n" << endl;
//		cout << "\t\t\t\t\t   Total Balances = " << TotalBalances << endl;
//		cout << "\t\t\t\t\t   ( " << clsUtil::NumberToText(TotalBalances) << ")" << endl;;
//	}
//
//
//	cout << "\n_______________________________________________________";
//	cout << "_________________________________________\n" << endl;
//}

int main()
{
	clsMainScreen::showMainMenu();
	return 0;
}