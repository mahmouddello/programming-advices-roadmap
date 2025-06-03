#pragma once
#include "clsScreen.h"
#include "clsUser.h"
#include "../cpplibs/clsString.h"

class clsLoginRegisterScreen : protected clsScreen
{

private:
	static void _drawTableUI()
	{

		cout << setw(8) << left << "" << "\n\t___________________________________________________________";
		cout << "____________________________________________\n" << endl;

		cout << setw(8) << left << "" << "| " << left << setw(25) << "Date/Time";
		cout << "| " << left << setw(20) << "Username";
		cout << "| " << left << setw(20) << "Password";
		cout << "| " << left << setw(12) << "Permessions";
		cout << setw(8) << left << "" << "\n\t__________________________________________________________";
		cout << "_____________________________________________\n" << endl;
	}

	static void _printLogDetails(clsUser::stLoginRegisterRecord record)
	{
		cout << setw(8) << left << "" << "| " << setw(25) << left << record.datetime;
		cout << "| " << setw(20) << left << record.username;
		cout << "| " << setw(20) << left << record.password;
		cout << "| " << setw(20) << left << record.permissions;
	}

public:
	static void showLoginRegisterScreen()
	{
		vector<clsUser::stLoginRegisterRecord> vLogs = clsUser::getRegisterLoginLogs();

		string title = "\t Login Register Screen";
		string subtitle = "\t   (" + to_string(vLogs.size()) + ") Record(s)";

		_drawScreenHeader(title, subtitle);

		if (vLogs.size() == 0)
			cout << "\t\t\t\tNo Clients Available In the System!";
		else
		{
			_drawTableUI();
			for (clsUser::stLoginRegisterRecord record: vLogs)
			{
				_printLogDetails(record);
				cout << endl;
			}

			cout << setw(8) << left << "" << "\n\t___________________________________________________________";
			cout << "____________________________________________\n" << endl;
		}
	}
};

