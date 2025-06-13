#pragma once
#include "clsBankClient.h"
#include "clsScreen.h"

class clsTransferLogScreen : protected  clsScreen
{
private:
	static void _drawTableUI()
	{

		cout << setw(8) << left << "" << "\n\t___________________________________________________________";
		cout << "____________________________________________\n" << endl;

		cout << setw(8) << left << "" << "| " << left << setw(25) << "Date/Time";
		cout << "| " << left << setw(10) << "s.Acct";
		cout << "| " << left << setw(10) << "d.Acct";
		cout << "| " << left << setw(10) << "Amount";
		cout << "| " << left << setw(10) << "s.Balance";
		cout << "| " << left << setw(10) << "d.Balance";
		cout << "| " << left << setw(12) << "User";
		cout << setw(8) << left << "" << "\n\t__________________________________________________________";
		cout << "_____________________________________________\n" << endl;
	}

	static void _printLogDetails(clsBankClient::stTransferLogRecord record)
	{
		cout << setw(8) << left << "" << "| " << setw(25) << left << record.datetime;
		cout << "| " << setw(10) << left << record.sourceAccountNumber;
		cout << "| " << setw(10) << left << record.destinationAccountNumber;
		cout << "| " << setw(10) << left << record.transferAmount;
		cout << "| " << setw(10) << left << record.sourceBalanceAfter;
		cout << "| " << setw(10) << left << record.destinationBalanceAfter;
		cout << "| " << setw(10) << left << record.username;
	}

public:
	static void showTransferLogScreen()
	{
		
		vector<clsBankClient::stTransferLogRecord> vLogs = clsBankClient::getTransferLogRecords();

		string title = "\t Login Register Screen";
		string subtitle = "\t   (" + to_string(vLogs.size()) + ") Record(s)";

		_drawScreenHeader(title, subtitle);

		if (vLogs.size() == 0)
			cout << "\t\t\t\tNo Clients Available In the System!";
		else
		{
			_drawTableUI();
			for (clsBankClient::stTransferLogRecord record : vLogs)
			{
				_printLogDetails(record);
				cout << endl;
			}

			cout << setw(8) << left << "" << "\n\t___________________________________________________________";
			cout << "____________________________________________\n" << endl;
		}
	}
};

