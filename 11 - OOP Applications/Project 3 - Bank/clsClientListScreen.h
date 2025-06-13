#pragma once
#include <iomanip>
#include "clsScreen.h"
#include "clsBankClient.h"

class clsClientListScreen : protected clsScreen
{
private:
	static void _printClientRecordLine(clsBankClient client)
	{

		cout << setw(8) << left << "" << "| " << setw(15) << left << client.getAccountNumber();
		cout << "| " << setw(20) << left << client.getFullName();
		cout << "| " << setw(12) << left << client.phoneNumber;
		cout << "| " << setw(20) << left << client.email;
		cout << "| " << setw(10) << left << client.pinCode;
		cout << "| " << setw(12) << left << client.accountBalance;
	}

	static void _drawTableUI()
	{

		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "_________________________________________\n" << endl;

		cout << setw(8) << left << "" << "| " << left << setw(15) << "Accout Number";
		cout << "| " << left << setw(20) << "Client Name";
		cout << "| " << left << setw(12) << "Phone";
		cout << "| " << left << setw(20) << "Email";
		cout << "| " << left << setw(10) << "Pin Code";
		cout << "| " << left << setw(12) << "Balance";
		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "_________________________________________\n" << endl;
	}
public:
	static void showClientsList()
	{
		vector <clsBankClient> vClients = clsBankClient::getClientsList();

		string title = "\t Client List Screen";
		string subtitle = "\t   (" + to_string(vClients.size()) + ") Client(s)";

		_drawScreenHeader(title, subtitle);
		if (vClients.size() == 0)
			cout << "\t\t\t\tNo Clients Available In the System!";
		else
		{
			_drawTableUI();
			for (clsBankClient Client : vClients)
			{
				_printClientRecordLine(Client);
				cout << endl;
			}
		}	
	}
};

