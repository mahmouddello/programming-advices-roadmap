#include <iostream>
#include "clsBankClient.h"
#include "clsMainScreen.h"
#include "../cpplibs/clsInputValidate.h"

using namespace std;

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